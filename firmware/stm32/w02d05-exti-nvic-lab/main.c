#include <stdint.h>
#include "stm32f446xx.h"

static void baseline_gpio_init(void)
{
    /* Previously learned baseline only: B1 on PC13 and LD2 on PA5. */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    (void)RCC->AHB1ENR;

    GPIOC->MODER &= ~(3U << (13U * 2U));
    GPIOC->PUPDR &= ~(3U << (13U * 2U));

    GPIOA->MODER &= ~(3U << (5U * 2U));
    GPIOA->MODER |=  (1U << (5U * 2U));
    GPIOA->BSRR = (1U << (5U + 16U));
}

static void learner_exti_nvic_init(void)
{
    /* TODO: determine and enable the required SYSCFG clock. */
    /* TODO: route the verified GPIO source to the required EXTI line. */
    /* TODO: configure the verified trigger and unmask only that EXTI line. */
    /* TODO: determine and enable the matching NVIC interrupt. */
}

int main(void)
{
    baseline_gpio_init();
    learner_exti_nvic_init();

    for (;;) {
        __asm volatile ("nop");
    }
}
