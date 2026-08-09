# Sprint 0 Preflight Evidence Summary — 2026-08-09

Scope: operational/bootstrap evidence only. This file does **not** establish Embedded/Firmware competency.

## Repository / Git

- Branch: `main`
- Remote push/pull: PASS
- Sprint 0 host-smoke source commit: `477b4c0`
- Technical preflight bookkeeping commit: `4f1ff8d`

## STM32

Hardware: Nucleo-F446RE / STM32F446 target.

Observed:
- STM32CubeIDE Debug build invoked `make -j8 all`.
- Build completed with 0 errors, 0 warnings.
- ELF size report: text 7288 B, data 20 B, bss 1572 B.
- ST-LINK programming and verification completed successfully.
- ST-LINK firmware: `V2J48M35`.
- Target voltage reported: 3.30 V.
- Debugger suspended at a breakpoint in `main()` on `HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);`.
- Board blink behavior observed at roughly 0.5 s toggle interval.

Decision: PASS for Sprint 0 setup revalidation.

Integrity note: historical blink project was reused only as a test vehicle; it is not imported as competency evidence.

## ESP32

Environment:
- ESP-IDF `v6.0.2`.
- Target `esp32`.
- Serial port COM6, monitor 115200 baud.

Observed:
- Initial build encountered stale CMake path/cache from the moved historical project.
- `idf.py fullclean` cleared the stale build state.
- `idf.py build` completed successfully.
- `idf.py flash` completed successfully with verified writes.
- Target identified as ESP32-D0WD-V3 rev 3.1 during flash.
- `idf.py monitor` showed boot logs and repeated `Hello world!` application output/restart cycles.
- Manual interruption of monitor produced a host-side `KeyboardInterrupt`; valid serial output had already been observed.

Decision: PASS for Sprint 0 setup revalidation.

Configuration note: flash hardware detection reported 4 MB while binary header used 2 MB. This is a non-blocking configuration item to revisit when ESP32 project work requires exact flash sizing.

## Host C

Compiler: MSYS2 GCC `14.2.0`.

Command:
`gcc -std=c11 -Wall -Wextra -Wpedantic -Werror tests\host\smoke.c -o tests\host\smoke.exe`

Runtime:
`.\tests\host\smoke.exe`

Observed output:
`HOST_C_SMOKE_PASS`

Decision: PASS.

Integrity note: `tests/host/smoke.c` was AI-assisted setup/test infrastructure. It is not learner competency evidence.

## ARM GCC

Global ordinary PowerShell PATH: command not found.

STM32CubeIDE-bundled executables verified directly:
- GNU Tools for STM32 13.3.rel1 — `arm-none-eabi-gcc 13.3.1 20240614`.
- GNU Tools for STM32 14.3.rel1 — `arm-none-eabi-gcc 14.3.1 20250623`.

Decision: PASS. Global PATH modification is not required for the current CubeIDE workflow.

## CMake

Ordinary PowerShell PATH: command not found.

Inside ESP-IDF environment:
- `cmake --version` -> `4.0.3`.

Decision: PASS. Global PATH modification is not required for the current ESP-IDF workflow.

## UART / Serial Path

ESP-IDF monitor on COM6 at 115200 baud produced readable target boot/application logs.

Decision: PASS.

## Logic Analyzer / Measurement

Tool path: PulseView with Saleae Logic-compatible 8-channel device.

Observed:
- Device detected; D0–D7 channels available.
- D0 captured STM32 PA5 blink waveform.
- Approximately 0.5 s HIGH and 0.5 s LOW, ~1 s period, ~50% duty cycle.
- Common ground used between analyzer and target.

Decision: PASS.

## Hardware Inventory / Safety

Core availability:
- Nucleo-F446RE: present, working.
- ESP32-WROOM-32 development board: present, working.
- USB data cable: present, working.
- 8-channel logic analyzer: present, working.
- Jumper wires: present.
- MPU6050: present; headers soldered; visually new/clean; no visible physical damage; electrical/I2C function NOT_TESTED in Sprint 0.

Baseline safety: 3.3 V logic unless exact hardware documentation says otherwise; verify voltage, common ground, exact pin, alternate function, direction, connector and current/power assumptions before wiring.

Fallbacks: mock sensor data where roadmap permits; UART output when display path is unavailable; optional modules do not block core roadmap.

Decision: PASS for Sprint 0 inventory readiness.

## Competency Integrity

- No V3 competency is promoted by Sprint 0.
- Pre-V3 Week 1 C competency remains `COMPETENCY_UNVERIFIED / RETEST REQUIRED`.
- Fresh Week 1 learning and independent AI-0 gate remain required.

## Sprint 0 Technical Result

All mandatory operational paths required for CP-00 were successfully revalidated. Final transition decision is recorded separately in `evidence/sprint-00/cp-00-review.md` and `roadmap-control/current-state.md`.
