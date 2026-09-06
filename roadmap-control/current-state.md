# CURRENT STATE V3 — EMBEDDED/FIRMWARE ROADMAP

**Document ID:** `CURRENT_STATE_V3`
**Version:** `3.0.48`
**State type:** Operational snapshot — describes reality and creates no new policy
**Generated at:** `2026-09-06`
**Timezone:** `Asia/Ho_Chi_Minh`
**Status:** `W04D06 YELLOW / CLOSED / ARTIFACT_PASS; Week 4 ACTIVE; W04D07 NOT STARTED`

---

## Authority

- **System Spec version:** `SYSTEM_SPEC_V3 3.0.0`
- **Roadmap version:** `EMBEDDED_ROADMAP_V3.1 3.1.0`
- **Master Prompt version:** `MASTER_PROMPT_V3 3.1.3`
- **Current State version:** `3.0.48`
- **Implementation runbook:** `roadmap-control/execution-runbook.md` — `NON-AUTHORITATIVE`

If this file conflicts with a higher-authority source, the higher-authority source wins.

## Positions

- **Calendar position:** `2026-09-06 — W04D06 completed after canonical 2026-09-05; W04D07 next; canonical dates unchanged`
- **Execution position:** `W04D06 YELLOW / CLOSED / ARTIFACT_PASS; Week 4 ACTIVE; W04D07 NOT STARTED; CP-02 NOT STARTED`
- **Artifact position:** `W04D06 bounded TIM2/Channel-1 PWM BSP/driver/app refactor complete with clean build and exercised UART/PWM evidence; external review request READY_TO_SEND but REVIEWER_UNASSIGNED / NOT_SENT`
- **Competency position:** `W03-C-UART-FOUND — COMPETENCY_PASS`
- **Last artifact PASS:** `W04D06 bounded BSP/driver/app PWM refactor + review request`, evidence at `learning/week-04/day-06/SUBMIT_W04D06.md`, `REVIEW_REQUEST_W04D06.md`, and `Screenshot_1.png` through `Screenshot_3.png`
- **Last daily assessment PASS:** `W03D07 UART IRQ / parser competency gate — 87/100 PASS / AI-0 CLEAN`, evidence at `learning/week-03/day-07/ASSESSMENT_RESULT_W03D07.md`
- **Last competency PASS:** `W03-C-UART-FOUND — COMPETENCY_PASS (2026-08-31)`

## Competency and AI Integrity

- **Competencies verified:** `W01-C-FOUND — Embedded C foundation (2026-08-15); W02-C-MCU-FOUND — Cortex-M startup, GPIO, and EXTI foundations (2026-08-23); W03-C-UART-FOUND — UART IRQ, ring buffer, and bounded parser foundations (W03D07 AI-0 gate 87/100 PASS, 2026-08-31)`
- **Competencies unverified:** `NONE currently recorded for completed Week 1 through Week 3 P0 foundations`
- **Competencies invalidated/retest required:** The W02D07 original Week 2 gate attempt remains historical `INVALID / RETEST REQUIRED` because external reference lookup occurred during that scored closed-book phase. It was not a technical competency FAIL and is not rewritten. The separate fresh unseen retest passed under a prospectively declared allowed-reference contract and validly awarded `W02-C-MCU-FOUND`.
- **Current AI mode:** `NONE ACTIVE — W04D06 normal learning closed with highest AI-3; W04D07 and CP-02 not started; no active gate`
- **AI-contaminated evidence:** Assisted learning evidence remains separated from independent competency evidence. Detailed per-day assistance for W01D01–W03D06 is preserved in `roadmap-control/ai-usage-log.md`; those assisted artifacts do not independently award competency. W01D06/W01D07 scored phases and the valid W02D07 fresh retest retain their recorded AI-0 boundaries. The W03D07 scored phase was AI-0 CLEAN and independently awards `W03-C-UART-FOUND`; AI-3 review/administration began only after gate closure.
- **W03D06 AI integrity note:** Executor prepared neutral starter/report infrastructure. Project Chat performed the pre-check and post-attempt evidence review. The learner supplied expected behavior, known facts, unknowns, H1, reproduction design, and measurement plan before the physical run. AI later suggested the concrete temporary foreground busy-delay mechanism, but supplied no ring-buffer algorithm patch. W03D06 remains AI-3 artifact evidence only and creates no competency result.
- **W03D07 AI integrity note:** The 65-minute scored phase used AI-0 with paper/pen and ordinary calculator only; scored assistance was NONE. Learner declaration after close was `CLEAN ko dùng bất kì cái gì ngoài máy tình cầm tay`, normalized only as metadata to `CLEAN — no AI/search/notes/other person; ordinary calculator only.` Raw answers are preserved verbatim. AI-3 review and closure administration began only after `CLOSE GATE`.
- **W02D07 integrity note:** The learner disclosed external lookup of some register names during the original scored phase. The declared contract prohibited documentation/search, so that attempt remains historical `INVALID / RETEST REQUIRED`. A separate fresh unseen retest used a prospectively declared AI-0 contract allowing official manual/datasheet/vendor-header lookup only for register/bitfield/IRQ names; learner integrity declaration was `CLEAN`, technical result `PASS`, and official result `COMPETENCY PASS`. Post-close AI-3 career/admin/evidence assistance does not replace the scored answers.

- **W04D03 AI integrity note:** Learner owned prediction, physical capture/cursors, runtime register readback, cross-check and common-scaling reasoning. AI-1/AI-2 preceded meaningful work; AI-3 review/debugger/cursor guidance and closure administration followed attempt. No new competency result; no firmware or screenshot alteration.
- **W04D04 AI integrity note:** Learner independently completed the pre-check reasoning and made meaningful DMA implementation attempts before AI-3 review. Learner owned the register configuration, hardware/debugger execution, success result, predicted and ran the intentional `MINC=0` negative case, then restored `MINC=1`. Project Chat supplied post-attempt review/debugger/evidence guidance; Cowork supplied neutral starter infrastructure and closure bookkeeping. No new competency result.
- **W04D05 AI integrity note:** Learner owned the controlled-fault choice and implementation, first hardware/debugger attempt, fault-register and raw exception-frame measurements, disassembly correlation, root-cause reasoning, minimal fix, normal regression, and controlled reproduction. Project Chat supplied theory/pre-check and AI-3 post-attempt review, rejected an inconsistent first transcription, and requested raw-frame re-measurement. The executor supplied neutral starter infrastructure plus closure formatting/validation only. No new competency result.
- **W04D06 AI integrity note:** Learner owned the target choice, architecture boundaries, dependency invariants, minimal timer-instance/clock injection, clock/PSC reasoning, implementation, build execution, hardware PWM measurement, CMSIS/LL/HAL reasoning, evidence mapping, limitations, self-explanation, and reviewer questions. Project Chat supplied theory/pre-check, post-attempt AI-3 review/debug and evidence/cursor guidance, plus closure orchestration. The executor supplied neutral prep, documentation/bookkeeping, validation, and separately authorized two-space mechanical cleanup only. No new competency result.

## Outcome and Gates

- **Current outcome:** `W04D06 YELLOW / CLOSED / ARTIFACT_PASS — technical/refactor and review-request artifacts complete; external review #1 REVIEWER_UNASSIGNED / NOT_SENT; Week 3 UART wire-timing P1 OPEN; W03-C-UART-FOUND remains latest COMPETENCY_PASS`
- **Status correction:** The previous W01D03 `YELLOW` was based solely on an incomplete generated pre-check flow. Authority audit found that flow was a baseline diagnostic, not a roadmap-required daily completion criterion. Its interruption remains recorded as `MENTOR/SYSTEM WORKFLOW VARIANCE — NON-SCORING`; artifact, AI, competency, schedule and recovery semantics are unchanged.
- **W01D06/W01D07 correction:** `W01D06 is the roadmap's 45-minute independent daily coding gate. W01D07 contains the separate approximately 60-minute Week 1 competency gate required for W01-C-FOUND COMPETENCY_PASS and Week 1 PASS.`
- **Week 1 daily status:** `W01D01 GREEN; W01D02 GREEN; W01D03 GREEN; W01D04 GREEN; W01D05 GREEN; W01D06 GREEN; W01D07 GREEN — FINAL`
- **Week 1:** `PASS / CLOSED`
- **MASTER CHECK:** `COMPLETED — PASS WITH FINDINGS; MEDIUM finding RESOLVED; LOW finding ACCEPTED / NO ACTION`
- **CP-01:** `COMPLETED — RV-002`
- **RR-019:** `APPLIED — CP-01 workflow/learning-feedback amendment; END WEEK added; harder iterative normal practice calibrated; bounded coding-gate feedback is prospective explicit opt-in only; HANDOFF unchanged`
- **Week 2 eligibility:** `YES — ACTIVE`
- **W02D01:** `GREEN / CLOSED / ARTIFACT_PASS`
- **W02D02:** `GREEN / CLOSED / ARTIFACT_PASS`
- **W02D03:** `GREEN / CLOSED / ARTIFACT_PASS`
- **W02D04:** `GREEN / CLOSED / ARTIFACT_PASS — AI-5; NOT independent competency evidence`
- **W02D05:** `GREEN / CLOSED / ARTIFACT_PASS — AI-5; NOT independent competency evidence`
- **W02D06:** `GREEN / CLOSED / ARTIFACT_PASS — AI-3; NOT independent competency evidence`
- **W02D07:** `GREEN / CLOSED — original attempt historical INVALID / RETEST REQUIRED; fresh unseen retest PASS / CLEAN; W02-C-MCU-FOUND COMPETENCY_PASS`
- **Week 2:** `PASS / CLOSED`
- **Week 2 career baseline:** `PASS — CV master skeleton + GitHub profile draft complete; public README NOT DEPLOYED`
- **Week 2 MASTER CHECK:** `PASS WITH LOW FINDINGS — BLOCKER NONE / HIGH NONE`
- **Week 3:** `CONDITIONAL PASS / CLOSED`
- **Week 4 eligibility:** `YES — ACTIVE; W04D06 YELLOW / CLOSED / ARTIFACT_PASS; W04D07 NOT STARTED`
- **W04D03:** `GREEN / CLOSED / ARTIFACT_PASS — AI-3; normal assisted measurement evidence only; NO new competency PASS`
- **W04D04:** `GREEN / CLOSED / ARTIFACT_PASS — AI-3; DMA2 M2M normal-mode success and intentional MINC=0 negative evidence; NO new competency PASS`
- **W04D05:** `GREEN / CLOSED / ARTIFACT_PASS — AI-3; controlled precise BusFault escalated to HardFault, fault status/raw frame/disassembly correlated, minimal switch fix and normal regression recorded; NO new competency PASS`
- **W04D06:** `YELLOW / CLOSED / ARTIFACT_PASS — AI-3 normal assisted learning; bounded TIM2/Channel-1 PWM BSP/driver/app refactor and evidence-backed review request complete; external review required action REVIEWER_UNASSIGNED / NOT_SENT; NO new competency PASS`
- **W04D02:** `GREEN / CLOSED / ARTIFACT_PASS — AI-3; NOT independent competency evidence; TIM2_CH1 PA5 default ~1 kHz / 50% PWM, runtime shell control (10–100000 Hz, 0–100% duty), negative/recovery tests verified on hardware`
- **W04D01:** `GREEN / CLOSED / ARTIFACT_PASS — AI-3; NOT independent competency evidence; initial ~88.9 Hz measurement debugged to 16 MHz clock tree; corrected PSC=15 ARR=999 verified on logic analyzer (~500 Hz / ~2 ms)`
- **W03D01:** `GREEN / CLOSED / ARTIFACT_PASS — AI-3; NOT independent competency evidence`
- **W03D02:** `GREEN / CLOSED / ARTIFACT_PASS — AI-3; NOT independent competency evidence`
- **W03D03:** `GREEN / CLOSED / ARTIFACT_PASS — AI-3; NOT independent competency evidence`
- **W03D04:** `GREEN / CLOSED / ARTIFACT_PASS — AI-3; NOT independent competency evidence`
- **W03D05:** `GREEN / CLOSED / ARTIFACT_PASS — AI-3; NOT independent competency evidence; executed early on 2026-08-27 for the 2026-08-28 roadmap card`
- **W03D06:** `GREEN / CLOSED / ARTIFACT_PASS — AI-3; NOT independent competency evidence; Debug Report #1 completed for controlled RX/ring-buffer overflow`
- **W03D07:** `GREEN / CLOSED — 87/100 PASS / AI-0 CLEAN / W03-C-UART-FOUND COMPETENCY_PASS`
- **Current gate:** `NONE ACTIVE`
- **Gate completed:** `CP-00 Sprint 0 operational/bootstrap gate — CONTINUE (2026-08-09); W01D06-C-CODING-01 daily coding gate — 98/100 PASS (2026-08-15); W01D07 Week 1 C Foundations competency gate — CATEGORICAL PASS / AI-0 integrity PASS (2026-08-15); Week 1 MASTER CHECK — PASS WITH FINDINGS / MEDIUM RESOLVED / LOW ACCEPTED; CP-01 — RV-002 COMPLETED (2026-08-15); W02D07 original attempt — INVALID / RETEST REQUIRED (historical, 2026-08-23); W02D07 fresh unseen retest — PASS / CLEAN / COMPETENCY PASS (2026-08-23); Week 2 MASTER CHECK — PASS WITH LOW FINDINGS; W03D07-UART-IRQ-PARSER-GATE — 87/100 PASS / AI-0 CLEAN / W03-C-UART-FOUND COMPETENCY_PASS (2026-08-31)`
- **Gate missing:** `NONE for Week 3 P0 competency closure`
- **Roadmap review:** `CP-02 boundary reached with W04D07 next; NOT STARTED`; no review finding or gate result was created in this closure.

## Repository

- **Repo URL:** `https://github.com/MinhSit/embedded-firmware-journey-v3`
- **Branch:** `feature/w04d06-refactor-review`
- **Artifact closure:** W04D06 END DAY transaction; commit `SELF — containing closure commit`. Learner refactor source preserved except the separately authorized removal of exactly two trailing spaces; `Screenshot_1.png` through `Screenshot_3.png` retained byte-for-byte.
- **Current operational HEAD:** Resolve from the Git repository at `BOOT`.
- **Release:** `uart-shell-v0.1 — annotated Week 3 milestone tag on the containing closure commit`

## Latest Build and Test

- **Latest validation path:** `learning/week-04/day-06/TODO_W04D06_REFACTOR_REVIEW.md`, `SUBMIT_W04D06.md`, `REVIEW_REQUEST_W04D06.md`, `Screenshot_1.png` through `Screenshot_3.png`, and `firmware/stm32/w04d02-pwm-uart-shell/`.
- **Build/test command:** `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean` from `firmware/stm32/w04d02-pwm-uart-shell/`.
- **Latest build/test result:** STM32 clean build PASS / exit 0 with `text=5168`, `data=0`, `bss=1592`, `dec=6760`, `hex=1a68`; only inherited non-blocking `nosys` warnings for `_close`, `_lseek`, `_read`, and `_write`. Pre-refactor baseline was `4876/0/1592/6468`; observed delta was `+292` text bytes and `0` static-RAM bytes.
- **Latest demo result:** Learner evidence shows the exercised UART shell boot/status, successful `pwm duty 25`, later software status `1000 Hz / 25%`, and rejection of `pwm duty 101`. Physical PWM measurement showed period `992.375 us` (approximately `1.00768 kHz`) and HIGH time `248.042 us` (approximately `25.0%` duty). No regression was observed in the exercised build/UART/PWM cases; exact 1.000 kHz, zero clock error, complete behavior preservation, and full-range hardware validation are not claimed.
- **Earlier W03D06 evidence retained:** controlled UART RX/ring-buffer overflow debug story with measured `overflow_count = 12`, post-overload recovery, and clean regression.
- **Earlier W02D02 evidence retained:** startup-sequence artifact plus supplemental host startup-simulator validation remained `ARTIFACT_PASS` with `30/30` individual cases PASS.

## Hardware and Toolchain

- **Hardware working:** Nucleo-F446RE, ESP32-WROOM-32 dev board, USB data cable, and 8-channel logic analyzer — Sprint 0 `PASS`.
- **Hardware missing/broken:** Broken hardware: `NONE confirmed`. Optional CAN transceiver: `NO`. MPU6050 and jumper wires are present but `NOT_TESTED` electrically.
- **Toolchain versions:** Git `2.49.0.windows.1`; Host GCC `14.2.0`; ARM GCC `13.3.1 / 14.3.1`; CMake `4.0.3`; Python `3.12.0`; pyserial `3.5`; ESP-IDF `v6.0.2`; STM32CubeIDE `2.2.0`; STM32CubeMX `6.18.1`; ST-Link `V2J48M35`; PulseView `0.5.0-git-e2fe9df`; Wireshark `4.6.5 x64`.

## Blockers and Deferred Work

- **Open blockers:** `No P0 technical blocker`; W04D06 external review #1 is `REVIEWER_UNASSIGNED / NOT_SENT`; Week 3 P1 UART direct wire timing remains `OPEN`.
- **W02D07 assessment status:** Original attempt historical `INVALID / RETEST REQUIRED`; no technical FAIL. Fresh unseen retest `PASS / CLEAN`; no further retest required.
- **Known bugs:** `NONE blocking the W04D06 technical artifact`; inherited `nosys` syscall warnings are non-blocking. External review #1 remains unsent. UART wire-timing evidence remains insufficient for P1 closure.
- **Technical debt:** W04D06 PWM injection is validated only on TIM2 / Channel 1 with a current 16 MHz BSP clock assumption; no full frequency/duty wire sweep, dynamic clock-tree adaptation, de-init/re-init lifecycle, concurrency design, or production-generic PWM framework is established. W04D05 demonstrates one controlled precise BusFault-to-HardFault path and does not implement production recovery or cover every HardFault class; buffered-write/imprecise BusFault behavior was not measured. W04D04 uses hard-coded internal DMA source/destination data, leaves its request parameter unused, polls completion, and leaves `HTIF` for the next invocation's initial full Stream 0 flag clear; no production DMA claim is made. W03D03 retains fixed 8-byte RX capacity, DROP_NEWEST loss under sustained overflow, a short USART2 IRQ-disabled foreground critical section, and polling TX. W03D06 did not retain `count/head/tail/storage` snapshots or sufficient UART ORE history; its regression covers the tested 20-byte case, not sustained overload. W03D04 proves the hardware-independent parser core only; physical UART command dispatch and LED/status/rate actions were not performed or claimed. W03D05 persists only complete newline-terminated records, leaves a short pending fragment unpersisted at shutdown, uses a fixed 4096-byte bound, and proves software-delivered bytes rather than electrical wire integrity; flow-control and exact connector/bridge details were not recorded. Verify MPU6050 at the sensor/I2C phase; resolve ESP32 4 MB detected flash versus historical 2 MB project header when creating the clean ESP32 baseline; verify optional physical CAN hardware before any physical-bus claim; validate Wireshark capture workflow in the network/protocol phase.
- **Carry-over:** `W04D06 external review #1 — READY_TO_SEND / REVIEWER_UNASSIGNED / NOT_SENT; Week 3 P1 UART direct wire timing — OPEN / UNCHANGED, measurement attempt completed but retained evidence insufficient for closure`

## Schedule, Load, and Risk

- **Schedule variance:** `W04D06 completed on 2026-09-06 after canonical 2026-09-05; Available Focused Time: 6h — learner supplied; Planned Focused Time: 6h — learner supplied; Actual Focused Time: 4h — learner supplied; variance -2h; reason NOT SUPPLIED and not inferred`
- **Recovery status:** `ACTIVE EXECUTION RECOVERY — W04D06 is closed YELLOW and W04D07 is next as a separate transaction. Canonical dates remain unchanged; do not silently start or execute the Foundation MCU gate.`
- **Critical path risk:** `External review #1 remains unassigned/not sent; Week 3 P1 UART direct wire-timing evidence remains open after an insufficient measurement attempt`; no P0 technical blocker exists.
- **Weekly scorecard:** `roadmap-control/weekly-scorecards/week-03.md — CONDITIONAL PASS / CLOSED`
- **Career pipeline:** `Week 2 baseline PASS — CV master skeleton + ready-to-publish GitHub profile draft complete; public profile README NOT DEPLOYED`
- **Health/load:** `UNRESOLVED for W04D04 — no day-specific learner value supplied and none inferred`; earlier learner-supplied health/load remains historical context only. Execution recovery remains active as recorded above.

## Forward Control

- **Next gate:** `CP-02 — Foundation MCU Gate — 2026-09-06; not currently active`
- **Roadmap calendar start for Week 4:** `2026-08-31`
- **Roadmap calendar start for Week 3:** `2026-08-24`
- **Roadmap calendar start for Week 2:** `2026-08-17`
- **Hard deadline:** `2026-12-14 — project v1.0`
- **Scope cuts:** `NONE active`. If schedule lag occurs later, apply roadmap-defined cut order: cut P2 first, reduce P1 polish, preserve P0.
- **Exact Next Action:** `BOOT W04D07 as a separate transaction after Project Chat independently verifies the W04D06 remote closure; preserve the Foundation MCU gate firewall and do not treat either open item as closed`
- **Files/links to inspect first:**
  - `learning/week-04/day-06/TODO_W04D06_REFACTOR_REVIEW.md`
  - `learning/week-04/day-06/SUBMIT_W04D06.md`
  - `learning/week-04/day-06/REVIEW_REQUEST_W04D06.md`
  - `learning/week-04/day-06/Screenshot_1.png`
  - `learning/week-04/day-06/Screenshot_2.png`
  - `learning/week-04/day-06/Screenshot_3.png`
  - `firmware/stm32/w04d02-pwm-uart-shell/main.c`
  - `firmware/stm32/w04d02-pwm-uart-shell/pwm.c`
  - `firmware/stm32/w04d02-pwm-uart-shell/pwm.h`
  - `firmware/stm32/w04d02-pwm-uart-shell/bsp/bsp_pwm.c`
  - `firmware/stm32/w04d02-pwm-uart-shell/bsp/bsp_pwm.h`
  - `learning/week-04/day-05/HARDFAULT_REPORT_W04D05.md`
  - `learning/week-04/day-05/SUBMIT_W04D05.md`
  - `learning/week-04/day-05/TODO_W04D05_HARDFAULT.md`
  - `learning/week-04/day-05/Screenshot_1.png`
  - `firmware/stm32/w04d05-hardfault-triage/main.c`
  - `firmware/stm32/w04d05-hardfault-triage/fault_diag.c`
  - `firmware/stm32/w04d05-hardfault-triage/fault_diag.h`
  - `learning/week-04/day-04/SUBMIT_W04D04.md`
  - `learning/week-04/day-04/TODO_W04D04_DMA.md`
  - `learning/week-04/day-04/Screenshot_1.png`
  - `learning/week-04/day-04/Screenshot_2.png`
  - `learning/week-04/day-04/Screenshot_3.png`
  - `firmware/stm32/w04d04-dma-mini-lab/dma_m2m.c`
  - `firmware/stm32/w04d04-dma-mini-lab/dma_m2m.h`
  - `firmware/stm32/w04d04-dma-mini-lab/main.c`
  - `learning/week-04/day-03/SUBMIT_W04D03.md`
  - `learning/week-04/day-03/PWM_MEASUREMENT_WORKSHEET_W04D03.md`
  - `learning/week-04/day-03/TODO_W04D03_PWM_MEASUREMENT.md`
  - `learning/week-04/day-03/Screenshot_1.png`
  - `learning/week-04/day-03/Screenshot_2.png`
  - `learning/week-04/day-03/Screenshot_3.png`
  - `learning/week-04/day-03/Screenshot_4.png`
  - `learning/week-04/day-02/Screenshot_1.png`
  - `learning/week-04/day-02/Screenshot_2.png`
  - `learning/week-04/day-02/Screenshot_3.png`
  - `learning/week-04/day-02/SUBMIT_W04D02.md`
  - `learning/week-04/day-02/TODO_W04D02_PWM.md`
  - `firmware/stm32/w04d02-pwm-uart-shell/pwm.c`
  - `firmware/stm32/w04d02-pwm-uart-shell/pwm.h`
  - `firmware/stm32/w04d02-pwm-uart-shell/main.c`
  - `roadmap-control/current-state.md`
  - `roadmap-control/execution-runbook.md`
  - `docs/system/ROADMAP_REVIEW_LOG.md`
  - `roadmap-control/competency-ledger.md`
  - `roadmap-control/ai-usage-log.md`
  - `roadmap-control/daily-log.md`
  - `docs/system/EMBEDDED_ROADMAP_V3.1.docx` — W04D04 day card; Foundation MCU gate remains future/not active
  - `learning/week-03/day-06/TODO_W03_D06.md`
  - `learning/week-03/day-06/DEBUG_REPORT_W03_D06.md`
  - `learning/week-03/day-07/RAW_COMPETENCY_SUBMISSION_W03D07.md`
  - `learning/week-03/day-07/ASSESSMENT_RESULT_W03D07.md`
  - `learning/week-03/day-07/POST_GATE_REVIEW_W03D07.md`
  - `learning/week-03/day-07/SUBMIT_W03_D07.md`
  - `learning/week-03/MASTER_CHECK_DISPOSITION_W03.md`
  - `roadmap-control/weekly-scorecards/week-03.md`
  - `learning/week-03/day-03/SUBMIT_W03_D03.md`
  - `firmware/stm32/w03d03-uart-ring-buffer-lab/main.c`
  - `firmware/stm32/w03d03-uart-ring-buffer-lab/rx_ring_buffer.c`
  - `roadmap-control/weekly-scorecards/week-01.md`
  - `learning/week-02/day-06/TODO_W02_D06.md`
  - `learning/week-02/day-06/SUBMIT_W02_D06.md`
  - `learning/week-02/day-06/DEBOUNCE_LOG_W02D06.md`
  - `learning/week-02/day-06/SCHEMATIC_REVIEW_W02D06.md`
  - `learning/week-02/day-07/RAW_COMPETENCY_SUBMISSION_W02D07.md`
  - `learning/week-02/day-07/ASSESSMENT_RESULT_W02D07.md`
  - `learning/week-02/day-07/POST_GATE_REVIEW_W02D07.md`
  - `learning/week-02/day-07/RAW_COMPETENCY_RETEST_W02D07.md`
  - `learning/week-02/day-07/ASSESSMENT_RESULT_RETEST_W02D07.md`
  - `learning/week-02/day-07/SUBMIT_W02_D07.md`
  - `learning/week-02/CAREER_EVIDENCE_W02.md`
  - `learning/week-02/MASTER_CHECK_W02.md`
  - `roadmap-control/weekly-scorecards/week-02.md`
  - `career/CV_MASTER.md`
  - `career/GITHUB_PROFILE_BASELINE.md`
  - `learning/week-02/day-06/schematic_b1_pc13_page3.png`
  - `learning/week-02/day-06/schematic_pa5_ld2_page5.png`
  - `firmware/stm32/w02d06-debounce-lab/debounce.h`
  - `firmware/stm32/w02d06-debounce-lab/debounce.c`
  - `firmware/stm32/w02d06-debounce-lab/main.c`
  - `tests/host/test_debounce.c`
  - `learning/week-02/startup-simulator/README.md`
  - `learning/week-02/startup-simulator/src/startup.c`
  - `learning/week-02/day-01/TODO_W02_D01.md`
  - `learning/week-02/day-01/CORTEX_M_EXCEPTION_FLOW_W02D01.md`
  - `learning/week-02/day-01/SUBMIT_W02_D01.md`
  - `learning/week-02/day-01/cortex_m_exception_flow.png`
  - `learning/week-01/day-07/RAW_COMPETENCY_SUBMISSION_W01D07.md`
  - `learning/week-01/day-07/RAW_POST_GATE_EXPLANATION_W01D07.md`
  - `learning/week-01/day-07/ASSESSMENT_RESULT_W01D07.md`
  - `learning/week-01/day-07/POST_GATE_REVIEW_W01D07.md`
  - `learning/week-01/day-07/ENGLISH_ORAL_EXPLANATION_W01D07.md`
  - `docs/system/ROADMAP_REVIEW_LOG.md` — `RV-002`

## Operational Note — W02D01

- Previous STM32 baseline source was deleted. This did not block W02D01.
- A clean STM32 project/source context may need preparation for startup/debug
  work in W02D02/W02D03.
- This note is not a W02D01 failure or mandatory carry-over.
