# TODO — W04D06 Refactor and Review

## Metadata

- Day: Week 04 / Day 06.
- Topic: Tái cấu trúc vừa đủ và review.
- Status: YELLOW / CLOSED / ARTIFACT_PASS; external review remains NOT SENT.
- Learning mode: normal assisted learning; not a competency gate.
- Available Focused Time: 6h — learner supplied.
- Planned Focused Time: 6h — learner supplied.
- Actual Focused Time: 4h — learner supplied.
- Focused-time variance: -2h versus plan; reason NOT SUPPLIED.
- Highest AI Level Used: AI-3.

## Authoritative roadmap outcome

Complete a learner-owned, appropriately bounded `bsp` / `driver` / `app`
refactor, compare CMSIS / LL / HAL, and prepare external review #1.

## Authoritative required artifact

Repo cleanup + review request.

## AI boundary

- The learner owns the architecture choice, reasoning, dependency boundaries,
  and core refactor implementation.
- AI review/debug is allowed only after a meaningful learner attempt.
- AI-4/AI-5 implementation substitution is not allowed during this work.
- Do not start W04D07 or any competency gate from this task.

## Acceptance checklist

- [x] Refactor target and reason are recorded by the learner.
- [x] Current dependency/data-flow sketch is recorded.
- [x] BSP, driver, and app responsibilities and invariants are learner-authored.
- [x] The chosen refactor remains appropriately bounded.
- [x] Pre-refactor baseline build evidence is retained.
- [x] Post-refactor clean build and exercised regression evidence are recorded.
- [x] CMSIS / LL / HAL comparison is learner-authored.
- [x] Every documented review claim maps to code, build, or capture evidence.
- [x] Referenced repository evidence paths were checked.
- [x] Changed text was checked for obvious secrets and unsupported wording.
- [x] External review request is prepared without inventing a reviewer.
- [x] Known limitations and open requirements are stated truthfully.
- [x] No W04D07 or competency result is created.
- [ ] External review request sent to an eligible human reviewer.
- [ ] Human reviewer feedback received and dispositioned.

## Executor-discovered baseline build commands

From `firmware/stm32/w04d05-hardfault-triage/`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

Preparation baseline: exit `0`; `text=868`, `data=0`, `bss=1616`,
`dec=2484`, `hex=9b4`; inherited `nosys` warnings only.

From `firmware/stm32/w04d02-pwm-uart-shell/`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

Pre-refactor baseline: exit `0`; `text=4876`, `data=0`, `bss=1592`,
`dec=6468`, `hex=1944`; inherited `nosys` warnings only. These preparation
builds prove baseline buildability only, not runtime behavior or competency.

## Learner-owned: chosen refactor target + reason

Chosen target: `firmware/stm32/w04d02-pwm-uart-shell/`.

Primary vertical slice: the PWM path centered on `pwm.c`, with `main.c` as the
application/composition root. The original PWM implementation mixed
board-specific GPIO/clock/pin knowledge, timer mechanism/register math, and
application orchestration. The target is intentionally bounded: it demonstrates
`bsp` / `driver` / `app` boundaries without rewriting UART/parser infrastructure
or building a generic framework.

## Learner-owned: current dependency/data-flow sketch

```text
BSP board facts (TIM2 instance + current timer clock)
    -> main/application composition boundary
    -> PWM driver initialization and mechanism

UART input -> main/application parsing and policy
    -> PWM driver operation -> main/application UART response
```

## Learner-owned: proposed BSP responsibility

- Own Nucleo-F446RE-specific PWM hardware knowledge.
- Own GPIOA / PA5 / AF1 mapping for TIM2_CH1.
- Enable GPIOA and TIM2 peripheral clocks.
- Provide the selected TIM instance and current timer input clock assumption.

## Learner-owned: proposed driver responsibility

- Own timer/PWM mechanism and internal 1 MHz target timer tick.
- Calculate PSC from injected `timer_clock_hz`.
- Own ARR/CCR1 math, PWM Mode 1, Channel 1 preload/polarity/output enable,
  ARPE, update event, counter enable, and frequency/duty set/get mechanism.
- Return status only; do not own CLI/application messaging.

## Learner-owned: proposed app responsibility

- Own UART shell parsing, response policy, and composition/orchestration.
- Call BSP hardware initialization, obtain its timer instance/clock, and inject
  them into `pwm_init()`.
- Decide startup failure policy and format/send `OK` / `ERR` responses.

## Learner-owned: dependency direction/invariants

1. Driver must not include or depend on app.
2. Driver must not include or depend on BSP.
3. Driver/BSP must not contain CLI formatting or application policy.
4. App must not directly dereference/write RCC/GPIO/TIM/USART registers.
5. BSP supplies board facts; main/application injects the timer instance and
   clock into the driver at the composition boundary.

## Learner-owned: CMSIS vs LL vs HAL comparison

### CMSIS / direct-register

The current code uses `stm32f446xx.h` device definitions plus direct register
access. Device headers provide peripheral structures, base addresses, bit masks,
and named fields. The programmer still owns sequencing, register math, RMW
correctness, preload/update-event behavior, timing, and validation. CMSIS
naming/types reduce raw-address mistakes but do not make wrong register values
safe.

### LL

LL adds thin, named, static-inline-style register operations and reduces manual
bit manipulation. The programmer still owns peripheral sequencing, timing math,
interrupt/state behavior, and semantics. LL remains close to the register model;
universally identical generated assembly is not claimed. Migrating W04D06 to LL
would not materially improve the architectural boundaries and would increase
the change surface before the gate.

### HAL

HAL adds higher-level handle/config/state abstractions and standardized flows.
It can improve bring-up speed and consistency, while obscuring exact register
sequence/state interaction. Portability across all STM32 families is not
claimed. HAL is not assumed to configure NVIC/DMA automatically or always
provide timeout behavior. It is useful where integration speed and complex
middleware/peripheral flows dominate; direct-register/LL remains valuable for
explicit register understanding, debugging visibility, or tight control.

W04D06 retains CMSIS/direct-register because the task addresses architectural
separation, not register-access syntax.

## Learner-owned: implementation attempt

Chosen API:

```c
bool pwm_init(TIM_TypeDef *tim, uint32_t timer_clock_hz);
```

Exactly two hardware dependencies are injected. A config struct and CH1–CH4
generic abstraction were not added. This is minimal timer-instance injection,
currently validated on TIM2 / Channel 1; it is not a fully generic STM32 PWM
driver.

BSP supplies `16000000U` under the current HSI/APB1 assumption. The 1 MHz timer
tick is internal driver mechanism, with:

```text
PSC = (timer_clock_hz / target_tick_hz) - 1
```

`pwm_init()` rejects NULL, clocks below 1 MHz, clocks not exactly divisible by
1 MHz, and PSC values beyond the declared limit. `s_tim` is reset to NULL before
validation and assigned only after parameter validation succeeds. Full
de-init/re-init lifecycle safety is not claimed.

Startup order is `uart_init(...)`, `bsp_pwm_hw_init()`, obtain BSP timer/clock,
then `pwm_init(...)`. UART is initialized first as the available diagnostic
channel. If PWM initialization fails, the app emits `ERR: PWM init failed` and
fail-stops before the shell loop.

`build.ps1` was surgically extended with `-Ibsp`, compilation of
`bsp/bsp_pwm.c` to `build/bsp_pwm.o`, and linkage of that object. Existing
startup/parser objects, ELF name, toolchain, and remaining flow were preserved.
This is not a build-system redesign.

## Learner-owned: post-refactor validation

From `firmware/stm32/w04d02-pwm-uart-shell/`:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

Executor verification: PASS / exit `0`; `text=5168`, `data=0`, `bss=1592`,
`dec=6760`, `hex=1a68`. Only the inherited `nosys` warnings for `_close`,
`_lseek`, `_read`, and `_write` remain. Versus the pre-refactor baseline, the
delta is `+292` text bytes and `0` static-RAM bytes.

- `Screenshot_1.png`: 115200-baud Serial Monitor shows boot, 1000 Hz / 50%
  status, valid `pwm duty 25`, later 1000 Hz / 25% status, and rejection of
  `pwm duty 101`.
- `Screenshot_2.png`: D0 period `992.375 us`, reciprocal approximately
  `1.007683587 kHz`.
- `Screenshot_3.png`: D0 high interval `248.042 us`; `248.042 / 992.375` is
  approximately `0.24995`, or `25.0%`.

No regression was observed in the exercised build/UART/PWM cases. This does not
claim exact 1.000 kHz, zero clock error, UART wire timing, or complete behavior
preservation.

## Learner-owned: evidence/claim audit

1. Post-refactor build succeeds: clean build PASS / exit `0`; no new
   compile/link failure; four inherited `nosys` warnings remain.
2. UART shell works for exercised commands: `Screenshot_1.png`.
3. PWM remains approximately 1 kHz: `Screenshot_1.png` software status and
   `Screenshot_2.png` physical measurement.
4. `pwm duty 25` produces approximately 25% duty on wire: command/status in
   `Screenshot_1.png`, period in `Screenshot_2.png`, and high time in
   `Screenshot_3.png`.
5. Invalid 101% duty is rejected at the mechanism/policy boundary: `pwm.c`
   returns false, `main.c` owns the UART error response, and `Screenshot_1.png`
   shows `ERR: Invalid duty`.

## Known limitations / non-claims

1. Current validation is TIM2 + CH1, not all STM32 timers/channels.
2. BSP assumes HSI 16 MHz and current APB1 setup; dynamic clock-tree adaptation
   is not implemented.
3. Physical evidence covers approximately 1 kHz and observed 50%/25% behavior,
   not the full 10 Hz–100 kHz range or every duty boundary.
4. Re-init/de-init lifecycle is not designed or validated. A later failed
   re-init may clear software context while configured hardware remains active.
5. Serial Monitor evidence does not close the UART wire-timing requirement.

## Learner-owned: self-explanation

This work changes internal dependency structure and responsibility boundaries,
not the external feature set. BSP isolates PA5/AF1, RCC, and board-specific TIM2
knowledge. The PWM driver receives the timer instance and clock instead of
hard-coding those facts. Application owns orchestration and user-facing error
policy. No regression was observed in the exercised build/UART/PWM cases. This
is a bounded refactor, not feature work.

## External review status

- Reviewer: UNASSIGNED.
- Request: READY_TO_SEND.
- Sent: NO.
- Feedback received: NO.
- Status: REVIEWER_UNASSIGNED / NOT_SENT.
- Reason: no mentor, senior, or suitable peer is currently assigned.

## P1 carry-over reminder

The Week 3 direct correct-baud UART wire-timing / logic-analyzer evidence remains
OPEN / UNCHANGED. W04D06 evidence does not close or waive it.

## Stop condition

Stop and report if work requires an invented fact, unsupported claim, future
gate answer, AI substitution for learner-owned work, or out-of-scope mutation.

## Next physical action

BOOT W04D07 as a separate transaction after independent closure verification.
Keep the unassigned external-review requirement and UART timing P1 open; do not
start the Foundation MCU gate inside this closure.
