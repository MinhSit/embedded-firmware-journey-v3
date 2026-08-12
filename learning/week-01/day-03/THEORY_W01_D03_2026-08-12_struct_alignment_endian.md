# THEORY — W01D03 — Struct, Alignment và Endian

Date: 2026-08-12
Roadmap: Week 1 / Day 3
AI mode for learning: AI-1 theory/clarification; AI-2 hints. AI-3 only after a meaningful attempt. Do not request implementation patches for the core TODO if you want clean practice provenance.

## 1. Outcome

Đến cuối ngày, bạn sẽ đo và giải thích được layout của hai `struct` bằng `sizeof`, `_Alignof` và `offsetof`; phân biệt padding/alignment/tail padding; hiểu `union`/`enum` ở mức thực dụng; tự implement byte-swap + host-endian detection và PASS host tests.

## 2. Mental model

### Struct layout

Compiler đặt member theo thứ tự khai báo nhưng có thể chèn **padding bytes** để thỏa yêu cầu **alignment** của từng member. `sizeof(struct)` còn có thể lớn hơn vị trí kết thúc member cuối vì **tail padding**, giúp phần tử kế tiếp trong một array of struct cũng được căn chỉnh đúng.

Đừng học thuộc một con số layout cụ thể như một luật C. Hãy đo bằng:

- `sizeof(T)` — tổng kích thước object type `T`;
- `_Alignof(T)` — yêu cầu alignment của type `T`;
- `offsetof(T, member)` — byte offset của member trong struct.

Exact size/offset là implementation/toolchain/ABI dependent. Điều cần hiểu là cơ chế và cách kiểm tra.

### Union

Các member của `union` chia sẻ cùng một vùng storage. `sizeof(union)` phải đủ chứa member lớn nhất và alignment phải đủ cho các member của nó. Trong bài hôm nay, union dùng để quan sát storage overlap; không dùng union-punning làm baseline portable cho serialization/endian conversion.

### Enum

`enum` tạo một tập tên symbolic integer constants. Dùng enum để làm state/status rõ nghĩa hơn magic number. Đừng mặc định `sizeof(enum)` hay exact representation là portable nếu chưa kiểm tra ABI/compiler contract.

### Endianness

Endian là thứ tự byte của một multi-byte object trong memory.

Ví dụ giá trị 32-bit `0x12345678`:

- little-endian: byte ở địa chỉ thấp nhất thường là `0x78`;
- big-endian: byte ở địa chỉ thấp nhất thường là `0x12`.

Endian không phải "bit order". Khi encode protocol, hãy định nghĩa byte order của wire format thay vì phụ thuộc host layout.

## 3. Integer-promotion warning

Các toán hạng nhỏ hơn `int` có thể bị integer promotion trước phép shift/bitwise. Khi viết byte-swap, dùng unsigned types có độ rộng rõ ràng và kiểm soát cast/mask/shift để tránh signed-shift hoặc width assumptions.

## 4. Flow hôm nay

1. Predict layout A/B trên giấy.
2. Build/run một probe nhỏ bằng `sizeof/_Alignof/offsetof`.
3. So sánh prediction với observation.
4. Implement `inspect_layout_*` bằng language operators/macros chuẩn.
5. Implement byte swap 16/32-bit.
6. Implement host-endian detection bằng object representation.
7. Chạy visible host tests.
8. Ghi `alignment-note.md` và tự giải thích lại closed-book.

## 5. Failure modes thường gặp

- nhầm padding là "compiler lãng phí memory" thay vì alignment trade-off;
- học thuộc exact offsets từ một máy và gọi đó là C guarantee;
- cho rằng member order không ảnh hưởng size;
- nhầm endian với bit numbering;
- shift signed value hoặc shift với width không kiểm soát;
- dùng cast pointer tùy tiện để đọc object representation;
- serialize raw `struct` trực tiếp rồi giả định wire format portable.

## 6. Điều cần quan sát

- `sizeof(layout_a_t)` và `sizeof(layout_b_t)`;
- `_Alignof(...)` của struct và member types;
- `offsetof(...)` của từng member;
- có internal padding và tail padding hay không;
- byte đầu tiên của `0x01020304` trong memory;
- test output cho known pattern + boundary + involution của byte swap.

## 7. Interview vocabulary

- **alignment** — yêu cầu địa chỉ object/member phải chia hết theo một biên nhất định.
- **padding** — byte compiler chèn giữa/đầu/cuối layout để thỏa alignment.
- **tail padding** — padding sau member cuối của struct.
- **object representation** — dãy byte biểu diễn một object trong memory.
- **endianness** — thứ tự byte của multi-byte value trong memory/wire format.
- **ABI (Application Binary Interface)** — quy ước binary giữa compiler/platform, gồm nhiều chi tiết như calling convention và layout rules.

## 8. Reading scope

Chỉ tra đúng các mục cần cho bài: `sizeof`, `_Alignof`, `offsetof`, struct/union layout, object representation và integer promotion. Không đi sang `#pragma pack`, bit-field ABI hoặc compiler extension hôm nay.

## 9. Pre-check — trả lời trước khi code, không dùng AI

1. Padding khác alignment như thế nào?
2. Vì sao `sizeof(struct)` có thể lớn hơn `offsetof(last) + sizeof(last)`?
3. Exact offset của member có phải C-language guarantee không?
4. Endianness mô tả thứ tự byte hay thứ tự bit?
5. Vì sao gửi raw bytes của một `struct` qua UART/protocol là thiết kế không portable?
6. `uint16_t` tham gia shift có thể chịu integer promotion như thế nào?
