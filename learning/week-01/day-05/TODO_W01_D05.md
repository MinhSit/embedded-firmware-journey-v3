# TODO — Week 01 / Day 05 — Fixed-Size Ring Buffer

## Metadata

- Date: 2026-08-14
- Timezone: Asia/Ho_Chi_Minh
- Execution: `W01D05`
- Week: `Week 01`
- Topic: fixed-size `uint8_t` FIFO ring buffer
- Evidence class: learning/practice artifact; not competency evidence
- Competency: `W01-C-FOUND — COMPETENCY_UNVERIFIED`
- Expected AI mode: AI-1/AI-2; AI-3 only after a meaningful learner attempt

## Outcome

- Learner designs and implements the agreed fixed-size FIFO ring buffer API.
- Strict-warning host build passes under C17.
- Repeatable host tests pass for normal, full, empty, wrap, and invalid-input
  behavior.
- Learner explains the core invariants closed-book.

## Public Contract

- Capacity is the named compile-time constant `RB_CAPACITY`.
- Storage is fixed-size; no dynamic allocation is allowed.
- `rb_push` rejects a full buffer. It must not silently overwrite old data.
- `rb_pop` rejects an empty buffer and preserves the caller's output value.
- Rejected operations must not corrupt buffered data or observable state.
- NULL query behavior:
  - `rb_is_empty(NULL) -> false`
  - `rb_is_full(NULL) -> false`
  - `rb_size(NULL) -> 0`
  - `rb_capacity(NULL) -> 0`

## Core Invariants to Verify

- `0 <= count <= capacity`
- `head` and `tail` stay within the valid index range.
- `count == 0` represents empty.
- `count == capacity` represents full.
- Successful pops preserve FIFO ordering.
- Rejected operations do not corrupt state.
- A failed empty pop preserves the caller's output value.

Explain why each invariant remains true after successful and rejected
operations. Do not write a complete state-transition algorithm into comments or
notes.

## Learner TODO Order

1. Read `ring_buffer.h` and `tests/host/test_ring_buffer.c`.
2. Predict the baseline failures before running the executable.
3. Run the baseline strict build and tests without changing the harness.
4. Implement init/query behavior.
5. Implement push independently.
6. Implement pop independently.
7. Run the strict build and tests after meaningful changes.
8. Debug using the exact failing test IDs.
9. Explain the invariants closed-book.
10. Record expected versus actual results and open defects for END DAY.

## Build and Run

Strict build:

```powershell
gcc -std=c17 -Wall -Wextra -Wpedantic -Werror `
  learning/week-01/day-05/ring_buffer.c `
  tests/host/test_ring_buffer.c `
  -Ilearning/week-01/day-05 `
  -o tests/host/test_ring_buffer.exe
```

Run:

```powershell
.\tests\host\test_ring_buffer.exe
```

The untouched starter is expected to compile and then fail behavioral tests
because `ring_buffer.c` still contains learner TODO stubs.

## Test Categories

- NORMAL: initialization, one element, multiple elements, FIFO order.
- EMPTY: rejection, output preservation, state preservation.
- FULL: exact fill, rejection without overwrite, FIFO data preservation.
- WRAP: write wrap, read wrap, FIFO order, repeated cycles.
- INVALID INPUT: NULL for init, push, pop, output, and query APIs.

Tests exercise only public API behavior. They must not depend on private state
transitions or be weakened to make incomplete code pass.

## AI Rules

- AI-1 theory is allowed.
- AI-2 graded hints are allowed.
- AI-3 review/debug is allowed only after a meaningful attempt plus concrete
  failing evidence.
- No AI-4/AI-5 exposure of the core implementation.
- This practice artifact cannot by itself mark `W01-C-FOUND` competency PASS.

## Forbidden Shortcuts

- No complete/reference ring-buffer implementation.
- No weakening, skipping, or removing tests to make stubs pass.
- No dynamic allocation.
- No silent overwrite-on-full policy unless the roadmap/user explicitly changes
  the API.
- No hidden solution in macros, helpers, inactive code, generated files,
  documentation, or repository history.
- No competency PASS claim from this artifact.
- No control-state or END DAY bookkeeping during focus work.

## Learner Completion Condition

The learning task is complete only when the strict build passes, all required
tests pass repeatably, expected versus actual results and open defects are
recorded, and the learner can explain the invariants closed-book. END DAY remains
a separate explicit workflow.
