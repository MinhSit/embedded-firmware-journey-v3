# W02D05 EXTI/NVIC Lab Provenance

This directory contains AI-assisted, executor-prepared starter and build/vendor
infrastructure for the `NUCLEO-F446RE` / `STM32F446RETx` target. It is a normal
learning scaffold, not independent competency evidence.

## Reused infrastructure

The startup source, linker script, CMSIS/device headers, license texts,
reset-default system stub, and PowerShell build structure were copied
mechanically from the verified
`firmware/stm32/w02d04-gpio-input-lab/` infrastructure. Only the lab artifact
names in the build script were adapted for W02D05.

The reused vendor files retain their existing license notices. No build output
from W02D04 was copied.

## Learner ownership boundary

The starter preserves only the already-learned PA5 output and PC13 input
baseline. It does not configure SYSCFG-to-EXTI routing, an EXTI trigger or mask,
NVIC enable/priority, pending-clear behavior, or a functional ISR. The startup
file's weak/default vector behavior is unchanged until the learner defines the
required handler.

The learner owns the core implementation, official-source derivation, hardware
test, failure case, evidence, and explanation. Build success proves only that
the prepared infrastructure compiles; it does not prove interrupt behavior,
artifact PASS, or competency PASS.
