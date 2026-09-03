# TODO — Week 04 / Day 01 — Timer Clock

## Metadata

- Week: `04`
- Day: `01`
- Topic: `Timer clock / PSC / ARR / update event`
- Day type: `LEARNING`
- Available Focused Time: `6h — learner supplied`
- AI mode: `AI-1 / AI-2 for core learning; AI-3 for post-attempt review and debugging`
- Starter status: `READY`
- Learner implementation: `COMPLETED`

## Outcome

Đến cuối ngày, tôi sẽ tự tính và cấu hình được một TIM2 time base từ clock
tree đã xác minh, tạo periodic update interrupt, quan sát timing thực tế và ghi
lại expected/actual trong `timer-calculation-note.md`.

## A. Confirm the actual project clock

- [x] Trace `HCLK -> PCLK1 -> TIM2CLK`.
- [x] Record HCLK: `16 MHz`.
- [x] Record the APB1 prescaler: `/1` (default reset).
- [x] Record PCLK1: `16 MHz`.
- [x] Derive and record TIM2CLK: `16 MHz`.
- [x] Record the actual project clock configuration source: `SystemInit()` in `system_stm32f4xx.c` provides minimal reset clock; `SystemCoreClock = 16000000U`.
- [x] Record the official RM0390 revision and relevant section references: `NOT RECORDED`.

Do not proceed from an assumed tutorial clock.

## B. Calculate the target configuration

Targets:

- counter tick: `1 MHz`
- update event: `1 kHz`

Learner fills:

- [x] `PSC = 15`
- [x] `ARR = 999`
- [x] expected update period: `1 ms`
- [x] expected GPIO square-wave frequency when toggled once/update: `500 Hz`
- [x] derivation recorded in `timer-calculation-note.md`

## C. Implement `timer2_init_1khz()`

Implement at register level. Determine the exact registers, fields, ordering and
values from official sources. Your implementation must account for:

- [x] TIM2 peripheral clock;
- [x] configuration while the counter is stopped;
- [x] prescaler;
- [x] auto-reload;
- [x] initial counter state;
- [x] initial update generation and flag handling;
- [x] update interrupt enable;
- [x] TIM2 NVIC configuration;
- [x] counter enable.

The checklist describes required behavior, not a register-write solution.

## D. Implement `TIM2_IRQHandler()`

- [x] Determine whether an update event occurred.
- [x] Acknowledge/clear the required status correctly.
- [x] Toggle the observation GPIO exactly once per accepted update.
- [x] Do not use `printf`.
- [x] Do not use delay functions.
- [x] Do not busy-wait inside the ISR.

## E. Build

From `firmware/stm32/w04d01-timer-timebase/`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

- [x] Exit code is `0`.
- [x] Review warnings.
- [x] Confirm ELF, map and list artifacts exist.

## F. Flash and hardware smoke

Only after learner implementation and the normal learner-session authorization:

- [x] Flash the exact built artifact.
- [x] Measure the update behavior directly.
- [x] Expected update event: approximately `1 kHz`.
- [x] If GPIO toggles once/update, expected square wave: approximately `500 Hz`.
- [x] Expected GPIO period: approximately `2 ms`.
- [x] Record the actual value and measurement method; do not fabricate results.

## G. Safe negative/reasoning case

- [x] Predict the effect of one reversible ARR change or one wrong APB
      timer-clock assumption.
- [x] Change only one variable if the case is run physically.
- [x] Measure and record the result.
- [x] Restore the intended configuration.

## H. Evidence and explanation

- [x] Complete `timer-calculation-note.md`.
- [x] Complete `SUBMIT_W04D01.md`.
- [x] Explain the difference between counter tick and update event.
- [x] Explain why one toggle per 1 kHz update produces a 500 Hz square wave.

## Boundaries

- No HAL/LL timer initialization that bypasses register reasoning.
- No PWM implementation today; PWM belongs to W04D02.
- No clean-build-only `ARTIFACT_PASS` or `COMPETENCY_PASS` claim.
