#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define RB_CAPACITY 4u

typedef struct {
    uint8_t storage[RB_CAPACITY];
    size_t head;
    size_t tail;
    size_t count;
} ring_buffer_t;

/* Initialize a valid buffer as empty. Return false when rb is NULL. */
bool rb_init(ring_buffer_t *rb);

/*
 * Append one byte to the FIFO.
 * Return false and preserve the buffered data/state when rb is NULL or full.
 */
bool rb_push(ring_buffer_t *rb, uint8_t value);

/*
 * Remove the oldest byte from the FIFO and store it in *out.
 * Return false when either pointer is NULL or the buffer is empty. An empty
 * pop must preserve both the buffer state and the caller's output value.
 */
bool rb_pop(ring_buffer_t *rb, uint8_t *out);

/* NULL query pointers follow the documented safe-failure contract. */
bool rb_is_empty(const ring_buffer_t *rb);
bool rb_is_full(const ring_buffer_t *rb);
size_t rb_size(const ring_buffer_t *rb);
size_t rb_capacity(const ring_buffer_t *rb);

#endif
