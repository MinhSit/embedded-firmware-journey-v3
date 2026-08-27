"""W03D05 learner starter for a timestamped Python serial logger.

This module intentionally contains no serial receive, timestamp formatting,
log-persistence, timeout/decode, or shutdown solution.
"""

from __future__ import annotations

import argparse
from collections.abc import Sequence
from pathlib import Path


def build_argument_parser() -> argparse.ArgumentParser:
    """Build the learner-facing command-line interface skeleton."""

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
    """Return one timestamp under the learner-defined timestamp contract."""

    # TODO(learner): Define and implement clock, timezone, precision, and format.
    raise NotImplementedError("learner TODO: implement timestamp formatting")


def persist_record(output_path: Path, timestamp: str, received: bytes) -> None:
    """Persist one received record under the learner-defined file contract."""

    # TODO(learner): Define record boundaries, byte/text representation, and flush.
    _ = (output_path, timestamp, received)
    raise NotImplementedError("learner TODO: implement log persistence")


def run_logger(*, port: str, baud: int, output_path: Path) -> int:
    """Run the learner-owned serial receive and logging workflow."""

    # TODO(learner): Verify the dependency and implement serial acquisition.
    # TODO(learner): Implement the bounded receive loop and timestamp each record.
    # TODO(learner): Decide timeout, raw/decode, error, and shutdown policies.
    _ = (port, baud, output_path)
    raise NotImplementedError("learner TODO: implement the serial logger core")


def main(argv: Sequence[str] | None = None) -> int:
    """Parse CLI inputs and hand them to the learner-owned logger core."""

    args = build_argument_parser().parse_args(argv)
    return run_logger(port=args.port, baud=args.baud, output_path=args.output)


if __name__ == "__main__":
    raise SystemExit(main())
