# W02D02 Startup Lab Provenance

This directory is executor-prepared infrastructure/reference material. It is
not learner-authored competency code and contains no learner conceptual answer.

## Exact target

- Board/project identity: `NUCLEO-F446RE`
- Device: `STM32F446RETx`, LQFP64
- Startup source: STM32F446xx GCC startup source
- Installed STM32Cube firmware package: `STM32Cube_FW_F4_V1.28.3`
- Verified build toolchain: STM32CubeIDE-bundled GNU Tools for STM32
  `13.3.rel1` (`arm-none-eabi-gcc 13.3.1 20240614`)

## Reused source

The repository history contains no prior tracked STM32 project beyond
`firmware/stm32/.gitkeep`. The exact-device files below were copied without
semantic edits from the local Sprint-0 test vehicle at:

`C:\Users\Admin\STM32CubeIDE\workspace_2.0.0\test`

| Lab file | Original path relative to test vehicle | Original SHA-256 |
|---|---|---|
| `startup_stm32f446retx.s` | `Core/Startup/startup_stm32f446retx.s` | `448435EB5D2FFE063490BCAC42B9C861461CE05528141D87E62F8425C00131F8` |
| `STM32F446RETX_FLASH.ld` | `STM32F446RETX_FLASH.ld` | `12F8B127A236C277A5B92D44A9325A2CA5D589929CBC5960BAB47C21DA39B4A0` |
| `system_stm32f4xx.c` | `Core/Src/system_stm32f4xx.c` | `A31929EAB936AC98DB060C18917118ACF79DC96E1F03ED4B57D614535DD06D70` |

The required CMSIS device/core headers and license texts in `include/` and
`licenses/` were also copied from that exact generated project. `main.c` and
`build.ps1` are bounded executor-prepared lab infrastructure.

After copying, authorized mechanical hygiene removed trailing spaces only from
files inside the lab. The hashes above intentionally identify the untouched
original source files; no semantic source or line-ending change was made.

## Build

From this directory in PowerShell:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

Generated artifacts are written only under ignored `build/`.
