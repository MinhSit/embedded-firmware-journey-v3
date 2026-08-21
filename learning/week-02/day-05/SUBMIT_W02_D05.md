# SUBMIT — Week 02 / Day 05

Use `NOT RECORDED` or `NOT MEASURED` where the closeout input does not preserve
the original observation metadata. Do not infer hardware facts from timestamps.

## Canonical submission fields

- Task: `W02D05 — EXTI + NVIC`
- Date: `2026-08-21`
- Actual Focused Time: `6h — learner supplied`
- Highest AI Level Used: `AI-5`
- Commit: `SELF — containing commit`
- Files Changed:
  - `firmware/stm32/w02d05-exti-nvic-lab/main.c`
  - `learning/week-02/day-05/SUBMIT_W02_D05.md`
  - `learning/week-02/day-05/evidence/W02D05_LD2_OFF.jpg`
  - `learning/week-02/day-05/evidence/W02D05_LD2_ON_AFTER_PRESS.jpg`
  - `roadmap-control/daily-log.md`
  - `roadmap-control/ai-usage-log.md`
  - `roadmap-control/current-state.md`
- Official Sources:
  - NUCLEO-F446RE official board documentation/schematic for B1/PC13 polarity;
    exact document revision, page, and section `NOT RECORDED` in the closeout
    input.
  - STM32F446 reference manual `RM0390` for RCC, SYSCFG, EXTI routing/trigger,
    mask, and write-1-to-clear pending behavior; exact revision/page/section
    `NOT RECORDED` in the closeout input.
  - Cortex-M4 programming manual `PM0214` and the provided STM32F446 CMSIS/device
    header for NVIC and `EXTI15_10_IRQn`; exact manual location `NOT RECORDED`.
- Derived routing and trigger reasoning: B1 is PC13, released HIGH and pressed
  LOW. `SYSCFG_EXTICR4.EXTI13` selects port C for EXTI13. A button press is a
  HIGH-to-LOW transition, so the restored working configuration enables falling
  edge and disables rising edge.
- Build Command: `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`
- Build Result: `PASS / exit 0`; `text=1164`, `data=0`, `bss=1568`, `dec=2732`,
  `hex=aac`; ELF `build/w02d05-exti-nvic-lab.elf`
- Flash Method/Command: exact method/command `NOT RECORDED` in the closeout
  input; the learner reported the hardware demo results below.
- Demo/Test Procedure: start with LD2 OFF; press and release B1 twice; then
  change only the trigger to rising-edge-only, observe press/release behavior,
  restore falling-edge configuration, and retest.
- Demo/Test Result: `PASS` — initial LD2 OFF; first press -> LD2 ON; release ->
  no change; second press -> LD2 OFF.
- Pending-clear observation: source and learner explanation use
  `EXTI_PR.PR13` write-1-to-clear semantics. No debugger register capture was
  supplied.
- ISR minimality explanation: `EXTI15_10_IRQHandler` checks only PR13, clears
  PR13 by writing 1, and toggles PA5. It performs no blocking call, allocation,
  logging, or delay.
- Negative-case prediction: with rising-edge-only on active-low B1, press causes
  no toggle and release toggles.
- Negative-case single change: disable falling-edge trigger and enable only the
  rising-edge trigger for EXTI13.
- Negative-case observation and root cause: press -> no toggle; release ->
  toggle. Release changes PC13 from LOW to HIGH and therefore produces the
  configured rising edge.
- Working state restored: `YES` — falling-edge enabled, rising-edge disabled;
  hardware behavior retested `PASS`.
- Evidence paths:
  - `learning/week-02/day-05/evidence/W02D05_LD2_OFF.jpg`
  - `learning/week-02/day-05/evidence/W02D05_LD2_ON_AFTER_PRESS.jpg`
- Measurements: PC13 released HIGH and pressed LOW were learner-reported logic
  levels; voltage, timing, bounce, and direct register values were `NOT MEASURED`
  or not supplied.
- Known Failures/Limitations: `NONE` blocking. Button bounce was not
  characterized. Exact official-source locations and flash method were not
  recorded. Inherited non-blocking `nosys` linker warnings remain for `_close`,
  `_lseek`, `_read`, and `_write`.
- Questions: `NONE`

## Expected vs Actual

- Expected: a PC13 falling edge reaches EXTI13, asserts the shared EXTI15_10
  interrupt, and the minimal handler clears PR13 and toggles PA5 once per
  observed press event.
- Actual: initial OFF -> first press ON -> release unchanged -> second press OFF.
  The controlled rising-edge-only case moved the toggle to button release; the
  restored falling-edge configuration passed.

## Outcome boundary

- Artifact outcome: `ARTIFACT_PASS`
- Daily status: `GREEN / CLOSED`
- Competency outcome: unchanged. This assisted learning day creates no new
  competency PASS; the normal fresh Week 2 AI-0 gate remains required.
