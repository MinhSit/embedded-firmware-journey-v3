# TODO — Week 01 / Day 03 — Struct, Alignment và Endian

## 0. Metadata

Date: 2026-08-12
Timezone: Asia/Ho_Chi_Minh
System Spec: 3.0.0
Roadmap: 3.1.0
Week/Day: W01D03
Calendar Position: W01D03
Execution Position: W01D03 — start after BOOT
Artifact Position at start: W01D02 ARTIFACT_PASS
Competency Position: W01-C-FOUND — COMPETENCY_UNVERIFIED
Available Time: TBD; use ~6–7 focused hours if today is a normal roadmap day
Toolchain: Host GCC 14.2.0 / C17
AI Mode Used: AI-1 theory, AI-2 hints, AI-3 review/debug, AI-4 bounded code/syntax assistance after own attempts
Source: Week 1 Day 3 roadmap card; System Spec AI/evidence rules

## 1. Outcome

Đến cuối ngày, tôi sẽ có host tests + `alignment-note.md` chứng minh tôi đã đo và giải thích struct padding/alignment/endian bằng `sizeof/_Alignof/offsetof`, đồng thời tự implement byte-swap + endian detection.

## 2. Acceptance Criteria

### MUST

- [ ] Trả lời pre-check trước khi code.
  - NOT MET (historical / non-recoverable).
  - Flow was changed to theory-first because prerequisite understanding was insufficient.
  - Do not count as independent pre-check evidence.
- [x] Predict layout A/B trước khi chạy measurement.
- [x] `inspect_layout_a()` và `inspect_layout_b()` trả đúng `sizeof/_Alignof/offsetof`.
- [x] `byte_swap_u16()` PASS known-pattern + boundary + involution tests.
- [x] `byte_swap_u32()` PASS known-pattern + boundary + involution tests.
- [x] `detect_host_endian()` khớp independent byte-observation trong test harness.
- [x] Host build sạch với `-Wall -Wextra -Wpedantic -Werror`.
- [x] Final host tests PASS.
- [x] `alignment-note.md` có prediction -> observed -> explanation.
- [x] Closed-book: giải thích padding vs alignment, tail padding, endian, và vì sao raw struct serialization không portable.
  - Initial mini closed-book check after implementation: 6 PASS, 1 PARTIAL.
  - Initial raw-struct answer identified layout/padding risk but omitted endian risk.
  - Fresh independent retest completed without hints: PASS.
  - Fresh retest correctly identified both ABI/layout-padding risk and endian mismatch risk.
  - This remains practice-level evidence and is not an AI-0 competency PASS.

### SHOULD

- [x] Ghi một observation về việc đổi member order ảnh hưởng `sizeof` trên host hiện tại.
- [x] Nêu phần nào là C concept, phần nào là implementation/ABI-specific observation.

### BONUS

- [ ] Tạo một layout C riêng và dự đoán trước khi đo. Không dùng packing extension.

## 3. Prerequisites

Knowledge: pointer/array basics, fixed-width integer types, storage concepts from W01D01-D02.
Files: starter pack W01D03.
Tools: GCC, terminal.
Hardware: none.

Baseline build:

```powershell
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror learning/week-01/day-03/struct_layout.c tests/host/test_struct_layout.c -Ilearning/week-01/day-03 -o tests/host/test_struct_layout.exe
```

Baseline run:

```powershell
.\tests\host\test_struct_layout.exe
```

Initial expectation: compile PASS, some tests FAIL because core functions are TODO stubs.

## 4. Starter State

- `struct_layout.h` — types/API contract.
- `struct_layout.c` — compile-clean TODO stubs.
- `test_struct_layout.c` — visible test harness.
- `alignment-note.md` — prediction/measurement template.

## 5. Learner TODO

### Phase A — Closed-book pre-check

Answer the six questions in THEORY without AI. Do not chase perfect wording; record misconceptions.

### Phase B — Prediction before measurement

In `alignment-note.md`, predict for `layout_a_t` and `layout_b_t`:

- total size;
- struct alignment;
- offset of each member;
- where you expect internal/tail padding.

### Phase C — Implement layout inspection

Implement:

- `inspect_layout_a()`
- `inspect_layout_b()`

Constraint: use `sizeof`, `_Alignof`, `offsetof`; do not hard-code measured numeric offsets.

### Phase D — Implement endian helpers

Implement:

- `byte_swap_u16()`
- `byte_swap_u32()`
- `detect_host_endian()`

Constraints:

- fixed-width unsigned types;
- no raw struct serialization;
- no compiler built-in byte-swap for the core attempt;
- no union-punning shortcut for host-endian detection;
- avoid signed-shift assumptions.

### Phase E — Test and explain

Run tests until PASS. Then fill the note from actual measurements and explain any prediction mismatch.

## 6. Test Matrix

| Test ID | Category | Requirement |
|---|---|---|
| D03-T01 | normal | layout A reported values equal language operators/macros |
| D03-T02 | normal | layout B reported values equal language operators/macros |
| D03-T03 | invariant | member offsets satisfy required alignment on this implementation |
| D03-T04 | union observation | union storage begins at same address for its members |
| D03-T05 | normal | 16-bit known byte-swap pattern |
| D03-T06 | boundary | 16-bit zero/all-ones |
| D03-T07 | invariant | 16-bit swap twice returns original |
| D03-T08 | normal | 32-bit known byte-swap pattern |
| D03-T09 | boundary | 32-bit zero/all-ones |
| D03-T10 | invariant | 32-bit swap twice returns original |
| D03-T11 | environment | host-endian result matches independent byte observation |

## 7. Fault / Negative Thinking

No artificial crash is required today. Use these reasoning negatives:

- hard-code observed offsets, then ask what happens on another ABI;
- imagine sending `layout_a_t` raw bytes over UART to a different compiler/CPU;
- explain what breaks if byte order is assumed but never encoded in protocol spec.

## 8. Evidence to Save

Required:

- `learning/week-01/day-03/alignment-note.md`
- final sanitized verification record at `evidence/week-01/day-03/test_struct_layout.txt`
- final source + tests

Reproduction commands:

```powershell
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror learning/week-01/day-03/struct_layout.c tests/host/test_struct_layout.c -Ilearning/week-01/day-03 -o tests/host/test_struct_layout.exe
.\tests\host\test_struct_layout.exe
```

The tracked `.txt` record contains the command/result metadata and sanitized
test output. Raw `*.log` files remain ignored by repository policy.

## 9. Self-Explanation

Without AI/code, answer:

1. padding vs alignment?
2. why tail padding exists?
3. why member reorder can change size?
4. why exact offsets are ABI-specific?
5. little vs big endian?
6. why raw struct serialization is risky?
7. what integer promotion risk exists in byte-swap code?

## 10. Artifact Definition of Done

Build PASS + host tests PASS + note complete + expected/actual recorded + no hidden failing test + provenance honest.

## 11. Competency Status

This is learning/practice artifact evidence. It does **not** grant W01-C-FOUND competency PASS. Fresh Week 1 AI-0 gate remains required.

## 12. AI Usage Rules

Allowed now: AI-1/AI-2.
AI-3 only after you provide a meaningful attempt plus observed failure/uncertainty.
AI-4/AI-5 on core TODO => affected practice becomes unsuitable as independent competency evidence and must be retested fresh.

## 13. Submission Format

Fill `SUBMIT_W01_D03_2026-08-12.md` at END DAY; control-file bookkeeping is handled during the atomic close transaction, not during focus work.

## 14. Forbidden Shortcuts

- Do not hard-code host-specific offsets to satisfy tests.
- Do not use compiler byte-swap built-ins for the core attempt.
- Do not use `#pragma pack`/packed attribute today.
- Do not rewrite tests merely to make incorrect code pass.
- Do not claim competency PASS from this artifact.

## 15. Stop Condition

Stop when final strict build + tests PASS, `alignment-note.md` contains prediction/observation/explanation, and you can explain 4 core ideas closed-book.

## 16. Next Physical Action

Run `BOOT` to start W01D04 — safe bit-manipulation APIs.
