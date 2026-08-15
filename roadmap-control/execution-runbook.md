# EXECUTION RUNBOOK

**Document ID:** `EXECUTION_RUNBOOK`
**Version:** `1.3.0`
**Status:** `ACTIVE IMPLEMENTATION RUNBOOK — NON-AUTHORITATIVE`
**Owner approval:** `2026-08-15 — APPROVE CP-01 WORKFLOW AMENDMENT`

Purpose: mechanical repository HOW implementing `MASTER_PROMPT_V3 3.1.3`.

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

## A.1 Pipelined Start-Day Preparation

For a normal `LEARNING` day where starter/repository prep is useful and no
safety, prerequisite, review or assessment-integrity blocker exists:

1. run `ENSURE_CONTEXT_READY` and resolve source-derived Day Contract facts;
2. return `STATE SNAPSHOT -> THEORY PACK -> DAY OUTCOME / AI BOUNDARY`;
3. do not claim `FOCUS_ACTIVE` or activate learner implementation;
4. ask one compact `BOOT PREP INPUT` containing:
   - `Available Focused Time` if still missing;
   - explicit repository-executor consent when executor is useful;
5. after approval, emit the self-contained executor prompt;
6. learner may read the delivered Theory Pack while the independent executor
   prepares bounded starter/TODO/tests;
7. when the report returns, Project Chat independently verifies prep;
8. only then activate interactive Pre-check, preferably one question at a time;
9. resolve remaining Day Contract items and `Planned Focused Time`;
10. only after the Day Contract is complete, enter `FOCUS_ACTIVE` and issue the
    exact first learner-owned implementation/test action.

This is transient orchestration only. Do not persist `DAY_PREPARING`, mutate
bookkeeping because theory was displayed, or change the canonical five-state
lifecycle.

For scored AI-0 `DIAGNOSTIC` / `GATE` / `RETEST`, do not deliver targeted theory,
hints, examples or tutoring Pre-check before/during the attempt. Neutral
logistics, contract/timing, allowed references and non-answer-revealing scaffold
prep may proceed; assessment integrity overrides pipeline optimization.

Before any operational `NEXT ACTION`, mechanically check lifecycle state,
operation class, proposed owner, whether repo prep/admin/mutation is involved,
executor usefulness, transaction-specific explicit consent, AI-level boundary
and learner-work ownership. Administrative multi-file starter setup defaults to
an executor proposal when useful, never to learner boilerplate creation.

## B. Managed Repository Transaction Preflight

The `EXECUTOR DISPATCH` contract must state:

```text
Purpose
Canonical repo
Local repo path
Expected branch
Expected base SHA
Read-first files
Known state
Facts to preserve
Allowed file scope
Forbidden scope
Required validation
Commit authorization
Push authorization
STOP/REPORT conditions
Return-report schema
```

Before mutation, verify repo path, origin, branch, local/remote base SHA,
staged/unstaged/untracked paths, candidate ref state and allowlist. Only one
managed mutation transaction may own a worktree at a time. Unexpected state is:

```text
STOP / REPORT
```

Do not silently rebase, reset, force, overwrite, merge or discard work.

After preflight, inspect candidate technical files and run an early
`git diff --check` before long build/bookkeeping work. Within files already in
the approved mutation scope, the executor may remove trailing whitespace or add
a missing final newline only when the delta is purely mechanical/whitespace and
contains no semantic token, code-logic or behavior change. Report exact affected
files and rerun relevant build/tests/checks.

Do not use this exception to refactor, rename, reformat a whole file, normalize
line endings, remove learner comments/TODOs, change unrelated style or learner
logic, or suppress tests/warnings. Any required non-mechanical change is
`STOP / REPORT`.

Managed transaction order:

```text
preflight
-> inspect candidate technical files
-> early git diff --check
-> allowed mechanical hygiene if needed
-> main build/tests/validation
-> evidence/log/state mutation
-> closure linter / semantic audit
-> final git diff --check
-> commit
-> authorized push
-> independent verification
```

The final `git diff --check` remains mandatory.

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

## 2.1 Calibrated Normal-Learning Practice

For normal `LEARNING` coding work, especially from Week 2 onward after
prerequisites are satisfied, prepare materially harder implementation and tests
inside the authoritative day outcome. Preserve the learner's loop:

```text
code -> visible/deep tests -> observe failure -> reason about delta
-> modify -> rerun
```

Use deterministic normal/boundary/invalid/failure/state/repeated-call/wrap and
regression cases as the baseline. Add randomized/property/stress cases only when
technically meaningful and after deterministic behavior is established. Tests
may expose actual/expected differences during normal learning.

Do not pre-fill core implementation. Generated extra/deep tests without trace to
System Spec, roadmap/day card, valid gate contract or necessary operational
invariant are `NON-SCORING learning feedback`, never a silent acceptance `MUST`.
Add a short code-to-diagram/state-flow-to-reasoning/verbal transfer exercise when
useful without replacing implementation.

## 3. END DAY Is One Atomic Close Transaction

The active repository execution environment handles `END DAY` in this order:

1. Determine the artifact result and AI provenance first.
2. Run the human-input preflight and identify any missing mandatory human-only fields.
3. Ask the learner only for those genuinely missing fields and resolve them.
4. Inspect candidate technical files and run the early hygiene check; apply only
   the bounded mechanical exception above when needed, then rerun affected validation.
5. Update required evidence metadata.
6. Update the daily log.
7. Update the AI usage log.
8. Update current state.
9. If the repository closure linter exists, run it against the updated control state.
10. Run one human consistency audit across result, provenance, human-only fields, evidence, logs, and state.
11. Run the mandatory final `git diff --check`.
12. Commit the closure.
13. Push only after one verification, when push is authorized.

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

## 3.3 END WEEK Canonical Orchestration

`END WEEK` is a stateful public orchestrator. Run `ENSURE_CONTEXT_READY`, validate
governing versions and check assessment/gate dependencies before deep audit.

Mechanical sequence:

```text
context/state + version ready
-> unresolved required AI-0 gate/retest resolved under assessment firewall
-> MASTER CHECK read-only AUDIT
-> findings disposition
-> if required: finish AUDIT, REVIEW/disposition, separate bounded CORRECTION, VERIFY
-> one batched human-only-input preflight
-> WEEKLY REVIEW / formal CP when due
-> PASS / CONDITIONAL PASS / FAIL
-> carry-over / Recovery / next-week eligibility
-> one coherent week-closure repository transaction
-> closure linter + semantic consistency audit
-> final git diff --check
-> commit + authorized push
-> independent remote verification
-> final status + exactly one NEXT ACTION
```

`MASTER CHECK` never mutates. One explicit executor consent covers one
already-defined bounded transaction; do not re-ask at internal steps. Unexpected
new correction scope requires a new transaction boundary. `END WEEK` does not
alter PASS, competency or AI-integrity semantics.

## 3.4 Optional Bounded Coding-Gate Feedback Mechanics

Apply only when a future scored AI-0 coding-subpart contract explicitly opts in.
Default/existing gate behavior otherwise remains unchanged.

Contract metadata:

```text
Submission Policy:
Max Scored Submissions: 2 total
Hidden Feedback Mode: PASS / NOT PASS only
Timer Across Submissions: one original timer; no reset/extension/retry clock
Raw Attempt Retention: Attempt 1 and Attempt 2 if used
```

Evaluator mechanics:

1. store raw Attempt 1 plus timestamp/result before returning binary status;
2. if `PASS`, close the coding subpart subject to all mandatory gate criteria;
3. if `NOT PASS`, permit at most one learner-chosen revision/submission while the
   original timer continues;
4. store raw Attempt 2 plus timestamp/result if used;
5. record submissions allowed/used, feedback mode, original limit, attempt
   evidence and final scored submission without overwriting Attempt 1.

Do not reveal hidden test identity/count/category, expected or actual hidden
value/diff, failing input, bug location, hint, explanation, review, score,
aggregate pass count or solution. Only ordinary learner-program compiler/runtime
output explicitly allowed by the contract may be used.

Both submissions are one gate attempt; the retry is not `RETEST`. Exhaustion
without mandatory criteria is `FAIL`; a later reassessment is a fresh retest.
AI contamination remains `INVALID / RETEST REQUIRED`. Conceptual/verbal/design-
defense/project-defense/unseen-diagnosis/interview portions remain single-response
and no-feedback. Do not reinterpret W01D06 or W01D07.

## 4. Bookkeeping Ownership

- Routine control-file bookkeeping and long control-file edits belong to the active repository execution environment; the Master Prompt defines how Project Chat prepares this work for an external executor.
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

- Run the early hygiene check described in Section B, then one final pre-commit
  audit covering applicable build/tests, provenance, required fields,
  consistency, and the mandatory final `git diff --check`.
- For `END WEEK`, verify audit/review/correction/verify separation, AI-0 firewall
  ordering, one batched human-input preflight, weekly decision/carry-over/Recovery/
  eligibility consistency and the authorized remote result.
- For an opted-in bounded coding subpart, verify exactly two maximum scored
  submissions, binary-only hidden feedback, one original timer, raw-attempt
  retention and prospective/non-retroactive application.
- After an authorized push, run one post-push sync check.
- Do not repeat an audit/check when there is no objective failure, conflict or
  new evidence. Rerun only affected validation after allowed mechanical hygiene;
  the mandatory final hygiene check is not a repeated audit.

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

CP-01 retained HANDOFF as context-transfer-only; this amendment makes no
behavioral change to that architecture.

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

For pipelined BOOT prep, steps 2-4 may be represented by the single compact
`BOOT PREP INPUT` after the already-delivered State Snapshot/Theory Pack/day
boundary. Availability and executor consent may be collected together to avoid
sequential round trips. Consent remains explicit and transaction-specific; the
executor prompt still follows approval, and Pre-check waits for prep verification.

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
