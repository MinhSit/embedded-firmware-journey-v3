# SUBMIT — Week 03 / Day 02 — USART2 RX interrupt

Complete only with learner-performed, learner-supplied, or tool-verified facts.
Use `NOT RECORDED`, `NOT MEASURED`, or `NOT PERFORMED` instead of inference.
This normal-learning artifact is not independent competency evidence.

## Identity and provenance

- Date: `2026-08-25`
- Board/MCU: `NUCLEO-F446RE` / `STM32F446RETx`
- Actual Focused Time: `3h`
- Highest AI Level Actually Used: `AI-3`
- Commit: `SELF — containing commit`
- AI Disclosure: `Executor prepared compile-clean W03D02 starter/infrastructure only. Learner performed the core USART2 RX interrupt implementation, shared-state implementation, hardware/debug work, register inspection, ORE experiment, and interpretation. Project Chat provided AI-3 review/debugging guidance after learner-first implementation attempts. No independent competency result is claimed.`

## Official-source record

- Reference manual identifier/revision and relevant USART locations: `STM32F446xx Reference Manual RM0390; USART receive, RXNE/RXNEIE, overrun error, and SR/DR clearing behavior consulted. Exact document revision NOT RECORDED.`
- Device header identifier/location used: `firmware/stm32/w03d02-uart-rx-irq-lab/include/stm32f446xx.h`
- Startup/vector source and handler-symbol location: `firmware/stm32/w03d02-uart-rx-irq-lab/startup_stm32f446retx.s`; exact handler symbol verified as `USART2_IRQHandler`
- STM32F446RE datasheet identifier/revision and pin/AF location: `Exact datasheet identifier/revision NOT RECORDED`
- NUCLEO-F446RE board document/schematic identifier/revision: `NOT RECORDED`
- Verified physical connector/debugger signal path: `NUCLEO-F446RE on-board ST-LINK; ST-LINK Virtual COM Port appeared as COM4; debugger connected through ST-LINK GDB Server`
- Unresolved board/version-sensitive facts: `Exact reference-manual revision, datasheet revision, and NUCLEO board-document revision NOT RECORDED`

## USART2 clock and framing baseline

- Actual peripheral clock source/path: `Exact RCC peripheral clock source/path NOT RECORDED`
- Clock frequency used: `16,000,000 Hz passed to uart_init(16000000U, 115200U)`
- Baud and framing: `115200 baud, 8 data bits, no parity, 1 stop bit (115200 8N1)`
- GPIO pins and alternate function: `PA2 = USART2 TX, PA3 = USART2 RX, AF7 — preserved from validated W03D01 USART2 baseline`
- Prior W03D01 baseline preservation check: `PASS during BOOT prep — W03D01 polling implementation was mechanically preserved byte-for-byte`

## Interrupt enable and vector reasoning — learner-owned

- Receive/status condition that causes the IRQ: `A valid received frame is transferred from the receive shift register into USART2 DR; hardware sets RXNE=1 when receive data is available`
- Peripheral interrupt-enable reasoning: `RXNE alone is not sufficient to request the receive interrupt; RXNEIE in USART2 CR1 must also be enabled. Runtime capture showed CR1=0x202C with RXNEIE=1`
- NVIC IRQ/configuration reasoning: `USART2 uses USART2_IRQn. NVIC must enable that IRQ. Runtime capture showed NVIC->ISER[1]=64 (0x40), corresponding to bit 6 for IRQ 38`
- Vector-table and exact handler-symbol reasoning: `The USART2 vector resolves to USART2_IRQHandler. A runtime breakpoint and call stack showed execution inside USART2_IRQHandler after bytes were sent through COM4`
- Receive-state consumption/clear reasoning: `Reading USART2->DR consumes the received byte and clears RXNE in single-buffer receive operation`
- Relevant error-state reasoning: `If another receive completes while previous receive data has not been serviced, USART can assert ORE. The controlled experiment observed ORE=1. The SR-read then DR-read sequence was exercised; afterward ORE and RXNE were both observed cleared`

## Shared-state and work ownership — learner-owned

| Object/state | Producer/writer | Consumer/reader | Visibility/atomicity/ordering reasoning | Full/overwrite/error policy |
|---|---|---|---|---|
| `s_rx_byte` | `USART2_IRQHandler` | foreground through `uart_rx_get_byte()` | Shared between ISR and foreground; foreground temporarily disables `USART2_IRQn` while consuming the mailbox so the USART2 ISR cannot interleave the copy/flag-clear critical section | Single-byte mailbox only; a new byte may overwrite an unconsumed previous byte under burst traffic |
| `s_rx_ready` | `USART2_IRQHandler` sets ready; foreground clears after consuming | foreground `uart_rx_get_byte()` | Used as notification state; foreground brackets the read/copy/clear sequence with `NVIC_DisableIRQ(USART2_IRQn)` / `NVIC_EnableIRQ(USART2_IRQn)` | Binary flag does not count multiple pending bytes; event/data loss remains possible when producer outruns consumer |

- ISR work performed: `Check RXNE/RXNEIE condition, read USART2->DR into s_rx_byte, set s_rx_ready=true, then return`
- Foreground work performed: `Poll uart_rx_get_byte(); when a byte is available, consume the shared mailbox and echo the byte through uart_write_byte()`
- Why the ISR is short/bounded: `ISR performs only receive-condition checking, one DR read, one byte store, and one ready-flag update. Parsing, formatting, and polling TX work are not performed inside the ISR`
- Behavior when a new byte arrives before consumption: `The depth-1 mailbox can be overwritten and a receive event can be lost. The implementation prevents the specific foreground copy/clear race by masking USART2_IRQn during mailbox consumption, but it does not provide queue capacity. Ring buffer support is intentionally deferred beyond W03D02`

## Build evidence

- Working directory: `firmware/stm32/w03d02-uart-rx-irq-lab`
- Exact build command:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

- Exit code/result: `PASS — clean build completed successfully`
- Compiler/linker warnings: `Four inherited non-blocking nosys warnings: _close, _lseek, _read, _write. Linker also emitted the corresponding informational notes that those messages do not take linker garbage collection into account`
- ELF path/result: `build/w03d02-uart-rx-irq-lab.elf — produced successfully`
- Map path/result: `build/w03d02-uart-rx-irq-lab.map — produced by the build workflow`
- List path/result: `build/w03d02-uart-rx-irq-lab.list — produced by the build workflow`
- Size output: `text=1420, data=0, bss=1568, dec=2988, hex=bac`

## Flash, terminal, and physical setup

- Exact flash/debug tool and method/command: `VS Code Cortex-Debug with ST-LINK GDB Server; F5 debug launch loaded the W03D02 ELF to the NUCLEO-F446RE. Exact backend flash command NOT RECORDED`
- Terminal application/version: `VS Code Serial Monitor; exact extension/version NOT RECORDED`
- Terminal command/settings: `COM4, 115200 baud, 8N1, line ending None`
- Physical wiring/connector path: `NUCLEO-F446RE on-board ST-LINK Virtual COM Port exposed as COM4; no external UART jumper wiring was recorded`

## IRQ demo — expected versus observed

- Demo procedure/input: `Open COM4 at 115200 8N1; send individual bytes including A, B, C, 1, 2, x, K, N, and R. During debug, place a breakpoint at the beginning of USART2_IRQHandler and send a byte to prove execution enters the handler`
- Expected result: `Each slow single-byte input should cause USART2 RX interrupt service, move the byte into shared state, allow foreground consumption, and echo the same byte back through USART2 TX`
- Observed result: `A/B/C/1/2/x echoed correctly during the physical smoke test. K and N triggered USART2_IRQHandler during debugger tests and were echoed after Continue. R echoed successfully after the ORE recovery sequence`
- Evidence path/log: `learning/week-03/day-02/Screenshot_1.png` and `learning/week-03/day-02/Screenshot_4.png`
- How the evidence shows the handler actually ran: `Screenshot_1 captures CPU paused at the USART2_IRQHandler breakpoint with USART2 register/NVIC state visible and the call stack showing USART2_IRQHandler`
- Demo result: `PASS — physical USART2 RX interrupt path and foreground echo were observed on hardware`

## Register/debug capture

- Capture tool/method and capture point: `VS Code Cortex-Debug Watch/Call Stack while CPU was halted at the USART2_IRQHandler breakpoint and while stepping the receive path`
- Registers/state captured: `Normal IRQ: USART2->CR1=8236 decimal = 0x202C; USART2->SR=240 decimal = 0xF0; NVIC->ISER[1]=64 decimal = 0x40. Forced overrun: USART2->SR=248 decimal = 0xF8. Recovery after receive-data consumption: USART2->SR=192 decimal = 0xC0`
- Saved evidence path: `learning/week-03/day-02/Screenshot_1.png`, `learning/week-03/day-02/Screenshot_2.png`, `learning/week-03/day-02/Screenshot_3.png`, `learning/week-03/day-02/Screenshot_4.png`
- Learner interpretation: `CR1=0x202C shows UE/TE/RE and RXNEIE enabled; SR=0xF0 at normal IRQ includes RXNE=1; NVIC->ISER[1]=0x40 shows USART2_IRQn enabled; SR=0xF8 adds ORE=1; after the SR->DR recovery sequence SR=0xC0 shows ORE=0 and RXNE=0`

## Controlled negative/error case and restoration

- Selected fault/error condition: `USART2 receive overrun (ORE) caused by deliberately preventing received data from being serviced`
- Prediction before test: `If CPU is halted before USART2->DR is read and additional bytes continue arriving, previous receive data remains unconsumed and USART2 should assert ORE`
- Single controlled change/condition: `CPU was held at the USART2_IRQHandler breakpoint before the DR read while additional serial data was sent through COM4, including burst input such as ABCDEFG and a longer alphanumeric sequence`
- Observed result/evidence: `USART2->SR changed from normal 0xF0 to 0xF8 while servicing was delayed; Screenshot_2.png records the forced-overrun state`
- ORE or other relevant error observation: `ORE=1 observed with USART2->SR=248 decimal = 0xF8`
- Restoration action: `After status had been observed/read, execution was stepped through the USART2->DR read. USART2->SR was then observed as 192 decimal = 0xC0, with ORE=0 and RXNE=0. Execution was continued`
- Post-restoration primary demo result: `PASS — after recovery, byte R was sent through COM4 and echoed back successfully; Screenshot_4.png records the post-recovery runtime result`

## Limitations, blockers, and final boundary

- Known limitations: `Receive storage is a single-byte mailbox (depth=1), not a FIFO/ring buffer. Burst traffic can overwrite/drop data if ISR production outruns foreground consumption. The ready flag does not count multiple pending bytes. Ring buffer, DMA, and parser functionality are intentionally not implemented in W03D02`
- Blockers: `NONE currently observed`
- Artifact result: `ARTIFACT_PASS — W03D02 GREEN / CLOSED`
- Competency result: `NONE — this normal-learning artifact is not an independent competency gate`
- Lifecycle/status: `Learner implementation, final clean build, physical IRQ demo, register capture, controlled ORE fault case, recovery, and post-recovery runtime verification completed; END DAY closure completed on 2026-08-25`
- Build success alone does not prove IRQ behavior, physical hardware behavior, `ARTIFACT_PASS`, or `COMPETENCY_PASS`; the runtime/debug evidence above is recorded separately.
