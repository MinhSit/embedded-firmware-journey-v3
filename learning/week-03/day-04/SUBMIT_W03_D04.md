# SUBMIT — Week 03 / Day 04 — Non-blocking UART command parser

This record contains learner-supplied or executor-verified facts only. This
normal-learning artifact is not independent competency evidence.

## Identity and provenance

- Date: `2026-08-27`
- Board/MCU build target: `NUCLEO-F446RE` / `STM32F446RETx`
- Available Focused Time: `6h — learner supplied`
- Planned Focused Time: `6h — learner supplied`
- Actual Focused Time: `2.5h — learner supplied`
- Planned-vs-actual variance: `-3.5h`
- Health impact: `NOT RECORDED`
- Highest AI Level Actually Used: `AI-3`
- Commit: `SELF — containing closure commit`
- AI Disclosure: `Executor prepared W03D04 starter infrastructure, public API,
  visible tests, compile-clean stubs, and closure records. Project Chat provided
  theory, graded hints, post-attempt review, and timeout debugging guidance
  through AI-3. The learner wrote the core parser implementation and explained
  timeout, overlong resynchronization, and ISR/foreground separation.`

## Parser contract and learner-owned design

- Final line-ending policy: `LF and CRLF accepted; empty line emits no event.`
- Final timeout policy/value: `Inter-byte timeout measured from the most recent
  byte; timeout_ticks is supplied at initialization; elapsed time uses unsigned
  (now_tick - last_byte_tick) comparison and remains correct across wrap.`
- Final command grammar: `Exact lowercase ASCII: help; status; led on; led off;
  led toggle; rate 1..10000. Unknown commands and malformed recognized-command
  arguments produce distinct events.`
- Maximum line length: `32 bytes excluding line ending and NUL terminator.`
- Idle invariant: `line_length is 0, line[0] is NUL, line_active is false, and
  discarding_overlong is false.`
- Partial-line invariant: `line_active remains true; accumulated bytes stay
  NUL-terminated; line_length never exceeds 32; last_byte_tick tracks the most
  recent received byte.`
- Overlong/resynchronization invariant: `Byte 33 emits LINE_TOO_LONG once and
  enters discard mode. Suffix bytes are not stored. Discard continues through
  the next newline, then state resets so a later command is parsed cleanly.`
- Timeout transition: `When an active partial line reaches timeout, the parser
  clears line state, emits one TIMEOUT event, and a repeated poll emits no event.`
- Invalid-input recovery: `Unknown or malformed completed lines emit their event,
  reset line state, and do not prevent a later valid command.`
- ISR/foreground/parser ownership: `USART ISR should only push received bytes to
  the ring buffer and return quickly; foreground code feeds bytes to the parser
  and performs command actions.`

## Host test evidence

- Exact compile command: `gcc -std=c17 -Wall -Wextra -Wpedantic -Werror firmware/stm32/w03d04-uart-parser-lab/uart_parser.c tests/host/test_w03d04_uart_parser.c -Ifirmware/stm32/w03d04-uart-parser-lab -o tests/host/test_w03d04_uart_parser.exe`
- Compile exit/result: `PASS / exit 0`
- Exact test command: `.\tests\host\test_w03d04_uart_parser.exe`
- Test exit/result: `PASS / exit 0`
- Test summary: `16 tests, 0 failed`
- Passing coverage: `INIT; HELP_LF; STATUS_CRLF; LED_FORMS;
  RATE_VALID_BOUNDARIES; UNKNOWN_COMMAND; MALFORMED_ARGUMENTS; EMPTY_LINE;
  EXACT_LENGTH_BOUNDARY; OVERLONG_NO_BUFFER_OVERRUN; PARTIAL_LINE_TIMEOUT;
  TIMEOUT_TICK_WRAP; RECOVERY_AFTER_INVALID; RECOVERY_AFTER_OVERLONG;
  RECOVERY_AFTER_TIMEOUT; REPEATED_COMMANDS.`
- Failing test IDs, if any: `NONE`
- Raw output path, if retained: `NOT STORED`

## STM32 build/integration evidence

- Working directory: `firmware/stm32/w03d04-uart-parser-lab`
- Exact build command: `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`
- Exit code/result: `PASS / exit 0`
- Compiler/linker warnings: `Four inherited non-blocking nosys warnings:
  _close, _lseek, _read, and _write are not implemented and will always fail.`
- New W03D04 warnings/errors: `NONE`
- ELF/map/list result: `build/w03d04-uart-parser-lab.elf`,
  `build/w03d04-uart-parser-lab.map`, and
  `build/w03d04-uart-parser-lab.list` — `generated successfully`
- Size output: `text=1720, data=0, bss=1592, dec=3312, hex=cf0`
- Parser/command-action hardware integration performed: `NO — parser core was
  compiled into the STM32 target, but physical command-action behavior was not
  claimed or required for core W03D04 evidence.`

## Learner self-check

- Timeout explanation: `PASS — learner explained partial-line state,
  last_byte_tick updates, wrap-safe elapsed comparison, one-shot reset/event,
  and clean recovery without blocking.`
- Overlong recovery explanation: `PASS — learner explained why byte 33 emits one
  event and why suffix bytes must be discarded until newline before reset.`
- ISR/foreground separation explanation: `PASS — learner explained bounded ISR
  latency, reduced UART loss risk, separation of interrupt and foreground work,
  and improved parser testability/debuggability.`
- Evidence class: `Learning/self-check evidence only; not a competency gate.`

## Hardware evidence

- Hardware parser demo performed: `NOT PERFORMED`
- UART/terminal setup: `NOT RECORDED`
- Physical command observations: `NOT RECORDED`
- LED/status/rate action observations: `NOT RECORDED`
- Evidence paths/logs: `NONE`
- Closure interpretation: `No hardware demo was required for the core W03D04
  parser artifact; no physical behavior is inferred from host tests or build.`

## Final boundary

- Known limitations: `Parser is a hardware-independent core. Command dispatch
  and physical UART/LED/status/rate behavior are outside the evidence claimed by
  this closure. The public contract is the bounded 32-byte LF/CRLF parser tested
  by the visible host suite.`
- Blockers: `NONE`
- Carry-over: `NONE`
- Recovery: `NOT ACTIVE`
- Artifact result: `ARTIFACT_PASS`
- Competency result: `NONE — normal learning day; no competency gate`
- Lifecycle/status: `GREEN / CLOSED`
- Next scheduled day: `W03D05`
