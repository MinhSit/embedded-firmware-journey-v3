#include <stdint.h>
#include "stm32f446xx.h"

static void learner_gpio_input_output_task(void)
{
    /* RCC */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    (void)RCC->AHB1ENR;

    /* PC13 -> input, no pull */
    GPIOC->MODER &= ~(3U << (13U * 2U));
    GPIOC->PUPDR &= ~(3U << (13U * 2U));

    /* PA5 -> output */
    GPIOA->MODER &= ~(3U << (5U * 2U));
    GPIOA->MODER |=  (1U << (5U * 2U));

    for (;;)
    {
        if ((GPIOC->IDR & (1U << 13)) == 0U)
        {
            // GPIOA->BSRR = (1U << 5);
            GPIOA->ODR |= (1U << 5);
        }
        else
        {
            // GPIOA->BSRR = (1U << (5U + 16U));
            GPIOA->ODR &= ~(1U << 5);
        }
    }
}

int main(void)
{
    learner_gpio_input_output_task();

    for (;;) {
        __asm volatile ("nop");
    }
}
