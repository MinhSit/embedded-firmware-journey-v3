#include "pwm.h"
#include <stdbool.h>
#include <stdint.h>

/*
 * W04D02 PWM Implementation — Non-working starter stubs.
 *
 * All peripheral configuration, GPIO routing, clock calculations, and
 * parameter validations must be implemented by the learner.
 */

void pwm_init(void)
{
    /* TODO(learner): configure GPIO pin, alternate function, and timer channel for PWM output */
}

bool pwm_set_frequency(uint32_t frequency_hz)
{
    /* TODO(learner): calculate and apply prescaler / auto-reload for target frequency */
    (void)frequency_hz;
    return false;
}

bool pwm_set_duty_cycle(uint32_t duty_percent)
{
    /* TODO(learner): calculate and apply capture/compare value for target duty cycle */
    (void)duty_percent;
    return false;
}

uint32_t pwm_get_frequency(void)
{
    /* TODO(learner): return active configured PWM frequency in Hz */
    return 0U;
}

uint32_t pwm_get_duty_cycle(void)
{
    /* TODO(learner): return active configured PWM duty cycle percentage */
    return 0U;
}
