# AI USAGE LOG — V3

Log only material assistance that may affect implementation provenance or competency verification.

AI levels:

- AI-0: independent / no AI
- AI-1: theory / clarification
- AI-2: hints
- AI-3: review/debug after meaningful attempt
- AI-4: implementation patch
- AI-5: full/reference solution

---

## Entry Template

### YYYY-MM-DD — Task

Highest AI level:

What AI contributed:

Files/functions materially assisted:

Implementation code provided:
YES / NO

Gate answer revealed:
YES / NO

Competency affected:

Fresh independent retest required:
YES / NO

Notes:

---

## 2026-08-09 — Sprint 0 operational/bootstrap preflight

Highest AI level:
AI-5 for bounded setup/test infrastructure and bookkeeping. This level applies to the assisted artifacts below, not to a competency gate.

What AI contributed:
- preflight sequencing and command guidance;
- diagnosis of stale ESP-IDF CMake/build cache and use of `idf.py fullclean`;
- full host smoke-test source for infrastructure validation;
- bookkeeping updates for preflight, inventory, tool versions, evidence summary, CP-00 review and state;
- interpretation/organization of visual evidence supplied by the learner.

Files/functions materially assisted:
- `tests/host/smoke.c`;
- `roadmap-control/preflight.md`;
- `roadmap-control/inventory.md`;
- `roadmap-control/tool-versions.md`;
- `evidence/sprint-00/preflight-summary.md`;
- `evidence/sprint-00/cp-00-review.md`;
- `evidence/sprint-00/captures/README.md`;
- `roadmap-control/current-state.md` bookkeeping/state content.

Implementation code provided:
YES — `tests/host/smoke.c`, solely as a host-toolchain smoke test.

Gate answer revealed:
NO — Sprint 0 CP-00 is an operational/bootstrap gate, not an Embedded/Firmware competency gate.

Competency affected:
NONE by Sprint 0 assistance. No V3 competency PASS is claimed from these artifacts.

Fresh independent retest required:
NO because of Sprint 0 assistance itself. Separately, pre-V3 Week 1 C competency remains `COMPETENCY_UNVERIFIED / RETEST REQUIRED` and must pass the fresh Week 1 AI-0 gate.

Notes:
AI assistance is deliberately retained in provenance instead of being hidden. Setup/artifact PASS must not be interpreted as competency PASS.

---

## 2026-08-10 — W01D01 Embedded C learning/practice and evidence workflow

Highest AI level:
AI-4 — bounded implementation exposure on E06 after a meaningful learner attempt. Other assistance was AI-1/AI-2/AI-3 theory, hints, review/debug and evidence workflow.

What AI contributed:
- theory and clarification for pointer, array, pointer arithmetic and `const` placement;
- bounded hints during the learner's implementation attempts;
- review and debugging after meaningful learner attempts;
- exact implementation line `*slot = target;` was exposed for E06 `retarget_pointer` after the learner had already attempted the function;
- test/evidence workflow guidance and post-result interpretation.

Files/functions materially assisted:
- `learning/week-01/day-01/TODO_W01_D01.md`;
- E06 `retarget_pointer` implementation provenance;
- W01D01 test/evidence and `roadmap-control/daily-log.md` bookkeeping.

Implementation code provided:
YES — bounded to the exact E06 line `*slot = target;`; no full W01D01 exercise-set solution was provided.

Gate answer revealed:
NO — W01D01 was learning/practice, not the fresh independent Week 1 competency gate.

Competency affected:
No competency PASS is claimed. Because W01D01 had AI-4 implementation exposure, the affected practice cannot serve as independent competency evidence. `W01-C-FOUND` remains `COMPETENCY_UNVERIFIED`.

Fresh independent retest required:
YES — a fresh AI-0 Week 1 competency gate is required before any `W01-C-FOUND` PASS claim.

Notes:
W01D01 learning/practice PASS and host tests 46/46 PASS remain valid artifact evidence. Artifact commit: `aff3d4d`. Daily-log commit: `ab4a578`. Recovery: `NOT ACTIVE`. Next execution: `W01D02`.

---

## 2026-08-11 — W01D02 storage/linkage/memory-map learning and evidence

Highest AI level:
AI-5 — AI provided the complete host experiment source scaffold and substantial
ready-to-paste evidence prose. Theory/hints/review portions also used
AI-1/AI-2/AI-3.

What AI contributed:
- detailed teaching and correction for scope, linkage, storage duration,
  `static`, `extern`, memory placement, build/link stages, and `volatile`;
- complete source scaffold for the multi-translation-unit host experiment;
- build/map/`nm` command guidance and interpretation after learner execution;
- fault-injection procedure and root-cause review after learner prediction;
- substantial Markdown sections/templates for the evidence note;
- END DAY provenance audit and routine bookkeeping.

Files/functions materially assisted:
- `learning/week-01/day-02/storage_demo.h`;
- `learning/week-01/day-02/storage_demo.c`;
- `learning/week-01/day-02/storage_peer.c`;
- `learning/week-01/day-02/memory-map-note.md`;
- W01D02 daily log, AI usage log, and current-state bookkeeping.

Implementation code provided:
YES — complete source scaffold for the W01D02 host experiment, plus substantial
evidence prose. This was an assisted learning/practice artifact, not a
competency-gate solution.

Gate answer revealed:
NO — W01D02 was not the fresh Week 1 competency gate. AI corrected closed-book
practice answers after learner attempts; those corrected answers are not
independent gate evidence.

Competency affected:
No competency PASS is claimed. W01D02 remains valid learning/practice,
artifact, and reproducibility evidence, but cannot independently verify
`W01-C-FOUND`. Status remains `COMPETENCY_UNVERIFIED`.

Fresh independent retest required:
YES — a fresh AI-0 Week 1 competency gate is required before any
`W01-C-FOUND` PASS claim.

Notes:
Final baseline build/runtime passed with output `11 20 0 6 W01D02`. The
generated `storage_demo.map` remains ignored by `*.map` policy and was not
force-added. Recovery: `NOT ACTIVE`. Next execution: `W01D03`.

---

## 2026-08-12 — W01D03 struct/alignment/union/endian learning and evidence

Highest AI level:
AI-4 — bounded code/syntax assistance after learner attempts. Theory, hints and
review/debug also used AI-1/AI-2/AI-3.

What AI contributed:
- theory and clarification for struct padding/alignment, union/enum and endian;
- hints and review/debug after learner attempts;
- bounded code/syntax assistance in the W01D03 implementation;
- AI-assisted wording for Section 7 of `alignment-note.md`;
- closure audit, evidence metadata and routine bookkeeping.

Files/functions materially assisted:
- `learning/week-01/day-03/struct_layout.c`;
- `learning/week-01/day-03/alignment-note.md`, especially Section 7 wording;
- W01D03 TODO/SUBMIT, evidence metadata and control-file bookkeeping.

Implementation code provided:
YES — bounded code/syntax assistance after learner attempts. The repository does
not preserve a finer-grained transcript, so provenance is conservatively AI-4.

Gate answer revealed:
NO — W01D03 was learning/practice, not the fresh Week 1 competency gate. The
later closed-book retest is recorded as practice-level evidence only.

Competency affected:
No competency PASS is claimed. W01D03 remains valid artifact/practice evidence,
but it cannot independently verify `W01-C-FOUND`; status remains
`COMPETENCY_UNVERIFIED`.

Fresh independent retest required:
YES — a fresh AI-0 Week 1 competency gate is required before any
`W01-C-FOUND — COMPETENCY_PASS` claim.

Notes:
Strict build and 25/25 host tests passed. The original generated pre-check flow
was interrupted when the learner disclosed missing prerequisite knowledge and
the mentor switched to theory-first teaching. It remains historical
`MENTOR/SYSTEM WORKFLOW VARIANCE — NON-SCORING`, not learner non-compliance or
competency evidence. Initial closed-book practice was 6 PASS / 1 PARTIAL; a
fresh unhinted practice retest later identified both ABI/layout-padding and
endian risks. AI-4 remains unchanged, and competency remains unverified because
the fresh Week 1 AI-0 gate is outstanding. Recovery: `NOT ACTIVE`. Next
execution: `W01D04`.

---

## 2026-08-13 — W01D04 safe bit-operations learning and evidence

Highest AI level:
AI-3 — review/debug after meaningful learner attempts. Theory, clarification and
hints also used AI-1/AI-2.

What AI contributed:
- short theory and clarification about safe shifts, validation and masks;
- hint-level guidance and explanation of a pointer-versus-bit mistake;
- a generic bit-mask syntax example, not a complete exact solution;
- review/debug of learner-written validation and implementation after meaningful
  attempts, including correctness and UB reasoning;
- feedback on closed-book explanations and additional AND/OR mask practice;
- closure audit, evidence metadata and routine bookkeeping.

Files/functions materially assisted:
- review of learner-written `learning/week-01/day-04/bit_ops.c` after attempts;
- W01D04 self-explanation feedback, evidence metadata and control bookkeeping.

Implementation code provided:
NO — AI did not provide a complete or exact `bit_ops` solution. The learner
wrote the core implementations.

Gate answer revealed:
NO — W01D04 was learning/practice, not the fresh Week 1 AI-0 competency gate.
Corrected practice explanations are not independent E5 evidence.

Competency affected:
No competency PASS is claimed. W01D04 remains valid artifact/practice evidence,
but it cannot independently verify `W01-C-FOUND`; status remains
`COMPETENCY_UNVERIFIED`.

Fresh independent retest required:
YES — a fresh AI-0 Week 1 competency gate is required before any
`W01-C-FOUND — COMPETENCY_PASS` claim.

Notes:
Strict build and 34/34 visible host tests passed. Runtime validation handles
caller-controlled invalid inputs; no cosmetic assert was added because no
additional useful internal invariant was identified. Recovery: `NOT ACTIVE`.
Next execution: `W01D05`.

---

## 2026-08-14 — W01D05 fixed-size ring-buffer learning and evidence

Highest AI level:
AI-3 — post-attempt review after the learner completed the implementation.
Theory and design work also used AI-1/AI-2.

What AI contributed:
- AI-1 theory and clarification about ring-buffer concepts and invariants;
- AI-2 graded hints, design questioning and API discussion before implementation;
- mirrored confirmation of push/pop state transitions only after the learner
  had stated that logic;
- AI-3 review of the learner-completed implementation and closed-book reasoning;
- closure audit, evidence metadata and routine bookkeeping.

Files/functions materially assisted:
- post-attempt review of the learner-written
  `learning/week-01/day-05/ring_buffer.c` and public API contract;
- W01D05 reasoning feedback, evidence metadata and control bookkeeping.

Implementation code provided:
NO AI-4/AI-5 substitute implementation — the learner derived and implemented
the final ring-buffer core. Later code-like mirroring confirmed learner-stated
state transitions and did not replace learner ownership.

Gate answer revealed:
NO — W01D05 was learning/practice, not the fresh Week 1 AI-0 competency gate.
The closed-book practice explanation satisfies only the W01D05 stop condition.

Competency affected:
No competency PASS is claimed. W01D05 remains valid artifact/practice evidence,
but it cannot independently verify `W01-C-FOUND`; status remains
`COMPETENCY_UNVERIFIED`.

Fresh independent retest required:
YES — a fresh AI-0 Week 1 competency gate is required before any
`W01-C-FOUND — COMPETENCY_PASS` claim.

Notes:
Strict build passed and two consecutive visible-suite runs each reported 36/36
tests PASS. Required NORMAL, EMPTY, FULL, WRAP, repeated-wrap and INVALID INPUT
categories passed. Recovery: `NOT ACTIVE`. Next execution: `W01D06`.

---

## 2026-08-15 — W01D06 independent C coding assessment and post-close review

Assessment ID:
`W01D06-C-CODING-01`

Scored phase AI level:
AI-0 — independent / closed book.

External help during scored phase:
NO.

Scored-phase integrity:
PASS — no external AI, search, notes, old code or solution assistance was used
during `START GATE` through `CLOSE ATTEMPT`. The learner sent work to ChatGPT
before closure, but ChatGPT withheld review, hints and correctness feedback until
after `CLOSE ATTEMPT`.

Post-close AI level:
AI-3 — review, assessment and correction discussion after the attempt closed.

What AI contributed after close:
- reviewed and scored the preserved submission;
- clarified that `memcpy(dst, src, sizeof(src))` may read beyond the source
  object and therefore has undefined behavior, not guaranteed "garbage";
- created and ran post-close executor boundary tests;
- prepared evidence metadata and routine END DAY bookkeeping.

Files/functions materially assisted:
- No raw `.c` file was assisted or modified.
- `POST_GATE_REVIEW_W01D06.md`, `ASSESSMENT_RESULT_W01D06.md`, executor-created
  test/evidence and control bookkeeping were prepared after close.

Implementation code provided during scored phase:
NO.

Gate answer revealed during scored phase:
NO.

Raw result:
`98/100 PASS` — Task 1 35/35; Task 2 28/30; Task 3 20/20; Task 4 15/15;
mandatory items PASS.

Competency affected:
The W01D06 daily coding-gate result is valid AI-0 assessment evidence, but it is
not the roadmap's separate W01D07 Week 1 competency gate. No competency PASS is
claimed; `W01-C-FOUND` remains `COMPETENCY_UNVERIFIED`.

Fresh independent retest required:
NO for the passed W01D06 daily coding gate. W01D07 remains the separate required
60-minute Week 1 AI-0 competency gate, not a retest of W01D06.

Notes:
Raw source hashes were preserved. Strict C17 builds passed; the learner-authored
Task 1 runner reported seven PASS results; the executor-created post-close
harness reported 14 tests, 0 failed. Recovery: `NOT ACTIVE`. Next execution:
`W01D07`.

---

## 2026-08-15 — W01D07 Week 1 C Foundations competency gate and post-gate review

Assessment:
`Week 1 C Foundations competency gate`

Competency ID:
`W01-C-FOUND`

Scored phase AI level:
AI-0 — independent / closed book.

External help during scored phase:
NO — learner human confirmation.

Scored-phase integrity:
PASS — the assessment scope, 60-minute maximum and AI firewall were established
before the attempt. The learner completed before the hard stop and explicitly
sent `CLOSE GATE`; no prohibited assistance was provided during the scored
phase.

Post-close AI level:
AI-3 — assessment/review and administrative persistence after the gate closed.

What AI contributed after close:
- preserved the recovered learner chat submission and volatile/UB explanation
  as separate verbatim raw evidence;
- authored the assessment result and post-gate review, keeping precision
  caveats separate from raw evidence;
- prepared the bounded control-file bookkeeping and repository transaction.

Files/functions materially assisted:
- No learner-created Day07 `.c` file existed during the scored attempt.
- `ASSESSMENT_RESULT_W01D07.md`, `POST_GATE_REVIEW_W01D07.md` and control
  bookkeeping were executor-authored after `CLOSE GATE`.
- `RAW_COMPETENCY_SUBMISSION_W01D07.md` and
  `RAW_POST_GATE_EXPLANATION_W01D07.md` are executor transcriptions of recovered
  learner text and are not rewritten solutions.

Implementation code provided during scored phase:
NO.

Gate answer revealed during scored phase:
NO.

Raw result:
`CATEGORICAL PASS` — Tasks 1-4 PASS; mandatory bounds/lifetime condition PASS;
no numeric score was declared or inferred.

Competency affected:
`W01-C-FOUND — COMPETENCY_PASS` based on the fresh W01D07 AI-0 gate.

Fresh independent retest required:
NO — none required from this passed gate.

Notes:
W01D07 was executed one day early on 2026-08-15 and the normal availability /
planned-time precheck was skipped. This is
`MENTOR/SYSTEM WORKFLOW VARIANCE — NON-SCORING`; it does not invalidate the
established scope/time/AI firewall. Actual Focused Time is
`~2h — learner estimate`; Available Focused Time and Planned Focused Time are
`NOT SUPPLIED`. Recovery is `NOT ACTIVE`. Week 1 remains pending MASTER CHECK
and CP-01 / WEEKLY REVIEW.

---

## 2026-08-17 — W02D01 Cortex-M mental model / exception flow

Highest AI level:
AI-3

What AI contributed:
- theory/clarification from learner-provided ARM documentation;
- bounded hints and comprehension checks;
- post-attempt review of learner reasoning and the learner-created diagram;
- routine closure bookkeeping.

Files/functions materially assisted:
- review of W02D01 worksheet/diagram concepts;
- routine closure bookkeeping.

Implementation code provided:
NO

Gate answer revealed:
NO — W02D01 is normal learning, not an AI-0 gate.

Competency affected:
NONE — normal learning day; no new competency PASS is claimed.

Fresh independent retest required:
NO

Notes:
The required diagram and learning evidence may support `ARTIFACT_PASS`, but do
not independently prove a new Cortex-M competency. `W01-C-FOUND` remains the
latest competency PASS.

---

## 2026-08-18 — W02D02 startup sequence / power-on to `main()`

Highest AI level:
AI-5 overall — executor-prepared lab/reference/infrastructure for both the
STM32F446RE source/map lab and the supplemental PC-hosted startup simulator.

What AI contributed:
- theory and clarification of the vector table, `_estack`, MSP,
  `Reset_Handler`, `.data`, `.bss`, linker symbols, `SystemInit()` and
  `__libc_init_array()`;
- review/correction after meaningful learner attempts;
- administrative worksheet/submission support and closure bookkeeping;
- a complete bounded STM32F446RE lab/reference package used to build and inspect
  startup behavior.
- the supplemental simulator's full scaffold, harness, tests, fault
  infrastructure, documentation scaffold and build plumbing;
- direct guided implementation structure/syntax for the learner's `.data` copy,
  `.bss` zero and trace instrumentation, plus debugging, fault-diagnosis tutoring
  and simulator-to-STM32 mapping review.

Files/functions materially assisted:
- `firmware/stm32/w02d02-startup-lab/**` — executor-prepared
  lab/reference/infrastructure, including bounded `main.c` and `build.ps1`;
- administrative assistance around `learning/week-02/day-02/**` and closure
  control records;
- the learner's final reconstruction in `POWER_ON_TO_MAIN_W02D02.md` was not
  authored or rewritten by AI.
- `learning/week-02/startup-simulator/**` — executor-generated infrastructure
  and reference material; Project Chat materially assisted the learner-owned
  `src/startup.c` core with substantial exact structure/syntax.

Learner contribution:
- entered and iterated the final `src/startup.c` startup logic;
- ran tests and baseline/fault demos;
- corrected the BSS trace-index instrumentation;
- performed the fault diagnosis and conceptual reconstruction.

Implementation code provided:
YES — executor-generated infrastructure/reference code plus substantial exact
implementation structure/syntax exposed during tutoring for the supplemental
startup core.

Gate answer revealed:
NO ACTIVE GATE — W02D02 and its supplemental simulator were learning practice,
not an AI-0 competency gate.

Competency affected:
No existing competency was invalidated and no new competency PASS is claimed.
The W02D02 artifact is learning evidence only; Week 2 Cortex-M/startup
competency remains pending the scheduled fresh AI-0 gate.
The supplemental simulator does not independently prove competency and does not
create a second W02D02 PASS decision.

Fresh independent retest required:
NO special retest solely because of this learning-day assistance; the normal
scheduled fresh Week 2 AI-0 competency gate remains required.

Notes:
The supplemental transaction preserves additional artifact reinforcement only;
W02D02 remains the original `GREEN / CLOSED / ARTIFACT_PASS` day.
External help: YES. AI-5 covers executor-prepared infrastructure and the direct
guided implementation support disclosed above; none of this is independent
competency evidence.
Debugger/hardware observation was `NOT PERFORMED`.

---

## 2026-08-19 — W02D03 RCC + register-level GPIO output

Highest AI level:
AI-5

What AI contributed:
- executor-created starter/build/vendor infrastructure;
- theory and official-source navigation guidance;
- graded pre-check support;
- post-attempt build/debug/code review;
- evidence/checklist/submission drafting and editing plus closure bookkeeping.

Files/functions materially assisted:
- W02D03 starter, build and vendor infrastructure;
- `firmware/stm32/w02d03-gpio-lab/main.c` post-attempt review only;
- `learning/week-02/day-03/**` evidence documentation and closure control records.

Core implementation code provided by AI:
NO complete core RCC/GPIO solution.

Learner-owned:
Official-source lookup, register derivation, core RCC/GPIO implementation, build
execution, hardware observation, controlled negative test, restoration and
self-explanation.

Gate answer revealed:
NO ACTIVE GATE — W02D03 was normal learning, not an AI-0 competency gate.

Competency affected:
The W02D03 artifact is not independent competency evidence. No new competency
PASS is claimed, and `W01-C-FOUND — COMPETENCY_PASS` remains valid.

Retest required:
No special retest caused by this learning day. The normal scheduled fresh Week
2 AI-0 competency gate remains required.

Notes:
The learner independently performed official-source reading, core RCC/GPIO
reasoning and implementation, build execution, hardware observations, the
clock-disable negative test, restoration and self-explanation. Normal LD2 ON,
clock disabled -> LD2 OFF and clock restored -> LD2 ON were learner-supplied
physical observations. Register view was NOT MEASURED, no capture was saved and
the exact flash command/tool action was NOT RECORDED.

---

## 2026-08-20 — W02D04 GPIO input and BSRR

Highest AI level:
AI-5

What AI contributed:
- executor-prepared starter/build/vendor infrastructure;
- extensive theory instruction and iterative review;
- complete/reference-level core GPIO code snippets after learner attempts;
- evidence/checklist/submission/provenance drafting and closure bookkeeping.

Files/functions materially assisted:
- W02D04 starter, build, and vendor infrastructure;
- core GPIO input/output implementation through complete/reference-level
  snippets after iterative learner attempts;
- `learning/week-02/day-04/**` evidence documentation;
- `firmware/stm32/w02d04-gpio-input-lab/PROVENANCE.md` and closure control
  records.

Core implementation code provided by AI:
YES — complete/reference-level core GPIO snippets were supplied after iterative
learner attempts.

Learner-owned contribution:
- substantial reasoning and multiple implementation attempts;
- interactive correction of multiple mask/register mistakes;
- multimeter measurement, build, flash, button/LED hardware tests, ODR/BSRR
  comparison, negative case, restoration, and logic-analyzer capture;
- demonstrated explanations recorded in the W02D04 daily log.

Gate answer revealed:
NO ACTIVE GATE — W02D04 was assisted normal learning, not an AI-0 competency
gate.

Competency affected:
W02D04 may be valid artifact evidence but is not independent competency
evidence. No new competency PASS is awarded. `W01-C-FOUND — COMPETENCY_PASS`
remains the latest competency PASS.

Retest required:
The normal scheduled fresh Week 2 AI-0 competency gate remains required.

Notes:
- Learner-reported normal behavior: press B1 -> LD2 ON; release B1 -> LD2 OFF.
- Both BSRR and ODR RMW produced the same visible behavior in the simple
  single-context test. No concurrency race was experimentally reproduced.
- The controlled active-high software-interpretation case produced the predicted
  inverted behavior; active-low behavior was restored.
- B1/PC13 was measured at approximately 3.19 V released and 0 V pressed.
- Capture: `learning/week-02/day-04/evidence/W02D04_PC13_PA5_CAPTURE.png`.
- Register view: NOT MEASURED / OPTIONAL / NON-SCORING.

---

## 2026-08-21 — W02D05 EXTI + NVIC

Highest AI level:
AI-5

What AI contributed:
- executor-prepared starter/build/vendor infrastructure;
- substantial interactive theory teaching and review after learner attempts;
- evidence/submission drafting and END DAY closure bookkeeping.

Files/functions materially assisted:
- W02D05 starter, build, and vendor infrastructure;
- `firmware/stm32/w02d05-exti-nvic-lab/main.c` post-attempt review only; the
  learner retained ownership of the final core SYSCFG/EXTI/NVIC implementation;
- `learning/week-02/day-05/SUBMIT_W02_D05.md`, evidence metadata, and closure
  control records.

Core implementation code provided by AI:
NO complete core EXTI/NVIC solution was supplied in the starter. The learner
owned the final clock, routing, trigger, mask, pending-clear, NVIC, and ISR code.

Learner-owned contribution:
- final core SYSCFG/EXTI/NVIC implementation;
- active-low trigger reasoning and write-1-to-clear explanation;
- build/hardware demo, rising-edge-only negative case, root-cause explanation,
  restoration, and two state photographs.

Gate answer revealed:
NO ACTIVE GATE — W02D05 was assisted normal learning, not an AI-0 competency
gate.

Competency affected:
W02D05 may be valid artifact evidence but is not independent competency
evidence. No new competency PASS is awarded. `W01-C-FOUND — COMPETENCY_PASS`
remains the latest competency PASS.

Retest required:
The normal scheduled fresh Week 2 AI-0 competency gate remains required.

Notes:
- Build PASS / exit 0: `text=1164`, `data=0`, `bss=1568`, `dec=2732`,
  `hex=aac`; only inherited non-blocking `nosys` warnings were present.
- Working behavior: initial LD2 OFF; first press ON; release unchanged; second
  press OFF.
- Rising-edge-only: press no toggle; release toggle because release is LOW-to-HIGH;
  falling-edge operation was restored and passed.
- Captures: `learning/week-02/day-05/evidence/W02D05_LD2_OFF.jpg` and
  `learning/week-02/day-05/evidence/W02D05_LD2_ON_AFTER_PRESS.jpg`.
- Button bounce was not characterized; exact flash method and official-source
  locations were not recorded in the closeout input.

---

## 2026-08-22 — W02D06 debounce + schematic

Highest AI level:
AI-3

What AI contributed:
- theory/clarification and graded hints;
- post-attempt code review/debug;
- SysTick/integration guidance;
- diagnosis of the release-edge hardware defect;
- evidence-document assistance and END DAY closure bookkeeping.

Files/functions materially assisted:
- W02D06 debounce and STM32 integration after meaningful learner attempts;
- `learning/week-02/day-06/SUBMIT_W02_D06.md`;
- `learning/week-02/day-06/DEBOUNCE_LOG_W02D06.md`;
- `learning/week-02/day-06/SCHEMATIC_REVIEW_W02D06.md`;
- W02D06 closure control records.

Core implementation code provided by AI:
NO complete core debounce solution was supplied before the learner's meaningful
implementation attempts. The learner owned the final core debounce implementation.

Learner-owned contribution:
- final core debounce state transitions and integration attempts;
- invariant, threshold, wrap, ISR/foreground, and active-low reasoning;
- physical board operation and repeated-press observation;
- schematic inspection and conclusions for the B1/PC13 and PA5/LD2 paths.

Gate answer revealed:
NO ACTIVE SCORED GATE — W02D06 was assisted normal learning, not an AI-0
competency gate.

Competency affected:
W02D06 remains assisted learning/artifact evidence only. No new competency PASS
is awarded. `W01-C-FOUND — COMPETENCY_PASS` remains the latest competency PASS.

Retest required:
The normal scheduled fresh Week 2 AI-0 competency gate remains required.

Notes:
- Host strict compile PASS; `SUMMARY: 10 tests, 0 failed`.
- STM32 clean build PASS / exit 0: `text=1652`, `data=0`, `bss=1576`,
  `dec=3228`, `hex=c9c`; only inherited non-blocking `nosys` warnings.
- SysTick is 1 ms; software threshold is 20 ticks = 20 ms.
- Learner-observed repeated valid presses toggled LD2 OFF/ON.
- Capture filename `VID_20260822_140328.mp4` is NOT STORED IN REPO.
- Exact physical C03/C04 subrevision is UNRESOLVED; voltage and physical bounce
  duration were NOT MEASURED; exact flash/debug command is NOT RECORDED.

---

## 2026-08-23 — W02D07 Week 2 competency-gate attempt and post-gate review

Highest AI level:
AI-3 — post-gate technical review and evidence/control-plane administration.

Scored phase declared mode:
AI-0 — closed-book, with no documentation, search, notes, previous solutions,
or other external help allowed.

External help during scored phase:
YES — learner disclosure: `YES 1 tí, tôi dùng để tra cứu 1 số tên thanh ghi thôi ko tra cả đáp án`

The learner states that the lookup was limited to some register names and did
not search for complete answers. The exact source/tool used for the lookup is
not available to this executor and is not inferred.

Scored-phase integrity:
INVALID — external reference lookup occurred during a scored phase whose
prospectively declared contract was closed-book.

What AI contributed after close:
- reviewed the submitted technical reasoning and recorded precision findings;
- supported post-gate correction/review of the EXTI pending-clear symptom;
- prepared W02D07 raw-evidence transcription, assessment result, post-gate
  review, submission, and bounded control-plane bookkeeping.

Files/functions materially assisted:
- `learning/week-02/day-07/RAW_COMPETENCY_SUBMISSION_W02D07.md` — executor
  transcription of supplied learner text plus explicit unavailable-text markers;
- `learning/week-02/day-07/ASSESSMENT_RESULT_W02D07.md`;
- `learning/week-02/day-07/POST_GATE_REVIEW_W02D07.md`;
- `learning/week-02/day-07/SUBMIT_W02_D07.md`;
- W02D07 evidence/control-plane records.

Implementation code provided during scored phase:
NO evidence of implementation code being provided is recorded. The disclosed
external lookup still violates the closed-book contract.

Gate answer revealed during scored phase:
The learner states no complete answers were searched. Because the scored-phase
reference lookup itself was prohibited, the executor does not infer clean
integrity from that statement.

Competency affected:
The original W02D07 attempt cannot independently award Week 2 competency. No
new `COMPETENCY_PASS` is created. This is not a technical competency FAIL.

Fresh independent retest required:
YES — a fresh unseen W02D07 variant under a prospectively declared contract.

Notes:
Technical review observed broadly PASS-level reasoning, and the learner's
post-gate correction is retained as learning evidence only. Official outcome is
`INVALID / RETEST REQUIRED`. Week 2 remains open. No firmware, build, flash,
hardware, debugger, or measurement evidence was created for W02D07.

---

## Pre-V3 Migration Note

Known affected scope:
Week 1 pre-V3 implementation/tests/commits.

Status:
CONTAMINATED FOR INDEPENDENT COMPETENCY EVIDENCE.

Treatment:
Artifacts may remain historical references.
No V3 competency PASS is imported.
Fresh AI-0 verification is required before a V3 competency PASS. W01D07 now
provides new independent evidence for `W01-C-FOUND`; it does not import or
reclassify the pre-V3 evidence.
