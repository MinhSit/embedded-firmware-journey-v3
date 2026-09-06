#include "bsp_pwm.h"

/*
 * Giả định cấu hình xung nhịp hiện tại:
 * System chạy HSI 16 MHz, APB1 prescaler = /1 -> TIM2 clock = 16 MHz.
 * Lưu ý: Giá trị này phụ thuộc vào clock tree và timer multiplier của APB1.
 */
#define BSP_TIM2_CLOCK_HZ 16000000U

void bsp_pwm_hw_init(void)
{
    /* 1. Bật clock bus cho GPIOA và TIM2 */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    /* 2. Cấu hình chân PA5 sang Alternate Function (AF01 - TIM2_CH1) */
    GPIOA->MODER &= ~GPIO_MODER_MODER5;
    GPIOA->MODER |= GPIO_MODER_MODER5_1;

    GPIOA->OTYPER &= ~GPIO_OTYPER_OT_5;

    GPIOA->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR5;
    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5_1;

    GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD5;

    /* AF01 (TIM2_CH1) trên chân PA5: AFR[0] vị trí pin 5 (bit 20..23) */
    GPIOA->AFR[0] &= ~(0xFU << (5U * 4U));
    GPIOA->AFR[0] |=  (0x1U << (5U * 4U));
}

TIM_TypeDef *bsp_pwm_get_tim_instance(void)
{
    return TIM2;
}

uint32_t bsp_pwm_get_timer_clock_hz(void)
{
    return BSP_TIM2_CLOCK_HZ;
}