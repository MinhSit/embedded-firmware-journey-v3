# GPIO Checklist — W02D04

Complete this worksheet from exact official sources and actual measurements.
Leave unperformed observations explicit as `NOT MEASURED` or `NOT CAPTURED`.

## Board and electrical facts

- Board marking observed: `MB1136 rev C`
- MCU: `STM32F446RE`
- Target voltage shown by STM32CubeProgrammer: approximately `3.30 V`
- Common ground: `NOT RECORDED`
- Input pin: `B1 USER / PC13`
- Input GPIO port: `GPIOC`
- External pull: pull-up behavior consistent with the schematic used during the
  session; released HIGH and pressed LOW were measured
- Internal PUPDR choice: no internal pull for PC13
- Official schematic/source: NUCLEO-F446RE schematic used during the session;
  exact schematic subrevision, section, and page `NOT RECORDED`. The observed
  `MB1136 rev C` marking is a physical board marking.
- Output pin: `PA5 / LD2`
- Relevant clocks: `GPIOA` and `GPIOC` peripheral clocks
- Expected released level: PC13 HIGH; PA5 LOW; LD2 OFF
- Expected active level: PC13 LOW; PA5 HIGH; LD2 ON

## Observed behavior

- Observed released level: PC13 HIGH; approximately `3.19 V` at B1; PA5 LOW;
  LD2 OFF
- Observed active level: PC13 LOW; approximately `0 V` at B1; PA5 HIGH; LD2 ON
- Observed output behavior: press B1 -> LD2 ON; release B1 -> LD2 OFF; repeated
  transitions PASS. Behavior remained correct after STM32CubeProgrammer was
  disconnected.

## Output-write comparison

- ODR/RMW observation: press -> LED ON; release -> LED OFF; PASS in the simple
  single-context test. The retained final implementation uses ODR RMW.
- BSRR observation: press -> LED ON; release -> LED OFF; PASS in the same simple
  visible-behavior comparison.
- Concurrency/race reasoning: ODR RMW performs READ -> MODIFY -> WRITE. BSRR
  performs a direct set/reset write without first reading the previous ODR
  value, avoiding the RMW window and a class of lost updates if another context
  changes output state. No real concurrency race was experimentally reproduced.

## Negative/failure case

- Negative case: intentionally reversed only the software interpretation of the
  active-low button, treating `PC13 != 0U` as pressed
- Expected: released -> LED ON; pressed -> LED OFF
- Observed: released -> LED ON; pressed -> LED OFF
- Root-cause interpretation: software treated active-low hardware as active-high
- Working state restored: YES — active-low condition restored; pressed -> LED
  ON; released -> LED OFF

## Build and evidence

- Capture file/path:
  `learning/week-02/day-04/evidence/W02D04_PC13_PA5_CAPTURE.png`; learner-supplied
  mapping `D0 = PC13`, `D1 = PA5`; repeated inverse transitions visible
- Register view: `NOT MEASURED / OPTIONAL / NON-SCORING`
- Build result: PASS / exit 0 using
  `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`; final size
  `text=860`, `data=0`, `bss=1568`, `dec=2428`, `hex=97c`; ELF:
  `build/w02d04-gpio-input-lab.elf`
- Flash method: STM32CubeProgrammer via onboard ST-LINK / SWD; target observed
  as STM32F446xx / Cortex-M4, approximately 3.30 V, 512 KB flash. Exact ST-LINK
  serial number `NOT RECORDED`.
- Known limitations: exact schematic subrevision/section/page and common-ground
  observation were not recorded; register view was not measured; concurrency
  race was reasoned about but not experimentally reproduced; inherited
  non-blocking `nosys` warnings remain for `_close`, `_lseek`, `_read`, and
  `_write`.

Do not populate learner-observed values until the action was actually performed.
