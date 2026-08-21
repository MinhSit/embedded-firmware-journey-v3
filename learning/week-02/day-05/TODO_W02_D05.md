# TODO — Week 02 / Day 05

## Metadata

- Task: `W02D05 — EXTI + NVIC`
- Date: `2026-08-21`
- Target: `NUCLEO-F446RE`
- Board signals: `B1 = PC13`, `LD2 = PA5`
- Day type: normal `LEARNING`
- Available Focused Time: transient Project Chat input; do not persist here
- Initial evidence state: `NOT PERFORMED`

## Authoritative outcome

Configure SYSCFG / EXTI / NVIC correctly, clear pending correctly, keep the ISR
minimal, and produce a button-interrupt demo.

This starter intentionally contains no working EXTI/NVIC implementation and no
completed interrupt handler. The learner owns every core configuration choice.

## Acceptance criteria

- Verify the button signal and electrical polarity from an official board
  schematic or user manual before selecting an interrupt edge.
- Derive and implement the complete GPIO-to-EXTI routing path from official
  device documentation.
- Configure only the required EXTI line and matching NVIC interrupt.
- Define the handler required by the startup vector and keep it minimal.
- Inspect and clear only the relevant pending source using the documented
  register semantics.
- Demonstrate that button transitions invoke the interrupt behavior while the
  foreground loop remains idle.
- Build cleanly and record real hardware/debug evidence without inventing facts.
- Run one controlled negative/failure case, explain the observed symptom, and
  restore the working configuration.

## Required official-source verification

Record the exact document identifier/revision and section, table, figure, or
page used for each conclusion. At minimum, consult:

- the official NUCLEO-F446RE user manual and/or schematic for B1 wiring and
  electrical polarity;
- the STM32F446 reference manual (`RM0390`) for RCC, SYSCFG, EXTI, and pending
  register behavior;
- the Cortex-M4 programming manual (`PM0214`) for NVIC behavior where needed;
- the STM32F446 device datasheet and the provided CMSIS/device header for
  device-specific names and IRQ declarations.

Do not treat starter comments, memory, or third-party tutorials as authority.

## Learner TODO sequence

1. TODO: confirm B1 polarity from an official source and, if possible, measure
   the released and pressed levels before choosing the trigger edge.
2. TODO: determine and enable the required SYSCFG clock.
3. TODO: determine which EXTICR field maps PC13 to EXTI13.
4. TODO: select the trigger edge from the verified or measured B1 polarity.
5. TODO: unmask only the required EXTI line.
6. TODO: determine and enable the matching NVIC IRQ; justify any priority choice.
7. TODO: define the correct interrupt handler named by the startup vector.
8. TODO: inspect and clear only the relevant pending source using the documented
   register semantics.
9. TODO: keep the ISR minimal; move non-essential processing out of interrupt
   context.
10. TODO: build, flash, observe, capture evidence, and explain the complete event
    path in your own words.

## Test and evidence checklist

- [ ] Official-source references recorded with identifiers and locations.
- [ ] B1 released/pressed polarity: `NOT MEASURED` until actually measured.
- [ ] Clean build command and exit result recorded.
- [ ] Flash command/method and exact result recorded.
- [ ] Button-interrupt demo observation recorded.
- [ ] Relevant debugger register/pending observations recorded, or explicitly
      marked `NOT MEASURED`.
- [ ] ISR minimality justified from the submitted source.
- [ ] Repeated presses/transitions tested; bounce observations reported
      truthfully rather than inferred.
- [ ] Controlled negative/failure case predicted, run, explained, and restored.
- [ ] Evidence file paths listed and verified to exist.

## Negative/failure case requirement

After the working case is demonstrated, choose one controlled configuration
change within today's scope. Before changing it, write the predicted symptom.
Change exactly one variable, observe the result, identify the cause, then restore
and retest the working state. Do not damage hardware, force Git operations, or
claim evidence that was not observed.

## AI and ownership rules

- The learner must derive and implement the core SYSCFG/EXTI/NVIC setup,
  pending-clear behavior, and ISR.
- AI may explain theory, review a meaningful learner attempt, and help diagnose
  reported evidence according to the active Day Contract.
- Do not request or paste a complete reference solution before making a genuine
  attempt.
- Record the highest AI assistance level truthfully at submission time.
- This learning artifact cannot independently award competency PASS.

## Stop condition

Stop and report instead of guessing if official sources conflict, the target or
pin mapping differs, the starter/build infrastructure changes unexpectedly, a
command could overwrite learner work, or hardware behavior cannot be separated
from an unverified assumption.

## Submission fields

- Task:
- Date:
- Highest AI Level Used:
- Commit:
- Files Changed:
- Official Sources:
- Derived routing and trigger reasoning (learner's own words):
- Build Command:
- Build Result:
- Flash Method/Command:
- Demo/Test Procedure:
- Demo/Test Result:
- Pending-clear observation:
- ISR minimality explanation:
- Negative-case prediction:
- Negative-case single change:
- Negative-case observation and root cause:
- Working state restored:
- Evidence paths:
- Measurements:
- Known Failures/Limitations:
- Questions:
