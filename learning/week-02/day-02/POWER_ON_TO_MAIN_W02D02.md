# W02D02 — Power-on to `main()` Worksheet

Fill this worksheet from direct source/build/debug observations. Do not replace
unknowns with guesses.

## 1. Vector-table observation

Source location: startup_stm32f446retx.s, section .isr_vector, label g_pfnVectors

Learner observations: tại g_pfnVectors: 2 dòng đầu tiên thấy là .word là .word  _estack và .word  Reset_Handler

## 2. First two vector entries

Entry 0 — observed value/symbol and meaning:
_estack — giá trị ban đầu nạp vào MSP, cho CPU biết stack bắt đầu ở đâu.

Entry 1 — observed value/symbol and meaning:
Reset_Handler — địa chỉ đoạn startup code CPU bắt đầu chạy sau reset.

Evidence location:
startup_stm32f446retx.s → section .isr_vector → label g_pfnVectors → hai .word đầu.

## 3. `Reset_Handler` observations

Observed instruction/call sequence:

1. Khởi tạo lại stack: SP = _estack
2. Gọi SystemInit() để chuẩn bị các trạng thái hệ thống/CPU cần thiết
3. Copy .data từ Flash bắt đầu tại _sidata sang RAM từ _sdata đến _edata
4. Zero vùng .bss trong RAM từ _sbss đến _ebss
5. Gọi __libc_init_array() để chạy các initialization function cần chạy trước main()
6. Gọi main()

Questions:
None
## 4. Linker symbols encountered

| Symbol | Defined/used where | Learner reasoning |
|---|---|---|
| _sidata | linker script / Reset_Handler | Điểm bắt đầu của các giá trị khởi tạo `.data` trong Flash |
| _sdata  | linker script / Reset_Handler | Điểm bắt đầu vùng `.data` đích trong RAM |
| _edata  | linker script / Reset_Handler | Điểm kết thúc vùng `.data` trong RAM |
| _sbss | linker script / Reset_Handler | Điểm bắt đầu vùng `.bss` trong RAM, vùng sẽ được zero-initialize |
| _ebss | linker script / Reset_Handler | Điểm kết thúc vùng `.bss` trong RAM |

## 5. `.data` source/destination reasoning

Observed source range:
Bắt đầu tại _sidata trong Flash; số byte copy bằng kích thước vùng _sdata đến _edata.

Observed destination range:
Từ _sdata đến _edata trong RAM.

My reasoning:
Reset_Handler copy các giá trị khởi tạo của .data từ Flash, bắt đầu tại _sidata,
sang vùng .data trong RAM bắt đầu tại _sdata và dừng khi đạt _edata.

## 6. `.bss` reasoning

Observed range:
Từ _sbss đến _ebss trong RAM.

My reasoning:
Reset_Handler zero-fill toàn bộ vùng .bss từ _sbss đến _ebss, nên các biến thuộc .bss sẽ có giá trị ban đầu bằng 0 trước khi vào main().

## 7. `SystemInit` observation

Call location:
Gọi trong Reset_Handler, sau khi gán SP = _estack và trước bước copy .data.

What I directly observed in the source:
Startup source gọi `bl SystemInit`. Comment ngay trên đó mô tả đây là
"clock system initialization function". Sau khi SystemInit trả về,
code tiếp tục copy .data rồi zero .bss.

## 8. Runtime call(s) before `main`

Observed call(s):
__libc_init_array()

Source/map/list evidence:
Trong Reset_Handler của startup_stm32f446retx.s, sau khi zero .bss có:
bl __libc_init_array
sau đó:
bl main

## 9. Map-file observations

ELF/map build identity:
build/w02d02-startup-lab.elf
build/w02d02-startup-lab.map

Symbols/sections observed:
- Reset_Handler: 0x08000204
- SystemInit: 0x08000258
- main: 0x0800027c
- __libc_init_array: 0x08000294
- _sidata: 0x080002fc
- _sdata: 0x20000000
- _edata: 0x20000004
- _sbss: 0x20000004
- _ebss: 0x20000024

Additional observations:
- .data dài 4 bytes vì _edata - _sdata = 0x20000004 - 0x20000000 = 4 bytes.
- .bss dài 32 bytes vì _ebss - _sbss = 0x20000024 - 0x20000004 = 0x20 = 32 bytes.
- _edata = 0x20000004 và _sbss  = 0x20000004 nghĩa là trong build này, .bss bắt đầu ngay sau .data trong RAM.

## 10. Debugger observations

Status: NOT PERFORMED

Expected before measurement:
Khi CPU vào Reset_Handler, MSP/SP được kỳ vọng bằng _estack.
Sau lệnh `ldr sp, =_estack`, SP chắc chắn được nạp lại bằng _estack.

Observed measurement:

Evidence:

## 11. Expected vs observed

| Item | Expected | Observed | Match/mismatch |
|---|---|---|---|
| First two vector entries | Cung cấp địa chỉ stack ban đầu và địa chỉ code startup cần chạy | `_estack` và `Reset_Handler` | Match |
| .data placement | Giá trị khởi tạo nằm trong Flash, runtime .data nằm trong RAM | _sidata = 0x080002fc, _sdata = 0x20000000, _edata = 0x20000004 | Match |
| .bss placement | .bss nằm trong RAM và có một range riêng để zero | _sbss = 0x20000004, _ebss = 0x20000024 | Match |

## 12. Remaining questions

None

## 13. Final closed-book reconstruction

Close the source, map, notes and AI before writing this section.

Learner reconstruction:
Khi reset, CPU đọc vector table và lấy hai entry đầu. _estack cung cấp giá trị ban đầu cho MSP để biết stack nằm ở đâu, còn Reset_Handler cho CPU biết startup code cần bắt đầu chạy ở đâu. Sau đó trong Reset_Handler, SP được gán lại bằng _estack, rồi gọi SystemInit() để chuẩn bị một số trạng thái hệ thống/CPU. Tiếp theo .data được copy từ Flash sang RAM, vùng .bss trong RAM được đưa về 0. Sau đó __libc_init_array() chạy các initialization function cần chạy trước main(), rồi cuối cùng chương trình gọi main().