# TODO — Week 03 / Day 01 — UART clock and polling

## 0. Metadata

- Date: `2026-08-24`
- Timezone: `Asia/Ho_Chi_Minh`
- System Spec: `SYSTEM_SPEC_V3 3.0.0`
- Roadmap: `EMBEDDED_ROADMAP_V3.1 3.1.0`
- Week/Day: `W03D01`
- Calendar Position: `Week 3 / Day 1`
- Execution Position: BOOT transient preparation; learner implementation not started
- Artifact Position: starter only; no W03D01 artifact result
- Competency Position: `W02-C-MCU-FOUND — COMPETENCY_PASS`; no new competency result
- Available Time: `6h — learner supplied`
- Board/MCU: `NUCLEO-F446RE` / `STM32F446RETx`
- AI Mode: executor infrastructure/starter assistance; normal `LEARNING`
- Source sections: authoritative W03D01 day outcome; Master Prompt starter/TODO/day-pack rules

## 1. Outcome

Calculate UART baud from the actual peripheral clock; implement UART TX/RX
polling first; obtain a correct-baud UART loopback/log on hardware.

## 2. Acceptance Criteria

### MUST — traceable to the authoritative W03D01 outcome

- Derive and document the clock that actually feeds the chosen UART peripheral.
- Configure the verified GPIO/alternate-function and UART path at register level.
- Derive the baud-divider relationship and the value used from stated clock and
  serial assumptions; do not copy an unexplained constant.
- Implement polling transmit and polling receive behavior.
- Produce a physical UART loopback/log at the intended baud.
- Record expected versus observed evidence truthfully.

### NON-SCORING learning feedback

- Explain the clock-to-wire path concisely as if answering an interview follow-up.
- Run one controlled mismatch experiment only if safe and useful, then restore
  the intended terminal/firmware configuration. This is optional and cannot
  downgrade the day by itself.

No generated extra above silently becomes a scoring requirement.

## 3. Prerequisites

- Knowledge: peripheral clocks, GPIO alternate functions, register read/modify/write,
  integer arithmetic, serial framing, and polling.
- Files: `uart_polling.h`, `uart_polling.c`, `main.c`, and official device/board sources.
- Tools: STM32 ARM GCC build, a verified flash/debug workflow, and a serial terminal.
- Hardware: NUCLEO-F446RE, data cable, and the physically verified serial path.
- Baseline command: `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`

## 4. Starter State

- CMSIS/device headers, startup, linker, reset-clock stub, licenses, provenance,
  and build infrastructure are present.
- `uart_polling.c` is a compile-clean no-op/TODO stub.
- `main.c` is intentionally idle and claims no UART behavior.
- No GPIO/alternate-function choice, register sequence, baud-register value,
  polling status condition, terminal result, or physical observation is supplied.

## 5. Learner TODO

1. Use official sources to identify and record the clock that actually feeds
   USART2 under the clock configuration you will use.
2. Verify the usable NUCLEO-F446RE connector/debugger signal path and the matching
   STM32F446RE GPIO pins and alternate-function selection. Record document IDs,
   revisions, table/page/section, and any hardware-version uncertainty.
3. State the intended baud and framing. Derive the baud-generation relationship,
   rounding/encoding assumptions, and the baud-register value in your own work.
4. Determine the required peripheral/GPIO clock enables and the transmitter,
   receiver, and UART enable flow from RM0390.
5. Determine the status condition that must be observed before each polling TX
   or RX data-register access.
6. Implement `uart_polling_init()`, `uart_polling_write_byte()`, and
   `uart_polling_read_byte()` without HAL/LL calls.
7. Integrate a minimal smoke-test flow in `main.c`; keep it simple enough that
   observed bytes can be attributed to the UART path.
8. Clean-build, flash using a known method, configure the terminal, and perform
   the physical test. Record only observations actually made.
9. Complete `SUBMIT_W03_D01.md` and explain clock source, divider, framing,
   polling conditions, expected behavior, observed behavior, and limitations.

## 6. Test Matrix

| ID | Requirement/behavior | Expected evidence |
|---|---|---|
| W03D01-T01 | Clean starter/learner build | Exact command, exit code, warnings, ELF/map/list/size |
| W03D01-T02 | Clock and baud derivation | Source references plus learner calculation and assumptions |
| W03D01-T03 | Polling TX | Intended byte sequence and physical terminal/loopback observation |
| W03D01-T04 | Polling RX | Intended input and physical received/echoed byte observation |
| W03D01-T05 | Serial framing | Exact terminal baud/data/parity/stop configuration |

## 7. Fault Injection / Negative Tests

Optional, `NON-SCORING learning feedback`: if safe, deliberately create one
controlled terminal-setting mismatch, record the observed symptom, then restore
the intended configuration and rerun the primary smoke test. Do not leave the
system in the mismatched state.

## 8. Evidence to Save

- Exact build command, exit code, warnings, ELF/map/list paths, and size output.
- Exact official document identifiers/revisions and relevant locations used.
- Clock tree assumptions and complete learner-owned baud derivation.
- Exact flash/debug method actually used; otherwise `NOT PERFORMED`.
- Exact terminal application and baud/data/parity/stop settings.
- Expected TX/RX or loopback bytes and observed bytes/log/capture.
- Physical wiring/connector path actually used and any unresolved uncertainty.
- Measurement method and result if baud timing is measured; otherwise `NOT MEASURED`.

## 9. Self-Explanation / Interview Check

Explain why the selected peripheral clock, divider assumptions, status conditions,
and framing produce the intended wire behavior. Explain what a wrong clock or
terminal setting would change and how evidence distinguishes those causes.

## 10. Artifact Definition of Done

The learner implementation builds, the physical UART loopback/log at the intended
baud is captured truthfully, required source/command/configuration evidence is
complete, and remaining uncertainties are explicit. Starter build success alone
is not artifact completion.

## 11. Competency Status

Normal `LEARNING`; not a scored gate. This day cannot independently award a new
`COMPETENCY_PASS`.

## 12. AI Usage Rules

Keep the register-level clock/GPIO/USART configuration, baud derivation, polling
TX/RX bodies, hardware observation, and explanation learner-owned. Record the
highest actual AI assistance at submission/closure; do not backfill AI history.

## 13. Submission Format

Complete `SUBMIT_W03_D01.md` with exact commands, source references, calculations,
configuration, expected-versus-observed evidence, limitations, and AI disclosure.

## 14. Forbidden Shortcuts

- No unexplained hard-coded baud-register constant.
- No copied full vendor UART example.
- No HAL/LL implementation that bypasses register-level reasoning.
- No busy delay used as a substitute for a required UART status condition.
- No invented terminal output, baud measurement, wiring, flash method, or capture.

## 15. Stop Condition

Stop and report instead of guessing if official documents conflict, the physical
board/version or signal path cannot be verified, the actual peripheral clock is
unknown, the build requires out-of-scope infrastructure repair, or an action risks
overwriting learner work.

## 16. Next Physical Action

Open RM0390, the STM32F446RE datasheet/alternate-function tables, and the official
NUCLEO-F446RE board documentation. Before editing code, write down the clock path,
candidate physical signal path, intended framing, and the source location for each.
