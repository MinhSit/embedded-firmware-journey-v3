# SUBMIT — Week 03 / Day 03 — UART RX ring-buffer integration

Complete only with learner-performed, learner-supplied, or tool-verified facts.
Use `NOT RECORDED`, `NOT MEASURED`, or `NOT PERFORMED` instead of inference.
This normal-learning artifact is not independent competency evidence.

## Identity and provenance

- Date: `2026-08-26`
- Board/MCU: `NUCLEO-F446RE` / `STM32F446RETx`
- Actual Focused Time: `3.5h — learner supplied`
- Highest AI Level Actually Used: `AI-3`
- Commit: `SELF — containing closure commit`
- AI Disclosure: `Executor prepared W03D03 starter infrastructure, TODO/submission templates, compile-clean stubs, and visible host-test scaffolding. Project Chat provided theory, hints, and post-attempt review/debug support through AI-3. The learner owned the final ring-buffer implementation, overflow policy selection, USART2 integration, host/build/hardware execution, physical evidence, and invariant/state-transition explanation.`

## Ring-buffer design — learner-owned

- Capacity and storage model: `Fixed-size 8-byte static storage; no dynamic allocation. State is tracked with head, tail, count, and overflow_count.`
- Producer / writer: `USART2_IRQHandler() is the single producer; each RXNE event reads DR and pushes one byte into the RX ring buffer.`
- Consumer / reader: `Foreground main loop via uart_rx_get_byte(); it pops the oldest buffered byte and then echoes it with polling TX.`
- Empty invariant: `head == tail and count == 0.`
- Partial-state invariant: `head != tail and 0 < count < capacity.`
- Full invariant: `head == tail and count == capacity.`
- Wrap transition reasoning: `On a successful push, head advances by one position; on a successful pop, tail advances by one position. When either index reaches the end of the 8-slot storage, the next position wraps from index 7 to index 0.`
- Failed-operation state-preservation rule: `A failed pop does not change buffer state or the caller's output byte. A failed push under DROP_NEWEST does not overwrite queued data or advance head/tail/count; only overflow_count changes for the full-buffer overflow case. Invalid-input operations return failure without corrupting state.`
- Shared ISR/foreground visibility, atomicity, and ordering assumptions: `Single producer is the USART2 ISR and single consumer is foreground code. Foreground disables USART2_IRQn around rx_ring_buffer_pop(), so the ISR cannot modify shared ring-buffer state during that critical section. No other producer/consumer touches the buffer. volatile alone is not treated as a lock.`

## Overflow policy — learner-owned

- Selected bounded policy: `DROP NEWEST`
- Why this policy fits the USART2 RX path: `When RX is full, keeping already queued bytes preserves the contents and FIFO order of data that was accepted earlier. The trade-off is that newly arriving bytes can be lost, which is made visible through overflow_count.`
- State transition when full and another byte arrives: `The new byte is rejected/dropped; previously buffered data is left unchanged; head, tail, and count remain unchanged; overflow_count increments by 1; push returns false.`
- Overflow/error counter rule: `Increment overflow_count exactly once for each push attempt that arrives while the buffer is full under DROP_NEWEST. Normal successful pushes do not increment it.`

## Host test evidence

- Exact compile command: `gcc -std=c17 -Wall -Wextra -Wpedantic -Werror firmware/stm32/w03d03-uart-ring-buffer-lab/rx_ring_buffer.c tests/host/test_w03d03_rx_ring_buffer.c -Ifirmware/stm32/w03d03-uart-ring-buffer-lab -o tests/host/test_w03d03_rx_ring_buffer.exe`
- Compile exit/result: `PASS / exit 0`
- Exact test command: `.\tests\host\test_w03d03_rx_ring_buffer.exe`
- Test exit/result: `PASS / exit 0`
- Test summary: `11 tests, 0 failed`
- Failing test IDs, if any: `NONE`
- Saved raw output path, if retained: `NOT STORED`

## STM32 build evidence

- Working directory: `firmware/stm32/w03d03-uart-ring-buffer-lab`
- Exact build command: `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`
- Exit code/result: `PASS / exit 0`
- Compiler/linker warnings: `Four inherited non-blocking nosys warnings: _close, _lseek, _read, _write are not implemented and will always fail.`
- ELF/map/list paths and result: `build/w03d03-uart-ring-buffer-lab.elf`, `build/w03d03-uart-ring-buffer-lab.map`, `build/w03d03-uart-ring-buffer-lab.list` — `generated successfully`
- Size output: `text=1720, data=0, bss=1592, dec=3312, hex=cf0`

## Firmware integration evidence

- ISR work performed: `USART2_IRQHandler() checks RXNE/RXNEIE, reads USART2->DR once into a byte, and calls rx_ring_buffer_push(&s_rx_buffer, rx_byte).`
- Foreground work performed: `uart_rx_get_byte() validates the output pointer, disables USART2_IRQn, pops one byte from the ring buffer, re-enables USART2_IRQn, and returns whether a byte was obtained. main() echoes received bytes with uart_write_byte().`
- Why ISR work is bounded/non-blocking: `ISR performs a bounded status check, one DR read, and one fixed-size ring-buffer push. It does not parse, print, perform polling TX, allocate memory, or execute an unbounded loop.`
- Normal input/load and expected result: `Input "UART123" over USART2 at COM4, 115200 8N1; expected exact FIFO echo "UART123".`
- Normal observed result: `UART123`
- Normal evidence path/log: `learning/week-03/day-03/Screenshot_1.png`
- Overflow input/load and expected result: `Input "ABCDEFGHIJKLMNOP" while foreground was intentionally slowed with a temporary busy delay to force an 8-byte RX buffer overflow; expected DROP_NEWEST behavior with accepted queued bytes preserving FIFO order and overflow_count increasing.`
- Overflow observed policy behavior: `Observed truncated FIFO output "BCDEFGHI" during the forced-overflow run; newly arriving bytes were dropped once the buffer filled while queued bytes remained in order.`
- Final overflow/error counter value: `14`
- Overflow evidence path/log: `learning/week-03/day-03/Screenshot_2.png` and `learning/week-03/day-03/Screenshot_3.png`
- Exact flash/debug/terminal method: `Flashed the ELF with STM32CubeProgrammer. UART terminal used VS Code Serial Monitor on COM4 at 115200 baud. Runtime counter was inspected in STM32CubeIDE using GDB Hardware Debugging with arm-none-eabi-gdb connected to ST-LINK_gdbserver over localhost:61234; SWD enabled.`

## Final boundary

- Known limitations: `Fixed 8-byte RX capacity; DROP_NEWEST intentionally loses newly arriving bytes during sustained overflow. Foreground uses a short USART2 IRQ-disabled critical section around pop. TX remains polling. Temporary overflow-forcing delay and overflow_snapshot instrumentation were removed before final host/build verification.`
- Blockers: `NONE`
- Artifact result: `ARTIFACT_PASS`
- Competency result: `NONE — normal learning day; no competency gate`
- Lifecycle/status: `GREEN / CLOSED`

Build or host compilation alone does not prove UART hardware behavior,
`ARTIFACT_PASS`, or `COMPETENCY_PASS`.
