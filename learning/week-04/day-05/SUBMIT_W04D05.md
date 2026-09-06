# SUBMIT — W04D05 HardFault Triage

## Metadata

- Date: 2026-09-06.
- Result: GREEN / CLOSED / ARTIFACT_PASS.
- Learning mode: normal learning; not a competency gate.
- Available Focused Time: 5h — learner supplied.
- Planned Focused Time: 5h — learner supplied.
- Actual Focused Time: 2h30 — learner supplied.
- Highest AI Level Used: AI-3.
- Commit: SELF — containing closure commit.

## Artifact paths

- `firmware/stm32/w04d05-hardfault-triage/main.c`
- `firmware/stm32/w04d05-hardfault-triage/fault_diag.c`
- `firmware/stm32/w04d05-hardfault-triage/fault_diag.h`
- `learning/week-04/day-05/HARDFAULT_REPORT_W04D05.md`
- `learning/week-04/day-05/Screenshot_1.png`

Screenshot SHA-256:
`7CE0C019B2DC4936EBF33B2638658E26073B6498115D884E6CFB13172F8CC786`.

## Technical result

The controlled data read at `0x00100000` produced a precise BusFault on this
STM32F446RE target/configuration. BusFault was not separately enabled, so the
fault escalated to HardFault. Measured evidence:

- `HFSR = 0x40000000` (`FORCED = 1`)
- `CFSR = 0x00008200` (`PRECISERR = 1`, `BFARVALID = 1`)
- `BFAR = 0x00100000`
- `EXC_RETURN = 0xFFFFFFF9`
- raw stacked R3 = `0x00100000`
- stacked PC = `0x08000206`
- `0x08000206: ldr r3, [r3, #0]`

The first transcribed frame was inconsistent with disassembly. Project Chat
requested raw re-measurement; the corrected frame, BFAR, and disassembly then
converged before the fix was applied.

## Final source and regression

Final source retains `ENABLE_CONTROLLED_FAULT = 0`. The controlled-fault harness
and diagnostic capture implementation remain available for deliberate
reproduction by changing the same switch back to `1`.

Clean-build command from `firmware/stm32/w04d05-hardfault-triage/`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

Executor result: PASS / exit `0`; `text=868`, `data=0`, `bss=1616`, `dec=2484`,
`hex=9b4`. Only inherited `_close`, `_lseek`, `_read`, and `_write` `nosys`
warnings remained; no new compiler warning was observed.

The learner reported that normal execution reached the terminal loop in
`main()`, did not enter `HardFault_Handler`, and did not trigger the breakpoint
in `fault_diag_capture()`. Re-enabling the fault reproduced the same CFSR, HFSR,
BFAR, stacked R3, and stacked PC signature; final source was returned to switch `0`.

The learner-reported size `864/0/1616/2480 (0x9b0)` was four text bytes below
the executor's fresh clean build. Current disassembly contains two explicit
initial Thumb `nop` instructions in `main()` occupying four bytes. Learner source
was preserved; the actual closure build size is recorded above.

## Screenshot scope

`Screenshot_1.png` shows STM32CubeProgrammer reporting loss of connection and
core-ID access during the intentionally faulting configuration. It is classified
as fault/reproduction evidence, not proof of normal-run connectivity.

## Ownership and AI assistance

The learner owned the controlled-fault choice, implementation, first hardware
attempt, status-register and raw-frame measurements, disassembly correlation,
root-cause reasoning, minimal fix, normal regression, and controlled reproduction.

Project Chat provided theory/pre-check and AI-3 post-attempt review. It detected
the inconsistent first transcription and requested raw re-measurement. The
executor supplied neutral starter infrastructure, record formatting,
bookkeeping, and validation only. It did not rewrite learner logic.

## Competency and limitations

No scored competency gate occurred and no new competency result is created.
Latest verified competency remains `W03-C-UART-FOUND — COMPETENCY_PASS`.

This artifact demonstrates one controlled precise BusFault-to-HardFault triage
path. It does not establish production-grade recovery or coverage of every
HardFault class. The separate Week 3 UART timing carry-over remains OPEN.
