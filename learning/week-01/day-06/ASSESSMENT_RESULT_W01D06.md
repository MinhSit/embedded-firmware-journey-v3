# W01D06 Independent C Coding Assessment Result

Assessment ID: `W01D06-C-CODING-01`

Type: independent coding assessment / daily coding gate

Date: `2026-08-15`

Scored: `YES`

Scored phase AI mode: `AI-0`

External help during scored attempt: `NO`

Time limit: `45 minutes`

Attempt began: approximately `10:18 Asia/Ho_Chi_Minh`

Attempt closed: approximately `10:53 Asia/Ho_Chi_Minh`

The learner closed before the hard stop. No extra attempt time is inferred.

## Result

| Task | Result |
| --- | ---: |
| Task 1 — Safe bit-field write | 35 / 35 |
| Task 2 — String/array bug repair | 28 / 30 |
| Task 3 — Lifetime/pointer | 20 / 20 |
| Task 4 — Struct layout | 15 / 15 |
| **Total** | **98 / 100** |

Decision: `PASS`

## Mandatory Items

- PASS — Task 1 has no boundary-shift undefined behavior found.
- PASS — invalid Task 1 input does not modify the destination.
- PASS — Task 2 has no severe bounds defect in the corrected implementation.
- PASS — Task 3 does not return a pointer to an expired local object.

## Raw Evidence

- `safe_bit.c` — SHA-256
  `16ba35db6b8ed4579bfdd78d18487b5ae92d4023f1d80ab4b0d2aa8df7b40c9e`
- `copy_token.c` — SHA-256
  `85ecea161a1a3a03f012c8fcad5805acb488c41b18e86ee164a5c5981ce6f5ad`
- `lifetime.c` — SHA-256
  `6d00707f441b898635e8c52a8ff70682fdb0c733c5979497e5f9c81f383ea825`
- `RAW_WRITTEN_ANSWERS_W01D06.md` — original non-file answers.

The three raw C files retain their original line endings, missing final newline
and authorized whitespace. Formatting was not normalized.

## AI Integrity

Result: `PASS`

No external AI, search, notes, old code or solution assistance was used during
`START GATE` through `CLOSE ATTEMPT`. Work was sent to ChatGPT before closure,
but no review, hints or correctness feedback was returned until after
`CLOSE ATTEMPT`; this did not contaminate the scored AI-0 evidence.

Post-close review and correction used AI-3 and are recorded separately in
`POST_GATE_REVIEW_W01D06.md`.

## Validation

- Learner-authored Task 1 runner: strict C17 build PASS; seven reported tests
  PASS; exit code 0.
- Executor-created post-close boundary harness: strict C17 build PASS; 14 tests,
  0 failed; exit code 0.
- `copy_token.c` and `lifetime.c`: strict C17 object builds PASS.
- Full commands and phase attribution are recorded in
  `evidence/week-01/day-06/validation.txt`.

Executor-created tests are validation evidence only and are not attributed to
the learner's scored attempt.

## Competency Boundary

`W01D06-C-CODING-01 = PASS`

`W01-C-FOUND = COMPETENCY_UNVERIFIED`

W01D06 is the roadmap's 45-minute daily coding gate. W01D07 contains a separate
60-minute Week 1 independent competency gate. This daily PASS does not award
`COMPETENCY_PASS`, does not mark Week 1 PASS and does not close CP-01.
