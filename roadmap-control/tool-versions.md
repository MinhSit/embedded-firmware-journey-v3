# TOOL VERSIONS — V3 BASELINE

Generated:
2026-08-09

Last metadata verification:
2026-08-09 22:28 +07:00

Timezone:
Asia/Ho_Chi_Minh

| Tool | Command / evidence used | Version | Status | Notes |
|---|---|---|---|---|
| Windows | `Get-CimInstance Win32_OperatingSystem` | Windows 10 Pro `10.0.19045`, build `19045`, 64-bit | PASS | Exact OS version revalidated |
| Git | `git --version` / build environment output | 2.49.0.windows.1 | PASS | Repository push/pull also revalidated |
| Host GCC | `gcc --version` | 14.2.0 | PASS | MSYS2 GCC; C11 strict-warning smoke test passed |
| ARM GCC | direct bundled executable `--version` | 13.3.1 and 14.3.1 | PASS | STM32CubeIDE-bundled GNU Tools; not exposed in global PowerShell PATH |
| CMake | `cmake --version` in ESP-IDF environment | 4.0.3 | PASS | Available in ESP-IDF environment; not exposed in ordinary PowerShell PATH |
| Python | ESP-IDF build environment output | 3.12.0 | PASS | Revalidated during ESP-IDF build |
| STM32CubeIDE | running application Help/About | 2.2.0, build `29186_20260626_0934 (UTC)` | PASS | About dialog supersedes stale uninstall registry metadata |
| STM32CubeMX | running application About | 6.18.1 | PASS | About dialog supersedes stale uninstall registry metadata |
| ESP-IDF | `idf.py --version` | v6.0.2 | PASS | Build/flash/monitor passed |
| ST-Link | tool/firmware output | V2J48M35 | PASS | 3.30 V target; SWD session passed |
| PulseView | Windows uninstall registry + capture evidence | 0.5.0-git-e2fe9df | PASS | Version verified; logic capture passed |
| Wireshark | Windows uninstall registry | 4.6.5 x64 | PASS | Installation/version verified; workflow deferred until network/protocol phase |

## Integrity Notes

- Historical values are not promoted unless they were revalidated or supported by retained evidence.
- `PASS` here means tool availability/version or functional setup evidence, not learner competency.
- Missing global PATH entries for ARM GCC/CMake do not block current workflows because owning environments invoke them successfully.
- Application About dialogs are treated as authoritative when uninstall registry metadata is stale after upgrades.
