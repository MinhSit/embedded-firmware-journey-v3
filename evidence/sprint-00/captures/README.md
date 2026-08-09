# Sprint 0 Visual Captures — 2026-08-09

Scope: visual evidence for Sprint 0 operational/bootstrap validation only.
These captures do NOT establish Embedded/Firmware competency.

## Files

### `stm32-debug-breakpoint-evidence.jpg`

STM32CubeIDE debug evidence.

Observed:
- Nucleo-F446RE debug session active.
- Thread suspended at a breakpoint in `main()`.
- Breakpoint at `main.c:104`.
- Current source line:
  `HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);`
- Console shows successful download verification.

Supports:
- STM32 flash/debug path revalidation.
- `SPRINT-0-EXIT` operational evidence.

### `stm32-pa5-logic-capture-evidence.jpg`

PulseView logic-analyzer capture of the STM32 PA5 blink signal.

Observed:
- D0 contains a repeating square wave.
- HIGH approximately 0.5 s.
- LOW approximately 0.5 s.
- Period approximately 1 s.
- Duty cycle approximately 50%.

This matches the preflight firmware behavior:
`HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);`
followed by
`HAL_Delay(500);`

Supports:
- Logic-analyzer detection/capture path.
- Measurement-path revalidation for Sprint 0.

## Integrity

These files are setup/measurement evidence only.

They must NOT be used to claim:
- Embedded C competency PASS;
- STM32 programming competency PASS;
- Week 1 competency PASS.

Week 1 competency remains subject to fresh independent verification.
