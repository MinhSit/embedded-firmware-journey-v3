# W03D02 USART2 RX Interrupt Lab Provenance

This directory is an AI-assisted, executor-prepared starter for
`NUCLEO-F446RE` / `STM32F446RETx`. It is normal-learning infrastructure, not
independent competency evidence.

## Mechanically reused infrastructure

The startup source, linker script, CMSIS/device headers, license texts, and
reset-default system stub were copied mechanically from the validated
`firmware/stm32/w03d01-uart-polling-lab/` closure at commit
`a7e40583d5a3a14f0269ffdd3d7c2cee79feb605`. The PowerShell build structure was
copied and adapted only to emit W03D02-named ELF, map, and list artifacts. No
generated build output was copied.

## Prior learner work

`uart_polling.h` and `uart_polling.c` preserve the learner-written W03D01 UART
polling implementation as the prior-day technical baseline. They were copied
without semantic changes. This reuse does not turn that prior work into a
W03D02 interrupt solution.

## Executor-created starter content

`main.c` is a compile-clean, intentionally idle entry point with one learner
TODO. `TODO_W03_D02.md`, `SUBMIT_W03_D02.md`, this provenance record, and the
W03D02 artifact-name changes in `build.ps1` are executor-created preparation.
No interrupt-specific source module or final public API was imposed.

## Learner ownership boundary at starter preparation

The starter does not enable USART2 receive interrupts, configure the NVIC,
define `USART2_IRQHandler`, consume receive state in an ISR, choose a shared-
state protocol, implement foreground consumption or interrupt-driven echo, or
select an overflow/overrun recovery policy. It supplies no ring buffer, DMA,
HAL, or LL implementation.

The learner owns official-source verification, interrupt configuration, handler
and shared-state design, physical smoke test, debugging, observations, evidence,
and explanation. A clean starter build proves infrastructure only; it does not
prove IRQ behavior, hardware behavior, `ARTIFACT_PASS`, or `COMPETENCY_PASS`.

## Learner-completed W03D02 artifact

After the starter was prepared, the learner implemented the W03D02 receive path
in `uart_polling.c`, updated `main.c` for foreground mailbox consumption and
polling transmit echo, and retained the public interface in `uart_polling.h`.
The learner-owned implementation enables USART2 RXNE interrupts, configures
`USART2_IRQn`, defines `USART2_IRQHandler`, and uses a bounded single-byte
mailbox shared between the ISR and foreground. The mailbox has depth 1; burst
traffic may overwrite or drop data. Ring buffer, DMA, HAL, and LL integration
remain intentionally outside W03D02.

The learner performed the physical COM4 IRQ/echo demo, debugger/register
inspection, controlled ORE experiment, SR-to-DR recovery, and post-recovery
echo. Project Chat provided AI-3 review/debug assistance only after learner-first
implementation attempts. Evidence is recorded in
`learning/week-03/day-02/SUBMIT_W03_D02.md` and `Screenshot_1.png` through
`Screenshot_4.png`.

The final clean build passed with exit 0 and size `1420/0/1568/2988/bac`, with
only the inherited non-blocking `nosys` warnings for `_close`, `_lseek`, `_read`,
and `_write`. END DAY closure records `W03D02 GREEN / CLOSED / ARTIFACT_PASS`.
This normal-learning artifact creates no new competency result.
