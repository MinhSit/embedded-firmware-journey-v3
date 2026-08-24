#ifndef UART_POLLING_H
#define UART_POLLING_H

#include <stdint.h>

/*
 * W03D01 learner-owned interface.
 *
 * The learner must derive the active USART peripheral clock, select and
 * verify the board signal path, configure the peripheral, derive the baud
 * divider, and implement both polling data paths from official sources.
 */
void uart_polling_init(uint32_t peripheral_clock_hz, uint32_t baud_rate);
void uart_polling_write_byte(uint8_t byte);
uint8_t uart_polling_read_byte(void);

#endif
