# TOOL VERSIONS — V3 BASELINE

Generated:
2026-08-09

Timezone:
Asia/Ho_Chi_Minh

| Tool | Command used | Version | Status | Notes |
|---|---|---|---|---|
| Windows | `winver` / `Get-ComputerInfo` | TBD | NOT_VERIFIED | Exact OS version not revalidated during Sprint 0 session |
| Git | `git --version` / build environment output | 2.49.0.windows.1 | PASS | Repository push/pull also revalidated |
| Host GCC | `gcc --version` | 14.2.0 | PASS | MSYS2 GCC; C11 strict-warning smoke test passed |
| ARM GCC | direct bundled executable `--version` | 13.3.1 and 14.3.1 | PASS | STM32CubeIDE-bundled GNU Tools for STM32 13.3.rel1 and 14.3.rel1; not exposed in global PowerShell PATH |
| CMake | `cmake --version` in ESP-IDF environment | 4.0.3 | PASS | Available in ESP-IDF environment; not exposed in ordinary PowerShell PATH |
| Python | ESP-IDF build environment output | 3.12.0 | PASS | Revalidated during ESP-IDF build |
| STM32CubeIDE | GUI/About | TBD | NOT_VERIFIED | Functional build/flash/debug workflow passed; exact IDE application version not separately pinned |
| STM32CubeMX | GUI/About | TBD | NOT_VERIFIED | Not required for Sprint 0 exit and not separately revalidated |
| ESP-IDF | `idf.py --version` | v6.0.2 | PASS | Build/flash/monitor passed |
| ST-Link | tool/firmware output | V2J48M35 | PASS | 3.30 V target; SWD session passed |
| PulseView | GUI/About | TBD | FUNCTION_PASS_VERSION_UNVERIFIED | Application detected 8-channel logic analyzer and captured STM32 blink; exact PulseView version not separately pinned |

## Integrity Notes

- Historical values are not promoted unless they were revalidated during Sprint 0.
- `PASS` here means tool availability/version or functional setup evidence, not learner competency.
- Missing global PATH entries for ARM GCC/CMake do not block current workflows because their owning environments invoke them successfully.
