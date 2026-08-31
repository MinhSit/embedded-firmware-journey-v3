# W03D04 Non-blocking UART Parser Lab Provenance

This directory is AI-assisted, executor-prepared normal-learning
infrastructure for `NUCLEO-F446RE` / `STM32F446RETx`. It is not independent
competency evidence.

## Reused learner-owned baseline

The completed W03D03 lab was copied as the behavioral and build baseline from
commit `b66bb46cff11057a97da46628ca5167bc6e8bbaa`. Startup, linker,
CMSIS/device headers, license texts, reset-clock infrastructure, and the
learner-owned W03D03 UART/ring-buffer implementation were preserved. Generated
build output was not retained.

The build script is adapted only for W03D04 artifact names and compilation of
the parser TODO stub. The copied firmware remains the known W03D03 UART echo
baseline; command-action integration is intentionally not implemented here.

## Executor-created starter content

`uart_parser.h` declares a small hardware-independent API, explicit bounded
state, result types, and the documented starter contract. `uart_parser.c`
contains compile-clean non-working TODO stubs. The visible deterministic host
tests are normal-learning infrastructure. The initial host executable is
expected to report behavioral failures until the learner implements the parser.

## Learner ownership boundary

The learner owns line accumulation, command recognition, argument and numeric
parsing, timeout transitions, CR/LF handling, overlong-line resynchronization,
parser state recovery, command dispatch/integration, invariant explanation,
host results, and any later hardware evidence. No working parser transition or
command-recognition logic is present in this starter.

A clean starter build proves infrastructure integrity only. It does not prove
parser behavior, UART hardware behavior, `ARTIFACT_PASS`, or
`COMPETENCY_PASS`.
