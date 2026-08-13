#ifndef BIT_OPS_H
#define BIT_OPS_H

#include <stdbool.h>
#include <stdint.h>

/*
 * Set one bit in *value.
 *
 * Valid bit indexes are 0..31. On NULL or an invalid bit index, return false
 * and leave the destination unchanged.
 */
bool bit_set_u32(uint32_t *value, uint8_t bit);

/*
 * Clear one bit in *value.
 *
 * Valid bit indexes are 0..31. On NULL or an invalid bit index, return false
 * and leave the destination unchanged.
 */
bool bit_clear_u32(uint32_t *value, uint8_t bit);

/*
 * Extract width bits beginning at lsb and normalize the result to bit 0.
 *
 * Valid width values are 1..32, and the complete field must lie within a
 * uint32_t. width == 32 is valid only when lsb == 0. On failure, return false
 * and leave *out unchanged.
 */
bool bit_extract_u32(
    uint32_t value,
    uint8_t lsb,
    uint8_t width,
    uint32_t *out
);

/*
 * Replace width bits beginning at lsb with field_value.
 *
 * The range rules are the same as bit_extract_u32. field_value must fit in
 * width bits; width == 32 accepts any uint32_t. On failure, return false and
 * leave *value unchanged. On success, bits outside the field are unchanged.
 */
bool bit_update_u32(
    uint32_t *value,
    uint8_t lsb,
    uint8_t width,
    uint32_t field_value
);

#endif
