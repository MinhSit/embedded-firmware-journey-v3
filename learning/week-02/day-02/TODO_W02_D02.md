# TODO — Week 02 / Day 02

## Metadata

- Date: `2026-08-18`
- Week/Day: `Week 02 / Day 02`
- Topic: `STM32F446RE startup sequence / power-on to main`
- Day type: `LEARNING`
- AI boundary: AI may explain theory or review after a meaningful attempt, but
  must not prefill the learner's reconstruction or claim competency.
- Roadmap-derived Week 2 standard load: `46–49 focused hours/week`
- Available Focused Time: transient learner input is `6h`; do not persist it in
  control/state/log files during prep.
- Planned/Actual Focused Time: establish later in Project Chat; not set here.

## Outcome

Trace the real STM32F446RE path from the vector table through startup/runtime
initialization to `main()`, then reconstruct it independently in the worksheet.

## Sources to inspect

- `firmware/stm32/w02d02-startup-lab/startup_stm32f446retx.s`
- `firmware/stm32/w02d02-startup-lab/STM32F446RETX_FLASH.ld`
- `firmware/stm32/w02d02-startup-lab/system_stm32f4xx.c`
- `firmware/stm32/w02d02-startup-lab/main.c`
- `firmware/stm32/w02d02-startup-lab/build/w02d02-startup-lab.map`
- `firmware/stm32/w02d02-startup-lab/build/w02d02-startup-lab.list`
- `firmware/stm32/w02d02-startup-lab/PROVENANCE.md`

## Tasks

1. Build the lab without changing the supplied infrastructure.
2. Inspect the first two vector-table entries and locate `Reset_Handler`.
3. Record every linker symbol encountered in the startup path.
4. Trace initialization of the relevant memory sections from source and map.
5. Locate the system-initialization and C-runtime calls before `main()`.
6. Confirm `main` and the important symbols in ELF/map/list output.
7. If Project Chat later requests a debugger trace, record only observations
   actually measured on hardware.
8. Close sources and perform the final closed-book reconstruction.

## Artifact requirement

Complete `POWER_ON_TO_MAIN_W02D02.md` in the learner's own words and prepare
`SUBMIT_W02_D02.md` with references to the evidence used.

## Evidence to collect

- exact build command and exit result;
- ELF, map and disassembly/list file paths;
- source locations/line references used;
- learner observations of vector entries and linker symbols;
- expected vs observed notes;
- debugger/hardware evidence only if actually performed;
- remaining questions and final closed-book reconstruction.

## Exact build/map commands

Run from the repository root:

```powershell
Set-Location .\firmware\stm32\w02d02-startup-lab
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

Inspect the generated map without editing it:

```powershell
Select-String -Path .\build\w02d02-startup-lab.map -Pattern 'Reset_Handler|SystemInit|__libc_init_array| main$|_sidata|_sdata|_edata|_sbss|_ebss'
```

## AI boundary

- Do not ask AI to write the final `power-on-to-main` explanation.
- Do not ask AI to fill pre-check, worksheet, closed-book or defense answers.
- AI-created infrastructure/provenance is reference material, not learner
  competency evidence.
- Disclose stronger assistance if it occurs.

## Stop condition

Stop and report if the exact device/source provenance becomes uncertain, the
build no longer reproduces, evidence conflicts with source/map output, or the
next action would require AI to perform the learner's conceptual reconstruction.
