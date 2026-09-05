# PWM Measurement Worksheet — W04D03

Completed from the authorized 2026-09-05 session facts and visually verified
learner screenshots. Calculations, physical measurements, runtime readback and
reasoning belong to the learner; executor work is transcription/closure.

## Evidence context

- Date: 2026-09-05; exact acquisition time not recorded in supplied evidence.
- Firmware baseline: `a412a7909611673e3f91293449310aa2629d16c6`; source unchanged.
- Preparation commit: `e8544be8f3542677ddf4e0caa953f75f82dcaa45`.
- Evidence commit: SELF — containing closure commit.
- Hardware: NUCLEO-F446RE with existing W04D02 TIM2_CH1 / PA5 firmware.
- Analyzer: PulseView, device label `Saleae Logic`, channel D0; toolbar shows
  24 MHz and 1 M samples. Device label does not establish vendor authenticity
  or calibration. Exact analyzer hardware revision/PulseView version and wiring
  photograph are not supplied in this evidence set.
- Runtime verification: learner ST-Link / Cortex-Debug / GDB raw-memory readback.
- AI level: AI-3; external technical help outside Project Chat / Cowork: NO.
- Selected settings: 1 kHz / 25%, then 500 Hz / 25%; full shell-command transcript
  is not supplied. No command execution is invented here.
- Source context: `system_stm32f4xx.c` declares nominal
  `uint32_t SystemCoreClock = 16000000U;`; minimal `SystemInit()` does not configure
  the clock tree. Exact official document revisions used during the session are
  not recorded. Nominal source values are not calibrated physical-clock values.

## Case A — target / learner prediction

| Quantity | Pre-measurement prediction |
| --- | --- |
| Target frequency / duty | 1000 Hz / 25% |
| TIM2CLK | 16 MHz nominal |
| PSC / ARR / CCR1 | 15 / 999 / 250 |
| Timer tick | 1 us |
| Expected period | 1000 us |
| Expected frequency | 1000 Hz |
| Expected HIGH | 250 us |
| Expected LOW | 750 us |
| Expected duty | 25% |

Existing source mode: upcounting, edge-aligned PWM Mode 1, active-high.
Prediction above is the learner's recorded derivation, not a new executor solution.

## Case A — observed physical measurement

- `Screenshot_1.png`: rising-edge to rising-edge interval, about 991.913 us;
  inverse period about 1.008153 kHz. Cursor labels are rounded to about
  +8751 us and +9743 us; use the displayed interval, not subtraction of rounded labels.
- `Screenshot_2.png`: rising-edge to falling-edge HIGH interval, about 247.917 us;
  rounded cursor labels about +8751 us and +8999 us.
- Raw UI interval strings retained for traceability: `991.912876 us`,
  `1.008153058 kHz`, `247.916734 us`. These digits are display precision, not
  demonstrated measurement accuracy.
- Observed LOW: not independently cursor-measured in the supplied screenshots.
- Observed duty: approximately 25.0%, derived from HIGH / period; not a separate
  calibrated instrument reading. The inverse HIGH interval shown in Screenshot_2
  is not the PWM repetition frequency.

## Case A — calculated comparison

| Quantity | Expected | Observed, rounded | Signed difference | Signed percent error |
| --- | --- | --- | --- | --- |
| Period | 1000 us | 991.913 us | -8.087 us | -0.81% |
| Frequency | 1000 Hz | 1008.153 Hz | +8.153 Hz | +0.82% |
| HIGH | 250 us | 247.917 us | -2.083 us | -0.83% |
| Duty | 25% | approximately 25.0% | approximately 0 percentage points | not used as a scoring threshold |

Absolute-error magnitudes: approximately 8.087 us, 8.153 Hz and 2.083 us,
respectively. Percent comparison uses `(observed - expected) / expected * 100`.
Within expected quantization/tolerance?: no calibrated combined uncertainty
budget or numeric acceptance tolerance was established; no tolerance PASS claimed.

## Runtime register readback — Case A

`Screenshot_3.png` is the clean learner debugger screenshot; it contains:

| Register | Address | Raw value | Decimal where relevant |
| --- | --- | --- | --- |
| TIM2->PSC | 0x40000028 | 0x0000000f | 15 |
| TIM2->ARR | 0x4000002c | 0x000003e7 | 999 |
| TIM2->CCR1 | 0x40000034 | 0x000000fa | 250 |
| RCC->CFGR | 0x40023808 | 0x00000000 | 0 |

The session's attempted GDB lookup of SystemCoreClock was unavailable in the
final ELF context; the clean screenshot omits that lookup error. This is not
classified as a firmware defect or proof of a different physical clock.

## Case B — 500 Hz cross-check (SHOULD / NON-SCORING, completed)

- Target: 500 Hz / 25%; learner prediction: period 2000 us.
- `Screenshot_4.png`: rising-edge to rising-edge period approximately 1984.864 us,
  inverse period approximately 503.813 Hz; toolbar again shows 24 MHz / 1 M samples.
- Rounded cursor labels: about +8882 us and +10867 us.
- Raw displayed period: `1984.863513 us`; session frequency: approximately
  `503.812979 Hz`. Display digits do not establish calibrated accuracy.
- Period difference: approximately -15.136 us; absolute magnitude 15.136 us;
  period error approximately -0.76%.
- Frequency difference: approximately +3.813 Hz; absolute magnitude 3.813 Hz;
  frequency error approximately +0.76%.
- Separate Case B register readback, HIGH/LOW cursor measurements and an exact
  measured duty value are not supplied; do not copy Case A registers into Case B.

## Discrepancy / hypothesis update

- Observed symptom: timing is consistently about 0.8% faster than the nominal
  calculation while the Case A duty ratio remains approximately 25%.
- Known facts: Case A prediction, physical intervals, runtime PSC/ARR/CCR1/CFGR
  readback, and the second-frequency cross-check recorded above.
- Unknowns: separate MCU clock and analyzer reference errors; no independent
  calibrated timing reference is available in the supplied evidence.
- Learner reasoning preserved from session summary: a common scaling discrepancy
  should not immediately be labeled a firmware defect.
- Hypothesis update: evidence is consistent with a common time-base/reference
  scale difference; neither HSI nor analyzer is isolated as the cause.
- Single next measurement in the recorded investigation: the 500 Hz cross-check;
  result is Case B above, with a similar fractional discrepancy.
- Original word-for-word hypothesis chronology is not supplied; this is a session
  summary, not a reconstructed verbatim learner answer.

### Conclusion

Across the 1 kHz and 500 Hz cases, the measured waveform was consistently
about 0.8% faster than the nominal calculation. Runtime register readback
confirmed PSC=15, ARR=999, CCR1=250 for the 1 kHz / 25% case and RCC->CFGR=0.
The duty ratio remained approximately 25%. The residual discrepancy therefore
behaves like a common time-base/reference scaling discrepancy rather than a
frequency-specific PWM configuration defect. The available evidence does not
distinguish MCU internal-clock tolerance from logic-analyzer reference error,
so neither is claimed as the sole root cause.

No calibration, retuning or compensation was performed. No unresolved firmware
defect is demonstrated; residual reference uncertainty remains visible.

## Evidence filenames and annotation provenance

- `Screenshot_1.png`: original learner screenshot with PulseView period cursors
  and numeric interval/frequency annotation.
- `Screenshot_2.png`: original learner screenshot with HIGH-time cursors and annotation.
- `Screenshot_3.png`: original clean learner runtime register readback screenshot.
- `Screenshot_4.png`: original learner screenshot with cross-check period cursors
  and annotation.

The supplied screenshots already contain the learner's tool annotations; they
are preserved byte-for-byte. No separate executor-annotated image or substitute
capture is generated. A native acquisition file is not supplied in this set.
