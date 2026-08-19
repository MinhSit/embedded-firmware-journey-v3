#include <stdint.h>

static void learner_gpio_task(void)
{
    /* TODO(LEARNER): verify the peripheral clock source from RM0390. */
    /* TODO(LEARNER): enable the correct GPIO peripheral clock. */
    /* TODO(LEARNER): configure the verified LED pin as output. */
    /* TODO(LEARNER): drive/toggle the output without using HAL/LL init code. */
}

int main(void)
{
    learner_gpio_task();

    for (;;) {
        __asm volatile ("nop");
    }
}
