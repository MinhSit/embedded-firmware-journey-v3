#ifndef RX_RING_BUFFER_H
#define RX_RING_BUFFER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define RX_RING_BUFFER_CAPACITY 8U

typedef enum {
    RX_RING_BUFFER_OVERFLOW_POLICY_UNDECIDED = 0,
    RX_RING_BUFFER_OVERFLOW_POLICY_DROP_NEWEST,
    RX_RING_BUFFER_OVERFLOW_POLICY_OVERWRITE_OLDEST
} rx_ring_buffer_overflow_policy_t;

typedef struct {
    uint8_t storage[RX_RING_BUFFER_CAPACITY];
    size_t head;
    size_t tail;
    size_t count;
    uint32_t overflow_count;
} rx_ring_buffer_t;

void rx_ring_buffer_init(rx_ring_buffer_t *buffer);
bool rx_ring_buffer_push(rx_ring_buffer_t *buffer, uint8_t byte);
bool rx_ring_buffer_pop(rx_ring_buffer_t *buffer, uint8_t *out_byte);
bool rx_ring_buffer_is_empty(const rx_ring_buffer_t *buffer);
bool rx_ring_buffer_is_full(const rx_ring_buffer_t *buffer);
size_t rx_ring_buffer_count(const rx_ring_buffer_t *buffer);
uint32_t rx_ring_buffer_overflow_count(const rx_ring_buffer_t *buffer);
rx_ring_buffer_overflow_policy_t rx_ring_buffer_overflow_policy(void);

#endif
