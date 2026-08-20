#include <stdint.h>
#include "stm32f446xx.h"

static void learner_gpio_input_output_task(void)
{
    /* TODO(LEARNER): verify the board input/output topology from official sources. */
    /* TODO(LEARNER): derive and enable the required GPIO peripheral clocks. */
    /* TODO(LEARNER): configure the verified input mode and pull behavior. */
    /* TODO(LEARNER): read the verified input through the appropriate data register. */
    /* TODO(LEARNER): compare ODR read-modify-write with BSRR output updates. */
    /* TODO(LEARNER): implement and observe the intended input-to-output behavior. */
}

int main(void)
{
    learner_gpio_input_output_task();

    for (;;) {
        __asm volatile ("nop");
    }
}
