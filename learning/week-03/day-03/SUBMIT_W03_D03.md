# SUBMIT — Week 03 / Day 03 — UART RX ring-buffer integration

Complete only with learner-performed, learner-supplied, or tool-verified facts.
Use `NOT RECORDED`, `NOT MEASURED`, or `NOT PERFORMED` instead of inference.
This normal-learning artifact is not independent competency evidence.

## Identity and provenance

- Date: `2026-08-26`
- Board/MCU: `NUCLEO-F446RE` / `STM32F446RETx`
- Actual Focused Time: `<LEARNER SUPPLIED>`
- Highest AI Level Actually Used: `<RECORD ACTUAL MAXIMUM>`
- Commit: `<COMMIT SHA OR NOT YET COMMITTED>`
- AI Disclosure: `<WHAT AI/EXECUTOR HELPED WITH; WHAT REMAINED LEARNER-OWNED>`

## Ring-buffer design — learner-owned

- Capacity and storage model: `<FILL>`
- Producer / writer: `<FILL>`
- Consumer / reader: `<FILL>`
- Empty invariant: `<FILL IN OWN WORDS>`
- Partial-state invariant: `<FILL IN OWN WORDS>`
- Full invariant: `<FILL IN OWN WORDS>`
- Wrap transition reasoning: `<FILL IN OWN WORDS>`
- Failed-operation state-preservation rule: `<FILL IN OWN WORDS>`
- Shared ISR/foreground visibility, atomicity, and ordering assumptions: `<FILL>`

## Overflow policy — learner-owned

- Selected bounded policy: `<DROP NEWEST / OVERWRITE OLDEST / APPROVED OTHER>`
- Why this policy fits the USART2 RX path: `<FILL IN OWN WORDS>`
- State transition when full and another byte arrives: `<FILL IN OWN WORDS>`
- Overflow/error counter rule: `<FILL IN OWN WORDS>`

## Host test evidence

- Exact compile command: `<FILL>`
- Compile exit/result: `<FILL AFTER RUN>`
- Exact test command: `<FILL>`
- Test exit/result: `<FILL AFTER RUN>`
- Test summary: `<FILL AFTER RUN>`
- Failing test IDs, if any: `<FILL OR NONE>`
- Saved raw output path, if retained: `<FILL OR NOT STORED>`

## STM32 build evidence

- Working directory: `firmware/stm32/w03d03-uart-ring-buffer-lab`
- Exact build command: `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`
- Exit code/result: `<FILL AFTER RUN>`
- Compiler/linker warnings: `<FILL AFTER RUN>`
- ELF/map/list paths and result: `<FILL AFTER RUN>`
- Size output: `<FILL AFTER RUN>`

## Firmware integration evidence

- ISR work performed: `<FILL>`
- Foreground work performed: `<FILL>`
- Why ISR work is bounded/non-blocking: `<FILL IN OWN WORDS>`
- Normal input/load and expected result: `<FILL>`
- Normal observed result: `<FILL AFTER RUN OR NOT PERFORMED>`
- Normal evidence path/log: `<FILL OR NOT STORED>`
- Overflow input/load and expected result: `<FILL>`
- Overflow observed policy behavior: `<FILL AFTER RUN OR NOT PERFORMED>`
- Final overflow/error counter value: `<FILL AFTER RUN OR NOT MEASURED>`
- Overflow evidence path/log: `<FILL OR NOT STORED>`
- Exact flash/debug/terminal method: `<FILL AFTER USE OR NOT RECORDED>`

## Final boundary

- Known limitations: `<FILL>`
- Blockers: `<FILL OR NONE>`
- Artifact result: `<DO NOT FILL UNTIL AUTHORIZED CLOSURE>`
- Competency result: `NONE — normal learning day; no competency gate`
- Lifecycle/status: `<DO NOT CLAIM GREEN/YELLOW/RED DURING PREPARATION>`

Build or host compilation alone does not prove UART hardware behavior,
`ARTIFACT_PASS`, or `COMPETENCY_PASS`.
