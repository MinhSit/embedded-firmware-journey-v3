#include "stm32f446xx.h"
#include "fault_diag.h"

#define INVALID_RESERVED_ADDR  (0x00100000UL)

/* Đặt bằng 0 để chạy bình thường (Fix); Đặt bằng 1 khi muốn kích hoạt lại lỗi (Reproduce) */
#define ENABLE_CONTROLLED_FAULT  0

#if ENABLE_CONTROLLED_FAULT
static void trigger_controlled_fault(void)
{
    volatile uint32_t *bad_ptr = (volatile uint32_t *)INVALID_RESERVED_ADDR;
    volatile uint32_t read_val = *bad_ptr;
    (void)read_val;
}
#endif

int main(void)
{
    __asm volatile ("nop");
    __asm volatile ("nop");

#if ENABLE_CONTROLLED_FAULT
    /* Kích hoạt controlled fault */
    trigger_controlled_fault();
#endif

    /* Nhánh chạy bình thường: CPU sẽ vào đây và lặp vô tận ổn định */
    for (;;) {
        __asm volatile ("nop");
    }
}