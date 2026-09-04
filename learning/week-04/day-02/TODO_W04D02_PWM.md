# TODO — Week 04 / Day 02 — PWM Implementation & UART Shell Adjustment

## Metadata

- Date: `2026-09-04`
- Week/Day: `W04D02`
- Day type: `LEARNING`
- Topic: `PWM generation, duty cycle and frequency adjustment via UART shell`
- Lifecycle: `GREEN / CLOSED / ARTIFACT_PASS`
- Available Focused Time: `Available through 22:30; exact numeric hours not recorded`
- Planned Focused Time: `Work through W04D02 stop condition before 22:30; exact numeric hours not recorded`
- Actual Focused Time: `NOT RECORDED`
- Highest AI level used: `AI-3`
- Reason: `AI-3 occurred only after meaningful learner attempts; learner wrote and tested the core PWM implementation before receiving code-level review/debug guidance. This is NOT independent competency evidence.`
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
- Core clock / HCLK: `16 MHz HSI reset baseline`
- Chosen Timer: `TIM2`
- Timer bus (APB1 or APB2): `APB1`
- Bus prescaler / timer clock frequency: `APB1 prescaler /1, PCLK1 = 16 MHz, TIM2CLK = 16 MHz, counter tick rate = 1 MHz (PSC = 15)`
- Chosen Channel & Pin: `TIM2_CH1 on PA5 (onboard LD2, Arduino D13 / CN5 pin 6)`
- Alternate Function (AF) number for chosen pin: `AF1 (TIM2_CH1)`

## B. Learner PWM Design Decisions

Record your technical design decisions before coding:

- Target default PWM frequency: `1 kHz`
- Target default duty cycle: `50%`
- Timer counting mode: `upcounting edge-aligned`
- Output compare mode: `PWM Mode 1 (OC1M = 110), OC1 preload enabled (OC1PE = 1), ARR preload enabled (ARPE = 1)`
- Output polarity: `active high (CC1P = 0)`
- Frequency range supported by shell: `10 Hz .. 100000 Hz`
- Duty cycle range supported by shell: `0% .. 100%`

## C. Learner PWM Implementation TODO

Implement the register-level configuration in `pwm.c`:

- [x] Enable RCC bus clock for the chosen GPIO port (`RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN`).
- [x] Configure GPIO pin to Alternate Function mode in `MODER` (`MODER5 = 10`).
- [x] Configure the specific AF number in `AFR[0]` (`AF1` on pin 5).
- [x] Configure GPIO output speed (`OSPEEDR` high speed) and pull-up/pull-down (`PUPDR` none) as appropriate.
- [x] Enable RCC bus clock for the chosen timer in `RCC->APBxENR` (`RCC->APB1ENR |= RCC_APB1ENR_TIM2EN`).
- [x] Configure timer prescaler (`PSC = 15`) and auto-reload (`ARR = 999`) for the desired initial 1 kHz frequency.
- [x] Configure capture/compare register (`CCR1 = 500`) for the initial 50% duty cycle.
- [x] Configure PWM mode (`OC1M = 110` PWM Mode 1) and preload (`OC1PE = 1`).
- [x] Enable auto-reload preload (`ARPE = 1` in `CR1`).
- [x] Configure output polarity (active-high) and enable output in `CCER` (`CC1E = 1`).
- [x] Generate an update event (`TIM_EGR_UG`) to load shadow registers.
- [x] Start the counter (`TIM_CR1_CEN`).
- [x] Implement `pwm_set_frequency(uint32_t frequency_hz)` with boundary checks (10 Hz .. 100 kHz) and ratio-preserving CCR recalculation.
- [x] Implement `pwm_set_duty_cycle(uint32_t duty_percent)` with boundary checks (0% .. 100%) and uint64_t overflow-safe arithmetic.
- [x] Implement `pwm_get_frequency()` and `pwm_get_duty_cycle()`.

## D. UART Shell Integration TODO

Integrate PWM adjustment into the shell / parser in `main.c` (or parser module):

- [x] Define command syntax for frequency adjustment: `pwm freq <hz>`.
- [x] Define command syntax for duty cycle adjustment: `pwm duty <percent>`.
- [x] Define command syntax for status/query: `pwm status`.
- [x] Parse argument strings and convert to numerical values (`parse_u32` with uint32 overflow guard).
- [x] Dispatch parsed commands to `pwm_set_frequency()` and `pwm_set_duty_cycle()`.
- [x] Provide clear feedback over UART on success, invalid argument, or out-of-range value.

## E. Build Verification

Build from `firmware/stm32/w04d02-pwm-uart-shell/`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

- [x] Build exit code is `0`.
- [x] Zero compiler errors.
- [x] Zero compiler warnings (only inherited non-blocking `nosys` linker warnings).
- [x] `build/w04d02-pwm-uart-shell.elf`, `.map`, and `.list` generated.
- [x] Record image size: `text = 4876`, `data = 0`, `bss = 1592`, `dec = 6468`, `hex = 1944`.

## F. Hardware Smoke & PWM Demo

- [x] Flash binary to NUCLEO-F446RE.
- [x] Connect oscilloscope / logic analyzer / LED to the configured PWM pin (PA5).
- [x] Open serial terminal at 115200 baud.
- [x] Verify startup banner on terminal (`W04D02 PWM UART Shell Ready`).
- [x] Observe default PWM waveform: verify frequency (~1 kHz) and duty cycle (~50%) physically (`Screenshot_1.png`).
- [x] Send command to change duty cycle (e.g. 25%, 75%): observe physical change.
- [x] Send command to change frequency (500 Hz, 2000 Hz): observe physical period change.
- [x] Record expected vs observed physical measurements (final state 500 Hz / 25%: `Screenshot_2.png`).

## G. Boundary & Error Cases

Test and record at least one boundary/invalid case:

- [x] Out-of-bounds duty cycle (e.g. `pwm duty 101`, `pwm duty abc`, `pwm duty 25x`): verify rejection without crash (`ERR: Invalid duty`).
- [x] Out-of-bounds frequency (e.g. `pwm freq 0`, `pwm freq 9`, `pwm freq 100001`, `pwm freq abc`, `pwm freq 500x`, `pwm freq -100`, `pwm freq 42949672960`): verify rejection (`ERR: Invalid frequency`).
- [x] Malformed or incomplete shell command (`foo`, `pwm`, `pwm xyz 123`): verify parser reports error (`ERR: Unknown command`) and remains responsive.

## H. Evidence & Self-Explanation

- [x] Complete `learning/week-04/day-02/SUBMIT_W04D02.md`.
- [x] Capture physical evidence:
  - `learning/week-04/day-02/Screenshot_1.png` (PulseView default ~1 kHz / 50% PWM)
  - `learning/week-04/day-02/Screenshot_2.png` (PulseView UART-controlled ~500 Hz / 25% PWM)
  - `learning/week-04/day-02/Screenshot_3.png` (VS Code Serial Monitor terminal capture)
- [x] Self-explanation: Explain how `ARR` and `CCR` interact to determine duty cycle percentage:
  `ARR` defines the full PWM period count ($f_{\text{PWM}} = f_{\text{timer}} / ((\text{PSC} + 1) \times (\text{ARR} + 1))$), while `CCR` defines the threshold comparison for the output signal. In upcounting PWM Mode 1 active-high, the output is HIGH while $\text{CNT} < \text{CCR}$ and LOW while $\text{CNT} \ge \text{CCR}$. Thus, $\text{duty} \approx \text{CCR} / (\text{ARR} + 1)$. With fixed PSC and ARR, changing CCR scales the active pulse width without altering the frequency.
- [x] Self-explanation: Explain what happens when `CCR >= ARR` or `CCR == 0`:
  When $\text{CCR} == 0$, $\text{CNT} < 0$ is never true for an unsigned counter, so the output remains constantly LOW (0% duty). When $\text{CCR} \ge \text{ARR} + 1$, $\text{CNT} < \text{CCR}$ is always true throughout the entire counting cycle $0 \dots \text{ARR}$, so the output remains constantly HIGH (100% duty).
- [x] Self-explanation: Explain the role of preload registers (`OCxPE` and `ARPE`) when updating duty/frequency on the fly:
  Preload registers decouple software register writes from active timing. When preload is enabled, writing to ARR or CCR updates only the preload register, while the timer's current cycle continues to run off shadow registers. The newly programmed values transfer to shadow registers synchronously at the next Update Event (UEV, counter rollover), preventing mid-cycle glitches, runt pulses, or distorted periods.

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
Next physical action (5-15 min): BOOT W04D03 — measure PWM frequency and duty against calculations using the logic analyzer and create the annotated PWM capture.
```
