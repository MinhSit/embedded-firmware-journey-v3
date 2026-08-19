#include <stdint.h>
#include "stm32f446xx.h"

static void learner_gpio_task(void)
{
    /* TODO(LEARNER): verify the peripheral clock source from RM0390. */
    /* TODO(LEARNER): enable the correct GPIO peripheral clock. */
    /* TODO(LEARNER): configure the verified LED pin as output. */
    /* TODO(LEARNER): drive/toggle the output without using HAL/LL init code. */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    (void)RCC->AHB1ENR;
    GPIOA->MODER &= ~(0x3U << (5 * 2));
    GPIOA->MODER |=  (0x1U << (5 * 2));
    GPIOA->OTYPER &= ~(1U << 5);
    GPIOA->OSPEEDR &= ~(0x3U << (5 * 2));
    GPIOA->PUPDR &= ~(0x3U << (5 * 2));
    GPIOA->BSRR = GPIO_BSRR_BS5;
}

int main(void)
{
    learner_gpio_task();

    for (;;) {
        __asm volatile ("nop");
    }
}
