# DEBOUNCE LOG — W02D06

- Date: `2026-08-22`
- Board: `NUCLEO-F446RE`
- Main-board marking: `MB1136 rev C`
- Tick source: `SysTick`
- Tick unit: `1 ms`
- Debounce threshold: `20 ticks = 20 ms`

## Host verification

- Strict host compile: `PASS`
- Host tests: `PASS — 10 tests, 0 failed`
- Covered cases:
  - initial inactive state
  - initial active state
  - before-threshold rejection
  - exact-threshold acceptance
  - bounce/noise candidate restart
  - press stabilization
  - release stabilization
  - no duplicate semantic event
  - uint32 tick wrap-around
  - active-low event mapping

## STM32 verification

- Clean STM32 build: `PASS`
- Final ELF size: `text=1652`, `data=0`, `bss=1576`, `dec=3228`, `hex=c9c`
- Non-blocking linker warnings: inherited `_close`, `_lseek`, `_read`, `_write`
- Timing basis:
  - `SystemCoreClock = 16000000U`
  - `SysTick_Config(16000000U / 1000U)`
- Derived tick unit: `1 tick = 1 ms`

## Hardware observation

- USER button tested on physical NUCLEO-F446RE.
- Successive valid presses toggled LD2 OFF/ON.
- The earlier stuck-after-first-activation behavior was no longer observed after correcting input/EXTI handling.
- Hardware capture filename: `VID_20260822_140328.mp4`
- Repository storage status: `NOT STORED IN REPO`

## Schematic evidence

- Physical main-board marking: `MB1136 rev C`
- Exact C03 vs C04 physical subrevision: `UNRESOLVED`
- B1/PC13: C03 + C04, page 3
- PA5/LD2: C03 + C04, page 5
- The inspected W02D06-relevant paths are identical across both candidate packs.
- Electrical voltage measurement: `NOT MEASURED`
- Physical bounce duration: `NOT MEASURED`

## Result

`PASS for W02D06 debounce artifact evidence.`

Highest AI level used: `AI-3`. This remains assisted normal-learning work and
does not replace the fresh Week-2 AI-0 competency gate.
