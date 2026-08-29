# TODO — Week 3 / Day 6 — UART Fault Injection and Debugging

## Metadata

- Date: `2026-08-29`
- Week/Day: `W03D06`
- Execution Position: `W03D06 CLOSED / ARTIFACT_PASS`
- Available Focused Time: `5h — learner supplied`
- Planned Focused Time: `5h — learner supplied`
- Actual Focused Time: `3h — learner supplied`
- AI Mode: `AI-1/AI-2 before meaningful attempt only as permitted; AI-3 review/debug only after meaningful attempt`
- Competency Status: `no competency gate today`
- Closure Result: `GREEN / CLOSED / ARTIFACT_PASS — no new competency result`

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

- [x] Fault selected: `RX / ring-buffer overflow`.
- [x] Injection method designed: `temporary foreground busy_delay before uart_rx_get_byte(); USART2 ISR was not deliberately slowed`.
- [x] Expected: `8-byte buffer preserves the first 8 bytes and rejects 12 later pushes under DROP_NEWEST`.
- [x] Observed: `ABCDEFGHIJKLMNOPQRST -> ABCDEFGH`.
- [x] Known facts: `capacity 8; DROP_NEWEST; foreground consumer deliberately slowed`.
- [x] Unknowns: `UART ORE history was not measured sufficiently`.
- [x] Hypothesis H1: `producer/consumer rate imbalance will fill the software RX ring buffer and increment overflow_count`.
- [x] Measurement chosen: `UART output plus software overflow_count; planned ORE/internal snapshots were not fully retained`.
- [x] Measurement result: `overflow_count == 12`.
- [x] Hypothesis update: `software overflow prediction supported; no general claim about hardware ORE`.
- [x] Root cause: `intentional foreground slowdown created the producer/consumer imbalance`.
- [x] Minimal fix: `remove only the temporary busy_delay`.
- [x] Regression: `ABCDEFGHIJKLMNOPQRST -> ABCDEFGHIJKLMNOPQRST; overflow_count == 0`.
- [x] Remaining limitation: `fixed 8-byte capacity, DROP_NEWEST under sustained overload, ORE history NOT MEASURED, and unretained internal snapshots`.

## Day completion checks — authoritative learner-owned requirements

- [x] One fault is intentionally reproducible or created by a clearly defined case.
- [x] Expected and actual behavior are both preserved.
- [x] At least one measurement is recorded before any technical fix.
- [x] The minimum fix is applied only after the evidence narrows the cause.
- [x] A regression check proves the defect does not return in the tested case.
- [x] The learner writes one evidence-based root-cause story.
- [x] Debug Report #1 exists and links the evidence.
- [x] Remaining open issues or limitations are visible.
- [x] One concrete 5–15 minute NEXT ACTION is written.

## Evidence

- Debug report: `learning/week-03/day-06/DEBUG_REPORT_W03_D06.md`
- Raw terminal/test log: `NOT STORED — learner supplied exact Serial Monitor observations in Project Chat`
- Screenshot/capture if applicable: `NOT PERFORMED / NOT RECORDED`
- Regression output: `NOT STORED — exact learner-supplied input/output and overflow_count are preserved in the debug report`

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
