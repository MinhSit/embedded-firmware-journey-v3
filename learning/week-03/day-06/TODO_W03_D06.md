# TODO — Week 3 / Day 6 — UART Fault Injection and Debugging

## Metadata

- Date: `2026-08-29`
- Week/Day: `W03D06`
- Execution Position: `W03D06 NOT_STARTED / PREP COMPLETE`
- Available Focused Time: `5h — learner supplied`
- Planned Focused Time: `TBD after Project Chat pre-check`
- AI Mode: `AI-1/AI-2 before meaningful attempt only as permitted; AI-3 review/debug only after meaningful attempt`
- Competency Status: `no competency gate today`

## Outcome

Produce Debug Report #1 for one intentionally reproducible UART fault, preserving
expected versus actual behavior and evidence for the complete sequence
`hypothesis -> measurement -> minimum fix -> regression`, with remaining open
issues visible.

## Mandatory debugging sequence

1. `OBSERVE`
2. `DEFINE EXPECTED`
3. `LOCK ASSUMPTIONS`
4. `FORM HYPOTHESES`
5. `ONE MEASUREMENT`
6. `UPDATE HYPOTHESIS`
7. `MINIMAL FIX`
8. `REGRESSION`
9. `ROOT-CAUSE STORY`

Measure before fixing. Preserve the original failure evidence instead of
replacing it with only the final passing output.

## Fault choices

Choose one; the learner owns the choice, injection design, and diagnosis:

- baud mismatch
- RX/ring-buffer overflow
- parser fault

## PREP BASELINE — not learner fault evidence

The executor reran the existing documented commands before creating this pack.
These results establish only a known-good preparation baseline. They are not a
fault injection, learner measurement, hardware result, daily PASS, artifact
PASS, or competency result.

### W03D03 ring-buffer baseline

From repository root:

```powershell
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror firmware/stm32/w03d03-uart-ring-buffer-lab/rx_ring_buffer.c tests/host/test_w03d03_rx_ring_buffer.c -Ifirmware/stm32/w03d03-uart-ring-buffer-lab -o tests/host/test_w03d03_rx_ring_buffer.exe
.\tests\host\test_w03d03_rx_ring_buffer.exe
```

PREP result: strict compile `PASS / exit 0`; host suite `PASS / exit 0 — 11 tests, 0 failed`.

From `firmware/stm32/w03d03-uart-ring-buffer-lab`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

PREP result: `PASS / exit 0`; size `text=1720, data=0, bss=1592, dec=3312, hex=cf0`.
Warnings: inherited non-blocking `nosys` warnings for `_close`, `_lseek`,
`_read`, and `_write`.

### W03D04 parser baseline

From repository root:

```powershell
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror firmware/stm32/w03d04-uart-parser-lab/uart_parser.c tests/host/test_w03d04_uart_parser.c -Ifirmware/stm32/w03d04-uart-parser-lab -o tests/host/test_w03d04_uart_parser.exe
.\tests\host\test_w03d04_uart_parser.exe
```

PREP result: strict compile `PASS / exit 0`; host suite `PASS / exit 0 — 16 tests, 0 failed`.

From `firmware/stm32/w03d04-uart-parser-lab`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

PREP result: `PASS / exit 0`; size `text=1720, data=0, bss=1592, dec=3312, hex=cf0`.
Warnings: inherited non-blocking `nosys` warnings for `_close`, `_lseek`,
`_read`, and `_write`.

Hardware claims made by preparation: `NONE`.

## Learner-owned checkpoints

- [ ] Fault selected: `<learner fills after selection>`
- [ ] Injection method designed: `<learner fills before injection>`
- [ ] Expected: `<learner fills before measurement>`
- [ ] Observed: `<learner fills from actual evidence>`
- [ ] Known facts: `<learner fills>`
- [ ] Unknowns: `<learner fills>`
- [ ] Hypothesis H1: `<learner fills before fixing>`
- [ ] Measurement chosen: `<learner fills before measurement>`
- [ ] Measurement result: `<learner fills from actual evidence>`
- [ ] Hypothesis update: `<learner fills after measurement>`
- [ ] Root cause: `<learner fills after evidence supports it>`
- [ ] Minimal fix: `<learner fills after measurement>`
- [ ] Regression: `<learner fills from actual rerun>`
- [ ] Remaining limitation: `<learner fills>`

## Day completion checks — authoritative learner-owned requirements

- [ ] One fault is intentionally reproducible or created by a clearly defined case.
- [ ] Expected and actual behavior are both preserved.
- [ ] At least one measurement is recorded before any technical fix.
- [ ] The minimum fix is applied only after the evidence narrows the cause.
- [ ] A regression check proves the defect does not return in the tested case.
- [ ] The learner writes one evidence-based root-cause story.
- [ ] Debug Report #1 exists and links the evidence.
- [ ] Remaining open issues or limitations are visible.
- [ ] One concrete 5–15 minute NEXT ACTION is written.

## Evidence

- Debug report: `learning/week-03/day-06/DEBUG_REPORT_W03_D06.md`
- Raw terminal/test log: `<learner records path after experiment>`
- Screenshot/capture if applicable: `<learner records path or NOT PERFORMED>`
- Regression output: `<learner records path after rerun>`

Do not fabricate or reconstruct missing hardware, terminal, timing, counter, or
test evidence.

## AI boundary

No AI/executor technical review until the learner has supplied
`symptom + expected + meaningful attempt + hypothesis/measurement`.

If AI/executor supplies a core technical patch, the affected competency becomes
`UNVERIFIED` until a fresh independent assessment.

## Forbidden shortcuts

- random edits;
- several fixes at once;
- increasing buffer capacity merely to hide overflow;
- rewriting tests to bless broken behavior;
- deleting failure evidence;
- executor/AI writing the learner's root-cause story;
- AI/executor writing the core fix before meaningful learner attempt.

## Preserved Week 3 P0 context

W03D06 must not weaken the existing Week 3 P0 scope: RX IRQ,
overflow/error counter, non-blocking parser, host tests, and one real
debug/root-cause story.

## Stop condition

Stop when Debug Report #1 exists, expected/actual is recorded, remaining open
issues are visible, and one 5–15 minute NEXT ACTION is written.
