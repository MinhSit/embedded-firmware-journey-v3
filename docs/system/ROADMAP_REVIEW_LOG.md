# ROADMAP REVIEW LOG — EMBEDDED/FIRMWARE ROADMAP V3.1

**Document ID:** `ROADMAP_REVIEW_LOG`
**Version:** `1.0.5`
**Status:** `ACTIVE REVIEW LOG — NON-AUTHORITATIVE`
**Created:** `2026-08-09`
**Timezone:** `Asia/Ho_Chi_Minh`
**Reviewed roadmap:** `EMBEDDED_ROADMAP_V3.1.docx`
**System authority:** `SYSTEM_SPEC_V3.md 3.0.0`
**Execution authority:** `MASTER_PROMPT_V3.md 3.0.3`
**Intended repo path:** `docs/system/ROADMAP_REVIEW_LOG.md`
**Canonical live repo:** `https://github.com/MinhSit/embedded-firmware-journey-v3`

---

# 0. PURPOSE

File này là **nhật ký đánh giá roadmap theo bằng chứng thực thi**.

Nó tồn tại để tránh hai cực:

1. **Blind execution** — cứ chạy roadmap dù evidence cho thấy cấu trúc/tải học/thứ tự/gate có lỗi.
2. **Endless redesign** — viết lại roadmap vì lo lắng hoặc vì muốn “100% hoàn hảo” trước khi học.

Nguyên tắc:

> **Freeze baseline, execute, measure, review, then change only when evidence justifies change.**

File này KHÔNG có quyền:
- thay roadmap;
- đổi deadline;
- thêm/bỏ mandatory competency;
- đổi PASS definition;
- đổi AI integrity;
- đổi gate;
- cho phép scope mới;
- biến proposal thành rule.

---

# 1. AUTHORITY

```text
SYSTEM_SPEC_V3.md
    >
EMBEDDED_ROADMAP_V3.1.docx
    >
MASTER_PROMPT_V3.md
    >
CURRENT_STATE / repo operational state
    >
ROADMAP_REVIEW_LOG.md
```

Nếu file này mâu thuẫn source cao hơn: **source cao hơn thắng**.

---

# 2. BASELINE INVARIANTS

Các mốc bảo vệ:

```text
Sprint 0:                 09/08/2026
Week 1 start:             10/08/2026
Foundation MCU gate:      06/09/2026
Data Logger v1.0:         11/10/2026
Telemetry v0.1:           01/11/2026
CAN/verification gate:    08/11/2026
MQTT TLS checkpoint:      15/11/2026
Production/OTA design:    29/11/2026
HTTPS OTA checkpoint:     06/12/2026
Release candidate:        13/12/2026
Project v1.0 deadline:    14/12/2026
Roadmap close:            12/01/2027
```

Mọi revision vẫn phải giữ đúng tinh thần:
1. `ARTIFACT_PASS != COMPETENCY_PASS`.
2. Core competency cần independent verification.
3. AI material assistance phải được ghi khi ảnh hưởng kỹ thuật.
4. AI-4/5 làm affected competency unverified cho tới fresh retest.
5. Ordinary FAIL đi vào recovery, không reset toàn roadmap.
6. Calendar/Execution/Artifact/Competency không được nhập làm một.
7. P0 được bảo vệ trước P1/P2.
8. Technical fact version-sensitive dùng official exact-version source.
9. Không dùng thiếu ngủ để trả schedule debt.
10. Claim phải map evidence.

---

# 3. CHANGE CONTROL TỪ SYSTEM SPEC

Có thể điều chỉnh tự do nếu gate không đổi:
- daily timebox;
- implementation detail;
- optional tooling;
- specific exercise example;
- small same-week sub-task order.

Cần documented approval:
- project deadline;
- roadmap end date;
- mandatory competency;
- major technology addition/removal;
- PASS definition;
- AI integrity rule;
- repository evidence schema;
- gate requirement.

System Spec cũng khóa nguyên tắc:

> Learning work có priority cao hơn việc endless polish learning-management system.

---

# 4. REVIEW FLOW

```text
CONCERN
  ↓
OBSERVATION
  ↓
EVIDENCE
  ↓
REAL DEFECT?
  ├─ NO → CLOSE / DEFER
  └─ YES
       ↓
IMPACT ANALYSIS
       ↓
MINIMUM CHANGE
       ↓
OWNER APPROVAL
       ↓
APPLY
       ↓
VERIFY
```

Không dùng:

```text
ANXIETY → REWRITE ROADMAP
```

---

# 5. REVIEW ITEM STATUS

```text
HYPOTHESIS
OBSERVING
WATCH
DEFECT_CONFIRMED
PROPOSAL_READY
APPROVED
REJECTED
DEFERRED
CLOSED
```

- `HYPOTHESIS`: nghi ngờ, chưa có evidence.
- `OBSERVING`: đang thu dữ liệu.
- `WATCH`: có tín hiệu nhưng chưa đủ mạnh.
- `DEFECT_CONFIRMED`: evidence xác nhận lỗi roadmap/system.
- `PROPOSAL_READY`: đã có impact analysis + minimum-change proposal.
- `APPROVED`: owner chấp nhận.
- `REJECTED`: lợi ích/trade-off không đủ.
- `DEFERRED`: có thể hữu ích nhưng chưa đúng thời điểm.
- `CLOSED`: concern đã giải quyết hoặc chứng minh không phải defect.

---

# 6. REVIEW SEVERITY

## R0 — Cosmetic
Wording/layout/formatting không đổi behavior.
**Default:** không chặn execution.

## R1 — Operational friction
Day pack/logging/tool workflow gây phiền nhưng không ảnh hưởng gate.
**Default:** chỉnh operational detail, không rewrite roadmap core.

## R2 — Learning design risk
Prerequisite, practice, workload, evidence hoặc AI workflow có khả năng làm learning yếu.
**Default:** collect evidence + review tại checkpoint gần nhất.

## R3 — Critical path risk
Milestone có nguy cơ không khả thi, prerequisite block downstream, repeated structural failure.
**Default:** formal review ngay.

## R4 — System defect
PASS semantics/AI integrity/evidence authority tự mâu thuẫn hoặc false-PASS có tính hệ thống.
**Default:** formal System Spec amendment process.

---

# 7. EARLY REVIEW TRIGGERS

Không cần chờ checkpoint nếu có:

```text
[ ] R3/R4 concern.
[ ] Hard prerequisite không thể thực hiện với hardware/toolchain hiện có.
[ ] Cùng structural failure lặp lại qua nhiều task/tuần.
[ ] Gate yêu cầu competency chưa được dạy/practice đủ hợp lý.
[ ] Workload lặp lại vượt health/load constraints.
[ ] Critical deadline dự kiến trượt >7 ngày dù P2 đã cắt.
[ ] Source conflict làm execution không xác định.
[ ] Evidence cho thấy roadmap tạo fake progress.
```

Không trigger full review chỉ vì:
- một ngày YELLOW;
- một gate FAIL do learner gap;
- một bug khó;
- cảm giác roadmap chưa hoàn hảo;
- một technology mới hấp dẫn.

---
# 8. FORMAL REVIEW CHECKPOINTS

## CP-00 — Sprint 0 Exit — 09/08/2026
Focus: operational readiness.

Review:
```text
[ ] STM32 build/flash/debug
[ ] ESP32 build/flash/monitor
[ ] Host compiler/test
[ ] UART/measurement path
[ ] ARM GCC/CMake status
[ ] Inventory/fallback
[ ] Week 1 có thể bắt đầu không cần sửa system
```

Decision:
```text
CONTINUE
SPRINT0_RECOVERY
```

## CP-01 — End of Week 1 — 16/08/2026
Focus: first real learning-system validation.

Review:
```text
Workload:
- planned vs actual focused hours
- có bị ép >9h/day không?

Learning:
- C progression hợp lý?
- practice chuẩn bị đủ cho gate?
- gate đo transfer hay memorization?

AI:
- AI-1/AI-2 có đủ?
- có thường phải dùng AI-4 không?

Bookkeeping:
- logs/evidence hữu ích hay bureaucracy?

Week Consistency Sweep:
- follow `roadmap-control/operating-rules.md` Section 13
- cover every Week 1 CLOSED day with closure-linter output + human semantic audit
- record PASS/WARN/FAIL/N/A without re-grading technical competency
```

Decision:
```text
CONTINUE V3.1
OPERATIONAL ADJUSTMENT
OPEN REVIEW ITEM
```

## CP-02 — Foundation MCU Gate — 06/09/2026
Focus: first architecture-level curriculum review.

Review:
```text
[ ] C foundation đủ để debug MCU?
[ ] startup/GPIO/EXTI/UART/timer/HardFault sequence hợp lý?
[ ] datasheet/RM/schematic usage đã thành thói quen?
[ ] measurement/debug phát triển song song coding?
[ ] prerequisite nào đặt sai thứ tự?
[ ] industry-style unseen bug/review có cần tăng?
[ ] schedule variance còn trong recovery capacity?
```

## CP-03 — Data Logger v1.0 — 11/10/2026
Focus: RTOS + peripheral + project integration.

Review:
```text
[ ] RTOS/concurrency đã thành system behavior thật?
[ ] I2C/SPI/testing đủ cho project?
[ ] Data Logger có fault/soak/test report/defense?
[ ] project complexity có đúng effort/value?
[ ] project-local spec có đủ cụ thể?
[ ] career pipeline bắt đầu đúng wave?
```

## CP-04 — Telemetry/CAN Verification — 01/11 & 08/11
Focus: integration/protocol/verification.

Review:
```text
[ ] STM32↔ESP32 ownership/error boundary rõ?
[ ] parser/CRC/fault tests đủ?
[ ] network integration có che weakness firmware core?
[ ] requirement→test→evidence traceability usable?
[ ] CAN scope còn bounded?
[ ] industry realism đủ qua debug/review/traceability?
```

## CP-05 — Production / OTA Design — 29/11/2026
Focus: protect critical path.

Review:
```text
[ ] TLS/security claims có evidence?
[ ] threat model phân biệt mitigation/limitation?
[ ] OTA scope bounded ở ESP32?
[ ] memory/error/soak/reconnect evidence đủ?
[ ] P2 đã cắt?
[ ] revision lúc này có tăng deadline risk?
```

Default bias: **freeze features, reduce changes**.

## CP-06 — Release Candidate — 13/12/2026
Focus: release readiness, không redesign curriculum.

```text
[ ] relevant test matrix rerun
[ ] clean clone/reproducibility
[ ] claims map evidence
[ ] major competency interview-defensible
[ ] 30-min repo walkthrough ready
[ ] only BLOCKER/HIGH remain
```

## CP-07 — v1.0 Hard Deadline — 14/12/2026

```text
NO NEW FEATURE
```

Focus chuyển sang release/interview/application.

## CP-08 — Roadmap Close — 12/01/2027

Review:
```text
Competency gates
Project releases
Testing/evidence
Portfolio
Interview performance
Application data
Active pipeline
Offers/interviews
What worked
What failed
Next 30-day plan
```

Không đánh giá toàn roadmap chỉ bằng offer/no-offer.

---
# 9. REVIEW DIMENSIONS

Mỗi formal review dùng:

```text
OK
WATCH
DEFECT
UNKNOWN
```

## Curriculum Coverage
- core competency nào thiếu?
- competency nào học nhưng không gate?
- optional scope nào chiếm quá nhiều time?
- downstream phase nào dựa prerequisite chưa đủ?

## Sequencing / Prerequisites
- thứ tự topic tạo transfer tốt?
- learner có phải copy vì prerequisite thiếu?
- gate trước có bảo vệ phase sau?

## Workload Realism
So sánh:
```text
planned hours
actual hours
GREEN/YELLOW/RED
carry-over
sleep/load
recovery usage
```

Repeated need for >9 focused hours/day = warning signal.

## Learning Depth
```text
Can explain?
Can implement?
Can debug?
Can transfer to unseen case?
Can defend trade-off?
```

Artifact PASS liên tục nhưng AI-0 gate yếu = vấn đề cần điều tra.

## AI Integrity Fit
```text
AI-1/AI-2 sufficient?
AI-3 after meaningful attempt?
AI-4/5 frequency?
Retest realistic?
AI log lightweight?
```

## Testing / Evidence Overhead
- evidence có giúp reproduce/debug/interview?
- có duplicate log vô nghĩa?
- paperwork có ăn implementation time quá nhiều?

## Industry Relevance
Check qua:
```text
real code
debugging
official docs
measurement
fault handling
code review
maintenance reasoning
testing
integration
project defense
```

## Project Value
- architecture explainable?
- failure behavior có evidence?
- test strategy traceable?
- limitation honest?
- effort/value ratio tốt?

## Career Pipeline Fit
- tracker/CV/JD/application/outreach/mock/follow-up đúng wave?

## Health / Sustainability
- sleep/focus/burnout/peak recovery/exam-family constraints.

Nếu baseline chỉ chạy được bằng chronic sleep sacrifice → review defect.

---
# 10. EVIDENCE REQUIRED BEFORE ROADMAP CHANGE

Evidence đủ mạnh có thể là:

```text
A. Repeated execution evidence
   cùng vấn đề lặp 2–3 ngày hoặc nhiều task.

B. Gate evidence
   gate chỉ ra gap có tính hệ thống.

C. Schedule evidence
   actual hours / variance / recovery.

D. Technical dependency evidence
   official docs / hardware constraint.

E. Career evidence
   nhiều target JD cùng chỉ ra missing core signal.

F. Project evidence
   integration/test architecture chứng minh design không khả thi.

G. Health/load evidence
   baseline workload lặp lại vượt constraints.
```

Không đủ để sửa roadmap:
- “Tôi thấy lo.”
- “Có vẻ thiếu.”
- một video nói nên học thêm X;
- một JD random có Y;
- một ngày học khó.

Các tín hiệu đó chỉ được mở `HYPOTHESIS`.

---
# 11. CHANGE LEVELS VÀ REACTION CHAIN

## Level A — Operational Adjustment
Ví dụ:
```text
timebox
exercise example
optional tool
small same-week reorder
```

Impact:
```text
Roadmap:      usually no change
MasterPrompt: no
CurrentState: only if execution changes
ReviewLog:    optional note
Risk:         LOW
```

## Level B — Roadmap Clarification
Ví dụ:
- làm rõ wording;
- làm rõ evidence path;
- không đổi requirement.

Impact:
```text
Roadmap:      may change
MasterPrompt: only if behavior interpretation changes
Handbook:     only if learner workflow changes
CurrentState: note revision if relevant
ReviewLog:    mandatory
Risk:         LOW→MEDIUM
```

Không được dùng “clarification” để stealth-add requirement.

## Level C — Curriculum / Gate Change
Ví dụ:
- thêm/bỏ mandatory competency;
- đổi prerequisite;
- đổi weekly gate;
- chuyển major content tuần;
- đổi mandatory project feature.

Reaction chain:
```text
ROADMAP
  ↓
prerequisite map
  ↓
daily cards
  ↓
gate contract
  ↓
CURRENT_STATE compatibility
  ↓
competency ledger mapping
  ↓
Master Prompt if affected
  ↓
handbook if learner workflow affected
  ↓
schedule/deadline analysis
```

Requires:
```text
documented approval
impact analysis
migration plan
```

## Level D — System Rule Change
Ví dụ:
```text
PASS definition
AI integrity
evidence schema
source authority
state semantics
```

Required System Spec amendment format:
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

---
# 12. IMPACT ANALYSIS TEMPLATE

```text
# IMPACT ANALYSIS

Change ID:
Date:
Requested by:

## Problem
Observed:
Expected:
Why roadmap/system issue rather than learner gap:

## Evidence
Days/weeks:
Gate evidence:
Schedule data:
Technical source:
Career evidence:
Health/load:

## Proposed minimum change

## Files affected
[ ] SYSTEM_SPEC_V3.md
[ ] EMBEDDED_ROADMAP_V3.1.docx
[ ] MASTER_PROMPT_V3.md
[ ] HOW_TO_USE_ROADMAP_WITH_AI.docx
[ ] roadmap-control/current-state.md
[ ] competency-ledger.md
[ ] daily-log.md
[ ] weekly scorecard
[ ] project docs
[ ] tests/evidence
[ ] ROADMAP_REVIEW_LOG.md

## Competency impact
Added:
Removed:
Changed:
Existing PASS invalidated?:
Fresh retest required?:

## Gate impact
Gate IDs:
Mandatory items changed?:
Historical gate results still valid?:

## Calendar impact
Days added:
Days removed:
Milestones affected:
v1.0 risk:
Roadmap-close risk:

## Scope trade-off
Added:
Cut/reduced:
Why value > cost:

## Migration
Existing files/evidence affected:
State update:
Backfill:
Historical evidence must remain truthful:

## Rollback

## Decision
CONTINUE BASELINE / APPROVE / REJECT / DEFER

Owner approval:
Date:
```

---

# 13. ROADMAP CHANGE REQUEST TEMPLATE

```text
# ROADMAP CHANGE REQUEST — RR-XXX

Status:
Severity:
Opened:
Target checkpoint:

## Concern
## Why it matters
## Current behavior
## Evidence
## Hypothesis

## Alternatives
A — no change
B — operational adjustment
C — roadmap revision

## Recommended minimum change
## Cost
## Benefit
## Critical-path impact
## Competency impact
## Files affected
## Decision
## Verification after change
## Closure
```

---
# 14. FORMAL REVIEW PROCEDURE

Default timebox:
```text
30–60 minutes
```

Max:
```text
90 minutes
```
trừ R3/R4.

Procedure:
1. Mở checkpoint section.
2. Đọc `CURRENT_STATE`.
3. Đọc relevant weekly scorecard.
4. Đọc competency ledger.
5. Đọc AI usage liên quan.
6. Xem actual hours / GREEN-YELLOW-RED / carry-over.
7. Xem gate evidence.
8. Xem item `WATCH/OBSERVING`.
9. Quyết định: observe / close / confirm defect / proposal.
10. Chỉ impact-analyze confirmed defect.
11. Chỉ sửa minimum necessary scope.
12. Ghi next review checkpoint.
13. Quay lại execution.

Stop condition:

> Có decision cho active items; không tiếp tục brainstorm “còn thiếu gì nữa”.

---

# 15. DECISION RULES

## CONTINUE V3.1
Default khi:
- gates hợp lý;
- workload trong recovery capacity;
- concern chưa đủ evidence;
- không có critical prerequisite defect;
- không có system contradiction.

## OPERATIONAL ADJUSTMENT
Khi issue là timebox/example/tool/detail và core/gate không đổi.

## RECOVERY
Khi learner chưa đạt competency hoặc schedule lag nhưng system vẫn đúng.

## ROADMAP REVISION PROPOSAL
Chỉ khi:
- defect đã evidence-confirmed;
- recovery/operational adjustment không giải quyết được;
- minimum change rõ;
- deadline/trade-off rõ.

## SYSTEM AMENDMENT
Chỉ cho real operating-system defect.

---
# 16. INITIAL REVIEW BACKLOG — 09/08/2026

**Các item dưới đây là hypothesis/watch item, KHÔNG phải defect đã xác nhận.**

## RR-001 — Workload realism
Status: `OBSERVING`
Severity: `R2`
First review: `CP-01`

Collect:
```text
planned vs actual hours
days >8h
any day >9h
sleep/load
daily status
carry-over
quality near end of day
```

If repeated hard-limit pressure → confirm load/scope review.

## RR-002 — Evidence/bookkeeping overhead
Status: `CLOSED`
Severity: `R1`
First review: `CP-01`

Confirmed: `2026-08-11` from W01D01 operational evidence.
Closed: `2026-08-11`

Evidence:
```text
W01D01 closure required repeated commit/log/state/provenance correction cycles.
The late provenance correction caused additional bookkeeping commits after the technical artifact already passed 46/46 tests.
This consumed learning time without changing artifact behavior or competency status.
```

Owner decision:
```text
APPROVED — apply the minimum operational workflow fix now.
Do not rewrite frozen SYSTEM_SPEC, ROADMAP, or MASTER_PROMPT.
```

Minimum change:
```text
Add roadmap-control/operating-rules.md.
Consolidate END DAY bookkeeping and provenance before one closure commit.
Default to at most two commits/day and one pre-commit audit.
Keep evidence/competency requirements intact.
Keep the current daily-log schema unchanged.
DEFER per-day log files to CP-01 if friction repeats.
```

Fix:
```text
roadmap-control/operating-rules.md
```

Relevant commits:
```text
f0a1f15998830ef5b19ed68cf20f5b8fd1b6a980
docs(workflow): simplify daily close and commit flow

f973b9ae5b0d0f0b4004b77767ca6ce0019e46f7
docs(system): make BOOT discover active operating rules
```

Verification summary:
```text
- operating-rules.md ACTIVE
- Master Prompt 3.0.3 discovers active operational layer during BOOT
- Current State uses Exact Next Action = BOOT
- repository synchronized after previous push
- workflow now defers bookkeeping to END DAY atomic closure
```

Residual:
```text
Per-day daily-log split remains DEFERRED to CP-01 only if operational friction repeats.
```

Collect:
```text
minutes/day on logs
duplicate information
whether evidence helped review/debug/gate
manual maintenance burden
```

Preferred fix if too heavy:
```text
automate bookkeeping
reduce duplication
do not weaken competency evidence
```

## RR-003 — AI tutoring workflow effectiveness
Status: `OBSERVING`
Severity: `R2`
First review: `CP-01`

Collect:
```text
AI level distribution
why AI-4 happened
retest frequency
self-explanation
gate results
```

Interpret carefully:
- AI-4 because task jump too large → learning-design issue.
- AI-4 because learner skipped attempt → execution issue.
- AI-4 because prerequisite absent → sequencing issue.

## RR-004 — Consolidated survival/core checklist
Status: `HYPOTHESIS`
Severity: `R1/R2`
Target: `CP-02`

Question:
Có cần learner-facing consolidated map cho:
```text
C / MCU / RTOS / protocol / testing-debug / project defense / career
```
hay competency ledger + gates đã đủ?

Preferred answer if useful:
> create a derived checklist; do not change curriculum unless competency thật sự thiếu.

## RR-005 — Industry reality / legacy-code simulation
Status: `HYPOTHESIS`
Severity: `R2`
Target: `CP-02 → CP-04`

Potential bounded exercises:
```text
read existing code
find defect
fix small ticket
review diff
explain maintenance trade-off
```

Không thêm nếu phải cắt P0.

## RR-006 — Project spec granularity
Status: `HYPOTHESIS`
Severity: `R2`
Target: `CP-03`

If project needs more detail:
```text
requirements
architecture
interfaces
ownership
failure behavior
test matrix
limitations
```

Preferred response:
> create project-local spec before editing roadmap.

## RR-007 — Mock internship/work-ticket simulation
Status: `DEFERRED`
Severity: `R1/R2`
Target: `CP-06`

Roadmap cuối đã có live coding, mocks, project defense, walkthrough.
Chỉ thêm bounded ticket simulation nếu actual evidence cho thấy còn gap:

```text
receive bug
reproduce
measure
fix
test
review
demo/explain
```

## RR-008 — Recovery/buffer sufficiency
Status: `WATCH`
Severity: `R2`
Target: every checkpoint

Current system đã có:
```text
schedule variance
P0/P1/P2 cuts
targeted recovery
~7-day reassessment
no all-nighter
```

Không thêm “buffer week” nếu chưa có evidence.

## RR-009 — Hardware/toolchain dependency
Status: `CLOSED`
Severity: `R2`
Target: `CP-00`
Closed: `2026-08-09 — CP-00 PASS / CONTINUE`
Evidence: `evidence/sprint-00/cp-00-review.md`, `evidence/sprint-00/preflight-summary.md`, `roadmap-control/preflight.md`, `roadmap-control/inventory.md`, `roadmap-control/tool-versions.md`.

Sprint 0 resolved:
```text
STM32
ESP32
host test
UART/measurement
ARM GCC
CMake
inventory/fallback
```

Closure:
No P0 hardware/toolchain blocker remains for Week 1 entry. Functional status not tested for optional/deferred hardware remains explicitly unclaimed.

## RR-010 — Career timing realism
Status: `DEFERRED`
Severity: `R2`
Target: `CP-03+`

Dùng actual:
```text
tracker
CV readiness
JD signals
applications
response rate
interview gaps
```

Chỉ đổi timing bằng pipeline evidence.

## RR-011 — Pre-check diagnostic misclassified as daily PASS criterion
Status: `CLOSED`
Severity: `R2`
Opened: `2026-08-12`
Closed: `2026-08-12`
Target: `EARLY REVIEW — COMPLETED`

### Concern

A generated W01D03 TODO promoted a pre-learning baseline diagnostic into a
learner-scored `MUST`, and END DAY later used its incomplete checkbox to assign
`YELLOW`.

### Observed

- The learner disclosed no prior struct alignment/padding/endian knowledge.
- The mentor switched from the generated pre-check flow to theory-first teaching.
- The originally generated pre-check was not completed in its original sequence.
- W01D03 later completed the authoritative implementation, measurement,
  strict-build, host-test, evidence, expected/actual and end-of-day
  self-explanation criteria.
- END DAY nevertheless treated the generated diagnostic checkbox as a remaining
  learner-required item and assigned `YELLOW`.

### Expected

- A pre-check on new material is baseline data; `UNKNOWN`, "I don't know", an
  uncertainty, or a labeled prediction is valid unless a higher-authority
  source explicitly defines a scored diagnostic.
- Daily status follows `SYSTEM_SPEC_V3` plus the roadmap/day card, not a new PASS
  definition introduced by a generated checklist.
- Mentor/system diagnostic-flow failure is attributed to the workflow, not the
  learner.

### Root cause

- The generated day-pack requirement exceeded its authority.
- The mentor/system mishandled diagnostic sequencing after discovering the
  missing prerequisite baseline.
- END DAY trusted generated `MUST` state without tracing it to higher-authority
  criteria.

### Impact

- Inaccurate learner-performance signal and misleading W01D03 `YELLOW`.
- Recurrence risk across future day packs and cross-chat/BOOT sessions.
- No technical artifact, competency, schedule, or recovery impact.

### Decision and minimum correction

`APPROVED / CLOSED` — Level A operational clarification and historical status
correction; no frozen-source amendment and no curriculum/gate change.

- Add active baseline-diagnostic semantics and generated-pack authority guard.
- Add the Project chat <-> Cowork manual handoff workflow.
- Correct stale W01D03 records while preserving the interrupted chronology as
  `MENTOR/SYSTEM WORKFLOW VARIANCE — NON-SCORING`.
- Correct W01D03 daily status from `YELLOW` to `GREEN` because every
  authoritative daily criterion was complete.

### Preserved semantics

```text
Artifact impact:   NONE — W01D03 remains ARTIFACT_PASS
Competency impact: NONE — W01-C-FOUND remains COMPETENCY_UNVERIFIED
AI impact:         NONE — highest level remains AI-4
Gate impact:       NONE — fresh Week 1 AI-0 gate remains required
Schedule impact:   NONE — variance remains 0
Recovery impact:   NONE — NOT ACTIVE
Execution impact:  NONE — W01D04 remains NEXT
```

### Verification after change

- `roadmap-control/operating-rules.md` is already declared as the active
  operational layer in Current State and is mandatory BOOT input under Master
  Prompt 3.0.3.
- Future BOOT therefore inherits the diagnostic and Cowork rules.
- Repository-wide search and staged-diff audit must show no active claim that
  W01D03 is `YELLOW` because the learner failed unknown pre-learning material.
- W01D03 strict build, 25/25 host tests and measurement helper must still pass.

## RR-012 — END DAY closure misses mandatory human-only fields
Status: `CLOSED`
Severity: `R1`
Opened: `2026-08-12`
Closed: `2026-08-12`
Target: `EARLY OPERATIONAL REVIEW — COMPLETED`

### Concern

END DAY could reach committed closure while a required daily-log field remained
unknown because repository tooling could not derive the value.

### Evidence

- W01D02 closed without an actual focused-time value and required the later
  corrective bookkeeping commit `c869932` (`docs(control): correct W01D02
  focused time`).
- W01D03 again closed with `Actual: Không được ghi nhận` even though the fixed
  daily-log schema requires an `Actual` field and the learner could later supply
  an explicitly labeled estimate.
- This is repeated execution evidence across two consecutive days, not two
  unrelated wording errors.

### Expected

Before END DAY bookkeeping and commit, the active execution environment must
identify every mandatory field that cannot be reliably derived from repository
or tool state. If a required human-only value is missing, ask the learner only
for that missing information before closure.

### Root cause

END DAY had repository consistency checks but no mandatory human-input
preflight. The workflow said the learner supplies information the execution
environment cannot read, but did not require the environment to enumerate and
resolve missing human-only fields before commit.

### Impact

- repeated corrective commits;
- incomplete daily execution and workload data;
- weaker CP-01 planned-versus-actual and health/load analysis;
- avoidable bookkeeping churn;
- risk of silently recording an unknown value when learner input could resolve it.

There is no technical artifact, competency, AI-integrity, schedule, or recovery
impact.

### Decision and minimum correction

`APPROVED / CLOSED` — confirmed workflow defect; Level A operational adjustment,
severity `R1`. This is not an `R4` System Spec defect because PASS semantics, AI
integrity, evidence authority, gates, and state semantics remain consistent.

- Add a lightweight END DAY Human-Input Gate to the active operating rules.
- Integrate the gate before evidence/log/state edits and before the closure commit.
- Repair W01D03 Actual Focused Time with the learner-supplied estimate
  `~6h — learner estimate`.
- Do not modify frozen System Spec, Roadmap, or Master Prompt.

### Preserved semantics

```text
Daily impact:       NONE — W01D03 remains GREEN
Artifact impact:    NONE — W01D03 remains ARTIFACT_PASS
Competency impact:  NONE — W01-C-FOUND remains COMPETENCY_UNVERIFIED
AI impact:          NONE — highest level remains AI-4
Gate impact:        NONE — fresh Week 1 AI-0 gate remains required
Schedule impact:    NONE — variance remains 0
Recovery impact:    NONE — NOT ACTIVE
Execution impact:   NONE — W01D04 remains NEXT
```

### Verification after change

- `roadmap-control/operating-rules.md` requires the human-input preflight before
  the final END DAY commit and preserves the atomic closure, verification,
  diagnostic, and Cowork handoff rules.
- `roadmap-control/daily-log.md` and `roadmap-control/current-state.md` record
  W01D03 focused time as `~6h — learner estimate` without inferred precision.
- No technical source, test, artifact result, AI provenance, competency, gate,
  schedule, or recovery record is changed.

## RR-013 — Defect fixes lack mandatory retrospective scope verification
Status: `CLOSED`
Severity: `R1`
Opened: `2026-08-12`
Closed: `2026-08-12`
Target: `EARLY OPERATIONAL REVIEW — COMPLETED`

### Concern

The active workflow corrected a confirmed defect at the point where it was
noticed but did not explicitly require a bounded audit of prior `CLOSED` records
that could have been affected by the same defect class. This is a system-design
risk; it is not a claim that an undiscovered historical defect definitely exists.

### Evidence

- RR-011 corrected generated baseline-diagnostic semantics after W01D03 was
  misclassified.
- RR-012 confirmed that missing END DAY human-only focused-time data had occurred
  on both W01D02 and W01D03.
- These events demonstrate that a workflow defect class can span days. A fix that
  checks only the discovered occurrence can leave same-class historical records
  stale.

### Expected

Every confirmed workflow/system/control defect must define the defect class,
identify the reasonable historical scope that could have been affected, classify
every item in that scope, safely fix recoverable hits, preserve and explain
unrecoverable history, and record the results before the review item is closed.

### Root cause / system gap

The review flow required impact analysis and verification, but the active
operational layer did not make retrospective scope selection, per-item
classification, and completion-before-closure explicit. CP-01 also lacked a
bounded cross-day control-consistency sweep, and END DAY had no machine helper
for simple structural contradictions.

### Impact

- stale same-class historical inconsistencies could survive indefinitely;
- checkpoint inputs could contain hidden control defects;
- learner/reviewer could mistake a latest-day repair for repository-wide
  consistency.

There is no technical artifact or competency impact by itself.

### Decision and operational changes

`APPROVED / CLOSED` — confirmed operational/system hardening gap, severity `R1`.
This is a Level A operational adjustment, not an `R4` System Spec defect.

- Added `Confirmed Defect -> Retroactive Impact Sweep` to the active operating
  rules, including precise defect class, bounded scope, per-item classification,
  safe correction, unrecoverable-history handling, and closure gating.
- Added the bounded `CP-01 Week Consistency Sweep` for all Week 1 `CLOSED` days.
- Added read-only standard-library linter `tools/roadmap/closure_lint.py` and
  integrated it before the final END DAY commit without replacing human review.
- Did not modify the frozen System Spec, Roadmap, Master Prompt, daily-log schema,
  technical implementation, tests, AI provenance, or competency rules.

### Initial retrospective scope and results

Scope: `W01D01-W01D03` — every Week 1 day currently `CLOSED`.

Checked dimensions: daily status / planned and actual focused time / artifact /
required evidence / AI provenance / competency boundary / carry-over / next
action and closed-state progression / mandatory placeholders / Current State
alignment / RR-011 and RR-012 correction alignment.

| Invariant | W01D01 | W01D02 | W01D03 |
|---|---|---|---|
| Daily status | PASS | PASS | PASS |
| Planned focused time | PASS | PASS | PASS |
| Actual focused time | PASS | PASS | PASS |
| Artifact result | PASS | PASS | PASS |
| Required evidence present | PASS | PASS | PASS |
| AI provenance present/consistent | PASS | PASS | PASS |
| Competency claim within evidence | PASS | PASS | PASS |
| Carry-over explicit | PASS | PASS | PASS |
| Next action / closed-state progression | PASS | PASS | PASS |
| No unexplained mandatory placeholder | PASS | PASS | PASS |
| Current State alignment | PASS | PASS | PASS |
| RR-011 / RR-012 correction alignment | PASS | PASS | PASS |

Defect-specific historical results:

- RR-011 class — generated diagnostic misclassified as scored `MUST`:
  `W01D01 NOT APPLICABLE`; `W01D02 NOT APPLICABLE`; `W01D03 AFFECTED — FIXED`
  by the prior RR-011 correction.
- RR-012 class — `CLOSED` day missing Actual Focused Time:
  `W01D01 PASS`; `W01D02 AFFECTED — FIXED` by commit `c869932`;
  `W01D03 AFFECTED — FIXED` by commit `986f15a`.
- Additional same-scope recoverable inconsistencies found: `NONE`.

This bounded result means only that W01D01-W01D03 passed the defined closure
invariant matrix. It does not prove that no other unknown defect exists.

### Verification

- Real repository linter: `0 FAIL`, `0 WARN`, `20 PASS`; exit code `0`.
- Negative temporary fixture with blank W01D03 `Actual` focused time:
  `1 FAIL`, `0 WARN`, `19 PASS`; exit code `1`.
- False-positive review: legitimate hardware `NOT_TESTED/UNKNOWN` and historical
  review prose are outside the mandatory parsed fields and were not flagged.
- Human audit found no technical/competency issue requiring a separate review and
  no historical value requiring invention.

### Preserved semantics

```text
Daily impact:       NONE — W01D03 remains GREEN
Artifact impact:    NONE — W01D03 remains ARTIFACT_PASS
AI impact:          NONE — W01D03 remains AI-4
Competency impact:  NONE — W01-C-FOUND remains COMPETENCY_UNVERIFIED
Gate impact:        NONE — fresh Week 1 AI-0 gate remains required
Schedule impact:    NONE — variance remains 0
Recovery impact:    NONE — NOT ACTIVE
Execution impact:   NONE — W01D04 remains NEXT
Next action impact: NONE — Exact Next Action remains BOOT
```

## RR-014 — No proactive END DAY readiness / unclosed-session recovery contract
Status: `CLOSED`
Severity: `R1`
Opened: `2026-08-12`
Closed: `2026-08-12`
Target: `EARLY OPERATIONAL REVIEW — COMPLETED`

### Concern

The learner had to remember to trigger `END DAY` even after all authoritative
day criteria were satisfied. If a learning session ended without `END DAY`,
`BOOT` had no explicit recovery contract preventing silent advancement.

### Evidence and authority validation

- `SYSTEM_SPEC_V3` requires every day to have a stop condition and defines daily
  status, but does not assign the learner responsibility for detecting the
  threshold.
- Approved Roadmap V3.1 day cards define authoritative `Điểm dừng` criteria.
- `MASTER_PROMPT_V3` defines `END DAY` as an explicit command and specifies the
  audit performed after that command. It does not forbid a proactive readiness
  notification and it does not make readiness automatic closure.
- The active operating rules defined `BOOT`, the Focus Phase, the atomic END DAY
  transaction, Human-Input Gate, Closure Linter, commit/push, diagnostic/generated
  pack authority, and Project Chat <-> Cowork handoff. They did not assign
  readiness detection to the mentor/execution system or define an interrupted
  prior-session transition at `BOOT`.

### Expected

- The mentor/execution system owns proactive readiness detection from
  higher-authority daily criteria.
- The learner owns explicit `END DAY` confirmation.
- Only then does the normal END DAY closure transaction run.
- Before advancing, `BOOT` resolves credible evidence of any unclosed prior
  execution using available context first and minimum human input only when
  genuinely ambiguous.

### Root cause

The workflow specified END DAY execution but not readiness ownership or
interrupted-session transition semantics.

### Impact

- the learner had to manually decide the closure threshold;
- completed work could remain unclosed;
- the next `BOOT` could become ambiguous;
- closure/bookkeeping could be delayed;
- execution position could become unclear.

There is no automatic technical artifact or competency impact.

### Decision and operational changes

`APPROVED / CLOSED` — confirmed workflow defect; Level A operational adjustment,
severity `R1`. This does not require or authorize a frozen-source change.

- Added proactive `END DAY READY`: the mentor tracks the System Spec, approved
  Roadmap/day card and explicit gate contract, announces readiness, separates
  optional/bonus work, stops adding normal required work, and requests learner
  confirmation.
- Preserved explicit `END DAY`: readiness alone does not update closure
  bookkeeping, commit or push; learner confirmation starts the existing atomic
  transaction and Human-Input Gate.
- Preserved early learner-requested `END DAY`: the actual outcome is audited and
  classified honestly without forcing continued study.
- Added BOOT recovery classifications for prior-session in-progress, ready but
  unclosed, stopped before readiness, and genuinely ambiguous states.
- Required available context/tools first, one minimum human-only question only
  when needed, and local execution/Cowork only when repository inspection is
  actually necessary. Remote-`main` cleanliness alone is not proof of clean
  local closure.
- Did not change the Closure Linter because readiness is semantic and day-card
  dependent; a regex check would not be a robust structural invariant.

### Workflow state machine

```text
ACTIVE
  -> authoritative required criteria satisfied -> END_DAY_READY
  -> learner confirms END DAY -> CLOSURE_IN_PROGRESS
  -> Human-Input Gate + evidence/log/state + linter + human audit -> CLOSED

ACTIVE
  -> learner requests END DAY early -> CLOSURE_IN_PROGRESS
  -> classify actual outcome honestly -> CLOSED / carry-over as applicable
```

These are workflow concepts only and create no competency state.

### Retroactive impact sweep

Defect class: `Daily workflow lacks proactive END DAY readiness ownership and
explicit unclosed-session BOOT recovery.`

Scope: `W01D01-W01D03` — every Week 1 day currently `CLOSED`.

- `W01D01 — PASS — NO RECOVERABLE CONTROL INCONSISTENCY FOUND.` The daily log
  records `GREEN`, completed closure fields, explicit progression to W01D02 and
  `Next Action: BOOT`; repository history contains closure bookkeeping. The
  repository cannot prove whether the learner had to ask when the day was done,
  so no conversation chronology is invented.
- `W01D02 — PASS — NO RECOVERABLE CONTROL INCONSISTENCY FOUND.` The daily log
  records `GREEN`, completed closure fields, no artifact carry-over, explicit
  progression to W01D03 and `Next Action: BOOT`; later focused-time correction
  belongs to RR-012, not this defect class. No unclosed-session advancement is
  evidenced.
- `W01D03 — PASS — NO RECOVERABLE CONTROL INCONSISTENCY FOUND.` The corrected
  authoritative result is `GREEN`, closure fields are complete, W01D04 is
  explicitly `NEXT`, and `Next Action: BOOT`; the diagnostic correction belongs
  to RR-011, not this defect class. No unclosed-session advancement is evidenced.
- Current same-class inconsistency found/fixed: `NONE`. Correctly closed days
  remain closed; no historical chronology, status, artifact, AI provenance,
  competency, schedule, recovery or execution position was rewritten.

### Verification and preserved semantics

- Real repository linter before change: `0 FAIL`, `0 WARN`, `20 PASS`; exit code
  `0`. The linter is unchanged and remains part of the existing closure flow.
- Human audit found no technical/competency issue and no historical fact that
  could be safely reconstructed beyond repository evidence.

```text
Daily impact:       NONE — W01D03 remains GREEN
Artifact impact:    NONE — W01D03 remains ARTIFACT_PASS; 25/25 PASS
AI impact:          NONE — W01D03 remains AI-4
Competency impact:  NONE — W01-C-FOUND remains COMPETENCY_UNVERIFIED
Gate impact:        NONE — fresh Week 1 AI-0 gate remains required
Schedule impact:    NONE — variance remains 0
Recovery impact:    NONE — NOT ACTIVE
Execution impact:   NONE — W01D04 remains NEXT
Next action impact: NONE — Exact Next Action remains BOOT
```

---
# 17. BASELINE REVIEW — PRE-EXECUTION

**Review ID:** `RV-000`
**Date:** `2026-08-09`
**Stage:** `Pre-Sprint-0`
**Evidence:** document/system audit only; chưa có V3 execution data.

## Strengths đã có trong baseline
```text
source hierarchy
artifact vs competency separation
AI integrity levels
evidence model
daily/weekly operating system
targeted recovery
scope control
hard deadlines
health/load limits
week/day outcomes
project milestones
fault injection/testing ladder
career/interview phases
```

## Chưa thể chứng minh trước execution
```text
45–50h có sustainable không
day packs heavy/light ra sao
AI-1/AI-2 calibration
evidence friction
project spec granularity
industry-maintenance simulation need
recovery sufficiency
```

## Structural defect proven?
```text
NO
```

## Decision
```text
CONTINUE EMBEDDED_ROADMAP_V3.1
```

## Next formal review
```text
CP-00 — Sprint 0 Exit — before transition to Week 1
```

After CP-00 completes successfully:

```text
CP-01 — End of Week 1 — 16/08/2026
```

Exception: review sớm nếu R3/R4.

---

## RV-001 — CP-00 Sprint 0 Exit

Date: `2026-08-09`
Calendar Position: `Sprint 0 exit`
Execution Position: `Sprint 0 operational validation complete`
Roadmap version: `EMBEDDED_ROADMAP_V3.1`
Relevant commit: `e06d98b` — Sprint 0 transition state closed before this review-log update.

### Inputs
Current State: `SPRINT-0 CLOSED`; CP-00 operational result `CONTINUE`.
Weekly scorecard: `N/A` — Sprint 0 bootstrap, not Week 1 weekly learning review.
Gate: `CP-00`; detailed checklist in `evidence/sprint-00/cp-00-review.md`.
AI usage: Sprint 0 setup/bookkeeping assistance logged in `roadmap-control/ai-usage-log.md`; no competency PASS created.
Schedule variance: no calendar slip observed; Week 1 start remains `2026-08-10`.
Health/load: actual focused hours not reliably recorded for Sprint 0; no structural workload conclusion from this checkpoint.
Career data: `N/A`.
Other evidence: `roadmap-control/preflight.md`, `roadmap-control/inventory.md`, `roadmap-control/tool-versions.md`, `evidence/sprint-00/preflight-summary.md`, visual captures under `evidence/sprint-00/captures/`.

### Active review items
RR-009: `CLOSED` — required hardware/toolchain paths verified or explicitly bounded/deferred.
RR-002: `OBSERVING` at this historical CP-00 snapshot — Sprint 0 closure produced noticeable bookkeeping friction; one bootstrap day was not enough to confirm a system defect. Superseded by RR-002 `CLOSED` on `2026-08-11` after W01D01 evidence and workflow verification.
RR-008: remains `WATCH` — no new evidence requiring schedule/recovery change.

### Findings
Curriculum Coverage:      UNKNOWN
Sequencing/Prerequisite:  OK
Workload:                 UNKNOWN
Learning Depth:           UNKNOWN
AI Workflow:              OK
Evidence Overhead:        WATCH
Industry Relevance:       UNKNOWN
Project Value:            UNKNOWN
Career Fit:               UNKNOWN
Health/Sustainability:    UNKNOWN

### Defects confirmed
NONE.

### Operational adjustments
- Consolidate bookkeeping updates instead of repeated micro-edits.
- Preserve evidence integrity while minimizing duplicate manual maintenance.
- Do not add repository-management work unless a real execution need appears.

### Change requests opened
NONE.

### Decision
`CONTINUE V3.1`

No Sprint 0 recovery and no roadmap/system revision are justified.

### Files affected
- `docs/system/ROADMAP_REVIEW_LOG.md`
- Sprint 0 closure already reflected in live state/evidence files.

### Next formal review
`CP-01 — End of Week 1 — 16/08/2026`, when execution actually reaches Week 1 close.

### Exact next action
On `2026-08-10`, start `WEEK 1 DAY 1 — Embedded C Foundation` with fresh independent C validation under the V3 AI-integrity rules.

---
# 18. REVIEW ENTRY TEMPLATE

```text
## RV-XXX — <checkpoint/event>

Date:
Calendar Position:
Execution Position:
Roadmap version:
Relevant commit:

### Inputs
Current State:
Weekly scorecard:
Gate:
AI usage:
Schedule variance:
Health/load:
Career data:
Other evidence:

### Active review items
RR-XXX:
RR-XXX:

### Findings
Curriculum Coverage:      OK/WATCH/DEFECT/UNKNOWN
Sequencing/Prerequisite:  OK/WATCH/DEFECT/UNKNOWN
Workload:                 OK/WATCH/DEFECT/UNKNOWN
Learning Depth:           OK/WATCH/DEFECT/UNKNOWN
AI Workflow:              OK/WATCH/DEFECT/UNKNOWN
Evidence Overhead:        OK/WATCH/DEFECT/UNKNOWN
Industry Relevance:       OK/WATCH/DEFECT/UNKNOWN
Project Value:            OK/WATCH/DEFECT/UNKNOWN
Career Fit:               OK/WATCH/DEFECT/UNKNOWN
Health/Sustainability:    OK/WATCH/DEFECT/UNKNOWN

### Defects confirmed
### Operational adjustments
### Change requests opened

### Decision
CONTINUE V3.1
OPERATIONAL ADJUSTMENT
RECOVERY
ROADMAP REVISION PROPOSAL
SYSTEM AMENDMENT PROPOSAL

### Files affected
### Next formal review
### Exact next action
```

---
# 19. HOW TO USE THIS FILE

## Normal day
**Không mở file này.**

Dùng:
```text
BOOT
START DAY
SUBMIT TODO
END DAY
```

Review log không được ăn thời gian học.

## Non-checkpoint weekly review
Dùng `WEEKLY REVIEW` bình thường.
Chỉ thêm review item nếu concern lặp lại và có khả năng structural.

## Formal checkpoint
Nói với assistant:

```text
RÀ SOÁT ROADMAP THEO ROADMAP_REVIEW_LOG.md
Checkpoint: CP-XX
```

Assistant đọc:
```text
SYSTEM_SPEC_V3
EMBEDDED_ROADMAP_V3.1
MASTER_PROMPT_V3
ROADMAP_REVIEW_LOG
live CURRENT_STATE
competency ledger
AI usage
relevant scorecard
relevant evidence
```

Sau đó append một `RV-XXX`.

## Khi lo roadmap thiếu gì đó
Không sửa roadmap ngay.

Mở:
```text
RR-XXX
Status: HYPOTHESIS
Concern:
Why it matters:
Evidence needed:
Target checkpoint:
```

Rồi quay lại execution.

## Khi có R3/R4 thật
Nói:
```text
ROADMAP REVIEW — URGENT

Concern:
Observed:
Expected:
Evidence:
Critical path impact:
```

Sau đó impact analysis trước mọi governing-source change.

---
# 20. FILE LOCATION / CHATGPT PROJECT RULE

Recommended repo path:

```text
docs/system/ROADMAP_REVIEW_LOG.md
```

## Có cần upload file này vào ChatGPT Project không?

```text
NO — mặc định không.
```

Lý do:
- đây là live/dynamic log;
- nó thay đổi theo checkpoint;
- upload vào Project dễ tạo stale copy.

Architecture:

```text
ChatGPT Project — static
SYSTEM_SPEC_V3.md
EMBEDDED_ROADMAP_V3.1.docx
MASTER_PROMPT_V3.md

GitHub — live
roadmap-control/*
docs/system/ROADMAP_REVIEW_LOG.md
code/tests/evidence
```

Khi review:
> assistant đọc latest version từ GitHub.

Exception:
Nếu chuyển account/environment không đọc được GitHub, đưa latest review log vào HANDOFF package.

`HOW_TO_USE_ROADMAP_WITH_AI.docx` không cần sửa ngay chỉ để nhắc file này. Review log cố ý được dùng hiếm.

---

# 21. COMMIT POLICY

Initial commit:

```text
docs(system): add evidence-based roadmap review log
```

Later examples:

```text
docs(review): record Week 1 roadmap review
docs(review): open workload realism concern
docs(review): close Sprint 0 dependency review
```

Nếu revision roadmap được approve:
1. commit review/impact analysis;
2. update roadmap + affected source;
3. update current state;
4. verify consistency;
5. commit revision riêng.

Không trộn roadmap rewrite với unrelated code changes.

---

# 22. ANTI-PROCRASTINATION RULE

Nếu không có R3/R4 và chưa tới formal checkpoint:

```text
ROADMAP_REVIEW_LOG MUST NOT BLOCK LEARNING.
```

Ordinary maintenance tối đa:

```text
capture concern <= 5 minutes
then return to NEXT ACTION
```

Không dành hàng giờ chỉnh:
- review wording;
- taxonomy;
- template;
- aesthetics.

---

# 23. OWNER DECISION CONTRACT

Chỉ owner mới chuyển:

```text
PROPOSAL_READY → APPROVED
```

AI được:
```text
analyze
recommend
draft
impact-map
challenge assumptions
```

AI không được silently redefine roadmap.

---

# 23.1 VERSION NOTE — 1.0.1

```text
Change:
Synchronize execution authority with MASTER_PROMPT_V3 3.0.2 and pin canonical live repo.

Behavior impact:
NONE to review checkpoints, severity, change-control or roadmap semantics.
```

# 23.2 VERSION NOTE — 1.0.2

```text
Change:
Synchronize execution authority with MASTER_PROMPT_V3 3.0.3 active operational layer discovery clarification.

Behavior impact:
NONE to review checkpoints, severity, change-control or roadmap semantics.
```

# 23.3 VERSION NOTE — 1.0.3

```text
Change:
Close RR-002 after the approved operating-rules workflow fix and BOOT discovery verification.

Behavior impact:
NONE to roadmap curriculum, gates, competency, PASS, AI-integrity or evidence semantics.
```

# 23.4 VERSION NOTE — 1.0.4

```text
Change:
Close RR-013 after adding the confirmed-defect retrospective sweep, bounded
CP-01 Week Consistency Sweep, read-only closure linter, and initial W01D01-W01D03
verification.

Behavior impact:
Operational review/closure hardening only. NONE to curriculum, gates,
competency, PASS, AI-integrity or evidence semantics.
```

# 23.5 VERSION NOTE — 1.0.5

```text
Change:
Close RR-014 after adding mentor-owned proactive END DAY readiness, learner-owned
END DAY confirmation, unclosed-session BOOT recovery, and the bounded
W01D01-W01D03 retrospective impact sweep.

Behavior impact:
Operational workflow correction only. NONE to curriculum, gates, competency,
PASS, AI-integrity, evidence, schedule or recovery semantics.
```

---

# 24. FINAL RULE

File này chỉ thành công nếu roadmap vừa:

```text
stable enough to execute
+
adaptable enough to fix real defects
```

Default giữa các checkpoint:

> **Execute V3.1. Collect evidence. Change only the minimum necessary when a real defect is demonstrated.**

**Current decision:** `CONTINUE EMBEDDED_ROADMAP_V3.1`
**Last completed formal review:** `RV-001 — CP-00 Sprint 0 Exit — 09/08/2026`
**Next formal review:** `CP-01 — End of Week 1 — 16/08/2026`
**Early exception:** `R3/R4 structural/system defect`
