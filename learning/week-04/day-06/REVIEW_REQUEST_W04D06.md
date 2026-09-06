# External Review Request — W04D06

## Review scope

Please review:

1. the `bsp` / `driver` / `app` boundary and dependency invariants;
2. timer/PWM mechanism and math, including PSC, ARR, CCR1, rounding, preload,
   and update sequence;
3. driver state management and application startup failure handling.

## Commit/branch

- Branch: `feature/w04d06-refactor-review`
- Commit: `SELF — containing closure commit`

## What changed

- Board-specific GPIOA/PA5/AF1, RCC, TIM2 selection, and current 16 MHz timer
  clock assumption were isolated in `bsp/bsp_pwm.c`.
- `pwm_init()` now receives `TIM_TypeDef *tim` and `timer_clock_hz` at the
  application composition boundary.
- The PWM driver retains internal timer/PWM mechanism and a fixed 1 MHz target
  tick; it returns status without owning CLI messages.
- `main.c` initializes UART first, performs BSP/application composition, and
  fail-stops with `ERR: PWM init failed` if driver initialization fails.
- `build.ps1` was surgically extended to include, compile, and link the BSP
  source/object. This is not a build-system redesign.

Accurate scope claim: minimal timer-instance injection, currently validated on
TIM2 / Channel 1. This is not a fully generic STM32 PWM driver.

## Explicit non-goals

- Detailed UART/ring-buffer/parser review.
- Multi-timer or multi-channel framework.
- LL/HAL migration.
- Production HAL-style driver framework.
- Closing the open Week 3 UART wire-timing P1.

## Build/test evidence

Clean build from `firmware/stm32/w04d02-pwm-uart-shell/`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

Result: PASS / exit `0`; `text=5168`, `data=0`, `bss=1592`, `dec=6760`,
`hex=1a68`. No new compile/link failure was observed. The inherited `nosys`
warnings for `_close`, `_lseek`, `_read`, and `_write` remain.

Pre-refactor baseline: `4876/0/1592/6468 (0x1944)`. Delta: `+292` text
bytes and `0` static-RAM bytes.

No regression was observed in the exercised build/UART/PWM cases. This is not
a claim of exact 1.000 kHz, zero clock error, UART wire timing, or complete
behavioral coverage.

## Evidence links

- Build integration: `firmware/stm32/w04d02-pwm-uart-shell/build.ps1`
- Application composition/policy: `firmware/stm32/w04d02-pwm-uart-shell/main.c`
- PWM mechanism/duty rejection: `firmware/stm32/w04d02-pwm-uart-shell/pwm.c`
- PWM interface: `firmware/stm32/w04d02-pwm-uart-shell/pwm.h`
- Board mapping/clock assumption:
  `firmware/stm32/w04d02-pwm-uart-shell/bsp/bsp_pwm.c`
- BSP interface: `firmware/stm32/w04d02-pwm-uart-shell/bsp/bsp_pwm.h`
- UART exercised commands: `learning/week-04/day-06/Screenshot_1.png`
- Physical period/frequency: `learning/week-04/day-06/Screenshot_2.png`
- Physical high time: `learning/week-04/day-06/Screenshot_3.png`

Claim map:

1. Clean build PASS: build command/result above.
2. UART shell works for exercised commands: `Screenshot_1.png`.
3. PWM is approximately 1 kHz: software status in `Screenshot_1.png` and
   measured `992.375 us` / approximately `1.007683587 kHz` in
   `Screenshot_2.png`.
4. `pwm duty 25` produces approximately 25% physical duty: command/status in
   `Screenshot_1.png`, period in `Screenshot_2.png`, and `248.042 us` high time
   in `Screenshot_3.png` (approximately `25.0%`).
5. Invalid 101% duty is rejected: `pwm.c` returns false above 100, `main.c`
   owns the UART response, and `Screenshot_1.png` shows `ERR: Invalid duty`.

## Questions for reviewer

1. Does injecting `(TIM_TypeDef *tim, uint32_t timer_clock_hz)` and retaining a
   static single instance introduce important memory-safety or future
   concurrency risks? Concurrency is forward-looking; the current lab is
   single-threaded and non-RTOS.
2. Is keeping an internal fixed 1 MHz timer tick and rejecting timer clocks not
   exactly divisible by 1 MHz a reasonable accuracy-versus-flexibility
   trade-off for this bounded driver?
3. For production-quality bare-metal/CMSIS design, is the current ownership
   split reasonable—BSP enables board-selected RCC/peripheral mapping while the
   driver configures PSC/ARR/CR1/channel mechanism—or should the driver own its
   timer peripheral clock enable?

## Findings

### BLOCKER

PENDING HUMAN REVIEW — no finding recorded.

### HIGH

PENDING HUMAN REVIEW — no finding recorded.

### MEDIUM

PENDING HUMAN REVIEW — no finding recorded.

### LOW

PENDING HUMAN REVIEW — no finding recorded.

## Reviewer identity

UNASSIGNED

## Review date

NOT SET

## Review status

- Request: READY_TO_SEND.
- Reviewer: UNASSIGNED.
- Sent: NO.
- Feedback received: NO.
- Status: REVIEWER_UNASSIGNED / NOT_SENT.
- Reason: no mentor, senior, or suitable peer is currently assigned.
