# TODO — Week 02 / Day 06

## Metadata

- Task: `W02D06 — debounce using tick/state machine + schematic review`
- Target: `NUCLEO-F446RE`
- Day type: normal `LEARNING`; not a competency gate
- Available Focused Time: transient Project Chat input; do not persist here
- Starter evidence state: `NOT PERFORMED`
- Prior prerequisite: W02D05 EXTI/NVIC `GREEN / CLOSED / ARTIFACT_PASS`
- Known prior limitation: button bounce was `NOT CHARACTERIZED`

## Measurable outcome

Implement and explain a non-blocking, tick-driven debounce state machine that
emits one semantic activation/deactivation event for a stable input change,
passes the visible host contract, is integrated into the NUCLEO-F446RE lab, and
produces both an annotated schematic worksheet and a truthful debounce log.

This is normal-learning artifact work. It does not create a new competency PASS.

## AI and learner-ownership boundary

- Executor-owned: build/vendor infrastructure, public API/context scaffold,
  compile-clean TODO stub, visible tests, and blank evidence worksheets.
- Learner-owned: the debounce transitions, candidate/stable reasoning,
  threshold and wrap handling, STM32 tick integration, hardware observations,
  schematic conclusions, annotations, and final explanation.
- Do not request or paste the finished debounce algorithm before a genuine
  implementation attempt.
- Record the highest AI assistance level truthfully at submission time.
- The normal fresh Week-2 AI-0 competency gate remains required later.

## Starter state

- `main.c` is the validated W02D05 raw-EXTI prerequisite. It still toggles LD2
  directly on a raw EXTI13 edge and is intentionally not debounced.
- `debounce.h` defines the visible contract and context.
- `debounce.c` compiles but always returns `DEBOUNCE_EVENT_NONE`.
- Host tests compile; transition cases intentionally fail until the learner
  implements the core.
- No hardware behavior, timing, bounce count, schematic subrevision, or PASS is
  claimed by this starter.

## Debounce contract

- `threshold_ticks` must be greater than zero.
- The initial raw level becomes the initial stable level without emitting an
  event.
- A raw level must remain consistent for the full threshold before it becomes
  the new stable level.
- The exact threshold boundary is accepted.
- One stable transition emits exactly one semantic event; repeated identical
  samples emit no duplicate event.
- `active_level` maps the stable electrical level to activation/deactivation.
- `uint32_t` tick wrap-around is part of the visible contract.
- The API is non-blocking: no delay loop, sleep, polling wait, allocation, or
  logging inside `debounce_sample()`.

## Learner TODO sequence

1. Read `debounce.h` and `tests/host/test_debounce.c`; predict which untouched
   starter cases pass and fail.
2. Draw your own state/transition model without copying a finished algorithm.
3. Implement only the core in `debounce.c`; keep the public contract stable
   unless a real defect is demonstrated.
4. Run the strict host compile and visible tests after each meaningful change.
5. Explain how your elapsed-time comparison remains valid across `uint32_t`
   wrap-around.
6. Decide and justify how raw PC13 samples and a monotonic tick reach the module;
   then integrate without blocking inside the ISR.
7. Demonstrate press and release stabilization on hardware and record a
   debounce log using observations you actually made.
8. Complete `SCHEMATIC_REVIEW_W02D06.md` from the exact official schematic that
   matches the physical board; annotate rather than infer.
9. Complete `SUBMIT_W02_D06.md` only with verified commands, results, sources,
   measurements, evidence paths, and limitations.

## Visible test matrix

| Case | Required behavior |
|---|---|
| Initial inactive/active state | Preserve initial stable level; emit no event |
| Raw transition before threshold | Stable state unchanged; no event |
| Exact threshold boundary | Accept new stable state and emit one event |
| Bounce/noise sequence | Reject interrupted candidate interval |
| Press stabilization | Emit one activation after the full interval |
| Release stabilization | Emit one deactivation after the full interval |
| Repeated stable samples | Do not duplicate a semantic event |
| `uint32_t` tick wrap | Preserve elapsed-time behavior across wrap |
| Active-low mapping | Map stable LOW to activation when configured |

These visible cases are normal-learning feedback, not a hidden assessment or
competency gate. There are no hidden scoring criteria in this starter.

## Commands

From the repository root, compile the host harness strictly:

```powershell

```

Run it:

```powershell
.\tests\host\test_debounce.exe
```

Build the STM32 starter from its lab directory:

```powershell
powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean
```

## Evidence requirements

- Exact host compile command, exit result, and full test summary.
- Exact STM32 clean-build command and result.
- Exact flash/debug method if performed; otherwise state `NOT PERFORMED`.
- Debounce log containing tick/sample/event observations actually captured.
- Press, release, bounce/noise, and repeated-sample observations without
  inventing timing or transition counts.
- Exact official document identifier/revision and sheet/page/reference for each
  schematic conclusion.
- Learner-created annotated schematic or annotation image path.
- Explanation in the learner's own words of the chosen states, threshold
  boundary, event uniqueness, ISR boundary, and tick wrap behavior.

## Stop condition

Stop and report instead of guessing if the physical board cannot be matched to
an official schematic revision, official sources conflict, tick units are
unknown, hardware observations cannot be separated from assumptions, build
infrastructure changes unexpectedly, or any command could overwrite learner
work. Do not mark W02D06 complete or claim `ARTIFACT_PASS` from starter builds.
