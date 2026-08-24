# SUBMIT — Week 03 / Day 01 — UART clock and polling

Complete only with learner-performed, learner-supplied, or tool-verified facts.
Use `NOT RECORDED` or `NOT MEASURED` instead of inference. This is a normal
learning-day artifact closure, not independent competency evidence.

## Identity and provenance

- Date: `2026-08-24`
- Board/MCU: `NUCLEO-F446RE` / `STM32F446RETx`
- Actual Focused Time: `2h — learner supplied`
- Highest AI Level Used: `AI-3`
- Commit: `SELF — containing commit`

## Official-source record

- RM0390 revision and relevant sections: `NOT RECORDED in the supplied closure evidence`
- STM32F446RE datasheet revision and alternate-function table/location: `NOT RECORDED in the supplied closure evidence`
- NUCLEO-F446RE board document/schematic identifier and revision: `NOT RECORDED in the supplied closure evidence`
- Verified physical connector/debugger signal path: `USART2 serial path observed as COM4; exact board connector/debugger routing was not separately recorded`
- Unresolved board/version-sensitive facts: exact board document revision and connector/debugger routing remain `NOT RECORDED`

## Clock and baud derivation — learner-owned

- UART instance: `USART2`
- Actual peripheral clock source/path: `HSI 16 MHz -> SYSCLK 16 MHz -> HPRE /1 -> HCLK 16 MHz -> PPRE1 /1 -> PCLK1 16 MHz -> USART2`
- Clock frequency used: `16 MHz`
- Intended baud: `115200 baud`
- Oversampling/configuration assumptions: `oversampling by 16; 8 data bits; no parity; 1 stop bit`
- Baud-generation relationship: `BRR = round(fPCLK / baud)` for this oversampling-by-16 configuration
- Rounding/encoding method: `(16000000 + 115200 / 2) / 115200`
- Final baud-register value with calculation: `139 decimal = 0x008B`
- Estimated baud/error, if calculated: `NOT RECORDED — no wire-timing measurement was performed`

## GPIO and USART configuration — learner-owned

- GPIO port/pins and alternate function: `PA2 / PA3, AF7 — supported by the learner source; exact official table citation was not recorded`
- Required clock enables: `GPIOA through RCC AHB1; USART2 through RCC APB1`
- Transmitter/receiver/UART enable flow: disable `UE`; configure explicit oversampling/word length/parity/stop bits and `BRR`; enable `TE`, `RE`, and `UE`
- Polling TX status condition: poll `TXE`, then write the byte to `USART2->DR`
- Polling RX status condition: poll `RXNE`, then read the byte from `USART2->DR`
- Serial framing: `115200, 8N1, oversampling by 16; hardware/software flow control inactive in the terminal`

## Build evidence

- Working directory: `firmware/stm32/w03d01-uart-polling-lab`
- Exact build command:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

- Exit code: `0 — PASS; closure executor reran the clean build`
- Compiler/linker warnings: inherited non-blocking `nosys` warnings for `_close`, `_lseek`, `_read`, and `_write` only
- ELF path/result: `build/w03d01-uart-polling-lab.elf — generated`
- Map path/result: `build/w03d01-uart-polling-lab.map — generated`
- List path/result: `build/w03d01-uart-polling-lab.list — generated`
- Size output: `text=1084, data=0, bss=1568, dec=2652, hex=a5c`

## Flash and terminal configuration

- Exact flash/debug tool and command/method: `STM32CubeProgrammer GUI was used; exact GUI steps/settings and no CLI command were recorded`
- Terminal application/version: `Python pyserial miniterm; version NOT RECORDED`
- Terminal command: `python -m serial.tools.miniterm --parity N COM4 115200`
- Terminal baud: `115200`
- Data bits: `8`
- Parity: `N / none`
- Stop bits: `1`
- Flow control: `hardware and software flow control inactive`
- Physical wiring/connector path used: `COM4 serial path; exact connector/debugger routing NOT RECORDED`

## Expected-versus-observed physical evidence

| Test | Expected | Observed | Evidence path/log | Result |
|---|---|---|---|---|
| Polling TX | Echo received bytes at 115200 8N1 | `UART123` and the ANSI Right Arrow sequence `ESC [ C` were transmitted back | `learning/week-03/day-01/Screenshot_1.png` | `PASS` |
| Polling RX | Receive typed bytes by polling `RXNE` | `UART123` and `ESC [ C` were received and echoed | `learning/week-03/day-01/Screenshot_1.png` | `PASS` |
| Loopback/log at intended baud | Input bytes reappear unchanged | `UART123 -> UART123`; Right Arrow / `ESC [ C -> ESC [ C` | `learning/week-03/day-01/Screenshot_1.png` | `PASS` |

- Baud timing measurement method/result: `NOT MEASURED`
- Logic-analyzer/oscilloscope/terminal capture: terminal capture saved at `learning/week-03/day-01/Screenshot_1.png`; logic-analyzer/oscilloscope timing `NOT MEASURED`
- Controlled mismatch experiment, if used: `NOT PERFORMED — OPTIONAL / NON-SCORING`

## Learner explanation

- Why this clock reaches USART2: reset-clock infrastructure leaves HSI at 16 MHz as SYSCLK; HPRE and PPRE1 are `/1`, so APB1 and USART2 receive 16 MHz
- Why this divider produces the intended baud: with oversampling by 16, `round(16000000 / 115200) = 139 = 0x008B`
- Why each polling condition is required: `TXE` prevents writing before the transmit data register is ready; `RXNE` prevents reading before a received byte is available
- How framing matches the terminal: firmware and miniterm both use `115200, 8N1`, with no active flow control
- How evidence distinguishes clock/divider/framing/path faults: correct readable echo supports the combined clock/divider/framing/path configuration; without a logic-analyzer or oscilloscope measurement it does not independently isolate wire timing

## Limitations and final boundary

- Known failures/limitations: inherited non-blocking `nosys` warnings only; exact official-source locations, exact GUI flashing steps, terminal version, connector/debugger routing, and wire timing were not recorded or measured
- Questions/blockers: `NONE blocking closure`
- Technical day result: `GREEN`
- Artifact result: `ARTIFACT_PASS`
- Lifecycle: `CLOSED`
- Recovery: `NOT ACTIVE`
- Carry-over: `NONE`
- Competency result: `NONE — no new competency result`
- This normal-learning artifact used assistance up to AI-3 and is not independent competency evidence.
