# TODO — Week 03 / Day 03 — UART RX ring-buffer integration

## 0. Metadata

- Date: `2026-08-26`
- Timezone: `Asia/Ho_Chi_Minh`
- System Spec: `SYSTEM_SPEC_V3 3.0.0`
- Roadmap: `EMBEDDED_ROADMAP_V3.1 3.1.0`
- Week/Day: `Week 03 / Day 03`
- Calendar Position: `W03D03`
- Execution Position at preparation time: `W03D03 NOT STARTED`
- Competency Position: `W02-C-MCU-FOUND — COMPETENCY_PASS`
- Available Focused Time: `6h — learner supplied`
- AI Mode: `AI-1/AI-2 during learner implementation; AI-3 only after meaningful attempt`
- Competency status: `normal learning day, no competency gate`
- Board/MCU: `NUCLEO-F446RE` / `STM32F446RETx`
- Authoritative trace: W03D03 roadmap card in `EMBEDDED_ROADMAP_V3.1 3.1.0`

## 1. Outcome

Replace the depth-1 USART2 RX mailbox with a fixed-size SPSC ring buffer,
define and justify bounded overflow behavior and an error counter, and produce
repeatable host/firmware evidence for correct buffering behavior.

## 2. Acceptance Criteria

### MUST — traceable to the authoritative W03D03 roadmap card

- [x] Integrate a fixed-size ring buffer into the USART2 RX interrupt path.
- [x] Define and document one bounded overflow policy before completing the
  policy-specific overflow test.
- [x] Maintain an observable overflow/error counter.
- [x] Pass repeatable host tests for normal FIFO, boundary, invalid-input where
  the API permits it, full/empty, wrap, repeated-wrap, failed-operation state
  preservation, and overflow-counter behavior.
- [x] Clean-build the integrated STM32 firmware and record exact build evidence.
- [x] Record final overflow evidence and counter values from an attributable run.
- [x] Explain producer/consumer ownership, head/tail/state invariants, full versus
  empty, wrap, failed-operation preservation, and overflow transitions in the
  learner's own words without looking at the implementation.

### SHOULD — useful engineering quality, not an added scoring gate

- Keep ISR work short and bounded; leave polling TX and nonessential work in
  foreground.
- Keep the API small, use fixed storage, and avoid unrelated UART refactoring.
- Add concise comments only where ownership or invariants are not obvious.

### BONUS / NON-SCORING

- Add deterministic stress or randomized model-comparison tests after every
  MUST test passes.
- Capture extra debugger observations that help explain shared ISR/foreground
  state, clearly labeled as supplemental evidence.

BONUS items do not change the daily PASS requirements.

## 3. Prerequisites and starter state

- W03D02 is preserved as historical `GREEN / CLOSED / ARTIFACT_PASS` evidence.
- The new firmware directory initially retains the W03D02 depth-1 mailbox
  behavior so its clean build is a known starting point.
- `rx_ring_buffer.h` supplies fixed-size types and a small public API.
- `rx_ring_buffer.c` contains non-working compile-clean TODO stubs only.
- `tests/host/test_w03d03_rx_ring_buffer.c` is visible learning infrastructure;
  its initial behavioral failures are expected.
- Baseline STM32 command: `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`

## 4. Learner TODO

1. Read the starter header and tests. Before coding, write the invariants for
   every empty, partial, and full state represented by `head`, `tail`, and
   `count`.
2. State exactly which context produces bytes and which context consumes them.
   Record the atomicity/visibility assumptions used for ISR/foreground sharing.
3. Choose either a bounded drop-newest or overwrite-oldest policy, or propose
   another bounded policy to Project Chat before changing the API. Explain why
   the chosen behavior fits this UART receive path.
4. Implement init, push, pop, empty/full, occupancy, wrap, and overflow counting
   without dynamic allocation or unbounded loops.
5. Preserve the observable state required by every failed operation. Use the
   failing test ID to diagnose one transition at a time.
6. Run the strict host compile and test commands below until all MUST tests pass.
7. Replace the W03D02 depth-1 mailbox in the new W03D03 UART path with the ring
   buffer. Do not modify W03D02 files.
8. Keep `USART2_IRQHandler` bounded. Decide and explain any critical-section or
   SPSC synchronization assumptions instead of treating `volatile` as a lock.
9. Clean-build firmware, run an attributable normal/overflow demonstration,
   record actual counters/evidence, and complete the submission template.
10. Give the required invariant/state-transition explanation in your own words.

## 5. Host commands

From repository root:

```powershell
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror `
  firmware/stm32/w03d03-uart-ring-buffer-lab/rx_ring_buffer.c `
  tests/host/test_w03d03_rx_ring_buffer.c `
  -Ifirmware/stm32/w03d03-uart-ring-buffer-lab `
  -o tests/host/test_w03d03_rx_ring_buffer.exe

.\tests\host\test_w03d03_rx_ring_buffer.exe
```

## 6. Test / Evidence Matrix

| ID | Requirement / behavior | Expected evidence category |
|---|---|---|
| W03D03-T01 | Init/reset and empty state | Repeatable host test output |
| W03D03-T02 | Invalid input | Repeatable host test output |
| W03D03-T03 | Normal FIFO order | Repeatable host test output |
| W03D03-T04 | One-element boundary | Repeatable host test output |
| W03D03-T05 | Exact-capacity full state | Repeatable host test output |
| W03D03-T06 | Wrap | Repeatable host test output |
| W03D03-T07 | Repeated wrap | Repeatable host test output |
| W03D03-T08 | Failed-operation state preservation | Repeatable host test output |
| W03D03-T09 | Overflow counter | Repeatable host test output plus final counter evidence |
| W03D03-T10 | Learner-selected overflow policy | Declared policy, host output, and learner justification |
| W03D03-T11 | Reinitialization | Repeatable host test output |
| W03D03-F01 | STM32 integration | Clean build plus attributable firmware evidence |

The matrix defines required evidence categories only. Starter preparation does
not record a test, artifact, daily, or competency result.

## 7. Evidence to save

- Exact host and STM32 commands, exit codes, warnings, and host test summary.
- Learner-owned source diff and chosen overflow policy.
- Learner explanation of invariants, producer/consumer ownership, wrap, and
  failed-operation behavior.
- Normal buffering input, expected/observed FIFO output, and attributable log.
- Overflow input/load, expected/observed policy behavior, final counter value,
  and attributable capture/log.
- Hardware/debug facts only when actually observed; otherwise use
  `NOT PERFORMED`, `NOT MEASURED`, or `NOT RECORDED`.

## 8. Definition of Done and boundary

The day is complete only after the learner-owned implementation passes its
repeatable host tests, the integrated STM32 firmware clean-builds, final
overflow/counter evidence is recorded, and the learner can explain the required
invariants and transitions. Starter compilation alone proves infrastructure
only and awards no artifact or competency status.

Forbidden scope: DMA, parser, terminal UI, RTOS primitives, dynamic allocation,
long soak requirements, unrelated refactoring, or retroactive W03D02 changes.

Stop and report instead of guessing if the baseline unexpectedly differs,
official sources conflict, synchronization assumptions cannot be justified, or
passing tests would require an out-of-scope change.

## 9. Exact first learner action

Open `rx_ring_buffer.h` and `test_w03d03_rx_ring_buffer.c`. Before editing C,
write the empty, partial, full, successful-operation, and failed-operation
invariants in your own words and select a bounded overflow policy to justify.
