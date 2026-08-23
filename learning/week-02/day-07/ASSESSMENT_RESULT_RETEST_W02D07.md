# ASSESSMENT RESULT — W02D07 FRESH RETEST

## Assessment

- Date: `2026-08-23`
- Scope: `Week 2 startup / GPIO concurrency / EXTI-NVIC / fault isolation`
- Variant: `FRESH / UNSEEN`
- Raw evidence: `learning/week-02/day-07/RAW_COMPETENCY_RETEST_W02D07.md`
- Raw-answer authority: `Project Chat transcript`

## Prospective contract

- Scored mode: `AI-0`
- Allowed: official reference manual, datasheet, and vendor header for
  register, bitfield, and IRQ-name lookup
- Prohibited: AI, tutorials, previous answers, and answer-search

## Decision

- Technical result: `PASS`
- Integrity: `CLEAN under the prospectively declared retest contract`
- Mandatory Week 2 technical areas: `PASS`
- Official result: `COMPETENCY PASS`
- Retest required after this fresh attempt: `NO`

## Scope demonstrated

- startup, `.data`, and `.bss` reasoning;
- GPIO concurrency and the ODR read-modify-write race;
- BSRR reasoning;
- EXTI diagnosis;
- vector / `Default_Handler` debugging;
- pending-clear semantics;
- evidence-based fault isolation.

## Non-blocking findings

1. The FPU example in startup reasoning is conditional on project/system
   requirements.
2. Prefer describing BSRR as `single write / no RMW / peripheral-supported
   atomic bit set-reset`, not as a universal single-cycle bus operation.
3. For `PR |= BIT`, the primary read-modify-write risk is clearing other
   pending bits that were already read as `1`; do not overstate timing behavior.

## Historical boundary

The original attempt remains preserved separately as `INVALID / RETEST REQUIRED`
and is not relabeled as PASS. It was not a technical FAIL, but it could not
award competency under its own closed-book contract. This fresh retest is the
valid independent evidence used for the Week 2 competency decision.
