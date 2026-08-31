#include <stdint.h>
#include "uart_polling.h"

int main(void)
{
    uint32_t pclk1_hz = 16000000U;
    uint32_t baud = 115200U;

    uart_polling_init(pclk1_hz, baud);

    while (1) {
        uint8_t received_byte = uart_polling_read_byte();
        uart_polling_write_byte(received_byte);
    }

    return 0;
}