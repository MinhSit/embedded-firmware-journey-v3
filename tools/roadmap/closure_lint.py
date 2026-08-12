#!/usr/bin/env python3
"""Read-only structural checks for roadmap closure records.

This helper validates only machine-verifiable control fields. It does not edit
the repository, judge technical correctness, or award competency PASS.
"""

from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass
from pathlib import Path


DAILY_LOG = Path("roadmap-control/daily-log.md")
CURRENT_STATE = Path("roadmap-control/current-state.md")
COMPETENCY_LEDGER = Path("roadmap-control/competency-ledger.md")

DAY_HEADING_RE = re.compile(
    r"^##\s+(?P<date>\d{4}-\d{2}-\d{2})\s+[—-]\s+"
    r"Week\s+(?P<week>\d{2})\s*/\s*Day\s+(?P<day>\d{2})\s*$",
    re.MULTILINE,
)
SECTION_RE = re.compile(r"^###\s+(?P<number>\d+)\.\s+.+$", re.MULTILINE)
VALID_DAILY_STATUS_RE = re.compile(r"^(GREEN|YELLOW|RED)(?:\s|$)")
AI_LEVEL_RE = re.compile(r"\bAI-[0-5]\b")
COMPETENCY_ID_RE = re.compile(r"\bW\d{2}-C-[A-Z0-9-]+\b")
COMPETENCY_STATUS_RE = re.compile(
    r"\b(?:NOT_STARTED|LEARNING|IMPLEMENTING|ARTIFACT_PASS|"
    r"COMPETENCY_UNVERIFIED|COMPETENCY_PASS|PARTIAL|BLOCKED|"
    r"INVALIDATED|RECOVERY|FAIL)\b"
)
PLACEHOLDER_RE = re.compile(
    r"\b(?:TBD|UNKNOWN|NOT\s+RECORDED)\b|Không được ghi nhận",
    re.IGNORECASE,
)


@dataclass(frozen=True)
class Result:
    scope: str
    name: str
    level: str
    detail: str


@dataclass(frozen=True)
class DailyEntry:
    day_id: str
    body: str
    sections: dict[int, str]


def read_text(root: Path, relative_path: Path) -> str:
    path = root / relative_path
    try:
        return path.read_text(encoding="utf-8")
    except (OSError, UnicodeError) as exc:
        raise RuntimeError(f"cannot read {relative_path.as_posix()}: {exc}") from exc


def parse_sections(body: str) -> dict[int, str]:
    matches = list(SECTION_RE.finditer(body))
    sections: dict[int, str] = {}
    for index, match in enumerate(matches):
        end = matches[index + 1].start() if index + 1 < len(matches) else len(body)
        number = int(match.group("number"))
        sections[number] = body[match.end() : end].strip()
    return sections


def parse_daily_entries(text: str) -> list[DailyEntry]:
    # Operating rules defer concrete daily-log records until END DAY, so every
    # dated Week/Day entry is a closure record; the schema template is excluded.
    matches = list(DAY_HEADING_RE.finditer(text))
    entries: list[DailyEntry] = []
    for index, match in enumerate(matches):
        end = matches[index + 1].start() if index + 1 < len(matches) else len(text)
        body = text[match.end() : end].strip()
        day_id = f"W{match.group('week')}D{match.group('day')}"
        entries.append(DailyEntry(day_id, body, parse_sections(body)))
    return entries


def field_value(section: str, label: str) -> str | None:
    match = re.search(
        rf"^\s*{re.escape(label)}\s*:\s*(.*?)\s*$",
        section,
        re.MULTILINE | re.IGNORECASE,
    )
    return match.group(1).strip() if match else None


def first_content_line(section: str) -> str:
    for line in section.splitlines():
        value = line.strip()
        if value:
            return value
    return ""


def placeholder_level(value: str) -> str | None:
    matches = list(PLACEHOLDER_RE.finditer(value))
    if not matches:
        return None

    remainder = PLACEHOLDER_RE.sub("", value)
    remainder = re.sub(r"[`*_\s/|:;,—–-]+", "", remainder)
    return "WARN" if len(remainder) >= 4 else "FAIL"


def check_mandatory_value(
    scope: str, name: str, value: str | None, *, allow_explained: bool = False
) -> Result:
    if value is None or not value.strip():
        return Result(scope, name, "FAIL", "missing or empty")

    level = placeholder_level(value)
    if level is None:
        return Result(scope, name, "PASS", value)
    if level == "WARN" and allow_explained:
        return Result(scope, name, "WARN", f"explained placeholder: {value}")
    return Result(scope, name, "FAIL", f"unresolved placeholder: {value}")


def lint_daily_entry(entry: DailyEntry) -> list[Result]:
    results: list[Result] = []

    status_text = first_content_line(entry.sections.get(2, ""))
    status_match = VALID_DAILY_STATUS_RE.match(status_text)
    if status_match:
        results.append(Result(entry.day_id, "status", "PASS", status_match.group(1)))
    elif status_text:
        results.append(
            Result(entry.day_id, "status", "FAIL", f"invalid Actual Status: {status_text}")
        )
    else:
        results.append(Result(entry.day_id, "status", "FAIL", "missing Actual Status"))

    focused_time = entry.sections.get(3, "")
    planned = field_value(focused_time, "Planned")
    actual = field_value(focused_time, "Actual")
    planned_result = check_mandatory_value(entry.day_id, "planned", planned)
    actual_result = check_mandatory_value(
        entry.day_id, "actual", actual, allow_explained=True
    )
    if planned_result.level == "PASS" and actual_result.level == "PASS":
        results.append(
            Result(
                entry.day_id,
                "focused-time",
                "PASS",
                f"Planned: {planned}; Actual: {actual}",
            )
        )
    else:
        level = "FAIL" if "FAIL" in (planned_result.level, actual_result.level) else "WARN"
        details = "; ".join(
            result.detail
            for result in (planned_result, actual_result)
            if result.level != "PASS"
        )
        results.append(Result(entry.day_id, "focused-time", level, details))

    artifact = entry.sections.get(6, "").strip()
    if artifact:
        results.append(Result(entry.day_id, "artifact-result", "PASS", "section present"))
    else:
        results.append(Result(entry.day_id, "artifact-result", "FAIL", "missing or empty"))

    ai_usage = entry.sections.get(5, "")
    highest_ai = field_value(ai_usage, "Highest AI level used")
    if highest_ai and AI_LEVEL_RE.search(highest_ai):
        results.append(Result(entry.day_id, "AI-provenance", "PASS", highest_ai))
    elif highest_ai:
        results.append(
            Result(entry.day_id, "AI-provenance", "FAIL", f"invalid AI level: {highest_ai}")
        )
    else:
        results.append(
            Result(entry.day_id, "AI-provenance", "FAIL", "missing highest AI level")
        )

    next_action = first_content_line(entry.sections.get(12, ""))
    results.append(check_mandatory_value(entry.day_id, "next-action", next_action))
    return results


def current_state_value(text: str, label: str) -> str | None:
    match = re.search(
        rf"^\s*-\s+\*\*{re.escape(label)}:\*\*\s*(.*?)\s*$",
        text,
        re.MULTILINE | re.IGNORECASE,
    )
    return match.group(1).strip() if match else None


def ledger_statuses(text: str) -> dict[str, str]:
    heading_re = re.compile(
        r"^##\s+(?P<id>W\d{2}-C-[A-Z0-9-]+)\s+[—-].*$", re.MULTILINE
    )
    matches = list(heading_re.finditer(text))
    statuses: dict[str, str] = {}
    for index, match in enumerate(matches):
        end = matches[index + 1].start() if index + 1 < len(matches) else len(text)
        body = text[match.end() : end]
        status_match = re.search(
            r"^Status:\s*\n\s*([A-Z_]+)\s*$", body, re.MULTILINE
        )
        if status_match:
            statuses[match.group("id")] = status_match.group(1)
    return statuses


def lint_current_state(current: str, ledger: str) -> list[Result]:
    scope = "CURRENT STATE"
    labels = (
        ("Execution position", "execution-position"),
        ("Artifact position", "artifact-position"),
        ("Competency position", "competency-position"),
        ("Exact Next Action", "exact-next-action"),
    )
    values: dict[str, str | None] = {}
    results: list[Result] = []
    for label, output_name in labels:
        value = current_state_value(current, label)
        values[label] = value
        results.append(check_mandatory_value(scope, output_name, value))

    competency = values["Competency position"] or ""
    competency_id = COMPETENCY_ID_RE.search(competency)
    current_status = COMPETENCY_STATUS_RE.search(competency)
    if not competency_id or not current_status:
        results.append(
            Result(
                scope,
                "competency-consistency",
                "FAIL",
                "cannot parse competency ID/status from Current State",
            )
        )
        return results

    ledger_status = ledger_statuses(ledger).get(competency_id.group(0))
    if ledger_status is None:
        results.append(
            Result(
                scope,
                "competency-consistency",
                "FAIL",
                f"{competency_id.group(0)} missing status in Competency Ledger",
            )
        )
    elif ledger_status != current_status.group(0):
        results.append(
            Result(
                scope,
                "competency-consistency",
                "FAIL",
                f"Current State={current_status.group(0)}; Ledger={ledger_status}",
            )
        )
    else:
        results.append(
            Result(
                scope,
                "competency-consistency",
                "PASS",
                f"{competency_id.group(0)}={ledger_status}",
            )
        )
    return results


def run(root: Path) -> list[Result]:
    daily = read_text(root, DAILY_LOG)
    current = read_text(root, CURRENT_STATE)
    ledger = read_text(root, COMPETENCY_LEDGER)

    entries = parse_daily_entries(daily)
    if not entries:
        return [Result("DAILY LOG", "closed-days", "FAIL", "no concrete day entries")]

    results: list[Result] = []
    for entry in entries:
        results.extend(lint_daily_entry(entry))
    results.extend(lint_current_state(current, ledger))
    return results


def print_report(results: list[Result]) -> None:
    print("ROADMAP CLOSURE LINT")
    print()
    scopes: list[str] = []
    for result in results:
        if result.scope not in scopes:
            scopes.append(result.scope)
    for scope in scopes:
        print(f"{scope}:")
        for result in results:
            if result.scope == scope:
                print(f"  {result.level} {result.name} — {result.detail}")
        print()

    counts = {
        level: sum(result.level == level for result in results)
        for level in ("FAIL", "WARN", "PASS")
    }
    print("SUMMARY:")
    print(f"{counts['FAIL']} FAIL")
    print(f"{counts['WARN']} WARN")
    print(f"{counts['PASS']} PASS")


def parse_args() -> argparse.Namespace:
    default_root = Path(__file__).resolve().parents[2]
    parser = argparse.ArgumentParser(
        description="Read-only structural lint for roadmap closure records."
    )
    parser.add_argument(
        "--root",
        type=Path,
        default=default_root,
        help="repository root (default: inferred from this script)",
    )
    return parser.parse_args()


def main() -> int:
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    if hasattr(sys.stderr, "reconfigure"):
        sys.stderr.reconfigure(encoding="utf-8")
    args = parse_args()
    try:
        results = run(args.root.resolve())
    except RuntimeError as exc:
        print("ROADMAP CLOSURE LINT", file=sys.stderr)
        print(f"FAIL input — {exc}", file=sys.stderr)
        print("SUMMARY:\n1 FAIL\n0 WARN\n0 PASS", file=sys.stderr)
        return 1

    print_report(results)
    return 1 if any(result.level == "FAIL" for result in results) else 0


if __name__ == "__main__":
    raise SystemExit(main())
