#include "rx_ring_buffer.h"

void rx_ring_buffer_init(rx_ring_buffer_t *buffer)
{
    /* TODO(learner): establish the documented empty-state invariants. */
    if(buffer == NULL) return;
    buffer->count = 0U;
    buffer->head = 0U;
    buffer->tail = 0U;
    buffer->overflow_count = 0U;
}

bool rx_ring_buffer_push(rx_ring_buffer_t *buffer, uint8_t byte)
{
    /* TODO(learner): implement bounded producer-side state transitions. */
    if(buffer == NULL) return false;
    if(rx_ring_buffer_is_full(buffer)){
        buffer->overflow_count++;
        return false;
    }
    buffer->storage[buffer->head] = byte;
    buffer->head = (buffer->head + 1U) % RX_RING_BUFFER_CAPACITY;
    buffer->count++;
    return true;
}

bool rx_ring_buffer_pop(rx_ring_buffer_t *buffer, uint8_t *out_byte)
{
    /* TODO(learner): implement bounded consumer-side state transitions. */
    if(buffer == NULL || out_byte == NULL) return false;
    if(rx_ring_buffer_is_empty(buffer)){
        return false;
    }
    *out_byte = buffer->storage[buffer->tail];
    buffer->tail = (buffer->tail + 1U) % RX_RING_BUFFER_CAPACITY;
    buffer->count--;
    return true;
}

bool rx_ring_buffer_is_empty(const rx_ring_buffer_t *buffer)
{
    /* TODO(learner): report empty state from the chosen invariants. */
    if(buffer == NULL) return false;
    if(buffer->count == 0) return true;
    return false;
}

bool rx_ring_buffer_is_full(const rx_ring_buffer_t *buffer)
{
    /* TODO(learner): report full state without confusing it with empty. */
    if(buffer == NULL) return false;
    if(buffer->count == RX_RING_BUFFER_CAPACITY) return true;
    return false;
}

size_t rx_ring_buffer_count(const rx_ring_buffer_t *buffer)
{
    /* TODO(learner): return observable occupancy for host verification. */
    if(buffer == NULL) return false;
    return buffer->count;
}

uint32_t rx_ring_buffer_overflow_count(const rx_ring_buffer_t *buffer)
{
    /* TODO(learner): expose the bounded overflow/error counter. */
    if(buffer == NULL) return false;
    return buffer->overflow_count;
}

rx_ring_buffer_overflow_policy_t rx_ring_buffer_overflow_policy(void)
{
    /* TODO(learner): choose and document one policy before overflow closure. */
    return RX_RING_BUFFER_OVERFLOW_POLICY_DROP_NEWEST;
}
