# W02 Cortex-M Startup Simulator

## Purpose

This PC-hosted C11 lab makes Cortex-M startup state and ordering observable
without requiring a board or instruction-set emulator. The learner owns the
startup algorithm in `src/startup.c`; the surrounding simulator, tests, trace,
and fault controls are supplied infrastructure.

This simulator models startup semantics. It does not reproduce Cortex-M
instruction execution or exact linker/vector binary layout.

## Architecture

```text
fake power-on
    -> simulated CPU reads the portable vector table
    -> validates and stores the simulated MSP
    -> calls Reset_Handler
    -> SystemInit
    -> .data Flash image to RAM
    -> .bss zero
    -> runtime init
    -> app_main
```

Structured trace events expose the order. Fixed fake Flash/RAM arrays expose
memory state, poison values, and guard words.

## File map

- `include/`, `src/sim_*.c`, and `src/app.c`: executor-owned infrastructure.
- `src/startup.c`: learner-owned startup implementation.
- `tests/`: visible deterministic checks with expected/actual diagnostics.
- `demo/startup_demo.c`: before/reset/after trace runner.
- `TODO.md`: implementation order; open this first.

## Build and test

One PowerShell command configures, builds, and runs everything:

```powershell
.\run_tests.ps1
```

The script discovers the existing host GCC, MinGW Make, and local CMake. It
returns nonzero while learner startup tests fail.

Direct CMake commands, when `cmake` is on `PATH`:

```powershell
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
ctest --test-dir build --verbose
```

The project uses C11 and enables `-Wall -Wextra -Wpedantic -Werror` with the
repository's established host GCC toolchain.

## Demo

After building:

```powershell
.\build\startup_demo.exe
```

The demo prints pre-reset memory, reset result, structured trace, post-reset
memory, final MSP, and guard status.

## Learner-owned TODOs

All coding locations are in `src/startup.c`, function `Reset_Handler`:

- correct `SystemInit` placement;
- complete manual `.data` copy, without `memcpy`;
- complete manual `.bss` clear, without `memset`;
- runtime initialization and `app_main` ordering;
- per-word data/bss trace recording.

The simulator-to-STM32 explanations at the end of this file are also
learner-owned.

## Expected initial state

- Build: passes with no warnings.
- Memory-layout tests: pass.
- CPU-reset infrastructure tests: pass.
- Fault-infrastructure tests: pass.
- Learner startup tests: fail at runtime with measured discrepancies.

This intentional split keeps TODOs compile-safe while preserving a real
red-to-green learning loop.

## Fault modes

Pass one optional mode to the demo:

| Mode | Controlled observation |
|---|---|
| `data-short` | Last `.data` destination word is incorrect. |
| `skip-bss` | `.bss` remains poisoned even if execution reaches the app. |
| `bad-stack` | CPU reset rejects a misaligned simulated MSP. |
| `main-before-runtime` | Trace exposes application/runtime order inversion. |
| `wrong-reset-handler` | Vector fetch reaches `Fault_Handler`, not normal startup. |

The fault framework changes controlled state or hooks; it does not contain a
reference startup implementation.

## What is and is not simulated

The lab simulates vector semantics, initial MSP validation, reset-handler
dispatch, section initialization state, runtime/application calls, guard words,
and deterministic event order.

It intentionally does not simulate Cortex-M opcodes, exceptions beyond the
small reset/fault contract, real addresses, exact linker placement, exact vector
binary ABI, clocks, peripherals, CMSIS, or STM32 HAL.

## Learner mapping — fill in your own words

| Simulator concept | STM32F446 startup equivalent |
|---|---|
| `initial_msp` | `TODO(LEARNER EXPLAIN)` |
| `reset_handler` | `TODO(LEARNER EXPLAIN)` |
| `_sidata` | `TODO(LEARNER EXPLAIN)` |
| `_sdata` / `_edata` | `TODO(LEARNER EXPLAIN)` |
| `_sbss` / `_ebss` | `TODO(LEARNER EXPLAIN)` |
| runtime init | `TODO(LEARNER EXPLAIN)` |
| `app_main` | `TODO(LEARNER EXPLAIN)` |
