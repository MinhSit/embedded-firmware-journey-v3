# W01D02 — Storage / Linkage / Memory Map

## 1. Prediction Before Build

| Object | Scope | Linkage | Storage duration | Expected location |
|---|---|---|---|---|
| `shared_value` | file scope | external | static | `.data` |
| `file_value` | file scope | internal | static | `.data` |
| `zero_value` | file scope | external | static | `.bss` |
| `label` | file scope | internal | static | `.rdata` / `.rodata` |
| `id` | block scope | none | static | `.bss` |
| `automatic_value` | block scope | none | automatic | stack / register / possibly optimized away |

## 2. Build

Command:

`gcc -std=c17 -O0 -g -Wall -Wextra -Wpedantic -Werror learning/week-01/day-02/storage_demo.c learning/week-01/day-02/storage_peer.c "-Wl,-Map=evidence/week-01/day-02/storage_demo.map" -o tests/host/storage_demo.exe`

Result:

PASS — GCC/linker completed with no warning or error.

Runtime command:

`.\tests\host\storage_demo.exe`

Runtime output:

`11 20 0 6 W01D02`

## 3. Map and Symbol Observation

The linker map contains the expected `.data`, `.rdata`, and `.bss` sections.

Direct linker-map observations:

- `shared_value` appears in `.data`.
- `zero_value` appears in `.bss`.
- The program object contributes data to `.data`, `.rdata`, and `.bss`.

GNU `nm` provides clearer symbol-level evidence:

| Symbol | `nm` type | Observed location / meaning |
|---|---|---|
| `shared_value` | `D` | initialized global data (`.data`) |
| `file_value` | `d` | initialized local data (`.data`) |
| `zero_value` | `B` | global BSS data (`.bss`) |
| `label` | `r` | local read-only data (`.rdata` on this toolchain) |
| `id.0` | `b` | local BSS data (`.bss`) |
| `next_id` | `t` | local code (`.text`) |

`automatic_value` does not appear as a normal linker symbol, which is consistent
with it being an automatic local object rather than a static-storage object.

## 4. Prediction vs Reality

All section-location predictions for the static-storage objects matched the
observed executable:

- `shared_value` -> `.data`
- `file_value` -> `.data`
- `zero_value` -> `.bss`
- `label` -> read-only data (`.rdata` on this Windows/MinGW build)
- `id` -> `.bss`

The experiment also showed that linkage and location are separate concepts:
`shared_value` and `file_value` are both stored in initialized data, but
`shared_value` is externally visible while `file_value` is local/internal.

## 5. Linkage Fault Injection

Change:

`int shared_value = 10;`

to:

`static int shared_value = 10;`

while keeping:

`extern int shared_value;`

in `storage_peer.c`.

Prediction:

- Compilation should succeed.
- Final linking should fail.
- Reason: file-scope `static` gives `shared_value` internal linkage, so it cannot
  satisfy the external reference from another translation unit.

Observed result:

`undefined reference to 'shared_value'`

Conclusion:

The prediction matched reality. `extern` does not make an internally linked
definition visible across translation units.

## 6. Volatile Summary

`volatile` tells the compiler that accesses to the object must be treated as observable and must not be optimized away as if the value could not change unexpectedly.

However, `volatile` does not make operations atomic and does not provide synchronization. An operation such as `counter++` is still conceptually a read-modify-write sequence, so multiple execution contexts can interleave and cause lost updates.

Mental model:

`volatile` controls compiler treatment of accesses; it does not protect shared data from race conditions.

## 7. Closed-book Check

### Q1 — Scope vs Storage Duration

Question:

What is the difference between scope and storage duration? Use a block-scope
`static int` as an example.

Answer from memory:

Scope describes where an identifier can be used in source code, while storage
duration describes how long the object exists.

A `static int` declared inside a function has block scope, but static storage
duration. Other functions cannot directly use that identifier, while the object
itself still exists for the entire program execution.

Result:

PASS after correction.

Initial weakness:

I initially mixed scope with linkage by associating scope with whether an object
could be referenced using `extern`.

---

### Q2 — File-scope `static`

Question:

Compare these two file-scope declarations:

`int value = 10;`

`static int value2 = 10;`

Answer from memory:

Both have file scope and static storage duration.

`value` has external linkage.

`value2` has internal linkage because of file-scope `static`.

Both are expected in `.data` because they are writable static-storage objects
with non-zero initial values.

Result:

PASS.

---

### Q3 — Predicting Memory Sections

Question:

Predict the typical location of:

`int a;`

`static int b;`

`const char c[] = "ABC";`

when all are declared at file scope.

Answer from memory:

- `a` -> `.bss` because it has static storage duration and is zero-initialized.
- `b` -> `.bss` for the same storage reason; `static` additionally gives it
  internal linkage.
- `c` -> typically `.rdata` / `.rodata` because it is read-only static-storage
  data.

Result:

PASS.

---

### Q4 — `volatile` and Atomicity

Question:

What does `volatile` do, and why does it not make `counter++` atomic?

Answer after correction:

`volatile` requires the compiler to respect accesses to the volatile object
instead of treating the value as if it could not change unexpectedly.

However, `counter++` is still conceptually a read-modify-write sequence.
Multiple execution contexts can interleave those operations and lose updates.

Therefore:

`volatile` does not provide atomicity, locking, synchronization, or thread safety.

Result:

PASS after correction.

Initial weakness:

I initially understood `volatile` only as a warning or notification to the
compiler. I need to remember that it affects compiler treatment of accesses,
not concurrency protection.

## 8. Still Unclear

- I need more repetition to keep `scope` and `linkage` completely separate.
- I need more practice with the exact meaning of `volatile`; the core rule to
  remember is: `volatile` controls compiler treatment of accesses, not
  synchronization between execution contexts.
- Memory-section prediction is clearer now, but I should continue treating
  `.data`, `.bss`, `.rdata/.rodata`, stack, and registers as implementation /
  toolchain behavior rather than rules directly mandated by the C standard.

## 9. Next Action

After END DAY closure, run `BOOT` to start W01D03 — Struct, alignment, and
endian.

## 10. Evidence Metadata and Provenance

- Date: `2026-08-11` (`Asia/Ho_Chi_Minh`).
- Artifact closure commit:
  `68c43bd89dec8264f9b34b9877f97f6b3b83fe3e`
  (`feat(w01d02): close storage linkage memory map`).
- Toolchain: Windows host, GCC/MinGW `14.2.0`, GNU `ld` map output, GNU `nm`.
- Hardware: none; this was a host-side C experiment.
- Expected behavior: clean strict-warning build, runtime output
  `11 20 0 6 W01D02`, predicted static-storage sections, and link failure after
  the internal-linkage fault injection.
- Actual result: all expectations matched; source was restored and the final
  baseline build/runtime passed.
- Highest AI level: `AI-5` for the complete experiment scaffold and substantial
  evidence prose. This artifact is learning/practice and reproducibility
  evidence, not independent competency evidence.
- Known limitations: section names and placement are specific to this
  Windows/MinGW build; `storage_demo.map` is reproducible generated output and
  remains ignored by repository policy (`*.map`).
- Competency claim: none. `W01-C-FOUND` remains `COMPETENCY_UNVERIFIED` and
  requires a fresh AI-0 gate.
