#include "uart_polling.h"
#include "pwm.h"
#include <stdint.h>
#include <stdbool.h>

#define SHELL_MAX_LINE_LEN 64U

static void uart_send_str(const char *s)
{
    while (*s != '\0') {
        uart_write_byte((uint8_t)*s);
        s++;
    }
}

static void uart_send_u32(uint32_t val)
{
    char buf[11];
    int i = 0;
    if (val == 0U) {
        uart_write_byte((uint8_t)'0');
        return;
    }
    while (val > 0U) {
        buf[i++] = (char)('0' + (val % 10U));
        val /= 10U;
    }
    while (i > 0) {
        uart_write_byte((uint8_t)buf[--i]);
    }
}

static bool parse_u32(const char *s, uint32_t *out_val)
{
    if (s == 0 || *s == '\0') {
        return false;
    }
    uint32_t val = 0U;
    while (*s != '\0') {
        if (*s < '0' || *s > '9') {
            return false;
        }
        uint32_t digit = (uint32_t)(*s - '0');

        /* Kiểm tra tràn uint32 trước khi thực hiện val = val * 10 + digit */
        if (val > (UINT32_MAX / 10U)) {
            return false;
        }
        if (val == (UINT32_MAX / 10U) && digit > (UINT32_MAX % 10U)) {
            return false;
        }

        val = val * 10U + digit;
        s++;
    }
    *out_val = val;
    return true;
}

static bool str_starts_with(const char *str, const char *prefix)
{
    while (*prefix != '\0') {
        if (*str != *prefix) {
            return false;
        }
        str++;
        prefix++;
    }
    return true;
}

static bool str_equals(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return false;
        }
        s1++;
        s2++;
    }
    return (*s1 == '\0' && *s2 == '\0');
}

static void handle_pwm_command(const char *cmd)
{
    if (str_equals(cmd, "pwm status")) {
        uart_send_str("PWM Freq: ");
        uart_send_u32(pwm_get_frequency());
        uart_send_str(" Hz, Duty: ");
        uart_send_u32(pwm_get_duty_cycle());
        uart_send_str("%\r\n");
    } else if (str_starts_with(cmd, "pwm freq ")) {
        uint32_t freq = 0U;
        if (parse_u32(cmd + 9, &freq) && pwm_set_frequency(freq)) {
            uart_send_str("OK: Frequency set to ");
            uart_send_u32(pwm_get_frequency());
            uart_send_str(" Hz\r\n");
        } else {
            uart_send_str("ERR: Invalid frequency\r\n");
        }
    } else if (str_starts_with(cmd, "pwm duty ")) {
        uint32_t duty = 0U;
        if (parse_u32(cmd + 9, &duty) && pwm_set_duty_cycle(duty)) {
            uart_send_str("OK: Duty set to ");
            uart_send_u32(pwm_get_duty_cycle());
            uart_send_str("%\r\n");
        } else {
            uart_send_str("ERR: Invalid duty\r\n");
        }
    } else {
        uart_send_str("ERR: Unknown command\r\n");
    }
}

int main(void)
{
    /* Initialize USART2: 16 MHz APB1 peripheral clock, 115200 baud */
    uart_init(16000000U, 115200U);

    /* Initialize PWM peripheral */
    pwm_init();

    uart_send_str("W04D02 PWM UART Shell Ready\r\n");

    char line_buf[SHELL_MAX_LINE_LEN];
    uint32_t line_len = 0U;
    bool discarding_overlong = false;
    uint8_t rx_byte = 0U;

while (1) {
        if (uart_rx_get_byte(&rx_byte)) {
            if (rx_byte == '\r') {
                continue;
            }

            if (rx_byte == '\n') {
                if (discarding_overlong) {
                    /* Đã drain hết toàn bộ phần dư của dòng dài: resync hoàn tất, mới gửi phản hồi lỗi */
                    discarding_overlong = false;
                    line_len = 0U;
                    uart_send_str("ERR: Line too long\r\n");
                } else if (line_len > 0U) {
                    line_buf[line_len] = '\0';
                    handle_pwm_command(line_buf);
                    line_len = 0U;
                }
            } else {
                if (discarding_overlong) {
                    /* Bỏ qua nhanh từng byte dư thừa mà không block TX */
                    continue;
                }

                if (line_len < (SHELL_MAX_LINE_LEN - 1U)) {
                    line_buf[line_len++] = (char)rx_byte;
                } else {
                    /* Phát hiện quá giới hạn: chỉ bật cờ discard, không gọi hàm TX blocking */
                    discarding_overlong = true;
                    line_len = 0U;
                }
            }
        }
    }

    return 0;
}