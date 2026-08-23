# POST-GATE REVIEW — W02D07

## Boundary

This review records learning after the scored attempt closed. It does not alter
the original contract or convert the invalid attempt into competency PASS.

## Learner correction: EXTI symptom diagnosis

The learner correctly distinguished these two cases after the gate:

### A. Pending is not cleared

- The pending condition remains asserted.
- The ISR may immediately retrigger.
- This can cause an interrupt storm or severe starvation of foreground/main
  execution.

### B. ISR truly runs once and then becomes silent

Stronger hypotheses include:

- the pin never returns to the inactive state, so no new edge occurs;
- EXTI, NVIC, or global interrupt delivery becomes masked/disabled after the
  first event;
- the ISR or called code does not return normally, or execution gets stuck.

Therefore, failure to clear the pending bit generally explains repeated
retriggering, not the symptom "runs once then silent."

## Write-1-to-clear nuance

`EXTI->PR |= bit` is dangerous because `EXTI_PR` uses write-1-to-clear
semantics. A read-modify-write can write `1` back to other simultaneously
pending lines and clear them unintentionally.

For the intended line, the clearer pattern is a direct write:

```c
EXTI->PR = bit;
```

## Scored-attempt findings retained

The post-attempt technical review initially judged the performance broadly
PASS-level, with precision findings including:

- imprecise wording around half-open `.data` / `.bss` range arithmetic;
- an over-broad assumption that accessing a peripheral with its clock disabled
  necessarily causes a bus fault;
- the Task 3D symptom mismatch described above.

The correction is valid post-gate learning evidence only. Official assessment
outcome remains `INVALID / RETEST REQUIRED` because external reference lookup
occurred during a scored closed-book phase.
