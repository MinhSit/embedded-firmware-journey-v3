# W04D04 — DMA Concepts / Mini-Lab Closure

## Metadata

- Day: W04D04 — DMA concepts / mini-lab.
- Canonical date: 2026-09-03.
- Execution/closure date: 2026-09-05.
- Result: GREEN / CLOSED / ARTIFACT_PASS.
- Available Focused Time: 3h30 — learner supplied.
- Planned Focused Time: UNRECOVERABLE PROCESS VARIANCE — not persisted at BOOT; not reconstructed at closure.
- Actual Focused Time: 2h15 — learner supplied.
- Highest AI Level Used: AI-3.
- Learning mode: NORMAL LEARNING; this was not a competency gate.
- Completed artifact path: minimal DMA2 memory-to-memory hardware demo.
- Roadmap artifact requirement remains: DMA note OR minimal demo.

## Outcome achieved

The learner implemented and ran a bounded STM32F446RE DMA2 memory-to-memory
experiment in normal mode. The success case copied four 32-bit SRAM items. An
intentional `MINC=0` negative case completed at DMA level but produced the
predicted semantically wrong destination, demonstrating that Transfer Complete
does not prove application-level correctness.

## Learning objectives — verified in Project Chat

- [x] Transfer direction and source/destination port roles.
- [x] Normal versus circular mode.
- [x] NDTR as remaining data-item count.
- [x] Source/destination increment behavior.
- [x] Source and destination ownership while DMA may access the buffers.
- [x] Static/global lifetime versus unsafe stack lifetime.
- [x] Completion/error observation.
- [x] Half-buffer/ping-pong ownership concept at theory level only.

These were normal assisted-learning checks, not independent competency evidence.
No verbatim pre-check transcript is reconstructed here.

## Final success configuration

- Target: Nucleo-F446RE / STM32F446RE.
- Controller/path: DMA2 memory-to-memory, source through the peripheral-side
  port and destination through the memory-side port.
- Mode: normal.
- Buffers: source and destination in SRAM with static storage duration.
- Source increment: enabled (`PINC=1`).
- Destination increment: enabled (`MINC=1`) in final source.
- Source and destination widths: 32-bit.
- Initial count: `NDTR=4`.
- FIFO: enabled; direct mode disabled (`DMDIS=1`).
- Observation: polling; no DMA interrupt implementation is claimed.

## Expected versus observed

| Item | Expected before run | Observed | Evidence / status |
| --- | --- | --- | --- |
| Success destination | `{10,20,30,40}` | `{10,20,30,40}` | `Screenshot_2.png` |
| Direction / mode | DMA2 M2M / normal | DMA2 M2M / normal | Source + screenshots |
| Pre-enable addresses | SRAM source/destination | `PAR=0x20000000`, `M0AR=0x20000054` | `Screenshot_1.png` |
| Initial count | `NDTR=4` | `NDTR=4` before enable | `Screenshot_1.png` |
| Final count / enable | `NDTR=0`, `EN=0` | `NDTR=0`, `EN=0` | `Screenshot_2.png` |
| Completion | `TCIF=1` | `TCIF=1` | `Screenshot_2.png` |
| Errors / timeout | `TEIF=0`, `FEIF=0`, `timed_out=0` | all zero | `Screenshot_2.png` |

Interpretation: DMA completed the intended four-item SRAM-to-SRAM transfer.

## Boundary / negative case — intentional `MINC=0`

- Prediction before execution: four configured transfers still complete; all
  stores target `dst[0]`, overwriting it `10 -> 20 -> 30 -> 40`; final
  destination `{40,0,0,0}`; `NDTR=0`, `EN=0`, `TCIF=1`, with no transfer/FIFO
  error or timeout expected.
- Observed: `MINC=0`, destination `{40,0,0,0}`, `NDTR=0`, `EN=0`, `TCIF=1`,
  `TEIF=0`, `FEIF=0`, `timed_out=0`.
- Evidence: `learning/week-04/day-04/Screenshot_3.png`.
- Interpretation: prediction matched observation. Transfer Complete reports
  completion of the configured transfer, not semantic correctness.
- Final-state protection: the intentional negative-test mutation was removed;
  final source restores `MINC=1`.

## Buffer lifetime / ownership record

The source must remain valid and unchanged while DMA may read it. The destination
must remain valid and must not be consumed or modified by the CPU until DMA has
completed or has been safely disabled. Static storage used by this lab remains
alive after the function returns; a short-lived stack buffer would be unsafe if
the transfer could outlive that stack frame. Circular mode would require an
explicit ongoing ownership protocol such as half-buffer handoff; circular DMA
was discussed only and was not implemented.

## Evidence checklist

- [x] `Screenshot_1.png` — supporting pre-enable configuration evidence.
- [x] `Screenshot_2.png` — required success post-transfer evidence.
- [x] `Screenshot_3.png` — required intentional `MINC=0` negative evidence.
- [x] All three PNGs visually verified and retained without pixel edits.
- [x] Clean build PASS / exit 0.
- [x] Build size: text=1056, data=16, bss=1624, dec=2696, hex=a88.
- [x] Only inherited `_close`, `_lseek`, `_read`, `_write` `nosys` warnings.

## Known limitations / characteristics

- The mini-lab intentionally uses hard-coded internal source/destination data;
  the public request parameter is not consumed yet.
- Completion is polled; no interrupt-driven DMA is claimed.
- Circular mode, production driver architecture, UART/ADC DMA, HAL, and LL are
  outside this artifact.
- The post-snapshot flag clear omits `HTIF`; the next invocation's initial full
  Stream 0 flag clear removes it. This is a small lab cleanup characteristic,
  not a demonstrated blocker, and learner source was not changed for it.

## Competency boundary

W04D04 awards no competency result. Latest verified competency remains
`W03-C-UART-FOUND — COMPETENCY_PASS`.

## Stop condition

ACHIEVED — minimal demo exists, success and negative expected/observed facts are
recorded, evidence is retained, limitations are visible, core reasoning was
checked in Project Chat, and the next 5–15 minute action is defined.

## Next action

BOOT W04D05 — read the authoritative HardFault day card and establish the
controlled-fault / diagnostic-report Day Contract. Do not start W04D05 in this
closure transaction.
