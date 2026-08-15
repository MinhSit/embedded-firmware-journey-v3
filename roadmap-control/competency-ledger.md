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
- W01D01 through W01D05 records remain artifact/practice evidence. W01D06 is
  valid independent assessment evidence, but it is not the complete defined
  gate for `W01-C-FOUND`.

Independent gate:
W01D07 separate Week 1 V3 60-minute AI-0 competency gate required.

AI mode:
AI-0 for gate.

Status:
COMPETENCY_UNVERIFIED

Last verified:
NONE UNDER V3

Retest condition:
Complete W01D07 and pass its separate Week 1 AI-0 competency gate.

Notes:
Do not promote pre-V3 or W01D01–W01D05 artifact/test results to competency
PASS. W01D03's interrupted generated pre-check remains a historical
`MENTOR/SYSTEM WORKFLOW VARIANCE — NON-SCORING`; it is not why competency is
unverified. `W01-C-FOUND` remains unverified because the fresh independent
Week 1 AI-0 competency gate in W01D07 is outstanding. The W01D06 98/100 daily
coding-gate PASS is retained without being relabeled as Week 1 competency PASS.
