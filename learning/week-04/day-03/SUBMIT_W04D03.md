# SUBMIT — W04D03 PWM Measurement

- Task: W04D03 PWM frequency/duty measurement against calculations.
- Date: 2026-09-05.
- Result: GREEN / CLOSED / ARTIFACT_PASS — normal assisted learning evidence.
- Highest AI Level Used: AI-3.
- Commit: SELF — containing closure commit.
- Firmware baseline: `a412a7909611673e3f91293449310aa2629d16c6`, unchanged.
- Available Focused Time: 6h — learner supplied at BOOT.
- Planned Focused Time: maximum 6h; stop earlier when authoritative W04D03 stop condition is satisfied.
- Actual Focused Time: ~2h30m — learner estimate.
- External technical help outside Project Chat / Cowork: NO.

## Files Changed

- `learning/week-04/day-03/TODO_W04D03_PWM_MEASUREMENT.md`
- `learning/week-04/day-03/PWM_MEASUREMENT_WORKSHEET_W04D03.md`
- `learning/week-04/day-03/SUBMIT_W04D03.md`
- `roadmap-control/current-state.md`
- `roadmap-control/daily-log.md`
- `roadmap-control/ai-usage-log.md`
- `learning/week-04/day-03/Screenshot_1.png`
- `learning/week-04/day-03/Screenshot_2.png`
- `learning/week-04/day-03/Screenshot_3.png`
- `learning/week-04/day-03/Screenshot_4.png`

## Build command/result

Fresh closure build from `firmware/stm32/w04d02-pwm-uart-shell/`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

PASS / exit 0. Size: text=4876, data=0, bss=1592, dec=6468, hex=1944.
Only inherited non-blocking nosys linker warnings: _close, _lseek, _read, _write.
No firmware or tests changed. No new hardware run by the executor.

## Measurement setup / Expected / Observed / Calculated error

NUCLEO-F446RE; existing W04D02 PWM firmware; PulseView D0, 24 MHz sample rate,
1 M samples visible; ST-Link / Cortex-Debug / GDB register readback.
Exact tool revisions and full wiring/command transcript are not supplied.

| Case | Expected | Observed, approximate | Comparison |
| --- | --- | --- | --- |
| A: 1 kHz / 25% | tick 1 us; T=1000 us; f=1000 Hz; HIGH=250 us; LOW=750 us | T=991.913 us; f=1008.153 Hz; HIGH=247.917 us; derived duty approximately 25.0% | period -0.81%; frequency +0.82%; HIGH -0.83% |
| B: 500 Hz / 25% | T=2000 us; f=500 Hz | T=1984.864 us; f=503.813 Hz | period -0.76%; frequency +0.76% |

Case A learner prediction: nominal TIM2CLK=16 MHz, PSC=15, ARR=999, CCR1=250.
Readback: PSC 0x0000000f at 0x40000028; ARR 0x000003e7 at 0x4000002c;
CCR1 0x000000fa at 0x40000034; CFGR 0x00000000 at 0x40023808.
No separate observed LOW or Case B register/HIGH-time measurement is claimed.
Raw UI values and detailed separation of evidence are in
`PWM_MEASUREMENT_WORKSHEET_W04D03.md`.

## Evidence

- `Screenshot_1.png`: 1 kHz period/frequency, rising edge to rising edge.
- `Screenshot_2.png`: HIGH time, rising edge to falling edge.
- `Screenshot_3.png`: clean runtime register readback.
- `Screenshot_4.png`: 500 Hz period/frequency cross-check.

All four are genuine learner-supplied screenshots identified by visual inspection
against session facts; preserved without edits. Existing cursor labels are the
measurement annotations. No native acquisition file or calibrated reference is supplied.

## Known failures / Root cause / Questions

No unresolved firmware defect demonstrated. Residual approximately 0.8% common
timing/reference discrepancy remains characterized but not attributed to one
unverified source. No calibration was performed. SystemCoreClock lookup unavailable
in the final ELF context is not a technical defect.

Across the 1 kHz and 500 Hz cases, the measured waveform was consistently
about 0.8% faster than the nominal calculation. Runtime register readback
confirmed PSC=15, ARR=999, CCR1=250 for the 1 kHz / 25% case and RCC->CFGR=0.
The duty ratio remained approximately 25%. The residual discrepancy therefore
behaves like a common time-base/reference scaling discrepancy rather than a
frequency-specific PWM configuration defect. The available evidence does not
distinguish MCU internal-clock tolerance from logic-analyzer reference error,
so neither is claimed as the sole root cause.

Open technical question: relative contributions of MCU internal-clock tolerance
and analyzer reference error remain unresolved; this is not a new daily blocker.

## Independent explanation / AI provenance

Session-summary evidence: learner independently derived Case A before measurement,
placed period/HIGH cursors, acquired the physical waveform, performed runtime
register readback and the 500 Hz cross-check, and reasoned that common scaling
does not by itself prove a firmware defect. Verbatim explanation/self-check answers
are not supplied to the executor; none are reconstructed or separately scored here.

AI supplied AI-1/AI-2 theory/pre-check, timer mental-model/calculation questions
and measurement planning before meaningful work. AI-3 after the attempt covered
calculation/measurement review, PulseView cursor guidance, mismatch interpretation,
debugger workflow, readback review, evidence selection and closure administration.
AI did not acquire physical measurements, fabricate screenshots, alter timer
registers, or supply an independent gate answer.

Competency: normal assisted learning evidence only; NO new COMPETENCY_PASS.
Latest verified competency remains W03-C-UART-FOUND — COMPETENCY_PASS.

## Carry-over / next action

Week 3 correct-baud UART wire-timing P1 remains OPEN, due 2026-09-06; PWM captures
do not close it. Execution recovery remains active. W04D04 remains NOT STARTED.

BOOT W04D04 only after Project Chat independently verifies the complete END DAY
report. First 5–15 minutes: Project Chat verifies closure, then opens the W04D04
day card and establishes the Day Contract; no DMA work starts in this transaction.
