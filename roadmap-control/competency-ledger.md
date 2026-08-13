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
- These are artifact/practice evidence only. None is fresh AI-0 E5 evidence.

Independent gate:
Fresh Week 1 V3 AI-0 gate required.

AI mode:
AI-0 for gate.

Status:
COMPETENCY_UNVERIFIED

Last verified:
NONE UNDER V3

Retest condition:
Complete Week 1 V3 and pass a fresh AI-0 gate.

Notes:
Do not promote pre-V3 or W01D01–W01D04 artifact/test results to competency
PASS. W01D03's interrupted generated pre-check remains a historical
`MENTOR/SYSTEM WORKFLOW VARIANCE — NON-SCORING`; it is not why competency is
unverified. `W01-C-FOUND` remains unverified because the fresh independent
Week 1 AI-0 gate is outstanding and assisted practice cannot substitute for it.
