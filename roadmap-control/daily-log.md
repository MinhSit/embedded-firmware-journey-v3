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

Planned: Không được ghi nhận rõ trong session.
Actual: Không được đo; không suy diễn focused time từ wall-clock span.

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
- This atomic W01D02 closure commit; resolve the exact hash from repository
  `HEAD` after commit.

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
- Focused time was not measured.

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
