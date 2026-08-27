# SUBMIT — Week 03 / Day 05 — Python serial logger

This record contains learner-supplied or executor-verified facts only. This
normal-learning artifact is not independent competency evidence.

## Identity and Provenance

- Roadmap date: `2026-08-28`
- Actual execution date: `2026-08-27 — intentionally started early within Week 3`
- Physical board/MCU: `NUCLEO-F446RE / STM32F446RE`
- Operating system: `Windows / PowerShell — executor-observed environment`
- Python executable/version: `python / Python 3.12.0 — executor verified`
- Serial-library package/version: `pyserial 3.5 — executor verified`
- Available Focused Time: `5h — learner supplied`
- Planned Focused Time: `5h — learner supplied`
- Actual Focused Time: `3h — learner supplied`
- Planned-vs-actual variance: `-2h; no schedule debt inferred`
- Health impact: `NOT RECORDED`
- Highest AI Level Actually Used: `AI-3`
- Commit: `SELF — containing closure commit`
- AI Disclosure: `Executor prepared the W03D05 TODO/submission templates and a
  TODO-only argparse/function-signature scaffold. Project Chat provided theory,
  review, and debugging only after meaningful learner attempts; it did not
  write the learner's complete core solution. The learner owned the final
  serial receive, timestamp, persistence, boundary/error, hardware run, and
  self-explanation work.`

## Learner-Owned Contract

- CLI/interface behavior: `argparse requires --port, --baud, and --output; no
  machine-specific port, baud, or output default is embedded.`
- Timestamp clock source/timezone/precision/format: `PC/logger observation time;
  UTC; ISO 8601; microsecond precision; [YYYY-MM-DDTHH:MM:SS.ffffffZ].`
- Timestamp event semantics: `Timestamp is generated after a complete newline-
  terminated record is received by the logger; it is not a board timestamp or
  wire-level timing measurement.`
- Serial timeout/read policy: `8N1, timeout=1.0 s, reads at most 128 bytes per
  iteration; an empty timed read is idle/no data and the loop continues.`
- Raw-byte versus decoded-text representation: `HEX_RAW is the authoritative
  representation of bytes delivered to the software. DECODED_VIEW is a
  secondary human-readable UTF-8/escaped representation.`
- Decode-error policy: `UTF-8 decode uses backslash replacement; backslashes,
  CR, LF, and TAB are escaped so each persisted record remains one log line.`
- Output create/append/overwrite policy: `Parent directories are created as
  needed; the UTF-8 log is opened in append mode for each complete record.`
- Record-boundary and flush policy: `A complete record ends at b'\n'. Each valid
  complete record is persisted and flushed immediately. MAX_PENDING_BYTES is
  4096; oversized complete records and pending fragments are fatal/nonzero and
  are not persisted as valid lines.`
- Error exit behavior: `serial.SerialException returns 1; oversized record or
  pending fragment returns 2; other I/O failures propagate as nonzero errors.`
- Ctrl+C/shutdown/resource-cleanup behavior: `KeyboardInterrupt during the
  receive loop prints a graceful-stop message, exits the loop, and the serial
  context manager closes the port before returning 0.`

## Serial and Hardware Configuration

- Port: `COM4`
- Baud: `115200`
- Data bits: `8`
- Parity: `N / none`
- Stop bits: `1`
- Flow control: `NOT RECORDED`
- Physical signal/connector path: `NUCLEO-F446RE UART reached the PC as COM4;
  exact board connector/bridge path was not separately recorded.`
- Board firmware/output source: `Controlled one-shot LOGGER_TEST\r\n startup
  transmission temporarily added to the W03D04 firmware solely for evidence
  capture, then manually reverted.`
- Firmware baud tie: `Final tracked W03D04 source calls
  uart_init(16000000U, 115200U), matching the logger's 115200 baud.`
- Controlled temporary-test build: `PASS; text=1776, data=0, bss=1592,
  dec=3368, hex=d28; inherited nosys warnings only. This size belongs only to
  the temporary physical-evidence mutation and is not the canonical W03D04
  artifact size.`
- Final firmware restoration verification: `PASS — LOGGER_TEST is absent;
  tracked main.c is unchanged from HEAD and contains only 115200-baud init,
  uart_rx_get_byte(), and uart_write_byte() echo behavior.`
- Flash/debug method, if used: `NOT RECORDED`

## Validation Evidence

- Syntax/import command: `python -m py_compile .\tools\serial_logger.py`
- Syntax/import exit/result: `PASS / exit 0 after executor rerun`
- Help command/result: `python -B .\tools\serial_logger.py --help` — `PASS / exit 0`
- Exact logger invocation: `python -B .\tools\serial_logger.py --port COM4
  --baud 115200 --output .\learning\week-03\day-05\sample_uart.log`
- Logger exit/result: `COM4 opened and connected at 115200; Ctrl+C graceful
  shutdown observed. Original shell exit code was not separately recorded.`
- Expected received data: `LOGGER_TEST\r\n from the controlled one-shot firmware
  test mutation.`
- Actual received data: `HEX_RAW 4c4f474745525f544553540d0a, which decodes to
  LOGGER_TEST\r\n.`
- Expected timestamp/log behavior: `One PC-observation UTC timestamp plus
  authoritative hex bytes and one-line decoded view, flushed to the output.`
- Actual timestamp/log behavior: `[2026-08-27T10:51:49.572892Z]
  4c4f474745525f544553540d0a | LOGGER_TEST\r\n was persisted.`
- Executor bounded regression validation: `5 tests, 0 failed — timestamp and
  persistence regressions, split/multiple complete records, graceful Ctrl+C,
  4097-byte complete-record rejection, 4224-byte pending-fragment rejection,
  and SerialException nonzero behavior.`

## Working Tool and Sample Log

- Working tool demonstrated with physical board: `YES — learner supplied
  physical-run evidence; executor verified the persisted file.`
- Sample log path: `learning/week-03/day-05/sample_uart.log`
- Sample log size/record count: `76 bytes / 1 complete record — executor verified`
- Sample log SHA-256: `4B8FDCE98D894A83D4B4D5EA68E8FFFE441315A62B14A598517E1900CEED0AC9`
- Sample log start/end timestamps: `2026-08-27T10:51:49.572892Z / same single record`
- Representative actual records: `[2026-08-27T10:51:49.572892Z]
  4c4f474745525f544553540d0a | LOGGER_TEST\r\n`
- Attribution method linking the log to this board run: `The learner used a
  deterministic one-shot LOGGER_TEST\r\n firmware payload, invoked the logger on
  COM4 at the matching 115200 baud, and the persisted authoritative HEX_RAW
  matches that payload byte-for-byte. The temporary firmware mutation was then
  reverted.`
- Persistence/reopen verification: `PASS — executor reopened and parsed the
  persisted file; it contains one attributable record.`

Do not paste invented/example timestamps or payloads into this evidence section.

## Optional Negative Case — NON-SCORING Learning Feedback

- Failure selected and pre-run prediction: `NOT PERFORMED as learner physical
  evidence; executor separately exercised bounded synthetic regressions.`
- Exact command/setup: `Executor imported serial_logger with controlled fake
  serial streams; no physical port or learner evidence was overwritten.`
- Actual failure/exit behavior: `Oversized complete record and pending fragment
  returned 2 without valid-line persistence; controlled SerialException
  returned 1.`
- Valid configuration restored and primary case rerun: `Physical configuration
  had already been restored; final W03D04 source and sample evidence were
  independently rechecked.`

This optional case cannot independently change the roadmap result.

## Learner Self-Explanation

- Timestamp semantics: `The recorded contract and sample establish PC/logger
  UTC observation time; no separate learner oral explanation of timestamp
  semantics beyond the supplied timeout/HEX_RAW self-explain was recorded.`
- Record boundaries and evidence recoverability: `PASS — learner explained that
  HEX_RAW preserves bytes delivered to software and is authoritative; the
  decoded/escaped view is transformed and secondary.`
- Timeout behavior: `PASS — empty timed read means idle/no data and the loop
  continues; it is not treated as physical disconnect or fatal error.`
- Arbitrary/non-UTF-8 byte handling: `Executor regression verified no decode
  crash and retained an escaped secondary view; no additional learner oral
  explanation was recorded.`
- Persistence/flush failure modes: `Code flushes after each persisted record;
  no additional learner oral explanation of host/filesystem failure modes was
  recorded.`
- Normal/error/Ctrl+C cleanup: `Ctrl+C graceful shutdown was physically
  observed and executor-regressed; no additional learner oral explanation was
  recorded.`
- Evidence class: `Assisted learning/self-check only; not a competency gate.`

## Final Boundary

- Known limitations: `HEX_RAW proves bytes delivered to the logger software,
  not electrical bit-level integrity on the wire. Only newline-terminated
  records are valid; a short pending fragment is not persisted on shutdown.
  MAX_PENDING_BYTES is fixed at 4096. Flow-control and exact connector/bridge
  details were not recorded.`
- Blockers: `NONE`
- Carry-over: `NONE`
- Recovery: `NOT ACTIVE`
- Artifact result: `ARTIFACT_PASS`
- Competency result: `NONE — normal learning day; no competency gate`
- Lifecycle/status: `GREEN / CLOSED`
- Next action: `BOOT W03D06 — open the authoritative W03D06 roadmap day card
  before defining the controlled fault-injection/debug Day Contract.`

The physical sample plus independent artifact validation support
`ARTIFACT_PASS`. They do not create `COMPETENCY_PASS`.
