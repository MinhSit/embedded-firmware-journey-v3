# W02D03 GPIO Lab Provenance

This directory is AI-assisted, executor-prepared learning infrastructure for
the `NUCLEO-F446RE` / `STM32F446RETx` target. It is not independent competency
evidence.

## Reused infrastructure

The startup source, linker script, CMSIS/device headers, license texts, and
PowerShell build structure were reused from the repository's known-good
`firmware/stm32/w02d02-startup-lab/`. The build artifact names were adapted for
this lab. `system_stm32f4xx.c` is a bounded reset-default stub sufficient for
the clean starter build; it intentionally performs no RCC/GPIO configuration.

The reused vendor files retain their existing license notices. Their source
identity and original provenance remain documented in the W02D02 lab.

## Learner ownership boundary

The RCC/GPIO core implementation is intentionally absent. The learner must
independently verify the official device/board sources and fill the marked
implementation in `main.c`. No HAL/LL initialization or hidden reference
solution is included.

A compile-clean scaffold proves only that the startup/build infrastructure is
usable. It does not prove GPIO behavior, hardware operation, artifact PASS, or
competency PASS.
