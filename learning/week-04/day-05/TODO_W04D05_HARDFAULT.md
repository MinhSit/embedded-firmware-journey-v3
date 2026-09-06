# W04D05 — HardFault Triage Closure

## Metadata

- Day: W04D05 — HardFault handling / controlled fault / diagnostic triage.
- Canonical date: 2026-09-04.
- Execution/closure date: 2026-09-06.
- Result: GREEN / CLOSED / ARTIFACT_PASS.
- Available Focused Time: 5h — learner supplied.
- Planned Focused Time: 5h — learner supplied.
- Actual Focused Time: 2h30 — learner supplied.
- Interpretation: stop condition achieved early; unused 2h30 is not classified
  as lost or unrecoverable execution variance.
- Highest AI Level Used: AI-3.
- Learning mode: normal learning; not a competency gate.

## Completed learner sequence

- [x] Built and ran the unchanged baseline; recorded expected and observed behavior.
- [x] Defined the controlled fault before implementing it.
- [x] Implemented the controlled 32-bit read from `0x00100000`.
- [x] Reproduced HardFault under the debugger.
- [x] Captured relevant SCB fault status.
- [x] Re-measured and preserved the raw eight-word exception frame after the
  first transcription inconsistency was detected.
- [x] Correlated stacked PC and R3 to source/disassembly.
- [x] Formed an evidence-backed root-cause statement.
- [x] Applied the minimal fix by setting `ENABLE_CONTROLLED_FAULT = 0`.
- [x] Clean-built and ran the normal regression.
- [x] Re-enabled the switch temporarily and retained controlled-fault reproduction.
- [x] Completed `HARDFAULT_REPORT_W04D05.md` with truthful AI assistance.

## Key measured evidence

- `HFSR = 0x40000000`
- `CFSR = 0x00008200`
- `BFAR = 0x00100000`, with `BFARVALID = 1`
- `EXC_RETURN = 0xFFFFFFF9`
- raw stacked R3: `0x00100000`
- stacked PC: `0x08000206`
- faulting instruction: `ldr r3, [r3, #0]`

## Evidence boundary

- `Screenshot_1.png` is fault/reproduction evidence only. It shows
  STM32CubeProgrammer losing connection/core-ID access during the intentionally
  faulting configuration; it is not proof of normal-run connectivity.
- Normal-run status is the learner's debugger/runtime observation.
- The separate Week 3 correct-baud UART wire-timing carry-over remains OPEN and
  is not changed by W04D05 closure.

## Competency boundary

W04D05 is AI-3 normal learning evidence. It awards no new competency result.
Latest verified competency remains `W03-C-UART-FOUND — COMPETENCY_PASS`.

## Stop condition

ACHIEVED — controlled reproduction, measurement-before-fix, corrected raw-frame
evidence, status/context/disassembly correlation, minimal fix, normal regression,
retained reproduction, limitations, and AI provenance are recorded.

## Next action

BOOT W04D06 as a separate transaction. Do not start the Foundation MCU gate or
close the open UART timing carry-over in this W04D05 closure.
