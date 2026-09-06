# SUBMIT — W04D06 Refactor and Review

## Task

Bounded learner-owned PWM vertical-slice refactor separating board-specific
facts, timer/PWM mechanism, and application composition/policy; documentation,
evidence audit, CMSIS/LL/HAL comparison, and external-review request preparation.
Final result: YELLOW / CLOSED / ARTIFACT_PASS because external review #1 remains
REVIEWER_UNASSIGNED / NOT_SENT. This is not a technical FAIL.

## Date

2026-09-06

Canonical date: 2026-09-05.

## Focused Time

- Available: 6h — learner supplied.
- Planned: 6h — learner supplied.
- Actual: 4h — learner supplied.
- Variance: -2h versus plan; reason NOT SUPPLIED.

## Highest AI Level Used

AI-3 — normal assisted learning. No new competency result.

## Learner-owned refactor summary

Target: `firmware/stm32/w04d02-pwm-uart-shell/`, centered on the PWM path.
Board-specific GPIOA/PA5/AF1, RCC, TIM2 selection, and current timer-clock facts
were placed behind the BSP interface. The PWM driver now receives
`TIM_TypeDef *tim` and `timer_clock_hz`; `main.c` remains the
application/composition root and owns UART shell and failure-response policy.

This is minimal timer-instance injection, currently validated on TIM2 / Channel
1. It is not a fully generic STM32 PWM driver and does not redesign the build
system or UART/parser infrastructure.

## Files Changed

- `firmware/stm32/w04d02-pwm-uart-shell/build.ps1`
- `firmware/stm32/w04d02-pwm-uart-shell/main.c`
- `firmware/stm32/w04d02-pwm-uart-shell/pwm.c`
- `firmware/stm32/w04d02-pwm-uart-shell/pwm.h`
- `firmware/stm32/w04d02-pwm-uart-shell/bsp/bsp_pwm.c`
- `firmware/stm32/w04d02-pwm-uart-shell/bsp/bsp_pwm.h`
- `learning/week-04/day-06/REVIEW_REQUEST_W04D06.md`
- `learning/week-04/day-06/SUBMIT_W04D06.md`
- `learning/week-04/day-06/Screenshot_1.png`
- `learning/week-04/day-06/Screenshot_2.png`
- `learning/week-04/day-06/Screenshot_3.png`
- `learning/week-04/day-06/TODO_W04D06_REFACTOR_REVIEW.md`

## Build Command/Result

Run from `firmware/stm32/w04d02-pwm-uart-shell/`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

PASS / exit `0`; `text=5168`, `data=0`, `bss=1592`, `dec=6760`,
`hex=1a68`. The inherited `nosys` warnings remain: `_close`, `_lseek`, `_read`,
and `_write`.

Pre-refactor baseline: `4876/0/1592/6468 (0x1944)`. Delta: `+292` text
bytes and `0` static-RAM bytes.

## Tests

- Source boundary audit: PASS. `pwm.c` does not reference BSP or hard-code
  `TIM2->`; board facts are in `bsp_pwm.c`; `main.c` has no direct peripheral
  register dereference and owns UART response strings; `build.ps1` compiles and
  links `bsp_pwm.o`.
- Clean build: PASS / exit `0` with the size and inherited warnings above.
- UART exercised regression: learner evidence shows boot/status, valid 25% duty
  command, updated status, and invalid 101% duty rejection.
- Physical PWM measurement: approximately `1.008 kHz` and approximately `25.0%`
  duty for the exercised 25% command.

No regression was observed in the exercised build/UART/PWM cases.

## Evidence

- `learning/week-04/day-06/Screenshot_1.png`: Serial Monitor at 115200 baud;
  boot/status, 25% command/status, and invalid 101% rejection.
- `learning/week-04/day-06/Screenshot_2.png`: D0 period `992.375 us`, reciprocal
  approximately `1.007683587 kHz`.
- `learning/week-04/day-06/Screenshot_3.png`: D0 high time `248.042 us`;
  approximately `25.0%` using the measured period.
- `firmware/stm32/w04d02-pwm-uart-shell/pwm.c`: injected timer mechanism,
  initialization validation, and duty-boundary rejection.
- `firmware/stm32/w04d02-pwm-uart-shell/main.c`: composition and UART policy.
- `firmware/stm32/w04d02-pwm-uart-shell/bsp/bsp_pwm.c`: board mapping and
  timer-clock assumption.
- `firmware/stm32/w04d02-pwm-uart-shell/build.ps1`: BSP build integration.

Serial Monitor functionality is not UART wire-timing evidence.

## CMSIS/LL/HAL comparison summary

The implementation retains CMSIS device definitions and direct-register access
because this task addresses architectural separation rather than register-access
syntax. CMSIS naming/types reduce raw-address mistakes, but the programmer still
owns sequencing, register math, RMW correctness, timing, and validation.

LL offers thin named operations while leaving peripheral sequencing and timing
semantics with the programmer. HAL offers higher-level handle/config/state flows
and can accelerate integration, but can obscure exact register interactions.
Identical LL assembly, universal HAL portability, automatic NVIC/DMA setup, and
universal HAL timeout behavior are not claimed.

## External Review status/link

- Request: `learning/week-04/day-06/REVIEW_REQUEST_W04D06.md`
- Reviewer: UNASSIGNED.
- Status: READY_TO_SEND / REVIEWER_UNASSIGNED / NOT_SENT.
- Sent: NO.
- Feedback received: NO.
- External link: NONE.
- Reason: no mentor, senior, or suitable peer is currently assigned.

## Known limitations

1. Current validation is TIM2 + CH1; generic support for all STM32 timers and
   channels is not claimed.
2. BSP clock value assumes HSI 16 MHz and current APB1 setup; dynamic clock-tree
   adaptation is not implemented.
3. Physical coverage is limited to approximately 1 kHz and observed 50%/25%
   behavior. The full 10 Hz–100 kHz range and every duty boundary were not
   measured on wire.
4. Re-init/de-init lifecycle is not designed or validated. A later failed
   re-init may clear software context while configured hardware remains active.
5. UART wire timing was not measured by the Serial Monitor evidence.

## Open defects

- External human reviewer remains unassigned; the request has not been sent and
  no review feedback exists.
- Re-init/de-init lifecycle behavior remains undesigned and unvalidated.
- No human reviewer has yet assessed the implementation for additional findings.

## P1 UART timing carry-over status

OPEN / UNCHANGED. Correct-baud UART wire timing still requires genuine
logic-analyzer capture or equivalent direct measurement. A physical UART TX
waveform was located and rough bit-scale timing was observed, but the retained
evidence was insufficient for closure. Verified physical baud timing is not
claimed.

## Independent explanation

This work changes internal dependency structure and responsibility boundaries,
not the external feature set. BSP isolates PA5/AF1, RCC, and board-specific TIM2
knowledge. The PWM driver receives the timer instance and clock instead of
hard-coding those facts. Application owns orchestration and user-facing error
policy.

The exercised behavior was regression checked through build, UART interaction,
and physical PWM measurement. No regression was observed in the exercised
build/UART/PWM cases. This is a bounded refactor, not feature work.

## Questions for reviewer

1. Does injecting `(TIM_TypeDef *tim, uint32_t timer_clock_hz)` while retaining
   a static single instance introduce important memory-safety or future
   concurrency risks? The current lab is single-threaded and non-RTOS;
   concurrency is forward-looking.
2. Is a fixed internal 1 MHz timer tick with rejection of clocks not exactly
   divisible by 1 MHz a reasonable accuracy-versus-flexibility trade-off?
3. Is the current ownership split reasonable—BSP enables board-selected
   RCC/peripheral mapping while the driver configures PSC/ARR/CR1/channel
   mechanism—or should the driver own its timer peripheral clock enable?
