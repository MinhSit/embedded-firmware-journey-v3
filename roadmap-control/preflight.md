# SPRINT 0 PREFLIGHT — 2026-08-09

Status values:

- PASS
- FAIL
- N/A
- NOT_TESTED

---

## 1. Git / Repository

Git version:
2.49.0.windows.1 (observed during ESP-IDF configure; repository operations also revalidated)

Repository initialized:
YES

Branch `main` exists:
YES

Initial commit:
Pre-Sprint-0 baseline history exists; Sprint 0 host smoke evidence commit `477b4c0`.

Remote push:
PASS — repository push/pull path revalidated throughout Sprint 0.

Status:
PASS

---

## 2. STM32

Board:
Nucleo-F446RE

MCU:
STM32F446RE / target detected as STM32F446xx

Build command:
STM32CubeIDE Debug build: `make -j8 all`

Build result:
PASS — 0 errors, 0 warnings. ELF size report: text 7288 B, data 20 B, bss 1572 B.

Flash method:
ST-LINK GDB Server + STM32CubeProgrammer

Flash result:
PASS — download completed and verified successfully.

Debug breakpoint:
PASS — CPU suspended at breakpoint in `main()` on `HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);`.

ST-Link status:
PASS — ST-LINK FW `V2J48M35`, target voltage `3.30 V`, SWD 4000 KHz.

Evidence:
- `evidence/sprint-00/preflight-summary.md`
- `evidence/sprint-00/captures/stm32-debug-breakpoint-evidence.jpg`
- source project reused from historical repo only as a preflight test vehicle.

Status:
PASS

---

## 3. ESP32

Board:
ESP32-WROOM-32 development board

ESP-IDF version:
v6.0.2

Build command:
`idf.py fullclean` followed by `idf.py build`

Build result:
PASS — project build complete; target `esp32`; `hello_world.bin` generated. Initial stale CMake cache after project path move was cleared with `idf.py fullclean`.

Flash command:
`idf.py flash`

Flash result:
PASS — COM6; ESP32-D0WD-V3 rev 3.1; bootloader/partition/app written and hash verified; hard reset completed.

Monitor command:
`idf.py monitor`

Monitor result:
PASS — COM6 @ 115200; boot log + `Hello world!` + repeated software restart observed. Final `KeyboardInterrupt` came from manually stopping the monitor and is not a target failure.

Evidence:
`evidence/sprint-00/preflight-summary.md`

Status:
PASS

---

## 4. Host C

Compiler:
MSYS2 GCC

Version:
14.2.0

Strict-warning command:
`gcc -std=c11 -Wall -Wextra -Wpedantic -Werror tests/host/smoke.c -o tests/host/smoke.exe`

Smoke-test command:
`.\tests\host\smoke.exe`

Result:
PASS — output `HOST_C_SMOKE_PASS`.

Evidence:
`tests/host/smoke.c`; commit `477b4c0`; `evidence/sprint-00/preflight-summary.md`.

Status:
PASS

---

## 5. ARM GCC

Command:
Direct execution of STM32CubeIDE-bundled `arm-none-eabi-gcc.exe --version` binaries. Global PowerShell PATH does not contain `arm-none-eabi-gcc`.

Version:
- GNU Tools for STM32 13.3.rel1: `arm-none-eabi-gcc 13.3.1 20240614`
- GNU Tools for STM32 14.3.rel1: `arm-none-eabi-gcc 14.3.1 20250623`

Status:
PASS — bundled toolchains exist and execute; global PATH configuration is not required for current CubeIDE workflow.

---

## 6. CMake

Command:
`cmake --version` inside ESP-IDF v6.0.2 environment.

Version:
4.0.3

Status:
PASS — available in ESP-IDF environment. Global PowerShell PATH does not contain CMake.

---

## 7. UART

Tool:
ESP-IDF monitor / serial console

Test performed:
Opened ESP32 serial console on COM6 at 115200 baud and observed complete boot/application logs.

Result:
PASS — readable boot log, application log, countdown and restart cycles observed.

Status:
PASS

---

## 8. Logic Analyzer

Tool:
PulseView + Saleae Logic-compatible 8-channel device

Device detected:
PASS — D0–D7 available.

Capture performed:
PASS — D0 captured STM32 PA5 blink signal. Observed approximately 0.5 s HIGH / 0.5 s LOW, about 1 s period and ~50% duty cycle, matching the preflight firmware behavior.

Evidence:
- `evidence/sprint-00/preflight-summary.md`
- `evidence/sprint-00/captures/stm32-pa5-logic-capture-evidence.jpg`
- `evidence/sprint-00/captures/README.md`

Status:
PASS

---

## 9. Hardware Safety

3.3 V assumptions verified:
YES — STM32 target voltage reported as 3.30 V; roadmap baseline remains 3.3 V logic.

Common ground verified:
YES for logic-analyzer capture setup.

Board pinout documentation identified:
Baseline board/project mapping used for PA5 blink; exact document reference should be recorded when Week 2 begins register-level GPIO work.

MPU6050 status:
PRESENT — visually inspected; new/clean, headers soldered, no visible physical damage. Electrical/I2C function NOT_TESTED in Sprint 0.

Fallback available:
YES — mock data where roadmap permits; UART output for optional display path; optional modules do not block core roadmap.

Status:
PASS

---

## 10. Sprint 0 Exit

V3 repo ready:
PASS

Control files ready:
PASS

STM32 preflight:
PASS

ESP32 preflight:
PASS

Host compiler/test:
PASS

UART:
PASS

Logic analyzer:
PASS

ARM GCC checked:
PASS

CMake checked:
PASS

Inventory complete:
PASS — see `roadmap-control/inventory.md`.

Old competency claims marked UNVERIFIED:
PASS — Week 1 pre-V3 competency remains `COMPETENCY_UNVERIFIED / RETEST REQUIRED`.

Week 1 Day 1 ready:
PASS — no P0 operational/tooling/hardware blocker remains. This is readiness only, not competency PASS.

Decision:
CONTINUE — Sprint 0 closed operationally. See `evidence/sprint-00/cp-00-review.md`.
