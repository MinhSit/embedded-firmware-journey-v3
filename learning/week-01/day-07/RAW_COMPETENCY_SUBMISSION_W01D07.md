# W01D07 Raw Competency Submission

Evidence classification: `CHAT-DERIVED LEARNER RAW EVIDENCE`

Assessment: `Week 1 C Foundations competency gate`

Competency ID: `W01-C-FOUND`

The learner answered directly in chat during the scored AI-0 attempt. No
learner-created Day07 `.c` files or folder existed during the scored attempt.

The text and code below must remain verbatim. Spelling, grammar, technical
imprecision and formatting mistakes are preserved. The executor must not
silently correct this raw evidence.

## Raw Task 1

Task 1 — Pointer / Array / Qualifiers
Trả lời ngắn, không cần văn hoa:
A. int a[8]; và int *p; khác nhau bản chất thế nào?
Đơn giản a[8] là object mảng chứa các phần tử có cùng kiểu dữ liệu được cấp phát vùng nhớ liền kế chứa được 8 sô nguyên. *p là con trỏ trỏ tới 1 cái gì đó, có thể trỏ đến bất kì đâu
B. Trong:
void f(int a[8]);
bên trong f, parameter a thực sự có kiểu/semantics gì? sizeof(a) có cho kích thước toàn bộ array của caller không? Giải thích.
khi a được đưa vào hàm nó sẽ bị suy biến thành con trỏ tới phần tử đầu tiên là dùng size of chỉ ra kích thước con trỏ mà thôi
C. Giải thích khả năng sửa pointee và retarget pointer của ba declaration:
const int *p1; không được sửa pointee, được retaget
int * const p2 = ...; được sửa pontie, ko được retaget
const int * const p3 = ...; ko được pontiee ko dược retaget
D. Khi nào one-past-end pointer hợp lệ, và thao tác nào với nó là không hợp lệ?
hợp lệ khi dùng để làm mốc so sánh ko hợp lệ khi derefrence đọc ghi giá trị tại đó

## Raw Task 2

Task 2 — Fresh bit problem
Implement:
#include <stdbool.h>
#include <stdint.h>
bool u32_field_extract(
    uint32_t src,
    unsigned lsb,
    unsigned width,
    uint32_t *out
);
Contract:
out == NULL → fail.
width == 0 || width > 32 → fail.
lsb >= 32 → fail.
field không được vượt bit 31.
width == 32 chỉ hợp lệ khi lsb == 0.
invalid → *out phải giữ nguyên.
success → extract field về bit 0 của *out.
không có undefined behavior do shift.
Ví dụ về semantics, không phải lời giải:
src = ABCDEF..., lsb = k, width = n
=> lấy đúng n bit bắt đầu tại k và đưa chúng xuống bit 0
Viết function hoàn chỉnh.
bool u32_field_extract(
    uint32_t src,
    unsigned lsb,
    unsigned width,
    uint32_t *out
) {
    if (out == NULL) {
        return false;
    }
    if (width == 0 || width > 32) {
        return false;
    }
    if (lsb >= 32) {
        return false;
    }
    if (lsb + width > 32) {
        return false;
    }
    uint32_t mask = 0u;
    for (unsigned i = lsb; i < lsb + width; i++) {
        mask |= (1u << i);
    }

    *out = (src & mask) >> lsb;
    return true;
}

## Raw Task 3

Task 3 — Diagnose array / bounds / lifetime
Cho code:
#include <stdbool.h>
#include <stddef.h>
bool first_positive(
    const int *values,
    size_t count,
    const int **out
)
{
    int copy[4];
    for (size_t i = 0; i < count; ++i) {
        copy[i] = values[i];
    }
    for (size_t i = 0; i < count; ++i) {
        if (copy[i] > 0) {
            *out = &copy[i];
            return true;
        }
    }
    return false;
}
Yêu cầu:
Liệt kê các correctness/safety defects quan trọng.
Nói rõ defect nào là bounds, defect nào là lifetime.
Redesign API để caller nhận được kết quả an toàn.
Viết implementation mới.
Failure semantics phải rõ: input nào fail và output có bị thay đổi hay không.
1. Correctness/Safety Defects:
Bounds Defect: copy[4] chỉ có 4 phần tử. Nếu count > 4, vòng lặp ghi copy[i] = values[i] sẽ gây tràn bộ đệm (stack buffer overflow).
Lifetime Defect: *out = &copy[i]; gán con trỏ trỏ vào vùng nhớ của biến cục bộ copy trên stack. Khi hàm kết thúc, copy bị hủy, *out trở thành dangling pointer.
Safety Defect (Null Pointer Dereference): Hàm thiếu kiểm tra out == NULL trước khi gán *out = ..., có thể gây crash. Tương tự với values.
2. Redesign API & Implementation:
Giải pháp: Bỏ mảng copy. Thay vì trả về địa chỉ của biến cục bộ, trả về địa chỉ của chính phần tử trong mảng nguyên thủy values.
Failure semantics:
Fail nếu out == NULL.
Fail nếu values == NULL khi count > 0.
Khi fail hoặc không tìm thấy, trả về false, *out giữ nguyên không đổi.
#include <stdbool.h>
#include <stddef.h>

bool first_positive(
    const int *values,
    size_t count,
    const int **out
) {
    if (out == NULL) {
        return false;
    }
    if (values == NULL && count > 0) {
        return false;
    }

    for (size_t i = 0; i < count; ++i) {
        if (values[i] > 0) {
            *out = &values[i];
            return true;
        }
    }

    return false;
}

## Raw Task 4

Task 4 — Ring-buffer unseen-state reasoning
Ring buffer có:
capacity = 5
head  = index của slot sẽ ghi tiếp
tail  = index của phần tử sẽ đọc tiếp
count = số phần tử hiện có
Initial state:
head  = 4
tail  = 2
count = 2
slot[2] = A
slot[3] = B
Thực hiện lần lượt:
1. push(C)
2. push(D)
3. pop()
4. push(E)
5. push(F)
6. push(G)
7. pop()
8. pop()
Giả sử:
push khi full → fail, state không đổi.
pop khi empty → fail, state không đổi.
index wrap modulo capacity.
Hãy ghi:
operation 3 trả về gì;
operation 6 success hay fail;
operation 7 và 8 trả về gì;
head, tail, count sau mỗi operation;
logical FIFO contents sau operation 5;
final head, tail, count;
giải thích vì sao chỉ nhìn head == tail là chưa đủ nếu design này dùng count.
Operation 3 trả về: A
Operation 6: Fail (buffer đã đạt capacity 5 tại bước 5).
Operation 7 và 8 trả về:
Operation 7 trả về: B
Operation 8 trả về: C
Trạng thái sau mỗi operation:
Sau 1 push(C): head = 0, tail = 2, count = 3
Sau 2 push(D): head = 1, tail = 2, count = 4
Sau 3 pop():   head = 1, tail = 3, count = 3
Sau 4 push(E): head = 2, tail = 3, count = 4
Sau 5 push(F): head = 3, tail = 3, count = 5
Sau 6 push(G): head = 3, tail = 3, count = 5 (trạng thái không đổi do fail)
Sau 7 pop():   head = 3, tail = 4, count = 4
Sau 8 pop():   head = 3, tail = 0, count = 3
Logical FIFO contents sau operation 5:
[B, C, D, E, F]
Final state (sau operation 8):
head = 3
tail = 0
count = 3
Vì sao chỉ nhìn head == tail là chưa đủ?
Khi head == tail, có hai trạng thái vật lý hoàn toàn khác biệt nhưng trùng lặp cấu hình con trỏ:
Buffer trống hoàn toàn (vừa pop hết).
Buffer đầy hoàn toàn (vừa push đầy, head rượt kịp tail vòng tiếp theo).
Do đó, nếu thiết kế không chừa lại 1 slot trống (như kỹ thuật luôn giữ (head+1)%capacity == tail), ta bắt buộc phải duy trì biến count để phân biệt rỗng hay đầy.
