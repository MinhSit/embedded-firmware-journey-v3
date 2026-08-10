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

- Tự implement E01–E07:
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

Start `WEEK 1 DAY 2` under V3 AI-integrity rules; keep W01-C-FOUND unverified until the fresh AI-0 gate.
