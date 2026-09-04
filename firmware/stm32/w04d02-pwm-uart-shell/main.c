#include "uart_polling.h"
#include "uart_parser.h"
#include "pwm.h"
#include <stdint.h>
#include <stdbool.h>

static void uart_send_str(const char *s)
{
    while (*s != '\0') {
        uart_write_byte((uint8_t)*s);
        s++;
    }
}

int main(void)
{
    /* Initialize USART2: 16 MHz APB1 peripheral clock, 115200 baud */
    uart_init(16000000U, 115200U);

    /* Initialize PWM peripheral (non-working starter stub) */
    pwm_init();

    /* Initialize UART command parser */
    uart_parser_t parser;
    uart_parser_init(&parser, 1000U);

    uart_send_str("W04D02 PWM UART Shell Starter\r\n");

    uint8_t rx_byte = 0U;
    uint32_t tick = 0U;

    while (1) {
        /* Check for received bytes from interrupt ring buffer */
        if (uart_rx_get_byte(&rx_byte)) {
            uart_parser_result_t result = uart_parser_feed(&parser, rx_byte, tick);
            (void)result;
            /*
             * TODO(learner): Handle parsed commands or integrate PWM frequency/duty
             * control from the shell. Do not implement dispatch until design is confirmed.
             */
        }

        uart_parser_result_t timeout_res = uart_parser_poll(&parser, tick);
        (void)timeout_res;

        tick++;
    }

    return 0;
}
