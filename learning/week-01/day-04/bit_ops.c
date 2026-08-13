#include "bit_ops.h"

bool bit_set_u32(uint32_t *value, uint8_t bit)
{
    /* TODO: Validate the inputs and implement the operation safely. */
    if(value == NULL || bit > 31) return false;
    uint32_t mask = 1u << bit;
    *value = *value | mask;
    return true;
}

bool bit_clear_u32(uint32_t *value, uint8_t bit)
{
    /* TODO: Validate the inputs and implement the operation safely. */
    if(value == NULL || bit > 31) return false;
    uint32_t mask = 1u << bit;
    *value = *value & ~mask;
    return true;
}

bool bit_extract_u32(
    uint32_t value,
    uint8_t lsb,
    uint8_t width,
    uint32_t *out
)
{
    /* TODO: Validate the inputs and implement the operation safely. */
    if(lsb != 0 && width == 32) return false;
    if(width < 1 || width > 32 || lsb > 31) return false;
    if(out == NULL || lsb + width > 32) return false;
    uint32_t mask = 0u;
    uint32_t *p = &mask;
    for(uint8_t i = lsb; i < lsb + width; i++){
        bit_set_u32(p, i);
    }
    value = value & mask;
    *out = value >> lsb;
    return true;
}

bool bit_update_u32(
    uint32_t *value,
    uint8_t lsb,
    uint8_t width,
    uint32_t field_value
)
{
    /* TODO: Validate the inputs and implement the operation safely. */
    if(lsb != 0 && width == 32) return false;
    if(width < 1 || width > 32 || lsb > 31) return false;
    if(value == NULL || lsb + width > 32) return false;
    if(width < 32 && field_value >> width > 0 ) return false;
    for(uint8_t i = lsb; i < lsb + width; i ++){
        bit_clear_u32(value, i);
    }
    uint32_t mask = field_value << lsb;
    *value = *value | mask;
    return true;
}
