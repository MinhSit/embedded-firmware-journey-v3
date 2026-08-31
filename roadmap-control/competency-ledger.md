# COMPETENCY LEDGER — V3

Artifact evidence and competency evidence are tracked separately.

---

## Status vocabulary

- NOT_STARTED
- LEARNING
- IMPLEMENTING
- ARTIFACT_PASS
- COMPETENCY_UNVERIFIED
- COMPETENCY_PASS
- PARTIAL
- BLOCKED
- INVALIDATED
- RECOVERY
- FAIL

---

## Entry Template

### <Competency ID> — <Name>

Roadmap source:

Required level:

Artifact evidence:

Independent gate:

AI mode:

Status:

Last verified:

Retest condition:

Notes:

---

# Initial State

## W01-C-FOUND — Embedded C foundation

Roadmap source:
Week 1 — Embedded C, memory and host-test discipline.

Required level:
Independent reasoning about pointer/array/lifetime, qualifiers, memory, UB, bit operations and bounded ring-buffer behavior.

Artifact evidence:
- Pre-V3 artifacts may exist but are historical/reference only.
- W01D01 pointer/array/const practice: strict host build and 46/46 tests PASS;
  bounded AI-4 implementation exposure in E06.
- W01D02 storage/linkage/memory-map practice: strict host build/runtime PASS;
  AI-5 scaffold and substantial evidence assistance.
- W01D03 struct/alignment/endian practice: strict host build and 25/25 tests
  PASS; host layout/endian measurements recorded; bounded AI-4 code/syntax
  assistance and AI-assisted wording recorded.
- W01D04 safe bit-operations practice: strict host build and 34/34 tests PASS;
  invalid-input, unchanged-on-failure, full-width and field-isolation behavior
  recorded; AI-3 review/debug after meaningful learner attempts.
- W01D05 fixed-size ring-buffer practice: strict host build and two consecutive
  36/36 test runs PASS; AI-3 post-attempt review after learner implementation.
- W01D06 independent 45-minute C coding assessment
  `W01D06-C-CODING-01`: 98/100 PASS; mandatory items PASS; scored phase AI-0
  integrity PASS; original source and written answers preserved. This is daily
  coding-gate evidence and does not replace the separate W01D07 competency gate.
- W01D07 separate Week 1 C Foundations competency gate: categorical PASS;
  Tasks 1-4 PASS; mandatory bounds/lifetime condition PASS; scored phase AI-0
  integrity PASS; external help NO by learner human confirmation; raw chat
  submission preserved verbatim in `RAW_COMPETENCY_SUBMISSION_W01D07.md`.
- W01D01 through W01D05 records remain artifact/practice evidence. W01D06 is
  valid independent daily assessment evidence. The W01D07 gate independently
  verifies `W01-C-FOUND`.

Independent gate:
W01D07 separate Week 1 V3 60-minute AI-0 competency gate — PASS on 2026-08-15.

AI mode:
AI-0 for gate.

Status:
COMPETENCY_PASS

Last verified:
2026-08-15

Retest condition:
NONE REQUIRED from the passed W01D07 gate. Retest only if later evidence
invalidates this independent result or a higher-authority gate requires it.

Notes:
The competency transition is based only on the fresh W01D07 AI-0 gate, not on
pre-V3 evidence, W01D01-W01D05 artifact/test results or the W01D06 daily coding
gate. W01D03's interrupted generated pre-check remains historical
`MENTOR/SYSTEM WORKFLOW VARIANCE — NON-SCORING`. The W01D06 98/100 daily
coding-gate PASS remains separately labeled. W01D07 was executed one day early
with a skipped availability/planned-time precheck; this is recorded as
`MENTOR/SYSTEM WORKFLOW VARIANCE — NON-SCORING` and did not invalidate the
established assessment scope, time or AI firewall. Week 1 final closure remains
pending MASTER CHECK and CP-01 / WEEKLY REVIEW.

---

## W02-C-MCU-FOUND — Cortex-M startup, GPIO, and EXTI foundations

Roadmap source:
Week 2 — Cortex-M startup, RCC/GPIO, EXTI/NVIC, schematic reasoning, and
evidence-based fault isolation.

Required level:
Independently trace power-on to `main()`, reason about `.data`/`.bss`, explain
RCC-to-GPIO flow and ODR read-modify-write concurrency risk, use precise BSRR
semantics, diagnose EXTI/vector/pending-clear faults, and select evidence that
distinguishes competing hypotheses.

Artifact evidence:
- W02D01 Cortex-M exception-flow artifact — `ARTIFACT_PASS`.
- W02D02 startup sequence/lab and supplemental startup simulator —
  `ARTIFACT_PASS`; fresh validation `30/30 PASS`.
- W02D03 register-level RCC/GPIO output — `ARTIFACT_PASS`.
- W02D04 GPIO input, ODR/BSRR comparison, negative case, and physical capture —
  `ARTIFACT_PASS`.
- W02D05 EXTI/NVIC implementation, negative edge case, and physical evidence —
  `ARTIFACT_PASS`.
- W02D06 debounce state machine, host tests, physical behavior, and schematic
  review — `ARTIFACT_PASS`; fresh host validation `10/10 PASS` and clean STM32
  build exit `0`.
- Assisted W02D01–W02D06 artifacts support the weekly record but do not
  independently award this competency.

Independent gate:
Fresh unseen W02D07 retest on 2026-08-23 — `PASS`. The prospectively declared
contract allowed only official reference manual/datasheet/vendor-header lookup
for register, bitfield, and IRQ names; AI, tutorials, previous answers, and
answer-search were prohibited. Learner integrity declaration: `CLEAN`.

AI mode:
AI-0 for the scored fresh retest. Official reference lookup was allowed under
the prospective contract and does not violate the recorded AI-0 boundary.

Status:
COMPETENCY_PASS

Last verified:
2026-08-23

Retest condition:
NONE REQUIRED from the passed fresh retest. Retest only if later evidence
invalidates this independent result or a higher-authority gate requires it.

Notes:
Evidence is `RAW_COMPETENCY_RETEST_W02D07.md` and
`ASSESSMENT_RESULT_RETEST_W02D07.md`; exact raw answer text remains authoritative
in the Project Chat transcript and was not fabricated by the executor. The
original W02D07 attempt remains separately recorded below as `INVALID / RETEST
REQUIRED`; it is historical, not rewritten, and was not a technical FAIL.

---

## W03-C-UART-FOUND — UART IRQ, ring buffer, and bounded parser foundations

Roadmap source:
Week 3 — UART polling/IRQ, SPSC ring buffer, non-blocking parser, serial logger,
overflow policy, and evidence-based UART fault diagnosis.

Required level:
Independently derive baud from the active clock, reason about ISR constraints
and producer/consumer ownership, preserve bounded parser and overflow behavior,
and diagnose UART data loss using measurements that distinguish hardware ORE,
software ring overflow, parser loss, and shared-state corruption.

Artifact evidence:
- W03D01 polling UART, clock/BRR derivation, and physical terminal echo —
  `ARTIFACT_PASS`.
- W03D02 RX IRQ, NVIC/register capture, controlled ORE, and recovery —
  `ARTIFACT_PASS`.
- W03D03 fixed-size SPSC ring buffer, `DROP_NEWEST`, overflow counter, host
  tests, and physical overflow evidence — `ARTIFACT_PASS`.
- W03D04 bounded non-blocking parser and strict host suite — `ARTIFACT_PASS`.
- W03D05 timestamped serial logger and physical sample log — `ARTIFACT_PASS`.
- W03D06 controlled overflow Debug Report #1 with measurement, minimum fix,
  recovery, and regression — `ARTIFACT_PASS`.
- Assisted W03D01–W03D06 artifacts support the weekly record but do not
  independently award competency.

Independent gate:
`W03D07-UART-IRQ-PARSER-GATE` on 2026-08-31 — `87/100 PASS`. Mandatory
no-blocking-ISR, explicit-overflow-policy, and bounds/lifetime conditions all
passed. Raw evidence is preserved in
`learning/week-03/day-07/RAW_COMPETENCY_SUBMISSION_W03D07.md`.

AI mode:
AI-0 for the scored gate. Allowed aids were paper/pen and an ordinary
calculator only. Learner integrity declaration after close: `CLEAN — no
AI/search/notes/other person; ordinary calculator only.`

Status:
COMPETENCY_PASS

Last verified:
2026-08-31

Retest condition:
NONE REQUIRED from the passed W03D07 gate. Retest only if later evidence
invalidates the independent result or a higher-authority gate requires it.

Notes:
Post-close findings about `volatile` precision, the submitted parser's exact
15-data-character CRLF boundary, and DMA versus shorter ISR latency are retained
separately in `POST_GATE_REVIEW_W03D07.md`. They are non-gate-blocking and do not
rewrite the raw submission. Week 3 is `CONDITIONAL PASS / CLOSED` with exactly
one P1 carry-over for direct correct-baud wire-timing evidence, due 2026-09-06.

---

# Non-awarding Assessment Attempts

## W02D07 — Week 2 Cortex-M / GPIO / EXTI competency-gate attempt

Roadmap source:
Week 2 — Cortex-M, startup, RCC/GPIO, EXTI/NVIC and transfer/fault reasoning.

Artifact evidence:
- `learning/week-02/day-07/RAW_COMPETENCY_SUBMISSION_W02D07.md`
- `learning/week-02/day-07/ASSESSMENT_RESULT_W02D07.md`
- `learning/week-02/day-07/POST_GATE_REVIEW_W02D07.md`

Independent gate:
W02D07 original attempt on 2026-08-23 — `INVALID / RETEST REQUIRED`.

AI mode:
Declared `AI-0 / closed-book`; integrity invalid because the learner disclosed
external reference lookup of some register names during the scored phase.

Status:
COMPETENCY_UNVERIFIED

Last verified:
NOT VERIFIED

Retest condition:
Fresh unseen W02D07 variant under a prospectively declared contract. The
original questions must not be reused.

Notes:
Post-attempt review observed broadly PASS-level technical reasoning, but this
attempt cannot independently award competency under the contract actually used.
This is not a technical competency FAIL. No new `COMPETENCY_PASS` is created;
`W01-C-FOUND` remains the latest verified competency.
