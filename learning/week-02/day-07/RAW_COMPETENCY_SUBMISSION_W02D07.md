# RAW COMPETENCY SUBMISSION — W02D07

This document preserves learner-supplied text from the 2026-08-23 Week 2
Cortex-M / GPIO / EXTI competency-gate attempt. Spelling and technical content
inside quoted learner answers are not silently corrected.

Where the exact prompt or answer text was not available to this executor, the
record says so rather than reconstructing it.

## Assessment context

- Date: `2026-08-23`
- Planned start: `10:30 local`
- Actual assessment start recorded in Project Chat: `10:22 local`
- Assessment close: `11:11 local`
- Elapsed: `~49 minutes`
- Maximum: `60 minutes`
- Declared contract: `AI-0 / closed-book / no documentation, search, notes, or previous solutions`
- Official outcome: `INVALID / RETEST REQUIRED`

## Task 1

### 1A

Prompt: `RAW PROMPT TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

Learner answer:

> giá trị đầu là để khởi tạo giá trị cho MSP, giá trị được nạp vào thanh ghi sp để thiết lập vùng stack
> giá trị thứ 2 là reset_handler la giá trị được nạp vào thanh ghi PC để biết sẽ thực thi instruction nào đầu tiên

### 1B

Prompt: `RAW PROMPT TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

Learner answer:

> .data được cấp 0x2000000F - 0x20000000 là 16 byte
> .bss được cấp cũng 16 byte

### 1C

Prompt: `RAW PROMPT TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

Learner answer:

> flash nó giữ được khi mất điện, còn ram thì nhanh hơn nên phai đẩy lên ram vì các giá trị này có thể thay đổi giá trị liên tục trong chương trình

### 1D

Prompt: `RAW PROMPT TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

Learner answer:

> có thể đọc sai giá trị, ví dụ ta khởi tạo 1 flag = 0 trỏ vào bss nhưng nó chưa đc clear có thể = 1 làm sai cả logic

### 1E

Prompt: `RAW PROMPT TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

Learner answer:

> để cấu hình các thành phần cốt lỗi, các hàm đc yêu cầu chạy trước main

## Task 2

### 2A

Prompt: `RAW PROMPT TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

Learner answer:

> vì tất cả phải được đồng bộ với clock chung của cả hệ thống nếu ko sẽ gây lỗi khi chốt dữ liệu hoặc phả hòi bus -> sẽ bị bỏ qua khi thao tác thanh ghi hoặc gây lỗi

### 2B

Prompt: `RAW PROMPT TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

Learner answer:

> cấp clock rcc -> chèn 1 2 chu kì chờ để ổn định -> cấu hình kiểu pin qua MODER -> cấu hình output type -> gán mứu logic ban đầu

### 2C

Prompt: `RAW PROMPT TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

Learner answer:

> chưa bật rcc -> thử đọc giá trị của gpio -> moder nếu vẫn như lúc mới reset có thể do chưa bật
> sai phần cứng hoặc cấu hình output type sai -> dùng VOM đo
> chấn gpio đó bị ghi đề ở hàm khác -> kiểm tra bằng breakpoint

### 2D

Prompt: `RAW PROMPT TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

Learner answer:

> vì nó là 3 bước khác nhau nhau, ví dụ đang modifier mà có 1 interut thay đỏi giá trị thì sau đó nó lại bị write lại về giá trị cũ

### 2E

Prompt: `RAW PROMPT TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

Learner answer:

> vì BSRR là write only, tránh được TH ở câu 2D

## Task 3

### 3A

Prompt: `RAW PROMPT TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

Learner answer:

> có tín hiệu vật lý -> nhận tín hiệu, đưa vàn đưuongf nội bộ -> đưa vào EXTI line -> nhận diện và kích hoạt tín hiệu -> bit cờ ngắt bật lên 1 -> NVIC kiểm tra gửi tín hiệu tới CPU -> CPU thực hiện ISR

### 3B

`RAW TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

### 3C

`RAW TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

### 3D

`RAW TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

### 3E

`RAW TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

## Task 4

### 4A

`RAW TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

### 4B

`RAW TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

### 4C

`RAW TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

### 4D

`RAW TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

### 4E

`RAW TEXT NOT AVAILABLE TO EXECUTOR — see Project Chat transcript`

## Learner integrity disclosure after the gate

> YES 1 tí, tôi dùng để tra cứu 1 số tên thanh ghi thôi ko tra cả đáp án

This disclosure means external reference/help was used during the scored phase
to look up some register names. It does not change the raw attempt text, but it
makes this attempt inadmissible as independent competency evidence under the
prospectively declared closed-book contract.
