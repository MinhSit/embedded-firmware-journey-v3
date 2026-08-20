# SUBMIT — Week 02 / Day 04

Complete every field with exact paths, commands, results, and observations.
Use `NOT RUN`, `NOT MEASURED`, or `NONE` instead of inventing evidence.

## Canonical submission fields

- Task: `W02D04 — GPIO input and BSRR`
- Date: `2026-08-20`
- Highest AI Level Used: `AI-5`
- Commit: `SELF — containing commit`
- Files Changed:
  - `firmware/stm32/w02d04-gpio-input-lab/main.c`
  - `firmware/stm32/w02d04-gpio-input-lab/PROVENANCE.md`
  - `learning/week-02/day-04/TODO_W02_D04.md`
  - `learning/week-02/day-04/GPIO_CHECKLIST_W02D04.md`
  - `learning/week-02/day-04/SUBMIT_W02_D04.md`
  - `learning/week-02/day-04/evidence/W02D04_PC13_PA5_CAPTURE.png`
  - `roadmap-control/daily-log.md`
  - `roadmap-control/ai-usage-log.md`
  - `roadmap-control/current-state.md`
- Build Command: `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`
- Build Result: PASS / exit 0; final size `text=860`, `data=0`, `bss=1568`,
  `dec=2428`, `hex=97c`; ELF `build/w02d04-gpio-input-lab.elf`
- Test Command: learner-performed NUCLEO-F446RE B1/LD2 smoke tests,
  BSRR/ODR comparison, controlled polarity-negative case, restoration,
  multimeter measurement, and logic-analyzer capture
- Test Result: PASS — normal, comparison, negative, restoration, and repeated-
  transition observations matched their predictions
- Evidence:
  `learning/week-02/day-04/evidence/W02D04_PC13_PA5_CAPTURE.png`;
  `learning/week-02/day-04/GPIO_CHECKLIST_W02D04.md`
- Measurements: B1/PC13 approximately `3.19 V` released and `0 V` pressed;
  STM32CubeProgrammer target voltage approximately `3.30 V`
- Known Failures: NONE. Inherited non-blocking `nosys` linker warnings remain
  for `_close`, `_lseek`, `_read`, and `_write`.
- Questions: NONE

## W02D04-specific prompts

- Input topology verified from official source:
  - Board document/schematic identifier, revision, section/page: NUCLEO-F446RE
    schematic used during the session; exact schematic subrevision, section,
    and page `NOT RECORDED`. Board marking observed: `MB1136 rev C`.
  - Derived input pin, GPIO port, external topology, and electrical levels:
    `B1 / PC13 / GPIOC`; external pull-up behavior consistent with the
    schematic; released HIGH (~3.19 V), pressed LOW (~0 V).
  - Derived internal `PUPDR` choice and reasoning: no internal pull; the
    measured released state was HIGH and the node was not floating.

- BSRR versus ODR/read-modify-write explanation:
  - ODR/RMW behavior observed: press -> LED ON; release -> LED OFF; PASS in the
    simple single-context test. Final retained implementation uses ODR RMW.
  - BSRR behavior observed: press -> LED ON; release -> LED OFF; PASS.
  - Concurrency/race reasoning in learner's own words: ODR RMW performs READ ->
    MODIFY -> WRITE; BSRR directly sets/resets without reading the previous ODR
    value first. BSRR avoids the RMW window and a class of lost updates when
    another context changes output state. No real concurrency race was
    experimentally reproduced.

- Negative case:
  - Prediction: released -> LED ON; pressed -> LED OFF
  - Single variable changed: reversed only the software interpretation of the
    active-low button, treating `PC13 != 0U` as pressed
  - Observed result: released -> LED ON; pressed -> LED OFF
  - Root-cause interpretation: software treated active-low hardware as active-high
  - Working state restored: YES — pressed -> LED ON; released -> LED OFF

- Capture:
  - Input/output capture file/path:
    `learning/week-02/day-04/evidence/W02D04_PC13_PA5_CAPTURE.png`
  - Register view/path: `NOT MEASURED / OPTIONAL / NON-SCORING`
  - What the capture demonstrates: using the learner-supplied mapping
    `D0 = PC13`, `D1 = PA5`, released is D0 HIGH/D1 LOW and pressed is D0
    LOW/D1 HIGH; repeated inverse transitions are visible.

Do not write conclusions before the learner has produced and checked the
underlying evidence.
