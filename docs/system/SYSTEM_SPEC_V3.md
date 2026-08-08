# SYSTEM SPEC V3 — EMBEDDED/FIRMWARE ROADMAP OPERATING CONSTITUTION

**Document ID:** `SYSTEM_SPEC_V3`  
**Version:** `3.0.0`  
**Status:** `FROZEN BASELINE`  
**Effective date:** `2026-08-09`  
**Official roadmap start:** `2026-08-10`  
**Roadmap end:** `2027-01-12`  
**Project v1.0 hard deadline:** `2026-12-14`  
**Timezone:** `Asia/Ho_Chi_Minh`  
**Owner:** Trần Lê Minh  
**Primary domain:** Embedded/Firmware & Connected IoT  
**Primary target:** Internship / trainee / fresher-friendly Embedded/Firmware role with real technical work

---

# 0. PURPOSE OF THIS DOCUMENT

This document is the **system constitution** for the entire Embedded/Firmware roadmap.

It does not contain the detailed week-by-week curriculum. It does not replace the roadmap, master prompt, repository, or `CURRENT_STATE`. Its job is to define the stable rules that all of those artifacts must obey.

The V3 system exists to solve five recurring problems:

1. Prevent artifact quality from being mistaken for real competency.
2. Prevent AI from silently replacing the learner's thinking.
3. Keep evidence, progress, and PASS/FAIL decisions auditable.
4. Make recovery from delays possible without repeatedly rewriting the whole roadmap.
5. Keep the roadmap focused on genuine internship readiness instead of attractive but weak evidence.

The central rule is:

> **Artifact completion, test completion, and competency verification are three different things. None may be silently substituted for another.**

---

# 1. SYSTEM ARCHITECTURE

The V3 system has five primary layers.

## 1.1 Layer 1 — SYSTEM SPEC

File:

```text
SYSTEM_SPEC_V3.md
```

Purpose:

- defines operating rules;
- defines terminology;
- defines PASS semantics;
- defines AI integrity rules;
- defines evidence rules;
- defines recovery and change control;
- defines state transitions;
- defines repository/logging contracts at system level.

This document has the highest authority for operating rules.

## 1.2 Layer 2 — ROADMAP

Expected file:

```text
EMBEDDED_ROADMAP_V3.docx
```

Purpose:

- defines what is learned;
- defines when it is learned;
- defines phases, weeks, and days;
- defines outcomes, project milestones, required competencies, gates, evidence, and career milestones.

The roadmap may specialize this System Spec but may not contradict it.

## 1.3 Layer 3 — MASTER PROMPT

Expected file:

```text
MASTER_PROMPT_V3.md
```

Purpose:

- tells ChatGPT how to operate the roadmap;
- implements the learning workflow;
- implements AI assistance levels;
- creates starter packs;
- reviews submissions;
- performs diagnostics and gates;
- runs recovery;
- updates state.

The Master Prompt is an **execution engine**, not an independent source of policy.

## 1.4 Layer 4 — CURRENT STATE

Expected file:

```text
CURRENT_STATE_V3.md
```

Purpose:

- records the latest operational state;
- records calendar, execution, artifact, and competency positions;
- records valid and contaminated evidence;
- records schedule variance, blockers, and exact next action.

`CURRENT_STATE` describes reality. It does not redefine rules.

## 1.5 Layer 5 — REPOSITORY AND EVIDENCE

The repository contains:

- learner-written code;
- AI-assisted code when allowed and logged;
- tests and build scripts;
- hardware evidence;
- logs and captures;
- reports;
- competency records;
- daily logs;
- weekly scorecards;
- releases;
- project documentation.

The repository is the primary source for **what actually happened**.

---

# 2. SOURCE-OF-TRUTH PRECEDENCE

## 2.1 Operating-rule precedence

```text
SYSTEM_SPEC_V3
    >
EMBEDDED_ROADMAP_V3
    >
MASTER_PROMPT_V3
    >
CURRENT_STATE_V3
    >
daily logs / scorecards / repo documentation
```

A lower-level file may add detail but may not override a higher-level rule.

## 2.2 Technical-fact precedence

For hardware, APIs, registers, protocol behavior, compiler behavior, tool versions, or vendor-specific details:

```text
Official vendor documentation for exact device/version
    >
Pinned official examples / official API references
    >
project-local verified measurements
    >
roadmap teaching material
    >
AI explanation
```

AI-generated register names, API calls, bit fields, clocks, pin mappings, electrical assumptions, or version-sensitive commands must not be treated as authoritative without verification.

## 2.3 Progress precedence

```text
Independent competency evidence
    >
reproducible artifact evidence
    >
test logs / captures / reports
    >
daily log claims
    >
README claims
    >
memory / verbal recollection
```

A README saying `PASS` does not make a task PASS.

---

# 3. HARD CALENDAR ANCHORS

## 3.1 Sprint 0

```text
2026-08-09
```

Sprint 0 is a one-day audit/bootstrap sprint. Its purpose is to:

- verify hardware and toolchain already proven useful;
- fill missing infrastructure;
- establish the new repository;
- freeze V3 conventions;
- verify build/test commands;
- create baseline system files;
- invalidate or archive old competency claims that cannot be independently trusted.

Sprint 0 is not a deep-learning week.

## 3.2 Official Week 1 start

```text
2026-08-10
```

All official V3 learning evidence begins from this date unless a later artifact explicitly imports earlier evidence after revalidation.

## 3.3 Project v1.0 deadline

```text
2026-12-14
```

This deadline is protected. If the roadmap falls behind, recovery prioritizes:

1. mandatory competencies;
2. project-critical features;
3. test/evidence integrity;
4. application readiness;

before polish or optional features.

## 3.4 Roadmap end

```text
2027-01-12
```

This date closes the planned roadmap and evaluates competency, portfolio, interview readiness, application pipeline, and offer/interview status.

Not having an offer by this date is **not automatically equivalent to roadmap failure**.

---

# 4. CORE PRINCIPLES

## 4.1 Competency over appearance

A small project the learner can explain, test, debug, and defend is worth more than a large project mostly produced by AI or copied from examples.

## 4.2 Evidence over confidence

Do not use statements such as:

- “I think I understand.”
- “It looks correct.”
- “It worked once.”
- “The README says PASS.”
- “AI checked it.”

as sufficient proof.

## 4.3 Understanding over memorization

The learner does not need to remember every API name or syntax detail. The learner must understand mechanism, data flow, ownership, lifetime, failure behavior, trade-offs, and debugging reasoning.

## 4.4 Tests do not prove authorship or understanding

Passing tests prove only that a specific artifact satisfied those tests under a specific environment. They do not prove who wrote the code or whether the learner can solve a related unseen problem.

## 4.5 AI is a tool, not a proxy learner

AI may accelerate explanation, test design, review, debugging, documentation, interview practice, and repetitive work. It may not silently replace the learner during a competency gate.

## 4.6 FAIL is diagnostic

`FAIL` means a defined gate has not yet been satisfied. It does not mean the roadmap is over, the learner should quit, or all previous work is worthless.

## 4.7 No repeated full resets for ordinary failure

After V3 begins:

> **A failed day, failed week, or failed gate is handled through recovery, not by deleting the whole roadmap.**

A complete roadmap reset may occur only if the operating system itself is proven structurally invalid.

---

# 5. PROGRESS MODEL

V3 separates four positions.

## 5.1 Calendar Position

Where the roadmap says the learner should be according to date.

## 5.2 Execution Position

The day currently being worked on.

## 5.3 Artifact Position

The latest deliverable with valid reproducible output evidence.

## 5.4 Competency Position

The latest competency gate independently verified.

This is the position used to decide whether the learner is ready to build on a prerequisite.

## 5.5 Positions must never be merged

Invalid reasoning:

```text
Tests passed
therefore
competency passed
```

Correct reasoning:

```text
Tests passed
therefore
artifact correctness has evidence

Independent gate passed
therefore
competency has evidence
```

---

# 6. STANDARD STATUS VOCABULARY

All roadmap elements must use the following statuses.

## 6.1 NOT_STARTED

No meaningful work has begun.

## 6.2 LEARNING

Theory, reading, examples, or guided practice is in progress.

## 6.3 IMPLEMENTING

The learner is producing the required artifact.

## 6.4 ARTIFACT_PASS

The artifact satisfies its required build/test/output contract. This does not imply competency PASS.

## 6.5 COMPETENCY_UNVERIFIED

Artifacts may exist, but independent understanding has not been verified.

## 6.6 COMPETENCY_PASS

The learner has passed the defined independent gate.

## 6.7 PARTIAL

Some required outputs or competencies are satisfied, but mandatory items remain.

## 6.8 BLOCKED

Progress is stopped by an explicit named blocker.

## 6.9 INVALIDATED

Previously accepted evidence is no longer trustworthy or reproducible.

Examples:

- clean build no longer succeeds;
- test evidence cannot be reproduced;
- the learner later discloses that a competency artifact was mostly AI-generated and cannot be explained;
- evidence was recorded incorrectly.

Invalidation is not deletion of history.

## 6.10 RECOVERY

A targeted plan is active to repair a missed P0/P1 requirement.

## 6.11 PASS

Used only when the exact required gate has been satisfied.

## 6.12 FAIL

Used only when a defined gate has been attempted and mandatory criteria were not satisfied.

FAIL must be attached to:

- failed criteria;
- evidence;
- recovery action;
- retest condition.

---

# 7. ARTIFACT PASS VS COMPETENCY PASS

## 7.1 Artifact PASS requires

As appropriate for the task:

- clean build;
- required tests;
- required output;
- evidence saved;
- no unexplained blocker;
- mandatory warnings addressed;
- documented limitations;
- reproducible commands.

## 7.2 Competency PASS requires

A task-specific independent gate that may include:

- closed-book explanation;
- unseen coding exercise;
- unseen debugging exercise;
- output prediction;
- code reading;
- design defense;
- register/API reasoning;
- trade-off questions;
- failure-mode questions.

The gate must test transfer of understanding, not memorization of the exact previous exercise.

## 7.3 Competency PASS cannot be awarded solely from

- commit count;
- test count;
- README quality;
- code volume;
- AI review;
- tutorial completion;
- copied reference code;
- repeated questions already seen in practice.

---

# 8. AI INTEGRITY PROTOCOL

Every meaningful technical learning task must have an explicit AI level.

## 8.1 AI-0 — INDEPENDENT / CLOSED BOOK

Purpose:

- competency gates;
- baseline diagnostics;
- retests;
- selected interview simulations.

Allowed:

- problem statement;
- compiler;
- debugger if the gate permits it;
- hardware instruments if required;
- documentation only if explicitly declared in the gate contract.

Not allowed:

- ChatGPT;
- Copilot;
- code-generating AI;
- AI search summaries;
- prior solution;
- copying previous code unless the gate explicitly tests modification of existing code.

Evidence generated at AI-0 may count toward competency.

## 8.2 AI-1 — THEORY / CLARIFICATION

AI may:

- explain concepts;
- simplify difficult documentation;
- give analogies;
- define terminology;
- ask comprehension questions;
- point to official references.

AI may not solve the assigned implementation or reveal hidden gate answers.

## 8.3 AI-2 — HINT

AI may:

- ask leading questions;
- suggest one next step;
- identify the relevant concept;
- provide partial pseudocode;
- suggest what to measure;
- suggest a test category.

AI should avoid writing the implementation.

## 8.4 AI-3 — REVIEW / DEBUG ASSISTANCE

Prerequisite:

> The learner has already made a meaningful attempt.

AI may:

- review learner-written code;
- identify defects;
- explain warnings;
- propose hypotheses;
- suggest measurements;
- suggest targeted patches;
- generate additional tests.

Artifact evidence remains valid if assistance is logged. Competency still requires independent verification.

## 8.5 AI-4 — PATCH / STRONG ASSISTANCE

AI may provide:

- minimal implementation patches;
- missing function bodies;
- repair for a blocked section;
- more explicit pseudocode.

Any competency directly demonstrated by the provided patch becomes:

```text
COMPETENCY_UNVERIFIED
```

until retested independently.

## 8.6 AI-5 — FULL SOLUTION / REFERENCE

AI may provide a full solution only when:

- the learner explicitly requests it;
- the learning objective has shifted to review/reference;
- prolonged blocking justifies it;
- the roadmap allows it.

Consequences:

- the artifact may still be useful;
- it may still be portfolio material if understood and honestly represented;
- it cannot serve as independent competency evidence;
- a fresh AI-0 gate is required before competency PASS.

---

# 9. AI CONTAMINATION RULES

The term **contaminated** is technical, not moral.

It means AI assistance makes a specific artifact unsuitable as proof of independent competency.

## 9.1 Contamination examples

- AI writes the exact function being evaluated.
- AI explains the exact hidden bug during a diagnostic.
- AI provides a complete ring buffer before independent implementation.
- AI gives an interview answer immediately before the same question is used as a gate.

## 9.2 Contamination does not make the artifact worthless

A contaminated artifact may still prove integration, tool usage, testing, debugging collaboration, documentation, or project completion.

## 9.3 Required response to contamination

Do not delete the artifact. Record:

```text
AI level:
What AI contributed:
Which competency is no longer independently proven:
Required independent retest:
```

## 9.4 Gate contamination

If AI is accidentally used during an AI-0 gate:

```text
Gate result: INVALID / RETEST REQUIRED
```

Do not record PASS. Do not automatically record FAIL. Generate a fresh gate.

---

# 10. AI USAGE LOG CONTRACT

Each meaningful daily log must record AI usage.

Minimum fields:

```text
AI mode used:
AI assistance summary:
Files/functions materially assisted:
Did AI provide implementation code? yes/no
Did AI reveal a gate answer? yes/no
Competencies requiring independent retest because of AI:
```

Honest AI logging is good engineering practice. Hidden AI use is an evidence-integrity failure.

---

# 11. LEARNING LOOP

Every important technical topic follows this sequence:

```text
1. OUTCOME
2. THEORY
3. COMPREHENSION CHECK
4. MINIMAL EXPERIMENT
5. LEARNER IMPLEMENTATION
6. TEST
7. FAILURE / FAULT INJECTION
8. DEBUG / ROOT CAUSE
9. REFACTOR / DOCUMENT
10. INDEPENDENT COMPETENCY CHECK
11. EVIDENCE
12. PASS / RECOVERY
```

Not every small task requires all twelve steps, but major competencies do.

---

# 12. THEORY RULES

Theory must be:

- sufficient to start the task;
- scoped to the current outcome;
- technically accurate;
- linked to official references when version-sensitive;
- followed by comprehension checks.

Theory must not become a disguised full solution.

For major topics, theory should include as appropriate:

- why the topic matters;
- mental model;
- core terminology;
- mechanism;
- minimal example;
- common mistakes;
- failure modes;
- what must be measured;
- interview vocabulary;
- official source references.

---

# 13. EXERCISE DESIGN RULES

Exercises must define:

- measurable outcome;
- acceptance criteria;
- starter state;
- constraints;
- required tests;
- required evidence;
- forbidden shortcuts;
- AI mode;
- submission format.

## 13.1 Starter code

Starter code may include:

- function signatures;
- types;
- constants;
- comments;
- compile-clean stubs;
- test harness;
- mocks;
- fixtures.

Starter code should not contain the core implementation unless the exercise is explicitly a review/debugging exercise.

## 13.2 Test visibility

For normal learning exercises, tests may be visible.

For competency gates:

- at least part of the evaluation must be fresh;
- problems should not simply repeat the practice set;
- hidden or newly generated cases are preferred.

---

# 14. COMPETENCY GATE DESIGN

Every competency gate must declare:

```text
Gate ID:
Competencies tested:
Prerequisites:
AI mode:
Allowed references:
Time limit:
Tasks:
Scoring rubric:
Mandatory items:
Automatic-fail conditions:
Evidence required:
Retest rule:
```

## 14.1 Gate quality requirements

A strong gate checks multiple forms of understanding, for example:

```text
30% explanation
30% coding/reasoning
20% debugging
20% transfer/trade-off
```

Exact weights may vary.

## 14.2 No arbitrary percentage-only PASS

A numeric score is useful but not sufficient. A gate may include mandatory items such as correct pointer safety, ISR safety, ownership, timeout behavior, or electrical assumptions.

## 14.3 Retest

A retest must:

- use new questions or new input;
- target failed competencies;
- avoid identical memorized problems;
- remain AI-0 unless explicitly specified otherwise.

---

# 15. EVIDENCE MODEL

Evidence is classified by type.

## E0 — Claim

Examples: verbal statement, unchecked note, README claim.

## E1 — Static artifact

Examples: source code, design document, diagram, configuration.

## E2 — Execution evidence

Examples: build log, unit-test log, serial output, debugger output, CI result.

## E3 — Measurement evidence

Examples: logic-analyzer capture, register dump, timing measurement, memory metrics, fault counters, Wireshark capture.

## E4 — Reproducibility evidence

Examples: clean clone build, one-command host test, documented flash procedure, repeatable HIL checklist.

## E5 — Independent competency evidence

Examples: AI-0 coding gate, oral defense, unseen bug diagnosis, project defense, closed-book concept test.

E5 is strongest for proving competency.

---

# 16. EVIDENCE ADMISSIBILITY

Evidence must include enough metadata to answer:

- what was tested;
- when;
- on what commit;
- with what hardware/toolchain;
- using what command;
- expected behavior;
- actual result;
- AI level;
- known limitation.

If critical metadata is missing, evidence may be downgraded.

---

# 17. DEFINITION OF DONE

A feature or milestone is DONE only when the roadmap-relevant subset of these dimensions is satisfied.

## 17.1 Reproducible

Another competent person can follow documented commands and reproduce the required result.

## 17.2 Correct

Mandatory tests pass. Blocking paths have bounded behavior where required. Error/fallback behavior is defined.

## 17.3 Understood

The learner can explain data flow, major APIs/registers, ownership/lifetime, trade-offs, and relevant failure modes.

## 17.4 Evidenced

Required logs/captures/results exist.

## 17.5 Quality-controlled

As appropriate:

- warnings clean;
- bounds handled;
- no obvious lifetime defect;
- no secret leak;
- naming consistent;
- limitations documented.

## 17.6 Interview-defensible

For major milestones, the learner can explain the work without reading a prepared script.

---

# 18. DAILY OPERATING SYSTEM

Every learning day uses one stable structure. The exact tasks come from the roadmap.

## 18.1 Start-of-day protocol

Record:

```text
Date:
Week/Day:
Calendar position:
Execution position:
Primary outcome:
Mandatory competency:
Required artifact:
AI mode:
Available focused hours:
Main blocker:
Stop condition:
```

The day has one primary outcome.

## 18.2 End-of-day status

### GREEN

Mandatory daily artifact and required evidence are complete. If the day contains a competency gate, that gate must also be satisfied for GREEN.

### YELLOW

Meaningful progress exists, but one or more required items remain.

### RED

The primary outcome was not materially achieved.

RED is a data point, not a character judgment.

---

# 19. FIXED DAILY LOG TEMPLATE

All daily logs must use the same schema.

```text
## YYYY-MM-DD — Week XX / Day YY

### 1. Planned Outcome
One measurable sentence.

### 2. Actual Status
GREEN / YELLOW / RED

### 3. Focused Time
Planned:
Actual:

### 4. Independent Work
What I personally implemented, reasoned about, measured, or explained.

### 5. AI Usage
Highest AI level used:
What AI helped with:
Files/functions materially assisted:
Competencies contaminated:
Independent retest required:

### 6. Artifact Result
Files changed:
Build command:
Build result:
Test command:
Test result:

### 7. Evidence
Commit:
Logs:
Captures:
Reports:
Video/demo:
Other:

### 8. Measurements
Expected:
Observed:
Relevant numbers/registers/timing/errors:

### 9. Understanding Check
What I can explain without AI:
What I still cannot explain:

### 10. Defects / Failed Tests
Defect IDs or test IDs:
Root cause known?:
Current hypothesis:

### 11. Carry-over
Exactly one mandatory carry-over if needed:
Closure criteria:

### 12. Next Action
One physical action taking about 5–15 minutes.
```

Do not invent a new daily-log structure unless `SYSTEM_SPEC` is formally amended.

---

# 20. WEEKLY OPERATING SYSTEM

Each week has:

- one main mission;
- required competencies;
- required artifacts;
- mandatory evidence;
- a weekly gate;
- a scorecard;
- a recovery rule;
- a career/English task when scheduled.

---

# 21. WEEKLY SCORECARD

Use six dimensions:

```text
Output
Understanding
Testing
Documentation
Health
Career
```

Each receives `0 / 1 / 2`, except Career may be `N/A` before its scheduled wave.

## 21.1 Output

```text
0 = no meaningful deliverable
1 = local or partial output
2 = reproducible required output
```

## 21.2 Understanding

```text
0 = cannot explain core mechanism
1 = explains basic flow
2 = independently defends mechanism, trade-offs, and failure modes
```

## 21.3 Testing

```text
0 = eyeballing only
1 = basic smoke/unit tests
2 = required negative/fault/soak/reproducibility evidence
```

Use only the level appropriate to the week.

## 21.4 Documentation

```text
0 = required documentation absent
1 = minimum useful documentation
2 = build/test/limitations/evidence are clear and reproducible
```

## 21.5 Health

```text
0 = unsafe load, severe sleep sacrifice, or unsustainable operation
1 = acceptable but strained
2 = sustainable sleep/rest/load
```

Health `0` blocks a normal PASS decision until load is corrected.

## 21.6 Career

Before the career wave begins:

```text
N/A
```

After it begins:

```text
0 = scheduled career action missed
1 = tracker/preparation maintained
2 = required applications/outreach/mock/follow-up completed
```

---

# 22. WEEKLY GATE DECISIONS

## 22.1 PASS

Use only when:

- mandatory P0 competencies pass;
- mandatory artifact criteria pass;
- required evidence is present;
- no gate-blocking health condition exists.

## 22.2 CONDITIONAL PASS

Allowed only when:

- all P0 competencies pass;
- only a small P1 evidence/documentation item remains;
- exactly one carry-over is defined;
- carry-over has a deadline and closure criterion.

Conditional PASS must never hide a failed core competency.

## 22.3 FAIL

Use when:

- a mandatory competency fails;
- a mandatory artifact cannot meet required behavior;
- evidence integrity is invalid;
- a required gate was attempted and mandatory criteria were missed.

FAIL triggers recovery.

---

# 23. TESTING LADDER

V3 preserves a five-level testing ladder.

## L1 — Host / Unit

For pure logic: bit operations, ring buffer, CRC, parser, state machine, protocol encode/decode.

## L2 — Peripheral Smoke

For physical interfaces: GPIO, UART, I2C WHO_AM_I, SPI loopback/JEDEC ID, CAN loopback.

## L3 — Integration

For component interaction: task → queue → logger, sensor → MCU, STM32 → ESP32, ESP32 → broker.

## L4 — Fault Injection

Examples: sensor removed, NACK, UART corruption, queue full, wrong baud, broker down, Wi-Fi loss, invalid command, bad image.

## L5 — Soak / Resilience

Examples: 4–8 hour run, reconnect cycles, stack/heap metrics, error counters, reset/recovery, OTA rollback.

The roadmap decides the required level for each milestone.

---

# 24. TEST DESIGN REQUIREMENTS

Test matrices should cover only relevant categories, including:

- normal path;
- boundary;
- invalid input;
- overflow/wrap-around;
- timeout;
- repeated calls;
- state transition;
- resource exhaustion;
- concurrency/ISR interaction;
- fault injection;
- regression;
- clean-build reproducibility.

Tests must trace back to a requirement or failure mode.

---

# 25. DEBUG / STUCK PROTOCOL

Random code modification is prohibited as a default debugging method.

Use:

```text
1. OBSERVE
2. DEFINE EXPECTED
3. LOCK ASSUMPTIONS
4. FORM HYPOTHESES
5. MAKE ONE MEASUREMENT
6. UPDATE HYPOTHESIS
7. APPLY MINIMAL FIX
8. ADD REGRESSION TEST
9. SAVE ROOT-CAUSE STORY
```

## 25.1 Time escalation

### 0–30 minutes

- inspect errors/logs;
- verify assumptions;
- verify clock/pin/state/lifetime/bounds.

### 30–120 minutes

- minimal reproduction;
- debugger;
- logic analyzer;
- one-hypothesis-at-a-time measurement.

### 2–4 hours

- compare with official example;
- inspect official docs;
- request targeted review;
- write an issue with evidence.

### End of day

Stop random experimentation. Save reproduction and next hypothesis.

### More than two days

Cut extension work, use fallback if allowed, and protect critical path.

---

# 26. ROOT-CAUSE REPORT FORMAT

```text
Symptom:
Expected:
Reproduction:
Known facts:
Unknowns:
Hypotheses:
Measurements:
Root cause:
Minimal fix:
Regression test:
Side effects:
Remaining limitation:
AI assistance used:
```

---

# 27. RECOVERY SYSTEM

Recovery exists to protect the roadmap from both denial and overreaction.

## 27.1 Priority classes

### P0 — Mandatory competency / critical path

Examples: C fundamentals, MCU fundamentals, interrupt/debugging, RTOS ownership/concurrency, project-critical protocol behavior, release blockers.

P0 is protected.

### P1 — Required support work

Examples: required tests, core documentation, essential evidence, scheduled career task.

P1 may be simplified but not silently removed.

### P2 — Optional / polish / extension

Examples: cosmetic README work, optional peripherals, extra features, over-engineering, nonessential refactors.

P2 is cut first.

---

# 28. RECOVERY TRIGGER

Recovery is considered when:

- execution is materially behind calendar;
- a weekly gate fails;
- two RED days occur consecutively;
- a P0 blocker exceeds planned time;
- competency evidence is invalidated;
- health requires reduced load.

---

# 29. RECOVERY PROCEDURE

1. Identify exact failed competencies.
2. Identify exact schedule variance.
3. Freeze P2.
4. Reduce P1 polish.
5. Preserve P0.
6. Create targeted exercises.
7. Set retest criteria.
8. Limit the recovery plan to a maximum planned window of approximately seven days before reassessing.
9. Resume the normal roadmap when retest criteria pass.

Recovery is not “redo everything”.

---

# 30. SCHEDULE VARIANCE

`CURRENT_STATE` must track:

```text
Calendar position:
Execution position:
Days behind/ahead:
Reason:
Recovery active?:
Critical deadline at risk?:
```

A delay is not hidden. A delay is not automatically repaid by unsafe extra hours.

---

# 31. LOAD AND HEALTH RULES

The roadmap may define standard, peak, and minimum weeks.

System-level constraints:

- no all-night debugging;
- no routine >9 focused hours/day;
- do not compensate for scope creep with chronic sleep loss;
- after 22:30, prefer logging/stopping rather than major code changes;
- peak periods require recovery;
- health deterioration may justify minimum-load mode.

The goal is sustained learning quality.

---

# 32. SCOPE CONTROL

No technology enters the roadmap merely because it is interesting.

A new item requires:

```text
Reason:
Target role/JD relevance:
Competency value:
Time cost:
What existing scope will be removed:
Effect on gates:
Effect on deadlines:
```

Without an explicit trade-off, new scope is rejected.

---

# 33. CHANGE CONTROL

## 33.1 What may change freely

- daily timeboxes;
- implementation details;
- optional tooling;
- specific exercise examples;
- order of small same-week sub-tasks if the gate is unaffected.

## 33.2 What requires documented approval

- project deadline;
- roadmap end date;
- mandatory competency;
- major technology addition/removal;
- PASS definition;
- AI integrity rule;
- repository evidence schema;
- gate requirements.

---

# 34. SYSTEM FREEZE POLICY

`SYSTEM_SPEC_V3.md` is frozen after acceptance.

Do not rewrite it because:

- wording could be prettier;
- one day went badly;
- a gate failed;
- a new tool looks interesting;
- anxiety suggests starting over.

Amend only when a real system defect is observed.

## 34.1 Amendment format

```text
Amendment ID:
Date:
Defect:
Why current rule fails:
Proposed change:
Affected files:
Migration impact:
Approval:
```

Versioning:

```text
3.0.x = clarification / no behavior change
3.x.0 = backward-compatible policy addition
4.0.0 = breaking operating-system change
```

---

# 35. ANTI-PERFECTIONISM RULE

System design itself must not become procrastination.

Once V3 is frozen:

> Learning work has priority over endlessly improving the learning-management system.

Documentation polish is P2 unless it is directly required by a gate or job application.

---

# 36. REPOSITORY GOVERNANCE

The detailed repository design will be defined separately, but all V3 repositories must support these categories:

```text
roadmap-control/
learning/
firmware/
tests/
docs/
evidence/
captures/
tools/
```

The exact structure may evolve, but the meaning must remain stable.

---

# 37. REQUIRED CONTROL FILES

The main repository should include equivalents of:

```text
roadmap-control/
    current-state.md
    daily-log.md
    competency-ledger.md
    ai-usage-log.md
    weekly-scorecards/
    recovery/
```

The final repository specification may refine naming but must preserve these concepts.

---

# 38. COMPETENCY LEDGER

The competency ledger records skill state independently from project state.

Minimum entry:

```text
Competency ID:
Name:
Roadmap source:
Required level:
Artifact evidence:
Independent gate:
AI mode:
Status:
Last verified:
Expiry/retest condition if any:
Notes:
```

---

# 39. AI USAGE LOG

The repository must maintain a lightweight AI usage history for honesty, provenance, retest planning, and preventing fake competency.

This log must not become bureaucratic busywork. Record only material assistance.

---

# 40. COMMIT POLICY

A commit is an engineering snapshot, not a competency score.

Recommended pattern:

```text
<type>(<scope>): <behavior>
```

Examples:

```text
feat(ring-buffer): add bounded push/pop API
test(bit-ops): cover invalid bit indices
fix(uart): clear RXNE handling regression
docs(week-01): record closed-book gate result
```

Avoid messages whose only meaning is `done`, `final`, `pass`, `update`, or `fix stuff`.

---

# 41. BRANCH POLICY

Preferred simple workflow:

```text
main
feature/<short-topic>
fix/<short-topic>
recovery/<gate-or-topic>
```

Do not create process complexity that adds no learning value.

---

# 42. GENERATED ARTIFACT POLICY

Do not commit:

- binaries unless intentionally released;
- temporary build directories;
- IDE noise;
- private credentials;
- private keys;
- Wi-Fi passwords;
- personal tokens;
- private certificate material.

Generated evidence may be committed when intentionally useful and reasonably sized.

---

# 43. SECURITY RULES

Never commit or send to AI:

- Wi-Fi password;
- tokens;
- private keys;
- private certificate material;
- confidential employer code;
- confidential interview material;
- sensitive private URLs where disclosure matters.

Use `secrets.example`, `.gitignore`, and local configuration excluded from Git.

---

# 44. HARDWARE SAFETY

Before hardware changes, verify:

- voltage;
- common ground;
- pin mode;
- alternate function;
- connector;
- current/power assumptions.

Do not apply 5 V directly to a 3.3 V-only pin. Do not invent wiring from memory when official board documentation exists.

---

# 45. TECHNICAL VERIFICATION RULE

For version-sensitive topics, the mentor/AI must verify the exact version before giving authoritative instructions.

Examples:

- STM32 reference manual;
- CMSIS;
- STM32Cube software;
- ESP-IDF;
- FreeRTOS API;
- compiler flags;
- OTA APIs;
- certificate APIs.

If uncertain, label uncertainty and verify.

---

# 46. CAREER CLAIM INTEGRITY

CV/GitHub/interview claims must map to evidence.

Do not claim `production-ready`, `secure`, `real-time`, `optimized`, or `robust` without defining the claim and supporting it.

Prefer specific verbs:

```text
implemented
tested
measured
debugged
integrated
designed
validated
```

If a feature is not yet gated, label it `in progress`.

---

# 47. INTERVIEW READINESS

Major competencies should eventually support:

- concise explanation;
- deeper follow-up;
- code reading;
- debugging;
- design trade-offs;
- failure-mode discussion;
- project evidence.

The learner should be able to defend the repository for approximately 30 minutes by the final portfolio phase.

---

# 48. HANDOFF CONTRACT

A new assistant/account must be able to resume without reconstructing history from memory.

At handoff, provide:

```text
System Spec version:
Roadmap version:
Master Prompt version:
Current State version:
Repo URL:
Calendar position:
Execution position:
Artifact position:
Competency position:
Last valid gate:
AI-contaminated evidence:
Active recovery:
Current blocker:
Exact next action:
Critical deadlines:
Files to inspect first:
```

---

# 49. CURRENT STATE MINIMUM CONTRACT

`CURRENT_STATE_V3.md` must contain at least:

```text
Generated at:
Timezone:

System Spec version:
Roadmap version:
Master Prompt version:

Calendar position:
Execution position:
Artifact position:
Competency position:

Last artifact PASS:
Last competency PASS:

Competencies verified:
Competencies unverified:
Competencies invalidated/retest required:

Current AI mode:
AI-contaminated evidence:

Current outcome:
Current gate:
Gate completed:
Gate missing:

Repo URL:
Branch:
Commit:
Release:

Build command:
Latest build result:
Test command:
Latest test result:

Hardware working:
Hardware missing/broken:
Toolchain versions:

Open blockers:
Known bugs:
Technical debt:
Carry-over:

Schedule variance:
Recovery status:
Critical path risk:

Weekly scorecard:
Career pipeline:
Health/load:

Next gate:
Hard deadline:
Scope cuts:

Exact next action:
Files/links to inspect:
```

---

# 50. OLD EVIDENCE MIGRATION RULE

The pre-V3 attempt is not automatically trusted as competency evidence.

It may be used as:

- historical artifact;
- toolchain evidence;
- hardware evidence;
- debugging reference;
- example material.

It becomes competency evidence only after V3 revalidation.

## 50.1 Old repository handling

Preferred procedure:

1. make a local/private archive if technically possible;
2. mark the old attempt deprecated;
3. create the new V3 repository;
4. if desired, delete the old public repository after preserving any needed audit material.

Deleting old public history must not be used to pretend the previous attempt never happened.

---

# 51. SPRINT 0 REVALIDATION RULE

Sprint 0 should not waste time reinstalling tools that already work.

Revalidate what matters:

- STM32 build/flash/debug;
- ESP32 build/flash/monitor;
- Git;
- UART terminal;
- logic analyzer capture;
- host compiler;
- required version notes;
- repository bootstrap.

Missing items are completed. Working items are quickly reconfirmed.

---

# 52. DAILY PACK CONTRACT

The future Master Prompt may generate a day pack.

For coding days, the pack should normally include:

- theory notes;
- TODO;
- API/header when relevant;
- compile-clean implementation skeleton;
- tests;
- submission template.

Core solution code must not be pre-filled in AI-0/AI-1/AI-2 learning contexts.

---

# 53. SUBMISSION CONTRACT

A submission must identify:

```text
Task:
AI level:
Commit:
Files:
Build command/result:
Test command/result:
Evidence:
Known failures:
Questions for reviewer:
```

---

# 54. REVIEW SEVERITY

Code review findings use:

```text
BLOCKER
HIGH
MEDIUM
LOW
```

### BLOCKER

Crash, hang, unsafe hardware action, corrupted data, secret leak, build failure.

### HIGH

Bounds, lifetime, race, timeout, protocol incompatibility, critical error path.

### MEDIUM

Maintainability, API design, testability, documentation.

### LOW

Style/polish.

Near a gate, fix BLOCKER/HIGH before broad refactors.

---

# 55. FORBIDDEN SHORTCUTS

Unless explicitly allowed:

- copy a complete driver and claim it as learned;
- paste AI code without understanding;
- skip failure paths;
- hide failed tests;
- delete evidence that contradicts a PASS claim;
- rewrite a test only to make faulty behavior pass;
- hard-code expected output to satisfy a test;
- mark a gate PASS from README text;
- use AI during AI-0 and omit that fact;
- change the roadmap to avoid a difficult competency.

---

# 56. ACCEPTABLE TOOL USE

Tool use is encouraged when it improves engineering.

Examples:

- compiler warnings;
- sanitizers;
- debugger;
- static analysis;
- logic analyzer;
- serial logger;
- Wireshark;
- CI;
- Python helpers;
- AI review.

The purpose is not to prove the learner can work without tools forever. AI-0 exists specifically to verify ownership of the underlying competency.

---

# 57. REFERENCE SOLUTION POLICY

Reference solutions may exist internally for validating test harnesses.

They should not be shown before the learner's meaningful attempt unless the task is explicitly a review exercise or AI-5 is invoked.

Once a reference solution is shown, the exact task cannot later serve as independent competency evidence without a fresh variant.

---

# 58. RETENTION VS MASTERY

The learner is not expected to permanently memorize every detail.

A competency PASS means:

- core mental model is present;
- learner can reason through related problems;
- learner can recover forgotten syntax from documentation;
- learner can explain major risks and failure behavior.

Forgetting a detail does not automatically invalidate competency. Being unable to reconstruct the core mechanism may trigger targeted review.

---

# 59. PREREQUISITE ENFORCEMENT

The roadmap may declare hard prerequisites.

A downstream phase must not begin when a prerequisite competency is materially missing.

Examples:

- advanced MCU work should not rely on unverified basic C;
- RTOS integration should not hide weak pointer/lifetime understanding;
- project integration should not bypass basic peripheral/debug competence.

---

# 60. CARRY-OVER RULE

Normal weekly review allows at most:

```text
one mandatory carry-over item
```

unless Recovery Mode is active.

Carry-over requires:

```text
Task:
Reason:
Deadline:
Closure criteria:
Effect on next week:
```

Optional backlog does not count as carry-over.

---

# 61. APPLICATION PIPELINE RULE

Career work must not be postponed until the technical roadmap is “perfect”.

The roadmap will define application waves. Once a wave begins, job tracking, applications, outreach, CV tailoring, mock interviews, and follow-up continue in parallel unless health/recovery requires a documented temporary reduction.

---

# 62. END-OF-ROADMAP RULE

At `2027-01-12`, evaluate with data:

- competency gates;
- project releases;
- test evidence;
- portfolio quality;
- interview performance;
- application statistics;
- active interview pipeline;
- offers.

Do not reduce the entire result to one binary variable such as `offer/no offer`.

---

# 63. SYSTEM INVARIANTS

The following statements must remain true throughout V3.

1. `PASS` always has explicit criteria.
2. AI assistance is recorded when material.
3. AI-assisted artifacts do not automatically become independent competency evidence.
4. Core competency requires independent verification.
5. Tests and competency are tracked separately.
6. Calendar and execution positions are tracked separately.
7. FAIL triggers recovery, not a full reset.
8. Recovery cuts optional scope before core competency.
9. Health cannot be sacrificed indefinitely to hide schedule variance.
10. Claims must map to evidence.
11. Technical facts are verified against official version-specific sources when needed.
12. The roadmap is not rewritten to avoid discomfort.
13. The system is not endlessly polished instead of used.
14. Old invalid evidence is marked, not secretly reclassified.
15. The final objective is real engineering ability and internship readiness.

---

# 64. DOWNSTREAM DOCUMENT REQUIREMENTS

## 64.1 ROADMAP V3 must define

For every phase/week:

- dates;
- mission;
- required competencies;
- hard prerequisites;
- mandatory artifacts;
- testing level;
- competency gate;
- AI constraints;
- evidence;
- career/English work;
- recovery/cut order;
- exit criteria.

For every day:

- primary outcome;
- theory scope;
- practical work;
- test/evidence;
- AI mode;
- stop condition.

## 64.2 MASTER PROMPT V3 must implement

- source hierarchy;
- state model;
- AI levels;
- starter-pack policy;
- diagnostic mode;
- gate mode;
- debug mode;
- recovery mode;
- daily review;
- weekly review;
- handoff;
- state update;
- anti-overclaim rules.

It must not create alternative PASS definitions.

## 64.3 CURRENT STATE V3 must track

- all four positions;
- last valid gates;
- AI contamination;
- schedule variance;
- blockers;
- recovery;
- current command/result;
- exact next action.

## 64.4 Repository specification must implement

- stable daily logs;
- competency ledger;
- AI usage log;
- weekly scorecards;
- recovery logs;
- evidence paths;
- code/test/doc separation;
- reproducible commands.

---

# 65. ACCEPTANCE TEST FOR THIS SYSTEM SPEC

This System Spec is considered successfully implemented only when a future assistant can answer the following without ambiguity:

1. Does passing 100 tests prove competency?  
   **No.**

2. Can AI-generated code appear in the project?  
   **Yes, when allowed and honestly logged.**

3. Can that AI-generated code independently prove the learner's skill?  
   **No.**

4. What proves competency?  
   **A defined independent gate, normally AI-0.**

5. What happens after a failed week?  
   **Targeted recovery, not automatic roadmap deletion.**

6. Can a Conditional PASS hide a failed core competency?  
   **No.**

7. Can old pre-V3 evidence be used?  
   **Yes as historical/artifact evidence; competency claims require revalidation.**

8. Which date officially begins V3 Week 1?  
   **2026-08-10.**

9. Which date is V3 Sprint 0?  
   **2026-08-09.**

10. What is the roadmap end date?  
    **2027-01-12.**

11. What is the protected project v1.0 date?  
    **2026-12-14.**

12. What happens if the system itself becomes a source of procrastination?  
    **Freeze it and return to learning work.**

---

# 66. FINAL OPERATING RULE

When in doubt, choose the action that maximizes:

```text
real competency
+ reproducible engineering evidence
+ long-term employability
```

while minimizing:

```text
fake progress
+ hidden AI substitution
+ scope creep
+ unsustainable workload
```

The system exists to support learning.

The learner does not exist to maintain the system.

---

# 67. FREEZE DECLARATION

This file establishes the baseline operating constitution for the reset roadmap beginning with Sprint 0 on `2026-08-09` and official Week 1 on `2026-08-10`.

From this point forward:

- ordinary daily mistakes do not justify a system rewrite;
- ordinary failed gates do not justify a roadmap reset;
- AI usage is managed transparently instead of denied;
- evidence and competency remain separate;
- progress is reported exactly as it is;
- recovery is expected when necessary;
- the roadmap must now be built on top of these rules.

**Status after acceptance:** `FROZEN BASELINE — SYSTEM_SPEC_V3 3.0.0`
