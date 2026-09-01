# W04D01 Timer Time-Base Starter Provenance

This directory is AI-assisted, executor-prepared learning infrastructure for
the `NUCLEO-F446RE` / `STM32F446RETx` target. It is not independent competency
evidence.

## Reused infrastructure

The startup source, linker script, CMSIS/device headers, license texts, reset
clock baseline, and PowerShell build structure were reused from the repository's
known-good `firmware/stm32/w02d03-gpio-lab/`. The same startup, linker, system,
CMSIS, and license files are also used by the current Week 3 STM32 baseline.
Only the build artifact names and compilation of the new TODO module were added.

The PA5/LD2 GPIO observation setup is the minimum already-established Week 2
boilerplate. The starter drives it to a defined inactive state and does not
produce timer-driven output.

## Learner ownership boundary

`timer_timebase.c` contains compile-clean no-op TODO stubs. The executor supplied
no TIM2 PSC, ARR, CNT, EGR/UG, SR/UIF, DIER/UIE, NVIC, CEN, working ISR, GPIO
toggle, or PWM implementation. The learner must verify the clock tree and
official RM0390 details, then independently implement and explain the time base
and interrupt behavior.

A clean starter build proves infrastructure integrity only. It does not prove
timer behavior, hardware measurement, `ARTIFACT_PASS`, or `COMPETENCY_PASS`.
