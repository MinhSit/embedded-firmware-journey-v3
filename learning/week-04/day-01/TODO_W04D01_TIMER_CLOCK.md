# TODO — Week 04 / Day 01 — Timer Clock

## Metadata

- Week: `04`
- Day: `01`
- Topic: `Timer clock / PSC / ARR / update event`
- Day type: `LEARNING`
- Available Focused Time: `6h — learner supplied`
- AI mode: `AI-1 / AI-2 for core learning`
- Starter status: `READY`
- Learner implementation: `NOT STARTED`

## Outcome

Đến cuối ngày, tôi sẽ tự tính và cấu hình được một TIM2 time base từ clock
tree đã xác minh, tạo periodic update interrupt, quan sát timing thực tế và ghi
lại expected/actual trong `timer-calculation-note.md`.

## A. Confirm the actual project clock

- [ ] Trace `HCLK -> PCLK1 -> TIM2CLK`.
- [ ] Record HCLK.
- [ ] Record the APB1 prescaler.
- [ ] Record PCLK1.
- [ ] Derive and record TIM2CLK.
- [ ] Record the actual project clock configuration source.
- [ ] Record the official RM0390 revision and relevant section references.

Do not proceed from an assumed tutorial clock.

## B. Calculate the target configuration

Targets:

- counter tick: `1 MHz`
- update event: `1 kHz`

Learner fills:

- [ ] `PSC = ____`
- [ ] `ARR = ____`
- [ ] expected update period: `____`
- [ ] expected GPIO square-wave frequency when toggled once/update: `____`
- [ ] derivation recorded in `timer-calculation-note.md`

## C. Implement `timer2_init_1khz()`

Implement at register level. Determine the exact registers, fields, ordering and
values from official sources. Your implementation must account for:

- [ ] TIM2 peripheral clock;
- [ ] configuration while the counter is stopped;
- [ ] prescaler;
- [ ] auto-reload;
- [ ] initial counter state;
- [ ] initial update generation and flag handling;
- [ ] update interrupt enable;
- [ ] TIM2 NVIC configuration;
- [ ] counter enable.

The checklist describes required behavior, not a register-write solution.

## D. Implement `TIM2_IRQHandler()`

- [ ] Determine whether an update event occurred.
- [ ] Acknowledge/clear the required status correctly.
- [ ] Toggle the observation GPIO exactly once per accepted update.
- [ ] Do not use `printf`.
- [ ] Do not use delay functions.
- [ ] Do not busy-wait inside the ISR.

## E. Build

From `firmware/stm32/w04d01-timer-timebase/`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

- [ ] Exit code is `0`.
- [ ] Review warnings.
- [ ] Confirm ELF, map and list artifacts exist.

## F. Flash and hardware smoke

Only after learner implementation and the normal learner-session authorization:

- [ ] Flash the exact built artifact.
- [ ] Measure the update behavior directly.
- [ ] Expected update event: approximately `1 kHz`.
- [ ] If GPIO toggles once/update, expected square wave: approximately `500 Hz`.
- [ ] Expected GPIO period: approximately `2 ms`.
- [ ] Record the actual value and measurement method; do not fabricate results.

## G. Safe negative/reasoning case

- [ ] Predict the effect of one reversible ARR change or one wrong APB
      timer-clock assumption.
- [ ] Change only one variable if the case is run physically.
- [ ] Measure and record the result.
- [ ] Restore the intended configuration.

## H. Evidence and explanation

- [ ] Complete `timer-calculation-note.md`.
- [ ] Complete `SUBMIT_W04D01.md`.
- [ ] Explain the difference between counter tick and update event.
- [ ] Explain why one toggle per 1 kHz update produces a 500 Hz square wave.

## Boundaries

- No HAL/LL timer initialization that bypasses register reasoning.
- No PWM implementation today; PWM belongs to W04D02.
- No clean-build-only `ARTIFACT_PASS` or `COMPETENCY_PASS` claim.
