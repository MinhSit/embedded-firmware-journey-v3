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

---

## 2026-08-27 — Week 03 / Day 04

### 1. Planned Outcome

Implement a bounded non-blocking parser for `help`, `status`, `led`, and `rate`
commands with line timeout, invalid-input handling, length protection, and clean
state recovery, then verify it with repeatable host tests.

### 2. Actual Status

GREEN — W03D04 CLOSED / ARTIFACT_PASS.

The hardware-independent parser passed all normal, boundary, malformed,
overlong, timeout, tick-wrap, recovery, and repeated-use host cases. The STM32
target clean-built with the parser object included. This normal learning day
creates no new competency result.

### 3. Focused Time

Available: 6h — learner supplied

Planned: 6h — learner supplied

Actual: 2.5h — learner supplied

Planned-vs-actual variance: -3.5h. Hours are planning/history only. The lower
actual time is not a failure or Recovery trigger. Health impact: NOT RECORDED.

### 4. Independent Work

- Implemented parser initialization and reusable state invariants.
- Implemented bounded accumulation with NUL termination and LF/CRLF handling.
- Recognized `help`, `status`, `led on|off|toggle`, and bounded decimal `rate`.
- Distinguished malformed arguments from unknown commands.
- Implemented exact-length handling, one-shot overlong reporting, and
  discard-until-EOL resynchronization.
- Implemented inter-byte timeout with unsigned tick-wrap-safe arithmetic.
- Demonstrated recovery after invalid, overlong, and timed-out input.
- Explained timeout, overlong recovery, and ISR/foreground separation without
  source lookup.

These are assisted learning facts and artifact evidence, not independent
competency evidence.

### 5. AI Usage

Highest AI level used: AI-3

What AI helped with: executor-prepared starter/repository infrastructure,
visible host tests, theory and mental-model guidance, graded hints, post-attempt
review, timeout debugging guidance, and closure/evidence administration.

Files/functions materially assisted: W03D04 starter infrastructure, learning
review/debug after learner attempts, submission, and closure records.

Competencies contaminated: W03D04 cannot be used as independent competency
evidence.

Independent retest required: NO special retest created by this normal learning
day; no AI-0 gate occurred and no competency result is awarded.

### 6. Artifact Result

Files changed: learner-owned `uart_parser.c`, W03D04 TODO/submission, and the
allowlisted daily/AI/current-state closure records.

Host compile command: `gcc -std=c17 -Wall -Wextra -Wpedantic -Werror firmware/stm32/w03d04-uart-parser-lab/uart_parser.c tests/host/test_w03d04_uart_parser.c -Ifirmware/stm32/w03d04-uart-parser-lab -o tests/host/test_w03d04_uart_parser.exe`.

Host result: PASS / exit 0; `SUMMARY: 16 tests, 0 failed`.

Build command: `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`
from `firmware/stm32/w03d04-uart-parser-lab`.

Build result: PASS / exit 0; `text=1720`, `data=0`, `bss=1592`, `dec=3312`,
`hex=cf0`; only inherited non-blocking `nosys` warnings for `_close`, `_lseek`,
`_read`, and `_write`.

### 7. Evidence

Commit: `SELF — containing closure commit`

Logs: executor-reproduced strict host output showed all W03D04-T01 through
W03D04-T16 PASS and `SUMMARY: 16 tests, 0 failed`.

Captures: NONE.

Reports: `learning/week-03/day-04/SUBMIT_W03_D04.md`

Video/demo: NONE.

Hardware parser observations: NOT PERFORMED / NOT RECORDED; none are inferred.

### 8. Measurements

Expected: every parser call performs bounded work; a complete valid line emits
the matching command event; invalid and overlong lines cannot corrupt parser
state; timeout and newline reset the active line so a later command can recover.

Observed: 16/16 visible host cases passed, including exact-length bounds,
guarded overlong input, partial-line timeout, `uint32_t` tick wrap, and recovery
after invalid, overlong, and timed-out input.

Relevant values: maximum line length `32` bytes; valid `rate` range `1..10000`.
No physical UART timing or command-action behavior was measured.

### 9. Understanding Check

What I demonstrated/explained during the assisted learning session: the partial
line and timeout transition, why unsigned elapsed subtraction survives tick
wrap, why overlong suffix bytes must be discarded until newline, and why ISR RX
buffering should remain separate from foreground parsing/action handling.

Self-check result: PASS as learning evidence. What I still cannot claim from
this day: independent competency.

### 10. Defects / Failed Tests

Defect IDs or test IDs: NONE unresolved. The expected inherited `nosys` linker
warnings are non-blocking.

Root cause known?: N/A.

Current hypothesis: no unresolved artifact defect supported by the verified
source audit, host suite, and clean build.

### 11. Carry-over

Exactly one mandatory carry-over if needed: NONE.

Closure criteria: MET.

Recovery: NOT ACTIVE.

Known limitation: this closure proves the hardware-independent parser core. It
does not claim physical UART command dispatch or LED/status/rate action behavior.

### 12. Next Action

BOOT W03D05 — open the authoritative W03D05 roadmap day card before defining the
next Day Contract.

---

## 2026-08-27 — Week 03 / Day 05

### 1. Planned Outcome

Implement a Python serial logger that timestamps newline-terminated UART
records, persists authoritative raw bytes plus a readable view, and use it with
the physical board to create an attributable sample log.

Roadmap card date: `2026-08-28`. Execution intentionally started early within
Week 3 on calendar date `2026-08-27`.

### 2. Actual Status

GREEN — W03D05 CLOSED / ARTIFACT_PASS.

The learner-owned logger ran with the NUCLEO-F446RE on COM4 at 115200 baud and
persisted one attributable `LOGGER_TEST\r\n` record. Executor syntax, interface,
contract-regression, evidence, and firmware-restoration checks passed. This
normal learning day creates no new competency result.

### 3. Focused Time

Available: 5h — learner supplied

Planned: 5h — learner supplied

Actual: 3h — learner supplied

Planned-vs-actual variance: -2h. Hours are planning/history only. The lower
actual time creates no schedule debt and is not a Recovery trigger. Health
impact: NOT RECORDED.

### 4. Independent Work

- Implemented the required argparse interface, timestamp generation, persisted
  hex/readable record format, serial receive loop, and error/shutdown paths.
- Selected PC/logger UTC observation time with ISO 8601 microsecond precision.
- Defined complete records as newline-terminated and bounded pending/record
  storage with `MAX_PENDING_BYTES = 4096`.
- Used COM4 at 115200, 8N1 with the physical board and created the required
  sample log.
- Explained timeout-as-idle behavior and why HEX_RAW is authoritative for bytes
  delivered to software while DECODED_VIEW is secondary.
- Temporarily used deterministic `LOGGER_TEST\r\n` firmware output for evidence,
  then restored W03D04 to its original UART echo behavior.

These are assisted learning facts and artifact evidence, not independent
competency evidence.

### 5. AI Usage

Highest AI level used: AI-3

What AI helped with: executor-prepared starter/repository infrastructure plus
Project Chat theory, review, and debugging after meaningful learner attempts;
closure/evidence administration and additional post-attempt bounded validation.

Files/functions materially assisted: W03D05 starter infrastructure, learning
review/debug after learner attempts, submission, and closure records.

Competencies contaminated: W03D05 cannot be used as independent competency
evidence.

Independent retest required: NO special retest created by this normal learning
day; no AI-0 gate occurred and no competency result is awarded.

### 6. Artifact Result

Files changed: learner-owned `tools/serial_logger.py`, W03D05 TODO/submission,
physical `sample_uart.log`, and the allowlisted daily/AI/current-state closure
records.

Syntax command: `python -m py_compile .\tools\serial_logger.py`.

Syntax result: PASS / exit 0 after an executor rerun with permission to create
the ignored bytecode cache.

Interface command: `python -B .\tools\serial_logger.py --help`.

Interface result: PASS / exit 0.

Bounded executor regression result: PASS / exit 0; `SUMMARY: 5 tests, 0 failed`
covering timestamp/persistence, split and multiple records, Ctrl+C, oversized
complete record, oversized pending fragment, and SerialException behavior.

### 7. Evidence

Commit: `SELF — containing closure commit`

Logs: `learning/week-03/day-05/sample_uart.log` — 76 bytes, one record.

Captures: NONE.

Reports: `learning/week-03/day-05/SUBMIT_W03_D05.md`

Video/demo: NONE.

Physical invocation: `python -B .\tools\serial_logger.py --port COM4 --baud
115200 --output .\learning\week-03\day-05\sample_uart.log`.

### 8. Measurements

Expected: the deterministic board payload `LOGGER_TEST\r\n` is delivered as one
complete newline-terminated record and persisted with a UTC PC-observation
timestamp, authoritative hex, and a one-line decoded/escaped view.

Observed: `[2026-08-27T10:51:49.572892Z]
4c4f474745525f544553540d0a | LOGGER_TEST\r\n`.

Relevant values: pyserial 3.5; Python 3.12.0; COM4; 115200 baud; 8N1;
timeout 1.0 s; read size 128 bytes; `MAX_PENDING_BYTES = 4096`.

### 9. Understanding Check

What I demonstrated/explained during the assisted learning session: timeout
1.0 s is bounded blocking and an empty read means idle/continue rather than
disconnect; HEX_RAW preserves bytes delivered to software without text-decoding
loss, while DECODED_VIEW is transformed/escaped and secondary.

Precision boundary: HEX_RAW does not prove electrical bit-level integrity on
the wire. What I still cannot claim from this day: independent competency.

Self-check result: PASS as learning evidence.

### 10. Defects / Failed Tests

Defect IDs or test IDs: NONE unresolved. One trailing-whitespace line and the
missing final newline in `tools/serial_logger.py` were corrected mechanically
without changing tokens or behavior. Empty untracked `test_log.txt` scratch was
removed explicitly; it contained zero bytes and no evidence.

Root cause known?: N/A for the final artifact.

Current hypothesis: no unresolved artifact defect supported by the physical
sample, source audit, and bounded executor regressions.

### 11. Carry-over

Exactly one mandatory carry-over if needed: NONE.

Closure criteria: MET.

Recovery: NOT ACTIVE.

Known limitations: timestamp is PC observation time, not board/wire timing;
only complete newline-terminated records are persisted; a short pending
fragment is not persisted on shutdown; fixed 4096-byte bound; exact flow-control
and connector/bridge details were not recorded.

### 12. Next Action

BOOT W03D06 — open the authoritative W03D06 roadmap day card before defining the
controlled fault-injection/debug Day Contract.

---

## 2026-08-29 — Week 03 / Day 06

### 1. Planned Outcome

Intentionally reproduce one UART fault, preserve expected versus actual,
measure before fixing, apply the minimum fix, prove regression/recovery, and
complete Debug Report #1 with remaining limitations visible.

### 2. Actual Status

GREEN — W03D06 CLOSED / ARTIFACT_PASS.

The learner completed a controlled RX/ring-buffer overflow debug story on the
NUCLEO-F446RE. The final normal firmware no longer contains the artificial
foreground slowdown. This normal learning day creates no new competency result.

### 3. Focused Time

Available: 5h — learner supplied

Planned: 5h — learner supplied

Actual: 3h — learner supplied

Planned-vs-actual variance: -2h. Hours are planning/history only. Completing
the required evidence in 3h does not downgrade the result, create schedule
debt, or activate Recovery. Health impact: NOT RECORDED.

### 4. Independent Work

- Selected RX/ring-buffer overflow with fixed capacity 8 and DROP_NEWEST.
- Supplied expected behavior, known facts, unknowns, H1, reproduction design,
  and measurement plan before the physical fault run.
- Deliberately slowed the foreground consumer while leaving the USART2 ISR
  unslowed.
- Reproduced `ABCDEFGHIJKLMNOPQRST -> ABCDEFGH` and measured
  `overflow_count = 12`.
- Verified post-overload recovery with `XYZ -> XYZ`; the counter remained 12.
- Removed the artificial slowdown as the minimum fix and verified the full
  20-byte regression with `overflow_count = 0`.
- Independently explained reproduce, measure-before-fix, and recovery checks.

These are assisted learning facts and artifact evidence, not independent
competency evidence.

### 5. AI Usage

Highest AI level used: AI-3

What AI helped with: executor-prepared neutral W03D06 TODO/debug-report
infrastructure and baseline validation; Project Chat pre-check, post-attempt
evidence review, report normalization, and closure administration. AI suggested
the concrete temporary foreground busy-delay mechanism after the learner had
already supplied the pre-experiment reasoning and measurement plan.

Files/functions materially assisted: W03D06 starter/report infrastructure,
learning review after learner measurements, and closure records.

Core ring-buffer algorithm patch supplied: NO.

Competencies contaminated: W03D06 cannot be used as independent competency
evidence.

Independent retest required: NO special retest created by this normal learning
day; no AI-0 gate occurred and no competency result is awarded.

### 6. Artifact Result

Files changed: W03D06 TODO/debug report and the allowlisted daily/AI/current-state
closure records. The only final-firmware cleanup was restoration of the missing
newline at the end of W03D03 `main.c`; no semantic token or behavior changed.

Host compile result: PASS / exit 0.

Host test result: PASS / exit 0; `SUMMARY: 11 tests, 0 failed`.

STM32 clean build result: PASS / exit 0; `text=1720`, `data=0`, `bss=1592`,
`dec=3312`, `hex=cf0`; only inherited non-blocking `nosys` warnings for
`_close`, `_lseek`, `_read`, and `_write`.

### 7. Evidence

Commit: `SELF — containing closure commit`

Report: `learning/week-03/day-06/DEBUG_REPORT_W03_D06.md`

Raw terminal/test log: NOT STORED — learner supplied the exact Serial Monitor
observations in Project Chat.

Measurement/recovery/regression standalone files: NOT STORED. Exact values are
preserved in Debug Report #1.

### 8. Measurements

Fault input/output: `ABCDEFGHIJKLMNOPQRST -> ABCDEFGH`.

Fault software counter: `overflow_count = 12`.

Recovery: `XYZ -> XYZ`; `overflow_count` remained 12.

Regression after removing the artificial foreground slowdown:
`ABCDEFGHIJKLMNOPQRST -> ABCDEFGHIJKLMNOPQRST`; `overflow_count = 0`.

UART hardware ORE history: NOT MEASURED sufficiently. No claim is made that ORE
was absent throughout the fault run.

### 9. Understanding Check

The learner independently explained the first three actions for an unknown UART
overflow: reproduce deterministically and record expected/actual; measure at the
hardware/software boundary before fixing; then stop the overload and verify
post-overload recovery/liveness.

Self-check result: PASS as learning evidence. What this day cannot claim:
independent competency.

### 10. Defects / Failed Tests

Defect IDs or test IDs: NONE unresolved in the tested case.

Root cause: intentional producer/consumer rate imbalance caused by the temporary
foreground busy delay.

Remaining limitations: fixed 8-byte capacity; DROP_NEWEST under sustained
overload; foreground critical section around pop; polling TX; no retained
`count/head/tail/storage` snapshot; insufficient ORE-history measurement; and
regression limited to the tested 20-byte payload.

### 11. Carry-over

Exactly one mandatory carry-over if needed: NONE.

Closure criteria: MET.

Recovery: NOT ACTIVE.

### 12. Next Action

BOOT W03D07 — open the authoritative W03D07 competency-gate day card and
establish the fresh AI-0 contract before any scored work.

---

## 2026-08-31 — Week 03 / Day 07

### 1. Planned Outcome

Complete the independent 65-minute Week 3 UART IRQ / ring-buffer /
non-blocking-parser competency gate under AI-0, preserve the raw attempt before
review, resolve the historical MASTER CHECK findings, and close Week 3 without
activating Week 4 learner work.

### 2. Actual Status

GREEN — W03D07 CLOSED.

Gate result: `87/100 PASS / AI-0 CLEAN`.

Competency result: `W03-C-UART-FOUND — COMPETENCY_PASS`.

Week 3 result: `CONDITIONAL PASS / CLOSED` with exactly one P1 evidence
carry-over. W04D01 learner work remains `NOT STARTED`.

### 3. Focused Time

Available: NOT RECORDED.

Planned: assessment time limit `65 minutes`; this is the gate limit, not a
learner-supplied focused-time estimate.

Actual: NOT RECORDED — learner did not supply exact value; do not infer from
timestamps.

Health/load: `2 — sustainable — learner supplied`; learner statement:
`sức khoẻ rất ổn`. No unsafe load or health blocker is reported.

### 4. Independent Work

- Derived baud/divisor/error from the supplied clock and proposed bit-width and
  frame-structure measurements.
- Reasoned about empty/full ring-buffer states, traced five producer arrivals,
  and preserved an explicit `DROP_NEWEST` overflow policy.
- Rejected blocking/long-running ISR behavior and identified the shared-count
  read-modify-write race.
- Submitted a fresh bounded parser with discard-until-newline recovery and a
  concrete overlong-to-valid trace.
- Distinguished ORE, software ring overflow, and shared-state corruption using
  separate measurements.
- Defended DMA and stated when larger buffer or shorter ISR latency is the
  smaller relevant change.

The verbatim scored answers are preserved in
`learning/week-03/day-07/RAW_COMPETENCY_SUBMISSION_W03D07.md`.

### 5. AI Usage

Highest AI level used: AI-3 — post-close review and evidence/control-plane
administration only; scored phase remained AI-0.

Scored assistance: NONE.

Allowed during gate: paper/pen and ordinary calculator.

Prohibited during gate: AI, Copilot, web/search, old answers/solutions, notes,
and another person.

Learner integrity declaration after close: `CLEAN ko dùng bất kì cái gì ngoài
máy tình cầm tay`.

Normalized metadata only: `CLEAN — no AI/search/notes/other person; ordinary
calculator only.`

### 6. Artifact Result

This day creates assessment/evidence closure records only; it does not invent a
new firmware artifact.

Fresh technical validation:
- ring buffer: `11 tests, 0 failed`;
- parser: `16 tests, 0 failed`;
- serial logger syntax/help: `PASS / exit 0`;
- W03D06 STM32 clean build: `PASS / exit 0`, `text=1720`, `data=0`,
  `bss=1592`, `dec=3312`, `hex=cf0`;
- production `busy_delay`: absent;
- learner `main.c`: byte-identical to prep baseline.

Learner implementation changed by this transaction: NO.

### 7. Evidence

Commit: `SELF — containing closure commit`

Raw scored evidence:
`learning/week-03/day-07/RAW_COMPETENCY_SUBMISSION_W03D07.md`

Assessment:
`learning/week-03/day-07/ASSESSMENT_RESULT_W03D07.md`

Post-gate review:
`learning/week-03/day-07/POST_GATE_REVIEW_W03D07.md`

Submission:
`learning/week-03/day-07/SUBMIT_W03_D07.md`

MASTER CHECK disposition:
`learning/week-03/MASTER_CHECK_DISPOSITION_W03.md`

Weekly scorecard:
`roadmap-control/weekly-scorecards/week-03.md`

### 8. Measurements

Rubric:
- baud/clock reasoning: `20/20`;
- ISR + ring buffer: `17/20`;
- fresh parser: `19/25`;
- fault diagnosis: `19/20`;
- transfer/trade-off: `12/15`;
- total: `87/100 PASS`.

Mandatory conditions:
- no blocking ISR design: PASS;
- explicit overflow policy: PASS;
- no serious bounds/lifetime violation sufficient for automatic failure: PASS.

### 9. Understanding Check

Independent gate result: PASS. The learner demonstrated the required Week 3
competency scope under AI-0. Post-close review findings are precision/design
feedback only and do not replace or rewrite the scored answers.

### 10. Defects / Failed Tests

Gate-blocking defect: NONE.

Non-gate-blocking post-close findings:
- `volatile` is not a synchronization primitive or general memory barrier;
- submitted parser mishandles the exact 15-data-character-plus-CRLF boundary;
- shorter ISR/interrupt latency is the smaller first remediation for the
  measured ORE symptom before introducing DMA complexity.

No learner source is modified for these findings in this closure transaction.

### 11. Carry-over

Exactly one mandatory carry-over:
Capture correct-baud UART wire timing / logic-analyzer evidence.

Deadline: `2026-09-06 — CP-02 / Foundation MCU gate`.

Closure criterion: a genuine logic-analyzer capture or equivalent direct
measurement demonstrates the configured UART baud/timing sufficiently to close
the roadmap evidence item. Do not claim independent measurement-procedure
design unless separately demonstrated.

Classification: `P1 EVIDENCE CARRY-OVER — NON-COMPETENCY-BLOCKING`.

Recovery: NOT ACTIVE.

Week 4 eligibility: YES.

### 12. Next Action

BOOT W04D01 — timer clock / PSC / ARR / CCR Day Contract with learner Available
Focused Time = 6h.

---

## 2026-09-03 — Week 04 / Day 01

### 1. Planned Outcome

Reason from the actual timer clock tree, derive PSC and ARR for a 1 kHz TIM2
time-base update interrupt, implement `timer2_init_1khz()` and `TIM2_IRQHandler()`
at the register level, verify periodic PA5 GPIO toggling on hardware with a logic
analyzer, document expected versus actual timing, and explain the difference
between counter tick and update event without advancing into W04D02 PWM scope.

### 2. Actual Status

GREEN — W04D01 CLOSED / ARTIFACT_PASS.

Technical implementation, clean build, hardware logic analyzer evidence, and
documentation completed. W04D01 is a learning day and creates no new independent
competency award.

### 3. Focused Time

Available: 6h — learner supplied at START DAY.

Planned: 6h — learner supplied.

Actual: NOT RECORDED — learner did not supply exact actual focused-time total.

Health/load: 2 — sustainable; no physical or cognitive blocker reported.

### 4. Independent Work

What I personally implemented, reasoned about, measured, or explained:

- Derived the core timer formulas: $f_{\text{counter}} = \text{TIMxCLK} / (\text{PSC} + 1)$
  and $f_{\text{update}} = f_{\text{counter}} / (\text{ARR} + 1)$.
- Performed initial calculation drills for hypothetical 90 MHz APB timer clock
  (PSC=89, ARR=999 -> 1 kHz; PSC=89, ARR=99 -> 10 kHz; PSC=89, ARR=9999 -> 100 Hz;
  and compared PWM resolution between ARR=999 and ARR=99).
- Reasoned that toggling a GPIO once per 1 kHz update event creates a 500 Hz square
  wave with a 2 ms full period.
- Designed and wrote the complete register sequence for `timer2_init_1khz()` and
  `TIM2_IRQHandler()` in `timer_timebase.c`.
- Corrected the UIF clear sequence to direct `rc_w0` write (`TIM2->SR = ~TIM_SR_UIF`)
  to avoid RMW flag clearing races.
- Flashed physical NUCLEO-F446RE, connected USB logic analyzer, and discovered
  the initial ~88.9 Hz (~11.25 ms period) timing mismatch.
- Investigated the project clock source, confirmed `SystemInit()` ran on minimal
  16 MHz default HSI without PLL configuration (`SystemCoreClock = 16000000U`),
  identified the wrong input-clock assumption as root cause, and kept the 16 MHz
  project baseline unchanged.
- Recalculated PSC for actual 16 MHz clock: PSC 89 -> 15 (with ARR=999), rebuilt,
  reflashed, and captured final logic analyzer trace showing ~500 Hz / ~2 ms square wave.

### 5. AI Usage

Highest AI level used: AI-3 — post-attempt code review, debug assistance, and
closure administration only. Core learning and implementation were learner-owned.

What AI contributed:
- Theory explanation and APB clock formula verification.
- Review of learner-written register flow after meaningful attempt.
- Identified the RMW hazard on `TIM2->SR` and recommended direct `rc_w0` clearing.
- Suggested investigating actual `SystemCoreClock` after the first measurement mismatch.
- Documentation formatting and repository closure administration via executor.

Files/functions materially assisted:
- `firmware/stm32/w04d01-timer-timebase/timer_timebase.c` post-attempt review only.
- `learning/week-04/day-01/**` documentation templates and control bookkeeping.

Core implementation code provided by AI:
NO. The core TIM2 initialization and ISR were authored by the learner before review.

Gate answer revealed:
NO ACTIVE GATE — W04D01 was a normal learning day, not an AI-0 competency gate.

Competencies contaminated:
NONE. W04D01 is normal assisted learning and valid artifact evidence; it does not
award an independent competency result. `W03-C-UART-FOUND — COMPETENCY_PASS` remains
valid and unpolluted.

Independent retest required:
NO special retest created by this normal learning day.

### 6. Artifact Result

Files changed:
- `firmware/stm32/w04d01-timer-timebase/timer_timebase.c`
- `learning/week-04/day-01/Screenshot_1.png`
- `learning/week-04/day-01/timer-calculation-note.md`
- `learning/week-04/day-01/SUBMIT_W04D01.md`
- `learning/week-04/day-01/TODO_W04D01_TIMER_CLOCK.md`
- `roadmap-control/daily-log.md`
- `roadmap-control/ai-usage-log.md`
- `roadmap-control/current-state.md`

Clean build command:
`powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean` from `firmware/stm32/w04d01-timer-timebase/`

Clean build result:
PASS / exit 0; `text=1188`, `data=0`, `bss=1568`, `dec=2756`, `hex=ac4`; only inherited
non-blocking `nosys` linker warnings for `_close`, `_lseek`, `_read`, and `_write`.

### 7. Evidence

Commit: `SELF — containing closure commit`

Capture: `learning/week-04/day-01/Screenshot_1.png` — PulseView digital capture on D0
(PA5 / LD2) showing stable square wave with cursors at 2 ms, 3 ms.

Calculation note: `learning/week-04/day-01/timer-calculation-note.md`

Submission: `learning/week-04/day-01/SUBMIT_W04D01.md`

Checklist: `learning/week-04/day-01/TODO_W04D01_TIMER_CLOCK.md`

### 8. Measurements

Negative / initial measurement:
- Assumed TIM2CLK = 90 MHz, PSC = 89, ARR = 999.
- Expected under assumption: $f_{\text{gpio}} = 500\text{ Hz}$, $T_{\text{gpio}} = 2\text{ ms}$.
- Observed on logic analyzer: $f_{\text{gpio}} \approx 88.9\text{ Hz}$, $T_{\text{gpio}} \approx 11.25\text{ ms}$.
- Inference: Clock was $16\text{ MHz}$, yielding $f_{\text{counter}} = 16\text{ MHz} / 90 \approx 177.78\text{ kHz}$,
  $f_{\text{update}} \approx 177.78\text{ Hz}$, $f_{\text{gpio}} \approx 88.89\text{ Hz}$, $T_{\text{gpio}} \approx 11.25\text{ ms}$.

Final corrected measurement:
- Actual TIM2CLK = 16 MHz, PSC = 15, ARR = 999.
- Expected: $f_{\text{counter}} = 1\text{ MHz}$, $f_{\text{update}} = 1\text{ kHz}$, $f_{\text{gpio}} = 500\text{ Hz}$,
  $T_{\text{gpio}} = 2\text{ ms}$, HIGH $\approx 1\text{ ms}$, LOW $\approx 1\text{ ms}$, duty $\approx 50\%$.
- Observed on PulseView capture (`Screenshot_1.png`):
  - Period: approximately 2 ms
  - Frequency: approximately 500 Hz
  - HIGH duration: approximately 1 ms
  - LOW duration: approximately 1 ms
  - Duty cycle: approximately 50%

### 9. Understanding Check

The learner independently explained:
- Why $f_{\text{counter}} = \text{TIMxCLK} / (\text{PSC} + 1)$ and $f_{\text{update}} = f_{\text{counter}} / (\text{ARR} + 1)$.
- Why toggling GPIO once per 1 kHz update produces a 500 Hz square wave (two toggles per full cycle).
- How CCR compares against CNT to establish duty cycle in future PWM work, and why ARR=999 provides better resolution than ARR=99.
- Why direct write (`TIM2->SR = ~TIM_SR_UIF`) is required for `rc_w0` interrupt flags instead of RMW.
- How the initial measurement mismatch was diagnosed to a clock tree assumption rather than a calculation error.

Self-check result: PASS as Day-1 learning evidence. What this day cannot claim:
independent competency.

### 10. Defects / Failed Tests

Defect/Test IDs: NONE unresolved.

Root cause: Initial timing mismatch caused by unverified assumption of 90 MHz APB
timer clock. Minimal project ran at default 16 MHz HSI.

Resolution: Recalculated PSC for 16 MHz clock (15 instead of 89) while keeping ARR=999.
Verified timing on hardware.

Remaining limitations:
- Project clock runs at minimal default 16 MHz without PLL configuration.
- PA5 GPIO toggling is handled in software ISR, subject to interrupt latency and jitter.

### 11. Carry-over

From Week 3: Exactly one P1 carry-over remains — capture correct-baud UART wire
timing / logic-analyzer evidence by 2026-09-06.
From W04D01: NONE.

Closure criteria: MET.

Recovery: NOT ACTIVE.

Week 4 execution: W04D01 CLOSED; W04D02 NOT STARTED.

### 12. Next Action

BOOT W04D02 — PWM implementation using timer capture/compare/PWM channel, starting
from the now-verified timer-clock mental model.

---

## 2026-09-04 — Week 04 / Day 02

### 1. Planned Outcome

Implement hardware PWM output on TIM2_CH1 (PA5 / onboard LD2) at 1 kHz default
frequency and 50% duty cycle. Integrate frequency (10 Hz .. 100 kHz) and duty
cycle (0% .. 100%) runtime adjustment into the existing UART shell (`pwm freq`,
`pwm duty`, `pwm status`). Verify PWM waveform physically via logic analyzer, test
boundary/invalid cases, and resolve any integration bugs.

### 2. Actual Status

GREEN / CLOSED / ARTIFACT_PASS

### 3. Focused Time

Planned: Work through W04D02 stop condition before 22:30
Actual: NOT RECORDED — learner did not supply exact numeric hours; do not infer from timestamps

### 4. Independent Work

What I personally implemented, reasoned about, measured, or explained:

- Selected and verified hardware pins and clocking from official STM32 documentation:
  TIM2_CH1 on PA5 (AF1), TIM2 on APB1, 16 MHz HSI baseline, APB1 prescaler /1, TIM2CLK = 16 MHz.
- Derived timer register settings for 1 kHz / 50% PWM:
  counter tick rate = 1 MHz (PSC = 15), period count = 1000 (ARR = 999), CCR1 = 500.
- Implemented full register-level PWM driver in `firmware/stm32/w04d02-pwm-uart-shell/pwm.c`:
  RCC clock gating for GPIOA and TIM2, PA5 AF1 configuration, TIM2 timebase setup,
  PWM Mode 1 (`OC1M = 110`), OC1 preload enable (`OC1PE = 1`), auto-reload preload
  enable (`ARPE = 1`), active-high polarity, and update generation (`UG`).
- Implemented runtime API:
  `pwm_set_frequency()` with ratio-preserving CCR recalculation to minimize duty quantization loss;
  `pwm_set_duty_cycle()` with 64-bit intermediate arithmetic to prevent 32-bit multiplication overflow;
  `pwm_get_frequency()` and `pwm_get_duty_cycle()`.
- Extended UART shell in `main.c` with commands:
  `pwm freq <hz>`, `pwm duty <percent>`, `pwm status`.
- Integrated boundary checks and robust unsigned decimal parsing with uint32 overflow protection.
- Performed physical hardware testing on NUCLEO-F446RE with 8-channel logic analyzer via PulseView:
  verified default 1 kHz / 50%, duty transitions (25%, 75%), frequency transitions (500 Hz, 2000 Hz),
  and final state (500 Hz / 25%).
- Tested negative/error cases (`pwm duty 101`, `pwm freq 0`, `pwm freq 100001`, `pwm duty abc`, `pwm freq 42949672960`, malformed commands).
- Diagnosed and resolved overlong-line RX/TX integration bug during hardware testing.

### 5. AI Usage

Highest AI level used: AI-3

What AI helped with:
- Initial PWM mental model and pre-check: AI-1 / AI-2.
- Learner independently selected TIM2_CH1 / PA5 / AF1 with official-source verification.
- Learner independently calculated: TIM2CLK = 16 MHz, PSC = 15, ARR = 999, CCR1 = 500.
- Learner wrote the first working `pwm_init()` attempt before AI-3 review.
- Learner produced physical 1 kHz / 50% waveform before code-level AI review.
- AI-3 was then used for review/hardening/debugging:
  preload/shadow semantics,
  frequency change duty ratio preservation,
  uint64_t overflow-safe arithmetic for CCR calculation,
  UART shell robustness and boundary parsing,
  diagnosis of overlong-line RX ring buffer overflow / blocking TX interaction.
- Closure administration and control record updates via executor.

Files/functions materially assisted:
- `firmware/stm32/w04d02-pwm-uart-shell/pwm.c` (review/hardening of preload semantics and uint64_t arithmetic)
- `firmware/stm32/w04d02-pwm-uart-shell/main.c` (diagnosis of overlong-line newline-drain logic)
- `learning/week-04/day-02/**` (documentation and submission records)

Competencies contaminated:
- NONE newly awarded. W04D02 is normal assisted learning and valid artifact evidence; it is NOT independent competency evidence.

Independent retest required:
- NOT REQUIRED. No competency PASS claimed from this day.

### 6. Artifact Result

Files changed:
- `firmware/stm32/w04d02-pwm-uart-shell/pwm.c`
- `firmware/stm32/w04d02-pwm-uart-shell/main.c`
- `learning/week-04/day-02/Screenshot_1.png`
- `learning/week-04/day-02/Screenshot_2.png`
- `learning/week-04/day-02/Screenshot_3.png`
- `learning/week-04/day-02/TODO_W04D02_PWM.md`
- `learning/week-04/day-02/SUBMIT_W04D02.md`
- `roadmap-control/current-state.md`
- `roadmap-control/daily-log.md`
- `roadmap-control/ai-usage-log.md`

Clean build command:
`powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean` from `firmware/stm32/w04d02-pwm-uart-shell/`

Clean build result:
PASS / exit 0; `text=4876`, `data=0`, `bss=1592`, `dec=6468`, `hex=1944`; only inherited
non-blocking `nosys` linker warnings for `_close`, `_lseek`, `_read`, and `_write`.

### 7. Evidence

Commit: `SELF — containing closure commit`

Captures:
- `learning/week-04/day-02/Screenshot_1.png` — PulseView digital capture showing default approximately 1 kHz / 50% PWM waveform (period ~1 ms, HIGH ~0.5 ms, LOW ~0.5 ms)
- `learning/week-04/day-02/Screenshot_2.png` — PulseView digital capture showing UART-controlled approximately 500 Hz / 25% PWM waveform (period ~2 ms, HIGH ~0.5 ms, LOW ~1.5 ms)
- `learning/week-04/day-02/Screenshot_3.png` — VS Code Serial Monitor terminal log showing successful command execution, status queries, negative/error validation, and overlong line recovery

Submission: `learning/week-04/day-02/SUBMIT_W04D02.md`

Checklist: `learning/week-04/day-02/TODO_W04D02_PWM.md`

### 8. Measurements

Physical measurements (logic analyzer PulseView capture):
- TIM2 clock baseline: 16 MHz HSI, APB1 prescaler /1, TIM2CLK = 16 MHz, PSC = 15 -> 1 MHz tick rate.
- Pin / Alternate function: PA5 / TIM2_CH1 / AF1 (onboard LD2).
- Default startup target: 1 kHz / 50% duty:
  - Period: approximately 1 ms
  - Frequency: approximately 1 kHz
  - HIGH time: approximately 0.5 ms
  - LOW time: approximately 0.5 ms
  - Duty cycle: approximately 50%
- Dynamic runtime adjustments tested and observed:
  - `pwm duty 25` -> approximately 1 kHz / 25% (period ~1 ms, HIGH ~0.25 ms)
  - `pwm duty 75` -> approximately 1 kHz / 75% (period ~1 ms, HIGH ~0.75 ms)
  - `pwm freq 500` -> approximately 500 Hz / 75% (period ~2 ms, HIGH ~1.5 ms)
  - `pwm freq 2000` -> approximately 2 kHz / 75% (period ~0.5 ms, HIGH ~0.375 ms)
- Final physical smoke state (`pwm duty 25`, `pwm freq 500`):
  - Period: approximately 2 ms
  - Frequency: approximately 500 Hz
  - HIGH time: approximately 0.5 ms
  - LOW time: approximately 1.5 ms
  - Duty cycle: approximately 25%
(Note: Visual estimations from time scale; detailed annotated cursor measurements belong to W04D03)

### 9. Understanding Check

The learner independently demonstrated and explained:
- PSC controls counter tick rate ($f_{\text{counter}} = f_{\text{timer}} / (\text{PSC} + 1)$).
- ARR defines PWM period count together with PSC ($f_{\text{PWM}} = f_{\text{timer}} / ((\text{PSC} + 1) \times (\text{ARR} + 1))$).
- CCR controls the compare threshold and high-time in PWM Mode 1.
- For upcounting PWM Mode 1 active-high: output is active while $\text{CNT} < \text{CCR}$ and inactive while $\text{CNT} \ge \text{CCR}$.
- With fixed PSC and ARR, changing CCR adjusts duty cycle without affecting frequency.
- Concrete arithmetic: ARR 999 / CCR 500 -> ~50%. To double frequency ARR-only: ARR 999 -> 499, CCR 500 -> 250 to preserve ~50%.
- Preload and shadow register mental model: software writes to preload registers while active/shadow registers continue generating the current PWM cycle; the update event (UEV) synchronously transfers new values at period rollover, preventing runt pulses or corrupted waveforms.
- Recognized that modifying ARR without adjusting CCR alters the duty ratio; improved frequency setter to preserve the direct $\text{CCR}/(\text{ARR}+1)$ ratio to minimize quantization loss.

Self-check result: PASS as Day-2 learning evidence. What this day cannot claim: independent competency.

### 10. Defects / Failed Tests

Defect/Test IDs: NONE unresolved.

Resolved bug during session: Overlong line handling deadlock/drop bug.
- Root cause: The shell detected line overflow and immediately transmitted "ERR: Line too long" via blocking UART TX before the line was fully drained. Incoming characters arrived via IRQ into an 8-byte DROP_NEWEST ring buffer. While the CPU was blocked transmitting, incoming bytes overflowed the ring buffer and the terminating newline was dropped. `discarding_overlong` remained stuck true, causing the subsequent valid command to be consumed only to clear the discard state.
- Resolution: Upon detecting line overflow, set `discarding_overlong = true` without blocking TX; continue draining all incoming line characters until newline is received; clear discard state; only then transmit "ERR: Line too long".
- Retest: Overlong line generated "ERR: Line too long", immediately followed by `pwm status` which executed successfully with "PWM Freq: 1000 Hz, Duty: 50%". PASS.

### 11. Carry-over

From Week 3: Exactly one P1 carry-over remains — capture correct-baud UART wire
timing / logic-analyzer evidence by 2026-09-06 (today's PWM capture does not close
this UART timing carry-over).
From W04D02: NONE.

Closure criteria: MET.

Recovery: ACTIVE EXECUTION RECOVERY — execution is behind canonical Week 4 calendar;
stated recovery plan: 2026-09-05 W04D03 + W04D04; 2026-09-06 W04D05 + W04D06;
2026-09-07 Foundation MCU Gate; canonical dates unchanged.

Week 4 execution: W04D02 CLOSED; W04D03 NOT STARTED.

### 12. Next Action

BOOT W04D03 — measure PWM frequency and duty against calculations using the logic
analyzer and create the annotated PWM capture.


---

## 2026-09-05 — Week 04 / Day 03

### 1. Planned Outcome

Measure PWM frequency/duty with the logic analyzer against learner calculations,
characterize discrepancies and retain genuine annotated PWM capture evidence.
Canonical W04D03 date remains 2026-09-02; execution completed 2026-09-05.

### 2. Actual Status

GREEN / CLOSED / ARTIFACT_PASS

Normal assisted learning only; W04D04 NOT STARTED; no active competency gate.

### 3. Focused Time

Available: 6h — learner supplied at BOOT
Planned: maximum 6h; stop earlier when authoritative W04D03 stop condition is satisfied
Actual: ~2h30m — learner estimate

External technical help outside Project Chat / Cowork: NO.
No time was inferred from timestamps, screenshots or Git history.

### 4. Independent Work

Learner independently derived Case A (nominal TIM2CLK=16 MHz, PSC=15, ARR=999,
CCR1=250, tick=1 us, period=1000 us, frequency=1000 Hz, HIGH=250 us, LOW=750 us,
duty=25%) before measurement. Learner acquired the 24 MHz PulseView capture,
placed period/HIGH cursors, performed ST-Link/GDB runtime readback and physically
cross-checked 500 Hz. Learner reasoned that common scaling should not immediately
be labeled a firmware defect. No firmware source change was needed.

### 5. AI Usage

Highest AI level used: AI-3
What AI helped with: AI-1/AI-2 theory/pre-check, timer mental model, calculation
questions and measurement planning before meaningful work; AI-3 calculation and
measurement review, cursor/debugger guidance, mismatch interpretation, runtime
readback review, evidence selection and closure administration after attempt.
Files/functions materially assisted: W04D03 worksheet, submission, TODO and
daily/AI/current-state records; no firmware function modified.
Competencies contaminated: NONE newly awarded; W04D03 is assisted artifact evidence.
Independent retest required: NOT REQUIRED for this normal learning closure; no new competency PASS.

### 6. Artifact Result

Files changed: three W04D03 Markdown documents, four learner PNG screenshots,
and roadmap-control/current-state.md, daily-log.md, ai-usage-log.md; exact paths
listed in learning/week-04/day-03/SUBMIT_W04D03.md.
Build command: `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`
from `firmware/stm32/w04d02-pwm-uart-shell/`.
Build result: fresh PASS / exit 0; text=4876, data=0, bss=1592, dec=6468, hex=1944;
inherited non-blocking nosys warnings _close, _lseek, _read, _write only.
Test result: physical evidence verified from learner screenshots; no executor
hardware run, firmware repair or additional code test requirement.

### 7. Evidence

Commit: SELF — containing closure commit
Firmware base: a412a7909611673e3f91293449310aa2629d16c6, source unchanged.
Captures:
- learning/week-04/day-03/Screenshot_1.png — Case A period/frequency cursors.
- learning/week-04/day-03/Screenshot_2.png — Case A HIGH-time cursors.
- learning/week-04/day-03/Screenshot_3.png — runtime PSC/ARR/CCR1/CFGR readback.
- learning/week-04/day-03/Screenshot_4.png — 500 Hz period/frequency cross-check.
Reports: learning/week-04/day-03/PWM_MEASUREMENT_WORKSHEET_W04D03.md and SUBMIT_W04D03.md.
Screenshots preserve learner tool annotations without executor edits; native
acquisition file, calibrated reference and exact tool revisions are not supplied.

### 8. Measurements

Expected Case A: 1000 Hz / 25%, period 1000 us, HIGH 250 us, LOW 750 us.
Observed Case A: period approximately 991.913 us; frequency approximately
1008.153 Hz; HIGH approximately 247.917 us; derived duty approximately 25.0%.
Errors: period -0.81%, frequency +0.82%, HIGH -0.83%.
Readback: PSC=0x0000000f (15), ARR=0x000003e7 (999), CCR1=0x000000fa (250),
RCC->CFGR=0x00000000. Source SystemCoreClock=16000000U is nominal, not calibration.
Expected Case B: target 500 Hz / 25%, period 2000 us.
Observed Case B: period approximately 1984.864 us, frequency approximately
503.813 Hz; errors -0.76% period / +0.76% frequency.
Raw UI display strings are retained in the worksheet without claiming that
all displayed digits represent physical accuracy. No separate LOW measurement claimed.

### 9. Understanding Check

Session-summary evidence: learner-owned pre-measurement timer derivation and
reasoning that similar fractional timing discrepancy across both cases does not
prove a frequency-specific firmware defect. Verbatim self-check answers are not
supplied to the executor and are not reconstructed or independently scored.
Unresolved explanation: MCU and analyzer reference contributions cannot be
separated by the available evidence. This normal learning record awards no competency.

### 10. Defects / Failed Tests

Defect/Test IDs: No unresolved firmware defect demonstrated.
Root cause known?: No sole root cause established; residual common reference/time-base
discrepancy is characterized. No calibration, compensation or PSC/ARR retuning.
Current hypothesis: common time-base/reference scaling discrepancy, consistent
with approximately 0.8% faster waveform and approximately unchanged duty ratio.
HSI alone and analyzer alone are not proven causes. SystemCoreClock symbol lookup
unavailable in the final ELF context is a debugger observation, not a technical defect.

### 11. Carry-over

Task: Week 3 exactly one P1 correct-baud UART wire-timing evidence item remains OPEN,
due 2026-09-06. PWM evidence does not close the UART item.
Closure criteria: genuine UART logic-analyzer capture or equivalent direct
measurement demonstrating configured baud/timing; unchanged.
From W04D03: no new blocking carry-over; residual reference uncertainty documented.
Recovery: ACTIVE EXECUTION RECOVERY; existing plan/canonical dates unchanged.
W04D04 NOT STARTED. Latest competency remains W03-C-UART-FOUND — COMPETENCY_PASS.

### 12. Next Action

BOOT W04D04 only after Project Chat independently verifies this END DAY report;
first 5–15 minutes: verify closure and establish the W04D04 Day Contract.


---

## 2026-09-05 — Week 04 / Day 04

### 1. Planned Outcome

Learn DMA transfer direction, normal/circular mode, NDTR/count, buffer lifetime
and ownership; complete a DMA note OR a minimal transfer demo. The learner chose
and completed a bounded STM32F446RE DMA2 memory-to-memory normal-mode demo.
Canonical W04D04 date remains 2026-09-03; execution completed 2026-09-05.

### 2. Actual Status

GREEN / CLOSED / ARTIFACT_PASS

Normal assisted learning only; W04D05 NOT STARTED; no active competency gate.

### 3. Focused Time

Available: 3h30 — learner supplied
Planned: UNRECOVERABLE PROCESS VARIANCE — not persisted at BOOT; not reconstructed at closure
Actual: 2h15 — learner supplied

Health/load: UNRESOLVED — no W04D04-specific learner value was supplied; none inferred.
External technical help outside Project Chat / Cowork: NO such help reported.
No time or health/load value was inferred from timestamps, screenshots or Git history.

### 4. Independent Work

The learner completed the pre-check reasoning and made meaningful implementation
attempts before targeted review. The learner owned DMA2 register configuration,
hardware/debugger execution, success observation, the pre-execution prediction
for an intentional `MINC=0` negative case, execution of that case, interpretation
of the result, and restoration of `MINC=1` in final source.

### 5. AI Usage

Highest AI level used: AI-3
What AI helped with: Project Chat supplied theory/pre-check, then post-attempt
code review, debugger setup guidance and evidence interpretation. Cowork prepared
neutral starter infrastructure and performed closure validation/bookkeeping.
Core learner implementation provided by AI: NO.
Competencies contaminated: NONE newly awarded; W04D04 is assisted artifact evidence.
Independent retest required: NOT REQUIRED for this normal learning closure; no competency PASS awarded.

### 6. Artifact Result

Artifact: STM32F446RE DMA2 memory-to-memory normal-mode minimal hardware demo
with success and intentional negative-configuration debugger evidence.

Build command: `powershell -ExecutionPolicy Bypass -File .\build.ps1 -Clean`
from `firmware/stm32/w04d04-dma-mini-lab/`.

Build result: PASS / exit 0; text=1056, data=16, bss=1624, dec=2696, hex=a88;
only inherited non-blocking `nosys` warnings `_close`, `_lseek`, `_read`, `_write`.

Executor source mutation: purely mechanical trailing-whitespace removal from
`dma_m2m.c` lines 20, 21 and 68; no token, register sequence or behavior change.

### 7. Evidence

Commit: SELF — containing closure commit

- `learning/week-04/day-04/Screenshot_1.png` — pre-enable configuration support:
  SRAM `PAR=0x20000000`, `M0AR=0x20000054`, `NDTR=4`, `EN=0`, `PINC=1`,
  `MINC=1`, `DMDIS=1`.
- `learning/week-04/day-04/Screenshot_2.png` — success post-transfer result.
- `learning/week-04/day-04/Screenshot_3.png` — intentional `MINC=0` negative result.
- `learning/week-04/day-04/TODO_W04D04_DMA.md` and `SUBMIT_W04D04.md` —
  expected/observed, ownership, provenance and limitation records.

All three PNGs were visually verified and retained byte-for-byte. The executor
did not rerun the physical hardware test, edit screenshots or fabricate evidence.

### 8. Measurements

Success case: DMA2 M2M normal mode; SRAM source/destination; `PINC=1`, `MINC=1`,
32-bit source/destination widths; initial `NDTR=4`; FIFO enabled/direct mode
disabled. Expected and observed destination: `{10,20,30,40}`. Final observation:
`NDTR=0`, `EN=0`, `TCIF=1`, `TEIF=0`, `FEIF=0`, `timed_out=0`.

Intentional negative case: `MINC=0`, `PINC=1`. Learner predicted all four stores
would overwrite `dst[0]`, producing `{40,0,0,0}` while DMA still reached Transfer
Complete. Observed destination `{40,0,0,0}`, `NDTR=0`, `EN=0`, `TCIF=1`,
`TEIF=0`, `FEIF=0`, `timed_out=0`. Final source restores `MINC=1`.

### 9. Understanding Check

Project Chat verified the learner's mental model for source/destination direction,
increment behavior, NDTR as remaining-item count, normal/circular behavior,
buffer lifetime and CPU/DMA ownership, including static/global versus stack
lifetime and half-buffer/ping-pong ownership at concept level.

Core lesson: Transfer Complete means DMA completed the configured transfer; it
does not prove the application-level output is semantically correct. This was
normal AI-3 learning, not an independent competency assessment.

### 10. Defects / Failed Tests

P0 blocker: NONE discovered.

Known limitations/characteristics: hard-coded internal source/destination data;
the request parameter remains unused; polling only; no DMA interrupt, circular
implementation or production driver claim. Post-snapshot flag clearing leaves
`HTIF` for the next invocation's initial full Stream 0 flag clear. This did not
block the measured transfer and learner logic was not changed for cleanup.

### 11. Carry-over

From Week 3: exactly one P1 correct-baud UART wire-timing / logic-analyzer evidence
item remains OPEN, due 2026-09-06. W04D04 evidence does not close it.
From W04D04: no P0 blocker; recorded lab limitations are non-blocking.
Recovery: ACTIVE EXECUTION RECOVERY; canonical dates and remaining sequence unchanged.
W04D05 remains NOT STARTED. Latest competency remains W03-C-UART-FOUND — COMPETENCY_PASS.

### 12. Next Action

BOOT W04D05 only after Project Chat independently verifies this END DAY report;
read the authoritative HardFault day card and establish the controlled-fault /
diagnostic-report Day Contract before implementation.
