# DEBUG REPORT #1 — W03D06

Complete only with learner-performed, learner-supplied, or tool-verified facts.
Preserve failure evidence and measure before fixing. Do not infer missing facts.

## Metadata

- Date: `2026-08-29`
- Commit / branch: `feature/w03d06-uart-fault-injection / experiment commit NOT RECORDED`
- Hardware/toolchain if applicable: `NUCLEO-F446RE / STM32F446RETx; ARM GNU Toolchain 13.3.1; STM32 bare-metal build`
- AI assistance used: `Project Chat performed the W03D06 pre-check, asked the learner to define expected behavior, known facts, unknowns, hypothesis, reproduction design, and measurement plan, then normalized those learner-supplied answers into report text. After the learner reproduced the fault and supplied measured results, Project Chat reviewed the evidence and helped structure the root-cause, minimal-fix, regression, recovery, limitation, and self-explanation sections. No measured result was fabricated by AI.`
- Fault category: `RX / ring-buffer overflow`

## 1. Symptom

Trong fault run trên physical NUCLEO-F446RE, PC gửi một burst liên tục gồm đúng 20 byte:

`ABCDEFGHIJKLMNOPQRST`

Serial Monitor quan sát được board chỉ echo:

`ABCDEFGH`

Tức là chỉ 8 byte đầu tiên của burst xuất hiện ở output, còn 12 byte:

`IJKLMNOPQRST`

không được echo.

Debugger sau đó cho thấy:

`overflow_count == 12`

Observable symptom này phù hợp với việc software RX ring buffer capacity 8 byte đã đạt trạng thái full và các byte mới sau đó bị từ chối theo policy `DROP_NEWEST`.

Không có evidence trong experiment này cho thấy 8 byte đã được accept ban đầu bị overwrite hoặc reorder.

## 2. Expected

Khi ring buffer đã đầy đủ 8 byte và byte thứ 9 tới dưới policy
`DROP_NEWEST`, hệ thống được kỳ vọng hoạt động như sau:

- Byte thứ 9 bị từ chối và không được ghi vào buffer;
  `rx_ring_buffer_push()` trả về `false`.
- 8 byte đã có trong buffer phải được giữ nguyên, đúng thứ tự FIFO,
  không bị ghi đè hoặc xáo trộn.
- `count` giữ nguyên tại `RX_RING_BUFFER_CAPACITY` (`8`),
  không được vượt quá capacity.
- `overflow_count` tăng chính xác thêm `1` cho mỗi lần push bị từ chối
  vì buffer đang full.
- Một failed push không được làm thay đổi `head`, `tail`, `count`
  hoặc dữ liệu đã được chấp nhận trước đó.
- Hệ thống vẫn phải giữ được liveness sau overflow.
  Khi foreground consumer tiếp tục `pop()` dữ liệu, buffer phải có khả năng
  drain về trạng thái nominal và tiếp tục nhận dữ liệu mới mà không cần reset
  MCU hoặc reinitialize UART/ring buffer.

Với fault run cụ thể gồm 20 byte, nếu consumer chưa pop byte nào trong burst
và cả 20 byte đều tới được software RX path, prediction là:

- 8 byte đầu tiên được accept;
- 12 byte còn lại bị `DROP_NEWEST`;
- `overflow_count == 12`.

## 3. Reproduction

Fault được tạo có chủ đích bằng cách làm chậm foreground consumer trong
W03D03 UART ring-buffer lab.

Temporary fault-injection code được thêm vào `main.c`:

```c
static void busy_delay(void)
{
    for (volatile uint32_t i = 0; i < 8000000U; i++) {
    }
}
```

Foreground loop tạm thời trở thành:

```c
while (1) {
    busy_delay();

    if (uart_rx_get_byte(&rx_data)) {
        uart_write_byte(rx_data);
    }
}
```

Không thêm delay, `printf()`, polling TX hoặc blocking operation vào
`USART2_IRQHandler()`.

Fault-injection firmware được clean build thành công.

Observed size của fault-injection build:

- `text = 1768`
- `data = 0`
- `bss = 1592`
- `dec = 3360`
- `hex = d20`

Build có các inherited `nosys` linker warnings cho `_close`, `_lseek`,
`_read`, `_write`; đây không phải lỗi do fault-injection code.

Sau khi flash firmware lên physical board, PC gửi đúng một burst:

`ABCDEFGHIJKLMNOPQRST`

Observed Serial Monitor output:

`ABCDEFGH`

Debugger measurement:

`overflow_count == 12`

Sau đó input overload được dừng hoàn toàn để kiểm tra recovery.

## 4. Known facts

Các facts sau đã được xác nhận từ baseline implementation hiện tại:

- Ring buffer có capacity cố định:

  `RX_RING_BUFFER_CAPACITY = 8U`

  và dùng mảng byte tuần hoàn làm storage.

- `rx_ring_buffer_t` quản lý trạng thái bằng các trường riêng biệt:

  - `head`: vị trí ghi tiếp theo;
  - `tail`: vị trí đọc tiếp theo;
  - `count`: số byte hiện đang lưu trong buffer;
  - `overflow_count`: số lần byte mới bị từ chối do buffer full.

- `USART2_IRQHandler` là producer.

  Khi `RXNE` được kích hoạt, ISR đọc `USART2->DR` và đưa byte nhận được
  vào ring buffer thông qua `rx_ring_buffer_push()`.

- ISR hiện không chứa `printf()`, delay hoặc thao tác TX blocking.

- Foreground loop là consumer.

  Dữ liệu được lấy ra thông qua:

  `uart_rx_get_byte()` -> `rx_ring_buffer_pop()`

  với một critical section ngắn quanh thao tác pop để tránh USART2 ISR
  thay đổi shared ring-buffer state trong cùng thời điểm.

- Overflow policy hiện tại là `DROP_NEWEST`.

- Khi buffer đã full (`count == RX_RING_BUFFER_CAPACITY`),
  `rx_ring_buffer_push()` từ chối byte mới, giữ nguyên dữ liệu đã queue,
  không advance `head` / `tail` / `count`,
  tăng `overflow_count`, rồi trả về `false`.

- Baseline host test của ring buffer đã PASS:

  `11 tests, 0 failed`

- Baseline STM32 build trước fault injection cũng đã PASS.

## 5. Unknowns

Trước khi chạy fault injection trên board thật, các điểm sau chưa được xác nhận:

- Chưa biết artificial slowdown có đủ để producer thực sự vượt consumer
  và tái hiện software ring-buffer overflow hay không.

- Chưa biết `overflow_count` sẽ phản ánh thế nào dưới physical UART traffic.

- Chưa biết prediction:

  `overflow_count == 20 - 8 == 12`

  có đúng trong execution thật hay không.

- Chưa biết hệ thống có phục hồi đúng sau overload hay sẽ bị kẹt state.

- Chưa biết có hardware UART overrun (`ORE`) xảy ra trong fault run hay không.

Sau experiment:

- software overflow đã được tái hiện;
- `overflow_count == 12` đã được đo;
- post-overload recovery đã được xác nhận;
- history của UART `ORE` vẫn chưa được đo đủ để kết luận.

## 6. Hypotheses

### H1 — Foreground consumer bị làm chậm sẽ gây software ring-buffer overflow

Nếu cố tình làm chậm Foreground consumer và đồng thời gửi một burst gồm
`N` byte (`N > 8`) từ PC xuống USART2, tôi dự đoán tốc độ producer sẽ vượt
tốc độ consumer đủ lâu để ring buffer đạt trạng thái full.

Prediction của H1:

- `count` sẽ tăng đến `RX_RING_BUFFER_CAPACITY` (`8`).

- Khi buffer đã full, các lần `rx_ring_buffer_push()` tiếp theo sẽ bị từ chối
  theo policy `DROP_NEWEST`.

- Trong mỗi lần drop:

  - dữ liệu đã nằm trong `storage` được giữ nguyên;
  - `head`, `tail` và `count` không bị thay đổi bởi failed push;
  - `overflow_count` tăng thêm `1`.

- Nếu consumer hoàn toàn không pop byte nào trong thời gian toàn bộ burst
  `N` byte được nhận thành công bởi software RX path:

  `overflow_count == N - 8`

- Với burst `N = 20`:

  `overflow_count == 12`

- Tôi dự đoán việc làm chậm foreground không trực tiếp làm chậm ISR,
  vì temporary delay không nằm trong `USART2_IRQHandler()`.

### Hypothesis update after measurement

H1 được support bởi physical measurement.

Observed:

- Input: `ABCDEFGHIJKLMNOPQRST`
- UART output: `ABCDEFGH`
- `overflow_count == 12`

Kết quả phù hợp chính xác với prediction software overflow:

- 8 byte đầu tiên được giữ lại;
- 12 lần push tiếp theo bị từ chối;
- không có observable evidence cho thấy dữ liệu cũ bị overwrite.

Prediction liên quan đến lịch sử UART `ORE` chưa được xác nhận độc lập và
không được coi là proven.

## 7. Measurements

### Measurement plan

Measurement plan ban đầu là quan sát:

- `s_rx_buffer.count`
- `s_rx_buffer.head`
- `s_rx_buffer.tail`
- `s_rx_buffer.overflow_count`
- `s_rx_buffer.storage[0..7]`
- `USART2->SR`, đặc biệt trạng thái `ORE`

với mục tiêu phân biệt software true-overload với buffer invariant bug hoặc
UART hardware overrun.

### Fault Run #1 — actual measured result

Input sent from PC:

`ABCDEFGHIJKLMNOPQRST`

Observed UART output:

`ABCDEFGH`

Observed output length:

`8 bytes`

Bytes absent from UART output:

`IJKLMNOPQRST`

Measured with debugger:

`overflow_count == 12`

The following planned internal snapshot values were not retained as evidence:

- `count`: `NOT RECORDED`
- `head`: `NOT RECORDED`
- `tail`: `NOT RECORDED`
- complete `storage[0..7]` debugger snapshot: `NOT RECORDED`
- `USART2->SR / ORE`: `NOT MEASURED`

### Interpretation

The combination:

- 20 bytes sent;
- 8 bytes echoed in FIFO order;
- `overflow_count == 12`;

strongly supports the prediction that the 8-byte software ring buffer reached
full state and exactly 12 subsequent push attempts were rejected under
`DROP_NEWEST`.

The experiment does not provide enough evidence to make a general claim that
UART hardware `ORE` never occurred, because no dedicated ORE history measurement
was retained.

## 8. Root cause

Fault được tạo có chủ đích bằng cách chèn một `busy_delay()` vào foreground
loop.

Trong thời gian foreground bị giữ lại bởi delay, USART2 interrupt vẫn tiếp tục
đóng vai trò producer, trong khi consumer gần như không thực hiện
`rx_ring_buffer_pop()`.

Với burst 20 byte và ring buffer capacity 8 byte, producer tạm thời nhanh hơn
consumer đủ lâu để software ring buffer đạt full state.

Evidence:

- Input: `ABCDEFGHIJKLMNOPQRST`
- Observed output: `ABCDEFGH`
- Measured `overflow_count == 12`

Kết quả này phù hợp với policy `DROP_NEWEST`: 8 byte đầu tiên được giữ lại,
sau đó 12 lần push tiếp theo bị từ chối vì buffer đang full.

Root cause của fault run không phải là ring-buffer implementation tự báo full
sai hoặc overwrite dữ liệu cũ.

Root cause là producer/consumer rate imbalance có chủ đích:

`foreground consumer bị artificial slowdown trong khi UART producer vẫn tiếp tục nhận byte`.

Không có evidence trong experiment này cho thấy ring-buffer invariant bị phá vỡ.

UART hardware `ORE` không được đo đủ để kết luận và được giữ lại như một
remaining limitation.

## 9. Minimal fix

Minimal fix là loại bỏ temporary `busy_delay()` đã được chèn vào foreground
loop để tạo fault.

Không thay đổi:

- ring-buffer capacity;
- `DROP_NEWEST` policy;
- `USART2_IRQHandler()`;
- `rx_ring_buffer_push()`;
- `rx_ring_buffer_pop()`.

Lý do:

Measurement cho thấy ring buffer đang thực hiện đúng policy đã thiết kế.
Fault xuất hiện do consumer bị cố tình làm chậm, không phải do lỗi trong
ring-buffer implementation.

Vì vậy thay đổi nhỏ nhất là khôi phục foreground consumer về execution path
bình thường bằng cách xóa temporary artificial slowdown.

Final foreground loop sau khi loại bỏ fault injection:

```c
while (1) {
    if (uart_rx_get_byte(&rx_data)) {
        uart_write_byte(rx_data);
    }
}
```

## 10. Regression test

Sau khi loại bỏ temporary `busy_delay()`, firmware được clean build lại và
flash lên board.

Regression input sử dụng chính payload đã tái hiện fault:

`ABCDEFGHIJKLMNOPQRST`

Learner-reported clean build result:

`Clean build successful (0 errors, 0 warnings).`

Observed UART output:

`ABCDEFGHIJKLMNOPQRST`

Measured after regression:

`overflow_count == 0`

Expected regression result:

- toàn bộ 20 byte được nhận và echo đúng thứ tự;
- symptom chỉ echo `ABCDEFGH` không tái xuất hiện;
- `overflow_count` không tăng.

Actual result khớp expected.

Regression result:

`PASS`

Fault không tái xuất hiện trong tested case sau khi artificial consumer
slowdown được loại bỏ.

## 11. Side effects

### Post-overload recovery test

Trước khi áp dụng minimal fix, sau fault run có:

`overflow_count == 12`

Không reset MCU và không reinitialize UART/ring buffer.

Sau khi overload kết thúc, PC gửi payload mới:

`XYZ`

Observed board output:

`XYZ`

Measured:

`overflow_count == 12`

Counter giữ nguyên và không tăng thêm.

Kết quả này chứng minh trong tested case:

- foreground consumer tiếp tục hoạt động sau overload;
- software RX path không bị deadlock;
- ring buffer không bị kẹt vĩnh viễn ở full state;
- hệ thống tiếp tục nhận và xử lý traffic mới;
- traffic mới không tạo thêm overflow;
- không cần reset MCU hoặc reinitialize UART để phục hồi.

Không quan sát thấy side effect chức năng nào khác trong phạm vi test đã thực hiện.

## 12. Remaining limitation

- Thí nghiệm chỉ kiểm tra một controlled 20-byte burst tại cấu hình UART hiện tại;
  chưa chứng minh behavior dưới sustained high-rate traffic kéo dài.

- `overflow_count` chỉ phản ánh các lần software ring-buffer push bị từ chối
  vì buffer full. Nó không phải counter tổng quát cho mọi dạng UART data loss.

- Fault run không có measurement độc lập ghi lại lịch sử UART `ORE`,
  vì vậy không thể dùng experiment này để kết luận rằng hardware overrun
  không xảy ra hoặc không thể xảy ra.

- `count`, `head`, `tail` và complete `storage[0..7]` snapshot không được
  retained làm evidence trong fault run này.

- Regression chứng minh fault không quay lại trong tested 20-byte case sau khi
  bỏ artificial slowdown; nó không chứng minh capacity 8 byte là đủ cho mọi
  workload thực tế.

- RX path sử dụng interrupt nhưng TX hiện vẫn là polling.

- Fixed 8-byte capacity và `DROP_NEWEST` vẫn có chủ ý làm mất byte mới khi
  producer vượt consumer đủ lâu.

## 13. Evidence links

- Raw terminal/test log: `NOT STORED — learner supplied exact Serial Monitor observations in Project Chat`
- Failure screenshot/capture if applicable: `NOT PERFORMED / NOT RECORDED`
- Measurement evidence: `Debugger observation of s_rx_buffer.overflow_count == 12; standalone evidence file NOT STORED`
- Recovery evidence: `UART input XYZ -> output XYZ; overflow_count remained 12; standalone evidence file NOT STORED`
- Regression output: `UART input ABCDEFGHIJKLMNOPQRST -> output ABCDEFGHIJKLMNOPQRST; overflow_count == 0; standalone evidence file NOT STORED`
- Relevant source diff/commit: `Temporary busy_delay fault-injection change was applied to W03D03 main.c and removed after measurement; experiment commit NOT RECORDED at time of this report`

## 14. Learner self-explanation

Ring buffer của hệ thống có capacity 8 byte và sử dụng policy `DROP_NEWEST`.

Trong trạng thái bình thường, USART2 ISR là producer và foreground loop là
consumer. ISR nhận byte và push vào ring buffer, còn foreground liên tục pop
dữ liệu ra để xử lý và echo.

Để chủ động tạo fault, tôi làm chậm foreground bằng một temporary busy delay.
Điều này không đặt delay trong ISR, nên producer vẫn tiếp tục nhận dữ liệu trong
lúc consumer gần như không lấy byte ra.

Khi gửi burst:

`ABCDEFGHIJKLMNOPQRST`

board chỉ echo:

`ABCDEFGH`

và debugger đo được:

`overflow_count == 12`

Kết quả này support hypothesis rằng software ring buffer đạt capacity 8 byte,
giữ lại 8 byte đầu tiên và từ chối 12 byte tiếp theo theo `DROP_NEWEST`.

Tôi không kết luận `overflow_count` tăng đồng nghĩa với ring buffer bị bug.
Counter tăng có thể là hành vi đúng theo policy nếu producer thực sự nhanh hơn
consumer.

Sau overload, tôi gửi:

`XYZ`

board trả lại:

`XYZ`

và `overflow_count` vẫn giữ nguyên ở `12`.

Điều này cho thấy hệ thống vẫn có khả năng phục hồi và tiếp tục hoạt động sau
controlled overflow.

Minimal fix là loại bỏ artificial busy delay, không sửa ring-buffer algorithm
và không tăng capacity chỉ để che symptom.

Sau khi bỏ delay, cùng input:

`ABCDEFGHIJKLMNOPQRST`

được echo đầy đủ và:

`overflow_count == 0`

nên regression PASS.

Nếu gặp một UART overflow chưa rõ nguyên nhân trong tương lai, ba bước đầu tiên
tôi sẽ làm trước khi sửa code là:

1. Reproduce deterministically:
   khóa payload, baud rate, tần suất gửi và ghi expected so với actual.

2. Measure before fix:
   đo state ở hardware/software boundary để phân biệt hardware overrun,
   true software overload và ring-buffer invariant bug.

3. Verify post-overload recovery:
   dừng traffic gây tràn, kiểm tra consumer có drain được buffer và hệ thống
   có tiếp tục nhận payload mới bình thường hay không.

## 15. AI provenance

- Meaningful learner attempt completed before technical AI review: `YES — learner supplied expected behavior, known facts, unknowns, H1, reproduction design, and measurement plan before the physical fault run`
- Symptom supplied before technical AI review: `YES — learner physically reproduced input ABCDEFGHIJKLMNOPQRST -> output ABCDEFGH`
- Expected behavior supplied before technical AI review: `YES`
- Hypothesis and/or measurement supplied before technical AI review: `YES — learner supplied H1 and the planned discriminating measurements before executing the fault`
- Highest AI level actually used: `AI-3`
- Exact AI/executor contribution: `Executor prepared neutral W03D06 TODO/debug-report templates and verified the known-good W03D03/W03D04 baseline. Project Chat performed the pre-check, asked the learner for expected behavior, known facts, unknowns, hypothesis, reproduction design, and measurement plan, then normalized learner-supplied reasoning into report text. After the learner supplied physical observations and debugger measurements, Project Chat reviewed the evidence and helped structure the root-cause, minimal-fix, recovery, regression, limitation, and self-explanation sections.`
- Core technical patch supplied by AI/executor: `NO — AI suggested the temporary busy-delay fault-injection mechanism after the pre-experiment reasoning phase; the final production behavior was restored by removing that artificial fault condition. No ring-buffer algorithm patch was supplied.`
- Competency implication: `NONE — W03D06 is a normal-learning debug artifact and does not create independent competency evidence`

## 16. Next Action

Trong 5–15 phút tiếp theo:

1. lưu nội dung hoàn chỉnh của `DEBUG_REPORT_W03_D06.md`;
2. kiểm tra rằng temporary `busy_delay()` đã được loại bỏ khỏi final firmware;
3. chạy lại `git diff --check`;
4. kiểm tra `git status --short`;
5. lưu thêm raw screenshot/log nếu vẫn còn có thể thu thập mà không tái tạo hoặc
   giả mạo evidence đã mất;
6. sau đó thực hiện W03D06 END DAY closure transaction.

Debug sequence của ngày:

`reproduce -> expected/actual -> hypothesis -> measurement -> root cause -> minimal fix -> regression -> recovery`

đã được hoàn thành cho controlled RX ring-buffer overflow case.
