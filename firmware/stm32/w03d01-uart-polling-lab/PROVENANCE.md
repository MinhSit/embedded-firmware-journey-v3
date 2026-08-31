# W03D01 UART Polling Lab Provenance

This directory contains AI-assisted, executor-prepared starter and build/vendor
infrastructure for the `NUCLEO-F446RE` / `STM32F446RETx` target. It is a normal
learning scaffold, not independent competency evidence.

## Reused infrastructure

The startup source, linker script, CMSIS/device headers, license texts, and
reset-default system stub were copied mechanically from the validated
`firmware/stm32/w02d06-debounce-lab/` baseline. The PowerShell build structure
was copied and adapted only to compile `uart_polling.c` and produce W03D01-named
ELF, map, and list artifacts. No W02 build output was copied.

The reused vendor files retain their existing license notices. Hash comparison
is part of the executor validation for every mechanically unchanged file.

## Learner ownership boundary

`uart_polling.h` exposes only a small interface. `uart_polling.c` contains
compile-clean TODO stubs; `main.c` is intentionally idle. The starter does not
select the GPIO signal path, configure RCC/GPIO/USART registers, derive or store
a baud-register value, implement polling TX/RX behavior, or claim hardware
output.

The learner owns the clock derivation, official-source verification, GPIO and
USART configuration, baud-divider reasoning, polling implementation, physical
smoke test, observations, evidence, and explanation. Build success proves only
that the prepared infrastructure compiles; it does not prove UART behavior,
hardware behavior, artifact PASS, or competency PASS.
