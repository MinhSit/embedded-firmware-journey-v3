# TODO — Week 01 / Day 04 — Safe Bit Operations

## Metadata

- Date: 2026-08-13
- Timezone: Asia/Ho_Chi_Minh
- System Spec: `SYSTEM_SPEC_V3 3.0.0`
- Roadmap: `EMBEDDED_ROADMAP_V3.1 3.1.0`
- Execution: `W01D04`
- Previous artifact: `W01D03 — ARTIFACT_PASS`
- Competency: `W01-C-FOUND — COMPETENCY_UNVERIFIED`
- Recovery: `NOT ACTIVE`
- Toolchain: Host GCC 14.2.0 / C17
- Evidence class: learning/practice artifact; not a competency gate

## Outcome

Implement and explain a defensive `uint32_t` API for bit set, clear, extract,
and update. The implementation must avoid undefined behavior (UB), reject bad
runtime inputs, preserve destinations on failure, and pass repeatable host unit
tests under strict compiler warnings.

## Acceptance Criteria

### MUST

- Implement all four public functions in `bit_ops.c`; do not change their API.
- Validate every contract-defined runtime input before modifying an output or
  destination.
- Avoid invalid shifts, including shift counts equal to or greater than 32.
- Return `false` for rejected operations and leave the destination unchanged.
- On success, return `true` and satisfy the API contract exactly.
- Preserve all non-target bits in `bit_update_u32`.
- Use unsigned fixed-width operations; do not depend on signed-shift behavior.
- Keep runtime validation active in release builds. `assert` is not a substitute
  for handling caller-controlled invalid input.
- Make and explain an explicit assertion decision: use assertions only for a
  genuine internal invariant, or explain why this small public API has no useful
  internal assertion.
- Build cleanly with `-std=c17 -Wall -Wextra -Wpedantic -Werror`.
- Pass all visible host tests and keep the test harness unchanged.
- Record expected versus actual results and complete the closed-book
  self-explanation before END DAY.

### SHOULD

- Keep validation and bit logic easy to audit; avoid clever macros.
- Use named local variables where they make the invariants clearer.

### BONUS

- Add one focused, non-duplicate edge test and explain which defect it can catch.
- BONUS is optional and must not delay END DAY readiness.

## API Contract

### `bit_set_u32`

- Valid `bit`: 0..31.
- `value == NULL` or invalid `bit`: return `false`.
- Failure leaves the original word unchanged.
- Success sets the selected bit; setting an already-set bit still succeeds.

### `bit_clear_u32`

- Same input and failure policy as `bit_set_u32`.
- Success clears the selected bit; clearing an already-clear bit still succeeds.

### `bit_extract_u32`

- Valid `width`: 1..32.
- The complete range must lie inside a `uint32_t`.
- `width == 32` is valid only with `lsb == 0`.
- `out == NULL` or an invalid range: return `false`.
- Failure leaves `*out` unchanged.
- Success stores the selected field normalized to bit 0.

### `bit_update_u32`

- Uses the same range rules as `bit_extract_u32`.
- `field_value` must fit in `width` bits; width 32 accepts any `uint32_t`.
- `value == NULL`, invalid range, or oversized field: return `false`.
- Failure leaves `*value` unchanged.
- Success replaces only the target field; all other bits remain unchanged.

## Learner TODO

1. Read `bit_ops.h` and predict which tests should currently pass or fail.
2. Run the strict starter build and baseline tests before editing `bit_ops.c`.
3. Implement `bit_set_u32` and `bit_clear_u32`; rerun the suite.
4. Implement `bit_extract_u32`, including the full-width boundary.
5. Implement `bit_update_u32`, including field-fit and field-isolation rules.
6. Rerun the strict build after every meaningful change.
7. Answer the self-explanation questions without looking at code or AI output.
8. Record expected/actual results, open defects, and one next physical action.

Do not ask for or paste a complete implementation before making a meaningful
attempt and collecting the exact failing test IDs.

## Test Matrix

| IDs | Area | Coverage |
|---|---|---|
| D04-T01..T05 | set | bit 0, bit 31, idempotence, invalid index, NULL |
| D04-T06..T10 | clear | bit 0, bit 31, idempotence, invalid index, NULL |
| D04-T11..T21 | extract | single/middle/top fields, width 32, invalid widths/ranges, NULL, unchanged-on-failure |
| D04-T22..T34 | update | field positions, width 32, field fit, invalid ranges, NULL, unchanged-on-failure, field isolation |

Categories covered: NORMAL, BOUNDARY, INVALID INPUT,
UNCHANGED-ON-FAILURE, and FIELD ISOLATION.

## Invalid / Boundary Cases

- Bit indexes 0, 31, and 32.
- Widths 0, 1, 32, and 33.
- `lsb == 32`.
- A field ending exactly at bit 31.
- A field crossing bit 31.
- NULL destination/output pointers.
- Already-set and already-clear bits.
- Largest fitting field value and a value one step too large.
- Full-width extract/update, where an implementation must not evaluate a
  shift-by-32 expression.
- Sentinel destinations that must remain unchanged after rejection.

## Evidence Required

During focus work, do not edit roadmap control or bookkeeping files. Keep these
results available for the later END DAY transaction:

- final `bit_ops.c` and `bit_ops.h`;
- final `tests/host/test_bit_ops.c`;
- exact strict build command and exit result;
- exact test summary and exit result;
- expected versus actual baseline/final results;
- unresolved defect IDs, if any;
- answers to the self-explanation questions;
- honest AI assistance level and affected functions.

Strict build:

```powershell
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror `
  learning/week-01/day-04/bit_ops.c `
  tests/host/test_bit_ops.c `
  -Ilearning/week-01/day-04 `
  -o tests/host/test_bit_ops.exe
```

Run:

```powershell
.\tests\host\test_bit_ops.exe
```

## Self-Explanation Questions

Answer without looking at code or asking AI:

1. Why is shift-by-width dangerous in C?
2. Why must range validation happen before constructing or applying a mask?
3. Why should a rejected operation leave its destination unchanged?
4. What is the difference between an assertion and runtime input validation?
5. Why are unsigned fixed-width integers appropriate for this API?
6. How do you prove bits outside an updated field remain unchanged?
7. Why does `width == 32` need deliberate handling?

Do not write answers into the starter source comments.

## AI Rules

- The learner owns the core implementation of all four functions.
- Allowed starter assistance: API/header, compile-clean stubs, TODO, tests,
  fixtures, acceptance criteria, and build commands.
- AI-1 theory and AI-2 graded hints are allowed.
- AI-3 review/debug is allowed only after a meaningful learner attempt with
  concrete code and failing test evidence.
- AI-4/AI-5 implementation exposure makes the affected work assisted practice;
  it cannot become independent competency evidence.
- This day is learning/practice. A later fresh Week 1 AI-0 gate is still
  required for `W01-C-FOUND`.

## Forbidden Shortcuts

- Do not paste a complete/reference solution for the core functions.
- Do not weaken, skip, or rewrite tests to make stubs or incorrect code pass.
- Do not use signed integers for mask/shift logic.
- Do not rely on implementation behavior after an invalid shift.
- Do not use assertions to terminate on contract-defined invalid caller input.
- Do not write outputs before all failure checks needed to preserve them.
- Do not hide a reference implementation in the learner-visible repository.
- Do not claim competency PASS from this practice artifact.

## Stop Condition

Stop normal required work when:

- `bit_ops.c/.h` and repeatable unit tests exist;
- strict build and all required host tests pass;
- expected versus actual results and any open defects are recorded;
- the learner can explain the core invariants closed-book; and
- one concrete next action for the following session is written.

BONUS work does not create a new END DAY condition.
