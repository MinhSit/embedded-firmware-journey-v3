#ifndef PWM_H
#define PWM_H

#include <stdbool.h>
#include <stdint.h>
#include "stm32f446xx.h"

/*
 * PWM Driver Interface — Minimal Generic (Single Instance, CH1)
 *
 * Driver độc lập hoàn toàn với BSP và App.
 * Nhận instance ngoại vi và bus clock qua cơ chế dependency injection.
 */

bool pwm_init(TIM_TypeDef *tim, uint32_t timer_clock_hz);
bool pwm_set_frequency(uint32_t frequency_hz);
bool pwm_set_duty_cycle(uint32_t duty_percent);
uint32_t pwm_get_frequency(void);
uint32_t pwm_get_duty_cycle(void);

#endif /* PWM_H */