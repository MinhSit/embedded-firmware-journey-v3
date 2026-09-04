# TODO — Week 04 / Day 02 — PWM Implementation & UART Shell Adjustment

## Metadata

- Date: `2026-09-04`
- Week/Day: `W04D02`
- Day type: `LEARNING`
- Topic: `PWM generation, duty cycle and frequency adjustment via UART shell`
- Lifecycle: `NOT STARTED`
- Available Focused Time: `[TODO: learner fill, e.g. 6h]`
- Planned Focused Time: `[TODO: learner fill, e.g. 6h]`
- Actual Focused Time: `[TODO: learner fill at close]`
- Highest AI level used: `[TODO: learner record at close, max AI-3 after attempt]`
- Latest independent competency: `W03-C-UART-FOUND — COMPETENCY_PASS`

## Outcome

Create a hardware PWM signal on a timer capture/compare channel and allow duty
cycle and frequency adjustment from the existing UART-shell foundation. Verify
the PWM signal physically, record expected versus observed behavior, and test at
least one boundary/invalid case.

> [!NOTE]
> **W04D02 vs W04D03 Boundary:**
> W04D02 requires enough physical observation to confirm the PWM demo works
> (signal presence, frequency change, duty adjustment). Detailed annotated
> multi-point logic-analyzer characterization, duty linearity analysis, and deep
> clock discrepancy breakdown belong to W04D03. Do not front-load W04D03 scope
> into today.

## A. Hardware & Clock Facts to Verify

Verify these facts from official project sources (RM0390 reference manual,
STM32F446xx datasheet, `system_stm32f4xx.c`) before implementing.

- MCU: `STM32F446RE` / Board: `NUCLEO-F446RE`
- Core clock / HCLK: `[TODO: verify from system_stm32f4xx.c — e.g. 16 MHz HSI reset baseline]`
- Chosen Timer: `[TODO: learner choose e.g. TIM2, TIM3, or TIM4]`
- Timer bus (APB1 or APB2): `[TODO: learner verify bus connection]`
- Bus prescaler / timer clock frequency: `[TODO: learner verify timer clock, e.g. APB1 timer clock]`
- Chosen Channel & Pin: `[TODO: learner identify pin and channel from datasheet pinout]`
- Alternate Function (AF) number for chosen pin: `[TODO: learner verify from datasheet alternate function table]`

## B. Learner PWM Design Decisions

Record your technical design decisions before coding:

- Target default PWM frequency: `[TODO: e.g. 1 kHz]`
- Target default duty cycle: `[TODO: e.g. 50%]`
- Timer counting mode: `[TODO: upcounting edge-aligned / center-aligned]`
- Output compare mode: `[TODO: PWM Mode 1 or PWM Mode 2, preload enabled/disabled]`
- Output polarity: `[TODO: active high / active low]`
- Frequency range supported by shell: `[TODO: min Hz .. max Hz]`
- Duty cycle range supported by shell: `[TODO: e.g. 0% .. 100%]`

## C. Learner PWM Implementation TODO

Implement the register-level configuration in `pwm.c`:

- [ ] Enable RCC bus clock for the chosen GPIO port.
- [ ] Configure GPIO pin to Alternate Function mode in `MODER`.
- [ ] Configure the specific AF number in `AFR[0]` or `AFR[1]`.
- [ ] Configure GPIO output speed (`OSPEEDR`) and pull-up/pull-down (`PUPDR`) as appropriate.
- [ ] Enable RCC bus clock for the chosen timer in `RCC->APBxENR`.
- [ ] Configure timer prescaler (`PSC`) and auto-reload (`ARR`) for the desired initial frequency.
- [ ] Configure capture/compare register (`CCR`) for the initial duty cycle.
- [ ] Configure PWM mode (e.g. OCxM bits in `CCMRx`) and preload (`OCxPE`).
- [ ] Enable auto-reload preload (`ARPE` in `CR1`) if desired.
- [ ] Configure output polarity and enable output in `CCER` (e.g. `CCxE`).
- [ ] Generate an update event (`TIM_EGR_UG`) to load shadow registers.
- [ ] Start the counter (`TIM_CR1_CEN`).
- [ ] Implement `pwm_set_frequency(uint32_t frequency_hz)` with boundary checks.
- [ ] Implement `pwm_set_duty_cycle(uint32_t duty_percent)` with boundary checks.
- [ ] Implement `pwm_get_frequency()` and `pwm_get_duty_cycle()`.

## D. UART Shell Integration TODO

Integrate PWM adjustment into the shell / parser in `main.c` (or parser module):

- [ ] Define command syntax for frequency adjustment: `[TODO: e.g. pwm freq <hz>]`.
- [ ] Define command syntax for duty cycle adjustment: `[TODO: e.g. pwm duty <percent>]`.
- [ ] Define command syntax for status/query: `[TODO: e.g. pwm status or status]`.
- [ ] Parse argument strings and convert to numerical values.
- [ ] Dispatch parsed commands to `pwm_set_frequency()` and `pwm_set_duty_cycle()`.
- [ ] Provide clear feedback over UART on success, invalid argument, or out-of-range value.

## E. Build Verification

Build from `firmware/stm32/w04d02-pwm-uart-shell/`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

- [ ] Build exit code is `0`.
- [ ] Zero compiler errors.
- [ ] Zero compiler warnings (only inherited non-blocking `nosys` linker warnings).
- [ ] `build/w04d02-pwm-uart-shell.elf`, `.map`, and `.list` generated.
- [ ] Record image size (`text`, `data`, `bss`).

## F. Hardware Smoke & PWM Demo

- [ ] Flash binary to NUCLEO-F446RE.
- [ ] Connect oscilloscope / logic analyzer / LED to the configured PWM pin.
- [ ] Open serial terminal at 115200 baud.
- [ ] Verify startup banner on terminal.
- [ ] Observe default PWM waveform: verify frequency and duty cycle physically.
- [ ] Send command to change duty cycle (e.g. 25%, 75%): observe physical change.
- [ ] Send command to change frequency: observe physical period change.
- [ ] Record expected vs observed physical measurements.

## G. Boundary & Error Cases

Test and record at least one boundary/invalid case:

- [ ] Out-of-bounds duty cycle (e.g. > 100% or negative/malformed): verify rejection without crash.
- [ ] Out-of-bounds frequency (e.g. 0 Hz, too high for timer resolution, or overflow): verify rejection.
- [ ] Malformed or incomplete shell command: verify parser reports error and remains responsive.

## H. Evidence & Self-Explanation

- [ ] Complete `learning/week-04/day-02/SUBMIT_W04D02.md`.
- [ ] Capture physical evidence (logic analyzer screenshot, scope trace, or terminal log).
- [ ] Self-explanation: Explain how `ARR` and `CCR` interact to determine duty cycle percentage.
- [ ] Self-explanation: Explain what happens when `CCR >= ARR` or `CCR == 0`.
- [ ] Self-explanation: Explain the role of preload registers (`OCxPE` and `ARPE`) when updating duty/frequency on the fly.

## AI Rules

- `AI-1 / AI-2` for conceptual clarification and guided hints.
- `AI-3` only after an independent learner attempt with visible code/error.
- Strictly forbidden: pasting full PWM solutions, copying external vendor driver snippets without understanding, or generating gate answers.

## Forbidden Shortcuts

- Do not use STM32Cube HAL/LL PWM functions (`HAL_TIM_PWM_Init`, etc.). Implementation must be direct register-level to build deep mental models.
- Do not hard-code assumed clock speeds without checking `system_stm32f4xx.c`.
- Do not skip physical observation on hardware.

## Stop Condition

1. Clean build confirmed.
2. PWM demo exists: signal observed physically and controllable via UART shell.
3. Expected vs actual measurements recorded.
4. At least one boundary/invalid case tested.
5. Remaining questions or issues documented.
6. Exactly one next physical action (5–15 minutes) written.

## Next Physical Action Placeholder

```
Next physical action (5-15 min): [TODO: learner fill, e.g. Open STM32F446RE datasheet Table 10 to select timer channel pin and AF mapping]
```
