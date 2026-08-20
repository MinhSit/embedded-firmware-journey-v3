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

## Final learning-session provenance

Highest AI level used for W02D04: `AI-5`.

During the assisted learning session, AI provided extensive theory instruction
and later complete/reference-level core GPIO code snippets after iterative
learner attempts. The learner required substantial theory teaching and
iterative review; the final artifact is not independent competency evidence.

The learner personally performed substantial reasoning and implementation
attempts, corrected multiple register/mask mistakes interactively, and carried
out the multimeter measurement, build, flash, button/LED hardware tests,
ODR/BSRR comparison, negative case, restoration, and logic-analyzer capture.

This artifact may receive `ARTIFACT_PASS` when its build and evidence contract
is satisfied. It creates no competency PASS. The normal fresh Week 2 AI-0
competency gate remains required.
