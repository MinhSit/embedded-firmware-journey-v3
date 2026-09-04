#include "pwm.h"
#include <stdbool.h>
#include <stdint.h>
#include "stm32f446xx.h"

/*
 * W04D02 PWM Implementation — Non-working starter stubs.
 *
 * All peripheral configuration, GPIO routing, clock calculations, and
 * parameter validations must be implemented by the learner.
 */

#define TIM2_CLOCK_HZ        16000000ULL
#define TIMER_TICK_RATE_HZ    1000000ULL

/* Giới hạn dải tần số an toàn: từ 10 Hz đến 100 kHz */
#define PWM_MIN_FREQ_HZ      10U
#define PWM_MAX_FREQ_HZ      100000U


 void pwm_init(void)
{
    /* 1. Bật clock cho GPIOA và TIM2 */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    /* 2. Cấu hình chân PA5 sang chế độ Alternate Function (AF01 - TIM2_CH1) */
    /* PA5 MODER: set 10 (Alternate function mode) */
    GPIOA->MODER &= ~GPIO_MODER_MODER5;
    GPIOA->MODER |= GPIO_MODER_MODER5_1;

    /* Output push-pull (reset state là 0, ghi tường minh) */
    GPIOA->OTYPER &= ~GPIO_OTYPER_OT_5;

    /* High speed cho cạnh xung dứt khoát */
    GPIOA->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR5;
    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5_1;

    /* No pull-up, no pull-down */
    GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD5;

    /* Cấu hình AF1 cho PA5 (nằm ở AFR[0] vị trí pin 5: dịch 5 * 4 = 20 bits) */
    GPIOA->AFR[0] &= ~(0xFU << (5U * 4U));
    GPIOA->AFR[0] |=  (0x1U << (5U * 4U));

    /* 3. Cấu hình Timer Timebase cho 1 kHz */
    TIM2->PSC = 15U;       /* 16 MHz / (15 + 1) = 1 MHz tick rate */
    TIM2->ARR = 999U;      /* 1 MHz / (999 + 1) = 1 kHz PWM frequency */
    TIM2->CCR1 = 500U;     /* 500 / 1000 = 50% duty cycle */

    /* 4. Cấu hình Output Compare Mode cho Channel 1 (CCMR1) */
    /* Đảm bảo Channel 1 là output: CC1S = 00 */
    TIM2->CCMR1 &= ~TIM_CCMR1_CC1S;

    /* Thiết lập PWM Mode 1: OC1M = 110 (Active khi CNT < CCR1, Inactive khi CNT >= CCR1) */
    TIM2->CCMR1 &= ~TIM_CCMR1_OC1M;
    TIM2->CCMR1 |= (TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2);

    /* Bật Preload register cho Channel 1 (OC1PE = 1) */
    TIM2->CCMR1 |= TIM_CCMR1_OC1PE;

    /* 5. Cấu hình Auto-reload preload (ARPE = 1) trên CR1 */
    TIM2->CR1 |= TIM_CR1_ARPE;

    /* Đảm bảo chế độ đếm tăng (DIR = 0) và edge-aligned (CMS = 00) */
    TIM2->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS);

    /* 6. Cấu hình cực tính và kích hoạt ngõ ra Channel 1 (CCER) */
    /* Active-high: CC1P = 0 */
    TIM2->CCER &= ~TIM_CCER_CC1P;

    /* Bật output cho Channel 1: CC1E = 1 */
    TIM2->CCER |= TIM_CCER_CC1E;

    /* Tạo một Update Event bằng phần mềm để nạp giá trị từ PSC/ARR/CCR1 vào shadow register */
    TIM2->EGR |= TIM_EGR_UG;

    /* 7. Kích hoạt bộ đếm Timer */
    TIM2->CR1 |= TIM_CR1_CEN;
}

bool pwm_set_frequency(uint32_t frequency_hz)
{
    /* 1. Boundary check: kiểm tra dải tần số hợp lệ */
    if (frequency_hz < PWM_MIN_FREQ_HZ || frequency_hz > PWM_MAX_FREQ_HZ) {
        return false;
    }

    uint64_t arr_old = (uint64_t)TIM2->ARR;
    uint64_t ccr_old = (uint64_t)TIM2->CCR1;
    uint64_t period_old = arr_old + 1ULL;

    /*
     * 2. Tính số ticks cho chu kỳ mới:
     * period_new = round(TIMER_TICK_RATE_HZ / frequency_hz)
     */
    uint64_t period_new = (TIMER_TICK_RATE_HZ + ((uint64_t)frequency_hz / 2ULL)) / (uint64_t)frequency_hz;
    if (period_new == 0ULL) {
        return false;
    }
    uint32_t arr_new = (uint32_t)(period_new - 1ULL);

    /*
     * 3. Tính toán CCR mới bảo toàn trực tiếp tỉ lệ ratio:
     * CCR_new = round(CCR_old * period_new / period_old)
     */
    uint32_t ccr_new = 0U;

    if (ccr_old == 0ULL) {
        /* Giữ nguyên trạng thái 0% duty (luôn LOW) */
        ccr_new = 0U;
    } else if (ccr_old >= period_old) {
        /* Giữ nguyên trạng thái 100% duty (luôn HIGH: CCR > ARR) */
        ccr_new = arr_new + 1U;
    } else {
        /* Tính tỉ lệ với rounding (+ period_old / 2) trên không gian số 64-bit */
        uint64_t ccr_calc = (ccr_old * period_new + (period_old / 2ULL)) / period_old;
        ccr_new = (uint32_t)ccr_calc;
    }

    /* 4. Cập nhật vào Preload registers */
    TIM2->ARR = arr_new;
    TIM2->CCR1 = ccr_new;

    return true;
}

bool pwm_set_duty_cycle(uint32_t duty_percent)
{
    if (duty_percent > 100U) {
        return false;
    }

    uint32_t current_arr = TIM2->ARR;

    if (duty_percent == 0U) {
        TIM2->CCR1 = 0U;
    } else if (duty_percent == 100U) {
        TIM2->CCR1 = current_arr + 1U;
    } else {
        uint64_t period = (uint64_t)current_arr + 1ULL;
        uint64_t ccr_calc = ((period * (uint64_t)duty_percent) + 50ULL) / 100ULL;
        TIM2->CCR1 = (uint32_t)ccr_calc;
    }

    return true;
}

uint32_t pwm_get_frequency(void)
{
    /* Đọc chu kỳ hiện tại: period = ARR + 1 */
    uint64_t period = (uint64_t)TIM2->ARR + 1ULL;
    if (period == 0ULL) {
        return 0U;
    }

    /*
     * f_PWM = round(TIMER_TICK_RATE_HZ / period)
     * Thêm (period / 2) để làm tròn số nguyên gần nhất
     */
    uint64_t freq = (TIMER_TICK_RATE_HZ + (period / 2ULL)) / period;
    return (uint32_t)freq;
}

uint32_t pwm_get_duty_cycle(void)
{
    uint64_t arr = (uint64_t)TIM2->ARR;
    uint64_t ccr = (uint64_t)TIM2->CCR1;
    uint64_t period = arr + 1ULL;

    /* 1. Xử lý biên 0% (CCR = 0) */
    if (ccr == 0ULL) {
        return 0U;
    }

    /* 2. Xử lý biên 100% (CCR >= ARR + 1: CNT luôn < CCR nên output luôn HIGH) */
    if (ccr >= period) {
        return 100U;
    }

    /*
     * 3. Tính duty cycle thực tế dưới dạng percentage:
     * duty = round((CCR * 100) / period)
     * Thêm (period / 2) để làm tròn chính xác
     */
    uint64_t duty = ((ccr * 100ULL) + (period / 2ULL)) / period;

    /* Kẹp trần an toàn không vượt quá 100% */
    if (duty > 100ULL) {
        duty = 100ULL;
    }

    return (uint32_t)duty;
}
