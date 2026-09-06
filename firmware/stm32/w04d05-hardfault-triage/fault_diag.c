#include "fault_diag.h"
#include "stm32f446xx.h"

volatile fault_diag_snapshot_t g_fault_diag_snapshot;

/* Hàm C nhận con trỏ stack frame và lưu trữ trạng thái */
void fault_diag_capture(uint32_t *stacked_frame)
{
    /* 1. Lưu các thanh ghi trạng thái fault từ System Control Block (SCB) */
    g_fault_diag_snapshot.cfsr  = SCB->CFSR;
    g_fault_diag_snapshot.hfsr  = SCB->HFSR;
    g_fault_diag_snapshot.mmfar = SCB->MMFAR;
    g_fault_diag_snapshot.bfar  = SCB->BFAR;

    /* 2. Trích xuất Basic Exception Frame tự động lưu bởi Cortex-M */
    g_fault_diag_snapshot.r0   = stacked_frame[0];
    g_fault_diag_snapshot.r1   = stacked_frame[1];
    g_fault_diag_snapshot.r2   = stacked_frame[2];
    g_fault_diag_snapshot.r3   = stacked_frame[3];
    g_fault_diag_snapshot.r12  = stacked_frame[4];
    g_fault_diag_snapshot.lr   = stacked_frame[5];
    g_fault_diag_snapshot.pc   = stacked_frame[6];
    g_fault_diag_snapshot.xpsr = stacked_frame[7];

    /* Dừng debugger tại hiện trường */
    __asm volatile ("bkpt #0");

    for (;;) {
        __asm volatile ("nop");
    }
}

/* Handler chính: Naked wrapper kiểm tra bit 2 của EXC_RETURN */
__attribute__((naked)) void HardFault_Handler(void)
{
    __asm volatile (
        "tst lr, #4                \n" /* Kiểm tra bit 2 của EXC_RETURN */
        "ite eq                    \n"
        "mrseq r0, msp             \n" /* Nếu bit 2 = 0 -> Exception frame nằm trên MSP */
        "mrsne r0, psp             \n" /* Nếu bit 2 = 1 -> Exception frame nằm trên PSP */
        "b fault_diag_capture      \n" /* Nhảy vào hàm C với R0 = stacked_frame */
    );
}
