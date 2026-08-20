# W02D04 GPIO Input Lab Provenance

This directory contains AI-assisted, executor-prepared starter and build/vendor
infrastructure for the `NUCLEO-F446RE` / `STM32F446RETx` target. It is not
independent competency evidence.

## Reused infrastructure

The startup source, linker script, CMSIS/device headers, license texts,
reset-default system stub, and PowerShell build structure were copied
mechanically from the verified
`firmware/stm32/w02d03-gpio-lab/` infrastructure. Only the lab artifact names
were adapted for W02D04.

The reused vendor files retain their existing license notices. Their source
identity and original provenance remain documented in the W02D02/W02D03 labs.

## Learner ownership boundary

The core W02D04 implementation is intentionally absent. The learner must use
the exact board documentation, schematic, MCU datasheet, and reference manual
to derive and implement the GPIO input/output logic.

The following remain learner-owned: input port/pin selection, RCC clock
configuration, MODER/PUPDR configuration, IDR reading, ODR read-modify-write
comparison code, BSRR code, and input-to-output behavior.

This starter includes no gate answer. A compile-clean scaffold proves only that
the inherited build infrastructure is usable; it does not prove hardware
operation, artifact PASS, or competency PASS.
