#include "rx_ring_buffer.h"

void rx_ring_buffer_init(rx_ring_buffer_t *buffer)
{
    /* TODO(learner): establish the documented empty-state invariants. */
    (void)buffer;
}

bool rx_ring_buffer_push(rx_ring_buffer_t *buffer, uint8_t byte)
{
    /* TODO(learner): implement bounded producer-side state transitions. */
    (void)buffer;
    (void)byte;
    return false;
}

bool rx_ring_buffer_pop(rx_ring_buffer_t *buffer, uint8_t *out_byte)
{
    /* TODO(learner): implement bounded consumer-side state transitions. */
    (void)buffer;
    (void)out_byte;
    return false;
}

bool rx_ring_buffer_is_empty(const rx_ring_buffer_t *buffer)
{
    /* TODO(learner): report empty state from the chosen invariants. */
    (void)buffer;
    return false;
}

bool rx_ring_buffer_is_full(const rx_ring_buffer_t *buffer)
{
    /* TODO(learner): report full state without confusing it with empty. */
    (void)buffer;
    return false;
}

size_t rx_ring_buffer_count(const rx_ring_buffer_t *buffer)
{
    /* TODO(learner): return observable occupancy for host verification. */
    (void)buffer;
    return 0U;
}

uint32_t rx_ring_buffer_overflow_count(const rx_ring_buffer_t *buffer)
{
    /* TODO(learner): expose the bounded overflow/error counter. */
    (void)buffer;
    return 0U;
}

rx_ring_buffer_overflow_policy_t rx_ring_buffer_overflow_policy(void)
{
    /* TODO(learner): choose and document one policy before overflow closure. */
    return RX_RING_BUFFER_OVERFLOW_POLICY_UNDECIDED;
}
