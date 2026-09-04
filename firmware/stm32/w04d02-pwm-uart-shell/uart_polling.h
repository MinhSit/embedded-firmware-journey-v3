#ifndef UART_POLLING_H
#define UART_POLLING_H

#include <stdint.h>
#include <stdbool.h>

/*
 * W03D01 learner-owned interface.
 *
 * The learner must derive the active USART peripheral clock, select and
 * verify the board signal path, configure the peripheral, derive the baud
 * divider, and implement both polling data paths from official sources.
 */
void uart_init(uint32_t peripheral_clock_hz, uint32_t baud_rate);
void uart_write_byte(uint8_t byte);
bool uart_rx_get_byte(uint8_t *out_byte);

#endif
