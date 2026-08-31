"""W03D05 learner serial logger for timestamped evidence logging."""

from __future__ import annotations

import argparse
from collections.abc import Sequence
from datetime import datetime, timezone
from pathlib import Path
import sys

import serial

MAX_PENDING_BYTES = 4096


def build_argument_parser() -> argparse.ArgumentParser:
    """Build the command-line interface parser."""
    parser = argparse.ArgumentParser(
        description="Receive board serial data and persist timestamped records.",
    )
    parser.add_argument("--port", required=True, help="Serial port for this run")
    parser.add_argument("--baud", required=True, type=int, help="Baud for this run")
    parser.add_argument(
        "--output",
        required=True,
        type=Path,
        help="Destination log path",
    )
    return parser


def make_timestamp() -> str:
    """Return an ISO 8601 UTC timestamp with microsecond precision enclosed in brackets."""
    now = datetime.now(timezone.utc)
    return f"[{now.strftime('%Y-%m-%dT%H:%M:%S.%f')}Z]"


def persist_record(output_path: Path, timestamp: str, received: bytes) -> None:
    """Persist one received record under the authoritative evidence contract.

    Format: <TIMESTAMP> <HEX_RAW> | <DECODED_VIEW>
    - HEX_RAW: authoritative binary byte string.
    - DECODED_VIEW: human-readable UTF-8 string with escaped control characters.
    """
    hex_raw = received.hex()
    raw_text = received.decode("utf-8", errors="backslashreplace")

    decoded_view = (
        raw_text.replace("\\", "\\\\")
        .replace("\r", "\\r")
        .replace("\n", "\\n")
        .replace("\t", "\\t")
    )

    output_path.parent.mkdir(parents=True, exist_ok=True)
    with output_path.open(mode="a", encoding="utf-8") as f:
        f.write(f"{timestamp} {hex_raw} | {decoded_view}\n")
        f.flush()


def run_logger(*, port: str, baud: int, output_path: Path) -> int:

    print(f"[LOGGER] Opening {port} at {baud} baud (8N1, timeout=1.0s)...")
    buffer = bytearray()

    try:
        with serial.Serial(
            port=port,
            baudrate=baud,
            bytesize=serial.EIGHTBITS,
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            timeout=1.0,
        ) as ser:
            print(f"[LOGGER] Connected. Logging to '{output_path}' (Press Ctrl+C to stop).")

            while True:
                try:
                    chunk = ser.read(128)
                    if not chunk:
                        continue

                    buffer.extend(chunk)

                    # Tách và persist toàn bộ complete records kết thúc bằng b'\n'
                    while b"\n" in buffer:
                        newline_pos = buffer.index(b"\n")
                        record_len = newline_pos + 1

                        if record_len > MAX_PENDING_BYTES:
                            print(
                                f"[LOGGER FATAL] Complete record size ({record_len} B) exceeded "
                                f"MAX_PENDING_BYTES ({MAX_PENDING_BYTES} B). Aborting run.",
                                file=sys.stderr,
                            )
                            return 2

                        complete_record = bytes(buffer[:record_len])
                        del buffer[:record_len]

                        ts = make_timestamp()
                        persist_record(output_path, ts, complete_record)

                    # Kiểm tra pending buffer dở dang chưa gặp b'\n'
                    if len(buffer) > MAX_PENDING_BYTES:
                        print(
                            f"[LOGGER FATAL] Pending buffer ({len(buffer)} B) exceeded "
                            f"MAX_PENDING_BYTES ({MAX_PENDING_BYTES} B) without delimiter b'\\n'. Aborting run.",
                            file=sys.stderr,
                        )
                        return 2

                except KeyboardInterrupt:
                    print("\n[LOGGER] Stop signal received (Ctrl+C). Graceful shutdown.")
                    break

        return 0

    except serial.SerialException as exc:
        print(f"[LOGGER ERROR] Serial communication failed: {exc}", file=sys.stderr)
        return 1


def main(argv: Sequence[str] | None = None) -> int:
    """Parse CLI inputs and hand them to the logger core."""
    args = build_argument_parser().parse_args(argv)
    return run_logger(port=args.port, baud=args.baud, output_path=args.output)


if __name__ == "__main__":
    raise SystemExit(main())
