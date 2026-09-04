#ifndef PWM_H
#define PWM_H

#include <stdbool.h>
#include <stdint.h>

/*
 * W04D02 PWM Interface — Neutral Starter Stub
 *
 * All implementations, timer/channel selection, GPIO alternate-function
 * configuration, prescaler/auto-reload/compare calculations, and validation
 * policies are learner-owned.
 */

void pwm_init(void);
bool pwm_set_frequency(uint32_t frequency_hz);
bool pwm_set_duty_cycle(uint32_t duty_percent);
uint32_t pwm_get_frequency(void);
uint32_t pwm_get_duty_cycle(void);

#endif /* PWM_H */
