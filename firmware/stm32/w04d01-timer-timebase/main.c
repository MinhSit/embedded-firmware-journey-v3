#include <stdint.h>

#include "stm32f446xx.h"
#include "timer_timebase.h"

static void gpio_observation_init(void)
{
    /* Reused Week 2 PA5/LD2 observation baseline; timer logic is not here. */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    (void)RCC->AHB1ENR;

    GPIOA->MODER &= ~(0x3U << (5U * 2U));
    GPIOA->MODER |=  (0x1U << (5U * 2U));
    GPIOA->OTYPER &= ~(1U << 5U);
    GPIOA->OSPEEDR &= ~(0x3U << (5U * 2U));
    GPIOA->PUPDR &= ~(0x3U << (5U * 2U));
    GPIOA->BSRR = GPIO_BSRR_BR5;
}

int main(void)
{
    gpio_observation_init();

    /* The function is a no-op until the learner completes its TODO. */
    timer2_init_1khz();

    for (;;) {
        __asm volatile ("nop");
    }
}
