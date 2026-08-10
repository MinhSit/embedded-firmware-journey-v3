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

## Pre-V3 Migration Note

Known affected scope:
Week 1 pre-V3 implementation/tests/commits.

Status:
CONTAMINATED FOR INDEPENDENT COMPETENCY EVIDENCE.

Treatment:
Artifacts may remain historical references.
No V3 competency PASS is imported.
Fresh AI-0 verification is required.
