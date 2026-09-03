#include "timer_timebase.h"
#include <stm32f446xx.h>

void timer2_init_1khz(void)
{
    /* 1. Enable peripheral clock cho TIM2 tren APB1 bus */
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    /* 2. Dam bao counter dung khi cau hinh (clear bit CEN) */
    TIM2->CR1 &= ~TIM_CR1_CEN;

    /*
     * 3. Time-base configuration:
     *    TIM2CLK = 90 MHz (HCLK = 180 MHz, APB1 prescaler = /4 -> TIM2CLK = 90 MHz)
     *    - f_counter = TIM2CLK / (PSC + 1) = 90 MHz / (89 + 1) = 1 MHz (1 us tick)
     *    - f_update  = f_counter / (ARR + 1) = 1 MHz / (999 + 1) = 1 kHz (1 ms period)
     */
    TIM2->PSC = 15U;
    TIM2->ARR = 999U;

    /* 4. Reset counter ve 0 va cau hinh dem len (edge-aligned upcounting) */
    TIM2->CNT = 0U;
    TIM2->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS);

    /*
     * 5. Sinh Update Event bang phan mem (UG) de khoi tao lai counter va dam bao
     *    gia tri prescaler duoc apply ngay; hanh vi cua ARR phu thuoc cau hinh ARPE.
     *    Xoa co UIF theo semantics rc_w0 bang cach ghi truc tiep ~TIM_SR_UIF (write 0 to clear,
     *    write 1 has no effect), tranh RMW lam vo tinh xoa cac flag khac.
     */
    TIM2->EGR = TIM_EGR_UG;
    TIM2->SR = ~TIM_SR_UIF;

    /* 6. Cho phep Update Interrupt (UIE) */
    TIM2->DIER |= TIM_DIER_UIE;

    /* 7. Cau hinh NVIC: Set priority va kich hoat vector ngat TIM2_IRQn */
    NVIC_SetPriority(TIM2_IRQn, 2);
    NVIC_EnableIRQ(TIM2_IRQn);

    /* 8. Kich hoat Counter (CEN) */
    TIM2->CR1 |= TIM_CR1_CEN;
}

void TIM2_IRQHandler(void)
{
    /* Kiem tra co ngat Update Interrupt Flag (UIF) */
    if (TIM2->SR & TIM_SR_UIF)
    {
        /* Clear UIF bang direct write (rc_w0), ghi 0 vao bit UIF va 1 vao cac bit con lai */
        TIM2->SR = ~TIM_SR_UIF;

        /* Toggle chan PA5 (LED2) */
        GPIOA->ODR ^= (1U << 5);
    }
}
