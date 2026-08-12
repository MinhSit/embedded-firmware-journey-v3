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
- The learner supplies only execution results or evidence that the active execution environment cannot independently read from the repository or tools.

## 3. END DAY Is One Atomic Close Transaction

The active repository execution environment handles `END DAY` in this order:

1. Determine the artifact result and AI provenance first.
2. Run the human-input preflight and identify any missing mandatory human-only fields.
3. Ask the learner only for those genuinely missing fields and resolve them.
4. Update required evidence metadata.
5. Update the daily log.
6. Update the AI usage log.
7. Update current state.
8. If the repository closure linter exists, run it against the updated control state.
9. Run one human consistency audit across result, provenance, human-only fields, evidence, logs, and state.
10. Commit the closure.
11. Push only after one verification, when push is authorized.

Provenance must be settled before the closure commit so a late provenance audit does not create avoidable repair commits. This workflow does not change artifact, evidence, AI-contamination, or competency semantics.

## 3.1 END DAY Human-Input Gate

Before any END DAY closure edit or commit, the active execution environment must perform a lightweight human-input preflight.

1. Identify every mandatory field in the active daily/closure schema that cannot be reliably derived from repository state, tools, tests, measurements, or already recorded evidence.
2. Typical human-only fields may include actual focused time; a relevant required health/load issue; a learner-observed blocker not captured in repository evidence; material AI assistance not visible in repository/tool history; uncaptured physical/hardware observations; and other subjective or experiential information explicitly required by the active schema.
3. Reuse trusted current-session context or repository evidence when the value is already available. Do not ask repetitive questions.
4. Ask only for genuinely missing required human-only information.
5. If any required human-only field is missing, END DAY closure is `NOT READY`; do not commit the closure yet.
6. Never infer focused time from chat duration, conversation timestamps, file modification timestamps, commit timestamps, shell history, IDE-open duration, or wall-clock time between `BOOT` and `END DAY`.
7. A learner estimate is valid only when explicitly labeled as an estimate, for example: `Actual: ~6h — learner estimate`.
8. Do not add fake precision. If the learner says `~6h`, do not record `6h00m`.
9. If the learner genuinely cannot recover a required value, record `UNKNOWN` / `NOT RECORDED` honestly only when the governing schema allows it, record why, and determine whether it is a process variance. Do not silently pretend the field was resolved.
10. The normal atomic END DAY transaction may continue only after every mandatory human-only field is supplied, already available, or explicitly and validly classified as unrecoverable.
11. The pre-commit consistency audit must verify that no required human-only field was silently omitted; no `TBD`, `UNKNOWN`, `NOT RECORDED`, or equivalent placeholder remains unless intentionally allowed and explained; and no inferred human-only value is presented as fact.
12. This gate occurs before the final END DAY commit and must remain lightweight. Its purpose is to prevent repair commits, not create additional bureaucracy.

## 3.2 Closure Linter in END DAY

- The repository closure linter is `tools/roadmap/closure_lint.py`. Run `python tools/roadmap/closure_lint.py` after evidence/log/state updates and before the final commit.
- `FAIL` means `END DAY NOT READY`; correct the objective control-contract failure before closure.
- `WARN` requires human review. A warning does not automatically block closure unless that review confirms a required contract failure.
- `PASS` permits the normal human consistency audit to continue; it does not by itself make END DAY ready.
- The linter is a read-only operational helper, not policy authority. It must not edit files, judge conceptual answers, decide technical correctness, or award competency PASS.
- The human audit remains mandatory because evidence meaning, AI provenance, competency claims, carry-over, and historical explanations cannot be safely decided by a structural parser alone.

## 4. Bookkeeping Ownership

- Routine control-file bookkeeping and long control-file edits belong to the active repository execution environment; Section 11 defines how Project chat may prepare this work for Cowork.
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

## 10. Pre-check / Baseline Diagnostic and Generated-Pack Authority

- Before a new topic, a pre-check is `DIAGNOSTIC / NON-SCORING` unless `SYSTEM_SPEC_V3`, the approved roadmap/day card, or an explicit gate contract makes it scored.
- Correct answers are not required to complete a baseline. Honest answers such as "I don't know", "I haven't learned this", "I am unsure", or a clearly labeled prediction/guess are valid baseline data.
- Record each starting point as `KNOWN`, `PARTIAL`, `INCORRECT`, or `UNKNOWN`, then proceed to theory. A baseline measures the starting point; it must not penalize missing knowledge that the current lesson is intended to teach.
- End-of-day understanding checks and competency gates remain strict. "I still cannot explain it" after required learning may affect status when the authoritative contract says so; this clarification does not weaken competency verification.
- If the mentor/system interrupts or mishandles the diagnostic, record `MENTOR/SYSTEM WORKFLOW VARIANCE`, not automatic learner non-compliance. Preserve the chronology; do not retroactively mark an uncompleted diagnostic complete.
- `GENERATED PACK != SOURCE OF NEW POLICY`. A generated THEORY/TODO/SUBMIT pack may add exercises, examples, measurements, checklist structure, or optional diagnostics, but may not add a competency, gate, PASS definition, or learner-scored daily requirement.
- Every generated `MUST` that can downgrade daily status must trace to `SYSTEM_SPEC_V3`, the approved roadmap/day card, an explicit gate contract, or an operational requirement strictly necessary to satisfy one of those sources.
- If a generated pack exceeds its authority, the higher-authority criteria win and the discrepancy must be recorded and corrected.
- Daily `GREEN/YELLOW/RED` is decided from authoritative daily criteria, not generated checkbox state. This rule does not excuse an omitted scored diagnostic or pre-work artifact when a higher-authority source explicitly requires it.

## 11. Project Chat <-> Cowork Handoff

- The roadmap Project chat is the reasoning, teaching, and decision environment. Cowork is an external execution environment opened by the learner in a separate independent chat.
- The Project mentor finishes the analysis and decision before proposing Cowork. It must not invoke Cowork from the Project chat, leave the response unfinished, tell the learner to wait for Cowork, assume shared hidden context, or make the learner reconstruct a large request.
- When Cowork is useful, the Project mentor produces one complete self-contained Cowork prompt. As relevant, it includes the local repo path, canonical remote, objective, read-first sources, known state, facts to preserve, likely files, safety constraints, validation commands, commit/push rules, and final-report requirements.
- The learner manually opens an independent Cowork chat, points it to the repository, and pastes that prompt. Cowork performs the repository operations; the learner then returns its final report, commit SHA, build/test result, and relevant file list to the Project chat.
- The Project mentor independently audits the returned work. A Cowork `PASS` report is not automatically authoritative.
- Prefer Cowork for multi-file bookkeeping, repo-wide consistency audits, routine control-file/evidence metadata edits, END DAY closure, commit/push, and other repetitive operational work.
- Cowork must not replace learner-owned competency work: no AI-0 gate answers, assessed closed-book answers, learner core implementation under independence evaluation, or scored project-defense responses.
- If Cowork materially changes technical implementation, log the actual AI assistance under AI Integrity rules. Pure administrative help does not itself change competency, but provenance remains honest where recording is required.
- This handoff minimizes learner bookkeeping while preserving learner ownership of technical competency.

## 12. Confirmed Defect -> Retroactive Impact Sweep

Whenever a workflow, system, or control defect is `CONFIRMED`:

1. Do not fix only the day or file where the defect was discovered.
2. Define the defect class precisely. Use a testable class such as "CLOSED days can retain missing Actual Focused Time", not a vague statement such as "something was wrong with D04".
3. Determine the reasonable retrospective scope: every prior `CLOSED` day, artifact, or control record that could have been affected by the same defect class. Do not scan unrelated areas automatically.
4. Audit every item in that scope and classify it `PASS`, `AFFECTED — FIXABLE`, `AFFECTED — HISTORICAL / UNRECOVERABLE`, or `NOT APPLICABLE`.
5. Safely correct recoverable same-class inconsistencies where the evidence is authoritative and sufficient.
6. For unrecoverable historical cases, preserve truthful history, do not invent missing data, and record the limitation or process variance.
7. Record the exact retrospective scope and per-item results in the review item. Example: `Scope: W01D01-W01D03; W01D01 PASS; W01D02 AFFECTED — FIXED; W01D03 AFFECTED — FIXED`.
8. A confirmed review item must not be marked `CLOSED` until its required retrospective impact sweep is complete and recorded.
9. If the defect could affect technical artifacts or competency claims, do not auto-fix; escalate under the authoritative gate and evidence rules.
10. Keep the sweep defect-specific. Do not turn it into unlimited repository archaeology or unrelated cleanup.
11. If the defect is first discovered at a checkpoint, complete the same retrospective sweep before closing the checkpoint finding.
12. Prefer one coherent correction transaction where practical instead of multiple repair commits.

## 13. CP-01 Week Consistency Sweep

At `CP-01 — End of Week 1`, run one bounded consistency sweep across every Week 1 day that is `CLOSED` (`W01D01` through the last closed day, expected eventually through `W01D07`). This is control/review verification, not a curriculum change or a new competency gate.

Use `PASS`, `WARN`, `FAIL`, or `N/A` for this compact matrix:

- daily status;
- planned focused time;
- actual focused time;
- artifact result;
- required evidence present;
- AI provenance present;
- competency claim consistent with admissible evidence and the ledger;
- carry-over resolved or explicit;
- next action / closed-state progression consistent;
- no unexplained placeholder in a mandatory field;
- Current State consistent with the latest execution, artifact, and competency positions.

Combine:

1. the machine-checkable output of `python tools/roadmap/closure_lint.py`; and
2. a human semantic audit of evidence meaning, provenance, competency boundaries, carry-over, progression, and any warning.

Do not re-grade technical competency from this matrix and do not rerun every historical technical test by default. A technical rerun is required only when source/tests changed, evidence is stale or contradictory, an objective artifact concern exists, or a review/gate contract requires it. Record the exact scope, findings, and any bounded follow-up concisely enough to remain within the existing CP-01 review timebox.
