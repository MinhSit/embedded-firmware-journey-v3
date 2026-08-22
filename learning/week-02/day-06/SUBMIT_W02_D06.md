# SUBMIT — Week 02 / Day 06

Complete only with learner-performed or tool-verified facts. Use `NOT PERFORMED`,
`NOT MEASURED`, or `TO VERIFY` rather than inference.

## Canonical submission fields

- Task: `W02D06 — debounce using tick/state machine + schematic review`
- Date: `2026-08-22`
- Actual Focused Time: `6h — learner supplied`
- Highest AI Level Used: `AI-3`
- Commit: `SELF — containing commit`

- Files Changed:
  - `firmware/stm32/w02d06-debounce-lab/PROVENANCE.md`
  - `firmware/stm32/w02d06-debounce-lab/STM32F446RETX_FLASH.ld`
  - `firmware/stm32/w02d06-debounce-lab/build.ps1`
  - `firmware/stm32/w02d06-debounce-lab/debounce.c`
  - `firmware/stm32/w02d06-debounce-lab/debounce.h`
  - `firmware/stm32/w02d06-debounce-lab/include/cmsis_compiler.h`
  - `firmware/stm32/w02d06-debounce-lab/include/cmsis_gcc.h`
  - `firmware/stm32/w02d06-debounce-lab/include/cmsis_version.h`
  - `firmware/stm32/w02d06-debounce-lab/include/core_cm4.h`
  - `firmware/stm32/w02d06-debounce-lab/include/mpu_armv7.h`
  - `firmware/stm32/w02d06-debounce-lab/include/stm32f446xx.h`
  - `firmware/stm32/w02d06-debounce-lab/include/stm32f4xx.h`
  - `firmware/stm32/w02d06-debounce-lab/include/system_stm32f4xx.h`
  - `firmware/stm32/w02d06-debounce-lab/licenses/CMSIS_LICENSE.txt`
  - `firmware/stm32/w02d06-debounce-lab/licenses/STM32F4xx_DEVICE_LICENSE.txt`
  - `firmware/stm32/w02d06-debounce-lab/main.c`
  - `firmware/stm32/w02d06-debounce-lab/startup_stm32f446retx.s`
  - `firmware/stm32/w02d06-debounce-lab/system_stm32f4xx.c`
  - `learning/week-02/day-06/DEBOUNCE_LOG_W02D06.md`
  - `learning/week-02/day-06/SCHEMATIC_REVIEW_W02D06.md`
  - `learning/week-02/day-06/SUBMIT_W02_D06.md`
  - `learning/week-02/day-06/TODO_W02_D06.md`
  - `learning/week-02/day-06/schematic_b1_pc13_page3.png`
  - `learning/week-02/day-06/schematic_pa5_ld2_page5.png`
  - `tests/host/test_debounce.c`
  - `roadmap-control/daily-log.md`
  - `roadmap-control/ai-usage-log.md`
  - `roadmap-control/current-state.md`

- Debounce design summary in learner's own words:

  `When raw input equals the current stable level, there is no candidate transition.`

  `When raw input first differs from the stable level, that raw level becomes a candidate and candidate_since records when it started.`

  `The candidate must remain continuously at the same raw level for at least threshold_ticks. If it changes before the threshold, the previous candidate is cancelled/restarted.`

  `When elapsed time reaches the threshold, the candidate becomes the new stable level and exactly one semantic event is produced. active_level determines whether that stable transition is ACTIVATED or DEACTIVATED.`

- Tick source and unit:

  `Cortex-M SysTick interrupt.`

  `SystemCoreClock = 16000000 Hz.`

  `SysTick_Config(16000000U / 1000U) configures a 1 kHz tick.`

  `Therefore 1 tick = 1 ms.`

- Debounce threshold and justification:

  `threshold_ticks = 20`

  `With the verified 1 ms tick, this corresponds to 20 ms.`

  `20 ms is the software debounce threshold used for this lab; no electrical timing measurement of the physical switch bounce duration was performed.`

- Host Compile Command:

```powershell
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror `
  firmware/stm32/w02d06-debounce-lab/debounce.c `
  tests/host/test_debounce.c `
  -Ifirmware/stm32/w02d06-debounce-lab `
  -o tests/host/test_debounce.exe
```

- Host Compile Result:

  `PASS`

- Host Test Command:

```powershell
.\tests\host\test_debounce.exe
```

- Host Test Result:

  `PASS — 10 tests, 0 failed`

  Passed cases:
  - initial inactive state
  - initial active state
  - raw transition before threshold
  - exact threshold boundary
  - bounce/noise restarts candidate
  - press stabilization
  - release stabilization
  - no duplicate semantic event
  - uint32 tick wrap-around
  - active-low event mapping

- STM32 Build Command:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

- STM32 Build Result:

  `PASS`

  Final ELF size reported:

```text
text    data     bss     dec     hex
1652       0    1576    3228     c9c
```

  `_close`, `_lseek`, `_read`, and `_write` nosys warnings remained but did not prevent linking.

- Flash/Debug Method and Result:

  `Firmware was flashed/run on the physical NUCLEO-F446RE and hardware behavior was observed.`

  `Exact flash/debug command or tool method: NOT RECORDED`

- Hardware Test Procedure:

  `Run the W02D06 firmware on the NUCLEO-F446RE. Repeatedly operate the USER button and observe LD2 across successive press/release cycles.`

  `The purpose is to verify that a stable active-low button activation produces a semantic ACTIVATED event and that successive valid presses can toggle LD2 rather than leaving the system stuck after the first press.`

- Hardware Test Result:

  `PASS`

  `Physical-board video evidence shows repeated USER-button operation and LD2 changing OFF/ON across successive valid presses.`

  `The earlier failure mode where the first press turned LD2 on and subsequent presses could not toggle it again was no longer observed.`

  `Capture filename: VID_20260822_140328.mp4`

  `Repository storage status: NOT STORED IN REPO.`

- Debounce Log Path:

  `learning/week-02/day-06/DEBOUNCE_LOG_W02D06.md`

- Annotated Schematic Path:

  - `learning/week-02/day-06/schematic_b1_pc13_page3.png`
  - `learning/week-02/day-06/schematic_pa5_ld2_page5.png`

- Official Schematic/User-Manual Sources:

  - `NUCLEO-F446RE product/document page`
  - `UM1724 Rev 17 — STM32 Nucleo-64 boards (MB1136)`
  - `MB1136-DEFAULT-C03 schematic pack`
  - `MB1136-DEFAULT-C04 schematic pack`

- Exact board and schematic revision match:

  `Physical board marking: MB1136 rev C.`

  `Exact physical C03 vs C04 subrevision remains unresolved because the visible board marking does not distinguish them.`

  `Both C03 and C04 candidate schematic packs were inspected.`

  `The W02D06-relevant B1/PC13 path on page 3 and PA5/LD2 path on page 5 are identical in both candidate packs.`

- B1/PC13 path conclusion and source location:

  `Source: C03 + C04 schematic packs, page 3.`

  `PC13 connects through SB17 to the B1 USER switch node.`

  `R30 = 4.7 kOhm pulls the node toward VDD when the button is released.`

  `Pressing B1 connects the node toward GND.`

  `R29 = 100 Ohm and C15 = 100 nF are also present in the button input network.`

  `Therefore B1 is active-low: released = HIGH, pressed = LOW.`

- PA5/LD2 path conclusion and source location:

  `Source: C03 + C04 schematic packs, page 5.`

  `PA5 connects through SB42 to the D13 net.`

  `D13 connects through SB21 and R31 = 510 Ohm to LD2 Green, with the LED path returning to GND.`

- Power/ground conclusion and source location:

  `B1/PC13 source: page 3. R30 pulls the button node toward VDD and the pressed switch path references GND.`

  `PA5/LD2 source: page 5. The LD2 path returns to board GND.`

  `No direct voltage measurement was performed.`

- Connector/ST-LINK/jumper or solder-bridge conclusions and source locations:

  `PA5 is shown routed onto Arduino D13 through SB42 on page 5.`

  `SB17 is shown in the PC13-to-B1 path on page 3.`

  `Exact connector pin numbering, ST-LINK SWD/reset/clock tracing, unrelated power-jumper configuration, and physical fitted/open state of unverified solder bridges remain TO VERIFY.`

- Tick-wrap explanation:

  `Tick elapsed time is calculated using unsigned uint32_t subtraction: elapsed = now_ticks - candidate_since.`

  `Unsigned subtraction is modulo 2^32, so the elapsed-time calculation continues to work when the tick counter wraps from UINT32_MAX back to zero, provided the measured interval is within the valid unsigned timing range.`

  `Example: candidate_since = 0xFFFFFFFE and now_ticks = 0x00000002 gives elapsed = 4 ticks.`

- ISR/foreground responsibility explanation:

  `The EXTI ISR should remain short: detect/acknowledge the PC13 interrupt, clear the pending bit, record that button activity occurred, and return.`

  `It should not delay or wait for the debounce threshold.`

  `The foreground/main-loop path reads PC13, obtains the current monotonic tick, and calls debounce_sample().`

  `While a debounce candidate is active, foreground sampling continues so elapsed time can reach threshold_ticks even if no new EXTI edge occurs.`

  `Only DEBOUNCE_EVENT_ACTIVATED performs the application action of toggling LD2.`

  `Both falling and rising button transitions must be observable so the debounce state can commit both press and release stable states.`

- Measurements:

  `Electrical voltage measurements: NOT MEASURED`

  `Physical switch bounce duration: NOT MEASURED`

  `Tick period derived from verified clock/configuration: 1 ms`

  `Hardware functional behavior: observed on physical NUCLEO-F446RE`

- Known Failures/Limitations:

  `Initial host-test iteration failed 3 tests; implementation was corrected and final result was 10/10 PASS.`

  `Initial STM32 integration failed to link because systick_init() and get_tick() had no implementations; a SysTick-based monotonic tick source was then implemented and the clean build passed.`

  `Initial hardware behavior allowed the first activation but could not correctly handle later presses because release state was not being incorporated correctly.`

  `EXTI/input handling was corrected so successive active-low press/release transitions could be debounced.`

  `Exact physical C03 vs C04 schematic subrevision remains unresolved.`

  `No electrical measurements of switch voltage or physical bounce duration were performed.`

  `Hardware capture filename is VID_20260822_140328.mp4; the video is NOT STORED IN REPO.`

- Questions:

  `None blocking W02D06 closure.`

## Evidence boundary

- Starter STM32 build success proves infrastructure integrity only.
- Host tests prove only the tested software contract.
- Hardware behavior and timing require real observation.
- Schematic conclusions require an exact official source match.
- This assisted normal-learning artifact cannot independently award competency PASS; the fresh Week-2 AI-0 gate remains required.
