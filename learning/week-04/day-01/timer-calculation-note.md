# W04D01 Timer Calculation Note

## Hardware / Clock Context

- Board: NUCLEO-F446RE
- MCU: STM32F446RE (ARM Cortex-M4 @ up to 180 MHz)
- Timer: TIM2 (32-bit general-purpose timer on APB1)
- Actual project SystemCoreClock: 16 MHz
- Actual project clock note: `SystemInit()` in `system_stm32f4xx.c` provides minimal reset-clock infrastructure and does not configure the PLL or clock tree. The MCU runs on the default 16 MHz HSI clock.
- HCLK: 16 MHz
- APB1 prescaler: /1 (reset default)
- PCLK1: 16 MHz
- TIM2CLK: 16 MHz (when APB1 prescaler is /1, the APB timer clock equals PCLK1, so TIM2CLK = 16 MHz)
- Hypothetical 90 MHz example note: The generic textbook/reference configuration assumes max clock (HCLK = 180 MHz, APB1 prescaler = /4 -> PCLK1 = 45 MHz, APB timer x2 multiplier -> TIM2CLK = 90 MHz). This was used for initial calculation drills before discovering the actual project clock configuration.
- Official source: RM0390 (STM32F446xx reference manual) / Section references: NOT RECORDED

## Core Formulas

Timer counter clock frequency:
$$f_{\text{counter}} = \frac{\text{TIMxCLK}}{\text{PSC} + 1}$$

Timer update event frequency:
$$f_{\text{update}} = \frac{f_{\text{counter}}}{\text{ARR} + 1} = \frac{\text{TIMxCLK}}{(\text{PSC} + 1) \times (\text{ARR} + 1)}$$

Update period:
$$T_{\text{update}} = \frac{1}{f_{\text{update}}}$$

GPIO square wave (toggled once per update interrupt):
$$f_{\text{gpio}} = \frac{f_{\text{update}}}{2}$$
$$T_{\text{gpio}} = 2 \times T_{\text{update}}$$

The `+ 1` terms are required because prescaler division by $N$ is encoded by writing $N - 1$ into `PSC`, and an auto-reload period of $M$ counts is encoded by writing $M - 1$ into `ARR` (counting from 0 to $M - 1$).

## Calculation Table

| Target | TIM2CLK | Counter target | PSC | ARR | Expected update frequency | Expected period | Notes |
|---|---|---|---|---|---|---|---|
| 1 kHz update (Hypothetical) | 90 MHz | 1 MHz | 89 | 999 | 1 kHz | 1 ms | Initial calculation drill (assumed 90 MHz TIM2CLK) |
| 10 kHz update (Hypothetical) | 90 MHz | 1 MHz | 89 | 99 | 10 kHz | 100 µs | Calculation drill |
| 100 Hz update (Hypothetical) | 90 MHz | 1 MHz | 89 | 9999 | 100 Hz | 10 ms | Calculation drill |
| 1 kHz update — Option A | 90 MHz | 1 MHz | 89 | 999 | 1 kHz | 1 ms | Better PWM resolution: ARR+1 = 1000 steps (0.1% resolution, e.g. CCR=375 -> 37.5% duty) |
| 1 kHz update — Option B | 90 MHz | 100 kHz | 899 | 99 | 1 kHz | 1 ms | Coarser PWM resolution: ARR+1 = 100 steps (1% resolution) |
| Initial hardware attempt | 16 MHz (actual) | ~177.78 kHz | 89 | 999 | ~177.78 Hz | ~5.625 ms | Initial run with PSC=89: expected GPIO ~88.89 Hz (T_gpio ~11.25 ms); measured ~88.9 Hz |
| Final corrected configuration | 16 MHz (actual) | 1 MHz | 15 | 999 | 1 kHz | 1 ms | Corrected PSC=15 for actual 16 MHz clock: expected GPIO 500 Hz (T_gpio 2 ms); measured ~500 Hz |

## Hardware Experiment

- Expected: GPIO toggle at 500 Hz, period 2 ms, HIGH ~1 ms, LOW ~1 ms, duty ~50%
- Actual: GPIO toggle at approximately 500 Hz, period approximately 2 ms, HIGH approximately 1 ms, LOW approximately 1 ms, duty approximately 50%
- Measurement method: 8-channel USB Logic Analyzer (24 MHz sampling rate, 1 M samples) via PulseView, probing PA5 (NUCLEO-F446RE Green User LED LD2)
- Observed frequency: approximately 500 Hz
- Observed period: approximately 2 ms
- Error: Negligible (within instrument cursor resolution at 1 ms / 2 ms grid)
- Capture/log: `learning/week-04/day-01/Screenshot_1.png`

## Register Observations

- PSC: Set to 15 (`TIM2->PSC = 15U`), dividing 16 MHz by 16 to produce a 1 MHz counter clock (1 µs tick).
- ARR: Set to 999 (`TIM2->ARR = 999U`), producing an update event every 1000 counter ticks (1 ms period).
- CNT: Cleared to 0 (`TIM2->CNT = 0U`) during initialization; counts up from 0 to 999.
- SR/UIF: Direct write `TIM2->SR = ~TIM_SR_UIF` used for clearing UIF in both initialization and ISR. This follows `rc_w0` (read/clear by writing 0) hardware semantics, avoiding read-modify-write (`&= ~TIM_SR_UIF`) which could inadvertently clear other status flags.
- Other registers configured:
  - `RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;` enables APB1 bus peripheral clock for TIM2.
  - `TIM2->CR1 &= ~TIM_CR1_CEN;` ensures counter is disabled during configuration.
  - `TIM2->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS);` sets edge-aligned upcounting mode.
  - `TIM2->EGR = TIM_EGR_UG;` software update generation transfers prescaler value into active shadow register immediately.
  - `TIM2->DIER |= TIM_DIER_UIE;` enables update interrupt.
  - `NVIC_SetPriority(TIM2_IRQn, 2); NVIC_EnableIRQ(TIM2_IRQn);` unmasks TIM2 interrupt in Cortex-M NVIC.
  - `TIM2->CR1 |= TIM_CR1_CEN;` enables counter.
  - `TIM2_IRQHandler`: checks `TIM2->SR & TIM_SR_UIF`, clears UIF via `TIM2->SR = ~TIM_SR_UIF`, and toggles PA5 via `GPIOA->ODR ^= (1U << 5);`.

## Negative / Misconfiguration Case

- Change: Using `PSC = 89` with `ARR = 999` based on the unverified assumption that `TIM2CLK = 90 MHz`.
- Prediction:
  - If TIM2CLK was 90 MHz: $f_{\text{counter}} = 1\text{ MHz}$, $f_{\text{update}} = 1\text{ kHz}$, GPIO = 500 Hz ($T = 2\text{ ms}$).
  - Under actual 16 MHz clock: $f_{\text{counter}} = 16\text{ MHz} / 90 \approx 177.78\text{ kHz}$, $f_{\text{update}} = 177.78\text{ kHz} / 1000 \approx 177.78\text{ Hz}$, GPIO = $177.78 / 2 \approx 88.89\text{ Hz}$, $T_{\text{gpio}} = 1 / 88.89 \approx 11.25\text{ ms}$.
- Observed: Initial PulseView capture showed GPIO frequency $\approx 88.9\text{ Hz}$, period $\approx 11.25\text{ ms}$ with symmetric HIGH/LOW.
- Reason: The mathematical formula was completely sound, but the assumed timer clock input was wrong. The project clock tree ran from the default 16 MHz HSI clock without PLL configuration (`SystemCoreClock = 16000000U`). Recalculating PSC for the actual 16 MHz clock ($PSC = 16\text{ MHz}/1\text{ MHz} - 1 = 15$) immediately resolved the discrepancy and yielded the intended ~500 Hz / ~2 ms square wave.

## What I Can Explain Without AI

- The precise difference between counter tick frequency ($f_{\text{counter}} = \text{TIMxCLK}/(\text{PSC}+1)$) and update event frequency ($f_{\text{update}} = f_{\text{counter}}/(\text{ARR}+1)$).
- Why register values require `+ 1`: `PSC=0` gives division by 1, and `ARR=0` resets every 1 tick.
- Why toggling GPIO once per 1 kHz update event yields a 500 Hz square wave: each toggle represents one state transition (half period), so two update events are required for one full 2 ms period (HIGH + LOW).
- Why higher ARR with lower PSC is advantageous for PWM: with ARR=999 we have 1000 discrete compare steps (0.1% resolution), whereas ARR=99 provides only 100 steps (1% resolution).
- Why `rc_w0` registers require direct write (`TIM2->SR = ~TIM_SR_UIF`) instead of read-modify-write (`TIM2->SR &= ~TIM_SR_UIF`): RMW reads current flags and writes them back, potentially clearing flags that hardware set between the read and the write.

## Still Unclear

- None blocking Day 1 time-base fundamentals. Advanced master/slave timer synchronization and DMA burst trigger mechanisms will be addressed in future roadmap days.

## Known Limitation

- The project currently runs on the default 16 MHz internal RC oscillator (HSI) without PLL configuration.
- GPIO toggle is performed via software ISR (`TIM2_IRQHandler`), which incurs Cortex-M interrupt entry/exit latency and small software jitter compared to hardware timer compare output (OC / PWM).

## Next Action

- BOOT W04D02 — Implement PWM output on a timer capture/compare channel using the validated timer clock and ARR/CCR mental model.
