#include "uart_polling.h"
#include <stdint.h>
#include <stdbool.h>

int main(void)
{
    uart_init(16000000U, 115200U);

    uint8_t rx_data = 0U;

    while (1) {
        if (uart_rx_get_byte(&rx_data)) {
            uart_write_byte(rx_data);
        }
    }

    return 0;
}
