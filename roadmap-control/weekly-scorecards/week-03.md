# WEEK 03 SCORECARD — UART IRQ / RING BUFFER / PARSER

Week: `Week 3 — UART polling/IRQ, SPSC ring buffer, bounded parser, logger, and fault diagnosis`

Roadmap dates: `2026-08-24 through 2026-08-30`

Closure date: `2026-08-31`

Relevant commit: `SELF — containing commit`

## Scores

| Dimension | Score | Basis |
| --- | ---: | --- |
| Output | 2/2 | W03D01–W03D06 artifacts are `ARTIFACT_PASS`; W03D07 raw, assessment, review, submission, and weekly disposition are retained. |
| Understanding | 2/2 | Independent W03D07 AI-0 gate scored `87/100 PASS`; baud/clock, ISR constraints, SPSC ownership, parser behavior, overflow policy, diagnosis, and trade-offs were assessed. |
| Testing | 2/2 | Fresh closure rerun: ring buffer `11/11`, parser `16/16`, serial logger help exit `0`, and W03D06 STM32 clean build exit `0` at `1720/0/1592/3312/cf0`; physical UART/IRQ/overflow/logger evidence remains retained. |
| Documentation | 1/2 | Required submissions, gate evidence, logs, ledger, state, scorecard, and debug story are present. Direct correct-baud wire-timing evidence remains the single P1 carry-over. |
| Health | 2/2 | Learner supplied `2 — sustainable` and `sức khoẻ rất ổn`; no health gate blocks closure. |
| Career | 0/2 | No Week 3 application checklist, application, outreach, mock, follow-up, or new career artifact is evidenced. No value is fabricated and this is not a second carry-over. |

## Weekly decision

- **Weekly Decision:** `CONDITIONAL PASS / CLOSED`
- **W03-C-UART-FOUND:** `COMPETENCY_PASS`
- **W03D07 gate:** `87/100 PASS / AI-0 CLEAN`
- **Carry-over:** `Capture correct-baud UART wire timing / logic-analyzer evidence`
- **Carry-over deadline:** `2026-09-06 — CP-02 / Foundation MCU gate`
- **Closure criterion:** `Genuine logic-analyzer capture or equivalent direct measurement demonstrates configured UART baud/timing`
- **Recovery:** `NOT ACTIVE`
- **Week 4 eligibility:** `YES`
- **Roadmap review:** `NOT DUE`; CP-02 remains `2026-09-06`

## MASTER CHECK

- Historical audit status: `BLOCKED` at audit base `41ea2befdc518df822667d33d7ffac1e089ae558`
- Disposition: `learning/week-03/MASTER_CHECK_DISPOSITION_W03.md`
- Raw-gate-evidence finding: `RESOLVED FOR CLOSURE`
- Correct-baud measurement finding: `P1 CARRY-OVER — NON-COMPETENCY-BLOCKING`
- W03D06 remote absence: `AUTHORIZED TO RESOLVE IN CLOSURE TRANSACTION`

## Limitations

- The correct-baud carry-over is measurement/evidence debt; it does not hide a
  failed P0 competency after the valid independent gate.
- W03D06 physical observations are preserved in its debug report but standalone
  terminal/debugger capture files were not stored.
- W03D05 proves bytes delivered to logger software, not electrical wire timing.
- This scorecard records the weekly decision; it does not independently award
  competency PASS.
