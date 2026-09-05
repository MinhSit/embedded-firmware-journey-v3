# TODO — W04D03 PWM Measurement

## Metadata and primary outcome

- Week/Day: W04D03; day type: LEARNING.
- Preparation date: 2026-09-05. Canonical day-card date: 2026-09-02 (unchanged).
- Status: W04D03 GREEN / CLOSED / ARTIFACT_PASS — 2026-09-05 END DAY; AI-3 normal learning only.
- Available Focused Time = 6h — learner supplied
- Planned Focused Time: 6h maximum, stop earlier when authoritative stop condition is satisfied.
- Actual Focused Time: ~2h30m — learner estimate.
- External technical help outside Project Chat / Cowork: NO.
- Highest AI level used: AI-3.
- AI mode: normal learning; AI-1/AI-2 before meaningful attempt, AI-3 review after attempt; not an AI-0 competency gate.
- Prerequisite: W04D02 GREEN / CLOSED / ARTIFACT_PASS.
- Primary outcome: learner calculates expected PWM timing, physically measures frequency/duty with the logic analyzer, compares expected versus observed, investigates discrepancies, and produces genuine annotated PWM measurement evidence.
- Executor contribution: neutral preparation, fresh baseline build, visual evidence verification and authorized closure transcription/control updates. Learner screenshots and firmware preserved; no physical measurements or new learner answers supplied.

## Authority and scope

Sources, in precedence order: `docs/system/SYSTEM_SPEC_V3.md` (3.0.0),
`docs/system/EMBEDDED_ROADMAP_V3.1.docx` (Week 4, Day 3: “Đo tín hiệu và đối chiếu tính toán”),
`docs/system/MASTER_PROMPT_V3.md` (3.1.3), and `roadmap-control/current-state.md` (3.0.45 at closure; 3.0.44 at preparation).
The execution runbook and review log govern operational context, not new scoring rules.

MUST items below trace to the day card, higher-authority evidence/AI rules, or
necessary preparation invariants. No generated score, minimum case count beyond
a measured case, or arbitrary percent-error threshold is introduced.

- W04D01 and W04D02 remain CLOSED / ARTIFACT_PASS.
- Latest verified competency remains W03-C-UART-FOUND — COMPETENCY_PASS; no active gate.
- Active execution recovery remains in place; canonical schedule unchanged. W04D04 remains NOT STARTED.
- Week 3 P1 correct-baud UART wire-timing evidence remains due 2026-09-06. PWM evidence does not close it.
- No W04D04 DMA or HardFault work belongs to this pack.

## Required tools and existing inputs

- NUCLEO-F446RE, logic analyzer / PulseView, suitable probe leads and shared ground.
- Existing firmware: `firmware/stm32/w04d02-pwm-uart-shell/` at base `a412a7909611673e3f91293449310aa2629d16c6`.
- Existing W04D02 TODO/submission for context; independently confirm the current configuration rather than treating historical values as a new measurement.
- Official references for the actual board, clock, timer mode, pin and analyzer electrical limits. Record what was verified; do not assume hardware setup from this scaffold.

## Original MUST workflow — retained contract

1. Record the selected target configuration and command sequence in the worksheet. Independently confirm clock/timer data and measurement wiring from the actual setup and applicable official sources.
2. Calculate expected tick, period, frequency, HIGH/LOW time and duty before the physical measurement. Include units and the assumptions used.
3. Build/validate the existing firmware as appropriate to the day card and record the actual command/result. Existing clean-build command, from the firmware directory:

   ```powershell
   powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
   ```

4. Physically acquire PWM in PulseView. Record analyzer settings, channel/pin, capture identity and cursor intervals supporting observed timing. Shell status alone is not a physical measurement.
5. Compare expected and observed frequency/duty using the worksheet. Keep target settings, calculated expectations and observations distinct. If a discrepancy exists, record facts, unknowns, a learner-owned hypothesis and the next measurement; do not invent agreement or a root cause.
6. The day card includes correcting clock/prescaler discrepancies when found. Such technical diagnosis/correction remains learner-owned after verification; this preparation authorizes no firmware repair. Preserve unresolved findings for Project Chat review.
7. Save the genuine original capture and an annotated version. Annotations must identify the measured signal/case and show the timing intervals and values supporting frequency/duty, with visible units. Retain provenance linking annotations to the original.
8. Complete the submission and independently explain the core without AI/documents before closure, as the day card requires. A boundary/error check is required by the card only if the task includes code; do not manufacture a code task for this documentation preparation.

## MUST — evidence and submission contract

- Fill `PWM_MEASUREMENT_WORKSHEET_W04D03.md` with learner calculations, observations, comparison and any unresolved discrepancy.
- Fill `SUBMIT_W04D03.md` with truthful date, firmware/evidence commit, AI usage, setup, commands/results, expected/observed, error, evidence paths, limitations and independent explanation.
- Store real capture/annotation artifacts in this day directory when produced by the learner; none are provided by the executor.
- Evidence metadata must allow the reviewer to identify what/when, hardware, tool/version, command/configuration, expected/actual, AI level and known limitations (Master Prompt section 59). Unknown facts stay explicitly unknown.
- Never infer actual focused time, hardware observations or understanding from this preparation or its build result.

## Authoritative stop condition

Stop when the genuine annotated PWM capture exists, expected/observed are recorded,
open issues are visible, and one next action of 5–15 minutes for the following
session is written. Complete the day-card validation and independent self-check:
explain 2–3 core points or predict a small case with AI/documents closed. If unable,
report YELLOW/UNVERIFIED for review; do not hide it behind a build log.
No arbitrary tolerance or second configuration is a new daily PASS criterion.
Reaching the time limit without required evidence is not completion.
The authorized END DAY records ARTIFACT_PASS from completed learning evidence; no new COMPETENCY_PASS is awarded.

## SHOULD / NON-SCORING

- Repeat the blank case section for a second PWM configuration if useful.
- Use a small multiple-case comparison table if it helps explain results.
- Explore timer/analyzer quantization and uncertainty in more depth; no added scoring threshold.

## Forbidden shortcuts

- No fabricated, copied-as-new, simulated-as-physical or placeholder measurements/images.
- No AI-filled calculations, chosen final hypothesis, root-cause conclusion, independent explanation or competency answer.
- Do not annotate an image that does not exist or alter waveform/cursor data to imply agreement.
- Do not substitute a W04D02 screenshot or UART shell readout for newly claimed measurement evidence.
- No firmware edits, control/log/ledger/scorecard updates, carry-over closure, gate activation or push in this preparation transaction.

## END DAY evidence disposition

- [x] Learner prediction recorded: Case A nominal 16 MHz / PSC=15 / ARR=999 / CCR1=250; 1 kHz / 25% expected timing.
- [x] Genuine 24 MHz PulseView period/HIGH measurements: Screenshot_1.png and Screenshot_2.png.
- [x] Runtime register readback: Screenshot_3.png; source and readback kept distinct from calibrated physical-clock claims.
- [x] Optional 500 Hz cross-check completed: Screenshot_4.png; remains NON-SCORING as an extra case.
- [x] Expected/observed and approximately 0.8% discrepancy documented in the completed worksheet; no sole HSI/analyzer root cause claimed.
- [x] Existing learner cursor annotations retained byte-for-byte; no generated replacement images.
- [x] Fresh clean build PASS / exit 0, text=4876, data=0, bss=1592; inherited nosys warnings only.
- [x] Submission and required daily/AI/current-state closure records populated from authorized session facts.
- Understanding evidence: learner-owned derivation and common-scaling reasoning preserved as a session summary; no verbatim closed-book answer or new scored self-check is invented.
- Code boundary/error check: not applicable to this source-unchanged measurement day; no new coding requirement added.
- Remaining issue: unseparated timing-reference contributions; no unresolved firmware defect demonstrated.
- Preparation restrictions above describe the earlier prep transaction; this separately authorized END DAY permits closure records, one commit and feature-only push.

## Closure handoff

Exact next action: BOOT W04D04 only after Project Chat independently verifies this
END DAY report. First 5–15 minutes: verify closure, read the W04D04 card and complete
the next Day Contract. W04D04 remains NOT STARTED here.
