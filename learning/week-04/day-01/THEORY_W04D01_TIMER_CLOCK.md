# Theory — W04D01 Timer Clock

## Core mental model

```text
TIMxCLK -> PSC -> counter tick -> CNT -> ARR -> update event
```

- `TIMxCLK` is the timer peripheral input clock.
- `PSC` divides that clock before it advances `CNT`.
- `CNT` is the running counter.
- `ARR` defines the period boundary for an up-counting time base.
- An update event marks the timer period boundary and may request an interrupt
  when the corresponding interrupt path is configured.
- `CCR` is a compare/capture value. For Day 1, understand its conceptual role;
  PWM configuration belongs to W04D02.

## Core relationships

```text
f_counter = TIMxCLK / (PSC + 1)

f_update = TIMxCLK / ((PSC + 1) * (ARR + 1))
```

The `+ 1` terms matter because the programmed register values encode a division
or count range one less than the human-readable amount.

`counter tick` and `update event` are not synonyms. The counter may advance many
times before one update event occurs.

## APB timer clock checkpoint

Do not assume that `TIM2CLK` always equals `PCLK1`. Trace the active clock tree
and confirm the APB timer-clock rule, APB1 prescaler, and actual project clock
configuration against RM0390 and the project source before calculating `PSC`
and `ARR`.

## Observation relationship

If a GPIO changes state exactly once for every 1 kHz update event, a full square
wave needs two updates. The expected square-wave frequency is therefore 500 Hz,
with an expected period of about 2 ms.

## Facts to verify in RM0390

Before implementation, locate and record the exact RM0390 revision and sections
for:

- RCC clock enable and APB1 timer clock derivation;
- TIM2 prescaler, auto-reload, counter, event-generation, status and interrupt
  registers;
- update interrupt behavior and the applicable NVIC/vector path.

This note intentionally contains no TIM2 register-write sequence.
