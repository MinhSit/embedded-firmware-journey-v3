# W04D05 HardFault Triage Provenance

This directory contains AI-assisted learning infrastructure and learner-owned
HardFault triage implementation for the `NUCLEO-F446RE` / `STM32F446RETx`
target. It is normal learning evidence, not an independent competency gate.

## Mechanically reused infrastructure

The startup source, linker script, reset clock baseline, CMSIS/device headers,
license texts, and PowerShell build pattern were mechanically reused from the
proven W04D04 STM32F446RE baseline. The build script was adapted only for the
W04D05 source names and build-artifact labels.

## Learner-owned work

The learner owned the controlled-fault scenario and implementation, naked
HardFault wrapper, SCB status capture, basic exception-frame extraction, first
hardware/debugger attempt, raw measurements, disassembly correlation,
root-cause reasoning, minimal fix, normal regression, and retained controlled
reproduction. Final normal source has `ENABLE_CONTROLLED_FAULT = 0`.

## AI and executor assistance

Project Chat supplied theory/pre-check and AI-3 post-attempt review. It detected
that the first transcribed PC/R3 values conflicted with disassembly and requested
direct raw eight-word frame re-measurement. The learner performed that
measurement and supplied the corrected evidence before applying the fix.

The repository executor created the neutral starter and later formatted the
learner-supplied closure records, ran technical/repository validation, and
performed authorized bookkeeping. It did not rewrite learner firmware logic or
invent measurements.

## Evidence boundary

`learning/week-04/day-05/Screenshot_1.png` is fault/reproduction evidence. It
shows STM32CubeProgrammer reporting lost connection/core-ID access during the
intentionally faulting configuration; it does not prove the normal regression
remained connected.

The artifact demonstrates one controlled precise BusFault-to-HardFault triage
path. It does not claim production-grade fault recovery or coverage of every
HardFault class.

## Competency boundary

Highest assistance for W04D05 was AI-3. W04D05 closes as normal-learning
`ARTIFACT_PASS` only. No competency is awarded; latest verified competency
remains `W03-C-UART-FOUND — COMPETENCY_PASS`.
