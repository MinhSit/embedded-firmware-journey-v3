# TODO — Week 03 / Day 05 — Python serial logger

## Metadata

- Roadmap date: `2026-08-28`
- Starter prepared: `2026-08-27`
- Timezone: `Asia/Ho_Chi_Minh`
- System Spec: `SYSTEM_SPEC_V3 3.0.0`
- Roadmap: `EMBEDDED_ROADMAP_V3.1 3.1.0`
- Week/Day: `W03D05`
- Day type: `LEARNING`
- Execution position at preparation time: `W03D05 NOT STARTED`
- Available Focused Time: `5h — learner supplied`
- Latest independent competency: `W02-C-MCU-FOUND — COMPETENCY_PASS`
- Authoritative trace: W03D05 roadmap day card — write
  `serial_logger.py` with timestamping and log persistence, then use it with the
  physical board; required end-of-day evidence is a working tool plus sample log.

## Outcome

Implement `tools/serial_logger.py` so it receives serial data from the physical
board, attaches a timestamp under a learner-defined contract, and persists an
attributable sample log. This normal learning day is not a competency gate.

## Acceptance Criteria

### MUST — authoritative W03D05 scope

- [ ] `tools/serial_logger.py` timestamps received serial data.
- [ ] The tool persists the received serial evidence to a log.
- [ ] The learner runs the tool with the physical board.
- [ ] A working-tool result and attributable sample log are saved.
- [ ] The learner explains the timestamp and persistence contracts in their own
      words and distinguishes observed facts from assumptions.

### NON-SCORING learning feedback — engineering quality

- Define explicit CLI validation, serial timeout, bytes/text representation,
  decode-error, output-file, and shutdown/resource-cleanup policies.
- Exercise one safe negative case such as an unavailable port or unwritable
  destination, then restore the intended setup.
- Keep one receive iteration bounded and make failures visible with a nonzero
  exit instead of reporting false success.

These generated engineering checks improve practice but do not silently become
additional roadmap PASS requirements.

## Prerequisites

- W03D04 is preserved as `GREEN / CLOSED / ARTIFACT_PASS`; no W03D04 file is to
  be modified for this day.
- Python is available according to Current State. Record the exact interpreter
  used during learner validation.
- The repository had no tracked Python dependency manifest at preparation time.
  Verify the required serial-library package and version before use; do not
  infer that it is installed.
- W03D05 port, baud, framing, board output, and wiring/path are `NOT RECORDED` at
  preparation time. Establish them from the actual session rather than copying
  a prior-day observation.

## Starter State

- `tools/serial_logger.py` contains imports, an `argparse` interface skeleton,
  function signatures, and learner TODOs only.
- `python tools/serial_logger.py --help` is expected to succeed.
- A real logging invocation is expected to raise `NotImplementedError` until the
  learner implements the core exercise.
- No serial receive loop, timestamp formatting, persistence behavior,
  timeout/decode policy, or shutdown handling is implemented.
- No sample log, hardware observation, artifact result, or competency result is
  created by starter preparation.

## Learner TODO

1. Verify the Python interpreter and serial-library package/version you will use.
2. Confirm the physical board's actual serial port, baud, data bits, parity, and
   stop bits for this run. Do not reuse old values without checking.
3. Define the timestamp contract: clock source, timezone, precision, and exact
   serialized format. Explain why it is sufficient for the evidence.
4. Define the persistence contract: file creation/append policy, record
   boundaries, byte-versus-text representation, flushing, and failure behavior.
5. Implement argument validation and serial-port acquisition without embedding
   machine-specific defaults as evidence.
6. Implement the receive loop and bounded read behavior.
7. Implement timestamp generation and record persistence.
8. Decide and implement timeout, robust decode/raw-byte, error, and Ctrl+C
   shutdown/resource-cleanup behavior. These are engineering-quality items and
   remain `NON-SCORING learning feedback` unless Project Chat traces them to a
   higher-authority requirement.
9. Run the tool with the physical board, save a sample log, and record exact
   expected versus observed results.
10. Complete `SUBMIT_W03_D05.md` with only learner-supplied or tool-verified facts.

## Test / Validation Matrix

| ID | Check | Starter expectation | Day evidence |
|---|---|---|---|
| W03D05-S01 | Python syntax/import | PASS | Exact command and exit code |
| W03D05-S02 | `--help` interface | PASS | Visible usage only |
| W03D05-S03 | Real logging invocation | EXPECTED NOT PASS | Learner core pending |
| W03D05-T01 | Timestamp attached to received data | NOT RUN | Expected/observed records |
| W03D05-T02 | Log persistence | NOT RUN | File path and sample content |
| W03D05-T03 | Physical-board use | NOT RUN | Port/config plus attributable run |
| W03D05-N01 | Safe negative/failure case | OPTIONAL / NON-SCORING | Failure and recovery evidence |

Starter checks validate infrastructure only. They cannot prove working serial
I/O, physical-board behavior, `ARTIFACT_PASS`, or competency.

## Negative / Failure Case

`NON-SCORING learning feedback`: select one safe failure that cannot damage
learner work, such as an unavailable serial port or unwritable output location.
Predict the result first, verify a clear failure/nonzero exit, restore the valid
configuration, and rerun the primary case. Do not invent a failure observation.

## Evidence to Save

- Exact interpreter and serial-library versions actually used.
- Exact invocation, port, baud, data/parity/stop configuration, and output path.
- Timestamp contract and persistence/representation contract.
- Expected board payload and actual received records.
- Attributable sample log containing actual timestamps and board output.
- Exit code, stderr/stdout, and any safe negative-case evidence actually run.
- Highest AI level actually used and the specific files/functions assisted.
- Learner self-explanation of timestamp semantics, record boundaries, byte/text
  handling, persistence failures, and shutdown behavior.

Use `NOT PERFORMED`, `NOT MEASURED`, or `NOT RECORDED` where evidence is absent.

## Self-Explanation Check

1. What event does each timestamp represent, and which clock/timezone produces it?
2. How can a reviewer distinguish record boundaries and recover the received data?
3. What happens when no byte arrives before the timeout?
4. How are arbitrary/non-UTF-8 bytes handled without silently corrupting evidence?
5. When is data flushed, and what failure can still lose buffered log records?
6. What resources must be released on normal exit, error, and Ctrl+C?

## AI Usage Rules

- Executor-prepared files are AI-assisted infrastructure, not independent
  competency evidence.
- Keep the receive loop, timestamp formatting, persistence behavior,
  timeout/decode policy, error handling, shutdown behavior, hardware run, and
  self-explanation learner-owned.
- AI-1 may clarify theory; AI-2 may give graded hints after an attempt; AI-3 may
  review/debug after a meaningful implementation attempt.
- Record the highest assistance actually used. Do not claim AI-0 or independent
  competency from this assisted starter.

## Submission Format

Complete `learning/week-03/day-05/SUBMIT_W03_D05.md`. Preserve exact commands,
versions, configuration, expected/observed records, sample-log path, limitations,
and AI disclosure. Do not replace missing facts with inferred values.

## Forbidden Shortcuts

- No copied/generated complete serial logger or hidden reference solution before
  a meaningful learner attempt.
- No fabricated COM port, baud, framing, UART payload, timestamp, sample log,
  hardware observation, exit code, measurement, or PASS result.
- No tests/comments/documentation that disclose the completed receive,
  timestamp, persistence, timeout/decode, or shutdown implementation.
- No hard-coded local machine path presented as portable behavior.
- No broad exception swallowing or false-success exit on logging failure.
- No W03D04 edits, control/bookkeeping mutation, unrelated refactor, hardware
  flashing, END DAY closure, or competency claim during starter preparation.

## Stop Condition

Starter preparation stops after the three allowlisted files pass syntax/import,
`--help`, solution-boundary, path, and Git hygiene checks. The learning day may
close only after the learner-owned tool works with the physical board and an
attributable sample log exists; closure requires a separate authorized workflow.

Stop and report rather than guessing if the port/configuration or dependency
cannot be verified, learner work appears unexpectedly, the core solution would
need to be exposed, or an out-of-scope change is required.

## Next Physical Action Placeholder

`TO BE SET BY PROJECT CHAT after independent prep verification and Day Contract completion.`
