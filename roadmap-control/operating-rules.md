# OPERATING RULES — MINIMUM DAILY WORKFLOW

**Status:** `ACTIVE OPERATIONAL LAYER`
**Effective from:** `W01D02`
**Owner approval:** `2026-08-11 — APPROVED`

This file simplifies daily execution without overriding `SYSTEM_SPEC_V3`, `EMBEDDED_ROADMAP_V3.1`, or `MASTER_PROMPT_V3`. If a conflict exists, the higher-authority source wins.

## 1. Start / Resume Command

- `BOOT` is the only default user command to start or resume a new learning day.
- `BOOT` performs the authoritative state read and then runs the day according to `BOOT = STATUS + START DAY`.
- `START DAY` is an internal/subcommand path when context is already clear. The user does not need to type `START WEEK ...` or remember the next Week/Day identifier.

## 2. Focus Phase: LEARN / IMPLEMENT / TEST

- Do not update `current-state.md`, `daily-log.md`, or `ai-usage-log.md` during the focus phase.
- Do not create bookkeeping commits during the focus phase.
- AI keeps temporary session notes in chat. The learner focuses on learning, implementation, tests, and measurements.
- The learner supplies only execution results or evidence that AI/Work mode cannot read from the repository or tools.

## 3. END DAY Is One Atomic Close Transaction

AI/Work mode handles `END DAY` in this order:

1. Determine the artifact result and AI provenance first.
2. Update required evidence metadata.
3. Update the daily log.
4. Update the AI usage log.
5. Update current state.
6. Run one consistency audit across result, provenance, evidence, logs, and state.
7. Commit the closure.
8. Push only after one verification, when push is authorized.

Provenance must be settled before the closure commit so a late provenance audit does not create avoidable repair commits. This workflow does not change artifact, evidence, AI-contamination, or competency semantics.

## 4. Bookkeeping Ownership

- AI/Work mode owns routine control-file bookkeeping and long control-file edits.
- The learner is not required to manually edit control files.
- The learner remains responsible for honest disclosure and for providing results/evidence that cannot be independently read from repository/tool output.

## 5. Commit Policy

Default maximum: **two commits per learning day**.

- **A — Optional technical checkpoint:** use only when it provides real recovery/review value.
- **B — END DAY closure:** contains the final technical result plus required bookkeeping, or only closure changes if checkpoint A was necessary.

If no checkpoint is needed, combine technical work and bookkeeping into one END DAY commit. Do not split artifact, daily log, AI log, and state into three or four default commits.

## 6. Verification Policy

- Run one pre-commit audit covering applicable build/tests, provenance, required fields, consistency, and `git diff --check`.
- After an authorized push, run one post-push sync check.
- Do not repeat audits without an objective failure, conflict, or new evidence.

## 7. Minimum-Sufficient Evidence and Logging

- Record only metadata required to reproduce the result or support the claim.
- Do not duplicate the same narrative across files unless a mandatory field requires it.
- Evidence admissibility, required metadata, AI provenance, and independent competency requirements remain unchanged.

## 8. Deferred Schema Work

- Keep the current `daily-log.md` schema unchanged in this patch.
- Do not split the log into per-day files now.
- Reconsider per-day logs at `CP-01` only if bookkeeping friction repeats.

## 9. Stable State Semantics

- Closed days remain closed unless explicitly reopened by recovery or review.
- Current execution position must be read from `roadmap-control/current-state.md`; this file must not hard-code a stale Week/Day execution position.
- `W01-C-FOUND` remains `COMPETENCY_UNVERIFIED`.
- A fresh AI-0 gate remains required.
- Recovery status must be read from `roadmap-control/current-state.md`.
- `Exact Next Action` must be read from `roadmap-control/current-state.md`.
