#ifndef STRUCT_LAYOUT_H
#define STRUCT_LAYOUT_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t tag;
    uint32_t value;
    uint16_t code;
} layout_a_t;

typedef struct {
    uint32_t value;
    uint16_t code;
    uint8_t tag;
} layout_b_t;

typedef union {
    uint32_t word;
    unsigned char bytes[sizeof(uint32_t)];
} u32_view_t;

typedef enum {
    ENDIAN_UNKNOWN = 0,
    ENDIAN_LITTLE = 1,
    ENDIAN_BIG = 2
} endian_kind_t;

typedef struct {
    size_t size;
    size_t alignment;
    size_t offset_tag;
    size_t offset_value;
    size_t offset_code;
} layout_info_t;

layout_info_t inspect_layout_a(void);
layout_info_t inspect_layout_b(void);
uint16_t byte_swap_u16(uint16_t value);
uint32_t byte_swap_u32(uint32_t value);
endian_kind_t detect_host_endian(void);

#endif
