# W02 Startup Simulator — Learner TODO

## Step 1 — Run the baseline

From this directory:

```powershell
.\run_tests.ps1
```

Expected: memory-layout, CPU-reset, and fault-infrastructure tests pass. The
learner startup test executable fails because the startup algorithm is still a
stub. A nonzero command result is expected at this stage.

## Step 2 — Implement `Reset_Handler` sequencing

Open `src/startup.c`, function `Reset_Handler`. Work only at the marked
`TODO(LEARNER)` locations.

## Step 3 — Implement `.data` copy manually

Use the boundaries declared in `include/sim_memory.h`. Copy the complete range
and record the required structured trace event for each affected word.

Constraint: no `memcpy`.

## Step 4 — Implement `.bss` clear manually

Use the boundaries declared in `include/sim_memory.h`. Clear the complete range
and record the required structured trace event for each affected word.

Constraint: no `memset`.

## Step 5 — Make runtime/application ordering correct

Complete the remaining `TODO(LEARNER)` in `Reset_Handler`. The tests evaluate
observable order, not source-line shape.

## Step 6 — Run the full deterministic tests

```powershell
.\run_tests.ps1
```

Do not stop at “the build passed.” All four test executables must pass.

## Step 7 — Run the demo and inspect the trace

```powershell
.\build\startup_demo.exe
```

Compare the pre-reset and post-reset memory plus the ordered trace.

## Step 8 — Enable fault injections one at a time

```powershell
.\build\startup_demo.exe data-short
.\build\startup_demo.exe skip-bss
.\build\startup_demo.exe bad-stack
.\build\startup_demo.exe main-before-runtime
.\build\startup_demo.exe wrong-reset-handler
```

Explain what each measurement proves. Reaching `app_main` alone is not proof
that startup state is correct.

## Step 9 — Explain simulator to STM32 mapping

Fill only the learner-answer cells at the end of `README.md`. Use your own
words; do not turn the simulator into independent competency evidence.
