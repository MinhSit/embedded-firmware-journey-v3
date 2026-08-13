# EXECUTION RUNBOOK

**Document ID:** `EXECUTION_RUNBOOK`
**Version:** `1.1.0`
**Status:** `ACTIVE IMPLEMENTATION RUNBOOK — NON-AUTHORITATIVE`
**Owner approval:** `2026-08-13 — APPROVE MIGRATION D`

Purpose: mechanical repository HOW implementing `MASTER_PROMPT_V3 3.1.0`.

This file does not define PASS, AI levels, assessment rules, lifecycle states,
command legality, actor roles, HANDOFF semantics, competency requirements or
week-transition policy. Those semantics belong to the Master Prompt or higher
authority. If a conflict exists, the higher-authority source wins.

## A. Source and Context Preflight

Before a stateful operation or state-dependent response, load the canonical
System Spec, Roadmap, Master Prompt, Current State, this runbook and the relevant
review/log/evidence files. Validate governing source/version when required by
the Master Prompt.

For `ENSURE_CONTEXT_READY`:

1. read available persistent and transient facts;
2. reconcile prior/session state using the Master Prompt classifications;
3. mark unobservable facts `UNRESOLVED`;
4. ask only the minimum human-only question required;
5. continue to legality/dependency checks only when context is sufficient.

`BOOT` is the normal learner-facing start/resume command, but this preflight is
also invoked implicitly for other stateful commands and state-dependent
read-only commands such as `STATUS`.

## B. Managed Repository Transaction Preflight

The `EXECUTOR DISPATCH` contract must state:

```text
Purpose
Canonical repo
Local repo path
Expected branch
Expected base SHA
Allowed file scope
Forbidden scope
Required validation
Commit authorization
Push authorization
Return-report requirements
```

Before mutation, verify repo path, origin, branch, local/remote base SHA,
staged/unstaged/untracked paths, candidate ref state and allowlist. Only one
managed mutation transaction may own a worktree at a time. Unexpected state is:

```text
STOP / REPORT
```

Do not silently rebase, reset, force, overwrite, merge or discard work.

Executor prompts must be self-contained and product-agnostic enough to paste
unchanged into either Cowork or Antigravity, following `MASTER_PROMPT_V3`
Section 3A.7.2 portability requirements. If Cowork is unavailable or
quota-exhausted, do not cancel the roadmap operation automatically; offer
Antigravity as a learner-selected fallback and reuse the same executor contract.

## 1.2 Start-Day Focused-Time Plan

Before normal `FOCUS_ACTIVE`, Project Chat must establish and state all three
focused-time fields in the Day Contract:

1. `Roadmap Standard Load` — the source-derived standard load or day-card load.
2. `Available Focused Time` — the learner-specific human input for this day.
3. `Planned Focused Time` — the actual plan chosen after comparing the Day
   Contract with learner availability.

Use an explicit numeric daily load from the approved Roadmap/day card when it
exists. If the Roadmap provides only a standard daily load or range, record it
as `ROADMAP-DERIVED`. Never substitute that load for learner availability.

If trusted current context does not already contain learner availability for
this day, ask exactly one minimum human-only availability question and obtain
the value before normal Focus. Do not wait until `END DAY`, infer availability
from timestamps/chat duration/history, or create fake precision.

State the final `Planned Focused Time` explicitly before normal Focus. Planned
hours are workload planning, not a quota. Finishing earlier does not downgrade
`GREEN` when authoritative stop conditions are satisfied, and a time plan never
overrides proactive `END DAY READY` or the authoritative daily stop condition.

Record the complete Day Contract in temporary session notes, including Roadmap
Standard Load, Available Focused Time, Planned Focused Time and the authority
trace for every generated status-affecting `MUST`.

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

- Routine control-file bookkeeping and long control-file edits belong to the active repository execution environment; the Master Prompt defines how Project Chat prepares this work for Cowork.
- The learner is not required to manually edit control files.
- The learner remains responsible for honest disclosure and for providing results/evidence that cannot be independently read from repository/tool output.

## 5. Commit Policy

Default maximum: **two commits per learning day**.

- **A — Optional technical checkpoint:** use only when it provides real recovery/review value.
- **B — END DAY closure:** contains the final technical result plus required bookkeeping, or only closure changes if checkpoint A was necessary.

If no checkpoint is needed, combine technical work and bookkeeping into one END DAY commit. Do not split artifact, daily log, AI log, and state into three or four default commits.

A narrow review-confirmed system/control/evidence-integrity correction may use a
bounded extra correction commit when authorized by the Master Prompt. It does
not consume the next learning day's normal allowance and is not for polish.

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

## C. Current State and Commit Self-Reference

Mutate Current State with read-modify-validate semantics:

- Current execution position must be read from `roadmap-control/current-state.md`; this file must not hard-code a stale Week/Day execution position.
- Recovery status must be read from `roadmap-control/current-state.md`.
- `Exact Next Action` must be read from `roadmap-control/current-state.md`.

```text
READ complete state
-> calculate minimum semantic delta
-> preserve required schema and unrelated fields
-> apply
-> validate required fields
-> cross-check related control claims
```

For a record inside the same not-yet-created commit, write:

```text
Commit:
SELF — containing commit
```

Resolve `SELF = <actual SHA>` in the report; do not create a backfill-only commit.

## D. Interrupted Transaction and Context-Handoff Mechanics

On interruption, inspect branch, HEAD, status, staged/unstaged/untracked paths,
remote refs and last verified checkpoint. Preserve partial work. Resume only if
transaction ownership and exact safe base are proven; otherwise stop/report.

For an active context HANDOFF, collect workflow phase, current task, known repo
state, latest build/test/failures, measurements, attempts, hypotheses, hints,
highest AI level, exact implementation exposure, assessment integrity, blockers,
resume point and transfer strategy. Do not auto-commit. Unknown provenance is
`UNRESOLVED`; do not guess a lower AI level.

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

## E. Repository Executor Mechanics

The `REPOSITORY EXECUTOR` concept (Master Prompt Section 3A.7) defines an
external bounded repository-operation actor operating from a self-contained
executor prompt. Cowork is the preferred/default implementation; Antigravity is
the approved learner-selected fallback.

### E.1 Explicit Opt-In Sequence

1. Project Chat finishes its substantive reply first.
2. Project Chat identifies that an external repository executor is useful.
3. Project Chat explains purpose, scope and why executor is appropriate.
4. Project Chat asks one explicit consent question.
5. Only after explicit learner approval, Project Chat emits the self-contained
   executor prompt.
6. Learner manually opens an independent Cowork/Antigravity context and pastes
   the prompt.
7. Executor performs the bounded operation.
8. Learner returns the executor report.
9. Project Chat independently verifies the result.

Platform Work-mode popup rejection does NOT count as executor rejection.

### E.2 Return Report

Return result, expected/actual base SHAs, branch, commit, push, explicit main
protection, exact files/rename, versions, architecture summary, preserved state,
validation, unexpected findings, out-of-scope dependencies, final worktree and
remote SHAs. Project Chat independently verifies the report.

- When executor is useful, the Project mentor produces one complete self-contained
  executor prompt. As relevant, it includes the local repo path, canonical remote,
  objective, read-first sources, known state, facts to preserve, likely files,
  safety constraints, validation commands, commit/push rules, STOP/REPORT
  conditions, and final-report requirements.
- The learner manually opens an independent Cowork/Antigravity context, points it
  to the repository, and pastes that prompt. The executor performs the repository
  operations; the learner then returns its final report, commit SHA, build/test
  result, and relevant file list to the Project chat.
- The Project mentor independently audits the returned work. An executor `PASS`
  report is not automatically authoritative.
- Prefer executor for multi-file bookkeeping, repo-wide consistency audits,
  routine control-file/evidence metadata edits, END DAY closure, commit/push,
  and other repetitive operational work.
- Executor must not replace learner-owned competency work: no AI-0 gate answers,
  assessed closed-book answers, learner core implementation under independence
  evaluation, or scored project-defense responses.
- If executor materially changes technical implementation, log the actual AI
  assistance under AI Integrity rules. Pure administrative help does not itself
  change competency, but provenance remains honest where recording is required.

### E.3 Executor Failure

Executor failure, quota exhaustion, unexpected state, or partial execution:
never assume success; preserve partial work; return exact report; Project Chat
decides next action. If Cowork fails and learner selects Antigravity, reuse the
same executor contract.

### E.4 MASTER CHECK External Inspection

When MASTER CHECK needs local-repository inspection unavailable to Project Chat,
the executor prompt must be `READ_ONLY_AUDIT`. The executor must not edit files,
stage, commit, push, repair findings, or award competency. Observations return
to Project Chat for independent evaluation. Correction requires a separate
transaction with fresh executor consent.

This runbook is mechanical HOW only and must not become a second execution engine.
