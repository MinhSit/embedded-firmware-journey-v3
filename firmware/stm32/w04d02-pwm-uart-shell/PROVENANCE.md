# W04D02 PWM + UART Shell Starter Provenance

This directory contains AI-assisted, executor-prepared normal-learning starter
infrastructure for `NUCLEO-F446RE` / `STM32F446RETx`. It is not independent
competency evidence.

## Reused Baseline Files

The following files were copied faithfully from existing closed repository baselines:

1. Reused from `firmware/stm32/w04d01-timer-timebase/` (commit `2135616273d82b44a871533409e1eba39a2981f9`):
   - `STM32F446RETX_FLASH.ld` (Linker script for STM32F446RETx)
   - `startup_stm32f446retx.s` (Reset and vector table assembly)
   - `system_stm32f4xx.c` (Minimal reset clock / SystemCoreClock initialization)
   - `include/core_cm4.h` (CMSIS Cortex-M4 core header)
   - `include/cmsis_version.h` (CMSIS version header)
   - `include/cmsis_compiler.h` (CMSIS compiler abstraction)
   - `include/cmsis_gcc.h` (CMSIS GCC specific intrinsics)
   - `include/mpu_armv7.h` (CMSIS MPU definitions)
   - `include/stm32f446xx.h` (Device peripheral register definitions)
   - `include/stm32f4xx.h` (Top-level device selection header)
   - `include/system_stm32f4xx.h` (System initialization declarations)
   - `licenses/CMSIS_LICENSE.txt` (ARM CMSIS license)
   - `licenses/STM32F4xx_DEVICE_LICENSE.txt` (ST device header license)

   *Verification:* Verified 100% byte identical to source files in `firmware/stm32/w04d01-timer-timebase/`.

2. Reused from `firmware/stm32/w03d04-uart-parser-lab/` (commit `2135616273d82b44a871533409e1eba39a2981f9`):
   - `rx_ring_buffer.h` (W03D03/W03D04 ring buffer interface)
   - `rx_ring_buffer.c` (W03D03/W03D04 ring buffer implementation)
   - `uart_polling.h` (W03D01/W03D04 UART polling / IRQ interface)
   - `uart_polling.c` (W03D01/W03D04 USART2 initialization and IRQ handler)
   - `uart_parser.h` (W03D04 UART parser interface and contract)
   - `uart_parser.c` (W03D04 UART parser implementation)

   *Verification:* Verified 100% byte identical to source files in `firmware/stm32/w03d04-uart-parser-lab/`. No logic or semantic alterations were made.

## Executor-Created Starter Content

- `build.ps1`: Adapted PowerShell build script targeting `w04d02-pwm-uart-shell.elf`, `.map`, and `.list`, compiling startup, system, UART polling, ring buffer, parser, PWM stub, and main.
- `pwm.h`: Neutral function declarations for PWM initialization, frequency/duty setting, and querying.
- `pwm.c`: Compile-clean, non-working starter stubs with explicit learner TODO boundaries.
- `main.c`: Minimal entry point initializing UART, invoking `pwm_init()`, and providing the UART poll/feed loop with TODO markers for shell integration and command dispatch.

## Learner Ownership Boundary

The learner owns all technical and design implementation:
- Selection and verification of the timer peripheral (e.g. TIM2, TIM3, TIM4) and PWM channel.
- Selection and datasheet verification of the target GPIO pin and Alternate Function (AF) mapping.
- Register-level GPIO mode (`MODER`) and alternate function (`AFR`) configuration.
- Calculation and register programming of prescaler (`PSC`) and auto-reload (`ARR`) for the desired PWM frequency based on verified bus clock.
- Capture/compare register (`CCR`) calculation and configuration for duty cycle control.
- PWM channel mode configuration in `CCMR` (PWM Mode 1/2, preload enable) and `CCER` (output polarity, output enable).
- Main counter enable and timer startup.
- Frequency and duty adjustment functions and boundary/validation policies.
- Shell command dispatch linking UART parser commands to PWM parameter adjustments.
- Hardware smoke testing and physical signal verification.

No working PWM configuration, register writes, or command dispatch logic are provided in this starter. A clean starter build confirms infrastructure and toolchain readiness only.
