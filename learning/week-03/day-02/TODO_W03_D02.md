# TODO — Week 03 / Day 02 — USART2 RX interrupt

## 0. Metadata

- Date: `2026-08-25`
- Timezone: `Asia/Ho_Chi_Minh`
- System Spec: `SYSTEM_SPEC_V3 3.0.0`
- Roadmap: `EMBEDDED_ROADMAP_V3.1 3.1.0`
- Week/Day: `W03D02`
- Calendar Position: `Week 3 / Day 2`
- Execution Position: `W03D02 CLOSED`; next execution target `W03D03`
- Artifact Position: `W03D02 GREEN / CLOSED / ARTIFACT_PASS`
- Competency Position: `W02-C-MCU-FOUND — COMPETENCY_PASS`; no new competency result
- Available Focused Time: `6h — learner supplied`
- AI Mode: normal `LEARNING`; highest assistance used `AI-3`
- Board/MCU: `NUCLEO-F446RE` / `STM32F446RETx`
- Source sections: authoritative W03D02 day outcome; Master Prompt starter/TODO/day-pack rules

## 1. Outcome

Add USART2 RXNE interrupt reception, keep the ISR short, reason explicitly about
shared state, and produce a physical IRQ demo plus register/evidence capture.

## 2. Acceptance Criteria

### MUST — traceable to the authoritative W03D02 outcome

- [x] Add RXNE interrupt reception for USART2.
- [x] Keep the ISR short and justify the work assigned to ISR versus foreground.
- [x] Identify shared state and reason about its producer, consumer, and update risks.
- [x] Clean-build the learner implementation.
- [x] Verify clock, pin, register, and API facts from the correct official source.
- [x] Run a physical hardware smoke test and record expected versus observed results.
- [x] Exercise at least one suitable controlled fault/error case, then restore and
  recheck the intended configuration.
- [x] Produce an IRQ demo and register/debug/evidence capture.

### NON-SCORING learning feedback

- Draw a concise ISR-producer / foreground-consumer diagram.
- Compare polling versus interrupt CPU behavior.
- Observe an overrun/error condition only if it is safely reproducible.
- Give an interview-style explanation of the interrupt and shared-state path.

These suggestions do not expand or alter the MUST acceptance criteria.

## 3. Prerequisites

- Knowledge: W03D01 USART2 polling baseline, Cortex-M exception flow, NVIC,
  register read/modify/write, and C shared-state reasoning.
- Files: W03D02 lab sources, startup/vector source, device header, and official
  STM32F446RE/NUCLEO-F446RE sources.
- Tools: STM32 ARM GCC build, verified flash/debug workflow, serial terminal,
  and a method for capturing register/debug evidence.
- Hardware: NUCLEO-F446RE and its verified USART2 serial path.
- Baseline command: `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`

## 4. Starter State

- Vendor/CMSIS headers, startup, linker, reset-clock stub, licenses, and build
  infrastructure are mechanically reused from the validated W03D01 closure.
- `uart_polling.h` and `uart_polling.c` preserve prior learner W03D01 work.
- `main.c` is intentionally idle; no interrupt demo loop is supplied.
- No interrupt-specific module or final public API is imposed.
- No receive-interrupt enable sequence, NVIC setup, handler, shared-state
  protocol, foreground consumer, overrun policy, or hardware result is supplied.

## 5. Learner TODO

1. From official sources, determine which USART control bit enables receive-data
   interrupt generation. Record the source identifier, revision, and location.
2. Determine which NVIC IRQ corresponds to USART2 and how it must be configured.
3. Trace the startup/vector table to determine exactly how the handler symbol is
   resolved; do not guess the symbol spelling.
4. Determine which receive/status condition causes the interrupt.
5. Determine what action is required to consume the received byte and how that
   action affects relevant receive/error state.
6. Decide which work belongs inside the ISR and which belongs in foreground;
   keep the ISR bounded and non-blocking.
7. List every shared object. For each, state who writes it, who reads it, and
   what visibility/atomicity/ordering assumptions your design relies on.
8. Explain what happens if another byte arrives before foreground consumes the
   previous byte; choose and justify a bounded Day 2 policy without adding a
   ring buffer.
9. Plan evidence that distinguishes: peripheral interrupt disabled, NVIC
   disabled, wrong handler/vector symbol, shared-state bug, and receive overrun.
10. Define how you will observe that the handler truly ran without making the
    observation mechanism dominate ISR behavior.
11. Preserve the working W03D01 clock, framing, GPIO, and polling-TX baseline;
    change only the RX reception path needed for W03D02.
12. Implement, clean-build, flash, run the physical IRQ demo, capture required
    register/debug evidence, run one controlled fault/error experiment, restore
    the intended state, and record only facts actually observed.
13. Complete `SUBMIT_W03_D02.md` without pre-filling unverified conclusions.

### Completion record

- [x] RXNE/RXNEIE, `USART2_IRQn`, and `USART2_IRQHandler` path implemented and recorded.
- [x] ISR/foreground ownership and the depth-1 mailbox limitation documented.
- [x] Final clean build PASS with ELF/map/list and size recorded.
- [x] Physical COM4 IRQ/echo demo PASS at 115200 8N1.
- [x] Normal register/NVIC capture saved as `Screenshot_1.png`.
- [x] Forced ORE capture saved as `Screenshot_2.png`.
- [x] SR-to-DR recovery capture saved as `Screenshot_3.png`.
- [x] Post-recovery `R` echo saved as `Screenshot_4.png`.
- [x] `SUBMIT_W03_D02.md` completed with unresolved source revisions left explicitly `NOT RECORDED` rather than inferred.
- [x] END DAY closure records artifact result only; no competency gate or new competency result.

## 6. Test / Evidence Matrix

| ID | Requirement/behavior | Expected evidence category |
|---|---|---|
| W03D02-T01 | Clean build | Exact command, exit code, warnings, ELF/map/list paths, size |
| W03D02-T02 | Interrupt configuration | Learner source diff plus official-source references and reasoning |
| W03D02-T03 | Physical RX IRQ activation | Stated input, expected behavior, observed hardware/terminal evidence |
| W03D02-T04 | Foreground observes ISR-produced data/state | Shared-state ownership explanation plus attributable demo evidence |
| W03D02-T05 | Register/debug capture | Saved capture/log with register names, capture point, and interpretation |
| W03D02-T06 | Controlled failure/error path and restoration | Prediction, one controlled change/condition, observation, restoration, retest |

The matrix specifies evidence categories only. It records no test result.

## 7. Fault / Error Experiment

Select one safe case that can distinguish a relevant failure mode. Predict the
result first, change one variable or introduce one controlled condition, capture
what actually happens, restore the intended state, and rerun the primary demo.
Do not claim an ORE observation unless it was actually produced and captured.

## 8. Evidence to Save

- Exact official document identifiers/revisions and relevant locations.
- Learner-owned source diff and explicit shared-state ownership table or notes.
- Exact clean-build command, exit code, warnings, artifacts, and size output.
- Exact flash/debug method actually used; otherwise `NOT PERFORMED`.
- Exact terminal settings and physical USART path used.
- IRQ demo input, expected result, observed result, and saved evidence path.
- Register/debug capture with capture point and learner interpretation.
- Controlled negative/error case, restoration, and post-restoration result.
- ORE or other error observation only when actually measured.

## 9. Artifact Definition of Done

The learner implementation clean-builds; physical RX IRQ behavior and
foreground consumption are demonstrated; shared-state reasoning, official-source
references, register/debug capture, expected-versus-observed evidence, and one
restored controlled fault/error case are recorded truthfully. Starter build
success alone is not artifact completion.

## 10. Competency and AI Boundary

This is normal `LEARNING`, not a scored gate, and cannot independently award a
new `COMPETENCY_PASS`. The learner owns interrupt configuration, ISR logic,
shared-state design, hardware observation, debugging, and explanation. Record
the highest AI assistance actually used; do not backfill or minimize it.

## 11. Forbidden Shortcuts

- No ring buffer; integration belongs to W03D03.
- No DMA, HAL, or LL implementation.
- No blocking work, terminal output loop, or unbounded processing inside ISR.
- No copied complete interrupt example that replaces learner reasoning.
- No invented IRQ behavior, register state, error observation, capture, flash
  method, focused time, artifact result, or competency result.

## 12. Stop Condition

Stop and report instead of guessing if official sources conflict, board/signal
path cannot be verified, the baseline unexpectedly differs, build requires
out-of-scope repair, or the implementation would require hidden assumptions.

## 13. Next Physical Action

Before editing interrupt code, open the official reference manual, device
header, and startup/vector source. Record the receive-interrupt control,
peripheral-to-NVIC path, exact handler-symbol path, and a proposed shared-state
ownership table in your own words.
