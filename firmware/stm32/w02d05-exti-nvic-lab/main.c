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
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    (void)RCC->APB2ENR;
    /* TODO: route the verified GPIO source to the required EXTI line. */
    SYSCFG->EXTICR[3] &= ~(0xFU << (1U * 4U));
    SYSCFG->EXTICR[3] |=  (0x2U << (1U * 4U));
    /* TODO: configure the verified trigger and unmask only that EXTI line. */
    EXTI->FTSR |= EXTI_FTSR_TR13;
    EXTI->RTSR &= ~EXTI_RTSR_TR13;
    EXTI->PR = EXTI_PR_PR13;
    EXTI->IMR  |= EXTI_IMR_MR13;
    /* TODO: determine and enable the matching NVIC interrupt. */
    NVIC_SetPriority(EXTI15_10_IRQn, 2);
    NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(void)
{
    if (EXTI->PR & EXTI_PR_PR13) {
        EXTI->PR = EXTI_PR_PR13;
        GPIOA->ODR ^= (1U << 5U);
    }
}

int main(void)
{
    baseline_gpio_init();
    learner_exti_nvic_init();

    for (;;) {
        __asm volatile ("nop");
    }
}
