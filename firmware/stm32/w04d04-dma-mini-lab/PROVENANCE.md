# W04D04 DMA Mini-Lab Provenance

This directory contains AI-assisted learning infrastructure and learner-owned
DMA implementation for the `NUCLEO-F446RE` / `STM32F446RETx` target. It is
normal learning evidence, not independent competency evidence.

## Reused infrastructure

The startup source, linker script, reset clock baseline, CMSIS/device headers,
and license texts were copied mechanically from the repository's existing
`firmware/stm32/w04d01-timer-timebase/` build baseline. Cowork adapted the
PowerShell build structure only to compile the W04D04 module and name its build artifacts.

## Role separation

Cowork generated the neutral start-day scaffold before learner implementation.
At END DAY it validated the build/evidence, performed authorized mechanical
trailing-whitespace cleanup, and updated closure records. It did not rewrite,
refactor, optimize, or replace learner logic.

The learner owned the DMA reasoning, register configuration, implementation
attempts, debugging, hardware execution, success-case observation, prediction
and execution of the intentional `MINC=0` negative case, and restoration of
`MINC=1` in final source.

Project Chat supplied theory and pre-check, then AI-3 post-attempt review,
debugger guidance, and evidence interpretation. Highest assistance for W04D04
was AI-3. No AI-0 gate occurred and no competency was awarded.

## Final artifact boundary

The artifact is a bounded DMA2 memory-to-memory normal-mode mini-lab using
hard-coded static SRAM buffers, polling completion, 32-bit widths, FIFO mode,
and a four-item transfer. It does not claim interrupt-driven DMA, circular-mode
implementation, production-ready architecture, UART/ADC DMA, HAL, or LL.

The public request parameter remains unused. After the result snapshot, the
source leaves `HTIF` for the next invocation's initial full Stream 0 flag clear.
These are recorded lab characteristics, not hidden production claims.

The clean build and debugger screenshots support `ARTIFACT_PASS` only. They do
not establish `COMPETENCY_PASS`.
