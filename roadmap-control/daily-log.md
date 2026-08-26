# DAILY LOG — V3

Do not change this schema casually.

---

## YYYY-MM-DD — Week XX / Day YY

### 1. Planned Outcome

### 2. Actual Status
GREEN / YELLOW / RED

### 3. Focused Time
Planned:
Actual:

### 4. Independent Work
What I personally implemented, reasoned about, measured, or explained:

### 5. AI Usage
Highest AI level used:
What AI helped with:
Files/functions materially assisted:
Competencies contaminated:
Independent retest required:

### 6. Artifact Result
Files changed:
Build command:
Build result:
Test command:
Test result:

### 7. Evidence
Commit:
Logs:
Captures:
Reports:
Video/demo:
Other:

### 8. Measurements
Expected:
Observed:
Relevant values/registers/timing/errors:

### 9. Understanding Check
What I can explain without AI:
What I still cannot explain:

### 10. Defects / Failed Tests
Defect/Test IDs:
Root cause known?:
Current hypothesis:

### 11. Carry-over
Task:
Closure criteria:

### 12. Next Action
One physical action taking approximately 5–15 minutes.

---

## 2026-08-10 — Week 01 / Day 01

### 1. Planned Outcome

Hoàn thành W01D01 Embedded C: pointer, array, pointer arithmetic, const placement và host-side exercises; có build/test evidence và tự giải thích lại các khái niệm chính.

### 2. Actual Status

GREEN

### 3. Focused Time

Planned: ~5–6 hours
Actual: 5h26m

### 4. Independent Work

What I personally implemented, reasoned about, measured, or explained:

- Tự implement E01–E05 và E07. Với E06, learner đã có meaningful attempt trước review; AI sau đó exposed exact implementation line `*slot = target;`, nên E06 không được dùng làm independent competency evidence.
- Function coverage E01–E07:
  - `swap_int`
  - `sum_ints`
  - `max_int`
  - `reverse_ints`
  - `find_first`
  - `retarget_pointer`
  - `transform_ints`
- Tự chạy compile/test và sửa implementation theo test result.
- Reasoning về:
  - array vs pointer
  - array-to-pointer conversion
  - `arr[i] == *(arr + i)`
  - pointer arithmetic theo pointed type
  - pointer-to-pointer và dereference nhiều tầng
  - `const int *` vs `int *const`
  - one-past-end pointer
- Hoàn thành E08 const-placement reasoning.
- Hoàn thành E09 one-past-end / defined-vs-undefined reasoning.
- Tự giải thích lại các core concepts cuối buổi.

### 5. AI Usage

Highest AI level used: AI-4

What AI helped with:
- Giảng lý thuyết ngắn về pointer, array, const, pointer arithmetic và pointer-to-pointer.
- Làm rõ misunderstanding sau khi learner trả lời.
- Đưa hint theo từng mức.
- Review/debug sau khi learner đã có meaningful attempt.
- Trong E06 `retarget_pointer`, AI đã làm lộ exact implementation line `*slot = target;` sau meaningful learner attempt; provenance bảo thủ vì vậy được phân loại AI-4.
- Hướng dẫn cách lưu execution evidence và Git workflow.

Files/functions materially assisted:
- `learning/week-01/day-01/TODO_W01_D01.md`
- Review các function E01–E07 sau learner attempt.
- E06 `retarget_pointer`: bounded implementation exposure.
- `evidence/week-01/day-01/test_c_exercises_01.log` về cấu trúc evidence/logging.

Competencies contaminated:
- W01D01 không được dùng làm independent competency evidence do có AI-4 exposure ở E06.
- Artifact/practice result không được dùng làm W01-C-FOUND competency PASS.

Independent retest required:
- YES — fresh AI-0 Week 1 competency gate.

### 6. Artifact Result

Files changed:
- `learning/week-01/day-01/TODO_W01_D01.md`
- `learning/week-01/day-01/c_exercises_01.c`
- `learning/week-01/day-01/c_exercises_01.h`
- `tests/host/test_c_exercises_01.c`
- `evidence/week-01/day-01/test_c_exercises_01.log`

Build command:
`gcc -std=c17 -Wall -Wextra -Wpedantic -Werror learning/week-01/day-01/c_exercises_01.c tests/host/test_c_exercises_01.c -o tests/host/test_c_exercises_01.exe`

Build result:
PASS — exit code 0, no warning/error under configured warning flags.

Test command:
`.\tests\host\test_c_exercises_01.exe`

Test result:
PASS — 46 tests run, 0 failed.

### 7. Evidence

Commit:
`aff3d4d feat(w01d01): complete pointer array const exercises`

Logs:
- `evidence/week-01/day-01/test_c_exercises_01.log`

Captures:
- None

Reports:
- None

Video/demo:
- None

Other:
- `learning/week-01/day-01/TODO_W01_D01.md` contains exercise specification and completion record.
- Provenance corrected after audit: highest AI level = AI-4 due bounded E06 implementation exposure.

### 8. Measurements

Expected:
- Build succeeds with C17 and strict warning flags.
- 46 host tests execute.
- 0 test failures.
- Pointer/array/const reasoning completed.

Observed:
- Build exit code: 0
- Tests run: 46
- Tests failed: 0
- Result: PASS
- Test exit code: 0

Relevant values/registers/timing/errors:
- Initial stub baseline had failing tests as expected.
- Final host test result: 46/46 PASS.
- Focused time: 5h26m.
- No hardware/register/timing measurement required for this host-side C exercise.

### 9. Understanding Check

What I can explain without AI:
- Array là object chứa các phần tử liên tiếp; pointer là object chứa địa chỉ.
- Array không phải pointer; trong nhiều expression array undergoes array-to-pointer conversion tới phần tử đầu tiên.
- `arr[i]` tương đương `*(arr + i)`.
- Pointer arithmetic tự scale theo pointed type.
- `const int *p`: pointer có thể retarget, không sửa pointee qua `p`.
- `int *const p`: pointer không thể retarget, có thể sửa pointee qua `p`.
- Với `int **slot`, `slot` là pointer-to-pointer, `*slot` là `int *`, `**slot` là `int`.
- `a + len` có thể tồn tại như one-past pointer nhưng không được dereference.

What I still cannot explain:
- Không có blocker rõ ràng ở phạm vi W01D01.
- Các concept vẫn cần được xác minh lại bằng fresh AI-0 independent gate.

### 10. Defects / Failed Tests

Defect/Test IDs:
- Không còn failed test ở final run.

Root cause known?:
YES — các lỗi/misunderstanding trong quá trình học đã được xác định và sửa.

Current hypothesis:
- Không có unresolved defect trong W01D01 artifact.
- Independent competency vẫn chưa được xác nhận cho tới AI-0 gate.

### 11. Carry-over

Task:
- Tiếp tục Week 01 / Day 02 theo roadmap.
- W01-C-FOUND vẫn ở trạng thái chưa verified cho tới independent AI-0 gate.

Closure criteria:
- W01D01 artifact/evidence committed.
- Daily log updated.
- Provenance correction recorded.
- Repository synchronized.
- Sau đó bắt đầu W01D02, không cần recovery W01D01.

### 12. Next Action

BOOT

---

## 2026-08-11 — Week 01 / Day 02

### 1. Planned Outcome

Giải thích được `static` / `extern` / `volatile`, phân biệt scope / linkage /
storage duration, đọc map/symbol output của một chương trình C nhỏ, và ghi lại
prediction → observation → explanation trong `memory-map-note.md`.

### 2. Actual Status

GREEN

### 3. Focused Time

Planned: 7h
Actual: ~7h — learner estimate

### 4. Independent Work

What I personally implemented, reasoned about, measured, or explained:

- Tự dự đoán scope, linkage, storage duration và location cho sáu object trước
  khi build; các lỗi ban đầu về scope/linkage và automatic location đã được sửa.
- Tự chạy strict-warning build, executable, linker-map inspection và `nm`.
- Tự dự đoán fault injection: đổi `shared_value` sang file-scope `static` làm
  compilation đi qua nhưng final link thất bại vì external reference không được
  thỏa mãn; measurement xác nhận `undefined reference to 'shared_value'`.
- Restore baseline source và xác nhận lại build/runtime `11 20 0 6 W01D02`.
- Hoàn thành closed-book recall về scope/storage duration, file-scope `static`,
  memory-section prediction và `volatile`/atomicity; Q1 và Q4 PASS sau correction.

### 5. AI Usage

Highest AI level used: AI-5

What AI helped with:
- Giảng lý thuyết và sửa misunderstanding về scope, linkage, storage duration,
  memory placement, `extern`, build vs link, và `volatile`.
- Cung cấp complete source scaffold cho host experiment.
- Cung cấp command guidance, review/interpretation sau learner measurements,
  fault-injection workflow và closed-book correction.
- Cung cấp substantial ready-to-paste prose/template cho
  `memory-map-note.md`, rồi hỗ trợ END DAY bookkeeping.

Files/functions materially assisted:
- `learning/week-01/day-02/storage_demo.h`
- `learning/week-01/day-02/storage_demo.c`
- `learning/week-01/day-02/storage_peer.c`
- `learning/week-01/day-02/memory-map-note.md`
- W01D02 evidence/provenance and control-file bookkeeping.

Competencies contaminated:
- W01D02 không được dùng làm independent competency evidence vì full experiment
  scaffold và substantial evidence prose đã được AI cung cấp.
- Không có competency PASS nào được tạo; `W01-C-FOUND` vẫn
  `COMPETENCY_UNVERIFIED`.

Independent retest required:
- YES — fresh AI-0 Week 1 competency gate trước mọi claim
  `W01-C-FOUND — COMPETENCY_PASS`.

### 6. Artifact Result

Files changed:
- `learning/week-01/day-02/storage_demo.h`
- `learning/week-01/day-02/storage_demo.c`
- `learning/week-01/day-02/storage_peer.c`
- `learning/week-01/day-02/memory-map-note.md`

Build command:
`gcc -std=c17 -O0 -g -Wall -Wextra -Wpedantic -Werror learning/week-01/day-02/storage_demo.c learning/week-01/day-02/storage_peer.c "-Wl,-Map=evidence/week-01/day-02/storage_demo.map" -o tests/host/storage_demo.exe`

Build result:
PASS — exit code 0, no warning/error under configured flags.

Test command:
`.\tests\host\storage_demo.exe`

Test result:
PASS — exit code 0; output `11 20 0 6 W01D02`.

### 7. Evidence

Commit:
- Artifact closure commit:
  `68c43bd89dec8264f9b34b9877f97f6b3b83fe3e`
  (`feat(w01d02): close storage linkage memory map`).
- Corrective bookkeeping commit:
  `c86993217c40bb7c95ad3dd99af3fe78638bba32`
  (`docs(control): correct W01D02 focused time`).

Logs:
- None committed; final commands/results are recorded in
  `learning/week-01/day-02/memory-map-note.md`.

Captures:
- None

Reports:
- `learning/week-01/day-02/memory-map-note.md`

Video/demo:
- None

Other:
- `evidence/week-01/day-02/storage_demo.map` was regenerated from the restored
  baseline and intentionally remains ignored by repository policy (`*.map`).
- GNU `nm` confirmed `D shared_value`, `d file_value`, `B zero_value`,
  `b id.0`, `r label`, and `t next_id`.

### 8. Measurements

Expected:
- Strict-warning baseline build succeeds.
- Runtime output is `11 20 0 6 W01D02`.
- Static-storage objects match predicted `.data`, `.bss`, and read-only data.
- File-scope `static shared_value` fault injection causes final link failure.

Observed:
- Baseline build exit code: 0.
- Runtime exit code: 0; output matched exactly.
- Map and `nm` observations matched the section/linkage predictions.
- Fault-injection link failed with `undefined reference to 'shared_value'`.
- Baseline was restored and reverified.

Relevant values/registers/timing/errors:
- No hardware/register/timing measurement was required for this host exercise.
- Focused time: planned 7h; actual ~7h by learner estimate.

### 9. Understanding Check

What I can explain without AI:
- Scope answers where an identifier is visible; storage duration answers how
  long the object exists; linkage answers whether declarations can denote the
  same entity across translation units.
- File-scope `static` gives internal linkage; block-scope `static` retains block
  scope but has static storage duration.
- Writable non-zero static-storage data is typically `.data`; zero-initialized
  static-storage data is typically `.bss`; read-only static data is commonly
  `.rdata/.rodata`, subject to toolchain behavior.
- `volatile` affects compiler treatment of accesses but does not provide
  atomicity, locking, synchronization, or thread safety.

What I still cannot explain:
- Scope and linkage still need repetition to remain completely separate under
  interview pressure.
- The exact `volatile` wording and implementation-specific section placement
  need further practice.
- These concepts have not passed a fresh AI-0 independent gate.

### 10. Defects / Failed Tests

Defect/Test IDs:
- None unresolved in the final W01D02 artifact.

Root cause known?:
YES — the injected link failure was intentional and its linkage root cause was
confirmed; the baseline was restored.

Current hypothesis:
- No unresolved artifact defect.
- Independent competency remains unverified until the fresh AI-0 gate.

### 11. Carry-over

Task:
- NONE from W01D02 artifact. W01D03 is the next scheduled execution, not
  recovery carry-over.

Closure criteria:
- W01D02 source/note and control bookkeeping committed atomically.
- Repository synchronized if push succeeds.
- Fresh Week 1 AI-0 gate remains mandatory before competency PASS.

### 12. Next Action

BOOT

---

## 2026-08-12 — Week 01 / Day 03

### 1. Planned Outcome

Đo và giải thích layout của hai `struct` bằng `sizeof`, `_Alignof` và
`offsetof`; quan sát union/endian; implement byte-swap và host-endian detection;
lưu strict host-test evidence và `alignment-note.md`.

### 2. Actual Status

GREEN — authoritative W01D03 artifact, evidence and end-of-day understanding
criteria were completed.

Correction note (2026-08-12): the previous `YELLOW` classification was based
solely on a generated pre-check `MUST`. Authority audit found that item was a
non-scoring baseline diagnostic, not an independent W01D03 roadmap completion
criterion. The interrupted chronology remains documented as
`MENTOR/SYSTEM WORKFLOW VARIANCE — NON-SCORING`. `ARTIFACT_PASS`, AI-4,
`W01-C-FOUND — COMPETENCY_UNVERIFIED`, schedule and recovery remain unchanged.

### 3. Focused Time

Planned: ~6–7 focused hours nếu là normal roadmap day, theo TODO.
Actual: ~6h — learner estimate

### 4. Independent Work

What I personally implemented, reasoned about, measured, or explained:

- Dự đoán size/alignment/member offsets của `layout_a_t` và `layout_b_t` trước
  measurement; các dự đoán số học khớp kết quả host.
- Hoàn thành layout inspection, byte-swap và endian-detection practice; bounded
  AI-4 code/syntax assistance đã được dùng sau learner attempts.
- Chạy strict build, 25 host tests và measurement helper.
- Quan sát `layout_a_t` có size 12, `layout_b_t` có size 8, union size/alignment
  là 4, và bytes của `0x01020304` là `04 03 02 01` trên host hiện tại.
- Initial mini closed-book practice đạt 6 PASS / 1 PARTIAL; câu trả lời raw-struct
  ban đầu nêu ABI/layout-padding risk nhưng bỏ sót endian risk.
- Fresh unhinted practice retest sau đó nêu đúng cả ABI/layout-padding và endian
  mismatch risk. Kết quả này không phải AI-0 competency gate.
- Original generated pre-check flow was not completed before coding after the
  learner disclosed missing prerequisite knowledge and the mentor switched to
  theory-first teaching. This is `MENTOR/SYSTEM WORKFLOW VARIANCE — NON-SCORING`
  and is not independent competency evidence.

### 5. AI Usage

Highest AI level used: AI-4

What AI helped with:
- AI-1 theory/clarification về struct padding/alignment, union/enum và endian.
- AI-2 hints và AI-3 review/debug sau meaningful attempts.
- Bounded AI-4 code/syntax assistance trong implementation sau learner attempts.
- AI-assisted wording cho Section 7 của `alignment-note.md`.
- END DAY audit, evidence metadata và routine bookkeeping.

Files/functions materially assisted:
- `learning/week-01/day-03/struct_layout.c`
- `learning/week-01/day-03/alignment-note.md`, đặc biệt wording Section 7
- W01D03 TODO/SUBMIT, evidence metadata và control-file bookkeeping

Competencies contaminated:
- W01D03 không được dùng làm independent competency evidence do AI-4 bounded
  code/syntax assistance và AI-assisted evidence wording.
- `W01-C-FOUND` vẫn `COMPETENCY_UNVERIFIED`.

Independent retest required:
- YES — fresh AI-0 Week 1 competency gate trước mọi claim
  `W01-C-FOUND — COMPETENCY_PASS`.

### 6. Artifact Result

Files changed:
- `learning/week-01/day-03/struct_layout.c`
- `learning/week-01/day-03/alignment-note.md`
- `learning/week-01/day-03/measure_w01d03.c`
- `learning/week-01/day-03/TODO_W01_D03_2026-08-12_struct_alignment_endian.md`
- `learning/week-01/day-03/SUBMIT_W01_D03_2026-08-12.md`
- `evidence/week-01/day-03/test_struct_layout.txt`

Build command:
`gcc -std=c17 -Wall -Wextra -Wpedantic -Werror learning/week-01/day-03/struct_layout.c tests/host/test_struct_layout.c -Ilearning/week-01/day-03 -o tests/host/test_struct_layout.exe`

Build result:
PASS — exit code 0, no warning/error under configured flags.

Test command:
`.\tests\host\test_struct_layout.exe`

Test result:
PASS — exit code 0; `SUMMARY: 25 tests, 0 failed`.

### 7. Evidence

Commit:
- Closure commit; see repository history.

Logs:
- `evidence/week-01/day-03/test_struct_layout.txt` — intentionally tracked UTF-8
  verification record with build/test/measurement metadata and provenance.

Captures:
- None

Reports:
- `learning/week-01/day-03/alignment-note.md`
- `learning/week-01/day-03/SUBMIT_W01_D03_2026-08-12.md`

Video/demo:
- None

Other:
- `learning/week-01/day-03/measure_w01d03.c` is retained as a clean,
  reproducible host measurement helper.

### 8. Measurements

Expected:
- Strict build succeeds and all 25 visible host tests pass.
- `layout_a_t` and `layout_b_t` results match `sizeof/_Alignof/offsetof`.
- Object bytes identify the host byte order without union-punning.

Observed:
- `layout_a_t`: size 12, alignment 4, offsets `tag=0`, `value=4`, `code=8`.
- `layout_b_t`: size 8, alignment 4, offsets `tag=6`, `value=0`, `code=4`.
- `u32_view_t`: size 4, alignment 4.
- `0x01020304` bytes at increasing addresses: `04 03 02 01`.
- Detected host endian: little-endian (`ENDIAN_LITTLE`, enum value 1).
- Host tests: 25 run, 0 failed.

Relevant values/registers/timing/errors:
- No hardware/register/timing measurement was required for this host exercise.
- Exact layout/alignment/endian observations are implementation/ABI specific.

### 9. Understanding Check

What I can explain without AI:
- Alignment constrains where an object/member begins; padding is storage inserted
  to satisfy alignment.
- Tail padding lets consecutive struct array elements meet struct alignment.
- Member order can change padding and `sizeof(struct)`.
- Endian is byte order, not bit order.
- Raw struct serialization is unsafe across ABI/layout and endian boundaries.

What I still cannot explain:
- No unresolved concept blocker is recorded for this practice artifact.
- Independent ownership of Week 1 C concepts remains unverified until a fresh
  AI-0 gate.

### 10. Defects / Failed Tests

Defect/Test IDs:
- No unresolved source/test defect; final visible host suite is 25/25 PASS.
- Historical diagnostic-flow variance: the original generated pre-check was
  interrupted. Classification: `MENTOR/SYSTEM WORKFLOW VARIANCE — NON-SCORING`
  for W01D03 daily status.

Root cause known?:
YES — the learning flow changed to theory-first because prerequisite
understanding was insufficient; the missed pre-check cannot be recreated as a
genuine before-coding check.

Current hypothesis:
- Artifact behavior is correct under the verified host test contract.
- Passing tests do not establish competency.

### 11. Carry-over

Task:
- NONE from the W01D03 artifact. The historical diagnostic interruption is
  retained as a non-scoring mentor/system workflow variance, not converted into
  a fake diagnostic PASS or learner carry-over.
- W01D04 is the next scheduled execution. The Week 1 fresh AI-0 gate remains a
  required future gate, not a W01D03 artifact carry-over.

Closure criteria:
- W01D03 artifact/evidence and control bookkeeping committed atomically.
- Repository synchronized if push succeeds.
- `W01-C-FOUND` remains `COMPETENCY_UNVERIFIED` until the fresh AI-0 gate.

### 12. Next Action

BOOT

---

## 2026-08-13 — Week 01 / Day 04

### 1. Planned Outcome

Implement and explain a defensive `uint32_t` bit-operation API for set, clear,
extract and update; avoid undefined shifts, preserve destinations on rejection,
and save reproducible strict-build and host-test evidence.

### 2. Actual Status

GREEN — the authoritative W01D04 artifact, required execution evidence and
practice-level closed-book explanation criteria were completed.

### 3. Focused Time

Planned: 6–8h — roadmap standard daily load for a normal Week 1 technical day;
no separate learner-specific numeric plan was captured at START DAY.
Actual: ~5h — learner estimate

### 4. Independent Work

What I personally implemented, reasoned about, measured, or explained:

- Learner independently wrote the core implementations for `bit_set_u32`,
  `bit_clear_u32`, `bit_extract_u32` and `bit_update_u32`.
- Learner removed the earlier explicit width-32 assignment branch from
  `bit_update_u32`, rebuilt, and reran the complete visible host suite.
- Learner practiced and explained shift-width UB, validation-before-mask use,
  runtime validation versus `assert`, unsigned fixed-width operations,
  unchanged-on-rejection behavior, non-target-bit preservation and the
  `width == 32` boundary.
- Initial partial explanations were corrected during tutoring. The final
  explanation is practice evidence only, not independent E5 evidence.
- Assertion decision: keep caller-controlled failures under runtime validation;
  no useful additional internal invariant justified adding a cosmetic assert.

### 5. AI Usage

Highest AI level used: AI-3

What AI helped with:
- Short theory/clarification and hint-level guidance.
- Explanation of a pointer-versus-bit mistake and a generic mask-syntax example.
- Review/debug after meaningful learner attempts, including correctness and UB
  reasoning.
- Feedback on closed-book explanations and additional AND/OR mask practice.
- END DAY audit, evidence metadata and routine bookkeeping.

Files/functions materially assisted:
- Review of learner-written `learning/week-01/day-04/bit_ops.c` after attempts.
- W01D04 self-explanation feedback, evidence metadata and control bookkeeping.

Competencies contaminated:
- No complete bit-operations solution or AI-0 gate answer was provided.
- W01D04 remains assisted learning/practice and is not independent competency
  evidence; `W01-C-FOUND` remains `COMPETENCY_UNVERIFIED`.

Independent retest required:
- YES — fresh AI-0 Week 1 competency gate before any
  `W01-C-FOUND — COMPETENCY_PASS` claim.

### 6. Artifact Result

Files changed:
- `learning/week-01/day-04/TODO_W01_D04.md`
- `learning/week-01/day-04/bit_ops.c`
- `learning/week-01/day-04/bit_ops.h`
- `tests/host/test_bit_ops.c`
- `evidence/week-01/day-04/test_bit_ops.txt`

Build command:
`gcc -std=c17 -Wall -Wextra -Wpedantic -Werror learning/week-01/day-04/bit_ops.c tests/host/test_bit_ops.c -Ilearning/week-01/day-04 -o tests/host/test_bit_ops.exe`

Build result:
PASS — exit code 0, no warning/error under configured flags.

Test command:
`.\tests\host\test_bit_ops.exe`

Test result:
PASS — exit code 0; `SUMMARY: 34 tests, 0 failed`.

### 7. Evidence

Commit:
- Closure commit; see repository history.

Logs:
- `evidence/week-01/day-04/test_bit_ops.txt` — tracked UTF-8 verification record
  containing commands, expected/actual results, all 34 final test lines,
  assertion decision, provenance and limitations.

Captures:
- None

Reports:
- None

Video/demo:
- None

Other:
- `tests/host/test_bit_ops.exe` is generated, ignored by `*.exe` policy and not
  committed.

### 8. Measurements

Expected:
- Strict C17 build succeeds with all configured warnings treated as errors.
- All 34 visible host tests pass with zero failures.
- Rejected calls preserve destinations; full-width and boundary operations
  avoid invalid shifts; update preserves non-target bits.

Observed:
- Build exit code: 0.
- Test exit code: 0.
- Tests run: 34.
- Tests failed: 0.
- Result: PASS.

Relevant values/registers/timing/errors:
- No hardware/register/timing measurement was required for this host exercise.
- Actual focused time: ~5h — learner estimate.
- No unresolved final test ID.

### 9. Understanding Check

What I can explain without AI:
- Shift counts equal to or greater than the promoted type width are undefined in
  C, so ranges must be validated before a mask or shift is evaluated.
- Runtime validation handles caller-controlled invalid inputs; `assert` is for
  programmer/internal invariants and may be compiled out.
- Unsigned fixed-width integers make width and bitwise behavior explicit.
- Rejected operations preserve caller state by completing every failure check
  before writing the destination.
- A field mask clears/replaces only target bits, while the inverse mask keeps
  non-target bits; AND uses 1 to keep and 0 to clear, OR uses 0 to keep and 1
  to set.
- `width == 32` requires deliberate control flow so no shift by 32 is evaluated.

What I still cannot explain:
- No unresolved concept blocker is recorded for this practice artifact.
- Independent ownership of Week 1 C concepts remains unverified until a fresh
  AI-0 gate.

### 10. Defects / Failed Tests

Defect/Test IDs:
- None unresolved; final D04-T01 through D04-T34 all passed.

Root cause known?:
N/A — no final defect remains in the verified visible host-test contract.

Current hypothesis:
- Artifact behavior is correct under the verified host test contract.
- Passing tests and corrected practice explanations do not establish competency.

### 11. Carry-over

Task:
- NONE from the W01D04 artifact. W01D05 fixed-size ring buffer is the next
  scheduled execution, not recovery carry-over.
- The fresh Week 1 AI-0 gate remains a future requirement.

Closure criteria:
- W01D04 source/header/tests, reproducible evidence and control bookkeeping are
  included in one atomic closure commit.
- Repository is synchronized after the authorized push.
- `W01-C-FOUND` remains `COMPETENCY_UNVERIFIED`.

### 12. Next Action

BOOT — open W01D05 fixed-size ring buffer execution and declare its AI mode.

## 2026-08-14 — Week 01 / Day 05

### 1. Planned Outcome

Design, implement and explain a fixed-size `uint8_t` FIFO ring buffer; pass a
strict C17 build and repeatable host tests for normal, empty, full, wrap and
invalid-input behavior.

### 2. Actual Status

GREEN — the authoritative W01D05 artifact, required execution evidence and
practice-level closed-book state-reasoning criteria were completed.

### 3. Focused Time

Planned: ~7h
Actual: ~1.5h — learner estimate

The artifact and required reasoning stop conditions were satisfied
substantially earlier than planned. Planned hours are workload planning, not a
completion quota.

### 4. Independent Work

What I personally implemented, reasoned about, measured, or explained:

- Learner designed and implemented the final fixed-size ring-buffer core using
  compile-time storage plus `head`, `tail` and `count` state.
- Learner derived the push/pop state transitions and personally implemented
  rejection-before-mutation, wrap, count updates and FIFO behavior.
- Learner completed closed-book reasoning for the `head`/`tail`/`count`
  invariants, EMPTY/FULL distinction, logical FIFO order, wrap and failed-call
  state preservation.
- The closed-book explanation satisfies the W01D05 practice stop condition; it
  is not independent E5 competency evidence.

### 5. AI Usage

Highest AI level used: AI-3

What AI helped with:
- AI-1 theory and clarification.
- AI-2 graded hints, design questions and API discussion before implementation.
- AI-3 post-attempt code review after the learner completed the implementation.
- END DAY audit, evidence metadata and routine bookkeeping.

Files/functions materially assisted:
- The `ring_buffer` API/core was learner implemented; AI reviewed the completed
  implementation and reasoning after the learner's attempt.
- W01D05 evidence metadata and control bookkeeping.

Competencies contaminated:
- No AI-4/AI-5 replacement implementation was supplied, but this AI-assisted
  practice artifact does not independently verify `W01-C-FOUND`.
- `W01-C-FOUND` remains `COMPETENCY_UNVERIFIED`.

Independent retest required:
- YES — a fresh Week 1 AI-0 competency gate remains required before any
  `W01-C-FOUND — COMPETENCY_PASS` claim.

### 6. Artifact Result

Files changed:
- `learning/week-01/day-05/ring_buffer.h`
- `learning/week-01/day-05/ring_buffer.c`
- `learning/week-01/day-05/TODO_W01_D05.md`
- `tests/host/test_ring_buffer.c`
- `evidence/week-01/day-05/test_ring_buffer.txt`
- `roadmap-control/daily-log.md`
- `roadmap-control/ai-usage-log.md`
- `roadmap-control/current-state.md`

Build command:
`gcc -std=c17 -Wall -Wextra -Wpedantic -Werror learning/week-01/day-05/ring_buffer.c tests/host/test_ring_buffer.c -Ilearning/week-01/day-05 -o tests/host/test_ring_buffer.exe`

Build result:
PASS — exit code 0, no warning/error under configured flags.

Test command:
`.\tests\host\test_ring_buffer.exe`

Test result:
PASS — two consecutive runs each exited 0 with
`SUMMARY: 36 tests, 0 failed`.

### 7. Evidence

Commit:
SELF — containing commit

Logs:
- `evidence/week-01/day-05/test_ring_buffer.txt` — tracked UTF-8 verification
  record containing commands, expected/actual results, two final run summaries,
  historical baseline, provenance and limitations.

Captures:
- None

Reports:
- None

Video/demo:
- None

Other:
- `tests/host/test_ring_buffer.exe` is generated, ignored by `*.exe` policy and
  not committed.

### 8. Measurements

Expected:
- Strict C17 build succeeds with all configured warnings treated as errors.
- Required NORMAL, EMPTY, FULL, WRAP, repeated-wrap and INVALID INPUT tests pass.
- Failed push/pop operations preserve observable state; an empty pop preserves
  the caller's output value.

Observed:
- Build exit code: 0.
- Test run #1: 36 tests run, 0 failed, exit code 0.
- Test run #2: 36 tests run, 0 failed, exit code 0.
- All required W01D05 categories passed.

Relevant values/registers/timing/errors:
- Host GCC 14.2.0; C17; fixed capacity `RB_CAPACITY == 4`.
- Historical starter baseline from the prior session: 36 tests, 26 failed,
  exit code 1. It was not reconstructed during closure.
- No hardware/register/timing measurement was required for this host exercise.
- Actual focused time: ~1.5h — learner estimate.

### 9. Understanding Check

What I can explain without AI:
- `0 <= count <= capacity`, and `head`/`tail` stay in the valid index range.
- EMPTY is exactly `count == 0`; FULL is exactly `count == capacity`.
- A successful push writes at the old `head`, advances `head` with wrap and
  increments `count` without changing `tail`.
- A successful pop reads at the old `tail`, advances `tail` with wrap and
  decrements `count`.
- `tail` names the next logical FIFO element even when physical storage order
  differs from logical FIFO order.
- Rejected push/pop operations validate before mutation and preserve observable
  state; modulo implements wrap for this fixed capacity.

What I still cannot explain:
- None observed in the required W01D05 scope.
- Independent ownership of Week 1 C competency remains unverified until a fresh
  AI-0 gate.

### 10. Defects / Failed Tests

Defect/Test IDs:
- Final: none unresolved; D05-T01 through D05-T36 passed twice consecutively.
- Historical baseline: 36 tests, 26 failed before learner implementation.

Root cause known?:
- Final: N/A — no final defect remains in the verified visible host-test
  contract.
- Historical baseline failures belonged to the untouched TODO-stub behavior;
  no per-test root-cause detail was reconstructed during closure.

Current hypothesis:
- Artifact behavior is correct under the verified public host-test contract.
- Passing tests and practice reasoning do not establish competency.

### 11. Carry-over

Task:
- NONE from the W01D05 artifact. W01D06 independent coding gate is the next
  scheduled execution, not recovery carry-over.
- The fresh Week 1 AI-0 gate remains required.

Closure criteria:
- W01D05 source/header/TODO/tests, reproducible evidence and control bookkeeping
  are included in one atomic closure commit.
- Repository is synchronized after the authorized push.
- `W01-C-FOUND` remains `COMPETENCY_UNVERIFIED`.

### 12. Next Action

BOOT — open the W01D06 independent coding-gate contract and prepare the clean
45-minute AI-0 attempt; do not begin the gate before its contract is declared.

## 2026-08-15 — Week 01 / Day 06

### 1. Planned Outcome

Complete the roadmap's 45-minute independent C coding gate under AI-0, preserve
the original attempt before review, record the scored result and keep it
separate from the W01D07 Week 1 competency gate.

### 2. Actual Status

GREEN — `W01D06-C-CODING-01` closed with `98/100 PASS`; all mandatory items
passed, AI-0 integrity passed and the raw attempt was preserved unchanged.

This daily coding-gate PASS is not `W01-C-FOUND — COMPETENCY_PASS` and does not
mark Week 1 PASS.

### 3. Focused Time

Roadmap Standard Load: Week 1 roadmap load remains separate from learner time
estimates.

Available: ~7h — learner estimate

Planned: ~4h core + up to ~3h reserve

Actual: ~2h — learner estimate

The difference between planned/available and actual time is not underwork or
schedule debt. Hours are planning/accounting information, not a completion
quota. W01D06 stopped after its valid assessment/evidence conditions were met.

### 4. Independent Work

What I personally implemented, reasoned about, measured, or explained:

- Learner completed the scored attempt under AI-0 and supplied the original
  `safe_bit.c`, `copy_token.c` and `lifetime.c` files.
- Learner completed the Task 2 and Task 3 analysis plus the Task 4 struct-layout
  answer recorded in `RAW_WRITTEN_ANSWERS_W01D06.md`.
- Learner's Task 1 runner reported seven PASS results covering normal, full-width,
  MSB, NULL, zero-width, boundary-overflow and oversized-field cases.
- Learner closed the attempt before the 45-minute hard stop.

### 5. AI Usage

Scored phase: AI-0

External help during scored attempt: NO

Post-close phase: AI-3

Highest AI level used: AI-3 — post-close only; scored phase remained AI-0

What AI helped with:
- No hints, review, correctness feedback or solution assistance during
  `START GATE` through `CLOSE ATTEMPT`.
- After `CLOSE ATTEMPT`, AI reviewed/scored the submission, clarified the Task 2
  out-of-source-object undefined behavior and supported closure bookkeeping.
- Executor-created boundary tests were run only after closure of the attempt and
  are not attributed to the learner.

Files/functions materially assisted:
- Raw `.c` files: none; preserved byte-for-byte.
- Post-gate review record, reproducibility evidence, test harness and control
  bookkeeping: executor-assisted after `CLOSE ATTEMPT`.

Competencies contaminated:
- None in the valid W01D06 scored phase; AI-0 integrity is PASS.
- W01D06 is not the defined W01-C-FOUND competency gate. The later AI-3 review
  does not promote or retroactively invalidate the closed raw score.
- `W01-C-FOUND` remains `COMPETENCY_UNVERIFIED`.

Independent retest required:
- No retest is required for `W01D06-C-CODING-01`.
- W01D07 remains the separate required Week 1 independent competency gate; it is
  not a retest of the 98/100 daily coding-gate score.

### 6. Artifact Result

Assessment result:
- `W01D06-C-CODING-01 = 98/100 PASS`
- Task 1: 35/35
- Task 2: 28/30
- Task 3: 20/20
- Task 4: 15/15
- Mandatory items: PASS

Files changed:
- `.gitattributes` — exact-path `-text -eol` entries preserve raw scored bytes.
- `learning/week-01/day-06/safe_bit.c`
- `learning/week-01/day-06/copy_token.c`
- `learning/week-01/day-06/lifetime.c`
- `learning/week-01/day-06/RAW_WRITTEN_ANSWERS_W01D06.md`
- `learning/week-01/day-06/ASSESSMENT_RESULT_W01D06.md`
- `learning/week-01/day-06/POST_GATE_REVIEW_W01D06.md`
- `tests/host/test_w01d06_gate.c`
- `evidence/week-01/day-06/validation.txt`
- `roadmap-control/daily-log.md`
- `roadmap-control/ai-usage-log.md`
- `roadmap-control/current-state.md`
- `roadmap-control/competency-ledger.md`

Build commands:
- `gcc -std=c17 -Wall -Wextra -Wpedantic -Werror learning/week-01/day-06/safe_bit.c -o <temp>/safe_bit_learner.exe`
- Strict object builds for all three raw files, with Task 1 `main` renamed only
  by compiler macro in the executor harness object.
- `gcc -std=c17 -Wall -Wextra -Wpedantic -Werror tests/host/test_w01d06_gate.c <temp>/safe_bit.o <temp>/copy_token.o <temp>/lifetime.o -o <temp>/test_w01d06_gate.exe`

Build result:
PASS — every strict C17 build exited 0 with no warning/error.

Test result:
- Learner-authored Task 1 runner: seven reported tests PASS; exit code 0.
- Executor-created post-close harness: 14 tests, 0 failed; exit code 0.

### 7. Evidence

Commit:
SELF — containing commit

Logs:
- `evidence/week-01/day-06/validation.txt` — tracked UTF-8 validation record with
  commands, results, hashes, provenance and limitations.

Captures:
- None

Reports:
- `learning/week-01/day-06/ASSESSMENT_RESULT_W01D06.md`
- `learning/week-01/day-06/POST_GATE_REVIEW_W01D06.md`

Other:
- `learning/week-01/day-06/RAW_WRITTEN_ANSWERS_W01D06.md` preserves the raw
  non-file answers.
- `learning/week-01/day-06/safe_bit.exe` is learner-produced, ignored and not
  committed.

### 8. Measurements

Expected:
- Raw source hashes remain unchanged through closure.
- Strict-warning builds succeed.
- Learner Task 1 runner passes its seven reported cases.
- Executor post-close boundary harness passes without severe bounds/lifetime
  defects in the established corrected implementations.

Observed:
- All three raw SHA-256 values matched the learner-authorized baseline before
  closure edits.
- Strict builds exited 0 with no warning/error.
- Learner Task 1 runner: seven PASS results; exit code 0.
- Executor harness: `SUMMARY: 14 tests, 0 failed`; exit code 0.

Relevant values/registers/timing/errors:
- Attempt began approximately 10:18 and closed approximately 10:53
  Asia/Ho_Chi_Minh; no extra attempt time is invented.
- Actual focused time: ~2h — learner estimate.
- Host GCC 14.2.0; C17; no hardware/register measurement required.

### 9. Understanding Check

What I can explain without AI, as preserved in the raw answers:
- `sizeof(src)` on a function parameter gives pointer size, not string length.
- A terminator write at index `dst_cap` is out of bounds.
- NULL input requires explicit defensive handling.
- Returning the address of a local object creates a dangling pointer and
  undefined behavior.
- A status-return plus output-parameter API can preserve the output on failure.
- The original struct layout uses 12 bytes with four total padding bytes; the
  reordered layout uses 8 bytes with no padding under the stated ABI layout.

What required post-gate correction:
- The raw Task 2 explanation did not explicitly state that requesting
  `sizeof(src)` bytes may read beyond the source object itself; that access is
  undefined behavior, not guaranteed "garbage bytes".

### 10. Defects / Failed Tests

Defect/Test IDs:
- Task 2 analysis omission: two-point deduction, producing 28/30.
- Final technical validation: no failed learner-runner case and no failed
  executor-harness case.

Root cause known?:
- YES — the raw analysis identified pointer-size misuse but omitted the explicit
  source-object overread consequence.

Current hypothesis:
- The corrected implementation has no severe bounds defect under the verified
  contract. The post-gate explanation correction is recorded separately and
  does not alter the raw score.

### 11. Carry-over

Task:
- W01D07 — separate Week 1 review, English explanation and 60-minute independent
  competency gate.
- This is scheduled next work, not recovery carry-over from a failed W01D06.

Closure criteria:
- Raw attempt, written answers, score, post-gate correction, validation evidence
  and control bookkeeping are included in one atomic closure commit.
- AI-0 and post-close AI-3 phases remain distinct.
- `W01-C-FOUND` remains `COMPETENCY_UNVERIFIED`.
- Repository is synchronized after the authorized push.

### 12. Next Action

BOOT — open W01D07 as the separate Week 1 close/review and independent
competency-gate day. Do not reuse the W01D06 98/100 daily coding-gate PASS as
`W01-C-FOUND — COMPETENCY_PASS`.

## 2026-08-15 — Week 01 / Day 07

### 1. Planned Outcome

Complete the separate Week 1 C Foundations competency gate under AI-0, preserve
the recovered raw chat evidence, and record the post-gate volatile/UB
explanation without prematurely closing Week 1.

W01D07 was executed one day before its roadmap calendar date. The normal Day
Contract availability/planned-time precheck was skipped; this is recorded as
`MENTOR/SYSTEM WORKFLOW VARIANCE — NON-SCORING`.

### 2. Actual Status

GREEN — FINAL. W01D07 technical/assessment work, the remaining English oral
activity and all required Day-7/week-close evidence are complete. Tasks 1-4,
the mandatory bounds/lifetime condition and AI-0 integrity passed. The gate
decision remains categorical PASS, and `W01-C-FOUND` remains
`COMPETENCY_PASS`.

Historical note: W01D07 was previously marked GREEN for its technical/assessment
work before the remaining Day-7/week-close evidence was complete. MASTER CHECK
classified that premature whole-day GREEN as a MEDIUM finding. It did not affect
the competency PASS or AI-0 integrity and is `RESOLVED BY WEEK-1 FINAL CLOSURE`
through the persisted English oral note, Week-1 scorecard and RV-002 CP-01 review.

### 3. Focused Time

Roadmap Standard Load: Week 1 roadmap load remains separate from learner time
estimates.

Available: `NOT SUPPLIED`

Planned: `NOT SUPPLIED`

Actual: `~2h — learner estimate`

No underwork, schedule debt or Recovery state is inferred from Actual Focused
Time.

### 4. Independent Work

What I personally implemented, reasoned about, measured, or explained:

- Learner completed the fresh Week 1 C Foundations competency gate under AI-0
  and explicitly sent `CLOSE GATE` before the 60-minute hard stop.
- Learner answered pointer/array/qualifier questions, implemented a fresh safe
  bit-field extraction function, diagnosed bounds/lifetime defects and proposed
  a safe API redesign, and reasoned through unseen ring-buffer state.
- Learner supplied the post-gate volatile/UB explanation preserved separately
  from executor review caveats.
- Learner completed the scheduled English oral explanation about why `volatile`
  does not make code thread-safe. The delivery is recorded as non-competency
  communication evidence; no standalone audio exists and exact duration was not
  independently measured.
- No learner-created Day07 `.c` files or folder existed during the scored
  attempt; the direct chat answers are the raw competency evidence.

### 5. AI Usage

Scored phase: `AI-0`

External help during scored phase: `NO — learner human confirmation`

AI-0 integrity: `PASS`

Post-close phase: `AI-3 — assessment/review and administrative persistence`

Highest AI level used: AI-3 after `CLOSE GATE`; the scored phase remained AI-0.

What AI helped with:
- No hints, correctness feedback, solution assistance or gate answers during
  the scored phase.
- After closure, executor preserved the recovered raw text verbatim, authored
  the assessment/review files and prepared bounded control bookkeeping.
- AI also helped structure/edit the English wording before the learner spoke.
  This was allowed communication support outside the scored AI-0 gate.

Files/functions materially assisted:
- No learner-created Day07 `.c` file existed.
- Assessment result, post-gate review and control bookkeeping were
  executor-authored after closure.
- Raw Markdown evidence is an executor transcription of learner chat, not an
  executor solution.

Competencies contaminated:
- None in the scored W01D07 phase; AI-0 integrity is PASS.

Independent retest required:
- `NO — NONE REQUIRED` for `W01-C-FOUND` from this passed gate.

### 6. Artifact Result

Assessment result:
- Task 1: PASS
- Task 2: PASS
- Task 3: PASS
- Task 4: PASS
- Mandatory bounds/lifetime condition: PASS
- Decision: `CATEGORICAL PASS`
- Competency: `W01-C-FOUND — COMPETENCY_PASS`

Files changed by the earlier W01D07 gate-persistence transaction:
- `learning/week-01/day-07/RAW_COMPETENCY_SUBMISSION_W01D07.md`
- `learning/week-01/day-07/RAW_POST_GATE_EXPLANATION_W01D07.md`
- `learning/week-01/day-07/ASSESSMENT_RESULT_W01D07.md`
- `learning/week-01/day-07/POST_GATE_REVIEW_W01D07.md`

Files changed by the Week-1 final-closure transaction:
- `learning/week-01/day-07/ENGLISH_ORAL_EXPLANATION_W01D07.md`
- `roadmap-control/weekly-scorecards/week-01.md`
- `roadmap-control/daily-log.md`
- `roadmap-control/current-state.md`
- `docs/system/ROADMAP_REVIEW_LOG.md`

Build:
`NOT RUN — optional executor C transcription/validation was not required for
the recovered persistence transaction.`

Tests:
`NOT RUN — no learner Day07 source files existed; technical scoring rests on
the closed raw submission and recorded assessment decision.`

Week-1 final-closure validation:
- Canonical W01D01-W01D06 strict host builds/tests were rerun using temporary
  output paths; all builds and tests passed.
- W01D01: 46 tests, 0 failed.
- W01D02: runtime output `11 20 0 6 W01D02`.
- W01D03: 25 tests, 0 failed.
- W01D04: 34 tests, 0 failed.
- W01D05: two consecutive runs, each 36 tests and 0 failed.
- W01D06: learner runner seven PASS results; executor harness 14 tests, 0 failed.

### 7. Evidence

Commit:
`SELF — containing commit`

Logs:
- None; no optional C transcription/validation run was performed.

Captures:
- None

Reports:
- `learning/week-01/day-07/ASSESSMENT_RESULT_W01D07.md`
- `learning/week-01/day-07/POST_GATE_REVIEW_W01D07.md`
- `learning/week-01/day-07/ENGLISH_ORAL_EXPLANATION_W01D07.md`
- `roadmap-control/weekly-scorecards/week-01.md`
- `docs/system/ROADMAP_REVIEW_LOG.md` — `RV-002 — CP-01 End of Week 1`

Other:
- `learning/week-01/day-07/RAW_COMPETENCY_SUBMISSION_W01D07.md` preserves Raw
  Tasks 1-4 verbatim.
- `learning/week-01/day-07/RAW_POST_GATE_EXPLANATION_W01D07.md` preserves the
  volatile/UB explanation verbatim.

### 8. Measurements

Expected:
- Raw Tasks 1-4 and the post-gate volatile/UB block match the recovered learner
  transcript verbatim.
- The categorical PASS is not converted to a numeric score.
- Only `W01-C-FOUND` transitions from `COMPETENCY_UNVERIFIED` to
  `COMPETENCY_PASS`.
- The earlier gate-persistence snapshot correctly kept Week 1 pending MASTER
  CHECK and CP-01 / WEEKLY REVIEW. This final transaction completes those steps
  and closes Week 1 as PASS.

Observed:
- Raw block comparison: PASS for Tasks 1-4 and volatile/UB explanation.
- Gate: PASS; AI-0 integrity: PASS; external help: NO by learner human
  confirmation.
- Post-gate volatile/UB explanation: `PASS WITH PRECISION CAVEATS`.
- MASTER CHECK: `PASS WITH FINDINGS`; MEDIUM resolved, LOW accepted/no action.
- CP-01: `RV-002 PERSISTED`; Week-1 Weekly Decision: `PASS`.

Relevant values/registers/timing/errors:
- Date executed: `2026-08-15`; roadmap calendar Day 7: `2026-08-16`.
- Time limit: `60 minutes maximum`; learner completed before the hard stop.
- Actual Focused Time: `~2h — learner estimate`.
- Available Focused Time: `NOT SUPPLIED`.
- Planned Focused Time: `NOT SUPPLIED`.
- English oral-practice exact duration: `NOT INDEPENDENTLY MEASURED`.
- Standalone audio retained: `NO`.
- No hardware/register measurement was required.

### 9. Understanding Check

What I can explain without AI, as preserved in raw evidence:
- Pointer/array distinctions, array-parameter adjustment, qualifier effects and
  one-past-end restrictions.
- Safe bit-field extraction with validation-before-output-mutation and valid
  shift counts.
- Bounds overflow, expired-local lifetime and caller-owned storage redesign.
- Ring-buffer FIFO state using `head`, `tail` and `count`.
- `volatile` does not supply atomicity, locking, synchronization or memory
  barriers; several common C undefined-behavior classes.

What required post-gate precision caveats:
- Pointer validity is more constrained than "can point anywhere".
- `volatile` is stated in terms of required observable volatile accesses, not
  arbitrary physical-memory guarantees.
- Declaring an uninitialized local is not itself undefined behavior; the actual
  issue is a language-invalid use of an indeterminate value.

### 10. Defects / Failed Tests

Defect/Test IDs:
- None severe in the assessed mandatory bounds/lifetime scope.
- No numeric deductions exist because the declared result is categorical.
- MASTER CHECK MEDIUM: premature whole-day GREEN — `RESOLVED BY WEEK-1 FINAL
  CLOSURE`; no competency or retest impact.
- MASTER CHECK LOW: Task-2 `1u << i` theoretical C-portability caveat —
  `ACCEPT / NO ACTION REQUIRED`; no learner raw-code change.

Root cause known?:
- N/A — the gate passed its mandatory criteria.

Current hypothesis:
- No fresh retest is required for `W01-C-FOUND` from this gate.
- Review caveats improve precision without altering raw evidence or the closed
  categorical decision.

### 11. Carry-over

Task:
- `NONE`

Closure criteria:
- English oral note, Week-1 scorecard, MASTER CHECK disposition, RV-002 CP-01
  review and final control state are included in one bounded containing commit.
- Week 1 Weekly Decision: `PASS`; Week 2 prerequisite: `SATISFIED`.

Recovery:
- `NOT ACTIVE`

### 12. Next Action

Project Chat reviews the recorded CP-01 workflow observations before making any
workflow/gate-system change; W02D01 remains eligible but `NOT STARTED` until its
normal start workflow begins.

---

## 2026-08-17 — Week 02 / Day 01

### 1. Planned Outcome

Build a practical Cortex-M mental model covering Thread/Handler mode, MSP/PSP
and exception entry/return, then preserve the required learner-created diagram
and closed-book reconstruction.

### 2. Actual Status

GREEN

### 3. Focused Time

Planned: ~7h

Actual: ~2h56m — learner-derived estimate

### 4. Independent Work

What I personally implemented, reasoned about, measured, or explained:

- Read and reasoned from learner-provided excerpts/screenshots of the ARM guide.
- Produced self-explanations and a closed-book reconstruction.
- Reasoned about MSP/PSP selection and exception-frame placement.
- Distinguished nested/preemption, late-arriving and tail-chaining.
- Created the Thread/Handler + exception-flow diagram.

### 5. AI Usage

Highest AI level used: AI-3

What AI helped with:
- AI-1 theory/clarification from learner-provided ARM Cortex-M4 documentation.
- AI-2 comprehension questions and bounded hints.
- AI-3 review/correction of learner reasoning and the learner-created diagram
  after meaningful learner attempts.

Files/functions materially assisted:
- Review of W02D01 worksheet/diagram concepts.
- Routine closure bookkeeping.

Competencies contaminated:
NONE — normal learning day; no new competency PASS is claimed.

Independent retest required:
NO

External technical help outside Project Chat:
NO

### 6. Artifact Result

Files changed:
- `learning/week-02/day-01/TODO_W02_D01.md`
- `learning/week-02/day-01/CORTEX_M_EXCEPTION_FLOW_W02D01.md`
- `learning/week-02/day-01/cortex_m_exception_flow.png`
- `learning/week-02/day-01/SUBMIT_W02_D01.md`
- `roadmap-control/daily-log.md`
- `roadmap-control/ai-usage-log.md`
- `roadmap-control/current-state.md`

Build command:
N/A — theory/diagram day

Build result:
N/A

Test command:
N/A — no code test required by W02D01

Test result:
N/A

### 7. Evidence

Commit:
SELF — containing commit

Logs:
N/A

Captures:
- `learning/week-02/day-01/cortex_m_exception_flow.png`

Reports:
- `learning/week-02/day-01/CORTEX_M_EXCEPTION_FLOW_W02D01.md`
- `learning/week-02/day-01/SUBMIT_W02_D01.md`

Video/demo:
N/A

Other:
- `learning/week-02/day-01/TODO_W02_D01.md`

### 8. Measurements

Expected:
Practical Cortex-M Thread/Handler + exception-flow mental model.

Observed:
Learner reconstructed the required flow and produced diagram evidence.

Relevant values/registers/timing/errors:
No debugger/register measurement performed. Previous STM32 baseline source was
deleted; no hardware/debug observation was fabricated.

### 9. Understanding Check

What I can explain without AI:
- Thread mode runs normal application execution and may use MSP or PSP.
- Reset defaults Thread mode to MSP because `CONTROL.SPSEL` resets to 0.
- Handler mode is always privileged and always uses MSP.
- Exception entry stacks context on the current stack; if Thread uses PSP, the
  exception frame is stacked on PSP while Handler runs on MSP.
- EXC_RETURN carries return-mode, restoration-stack and floating-point-state
  information.
- Late-arriving, nested/preemption and tail-chaining are distinct flows.

What I still cannot explain:
- Detailed roles of xPSR and R0-R3/R12 in the exception stack frame.
- Deeper EXC_RETURN mechanics.

### 10. Defects / Failed Tests

Defect/Test IDs:
No code tests.

Learning misconceptions corrected during the session:
- reset stack default;
- exception-frame stack selection;
- EXC_RETURN vs tail-chaining responsibility;
- timing distinction among late-arriving / nested / tail-chaining.

Root cause known?:
YES — these were learning misconceptions resolved through source review and
post-attempt feedback.

Current hypothesis:
No unresolved blocker exists for the W02D01 practical mental-model outcome.

### 11. Carry-over

Task:
NONE

Closure criteria:
N/A — required W02D01 artifact/evidence is complete. The absence of debugger
observation is not a mandatory W02D01 carry-over.

### 12. Next Action

BOOT W02D02; inspect the Week 2 Day 2 startup-sequence contract and locate the
vector table / `Reset_Handler` path.

---

## 2026-08-18 — Week 02 / Day 02

### 1. Planned Outcome

Trace vector table -> `Reset_Handler` -> `.data`/`.bss` -> `SystemInit` ->
`main`, and produce the power-on-to-main artifact.

### 2. Actual Status

GREEN

### 3. Focused Time

Planned: UNRECOVERABLE PROCESS VARIANCE — the W02D02 Day Contract did not
preserve a trusted numeric value; no value is inferred from the transient `6h`
availability or from timestamps.

Actual: ~3h56m — learner estimate

This total includes ~1h — learner estimate of supplemental PC-hosted startup-
simulator reinforcement completed after the initial W02D02 closure.

### 4. Independent Work

What I personally implemented, reasoned about, measured, or explained:

- Traced the real vector table and startup source.
- Reasoned about `_estack`, initial MSP and `Reset_Handler`.
- Traced `.data` copy and `.bss` zeroing.
- Identified linker symbols from source and fresh map evidence.
- Reconstructed the power-on-to-`main()` sequence in the learner's own words.
- Implemented the learner-owned `startup.c` core: manual `.data` copy, manual
  `.bss` zero, and runtime-before-application sequencing without `memcpy` or
  `memset`.
- Corrected the BSS trace-index instrumentation so the final trace records
  indices `0,1,2,3`.
- Ran and diagnosed all five simulator fault scenarios, then mapped the
  simulator concepts back to the STM32 startup model.

### 5. AI Usage

Highest AI level used: AI-5 — executor-prepared lab/reference/infrastructure,
including the supplemental simulator scaffold, harness, tests, fault system,
documentation scaffold and build plumbing. Project Chat also exposed direct
implementation structure/syntax and debugging guidance for the learner-owned
startup core.

What AI helped with:
- Theory/clarification of the vector table, startup flow, Flash/RAM sections,
  linker symbols, `SystemInit()` and `__libc_init_array()`.
- Review/correction after meaningful learner attempts.
- Administrative worksheet/submission support and closure bookkeeping.
- Complete bounded STM32F446RE lab/reference infrastructure.
- Direct guided structure/syntax for the supplemental `.data`/`.bss` loops and
  trace instrumentation, plus fault-diagnosis tutoring and mapping review.

Files/functions materially assisted:
- `firmware/stm32/w02d02-startup-lab/**` — executor-prepared
  lab/reference/infrastructure, including bounded `main.c` and `build.ps1`.
- Administrative assistance around W02D02 worksheet/submission and control
  records; the final learner reconstruction was not AI-authored.
- `learning/week-02/startup-simulator/**` — executor-generated simulator
  infrastructure/reference material. The learner entered and iterated the
  final `src/startup.c` core and performed the fault diagnosis, but substantial
  exact implementation structure/syntax was exposed during tutoring.

Competencies contaminated:
NONE invalidated — no new competency PASS is claimed. The artifact remains
learning evidence; the scheduled fresh Week 2 AI-0 gate is still required.
The supplemental simulator is valid learning/artifact evidence, not independent
competency evidence.

Independent retest required:
NO special retest solely for this learning-day assistance; normal Week 2 AI-0
gate remains required.

External technical help outside Project Chat:
YES — executor-prepared lab/reference/infrastructure.

### 6. Artifact Result

Files changed:
- `learning/week-02/day-02/TODO_W02_D02.md`
- `learning/week-02/day-02/POWER_ON_TO_MAIN_W02D02.md`
- `learning/week-02/day-02/SUBMIT_W02_D02.md`
- `firmware/stm32/w02d02-startup-lab/**` excluding ignored `build/` products
- `learning/week-02/startup-simulator/**` excluding ignored `build/` products
- `roadmap-control/daily-log.md`
- `roadmap-control/ai-usage-log.md`
- `roadmap-control/current-state.md`

Build command:
`powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`

Build result:
PASS / exit 0. Linker reported non-blocking `nosys` warnings for `_close`,
`_lseek`, `_read` and `_write`; no startup-trace artifact was missing.

Test command:
N/A — required validation was clean build plus source/map/list inspection.

Test result:
N/A

Supplemental simulator validation:
- Command: `.\run_tests.ps1` from `learning/week-02/startup-simulator`
- Result: PASS — `100% tests passed, 0 tests failed out of 4`; `30/30`
  individual cases PASS (`9` memory-layout, `6` CPU-reset, `10` learner-startup,
  `5` fault-campaign cases).
- Build: C11 with GCC 14.2 and `-Wall -Wextra -Wpedantic -Werror`; no compiler
  warning or error was reported in the successful run.
- Demo commands: `.\build\startup_demo.exe none`, `data-short`, `skip-bss`,
  `bad-stack`, `main-before-runtime`, and `wrong-reset-handler`; all returned
  exit `0` with the expected controlled observations.

### 7. Evidence

Commit:
SELF — containing commit

Logs:
- Fresh map inspection of `build/w02d02-startup-lab.map`
- Fresh supplemental simulator test and six-mode demo output observed directly
  during this closure transaction.

Captures:
N/A

Reports:
- `learning/week-02/day-02/POWER_ON_TO_MAIN_W02D02.md`
- `learning/week-02/day-02/SUBMIT_W02_D02.md`

Video/demo:
N/A

Other:
- `firmware/stm32/w02d02-startup-lab/PROVENANCE.md`
- Generated ELF/map/list under ignored `build/`

### 8. Measurements

Expected:
- Startup source and fresh map reproduce the vector/startup path and linker
  ranges recorded by the learner.

Observed:
- `Reset_Handler = 0x08000204`
- `SystemInit = 0x08000258`
- `main = 0x0800027c`
- `__libc_init_array = 0x08000294`
- `_sidata = 0x080002fc`
- `_sdata = 0x20000000`, `_edata = 0x20000004`
- `_sbss = 0x20000004`, `_ebss = 0x20000024`

Relevant values/registers/timing/errors:
- `.data` size: `4 bytes`
- `.bss` size: `0x20 = 32 bytes`
- These are build/map observations, not hardware measurements.
- Debugger/hardware observation: `NOT PERFORMED`.

Supplemental simulator observations:
- Baseline changed `.data` from `0xDEADBEEF x4` to
  `0x11111111,0x22222222,0x33333333,0x44444444`; `.bss` changed from
  `0xA5A5A5A5 x4` to zero; runtime init preceded `app_main`; MSP was
  `0x20000040`; guards remained intact.
- `data-short` left only the last `.data` word poisoned; `skip-bss` left all
  `.bss` words poisoned despite reaching the app; `bad-stack` stopped before
  `Reset_Handler`; `main-before-runtime` exposed the wrong trace order; and
  `wrong-reset-handler` dispatched to `Fault_Handler` with startup memory still
  poisoned. These are simulator fault-injection lessons, not hardware findings.

### 9. Understanding Check

What I can explain without AI, as preserved in the learner artifact:
- The first two vector entries provide initial MSP and reset-entry information.
- `Reset_Handler` reloads SP, calls `SystemInit()`, copies `.data`, zeroes
  `.bss`, calls `__libc_init_array()` and then calls `main()`.
- The linker symbols connect the Flash load address and RAM runtime ranges.
- Vector entry 0 supplies the initial MSP while entry 1 targets the reset
  handler; `_sidata` is the Flash initialization-image start;
  `_sdata`/`_edata` and `_sbss`/`_ebss` are half-open RAM ranges.
- Correct final memory state does not prove correct runtime/application order,
  and reaching the app does not prove startup memory initialization succeeded.

What I still cannot explain:
- No unresolved mandatory W02D02 question was recorded.

### 10. Defects / Failed Tests

Defect/Test IDs:
NONE remaining for the required W02D02 artifact/build/map contract or the
supplemental simulator validation.

Root cause known?:
N/A

Current hypothesis:
The non-blocking `nosys` syscall warnings do not affect this bounded startup
trace; no source or build-logic change is required for W02D02 closure.
The earlier all-zero BSS trace indices were an instrumentation/measurement
defect, not a startup memory-state defect; the final trace records `0,1,2,3`.

### 11. Carry-over

Task:
NONE

Closure criteria:
N/A — the required W02D02 artifact and reproducible build/map evidence are
complete.

Recovery:
NOT ACTIVE

### 12. Next Action

BOOT W02D03 and open the authoritative RCC/GPIO sources before writing the
register-level GPIO output code.

---

## 2026-08-19 — Week 02 / Day 03

### 1. Planned Outcome

RCC + register-level GPIO output: verify official clock/pin facts,
independently configure GPIO output, clean build, hardware LED smoke test,
expected/actual, controlled negative case and register checklist.

### 2. Actual Status

GREEN

The authoritative W02D03 stop criteria were satisfied.

### 3. Focused Time

Roadmap Standard Load: 46–49 focused hours/week

Available: 6h — learner supplied at start of day

Planned: 6h

Actual: ~3.5h — learner estimate

### 4. Independent Work

What I personally implemented, reasoned about, measured, or explained:

- Traced the board user LED to PA5 from UM1724.
- Traced RCC/GPIO fields from RM0390 and derived GPIOAEN, MODER5 and BSRR
  bit positions.
- Wrote the core RCC/GPIO register implementation.
- Ran clean builds, flashed the board and observed the normal LD2 behavior.
- Performed the GPIOA clock-disable negative test and restored the working state.
- Explained clock-before-GPIO, field-mask read-modify-write preservation, BSRR
  rationale, active-HIGH LED polarity and the RCC -> MODER -> output -> physical
  path diagnostic order.

### 5. AI Usage

Highest AI level used: AI-5

What AI helped with:
- Executor-created starter/build/vendor infrastructure.
- Theory and official-source navigation guidance plus graded pre-check support.
- Post-attempt code/build/debug review.
- Material evidence/checklist/submission wording assistance and closure bookkeeping.

Files/functions materially assisted:
- W02D03 starter/infrastructure files.
- `firmware/stm32/w02d03-gpio-lab/main.c` review only after a meaningful
  learner attempt; no complete core implementation solution was provided.
- W02D03 evidence documentation and closure control records.

Competencies contaminated:
- W02D03 learning/artifact evidence is not independent competency evidence.
- No previously verified competency is invalidated and no new competency PASS
  is claimed.

Independent retest required:
- NO special retest triggered by this learning day.
- The normal scheduled fresh Week 2 AI-0 competency gate remains required.

### 6. Artifact Result

Files changed:
- `firmware/stm32/w02d03-gpio-lab/main.c`
- `learning/week-02/day-03/TODO_W02_D03.md`
- `learning/week-02/day-03/REGISTER_CHECKLIST_W02D03.md`
- `learning/week-02/day-03/SUBMIT_W02_D03.md`
- `roadmap-control/daily-log.md`
- `roadmap-control/ai-usage-log.md`
- `roadmap-control/current-state.md`

Build command:
`powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`

Build result:
PASS / exit 0. Linker reported inherited non-blocking `nosys` warnings for
`_close`, `_lseek`, `_read` and `_write`.

Test command:
Hardware LED smoke test plus controlled GPIOA clock-disable negative case.

Test result:
PASS — normal LD2 ON; clock disabled -> LD2 OFF; clock restored -> LD2 ON.

### 7. Evidence

Commit:
SELF — containing commit

Logs:
Clean-build result is recorded in this daily/evidence text; no standalone signal
log was created.

Captures:
NONE

Reports:
- `learning/week-02/day-03/REGISTER_CHECKLIST_W02D03.md`
- `learning/week-02/day-03/SUBMIT_W02_D03.md`

Video/demo:
Live onboard LD2 demo observed; no saved video.

Other:
- Exact flash command/tool action: NOT RECORDED.
- Register view: NOT MEASURED.

### 8. Measurements

Expected:
- PA5 HIGH -> LD2 ON.
- With GPIOA clock enable removed, intended GPIO output behavior fails and LD2
  remains OFF.

Observed:
- Normal LD2 ON.
- Negative case LD2 OFF.
- Restored LD2 ON.

Relevant values/registers/timing/errors:
- RCC_AHB1ENR.GPIOAEN bit 0.
- GPIOA_MODER.MODER5 bits 11:10 = `01`.
- BSRR set bit 5 and reset bit 21.
- Direct register-view values: NOT MEASURED.

### 9. Understanding Check

What I can explain without AI:
- The GPIO peripheral clock dependency.
- Field-mask/read-modify-write preservation of unrelated register bits.
- BSRR atomic set/reset versus ODR read-modify-write.
- Active-HIGH LED polarity.
- RCC -> MODER -> output -> physical path diagnostic sequence.

What I still cannot explain:
No current blocker, but Week 2 competency remains to be independently verified.

### 10. Defects / Failed Tests

Defect IDs or test IDs:
NONE. The clock-disable case was an intentional negative test, not an unresolved
defect.

Root cause known?:
N/A

Current hypothesis:
No unresolved final artifact defect. The inherited `nosys` linker warnings do
not affect the bounded GPIO artifact.

### 11. Carry-over

Exactly one mandatory carry-over if needed:
NONE from W02D03. Normal W02D04 is the next scheduled work, not recovery
carry-over.

Closure criteria:
MET

### 12. Next Action

BOOT W02D04 and begin GPIO input/pull-up plus BSRR versus
ODR/read-modify-write work.

---

## 2026-08-20 — Week 02 / Day 04

### 1. Planned Outcome

GPIO input and BSRR: verify the NUCLEO-F446RE button topology, implement and
test PC13 input controlling PA5/LD2, compare BSRR with ODR read-modify-write,
run a controlled negative case, and save input/output capture evidence.

### 2. Actual Status

GREEN

The authoritative W02D04 input/output test and capture criteria were satisfied.
Register-view evidence was optional/non-scoring and was not measured.

### 3. Focused Time

Roadmap Standard Load: 46–49 focused hours/week

Available: 6h — learner supplied

Planned: 6h

Actual: 6h — learner supplied

### 4. Independent Work

What I personally implemented, reasoned about, measured, or explained:

- Made substantial implementation attempts and corrected multiple register and
  mask mistakes interactively.
- Implemented the final PC13 active-low input to PA5/LD2 behavior.
- Ran the clean build and flashed through STM32CubeProgrammer using onboard
  ST-LINK / SWD.
- Measured B1/PC13 at approximately 3.19 V released and 0 V pressed.
- Performed the button/LED normal tests, BSRR/ODR visible-behavior comparison,
  controlled polarity-negative case, restoration, and logic-analyzer capture.
- Demonstrated the GPIO/RCC/register/bit-mask understanding summarized below
  during an assisted learning session.

### 5. AI Usage

Highest AI level used: AI-5

What AI helped with:
- Executor-prepared starter/build/vendor infrastructure.
- Extensive theory instruction and iterative review.
- Complete/reference-level core GPIO code snippets after learner attempts.
- Evidence/checklist/submission wording and closure bookkeeping.

Files/functions materially assisted:
- W02D04 starter, build, and vendor infrastructure.
- Core GPIO input/output implementation was exposed through complete/reference-
  level snippets after iterative learner attempts.
- W02D04 evidence documentation, provenance, and closure control records.

Competencies contaminated:
- W02D04 learning/artifact evidence is not independent competency evidence.
- No previously verified competency is invalidated and no new competency PASS
  is claimed.

Independent retest required:
- The normal scheduled fresh Week 2 AI-0 competency gate remains required.

### 6. Artifact Result

Files changed:
- `firmware/stm32/w02d04-gpio-input-lab/main.c`
- `firmware/stm32/w02d04-gpio-input-lab/PROVENANCE.md`
- `learning/week-02/day-04/TODO_W02_D04.md`
- `learning/week-02/day-04/GPIO_CHECKLIST_W02D04.md`
- `learning/week-02/day-04/SUBMIT_W02_D04.md`
- `learning/week-02/day-04/evidence/W02D04_PC13_PA5_CAPTURE.png`
- `roadmap-control/daily-log.md`
- `roadmap-control/ai-usage-log.md`
- `roadmap-control/current-state.md`

Build command:
`powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`

Build result:
PASS / exit 0. Final size: `text=860`, `data=0`, `bss=1568`, `dec=2428`,
`hex=97c`. ELF: `build/w02d04-gpio-input-lab.elf`. The linker reported inherited
non-blocking `nosys` warnings for `_close`, `_lseek`, `_read`, and `_write`.

Test command:
Learner-performed NUCLEO-F446RE B1/LD2 smoke tests, BSRR/ODR comparison,
controlled polarity-negative case, restoration, multimeter measurement, and
logic-analyzer capture.

Test result:
PASS — press B1 -> LD2 ON; release B1 -> LD2 OFF. Both BSRR and ODR RMW
variants produced this visible behavior in the simple single-context test.
The intentional polarity reversal produced the predicted inverted behavior,
and normal active-low behavior returned after restoration.

### 7. Evidence

Commit:
SELF — containing commit

Logs:
Final clean-build result is recorded in this daily/evidence text; no standalone
build log was committed.

Captures:
`learning/week-02/day-04/evidence/W02D04_PC13_PA5_CAPTURE.png`

Capture mapping supplied by learner:
- D0 = PC13 / button input
- D1 = PA5 / LD2 output
- Released: PC13 HIGH; PA5 LOW; LD2 OFF
- Pressed: PC13 LOW; PA5 HIGH; LD2 ON
- Repeated inverse transitions are visible.

Reports:
- `learning/week-02/day-04/GPIO_CHECKLIST_W02D04.md`
- `learning/week-02/day-04/SUBMIT_W02_D04.md`

Video/demo:
Live B1/LD2 behavior was observed by the learner; no saved video was supplied.

Other:
- Flash/programming: STM32CubeProgrammer via onboard ST-LINK / SWD.
- Connected target observed: STM32F446xx, Cortex-M4, approximately 3.30 V,
  512 KB flash.
- Exact ST-LINK serial: NOT RECORDED.
- Register view: NOT MEASURED / OPTIONAL / NON-SCORING.

### 8. Measurements

Expected:
- Released -> PC13 HIGH; PA5 LOW; LD2 OFF.
- Pressed -> PC13 LOW; PA5 HIGH; LD2 ON.
- With software polarity intentionally reversed: released -> LD2 ON; pressed ->
  LD2 OFF.

Observed:
- Released -> PC13 HIGH; PA5 LOW; LD2 OFF.
- Pressed -> PC13 LOW; PA5 HIGH; LD2 ON.
- B1/PC13 measured approximately 3.19 V released and 0 V pressed.
- Reversed-polarity negative case matched the predicted inverted behavior.
- After restore: pressed -> LD2 ON; released -> LD2 OFF.
- Normal behavior remained correct after STM32CubeProgrammer was disconnected.

Relevant values/registers/timing/errors:
- Board: NUCLEO-F446RE; physical marking observed: MB1136 rev C.
- B1/PC13 is active-low; no internal pull was selected. External pull-up
  behavior was consistent with the schematic used during the session.
- PC13 MODER/PUPDR field: bits 27:26; IDR mask: `(1U << 13)`.
- PA5 BSRR set bit: 5; reset bit: 21. Learner also correctly derived the
  general reset location as pin + 16 and PA13 reset bit as 29.
- Direct register-view values and timing measurements: NOT MEASURED.

### 9. Understanding Check

What I demonstrated/explained during the assisted learning session:
- GPIOA is a port/group; PA5 is one pin inside GPIOA.
- An input receives an external electrical state for software to read and
  interpret; an output is driven by the MCU.
- RCC clocks must be enabled for the corresponding ports: PC13 belongs to
  GPIOC and PA5 belongs to GPIOA.
- MODER selects each pin's mode using two bits per pin; the PC13 field is bits
  27:26 and begins at bit 26.
- PUPDR controls pull-up, pull-down, or no-pull; active-low behavior was
  correctly interpreted after measurement and no internal pull was selected.
- IDR reports input logic; ODR represents the output latch/state; BSRR directly
  sets or resets selected bits.
- `1U << n` creates a bit mask. AND, OR, NOT, shifts, and clearing a two-bit
  field using shifted `0b11`, NOT, then AND were correctly explained/applied.
- BSRR reset uses pin + 16; PA13 reset was correctly derived as bit 29.
- ODR RMW is READ -> MODIFY -> WRITE. BSRR writes set/reset directly without a
  prior ODR read, avoiding an RMW window and a class of lost-update problems.

These explanations were demonstrated after substantial theory teaching and
iterative review. They are not claimed as perfect unaided prior knowledge, and
no real concurrency race was experimentally reproduced.

What I still cannot claim from this day:
Independent Week 2 competency. A fresh AI-0 competency gate remains required.

### 10. Defects / Failed Tests

Defect IDs or test IDs:
NONE. The reversed-polarity case was intentional and the working state was
restored.

Root cause known?:
YES — software intentionally treated active-low hardware as active-high.

Current hypothesis:
No unresolved final artifact defect. The inherited `nosys` warnings do not
affect this bounded GPIO artifact.

### 11. Carry-over

Exactly one mandatory carry-over if needed:
NONE. W02D05 is normal scheduled work, not Recovery carry-over.

Closure criteria:
MET

Recovery:
NOT ACTIVE

### 12. Next Action

Open the W02D05 EXTI/NVIC day card and RM0390, then write down the PC13-to-EXTI13
routing path before changing code.

---

## 2026-08-21 — Week 02 / Day 05

### 1. Planned Outcome

Configure SYSCFG/EXTI/NVIC for B1/PC13, clear the relevant pending source
correctly, keep the ISR minimal, demonstrate a PA5/LD2 button-interrupt toggle,
run one controlled trigger-edge negative case, restore the working state, and
save evidence.

### 2. Actual Status

GREEN

Expected versus actual:
- Expected: PC13 falling edges route through EXTI13 to the shared EXTI15_10 IRQ;
  the handler clears PR13 and toggles PA5.
- Actual: initial LD2 OFF; first press -> ON; release -> no change; second press
  -> OFF. The rising-edge-only negative case moved the toggle to release, and
  the restored falling-edge configuration passed.

### 3. Focused Time

Roadmap Standard Load: 46–49 focused hours/week

Available: NOT SUPPLIED in the closeout input

Planned: NOT SUPPLIED in the closeout input

Actual: 6h — learner supplied

### 4. Independent Work

What I personally implemented, reasoned about, measured, or explained:

- Implemented the final SYSCFG clock enable, PC13-to-EXTI13 routing, trigger,
  pending clear, mask, NVIC enable/priority, and `EXTI15_10_IRQHandler` logic.
- Verified the active-low relationship: PC13 released HIGH and pressed LOW.
- Ran the hardware demo: initial LD2 OFF; first press -> ON; release -> no
  change; second press -> OFF.
- Predicted and ran the rising-edge-only negative case, explained the LOW-to-HIGH
  release edge, restored falling-edge operation, and retested successfully.
- Supplied the two LD2 state photographs used as repository evidence.

### 5. AI Usage

Highest AI level used: AI-5

What AI helped with:
- Executor-prepared starter/build/vendor infrastructure.
- Substantial interactive theory teaching and review after learner attempts.
- Evidence/submission drafting and END DAY closure bookkeeping.

Files/functions materially assisted:
- W02D05 starter, build, and vendor infrastructure.
- `firmware/stm32/w02d05-exti-nvic-lab/main.c` post-attempt review; the learner
  retained ownership of the final core EXTI/NVIC implementation.
- W02D05 submission/evidence metadata and closure control records.

Competencies contaminated:
- W02D05 learning/artifact evidence is not independent competency evidence.
- No previously verified competency is invalidated and no new competency PASS
  is claimed.

Independent retest required:
- The normal scheduled fresh Week 2 AI-0 competency gate remains required.

### 6. Artifact Result

Files changed:
- `firmware/stm32/w02d05-exti-nvic-lab/main.c`
- `learning/week-02/day-05/SUBMIT_W02_D05.md`
- `learning/week-02/day-05/evidence/W02D05_LD2_OFF.jpg`
- `learning/week-02/day-05/evidence/W02D05_LD2_ON_AFTER_PRESS.jpg`
- `roadmap-control/daily-log.md`
- `roadmap-control/ai-usage-log.md`
- `roadmap-control/current-state.md`

Build command:
`powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`

Build result:
PASS / exit 0. Final size: `text=1164`, `data=0`, `bss=1568`, `dec=2732`,
`hex=aac`. ELF: `build/w02d05-exti-nvic-lab.elf`. The linker reported only the
inherited non-blocking `nosys` warnings for `_close`, `_lseek`, `_read`, and
`_write`.

Test command:
Learner-performed NUCLEO-F446RE B1/LD2 interrupt demo, controlled
rising-edge-only negative case, restoration, and two state photographs.

Test result:
PASS — initial OFF; first press ON; release unchanged; second press OFF. With
rising-edge-only, press caused no toggle and release toggled. Falling-edge
operation was restored and passed.

### 7. Evidence

Commit:
SELF — containing commit

Logs:
Final clean-build result is recorded in this daily/evidence text; no standalone
build log was committed.

Captures:
- `learning/week-02/day-05/evidence/W02D05_LD2_OFF.jpg`
- `learning/week-02/day-05/evidence/W02D05_LD2_ON_AFTER_PRESS.jpg`

Reports:
- `learning/week-02/day-05/SUBMIT_W02_D05.md`

Video/demo:
Live B1/LD2 interrupt behavior was observed by the learner; no saved video was
supplied.

Other:
- Exact flash method/command: NOT RECORDED in the closeout input.
- Direct EXTI/NVIC debugger register capture: NOT MEASURED.
- Exact official-document revisions/pages/sections: NOT RECORDED.

### 8. Measurements

Expected:
- Released PC13 HIGH; pressed PC13 LOW.
- Falling edge: press toggles LD2; release does not toggle.
- Rising-edge-only negative case: press does not toggle; release toggles.

Observed:
- Initial LD2 OFF; first press -> ON; release -> no change; second press -> OFF.
- Rising-edge-only: press -> no toggle; release -> toggle.
- After restore: falling-edge configuration -> PASS.

Relevant values/registers/timing/errors:
- `RCC_APB2ENR.SYSCFGEN` enabled.
- `SYSCFG_EXTICR4.EXTI13` selects GPIOC.
- Final trigger: `FTSR.TR13=1`, `RTSR.TR13=0`; `IMR.MR13=1`.
- Stale `PR13` is cleared before `NVIC_EnableIRQ(EXTI15_10_IRQn)`.
- `EXTI_PR.PR13` uses write-1-to-clear behavior.
- Voltage, timing, bounce, and direct register values: NOT MEASURED.

### 9. Understanding Check

What I demonstrated/explained during the assisted learning session:
- PC13 is active-low: a press is HIGH-to-LOW and therefore a falling edge.
- GPIOC is selected for EXTI13 through the EXTI13 field in EXTICR4.
- EXTI13 is unmasked and uses the shared EXTI15_10 NVIC interrupt.
- The handler must check PR13 because the vector is shared, clear PR13 using
  write-1-to-clear semantics, and remain minimal.
- In the negative case, release changes PC13 from LOW to HIGH, which explains
  why rising-edge-only toggled on release rather than press.

These explanations followed substantial interactive AI teaching/review and are
learning evidence, not independent competency evidence.

What I still cannot claim from this day:
Independent Week 2 competency. A fresh AI-0 competency gate remains required.

### 10. Defects / Failed Tests

Defect IDs or test IDs:
NONE. The rising-edge-only case was intentional and the working state was
restored.

Root cause known?:
YES — release creates the configured LOW-to-HIGH rising edge.

Current hypothesis:
No unresolved final artifact defect. Button bounce was not characterized. The
inherited `nosys` warnings do not affect this bounded EXTI/NVIC artifact.

### 11. Carry-over

Exactly one mandatory carry-over if needed:
NONE. W02D06 debounce and schematic review are normal scheduled work, not
Recovery carry-over.

Closure criteria:
MET

Recovery:
NOT ACTIVE

### 12. Next Action

BOOT W02D06 and begin debounce with a tick/state machine plus NUCLEO-F446RE
schematic review.

---

## 2026-08-22 — Week 02 / Day 06

### 1. Planned Outcome

Implement a non-blocking debounce tick/state machine and review the
NUCLEO-F446RE schematic for the B1/PC13 and PA5/LD2 paths.

### 2. Actual Status

GREEN

Expected versus actual:
- Expected: a continuously stable raw transition commits at the exact threshold,
  interrupted candidates restart, and one semantic event is emitted per stable
  transition; annotated schematic and debounce log exist.
- Actual: strict host tests passed 10/10, the STM32 clean build passed, repeated
  valid USER-button presses toggled LD2 OFF/ON, and both schematic PNGs plus the
  debounce log are present and readable.

### 3. Focused Time

Roadmap Standard Load: 46–49 focused hours/week

Available: 6h

Planned: 6h

Actual: 6h — learner supplied

### 4. Independent Work

What I personally implemented, reasoned about, measured, or explained:

- Owned the final debounce transition logic, integration attempts, and corrected
  press/release handling.
- Explained continuous candidate timing, exact-threshold acceptance, candidate
  restart, unsigned tick-wrap handling, event uniqueness, and the ISR/foreground
  boundary.
- Operated the physical NUCLEO-F446RE and observed repeated valid presses toggle
  LD2 OFF/ON.
- Inspected the C03 and C04 schematic candidate packs and recorded the verified
  B1/PC13 and PA5/LD2 paths while leaving the physical C03/C04 match unresolved.

### 5. AI Usage

Highest AI level used: AI-3

What AI helped with:
- Theory/clarification and graded hints.
- Post-attempt code review/debug.
- SysTick/integration guidance and diagnosis of the release-edge hardware defect.
- Evidence-document assistance and END DAY bookkeeping.

Files/functions materially assisted:
- W02D06 debounce and STM32 integration after meaningful learner attempts.
- W02D06 submission, debounce log, schematic worksheet, and closure records.

Competencies contaminated:
- W02D06 is assisted normal-learning/artifact evidence only.
- No new competency PASS is claimed.

Independent retest required:
- The normal scheduled fresh Week 2 AI-0 competency gate remains required.

### 6. Artifact Result

Files changed:
- `firmware/stm32/w02d06-debounce-lab/**`
- `tests/host/test_debounce.c`
- `learning/week-02/day-06/**`
- `roadmap-control/daily-log.md`
- `roadmap-control/ai-usage-log.md`
- `roadmap-control/current-state.md`

Host compile command:
`gcc -std=c17 -Wall -Wextra -Wpedantic -Werror firmware/stm32/w02d06-debounce-lab/debounce.c tests/host/test_debounce.c -Ifirmware/stm32/w02d06-debounce-lab -o tests/host/test_debounce.exe`

Host compile/test result:
PASS — `SUMMARY: 10 tests, 0 failed`.

STM32 build command:
`powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`

STM32 build result:
PASS / exit 0. Final size: `text=1652`, `data=0`, `bss=1576`, `dec=3228`,
`hex=c9c`. ELF: `build/w02d06-debounce-lab.elf`. Only inherited non-blocking
`nosys` warnings for `_close`, `_lseek`, `_read`, and `_write` were emitted.

### 7. Evidence

Commit:
SELF — containing commit

Logs:
- `learning/week-02/day-06/DEBOUNCE_LOG_W02D06.md`

Captures:
- `learning/week-02/day-06/schematic_b1_pc13_page3.png`
- `learning/week-02/day-06/schematic_pa5_ld2_page5.png`

Reports:
- `learning/week-02/day-06/SUBMIT_W02_D06.md`
- `learning/week-02/day-06/SCHEMATIC_REVIEW_W02D06.md`

Video/demo:
Learner/session capture filename: `VID_20260822_140328.mp4`. The video is
`NOT STORED IN REPO`.

Other:
- Exact flash/debug command or tool method: NOT RECORDED.
- Physical main-board marking: `MB1136 rev C`.
- Exact physical C03/C04 subrevision: UNRESOLVED.

### 8. Measurements

Expected:
- SysTick period: 1 ms; threshold: 20 ticks = 20 ms.
- Released B1/PC13 HIGH; pressed LOW; one activation event per committed press.

Observed:
- Repeated valid USER-button presses toggled LD2 OFF/ON across successive
  activations.
- Initial stuck-after-first-activation behavior was corrected.

Relevant values/registers/timing/errors:
- `SystemCoreClock = 16000000U`.
- `SysTick_Config(16000000U / 1000U)`.
- Electrical voltage: NOT MEASURED.
- Physical switch bounce duration: NOT MEASURED.

### 9. Understanding Check

What I demonstrated/explained during the assisted learning session:
- A candidate must remain continuously unchanged for the full threshold; raw
  interruption or reversal cancels/restarts it.
- The exact threshold is accepted and each committed stable transition emits
  exactly one semantic event.
- Unsigned `uint32_t` subtraction preserves elapsed-time behavior across wrap
  for the bounded debounce interval.
- EXTI ISR work remains short; foreground sampling performs timed debounce and
  observes both press and release stable states.

These explanations are assisted learning evidence, not independent competency
evidence.

What I still cannot claim from this day:
Independent Week 2 competency. A fresh AI-0 competency gate remains required.

### 10. Defects / Failed Tests

Defect IDs or test IDs:
- Initial host iteration: 3 failed tests; corrected to 10/10 PASS.
- Initial STM32 integration: missing SysTick functions caused link failure;
  corrected and clean build passed.
- Initial hardware integration: release was not incorporated correctly, leaving
  later presses unable to toggle; corrected and repeated-press behavior passed.

Root cause known?:
YES for the resolved integration defects described above.

Current hypothesis:
No unresolved artifact defect. Exact C03/C04 physical subrevision remains
unresolved; exact flash/debug command is NOT RECORDED; electrical voltage and
physical bounce duration were NOT MEASURED. Inherited `nosys` warnings are
non-blocking.

### 11. Carry-over

Exactly one mandatory carry-over if needed:
NONE. The authoritative W02D06 artifact requirements passed.

Closure criteria:
MET

Recovery:
NOT ACTIVE

### 12. Next Action

BOOT W02D07 and begin the scheduled fresh Week-2 AI-0 competency gate/preparation
according to the authoritative roadmap.

---

## 2026-08-23 — Week 02 / Day 07

### 1. Planned Outcome

Attempt the Week 2 Cortex-M / GPIO / EXTI competency gate covering power-on to
`main()`, startup, RCC/GPIO, BSRR versus ODR read-modify-write, EXTI diagnosis,
and transfer/fault reasoning.

### 2. Actual Status

GREEN — W02D07 CLOSED after a valid fresh retest; original attempt retained as
historical `INVALID / RETEST REQUIRED`

Technical review found broadly PASS-level reasoning, with precision findings
around half-open `.data`/`.bss` range arithmetic, an over-broad peripheral-clock
bus-fault assumption, and an EXTI symptom mismatch. The learner then produced a
post-gate correction distinguishing interrupt storm/retrigger behavior from a
true one-shot/silent interrupt symptom.

The attempt is invalid for competency because external lookup occurred during a
scored phase whose declared contract prohibited documentation, search, notes,
and previous solutions. This is not a technical competency FAIL.

A fresh unseen retest was then completed under a prospectively declared AI-0
contract allowing only official manual/datasheet/vendor-header lookup for
register, bitfield, and IRQ names. Technical result was `PASS`; learner
integrity declaration was `CLEAN`; official result was `COMPETENCY PASS`.

### 3. Focused Time

Roadmap Standard Load: 46–49 focused hours/week

Available: ~6h — learner supplied

Planned: Assessment start planned for 10:30 local; no full-day planned focused
time value is recorded.

Actual: ~2h — learner supplied

Gate timing: 10:22 local start recorded in Project Chat; 11:11 local close;
~49 minutes elapsed within the 60-minute maximum.

### 4. Independent Work

- Completed the original assessment attempt across startup, GPIO, EXTI, and
  transfer/fault reasoning.
- After the scored phase, disclosed limited external lookup transparently.
- Produced a post-gate correction distinguishing uncleared EXTI pending state
  from stronger hypotheses for an ISR that runs once and becomes silent.
- Completed a fresh unseen retest covering startup, GPIO concurrency/BSRR,
  EXTI/vector/pending-clear diagnosis, and evidence-based fault isolation.

The raw attempt remains historical/learning evidence but is not admissible as
independent competency evidence under the contract actually used.

### 5. AI Usage

Highest AI level used: AI-3 — post-gate review, career/admin drafting, and
evidence/control-plane administration. The fresh scored retest remained AI-0.

Scored-phase disclosure:
`YES 1 tí, tôi dùng để tra cứu 1 số tên thanh ghi thôi ko tra cả đáp án`

The exact external lookup source/tool is not available to the executor and is
not inferred. The scored phase must not be represented as clean AI-0/closed-book
integrity.

Original-attempt competency effect:
The original W02D07 attempt cannot independently award Week 2 competency.

Fresh retest integrity:
`CLEAN — learner-supplied authoritative declaration`; official references were
allowed prospectively and AI/tutorial/previous-answer/answer-search use was
prohibited.

Independent retest required after the fresh attempt:
NO.

### 6. Artifact Result

Full W02D07/Week 2 closeout paths (the three original-attempt files below remain
historical and were not modified by the fresh-retest transaction):
- `learning/week-02/day-07/RAW_COMPETENCY_SUBMISSION_W02D07.md`
- `learning/week-02/day-07/ASSESSMENT_RESULT_W02D07.md`
- `learning/week-02/day-07/POST_GATE_REVIEW_W02D07.md`
- `learning/week-02/day-07/RAW_COMPETENCY_RETEST_W02D07.md`
- `learning/week-02/day-07/ASSESSMENT_RESULT_RETEST_W02D07.md`
- `learning/week-02/day-07/SUBMIT_W02_D07.md`
- `career/CV_MASTER.md`
- `career/GITHUB_PROFILE_BASELINE.md`
- `learning/week-02/CAREER_EVIDENCE_W02.md`
- `learning/week-02/MASTER_CHECK_W02.md`
- `roadmap-control/weekly-scorecards/week-02.md`
- Week 2 evidence/control-plane records.

Build:
W02D06 STM32 clean rebuild `PASS / exit 0`; size
`text=1652 data=0 bss=1576 dec=3228 hex=c9c`. No firmware/source behavior was
modified.

Tests:
Startup simulator `30/30 PASS`; debounce strict host tests `10/10 PASS`.

### 7. Evidence

- Raw: `learning/week-02/day-07/RAW_COMPETENCY_SUBMISSION_W02D07.md`
- Result: `learning/week-02/day-07/ASSESSMENT_RESULT_W02D07.md`
- Review: `learning/week-02/day-07/POST_GATE_REVIEW_W02D07.md`
- Fresh retest raw boundary: `learning/week-02/day-07/RAW_COMPETENCY_RETEST_W02D07.md`
- Fresh retest result: `learning/week-02/day-07/ASSESSMENT_RESULT_RETEST_W02D07.md`
- Submission: `learning/week-02/day-07/SUBMIT_W02_D07.md`
- Career: `learning/week-02/CAREER_EVIDENCE_W02.md`
- MASTER CHECK: `learning/week-02/MASTER_CHECK_W02.md`
- Scorecard: `roadmap-control/weekly-scorecards/week-02.md`

No W02D07 build, flash, debugger, hardware, register-capture, or electrical
measurement evidence was created or claimed.

### 8. Measurements

Available Focused Time: ~6h — learner supplied

Actual Focused Time: ~2h — learner supplied

Health/load: 2 — sustainable — learner supplied

Assessment elapsed: ~49 minutes based on recorded 10:22–11:11 local timestamps.

Fresh retest/admin/career additional actual time: NOT SUPPLIED; no time is
invented or added to the learner-supplied `~2h` daily value.

### 9. Understanding Check

Post-gate correction recorded:
- uncleared pending state can immediately retrigger and cause an interrupt storm
  or severe main starvation;
- true one-shot/silent behavior more strongly suggests no new edge, masking or
  disabling, or an ISR/called path that does not return normally;
- for write-1-to-clear `EXTI_PR`, direct `EXTI->PR = bit` is clearer than the
  dangerous read-modify-write form `EXTI->PR |= bit`.

This correction does not retroactively repair the invalid scored attempt.

Fresh retest findings — non-blocking:
- the FPU example is conditional on project/system requirements;
- prefer `single write / no RMW / peripheral-supported atomic bit set-reset`
  for BSRR rather than a universal single-cycle-bus claim;
- for `PR |= BIT`, the primary RMW risk is clearing other pending bits already
  read as `1`.

### 10. Defects / Failed Tests

Original attempt: `INVALID / RETEST REQUIRED`; technical FAIL `NO`.

Fresh retest: `PASS`; integrity `CLEAN`; official result `COMPETENCY PASS`.

Career task: `PASS — CV master skeleton + GitHub profile baseline draft complete`.
Public profile README remains `NOT DEPLOYED` and is not claimed live.

### 11. Carry-over

Carry-over: NONE.

Recovery:
NOT ACTIVE — fresh retest passed, no P0 blocker exists, and Week 2 closure
criteria are satisfied.

### 12. Next Action

BOOT Week 3 according to the authoritative roadmap. Do not mark the calendar as
Week 3 until that BOOT occurs.

Week 2 is `PASS / CLOSED`; `W02-C-MCU-FOUND = COMPETENCY_PASS`; Week 3 eligibility
is `YES`. Roadmap review is `NOT DUE`; the next formal checkpoint remains CP-02
on 2026-09-06.

---

## 2026-08-24 — Week 03 / Day 01

### 1. Planned Outcome

Derive the actual USART2 peripheral clock and baud divider, implement register-level
polling TX/RX, and capture a physical echo at the intended baud.

### 2. Actual Status

GREEN — W03D01 CLOSED / ARTIFACT_PASS.

The clean firmware build and physical USART2 polling echo passed. This normal
learning day did not contain an independent competency gate.

### 3. Focused Time

Available: 6h — learner supplied

Planned: UNRECOVERABLE PROCESS VARIANCE — no Planned Focused Time value was
supplied in the W03D01 closure input; no value is inferred.

Actual: 2h — learner supplied

### 4. Independent Work

- Reasoned the active clock path as HSI 16 MHz -> SYSCLK 16 MHz -> HPRE /1 ->
  HCLK 16 MHz -> PPRE1 /1 -> PCLK1 16 MHz -> USART2.
- Derived and used BRR 139 decimal / `0x008B` for 16 MHz, 115200 baud,
  oversampling by 16, and 8N1 framing.
- Implemented register-level GPIOA/USART2 setup, PA2/PA3 AF7, polling TX/RX,
  and one-byte echo after meaningful learner attempts.
- Performed the flash/terminal workflow and observed the physical echo on COM4.

These are assisted learning facts and artifact evidence, not independent
competency evidence.

### 5. AI Usage

Highest AI level used: AI-3

What AI helped with: theory/explanation, graded hints, and post-attempt
review/debug after meaningful learner core implementation attempts.

Files/functions materially assisted: W03D01 UART learning/review and closure
evidence/control-plane administration.

Competencies contaminated: W03D01 cannot be used as independent competency
evidence.

Independent retest required: NO special retest created by this normal learning
day; no AI-0 gate occurred and no competency result is awarded.

### 6. Artifact Result

Files changed: W03D01 learning evidence/submission, UART lab artifact, and the
allowlisted daily/AI/current-state closure records.

Build command: `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`
from `firmware/stm32/w03d01-uart-polling-lab`.

Build result: PASS / exit 0; `text=1084`, `data=0`, `bss=1568`, `dec=2652`,
`hex=a5c`; only inherited non-blocking `nosys` warnings for `_close`, `_lseek`,
`_read`, and `_write`.

Test command: `python -m serial.tools.miniterm --parity N COM4 115200`

Test result: physical polling echo PASS at 115200, 8N1, with hardware/software
flow control inactive.

### 7. Evidence

Commit: `SELF — containing commit`

Logs: miniterm visibly reported `COM4 115200,8,N,1`.

Captures: `learning/week-03/day-01/Screenshot_1.png`

Reports: `learning/week-03/day-01/SUBMIT_W03_D01.md`

Video/demo: NONE.

Other: STM32CubeProgrammer GUI was used to flash; exact GUI steps/settings and
no CLI flashing command were recorded.

### 8. Measurements

Expected: receive one byte by polling `RXNE`, then echo it by polling `TXE` and
writing `USART2->DR` at 115200, 8N1.

Observed: `UART123 -> UART123`; the ANSI Right Arrow sequence `ESC [ C` was also
echoed as `ESC [ C`.

Relevant numbers/registers/timing/errors: USART2 peripheral clock 16 MHz; BRR
139 decimal / `0x008B`; logic-analyzer/oscilloscope baud timing NOT MEASURED.

### 9. Understanding Check

What I demonstrated/explained during the assisted learning session: the
HSI-to-PCLK1 clock path, baud-divider relationship, explicit 8N1 configuration,
and why `TXE` and `RXNE` guard the transmit/receive data-register accesses.

What I still cannot claim from this day: independent competency. Exact official
source locations, connector/debugger routing, and wire timing were not recorded.

### 10. Defects / Failed Tests

Defect IDs or test IDs: NONE unresolved. The expected inherited `nosys` linker
warnings are non-blocking.

Root cause known?: N/A.

Current hypothesis: no unresolved artifact defect supported by the supplied
build and physical echo evidence.

### 11. Carry-over

Exactly one mandatory carry-over if needed: NONE.

Closure criteria: MET.

Recovery: NOT ACTIVE.

### 12. Next Action

BOOT W03D02.

---

## 2026-08-25 — Week 03 / Day 02

### 1. Planned Outcome

Add USART2 RXNE interrupt reception, keep the ISR short, reason explicitly about
shared state, and produce a physical IRQ demo plus register/evidence capture.

### 2. Actual Status

GREEN — W03D02 CLOSED / ARTIFACT_PASS.

The clean firmware build, physical USART2 RX interrupt demo, register capture,
controlled ORE case, recovery, and post-recovery echo passed. This normal
learning day did not contain an independent competency gate.

### 3. Focused Time

Available: 6h — learner supplied

Planned: UNRECOVERABLE PROCESS VARIANCE — no Planned Focused Time value was
supplied in the W03D02 closure input; no value is inferred.

Actual: 3h — learner supplied

### 4. Independent Work

- Implemented USART2 RXNE interrupt enable, NVIC configuration, and the exact
  `USART2_IRQHandler` vector symbol after learner-first attempts.
- Kept the ISR bounded to condition checks, one DR read, one mailbox-byte store,
  and one ready-flag update; foreground performs mailbox consumption and polling TX.
- Reasoned about ISR-producer/foreground-consumer ownership and protected the
  foreground copy/clear sequence by temporarily masking `USART2_IRQn`.
- Performed the COM4 physical IRQ/echo demo, breakpoint/register inspection,
  controlled ORE experiment, SR-to-DR recovery, and post-recovery echo.

These are assisted learning facts and artifact evidence, not independent
competency evidence.

### 5. AI Usage

Highest AI level used: AI-3

What AI helped with: executor starter preparation only, followed by post-attempt
review/debug assistance and END DAY evidence/control-plane administration.

Files/functions materially assisted: W03D02 starter infrastructure, learning
review/debug after learner attempts, submission/provenance, and closure records.

Competencies contaminated: W03D02 cannot be used as independent competency
evidence.

Independent retest required: NO special retest created by this normal learning
day; no AI-0 gate occurred and no competency result is awarded.

### 6. Artifact Result

Files changed: W03D02 learning evidence/submission, learner UART RX IRQ lab
artifact, provenance, and the allowlisted daily/AI/current-state closure records.

Build command: `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`
from `firmware/stm32/w03d02-uart-rx-irq-lab`.

Build result: PASS / exit 0; `text=1420`, `data=0`, `bss=1568`, `dec=2988`,
`hex=bac`; only inherited non-blocking `nosys` warnings for `_close`, `_lseek`,
`_read`, and `_write`.

Test setup: physical COM4 USART2 path at 115200, 8N1, line ending None; VS Code
Cortex-Debug breakpoint/register inspection through ST-LINK GDB Server.

Test result: physical RX IRQ and foreground echo PASS; controlled ORE capture,
SR-to-DR recovery, and post-recovery `R` echo PASS.

### 7. Evidence

Commit: `SELF — containing commit`

Logs: VS Code Serial Monitor showed the sent/echoed bytes on COM4.

Captures: `learning/week-03/day-02/Screenshot_1.png` through
`learning/week-03/day-02/Screenshot_4.png`.

Reports: `learning/week-03/day-02/SUBMIT_W03_D02.md`

Video/demo: NONE.

Other: exact backend flash command and terminal extension/version were NOT
RECORDED; no value is inferred.

### 8. Measurements

Expected: each slow single-byte input triggers USART2 RX interrupt service,
moves the byte into the depth-1 mailbox, permits foreground consumption, and is
echoed through polling TX. Holding the CPU before the DR read while more bytes
arrive should assert ORE; the SR-read then DR-read sequence should recover.

Observed: normal breakpoint capture showed `USART2->CR1=8236 / 0x202C`,
`USART2->SR=240 / 0x00F0`, and `NVIC->ISER[1]=64 / 0x00000040`; forced ORE showed
`USART2->SR=248 / 0x00F8`; recovery showed `USART2->SR=192 / 0x00C0` with ORE=0
and RXNE=0; post-recovery `R -> R` passed.

Relevant numbers/registers/timing/errors: COM4, 115200 8N1; no independent wire
timing measurement was supplied.

### 9. Understanding Check

What I demonstrated/explained during the assisted learning session: RXNE/RXNEIE
and NVIC gating, exact vector symbol, bounded ISR versus foreground work,
producer/consumer shared state, the depth-1 mailbox limitation, ORE cause, and
SR-to-DR recovery behavior.

What I still cannot claim from this day: independent competency. Exact official
document revisions, backend flash command, and terminal extension/version were
not recorded.

### 10. Defects / Failed Tests

Defect IDs or test IDs: NONE unresolved. The expected inherited `nosys` linker
warnings are non-blocking.

Root cause known?: N/A.

Current hypothesis: no unresolved artifact defect supported by the supplied
build and physical/debug evidence.

### 11. Carry-over

Exactly one mandatory carry-over if needed: NONE.

Closure criteria: MET.

Recovery: NOT ACTIVE.

Known limitation: receive storage is a single-byte mailbox (depth=1); burst
traffic can overwrite/drop data. Ring buffer integration is intentionally the
W03D03 target, not a W03D02 defect repair.

### 12. Next Action

BOOT W03D03 — open the W03D03 roadmap day card and define the ring-buffer
producer/consumer invariants before implementation.

---

## 2026-08-26 — Week 03 / Day 03

### 1. Planned Outcome

Replace the depth-1 USART2 RX mailbox with a fixed-size ring buffer, define a
bounded overflow policy and observable error counter, and verify the integrated
artifact with repeatable host tests, a clean STM32 build, and physical evidence.

### 2. Actual Status

GREEN — W03D03 CLOSED / ARTIFACT_PASS.

A fixed-size 8-byte USART2 RX ring buffer was integrated with DROP_NEWEST
overflow behavior and an observable overflow counter. Host, STM32 build, normal
UART, and forced-overflow evidence passed. This normal learning day creates no
new competency result.

### 3. Focused Time

Available: 6h — learner supplied

Planned: 6h — learner supplied

Actual: 3.5h — learner supplied

Hours are planning/history only. No schedule debt is inferred merely because
Actual is lower than Planned. Health impact: NOT RECORDED.

### 4. Independent Work

- Implemented fixed-capacity static ring-buffer state with head, tail, count,
  and overflow_count.
- Selected and justified DROP_NEWEST, preserving accepted FIFO contents while
  making sustained-overflow loss observable.
- Integrated the ISR producer with foreground consumption under a short
  USART2_IRQn-disabled critical section.
- Ran the host suite, clean firmware build, physical UART demo, forced-overflow
  experiment, and debugger counter observation.
- Explained empty, partial, full, push, pop, wrap, and failed-push transitions.

These are assisted learning facts and artifact evidence, not independent
competency evidence.

### 5. AI Usage

Highest AI level used: AI-3

What AI helped with: executor-prepared starter/repository infrastructure,
visible host-test scaffolding, theory and graded hints, post-attempt review/debug,
hardware/debug setup guidance, and closure/evidence administration.

Files/functions materially assisted: W03D03 starter infrastructure, learning
review/debug after learner attempts, submission, and closure records.

Competencies contaminated: W03D03 cannot be used as independent competency
evidence.

Independent retest required: NO special retest created by this normal learning
day; no AI-0 gate occurred and no competency result is awarded.

### 6. Artifact Result

Files changed: learner-owned W03D03 ring-buffer/UART source, W03D03 screenshots,
TODO/submission, and the allowlisted daily/AI/current-state closure records.

Host compile command: `gcc -std=c17 -Wall -Wextra -Wpedantic -Werror firmware/stm32/w03d03-uart-ring-buffer-lab/rx_ring_buffer.c tests/host/test_w03d03_rx_ring_buffer.c -Ifirmware/stm32/w03d03-uart-ring-buffer-lab -o tests/host/test_w03d03_rx_ring_buffer.exe`.

Host result: PASS / exit 0; `SUMMARY: 11 tests, 0 failed`.

Build command: `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`
from `firmware/stm32/w03d03-uart-ring-buffer-lab`.

Build result: PASS / exit 0; `text=1720`, `data=0`, `bss=1592`, `dec=3312`,
`hex=cf0`; only inherited non-blocking `nosys` warnings for `_close`, `_lseek`,
`_read`, and `_write`.

### 7. Evidence

Commit: `SELF — containing closure commit`

Logs: VS Code Serial Monitor on COM4 at 115200, 8N1.

Captures: `learning/week-03/day-03/Screenshot_1.png`, `Screenshot_2.png`, and
`Screenshot_3.png`.

Reports: `learning/week-03/day-03/SUBMIT_W03_D03.md`

Video/demo: NONE.

### 8. Measurements

Expected: normal input is echoed in FIFO order; under forced sustained overflow,
DROP_NEWEST preserves accepted queued bytes and increments overflow_count.

Observed: normal `UART123 -> UART123` PASS; forced overflow produced attributable
truncated FIFO output `BCDEFGHI`; final observed overflow counter was `14`.

Relevant setup: NUCLEO-F446RE, COM4, 115200 baud, 8N1; STM32CubeProgrammer flash;
GDB hardware debug through arm-none-eabi-gdb, ST-LINK_gdbserver, SWD, and
localhost:61234.

### 9. Understanding Check

What I demonstrated/explained during the assisted learning session: empty,
partial, and full invariants; successful push/pop and wrap transitions;
DROP_NEWEST failed-push state preservation; producer/consumer ownership; and why
volatile is not a lock.

What I still cannot claim from this day: independent competency.

### 10. Defects / Failed Tests

Defect IDs or test IDs: NONE unresolved. Temporary foreground delay and
overflow_snapshot instrumentation were removed before final verification. The
expected inherited `nosys` linker warnings are non-blocking.

Root cause known?: N/A.

Current hypothesis: no unresolved artifact defect supported by the verified
host, build, and physical evidence.

### 11. Carry-over

Exactly one mandatory carry-over if needed: NONE.

Closure criteria: MET.

Recovery: NOT ACTIVE.

Known limitations: fixed 8-byte RX capacity; DROP_NEWEST intentionally loses new
bytes during sustained overflow; foreground uses a short USART2 IRQ-disabled
critical section; TX remains polling; no DMA, parser, or RTOS is in W03D03 scope.

### 12. Next Action

BOOT W03D04 — open the authoritative W03D04 roadmap day card before defining the
next Day Contract.
