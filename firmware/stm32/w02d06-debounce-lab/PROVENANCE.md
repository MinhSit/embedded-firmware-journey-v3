# W02D06 Debounce Lab Provenance

This directory contains AI-assisted, executor-prepared starter and build/vendor
infrastructure for the `NUCLEO-F446RE` / `STM32F446RETx` target. It is a normal
learning scaffold, not independent competency evidence.

## Reused infrastructure

The startup source, linker script, CMSIS/device headers, license texts,
reset-default system stub, and PowerShell build structure were copied
mechanically from the validated
`firmware/stm32/w02d05-exti-nvic-lab/` prerequisite. The lab artifact names in
the build script were adapted for W02D06, and `debounce.c` was added to the
compile/link inputs.

The reused vendor files retain their existing license notices. No build output
from W02D05 was copied. All 16 copied source/infrastructure files matched their
W02D05 source SHA-256 before the bounded W02D06 adaptations.

## Learner ownership boundary

`main.c` preserves the already-validated W02D05 PA5/PC13 EXTI prerequisite,
including its raw-edge LD2 toggle. It intentionally contains no debounce
integration. The public debounce API and context types are executor-prepared;
`debounce.c` is a compile-clean TODO stub with no candidate/stable transition,
threshold decision, or tick-wrap implementation.

The learner owns the core debounce state machine, tick integration, official
schematic derivation, hardware test, debounce log, evidence, and explanation.
Build success proves only that the prepared infrastructure compiles; it does
not prove debounce behavior, hardware behavior, artifact PASS, or competency
PASS.
