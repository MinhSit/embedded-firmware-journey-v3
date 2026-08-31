# RAW COMPETENCY SUBMISSION — W03D07

This file preserves the learner's answer blocks from the scored Project Chat
attempt. Spelling, arithmetic, phrasing, and technical mistakes are retained
without silent correction.

## Gate contract

- Gate ID: `W03D07-UART-IRQ-PARSER-GATE`
- Date executed: `2026-08-31`
- Scored mode: `AI-0`
- Time limit: `65 minutes`
- Allowed: paper/pen and ordinary calculator
- Prohibited: ChatGPT/other AI, Copilot, web/search, old answers/solutions,
  notes, and another person
- Scored assistance: `NONE`

## Task 1 — raw learner answer

1. 115200 = 45.10^6 / 16 x USARTDIV => USARTDIV = 24.4140265
2. phần nguyên là 24, phần thập phân là 0.4140265, div được biểu diễn theo 1/16 nên lấy 0.4140265 x 16 = 6,625 làm tròn là 7 => giá trị divisor được chọn là 24 + 7/16 = 24.4375
3. baud thực tế = fck/16xusartdiv => = 115089.514 bit/s
4. sai sô = (baud thực tế - baud target)/ baud target x 100% ==> -0.0959 %
5. thì ta có

1) **Đo độ rộng 1 bit đơn lẻ (Bit-width measurement):**
   - **Cách thực hiện:** Cho MCU gửi liên tục ký tự `0x55` (mẫu bit luân phiên `01010101` trên đường truyền) hoặc đo khoảng thời gian từ cạnh xuống của Start bit đến cạnh lên gần nhất.
   - **Phân tích:**
     - Nếu thời gian 1 bit lệch đáng kể so với lý thuyết (`T_bit = 1/115200 ≈ 8.68 us`) hoặc dao động lớn (do clock jitter / sai cấu hình Prescaler/PLL), đây là **lỗi clock/baud rate**.
     - Nếu thời gian 1 bit chính xác khoảng `8.68 us`, loại trừ lỗi baud.
2) **Đo cấu trúc khung truyền (Frame structure & Protocol decoding):**
   - **Cách thực hiện:** Gửi một byte đã biết rõ (ví dụ: ASCII `'A'` = `0x41` = `0b01000001`) và kích hoạt bộ giải mã phần cứng (UART Decoder) trên máy hiện sóng / Logic Analyzer.
   - **Phân tích:**
     - Kiểm tra số lượng Data bits (7-bit vs 8-bit vs 9-bit), Parity bit (None / Even / Odd), số lượng Stop bit (1 hay 2 bit), mức phân cực (Active-Low vs Active-High) hoặc thứ tự truyền (LSB first vs MSB first).
     - Nếu dạng sóng khớp đúng với byte MCU gửi về mặt thời gian nhưng sai cấu hình định dạng giữa MCU và Terminal (hoặc MCU gửi chuỗi chưa kết thúc NULL / sai encoding UTF-8/ASCII), đây là **lỗi data-format/software**.

## Task 2 — raw learner answer

1/

1. Khi buffer rỗng: `count == 0`, `head == tail`.
2. Khi buffer đầy: `count == 8`, `head == tail` (nhưng phân biệt rõ ràng với EMPTY nhờ `count == 8` thay vì `count == 0`).

2/

Trạng thái ban đầu:
- head = 6
- tail = 2
- count = (6 - 2 + 8) % 8 = 4
- overflow_count = 0

Quy tắc:
- count == 8 -> FULL -> DROP; overflow_count++; head/count giữ nguyên.
- count < 8 -> ACCEPT; buffer[head], head=(head+1)%8, count++.

Trace:
- Initial: head=6 tail=2 count=4 overflow=0
- Byte1 ACCEPT -> head=7 tail=2 count=5 overflow=0
- Byte2 ACCEPT -> head=0 tail=2 count=6 overflow=0
- Byte3 ACCEPT -> head=1 tail=2 count=7 overflow=0
- Byte4 ACCEPT -> head=2 tail=2 count=8 overflow=0
- Byte5 DROP   -> head=2 tail=2 count=8 overflow=1

3/

1. Gây trễ ngắt (Interrupt Latency) và mất dữ liệu phần cứng (Hardware Overrun - ORE): `printf()` là hàm xử lý chuỗi phức tạp và truyền dữ liệu dạng blocking, tốn từ vài microsecond đến vài millisecond. Nếu ISR giữ CPU quá lâu, các byte tiếp theo truyền đến thanh ghi dịch (Shift Register) của UART sẽ ghi đè lên thanh ghi nhận dữ liệu (`RDR`/`DR`) trước khi được đọc ra, kích hoạt lỗi Overrun phần cứng và làm rơi rụng dữ liệu vật lý.

2. Nguy cơ Deadlock (Treo vĩnh viễn hệ thống): `HAL_Delay()` hoạt động dựa trên biến đếm ngắt định kỳ của timer hệ thống (`SysTick_Handler`). Nếu ngắt UART có mức ưu tiên cao hơn hoặc bằng ngắt SysTick (mặc định trong nhiều cấu hình HAL), việc gọi `HAL_Delay()` bên trong UART ISR sẽ làm CPU bị kẹt trong vòng lặp vô tận do SysTick không thể nhảy vào để tăng biến đếm thời gian.

3. Phá vỡ tính đáp ứng thời gian thực (Real-time Determinism): Việc ISR chủ động chờ (polling/blocking) foreground xử lý xong là vi phạm nguyên tắc cơ bản của lập trình ngắt. ISR phải chạy theo nguyên tắc "vào nhanh, thoát nhanh" (Run to Completion) để nhường quyền xử lý cho các tác vụ và ngắt khác trong hệ thống.

4/

Điều kiện lý thuyết để chạy Lock-free không cần Mutex:
1. Single-Writer Principle: chỉ ISR ghi `head`, foreground chỉ đọc; foreground ghi `tail`, ISR chỉ đọc.
2. Atomicity: `head`/`tail` dùng kiểu phù hợp để các access không bị torn.
3. Learner also stated `volatile`/memory-barrier reasoning.

Learner identified the shared-count problem:
- ISR performs count++
- foreground performs count--
- read-modify-write can race
- suggested a critical section or atomic mechanism
- concluded a shared count removes the natural single-writer SPSC property.

5/

Hypothesis 1:
Hardware Overrun Error (ORE).

Cause:
Byte can be lost at UART hardware before ring-buffer push.

First measurement:
Inspect/count ORE in UART status/error handling.

Hypothesis 2:
Framing/Parity error from noise or baud/data-format mismatch.

First measurement:
Inspect FE/PE and physical RX waveform / bit width / frame.

## Task 3 — raw learner answer

```c
#include <stdbool.h>
#include <stddef.h>

#define PARSER_MAX_DATA_LEN (sizeof(((parser_t *)0)->line) - 1)

parser_result_t parser_feed(parser_t *p, char byte) {
    if (byte == '\n') {
        if (p->discarding) {
            p->len = 0;
            p->discarding = false;
            return PARSER_LINE_TOO_LONG;
        }

        if (p->len > 0 && p->line[p->len - 1] == '\r') {
            p->len--;
        }

        if (p->len == 0) {
            return PARSER_EMPTY_LINE;
        }

        p->line[p->len] = '\0';
        p->len = 0;
        return PARSER_LINE_READY;
    }

    if (p->discarding) {
        return PARSER_NONE;
    }

    if (p->len < PARSER_MAX_DATA_LEN) {
        p->line[p->len++] = byte;
        return PARSER_NONE;
    } else {
        p->discarding = true;
        return PARSER_NONE;
    }
}
```

Trace:
- `"1234567890123456\r\n"` -> PARSER_LINE_TOO_LONG.
- after first newline: len=0, discarding=false.
- `"OK\r\n"` -> PARSER_LINE_READY.
- final C-string: `"OK"`.

Reasoning:
- `len < sizeof(line)` alone can consume all 16 bytes and leave no room for `'\0'`, causing an out-of-bounds terminator / invalid C-string use.
- silently truncating a long command can change command semantics.
- after overflow, remaining bytes before `'\n'` still belong to the damaged line.
- parsing them as a new command can desynchronize the stream / create unintended command interpretation.
- discard until newline to resynchronize at the frame boundary.

## Task 4 — raw learner answer

Hypothesis 1: Hardware Overrun Error (ORE)
- Burst bytes arrive around every 86.8 us at 115200.
- CPU/interrupt latency may allow hardware receive overrun.
- First measurement: count ORE status.
- Supports: ORE_count increases with lost-command event.
- Weakens: ORE_count remains zero.

Hypothesis 2: Ring-buffer software overflow
- N=8 can fill if foreground is delayed.
- First measurement: overflow_count.
- Supports: overflow_count increases with event.
- Weakens: stays zero during lost-command event.

Hypothesis 3: Race/data corruption in shared count/head/tail state
- Shared read-modify-write state can become inconsistent.
- First measurement: integrity assertion/log comparing state and producer/consumer byte counts.
- Supports: impossible/inconsistent states appear.
- Weakens: state remains internally consistent.

Given:
- ORE_count > 0
- ring overflow_count == 0
- parser receives fewer bytes than appear on wire

Learner root-cause conclusion:
Hardware Overrun (ORE) caused by excessive interrupt latency / CPU not servicing RX fast enough.

Why not parser:
Data is lost before parser receives it, so parser changes cannot reconstruct those bytes.

Chosen current improvement:
DMA (Circular DMA / DMA + Idle Line Detection).

Reason:
DMA removes per-byte CPU service and transfers UART data to RAM.

Trade-off:
- more configuration complexity;
- stream/channel/circular/IDLE or HT/TC handling;
- bus/resource considerations.

When increasing buffer is useful:
When ISR reads hardware in time, ORE is absent, but software ring overflow occurs
because foreground drains too slowly.

When shortening ISR is useful:
When ISR/other interrupt latency is measurably excessive or DMA is unavailable /
not justified.

## Learner integrity declaration after CLOSE GATE

> CLEAN ko dùng bất kì cái gì ngoài máy tình cầm tay

Normalized metadata only: `CLEAN — no AI/search/notes/other person; ordinary calculator only.`
