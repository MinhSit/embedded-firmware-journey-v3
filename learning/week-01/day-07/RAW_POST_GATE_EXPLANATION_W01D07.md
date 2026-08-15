# W01D07 Raw Post-Gate Explanation

Evidence classification: `CHAT-DERIVED LEARNER RAW POST-GATE EXPLANATION`

Phase: after the scored Week 1 C Foundations competency gate closed.

The text below is preserved verbatim. The executor must not silently correct
spelling, grammar, technical imprecision or formatting.

volatile đảm bảo gì?
Đảm bảo trình biên dịch không cache hay xóa bỏ các thao tác với biến; mọi lệnh đọc/ghi trên code bắt buộc phải thực thi thực tế xuống bộ nhớ (observable accesses).

volatile không đảm bảo gì?
Không cung cấp tính nguyên tử (atomicity) cho phép toán, và hoàn toàn không phải là cơ chế đồng bộ, locking hay memory barrier giữa các luồng/ngắt.

3 ví dụ UB trong C mà firmware engineer dễ dính:

Dịch trái một bit vào vị trí dấu ví dụ dịch 1 << 31 nên phải dùng 1u để nó ko âm
Số có dâu cũng ko bị tràn số như ko dâu dãn tới UB
Dịch số lượng bít vượt quá số bit của kiểu dữ liệu vd uint32_t result1 = val >> 32;
biến cục bộ khởi  tạo ko có giá trị ban đầu cũng có thể là UB vd  uint32_t total;
