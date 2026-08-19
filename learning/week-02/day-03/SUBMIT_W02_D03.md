# SUBMIT — Week 02 / Day 03

## Learner declaration

- Core RCC/GPIO implementation written by learner: YES
- Official sources verified before implementation: YES
- External help disclosed:
  Cowork/repository executor created the W02D03 starter, build and vendor
  infrastructure. ChatGPT provided theory clarification, graded guidance,
  official-source navigation, post-attempt code/build/debug review, and material
  assistance drafting/editing the evidence, checklist and submission wording.
- Highest AI level used: AI-5
- HAL/LL GPIO initialization used: NO

## Source and build evidence

- Learner source path:
  `firmware/stm32/w02d03-gpio-lab/main.c`

- Official source identifiers/sections:
  - UM1724 Rev 17, Section 7.6 — LEDs
  - UM1724 Rev 17, Table 19 — ARDUINO connectors on NUCLEO-F446RE
  - RM0390 Section 6.3.10 — RCC_AHB1ENR
  - RM0390 Section 7.4.1 — GPIOx_MODER
  - RM0390 Section 7.4.6 — GPIOx_ODR
  - RM0390 Section 7.4.7 — GPIOx_BSRR
  - STM32F446xC/E datasheet, Section 4 — Pinout and pin description

- Clean build command:
  `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`

- Build exit code:
  `0` / PASS

- Compiler/linker warnings:
  Inherited non-blocking newlib-nano linker warnings for `_close`, `_lseek`,
  `_read`, and `_write`.
  No new actionable compiler error from the GPIO implementation.

- ELF path:
  `firmware/stm32/w02d03-gpio-lab/build/w02d03-gpio-lab.elf`

- Map path:
  `firmware/stm32/w02d03-gpio-lab/build/w02d03-gpio-lab.map`

- List/disassembly path:
  `firmware/stm32/w02d03-gpio-lab/build/w02d03-gpio-lab.list`

## Hardware evidence

- Board/device identity confirmed:
  NUCLEO-F446RE / STM32F446RE

- Flash command/result:
  Firmware flashed successfully using the STM32 programming workflow.
  Exact flash command/tool action: NOT RECORDED.

- Expected LED/pin behavior:
  PA5 HIGH -> onboard LD2 ON.
  PA5 LOW -> onboard LD2 OFF.

- Observed LED/pin behavior:
  Normal firmware produced LD2 ON continuously after flashing.
  Observed behavior matched the expected normal path.

- Register/debugger measurement actually performed:
  NO / NOT MEASURED

- Photo/video/logic-analyzer evidence path, if captured:
  NONE

## Negative/failure observation

- Failure case:
  Temporarily removed/commented the GPIOA peripheral clock-enable operation.

- Prediction/hypothesis:
  Without GPIOA clock enabled, GPIOA would not operate as expected and PA5 would
  not be driven HIGH through the intended GPIO output path, so LD2 was expected OFF.

- Single variable changed:
  GPIOA clock-enable operation in RCC.

- Measurement:
  Visual observation of onboard LD2 after rebuilding and flashing the modified firmware.

- Result:
  LD2 OFF with GPIOA clock enable removed.

- Working state restored:
  YES.
  GPIOA clock enable was restored, the firmware was rebuilt and reflashed, and
  LD2 returned ON.

## Register checklist

- Completed worksheet: `REGISTER_CHECKLIST_W02D03.md`
- Any unresolved field:
  - Observed register state: NOT MEASURED
  - Direct debugger/register-view evidence: NONE
  - Exact flash command/tool action: NOT RECORDED

## Learner self-explanation

- Clock-before-GPIO reasoning:
  GPIO peripheral needs to receive its clock through RCC before it can be configured
  or controlled as intended. If GPIOA clock is not enabled, the GPIOA block does not
  operate as expected, so the MODER/output configuration does not produce the intended
  pin behavior. The negative test also showed that removing GPIOA clock enable caused
  LD2 to remain OFF.

- Field-mask/read-modify-write reasoning:
  Clear only the target field so the old value is removed without disturbing the
  configuration of unrelated pins, then OR the new value into the correct bit position.
  This changes only the intended field and avoids overwriting the rest of the register.

- Output-write mechanism reasoning:
  BSRR was used for output control. It allows individual GPIO bits to be set or reset
  with a single write without performing a read-modify-write on ODR. This also avoids
  a possible race where another execution context modifies ODR between the read and write.

- LED polarity reasoning:
  LD2 is Active-HIGH for this board path. PA5 HIGH corresponds to LD2 ON, while PA5
  LOW corresponds to LD2 OFF.

- Clock-error versus mode-error diagnosis:
  Check in this order:
  1. `RCC->AHB1ENR` — verify GPIOA peripheral clock enable.
  2. `GPIOA->MODER` — verify PA5 is configured as output mode `01`.
  3. GPIO output state through `GPIOA->ODR` / the intended `GPIOA->BSRR` operation.
  4. If register configuration appears correct, continue to the physical LED/pin path.

## Remaining questions or blockers

- No current functional blocker.
- Register state was not directly measured with debugger/register view.
- Exact flash command/tool action was not recorded.

## Review result

GREEN / ARTIFACT_PASS. The required W02D03 artifact and evidence are complete.
This learning day creates no new COMPETENCY_PASS; the scheduled fresh Week 2
AI-0 competency gate remains required.
