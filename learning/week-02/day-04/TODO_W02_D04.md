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

- [x] Verify the relevant board port, pin, electrical topology, and clock facts
      from exact official sources.
- [x] Implement the register-level input/output behavior as learner-owned code.
- [x] Produce a clean build and record the exact command and result.
- [x] Perform a physical hardware smoke test without fabricating observations.
- [x] Record expected versus actual behavior.
- [x] Run and record one suitable, safe negative/failure case.
- [x] Save input/output capture evidence and record its path.
- [x] Independently explain BSRR versus ODR/read-modify-write at end of day.

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

- [x] Board user-input pin and electrical topology from the board manual
      and schematic revision.
- [x] Corresponding GPIO port clock from the MCU reference manual.
- [x] Target pin's `MODER` field and required input-mode setting.
- [x] `PUPDR` requirement based on the actual schematic, without assuming an
      internal pull configuration in advance.
- [x] Target pin's `IDR` field and read behavior.
- [x] `ODR` behavior relevant to software read-modify-write.
- [x] `BSRR` set/reset behavior relevant to the selected output.

Record exact document identifiers, revisions, sections, pages, and the derived
facts in `GPIO_CHECKLIST_W02D04.md`.

The exact schematic document identifier, subrevision, section, and page used
during the session were `NOT RECORDED`. The observed physical board marking was
`MB1136 rev C`; it is not presented as a schematic document revision.

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
| W02D04-IO-01 | Normal released input | PC13 HIGH; PA5 LOW; LD2 OFF | PASS — PC13 HIGH (~3.19 V at B1); PA5 LOW; LD2 OFF | `evidence/W02D04_PC13_PA5_CAPTURE.png`; learner-reported measurement/observation |
| W02D04-IO-02 | Active/pressed input | PC13 LOW; PA5 HIGH; LD2 ON | PASS — PC13 LOW (~0 V at B1); PA5 HIGH; LD2 ON | `evidence/W02D04_PC13_PA5_CAPTURE.png`; learner-reported measurement/observation |
| W02D04-IO-03 | Output response to verified input state | Press -> LD2 ON; release -> LD2 OFF | PASS; remained correct after STM32CubeProgrammer was disconnected | Learner-reported hardware observation |
| W02D04-IO-04 | Repeated released/active transitions | Repeated inverse PC13/PA5 transitions | PASS | `evidence/W02D04_PC13_PA5_CAPTURE.png` |
| W02D04-NEG-01 | Reverse only the software interpretation of button polarity | Released -> LD2 ON; pressed -> LD2 OFF | PASS — prediction matched; active-low interpretation restored; normal behavior returned | Learner-reported hardware observation; no separate capture |
| W02D04-EVD-01 | Input/output capture; register view optional/non-scoring | Capture path recorded | PASS — capture saved; register view `NOT MEASURED / NON-SCORING` | `evidence/W02D04_PC13_PA5_CAPTURE.png` |

Do not replace the schematic-derived placeholders with assumptions. Predict the
negative case before changing one variable, avoid unsafe electrical conditions,
and restore the working state afterward.

## Required evidence

- Exact clean-build command, exit code, warnings/errors, and generated artifact
  paths.
- Hardware observation for released, active, output-response, and repeated
  transition cases.
- Input/output capture file/path. Register view is optional/non-scoring for
  W02D04 and remains `NOT MEASURED` because none was obtained.
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
