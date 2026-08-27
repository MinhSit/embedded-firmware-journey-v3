# TODO — Week 03 / Day 04 — Non-blocking UART command parser

## Metadata

- Date: `2026-08-27`
- Week/Day: `W03D04`
- Day type: `LEARNING`
- Topic: `Non-blocking UART command parser`
- Lifecycle: `NOT STARTED — starter preparation only`
- Available Focused Time: `6h — learner supplied`
- Planned Focused Time: `NOT YET LOCKED — Project Chat resolves after Pre-check`
- Latest independent competency: `W02-C-MCU-FOUND — COMPETENCY_PASS`

## Outcome

Implement a bounded, hardware-independent parser for conceptual `help`, `led`,
`status`, and `rate` commands. It must never block, must define a testable line
timeout, must handle invalid and overlong input, and must recover to accept a
later valid command. End-of-day artifact evidence is the visible parser host
suite. This normal learning day is not a competency gate.

## Roadmap-derived MUST criteria

- [ ] Support command behavior covering `help`, `led`, `status`, and `rate`.
- [ ] Keep the parser non-blocking; no input polling loop inside parser calls.
- [ ] Define and implement line timeout behavior.
- [ ] Reject invalid input without corrupting parser state.
- [ ] Keep all length/bounds behavior memory-safe.
- [ ] Pass repeatable host tests for normal, boundary, invalid, length/bounds,
      timeout, tick-wrap, and state-recovery paths.
- [ ] Explain parser invariants and state transitions without looking at code.
- [ ] Save parser host-test evidence before closure.

## STARTER CONTRACT — implementation detail, not roadmap policy

Project Chat and learner may revise this contract before Focus if needed. If it
changes, update the public API, tests, and TODO together before implementation.

- Line ending: LF; CRLF is accepted. Empty lines produce no event.
- Grammar is lowercase ASCII with exact single spaces and no leading/trailing
  whitespace: `help`, `status`, `led on|off|toggle`, `rate <milliseconds>`.
- `rate` accepts decimal `1..10000` milliseconds.
- Timeout is an inter-byte timeout from the most recent received byte; elapsed
  tick arithmetic must remain correct across `uint32_t` wrap.
- Maximum line length is `UART_PARSER_MAX_LINE_LENGTH` bytes, excluding line
  ending and terminator.
- On the first byte beyond the limit, emit `LINE_TOO_LONG` once, discard through
  the next line ending, reset, and accept a fresh line.
- Unknown command and malformed recognized-command arguments are distinct
  result categories.

## AI boundary

- `AI-1`: theory and concept clarification.
- `AI-2`: graded hints after the learner states an attempt and current model.
- `AI-3`: review/debug only after a meaningful learner implementation attempt.
- The starter contains no core parser solution.
- Do not ask AI for, copy, or accept a completed parser/state-machine patch
  before a meaningful attempt.

## Learner-owned TODOs

- [ ] Write the idle, accumulating, discarding-overlong, completed/error, and
      timeout-reset invariants in your own words before editing `uart_parser.c`.
- [ ] Implement safe initialization and bounded line accumulation.
- [ ] Implement LF/CRLF handling without blocking.
- [ ] Recognize exact commands and reject invalid whitespace/extra arguments.
- [ ] Parse `led` arguments and bounded decimal `rate` without hidden library
      behavior or integer overflow.
- [ ] Implement inter-byte timeout using wrap-safe unsigned tick subtraction.
- [ ] Implement one-shot overlong reporting plus resynchronization at line end.
- [ ] Reset/reuse state after success, invalid input, overlong input, and timeout.
- [ ] Keep hardware command actions outside the parser core.
- [ ] Integrate command dispatch with UART/LED/status/rate only after the host
      parser behavior passes; do not parse inside the ISR.

## Visible test matrix

| Category | Visible cases |
|---|---|
| Normal | `help`, `status`, all documented `led` forms, low/high valid `rate` |
| Invalid | unknown command; malformed `led`; nonnumeric/out-of-range `rate` |
| Empty/boundary | empty line; exactly maximum line length |
| Bounds | overlong line; guard values show no adjacent-memory overwrite |
| Timeout | partial line timeout; one-shot result; `uint32_t` tick wrap |
| Recovery | valid command after invalid, overlong, and timeout input |
| Reuse | repeated commands on one parser instance |

All listed tests are visible roadmap-traceable learning feedback. No hidden
assessment behavior exists. Any later random/stress suite must be labeled
`NON-SCORING learning feedback` unless separately traced to the roadmap.

## Evidence to save later

- Exact strict host compile command, exit code, and complete test summary.
- Learner-owned parser source diff and final starter-contract revisions, if any.
- Expected/actual result for normal, boundary, invalid, timeout, and recovery.
- Clean STM32 build command/result after integration.
- Hardware UART/LED/status/rate observations only if actually performed.
- Highest AI level actually used and the specific assistance received.
- Learner explanation of state invariants, transitions, bounds, and recovery.

## Self-explanation prompts

1. Why is feeding one byte and returning bounded work different from a blocking
   `read_line()` loop?
2. What state must be preserved while a partial line is active?
3. Why does `(uint32_t)(now - then) >= timeout` work across tick wrap?
4. How do you guarantee a line longer than the buffer cannot overwrite memory?
5. How does the parser resynchronize after invalid, overlong, or timed-out input?
6. Why must ISR receive/buffering remain separate from command parsing/actions?

## Forbidden shortcuts

- No blocking receive loop, busy wait, dynamic allocation, `scanf`, or unbounded
  string operation in the parser.
- No parser or command dispatch inside the USART ISR.
- No hidden/reference solution, generated answer file, HAL/LL rewrite, DMA,
  terminal UI, or unrelated W03D03 refactor.
- Do not weaken/delete tests to make an unfinished implementation pass.
- Do not claim UART hardware behavior, artifact PASS, or competency PASS from a
  clean compile alone.

## Validation commands

From repository root:

```powershell
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror firmware/stm32/w03d04-uart-parser-lab/uart_parser.c tests/host/test_w03d04_uart_parser.c -Ifirmware/stm32/w03d04-uart-parser-lab -o tests/host/test_w03d04_uart_parser.exe
.\tests\host\test_w03d04_uart_parser.exe
```

From `firmware/stm32/w03d04-uart-parser-lab`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

Starter expectation: strict compile `PASS`; behavior suite `EXPECTED INITIAL NOT
PASS — learner implementation pending`.

## Authoritative stop condition

Stop only after parser host tests exist and pass, expected/actual results and
remaining defects are visible, and a concrete next action is written. Day
closure, artifact status, AI provenance, and any hardware facts require actual
evidence and the separate authorized END DAY workflow. No competency PASS is
created by W03D04 starter preparation or normal assisted learning.
