# SUBMIT — W04D04 DMA Concepts / Mini-Lab

- Task: W04D04 DMA concepts / minimal DMA2 M2M demo.
- Date: 2026-09-05.
- Result: GREEN / CLOSED / ARTIFACT_PASS — normal assisted learning evidence.
- Highest AI Level Used: AI-3.
- Commit: SELF — containing closure commit.
- Available Focused Time: 3h30 — learner supplied.
- Planned Focused Time: UNRECOVERABLE PROCESS VARIANCE — not persisted at BOOT; not reconstructed at closure.
- Actual Focused Time: 2h15 — learner supplied.
- External technical help outside Project Chat / Cowork: NO such help reported.

## Ownership and assistance

The learner owned the DMA reasoning, register configuration, implementation
attempts, debugging, flash/debug execution, success test, pre-execution negative
prediction, intentional `MINC=0` experiment, and restoration of the correct
final source.

Cowork generated the neutral start-day scaffold and performed END DAY
bookkeeping/validation only. Project Chat provided theory/pre-check, then AI-3
post-attempt code review, debugger guidance, and evidence interpretation. The
executor made no semantic learner-source change; it removed trailing whitespace
only from `dma_m2m.c` lines 20, 21, and 68.

## Files changed

- 20 starter/firmware paths under `firmware/stm32/w04d04-dma-mini-lab/` and
  `learning/week-04/day-04/` prepared before learner implementation.
- Learner implementation: `main.c`, `dma_m2m.c`, `dma_m2m.h`.
- Evidence: `Screenshot_1.png`, `Screenshot_2.png`, `Screenshot_3.png`.
- Closure records: this submission, `TODO_W04D04_DMA.md`, `PROVENANCE.md`,
  `roadmap-control/current-state.md`, `roadmap-control/daily-log.md`, and
  `roadmap-control/ai-usage-log.md`.
- `roadmap-control/competency-ledger.md` and roadmap review/scorecard files are unchanged.

## Build command / result

From `firmware/stm32/w04d04-dma-mini-lab/`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

PASS / exit 0. Size: text=1056, data=16, bss=1624, dec=2696, hex=a88.
Only inherited non-blocking `nosys` warnings: `_close`, `_lseek`, `_read`, `_write`.

## Test / smoke result

PASS based on learner hardware/debugger evidence. The executor visually verified
the supplied original screenshots but did not rerun the physical hardware test.

## Success case

- Target/configuration: STM32F446RE, DMA2 memory-to-memory, normal mode, SRAM
  source/destination, `PINC=1`, `MINC=1`, 32-bit widths, initial `NDTR=4`, FIFO
  enabled and direct mode disabled.
- Pre-enable: `PAR=0x20000000`, `M0AR=0x20000054`, `NDTR=4`, `EN=0`, `PINC=1`,
  `MINC=1`, `DMDIS=1`.
- Expected destination: `{10,20,30,40}`.
- Observed destination: `{10,20,30,40}`.
- Final observation: `NDTR=0`, `EN=0`, `TCIF=1`, `TEIF=0`, `FEIF=0`,
  `timed_out=0`.
- Interpretation: the intended four-item RAM-to-RAM transfer completed.

## Boundary / negative case

- Intentional temporary change: `MINC=0` while `PINC=1` remained enabled.
- Prediction: each source item overwrites `dst[0]`; final destination
  `{40,0,0,0}`, with transfer complete and no transfer/FIFO error expected.
- Observed: `{40,0,0,0}`, `NDTR=0`, `EN=0`, `TCIF=1`, `TEIF=0`, `FEIF=0`,
  `timed_out=0`.
- Result: prediction matched observation. `TCIF=1` does not prove the
  application-level result is semantically correct.
- Final source: negative mutation removed; `MINC=1` restored.

## DMA direction / mode / ownership

The demo is DMA2 M2M normal mode. Source uses the peripheral-side port and
destination uses the memory-side port. While DMA may access the transfer, source
and destination lifetime must remain valid; CPU ownership resumes only after
completion or safe disable. Static storage provides the required lifetime here.
Circular and half-buffer/ping-pong ownership were explained conceptually but not implemented.

## Evidence

- `learning/week-04/day-04/Screenshot_1.png` — pre-enable/configuration support.
- `learning/week-04/day-04/Screenshot_2.png` — success post-transfer evidence.
- `learning/week-04/day-04/Screenshot_3.png` — intentional `MINC=0` negative evidence.

All images were retained byte-for-byte; no crop, annotation, regeneration, or
pixel alteration was performed by the executor.

## Known failures / limitations

- No unresolved P0 blocker was found.
- Hard-coded internal source/destination data are used; the request parameter is unused.
- Polling only; no DMA interrupt, circular implementation, or production-ready driver is claimed.
- Post-snapshot flag clearing leaves `HTIF` for the next invocation's initial
  full Stream 0 flag clear; this confirmed characteristic did not block the measured demo.
- Planned Focused Time was not persisted and is not reconstructed.

## Competency status

NONE — no new competency result. W04D04 is AI-3 normal learning evidence, not an
independent gate. Latest verified competency remains `W03-C-UART-FOUND`.

## Carry-over

The existing Week 3 P1 correct-baud UART wire-timing / logic-analyzer evidence
remains OPEN, due 2026-09-06. W04D04 does not close it. Schedule recovery remains active.

## Next Action

W04D05 remains NOT_STARTED. BOOT W04D05 only after Project Chat independently
verifies this END DAY report; establish the HardFault controlled-fault /
diagnostic-report Day Contract before implementation.
