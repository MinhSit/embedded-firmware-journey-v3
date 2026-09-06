# HardFault Report — W04D05

## Symptom

The controlled data read at `0x00100000` produced a precise BusFault on this
STM32F446RE target/configuration. Because BusFault handling was not separately
enabled, the configurable fault escalated to HardFault. The CPU entered
`HardFault_Handler` and reached the breakpoint in `fault_diag_capture()`.

The purpose was to create a deterministic fault suitable for evidence-based
HardFault triage. This result does not classify `0x00100000` universally for
other targets or configurations.

## Expected

Before measurement, the learner expected:

- the invalid 32-bit `LDR` to produce a BusFault;
- escalation to HardFault because BusFault was not separately enabled;
- `HFSR.FORCED = 1`;
- `CFSR.PRECISERR = 1` and `CFSR.BFARVALID = 1`;
- `BFAR = 0x00100000`;
- the basic exception frame on MSP in bare-metal Thread Mode;
- the stacked PC at the offending `LDR`.

Predicted register values were `HFSR = 0x40000000`, `CFSR = 0x00008200`,
`BFAR = 0x00100000`, and `EXC_RETURN = 0xFFFFFFF9`.

## Reproduction

1. Build with `ENABLE_CONTROLLED_FAULT = 1`.
2. Flash and debug the STM32F446RE target.
3. Run until the controlled read dereferences `0x00100000`.
4. Break in `fault_diag_capture()` and preserve fault status plus the raw basic
   exception frame before applying a fix.

The learner later repeated this controlled-fault mode and observed the same
diagnostic signature. Final committed normal source returns the switch to `0`.

## Known facts

- The CPU entered HardFault and reached `fault_diag_capture()`.
- Fault status and the raw eight-word exception frame were measured before the
  minimal fix.
- The first handwritten/transcribed stacked-context values contained a PC/register
  inconsistency. Project Chat rejected that transcription and requested a direct
  raw-frame re-measurement.
- Corrected PC, R3, BFAR, and disassembly evidence converge on the same access.

## Unknowns

- Other HardFault classes were not exercised.
- Production recovery behavior was not implemented or established.
- Buffered-write/imprecise BusFault behavior was not part of the measured
  required artifact.

## Hypotheses

The working hypothesis was that the intentional dereference of `0x00100000`
caused a precise BusFault and that the disabled separate BusFault handler caused
escalation to HardFault.

## Measurements

At entry to `fault_diag_capture()`:

- R0 / exception-frame pointer: `0x2001FFE0`
- handler LR / EXC_RETURN: `0xFFFFFFF9`
- MSP after the C function prologue: `0x2001FFD8`
- PSP: `0x00000000`

The naked wrapper passed the unchanged exception-frame pointer `0x2001FFE0`.
Handler LR / EXC_RETURN is distinct from the LR stored inside the exception frame.

## Fault-status snapshot

- `HFSR = 0x40000000` — `FORCED = 1`
- `CFSR = 0x00008200` — `PRECISERR = 1`, `BFARVALID = 1`
- `MMFAR = 0x00000000` — `MMFARVALID = 0`
- `BFAR = 0x00100000`

Because `BFARVALID = 1`, the measured BFAR value is valid evidence for this fault.

## Stacked execution context

Raw basic exception frame at `0x2001FFE0`:

| Offset | Field | Value |
| --- | --- | --- |
| `+0x00` | R0 | `0x00000000` |
| `+0x04` | R1 | `0x00000000` |
| `+0x08` | R2 | `0x00000000` |
| `+0x0C` | R3 | `0x00100000` |
| `+0x10` | R12 | `0x00000000` |
| `+0x14` | stacked LR | `0x08000219` |
| `+0x18` | stacked PC | `0x08000206` |
| `+0x1C` | xPSR | `0x61000000` |

## PC/source or disassembly correlation

Learner-recorded instructions:

```text
08000204: 687b    ldr r3, [r7, #4]
08000206: 681b    ldr r3, [r3, #0]
```

At `0x08000204`, R3 receives the pointer value `0x00100000`. The stacked PC is
`0x08000206`, where the instruction dereferences the address held in R3. Raw
stacked R3 and valid BFAR both equal `0x00100000`; execution-context evidence and
fault-address evidence therefore converge on the same data access.

## Root cause

`trigger_controlled_fault()` intentionally dereferenced a pointer whose value
was `0x00100000`. At faulting instruction `0x08000206` (`ldr r3, [r3, #0]`),
stacked R3 was `0x00100000`. The processor reported a precise BusFault through
`CFSR.PRECISERR = 1` and a valid fault address through `BFARVALID = 1`,
`BFAR = 0x00100000`. Because BusFault handling was not enabled separately, it
escalated to HardFault, reflected by `HFSR.FORCED = 1`.

This conclusion was formed from measured status registers, corrected raw stacked
context, and disassembly correlation before the minimal fix.

## Minimal fix

The learner changed the compile-time switch in `main.c` from
`ENABLE_CONTROLLED_FAULT = 1` to `ENABLE_CONTROLLED_FAULT = 0`. This removes the
intentional invalid dereference from the normal path while preserving both the
diagnostic handler and controlled-fault harness. No handler refactor,
architecture change, or unrelated cleanup was made.

## Regression test

Final normal clean build:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

Executor verification passed with exit code `0`: `text=868`, `data=0`,
`bss=1616`, `dec=2484`, `hex=9b4`. Only inherited non-blocking `nosys` warnings
for `_close`, `_lseek`, `_read`, and `_write` remained; there was no new compiler
warning.

The learner reported that the normal run reached the terminal `for (;;)` / `nop`
loop in `main()`, did not enter `HardFault_Handler`, and did not trigger `bkpt #0`
in `fault_diag_capture()`.

With `ENABLE_CONTROLLED_FAULT = 1`, the learner reproduced `CFSR = 0x00008200`,
`HFSR = 0x40000000`, `BFAR = 0x00100000`, stacked R3 `0x00100000`, and stacked
PC `0x08000206`. Final source was returned to `ENABLE_CONTROLLED_FAULT = 0`.

The learner-reported size was `864/0/1616/2480 (0x9b0)`. The executor's fresh
clean build was four text bytes larger. Disassembly shows two explicit initial
Thumb `nop` instructions in `main()` occupying those four bytes; source was
preserved and the actual closure build size is recorded above.

## Side effects

The minimal switch change disables only the intentional invalid dereference in
normal mode. The diagnostic handler and reproduction path remain available as
designed by the compile-time configuration.

## Remaining limitation

This lab demonstrates one controlled precise BusFault-to-HardFault triage path.
It does not prove universal production-grade recovery or coverage of every
HardFault class. A buffered write may behave differently and may produce an
imprecise BusFault; that point was theory/observation, not part of the measured
artifact.

`Screenshot_1.png` is fault/reproduction evidence showing STM32CubeProgrammer
reporting loss of connection/core-ID access during the intentionally faulting
configuration. It is not proof of normal-run connectivity.

## AI assistance used

Highest AI level: AI-3.

The learner first produced a meaningful implementation and hardware measurement.
Project Chat then identified that the first transcribed PC/R3 values conflicted
with the supplied disassembly and requested a raw eight-word exception-frame
dump. The learner re-measured the frame; corrected PC `0x08000206`, R3
`0x00100000`, and BFAR `0x00100000` independently converged. The learner then
selected and implemented the minimal fix and performed regression.

AI did not generate the learner's controlled-fault implementation or measurements.
