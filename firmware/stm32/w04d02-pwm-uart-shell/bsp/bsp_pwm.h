#ifndef BSP_PWM_H
#define BSP_PWM_H

#include <stdint.h>
#include "stm32f446xx.h"

/* Khởi tạo clock ngoại vi (GPIOA, TIM2) và định tuyến chân PA5 sang AF01 */
void bsp_pwm_hw_init(void);

/* Trả về timer instance gắn với chân PWM trên board Nucleo-F446RE */
TIM_TypeDef *bsp_pwm_get_tim_instance(void);

/* Trả về xung nhịp timer clock đầu vào dựa trên clock tree mặc định hiện tại (HSI 16 MHz) */
uint32_t bsp_pwm_get_timer_clock_hz(void);

#endif /* BSP_PWM_H */