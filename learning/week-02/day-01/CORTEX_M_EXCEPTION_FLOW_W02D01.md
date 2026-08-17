# W02D01 — Cortex-M Exception Flow Worksheet

## 1. My Initial Mental Model

Learner notes:
- Thread mode là mode chạy chương trình bình thường và có thể dùng MSP hoặc PSP.
- Handler mode dùng để xử lý exception/interrupt, nhưng lúc đầu tôi chưa rõ Handler dùng MSP hay PSP.
- Ban đầu tôi nghĩ sau reset có thể dùng MSP hoặc PSP vì Thread mode hỗ trợ cả hai.
- Tôi biết CPU phải lưu context khi exception xảy ra để sau Handler có thể quay lại chạy tiếp, nhưng chưa biết context được lưu vào stack nào.
- Tôi chưa biết rõ EXC_RETURN, late-arriving, nested/preemption và tail-chaining khác nhau thế nào.

## 2. Thread Mode
Learner notes:
- Dùng để chạy chương trình bình thường
- Sau reset CPU vào Thread Mode và dùng MSP
- Trong mode này có thể dùng stack ở MSP và PSP, CONTROL.SPSEL quyết định quyết định điều này

## 3. Handler Mode
Learner notes:
- Dùng để xử lý exception
- Khi có exception thì lưu stack frame lại rồi vào Handler Mode
- Mode này luôn dùng stack MSP
- Privilege của nó là always privileged

## 4. MSP
Learner notes:
- MSP là Main Stack Pointer, con trỏ của main stack.
- Cortex-M4 có hai stack pointer độc lập là MSP và PSP.
- Sau reset, Thread mode mặc định dùng MSP.
- Handler mode luôn dùng MSP.

## 5. PSP
Learner notes:
- PSP là Process Stack Pointer, con trỏ của process stack
- Chỉ Thread mode có thể dùng PSP
- CONTROL.SPSEL = 1 thì PSP
- Nếu Thread đang dùng PSP rồi exception xảy ra thì stack frame được lưu lại ở PSP, sau đó Handler chạy ở MSP

## 6. Exception Entry — My Reconstruction

Learner diagram / flow:

Thread mode đang dùng PSP
-> IRQ xảy ra
-> CPU lưu stack frame vào current stack = PSP để biết phải quay về chạy cái gì
-> CPU vào Handler mode, Handler dùng MSP
-> Handler chạy

## 7. Exception Return — My Reconstruction

Learner diagram / flow:

Handler kết thúc
-> EXC_RETURN cho biết return về Thread mode và unstack từ PSP
-> CPU restore context từ stack frame đã lưu trước đó
-> Thread tiếp tục dùng PSP

## 8. Registers I Need to Understand
Learner notes:
- SP: Stack Pointer, trỏ tới stack đang được dùng
- PC: Program Counter, địa chỉ/ lệnh tiếp theo CPU sẽ thực thi
- LR: Link Register, CPu ghi EXC_RETURN vào đây để phục vụ return
- xPSR: Chưa biết
- R0-R3, R12: Chưa biết
- CONTROL: trong Thread mode, dùng để chọn MSP/PSP qua SPSEL và chọn privileged/unprivileged qua nPRIV.

## 9. Closed-Book Reconstruction

Question 1: Thread mode khác Handler mode ở điểm cốt lõi nào?
My answer:
- Thread Mode chạy chương trình bình thường có thể dùng MSP lẫn PSP (MSP khi mới reset)
- Handler Mode xử lý expection, dùng MSP và always privileged

Question 2: Nếu Thread mode đang dùng PSP rồi một IRQ xảy ra, exception stack frame được lưu ở MSP hay PSP? Sau đó Handler chạy bằng stack nào?
My answer:
- Sẽ được lưu ở PSP
- Handler chạy băng MSP

Question 3: EXC_RETURN giúp CPU biết những gì khi handler kết thúc? Nêu 2 ý chính.
My answer:
- Cho biết return về Thread Mode hay Handler Mode, stack frame được lưu ở MSP hay PSP
- Cho biết có floating point state không

Question 4: Vì sao CPU phải lưu cả R0-R3, R12, LR, PC, xPSR vào exception stack frame thay vì chỉ lưu mỗi PC?
My answer:
- Vì cần phải có đủ context để restore về trạng thái trước khi xử lý expection, PC chỉ cho biết địa chỉ/ lệnh cần chạy tiếp theo

Question 5: Phân biệt ngắn gọn ba khái niệm này: late-arriving vs nested/preemption vs tail-chaining.
My answer:
- late-arriving là expection A vừa load chưa chạy lệnh nào thì B có priotity cao hơn tới, thì sẽ trỏ tới B để chạy B
- nested/preemption là expecion A đang chạy thì B tới, thì lưu stack frame A lên MSP và chạy B, sau khi B xong thì chạy tiếp A
- tail-chaining là A vừa chạy xong thay vì về Thread Mode thì thấy B đã đủ đièu kiện để chạy thì tiếp tục chạy B luôn
## 10. Official-Source Verification

Source: ARM Cortex-M4 Generic User Guide — Programmer's Model / Exception Model

What I corrected after verification:
- Sau reset, Thread mode mặc định dùng MSP vì CONTROL.SPSEL reset value = 0.
- Nếu Thread mode đang dùng PSP khi exception xảy ra, exception stack frame được lưu vào current stack = PSP; Handler sau đó chạy bằng MSP.
- Late-arriving xảy ra khi CPU còn đang stacking để vào Exception A và A chưa chạy instruction đầu tiên.
- Nested/preemption xảy ra khi Handler A đã đang chạy rồi bị Exception B priority cao hơn ngắt.
- Tail-chaining xảy ra khi Handler A vừa kết thúc và có exception khác đang pending, nên CPU chuyển thẳng sang handler tiếp theo.

## 11. Debugger / Register Observations

Expected:
- CPU sau reset vào Thread mode.
- Thread mode mặc định dùng MSP vì CONTROL.SPSEL reset value = 0.
- Handler mode luôn dùng MSP.

Observed:
- NOT PERFORMED — previous STM32 baseline source was deleted.
- No hardware/debug observation collected for W02D01.

## 12. Remaining Questions
- Trong stack frame thì xPSR, R0-R3/R12 có tác dụng gì ?
- EXC_RETURN làm việc cụ thể như nào ?

## 13. Final Independent Explanation

What I can now explain without AI/documentation:
-> Thread Mode đang chạy
-> Exception xảy ra
-> CPU lưu exception stack frame vào current stack của Thread (MSP hoặc PSP)
-> CPU vào Handler Mode, Handler luôn dùng MSP
-> Handler xử lý exception
-> Khi Handler kết thúc, nếu có exception khác đang pending và đủ điều kiện thì có thể tail-chain sang Handler đó
-> Nếu không, EXC_RETURN cho CPU biết return về mode nào và restore context từ MSP hay PSP
-> CPU restore context và tiếp tục execution trước đó

## 14. Next Action
- Kết thúc W02D01
