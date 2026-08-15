# W01D06 Raw Written Answers

Assessment ID: `W01D06-C-CODING-01`

Evidence status: original scored AI-0 answers, preserved without post-gate
correction. These answers are part of the raw attempt and must not be silently
rewritten after scoring.

## Task 2 Analysis

1. sizeof(src) dùng sai mục đích: Trả về kích thước của con trỏ
(thường là 4 hoặc 8 byte), chứ không phải chiều dài thực tế của chuỗi truyền vào.

Lỗi tràn bộ đệm (Buffer Overflow): Khi n == dst_cap, lệnh
dst[n] = '\0' sẽ ghi ký tự null ra ngoài phạm vi cấp phát của dst
(index hợp lệ cao nhất chỉ là dst_cap - 1).

Thiếu kiểm tra NULL: Nếu src hoặc dst là NULL, chương trình sẽ bị crash
(Segmentation Fault) khi gọi memcpy hoặc lúc gán mảng.

## Task 3 Analysis

1. Dangling Pointer (Con trỏ lửng): Hàm trả về địa chỉ của biến cục bộ max
(return &max;). Biến này nằm trên stack và sẽ bị hủy ngay khi hàm kết thúc.
Truy cập vào con trỏ này ở nơi gọi hàm sẽ dẫn đến Undefined Behavior.

Thiếu kiểm tra đầu vào: Hàm truy cập trực tiếp values[0] mà không kiểm tra
values == NULL hoặc count == 0, có thể gây invalid access/crash.

2. API redesign:
Dùng bool làm trạng thái success/failure và truyền out_max để nhận kết quả.

Success:
return true khi values != NULL, count > 0, out_max != NULL;
maximum được ghi vào *out_max.

Failure:
return false nếu values == NULL, count == 0 hoặc out_max == NULL;
không đọc/ghi sai vùng nhớ và *out_max không bị thay đổi.

## Task 4 Raw Answer

Original layout:

tag:
offset 0

padding:
3 bytes at offsets 1,2,3

seq:
offset 4

len:
offset 8

flags:
offset 10

sizeof(packet_meta_t):
12 bytes

total padding:
4 bytes
= 3 internal bytes + 1 tail-padding byte

Optimized ordering:

```c
typedef struct {
    uint32_t seq;
    uint16_t len;
    uint8_t  tag;
    uint8_t  flags;
} packet_meta_t_optimized;
```

Result:
sizeof = 8 bytes
padding = 0
