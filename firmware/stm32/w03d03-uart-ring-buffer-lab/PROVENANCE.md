# W03D03 UART RX Ring Buffer Lab Provenance

This directory is AI-assisted, executor-prepared normal-learning
infrastructure for `NUCLEO-F446RE` / `STM32F446RETx`. It is not independent
competency evidence.

## Mechanically reused baseline

The W03D02 lab was copied as the behavioral and build baseline from commit
`d24e12557bfe0e31f8e424b7291b30acc5e9c733`. Startup, linker, CMSIS/device
headers, license texts, reset-clock infrastructure, and the completed W03D02
USART2 source were preserved mechanically. The build script was adapted only
for W03D03 artifact names and compilation of the new starter module. Generated
build output was not retained.

The copied UART path intentionally still uses the W03D02 depth-1 mailbox. That
documented limitation is the W03D03 starting point, not a ring-buffer solution.

## Executor-created starter content

`rx_ring_buffer.h` declares a small fixed-size API and explicit state storage.
`rx_ring_buffer.c` contains compile-clean non-working stubs and learner TODOs.
`tests/host/test_w03d03_rx_ring_buffer.c` is visible deterministic learning
infrastructure. The initial host executable is expected to report behavioral
failures until the learner implements the core state transitions.

## Learner ownership boundary

The learner owns push, pop, full/empty, wrap, failed-operation preservation,
overflow counting, the selected bounded overflow policy, USART2 ISR/foreground
integration, invariant explanation, host results, hardware evidence, and final
policy justification. No working transition logic or policy implementation is
present in this starter.

A clean starter build proves infrastructure integrity only. It does not prove
ring-buffer behavior, UART hardware behavior, `ARTIFACT_PASS`, or
`COMPETENCY_PASS`.
