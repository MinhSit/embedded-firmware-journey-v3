#include "ring_buffer.h"

bool rb_init(ring_buffer_t *rb)
{
    /* TODO: Validate rb and initialize the buffer state. */
    if(rb == NULL) return false;
    rb->count = 0;
    rb->head = 0;
    rb->tail = 0;
    return true;
}

bool rb_push(ring_buffer_t *rb, uint8_t value)
{
    /* TODO: Validate the request and implement push independently. */
    if(rb == NULL || rb->count == RB_CAPACITY) return false;
    rb->storage[rb->head] = value;
    rb->head = (rb->head + 1) % RB_CAPACITY;
    rb->count++;
    return true;
}

bool rb_pop(ring_buffer_t *rb, uint8_t *out)
{
    /* TODO: Validate the request and implement pop independently. */
    if(rb == NULL || rb->count == 0 || out == NULL) return false;
    *out = rb->storage[rb->tail];
    rb->tail = (rb->tail + 1) % RB_CAPACITY;
    rb->count--;
    return true;
}

bool rb_is_empty(const ring_buffer_t *rb)
{
    /* TODO: Implement the empty query and its NULL contract. */
    if(rb == NULL) return false;
    if(rb->count == 0) return true;
    return false;
}

bool rb_is_full(const ring_buffer_t *rb)
{
    /* TODO: Implement the full query and its NULL contract. */
    if(rb == NULL) return false;
    if(rb->count == RB_CAPACITY) return true;
    return false;
}

size_t rb_size(const ring_buffer_t *rb)
{
    /* TODO: Implement the size query and its NULL contract. */
    if(rb == NULL) return false;
    return rb->count;
}

size_t rb_capacity(const ring_buffer_t *rb)
{
    /* TODO: Implement the capacity query and its NULL contract. */
    if(rb == NULL) return false;
    return RB_CAPACITY;
}
