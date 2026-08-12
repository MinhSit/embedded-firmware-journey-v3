# W01D03 — Alignment / Endian Note

Date: 2026-08-12
Toolchain: Host GCC 14.2.0
AI mode used so far: AI-1 theory, AI-2 hints, AI-3 review/debug, AI-4 bounded code/syntax assistance after my own attempts; AI-assisted wording in Section 7. No AI-0 competency claim.

## 1. Prediction — fill before running measurements

### layout_a_t

| Item | Prediction | Reason |
|---|---:|---|
| sizeof | 12 | Do tổng số các byte ba gồm pad là 12 |
| _Alignof | 4 | Có thể bắt đầu ở vị trí chia hết cho 4 |
| offset(tag) | 0 | Bắt đầu tại 0 thêm 3 pad |
| offset(value) | 4 | aligment quy định phải ở vị trí chia hết cho 4 |
| offset(code) | 8 | Ngay sau value và có 2 tail padding |
| internal padding | 3 | Điền sau tag để value bắt đầu tại 4 |
| tail padding | 2 | Điền sau code để cả struct đều đúng nếu được dùng lại |

### layout_b_t

| Item | Prediction | Reason |
|---|---:|---|
| sizeof | 8 | Tổng tất cả gồm cả pad là 8 |
| _Alignof | 4 | Có thể bắt đầu ở vị trí chia hết cho 4  |
| offset(tag) | 6 | Sau value 4 byte và code 2 byte nên tag bắt đầu ở offset 6 |
| offset(value) | 0 | Bắt đầu đầu tiên ở 0 |
| offset(code) | 4 | Ngay sau value |
| internal padding | 0 | Không có |
| tail padding | 1 | 1 byte tail padding sau tag để sizeof(struct) thành 8 và object kế tiếp vẫn thỏa alignment 4 |

## 2. Observed

Build command:

```text
PS D:\embedded-firmware-journey-v3> gcc -std=c17 -Wall -Wextra -Wpedantic -Werror learning/week-01/day-03/struct_layout.c tests/host/test_struct_layout.c -Ilearning/week-01/day-03 -o tests/host/test_struct_layout.exe
```

Test command:

```text
PS D:\embedded-firmware-journey-v3> .\tests\host\test_struct_layout.exe
PASS: D03-T01 A size
PASS: D03-T01 A alignment
PASS: D03-T01 A tag offset
PASS: D03-T01 A value offset
PASS: D03-T01 A code offset
PASS: D03-T03 A value aligned
PASS: D03-T03 A code aligned
PASS: D03-T02 B size
PASS: D03-T02 B alignment
PASS: D03-T02 B tag offset
PASS: D03-T02 B value offset
PASS: D03-T02 B code offset
PASS: D03-T03 B value aligned
PASS: D03-T03 B code aligned
PASS: D03-T04 union contains uint32_t
PASS: D03-T04 union members share start address
PASS: D03-T05 swap16 known
PASS: D03-T06 swap16 zero
PASS: D03-T06 swap16 ones
PASS: D03-T07 swap16 involution
PASS: D03-T08 swap32 known
PASS: D03-T09 swap32 zero
PASS: D03-T09 swap32 ones
PASS: D03-T10 swap32 involution
PASS: D03-T11 host endian
SUMMARY: 25 tests, 0 failed
```

### layout_a_t

```text
sizeof: 12
_Alignof: 4
offset(tag): 0
offset(value): 4
offset(code): 8
```

### layout_b_t

```text
sizeof: 8
_Alignof: 4
offset(tag): 6
offset(value): 0
offset(code): 4
```

## 3. Prediction mismatches

```text
No numeric mismatch.

All predicted sizeof, _Alignof and member offsets for layout_a_t
and layout_b_t matched the observed host results.
```

## 4. Union observation

```text
sizeof(u32_view_t): 4
_Alignof(u32_view_t): 4

What shared storage means:
All members of a union use the same memory region and start at the same address.

Why I am not using union-punning as my portable serialization baseline:
The in-memory representation depends on implementation details such as byte order.
For portable serialization, I should explicitly control individual bytes instead.
```

## 5. Endian observation

Use a value such as `0x01020304` and record the object bytes.

```text
Bytes at increasing addresses: 04 03 02 01
Detected host endian: Little-endian

What endian means:
Endian describes the order in which bytes of a multi-byte value are stored in memory.

What endian does NOT mean:
It does not mean that the bits inside each byte are reversed.
```

Điểm cần hiểu chứ không chỉ copy:

```text
value = 0x01020304

địa chỉ thấp                         địa chỉ cao
     ↓                                   ↓
    04        03        02        01
     ↑
least-significant byte
```

## 6. Portability boundary

C-level concepts I can rely on:
- `sizeof` gives the size of an object/type in bytes.
- `offsetof` gives the byte offset of a struct member.
- Union members share the same storage.
- `unsigned char *` can be used to inspect an object's byte representation.

Implementation/ABI observations I must re-measure or document:
- Exact `sizeof(struct)`.
- Exact member offsets and padding.
- Exact alignment values.
- Host endian / byte order.

## 7. Closed-book explanation

> Provenance note: The technical ideas below came from my answers during guided questioning. AI helped polish the wording. This section is not independent AI-0 competency evidence.

Alignment là yêu cầu để một object hoặc member bắt đầu tại địa chỉ phù hợp, còn padding là các byte compiler chèn thêm để thỏa yêu cầu đó. Tail padding được thêm ở cuối struct để kích thước của struct phù hợp với alignment của chính nó, nhờ đó các phần tử liên tiếp trong một array vẫn bắt đầu đúng vị trí. Thứ tự các member có thể làm thay đổi `sizeof(struct)` vì cách sắp xếp khác nhau có thể cần số lượng padding khác nhau; sắp xếp hợp lý có thể giảm padding và giảm kích thước struct. Endian mô tả thứ tự các byte của một giá trị multi-byte trong memory, và little-endian đặt byte có trọng số thấp nhất tại địa chỉ thấp nhất. Raw struct serialization không portable vì padding/layout và endian có thể khác giữa compiler, ABI hoặc platform, làm bên nhận hiểu sai dữ liệu hoặc thậm chí gây lỗi bộ nhớ nếu copy số byte không phù hợp vào buffer.

## 8. Final result

```text
Build: PASS
Tests: PASS
Tests run: 25
Tests failed: 0
Known issue: None in the current visible host test suite.
Evidence: `evidence/week-01/day-03/test_struct_layout.txt`
Artifact status: `ARTIFACT_PASS`
Competency status: `W01-C-FOUND — COMPETENCY_UNVERIFIED`
```
