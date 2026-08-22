# SCHEMATIC REVIEW — Week 02 / Day 06

Complete only with learner-performed or tool-verified facts. Use `NOT PERFORMED`,
`NOT MEASURED`, or `TO VERIFY` rather than inference.

## Canonical submission fields

- Task: `W02D06 — debounce using tick/state machine + schematic review`
- Date: `2026-08-22`
- Actual Focused Time: `6h — learner supplied`
- Highest AI Level Used: `AI-3`
- Commit: `SELF — containing commit`

- Files Changed:
  - `firmware/stm32/w02d06-debounce-lab/debounce.c`
  - `firmware/stm32/w02d06-debounce-lab/main.c`
  - `learning/week-02/day-06/DEBOUNCE_LOG_W02D06.md`
  - `learning/week-02/day-06/SCHEMATIC_REVIEW_W02D06.md`
  - `learning/week-02/day-06/SUBMIT_W02_D06.md`
  - `learning/week-02/day-06/TODO_W02_D06.md`
  - `learning/week-02/day-06/schematic_b1_pc13_page3.png`
  - `learning/week-02/day-06/schematic_pa5_ld2_page5.png`
  - `Complete final path list: see SUBMIT_W02_D06.md`

- Debounce design summary in learner's own words:

  `When raw input equals the stable level, there is no transition to accept. When raw input differs from the stable level, that raw level becomes a candidate and candidate_since records when it started. The candidate must remain continuously at the same level for the full threshold. If it changes before the threshold, the candidate is cancelled/restarted. At elapsed >= threshold_ticks, the candidate becomes the new stable level and exactly one semantic event is emitted. active_level decides whether the committed state is ACTIVATED or DEACTIVATED.`

- Tick source and unit:

  `Cortex-M SysTick interrupt.`

  `system_stm32f4xx.c reports SystemCoreClock = 16000000U.`

  `SysTick_Config(16000000U / 1000U) configures SysTick for 1 kHz.`

  `Therefore 1 tick = 1 ms.`

- Debounce threshold and justification:

  `threshold_ticks = 20`

  `With the verified 1 ms tick, this corresponds to 20 ms.`

  `20 ms is the software debounce threshold used by this lab. Physical switch bounce duration was not electrically measured.`

- Host Compile Command:

```powershell
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror `
  firmware/stm32/w02d06-debounce-lab/debounce.c `
  tests/host/test_debounce.c `
  -Ifirmware/stm32/w02d06-debounce-lab `
  -o tests/host/test_debounce.exe
```

- Host Compile Result: `PASS`

- Host Test Command:

```powershell
.\tests\host\test_debounce.exe
```

- Host Test Result: `PASS — 10 tests, 0 failed`

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

- STM32 Build Result: `PASS`

  Final ELF size reported:

```text
text    data     bss     dec     hex
1652       0    1576    3228     c9c
```

  `_close`, `_lseek`, `_read`, and `_write` nosys warnings remained but did not prevent linking.

- Flash/Debug Method and Result:

  `Firmware was flashed/run on the physical NUCLEO-F446RE and hardware behavior was observed.`

  `Exact flash/debug tool/command: NOT RECORDED`

- Hardware Test Procedure:

  `Run the W02D06 firmware on the physical NUCLEO-F446RE. Repeatedly press and release the USER button while observing LD2. Verify that successive valid active-low presses can toggle LD2 and that the application no longer becomes stuck after the first activation.`

- Hardware Test Result: `PASS`

  `Video evidence shows repeated USER-button operation and LD2 changing OFF/ON across successive valid presses.`

  `The earlier failure mode where the first press turned LD2 on and later presses could not toggle it again was no longer observed.`

  `Capture: VID_20260822_140328.mp4`

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

  Exact official URLs were not recorded in the repository evidence.

- Exact board and schematic revision match:

  `Physical board marking observed: MB1136 rev C.`

  `The visible marking does not distinguish exact subrevision C03 from C04.`

  `Both official C03 and C04 candidate schematic packs were inspected for the W02D06-relevant paths.`

  `The B1/PC13 circuitry on page 3 and PA5/LD2 circuitry on page 5 are identical in both candidate packs for the paths inspected in this lab.`

  `Exact physical C03 vs C04 remains unresolved and is kept visible.`

- B1/PC13 path conclusion and source location:

  `Source: C03 + C04 schematic packs, page 3; refs PC13, SB17, B1, R30, R29, C15, VDD, GND.`

  `PC13 connects through SB17 to the B1 USER switch node. R30 = 4.7 kOhm pulls the node toward VDD while released. Pressing B1 connects the node to GND, producing LOW. R29 = 100 Ohm and C15 = 100 nF are also present in the button input network. Therefore B1 is active-low: released = HIGH, pressed = LOW.`

- PA5/LD2 path conclusion and source location:

  `Source: C03 + C04 schematic packs, page 5; refs PA5, SB42, D13, SB21, R31, LD2.`

  `PA5 connects through SB42 to the Arduino D13 net. D13 connects through SB21 and R31 = 510 Ohm to LD2 Green. The LED path returns to GND.`

- Power/ground conclusion and source location:

  `B1/PC13 source: page 3. R30 pulls the button node toward VDD; the pressed switch path references GND.`

  `PA5/LD2 source: page 5. The LD2 path returns to board GND.`

  `Electrical voltage measurement: NOT MEASURED.`

- Connector/ST-LINK/jumper or solder-bridge conclusions and source locations:

  `PA5 is routed onto Arduino D13 through SB42 on page 5.`

  `SB17 is shown in the PC13-to-B1 signal path on page 3.`

  `Exact Arduino/Morpho connector pin numbering: TO VERIFY.`

  `ST-LINK SWD/reset/clock path review: TO VERIFY.`

  `Power-source jumper/bridge configuration: TO VERIFY.`

  `Exact physical fitted/open state of unverified solder bridges: TO VERIFY.`

  `These unresolved items were not required to establish the W02D06 debounce polarity or PA5-to-LD2 functional path.`

- Tick-wrap explanation:

  `Elapsed time is calculated with unsigned uint32_t subtraction: elapsed = now_ticks - candidate_since.`

  `uint32_t arithmetic is modulo 2^32, so this subtraction remains valid across timer wrap for the intended short debounce interval.`

  `Example: candidate_since = 0xFFFFFFFE and now_ticks = 0x00000002 gives elapsed = 4 ticks.`

- ISR/foreground responsibility explanation:

  `The EXTI ISR remains short: acknowledge the PC13 interrupt, clear the pending bit, record raw activity, and return.`

  `The ISR must not delay or wait for the debounce threshold.`

  `The foreground/main-loop path reads PC13, obtains the current monotonic SysTick value, and calls debounce_sample().`

  `While a candidate is active, foreground sampling continues so elapsed time can reach threshold_ticks without blocking inside the ISR.`

  `Only DEBOUNCE_EVENT_ACTIVATED toggles LD2.`

  `Both falling and rising button transitions must be observable so the state machine can commit both stable press and stable release states.`

- Measurements:

  `Electrical voltage measurements: NOT MEASURED`

  `Physical switch bounce duration: NOT MEASURED`

  `Tick period derived from verified clock/configuration: 1 ms`

  `Software debounce threshold: 20 ms`

  `Hardware functional behavior: observed on physical NUCLEO-F446RE`

- Known Failures/Limitations:

  `Initial host-test iteration reported 3 failed tests. The implementation was corrected and final host result was 10 tests, 0 failed.`

  `Initial STM32 integration failed to link because systick_init() and get_tick() were not implemented. A SysTick-based monotonic tick source was added and the clean STM32 build then passed.`

  `Initial hardware behavior allowed the first activation but later presses could not toggle LD2 because release state was not being incorporated correctly. EXTI/input handling was corrected so successive active-low press/release transitions could be debounced.`

  `Exact physical C03 vs C04 schematic subrevision remains unresolved.`

  `Exact connector pin numbering, unrelated ST-LINK path details, VDD/VDDA relationship, and power-jumper configuration remain TO VERIFY.`

  `No direct electrical voltage measurement or physical bounce-duration measurement was performed.`

  `Exact flash/debug tool or command remains NOT RECORDED.`

  `The containing commit is represented as SELF — containing commit.`

- Questions:

  `No technical question currently blocks W02D06 artifact closure.`

  `No administrative field remains blocking after END DAY closure.`

## Evidence boundary

- Starter STM32 build success proves infrastructure integrity only.
- Host tests prove only the tested software contract.
- Hardware behavior requires real observation.
- SysTick timing basis was verified from the 16 MHz core clock value and 1 kHz SysTick configuration.
- Schematic conclusions are limited to the explicitly inspected official C03/C04 pages and references.
- Exact physical C03 vs C04 subrevision remains unresolved.
- This assisted normal-learning artifact cannot independently award competency PASS; the fresh Week-2 AI-0 gate remains required.
