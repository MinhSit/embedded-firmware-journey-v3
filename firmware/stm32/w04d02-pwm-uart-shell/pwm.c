#include "pwm.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define TIMER_TICK_RATE_HZ    1000000ULL
#define PWM_MIN_FREQ_HZ       10U
#define PWM_MAX_FREQ_HZ       100000U
#define MAX_PRESCALER_VALUE   0xFFFFU

/* Ghi nhớ instance ngoại vi sau khi validate và khởi tạo thành công */
static TIM_TypeDef *s_tim = NULL;

bool pwm_init(TIM_TypeDef *tim, uint32_t timer_clock_hz)
{
    /* Đảm bảo fail-closed: reset trạng thái driver về uninitialized */
    s_tim = NULL;

    /* 1. Sanity check: Instance pointer không được NULL */
    if (tim == NULL) {
        return false;
    }

    /* 2. Kiểm tra xung nhịp: Phải lớn hơn target tick và chia hết chẵn cho 1 MHz */
    if (timer_clock_hz < (uint32_t)TIMER_TICK_RATE_HZ) {
        return false;
    }
    if ((timer_clock_hz % (uint32_t)TIMER_TICK_RATE_HZ) != 0U) {
        return false;
    }

    /* 3. Tính PSC: PSC = (timer_clock_hz / target_tick) - 1 */
    uint32_t psc_calc = (timer_clock_hz / (uint32_t)TIMER_TICK_RATE_HZ) - 1U;
    if (psc_calc > MAX_PRESCALER_VALUE) {
        return false;
    }

    /* Lưu instance sau khi validate toàn bộ tham số thành công */
    s_tim = tim;

    /* 4. Cấu hình Timebase khởi điểm 1 kHz, 50% duty */
    s_tim->PSC = (uint16_t)psc_calc;
    s_tim->ARR = 999U;      /* 1 MHz / (999 + 1) = 1 kHz */
    s_tim->CCR1 = 500U;     /* 500 / 1000 = 50% */

    /* 5. Cấu hình Output Compare Mode cho Channel 1 (CCMR1) */
    s_tim->CCMR1 &= ~TIM_CCMR1_CC1S;
    s_tim->CCMR1 &= ~TIM_CCMR1_OC1M;
    s_tim->CCMR1 |= (TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2);
    s_tim->CCMR1 |= TIM_CCMR1_OC1PE;

    /* 6. Cấu hình Auto-reload preload (ARPE = 1) trên CR1 */
    s_tim->CR1 |= TIM_CR1_ARPE;
    s_tim->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS);

    /* 7. Cấu hình cực tính và kích hoạt ngõ ra Channel 1 (CCER) */
    s_tim->CCER &= ~TIM_CCER_CC1P;
    s_tim->CCER |= TIM_CCER_CC1E;

    /* Nạp giá trị từ preload sang shadow register (ghi trực tiếp vào EGR) */
    s_tim->EGR = TIM_EGR_UG;

    /* 8. Kích hoạt bộ đếm Timer */
    s_tim->CR1 |= TIM_CR1_CEN;

    return true;
}

bool pwm_set_frequency(uint32_t frequency_hz)
{
    if (s_tim == NULL) {
        return false;
    }

    if (frequency_hz < PWM_MIN_FREQ_HZ || frequency_hz > PWM_MAX_FREQ_HZ) {
        return false;
    }

    uint64_t arr_old = (uint64_t)s_tim->ARR;
    uint64_t ccr_old = (uint64_t)s_tim->CCR1;
    uint64_t period_old = arr_old + 1ULL;

    uint64_t period_new = (TIMER_TICK_RATE_HZ + ((uint64_t)frequency_hz / 2ULL)) / (uint64_t)frequency_hz;
    if (period_new == 0ULL) {
        return false;
    }
    uint32_t arr_new = (uint32_t)(period_new - 1ULL);

    uint32_t ccr_new = 0U;
    if (ccr_old == 0ULL) {
        ccr_new = 0U;
    } else if (ccr_old >= period_old) {
        ccr_new = arr_new + 1U;
    } else {
        uint64_t ccr_calc = (ccr_old * period_new + (period_old / 2ULL)) / period_old;
        ccr_new = (uint32_t)ccr_calc;
    }

    s_tim->ARR = arr_new;
    s_tim->CCR1 = ccr_new;

    return true;
}

bool pwm_set_duty_cycle(uint32_t duty_percent)
{
    if (s_tim == NULL) {
        return false;
    }

    if (duty_percent > 100U) {
        return false;
    }

    uint32_t current_arr = s_tim->ARR;

    if (duty_percent == 0U) {
        s_tim->CCR1 = 0U;
    } else if (duty_percent == 100U) {
        s_tim->CCR1 = current_arr + 1U;
    } else {
        uint64_t period = (uint64_t)current_arr + 1ULL;
        uint64_t ccr_calc = ((period * (uint64_t)duty_percent) + 50ULL) / 100ULL;
        s_tim->CCR1 = (uint32_t)ccr_calc;
    }

    return true;
}

uint32_t pwm_get_frequency(void)
{
    if (s_tim == NULL) {
        return 0U;
    }

    uint64_t period = (uint64_t)s_tim->ARR + 1ULL;
    if (period == 0ULL) {
        return 0U;
    }

    uint64_t freq = (TIMER_TICK_RATE_HZ + (period / 2ULL)) / period;
    return (uint32_t)freq;
}

uint32_t pwm_get_duty_cycle(void)
{
    if (s_tim == NULL) {
        return 0U;
    }

    uint64_t arr = (uint64_t)s_tim->ARR;
    uint64_t ccr = (uint64_t)s_tim->CCR1;
    uint64_t period = arr + 1ULL;

    if (ccr == 0ULL) {
        return 0U;
    }

    if (ccr >= period) {
        return 100U;
    }

    uint64_t duty = ((ccr * 100ULL) + (period / 2ULL)) / period;
    if (duty > 100ULL) {
        duty = 100ULL;
    }

    return (uint32_t)duty;
}