# TODO — Week 02 / Day 04

## Metadata

- Date: `2026-08-20`
- Week/Day: `W02D04`
- Calendar Position: `Week 2 / Day 4`
- Execution Position: `W02D04`
- Day type: `LEARNING`
- Topic: `GPIO input and BSRR`
- Available Focused Time: `6h`
- Planned Focused Time: `6h`
- AI Mode: `AI-1/AI-2 before meaningful attempt; AI-3 only after attempt`
- Board: `NUCLEO-F446RE`
- MCU: `STM32F446RE`

This preparation does not activate `FOCUS_ACTIVE` and does not award artifact
PASS or competency PASS.

## Outcome

Independently derive and implement register-level GPIO input/output behavior,
then produce a clean build and truthful hardware evidence that compares BSRR
with ODR read-modify-write under verified board electrical conditions.

## Acceptance criteria

- [ ] Verify the relevant board port, pin, electrical topology, and clock facts
      from exact official sources.
- [ ] Implement the register-level input/output behavior as learner-owned code.
- [ ] Produce a clean build and record the exact command and result.
- [ ] Perform a physical hardware smoke test without fabricating observations.
- [ ] Record expected versus actual behavior.
- [ ] Run and record one suitable, safe negative/failure case.
- [ ] Save input/output capture evidence and record its path.
- [ ] Independently explain BSRR versus ODR/read-modify-write at end of day.

### NON-SCORING learning feedback

Optional defensive observations may include preserving unrelated register
fields, repeated-transition behavior, and concurrency/race implications. These
are learning feedback only and do not add silent acceptance requirements.

## Prerequisites

- W02D03 RCC/GPIO output artifact exists.
- `W01-C-FOUND — COMPETENCY_PASS` prerequisite is satisfied.
- No current Recovery state or blocker is active.

## Official-source checklist

Locate and verify these facts before implementation. Do not fill them from this
starter or from unofficial example code.

- [ ] Board user-input pin and electrical topology from the exact board manual
      and schematic revision.
- [ ] Corresponding GPIO port clock from the MCU reference manual.
- [ ] Target pin's `MODER` field and required input-mode setting.
- [ ] `PUPDR` requirement based on the actual schematic, without assuming an
      internal pull configuration in advance.
- [ ] Target pin's `IDR` field and read behavior.
- [ ] `ODR` behavior relevant to software read-modify-write.
- [ ] `BSRR` set/reset behavior relevant to the selected output.

Record exact document identifiers, revisions, sections, pages, and the derived
facts in `GPIO_CHECKLIST_W02D04.md`.

## Learner TODO

1. Confirm board revision, MCU, supply/common-ground conditions, and the exact
   official source set.
2. Derive the input pin, output pin, relevant clocks, electrical levels, and
   pull requirement from those sources.
3. Record the derivation in `GPIO_CHECKLIST_W02D04.md` before coding.
4. Implement the marked RCC/GPIO TODOs in
   `firmware/stm32/w02d04-gpio-input-lab/main.c` without HAL/LL GPIO init code.
5. Build from a clean lab state and inspect all warnings/errors.
6. Predict normal released/active behavior before flashing.
7. Run the physical input/output checks and repeated transitions; record actual
   observations and a capture path.
8. Compare an ODR read-modify-write output update with a BSRR output update and
   explain the concurrency/race implications.
9. Run one safe, controlled negative/fault case by changing one variable; then
   restore the working state.
10. Complete `SUBMIT_W02_D04.md` using only evidence actually produced.

## Build procedure

From `firmware/stm32/w02d04-gpio-input-lab/`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

A clean starter build proves infrastructure integrity only. It does not prove
learner implementation, hardware behavior, artifact PASS, or competency PASS.

## Test matrix

| ID | Case | Expected before test | Actual | Evidence |
|---|---|---|---|---|
| W02D04-IO-01 | Normal released input | `EXPECTED_RELEASED_LEVEL = TO_BE_VERIFIED_FROM_SCHEMATIC` | `NOT RUN` | `NOT CAPTURED` |
| W02D04-IO-02 | Active/pressed input | `EXPECTED_ACTIVE_LEVEL = TO_BE_VERIFIED_FROM_SCHEMATIC` | `NOT RUN` | `NOT CAPTURED` |
| W02D04-IO-03 | Output response to verified input state | `TO_BE_DERIVED` | `NOT RUN` | `NOT CAPTURED` |
| W02D04-IO-04 | Repeated released/active transitions | `TO_BE_DERIVED` | `NOT RUN` | `NOT CAPTURED` |
| W02D04-NEG-01 | One controlled negative/fault case | `TO_BE_PREDICTED_BEFORE_TEST` | `NOT RUN` | `NOT CAPTURED` |
| W02D04-EVD-01 | Input/output capture and register/source trace | `CAPTURE_PATH_TO_BE_RECORDED` | `NOT RUN` | `NOT CAPTURED` |

Do not replace the schematic-derived placeholders with assumptions. Predict the
negative case before changing one variable, avoid unsafe electrical conditions,
and restore the working state afterward.

## Required evidence

- Exact clean-build command, exit code, warnings/errors, and generated artifact
  paths.
- Hardware observation for released, active, output-response, and repeated
  transition cases.
- Capture file/path and register view actually obtained.
- Expected versus observed result for every executed case.
- Exact official document identifiers, revisions, sections/pages, and facts
  used.
- Negative-case prediction, single changed variable, observed result,
  root-cause interpretation, and restoration result.
- Independent learner explanation of BSRR versus ODR/read-modify-write.

## Stop condition

Stop when the required W02D04 artifact/evidence exists, expected/actual is
recorded, open defects are visible, and exactly one 5–15 minute next physical
action exists for the next session.

## Forbidden shortcuts

- Do not copy a complete RCC/GPIO input/output implementation from AI, tutorial,
  generated code, or another hidden solution.
- Do not treat a guessed pull configuration or electrical level as board fact.
- Do not fabricate build, flash, capture, register, or hardware evidence.
- Do not treat this starter build as artifact PASS or competency PASS.
