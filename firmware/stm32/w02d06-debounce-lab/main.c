#include <stdint.h>
#include "stm32f446xx.h"
#include <stdbool.h>
#include "debounce.h"

/*
 * W02D05 prerequisite baseline: raw EXTI13 edges still toggle LD2 directly.
 * W02D06 learner TODO: replace this raw-edge behavior with a non-blocking,
 * tick-driven debounce integration after completing the host-tested module.
 * No debounce state transition is implemented in this starter.
 */

static volatile uint32_t g_system_ticks = 0;

void SysTick_Handler(void)
{
    g_system_ticks++;
}

static uint32_t get_tick(void)
{
    return g_system_ticks;
}

static void systick_init(void)
{
    SysTick_Config(16000000U / 1000U);
}

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
    EXTI->RTSR |= EXTI_RTSR_TR13;
    EXTI->PR = EXTI_PR_PR13;
    EXTI->IMR  |= EXTI_IMR_MR13;
    /* TODO: determine and enable the matching NVIC interrupt. */
    NVIC_SetPriority(EXTI15_10_IRQn, 2);
    NVIC_EnableIRQ(EXTI15_10_IRQn);
}

volatile bool button_event_pending = false;

void EXTI15_10_IRQHandler(void)
{
    if (EXTI->PR & EXTI_PR_PR13) {
        EXTI->PR = EXTI_PR_PR13;
        button_event_pending = true;
    }
}

int main(void)
{
baseline_gpio_init();
    systick_init();
    learner_exti_nvic_init();

    debounce_config_t config = {
        .threshold_ticks = 20,
        .active_level = false
    };

    debounce_t btn;
    bool initial_raw = (GPIOC->IDR & (1U << 13)) != 0;
    debounce_init(&btn, &config, initial_raw, get_tick());

    while (1)
    {
        if (button_event_pending || btn.candidate_active)
        {
            button_event_pending = false;

            bool raw_level = (GPIOC->IDR & (1U << 13)) != 0;

            uint32_t now_ticks = get_tick();

            debounce_event_t evt = debounce_sample(&btn, raw_level, now_ticks);

            if (evt == DEBOUNCE_EVENT_ACTIVATED)
            {
                GPIOA->ODR ^= (1U << 5);
            }
        }
    }
}
