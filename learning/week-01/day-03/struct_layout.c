#include "struct_layout.h"

layout_info_t inspect_layout_a(void)
{
    layout_info_t info = {0};

    info.size = sizeof(layout_a_t);
    info.alignment = _Alignof(layout_a_t);
    info.offset_tag = offsetof(layout_a_t, tag);
    info.offset_value = offsetof(layout_a_t, value);
    info.offset_code = offsetof(layout_a_t, code);
    return info;
}

layout_info_t inspect_layout_b(void)
{
    layout_info_t info = {0};

    info.size = sizeof(layout_b_t);
    info.alignment = _Alignof(layout_b_t);
    info.offset_tag = offsetof(layout_b_t, tag);
    info.offset_value = offsetof(layout_b_t, value);
    info.offset_code = offsetof(layout_b_t, code);
    return info;
}

uint16_t byte_swap_u16(uint16_t value)
{
    uint16_t low = value & 0x00FF;
    uint16_t high = value & 0xFF00;
    low = low << 8;
    high = high >> 8;
    value = low | high;
    return value;
}

uint32_t byte_swap_u32(uint32_t value)
{
    uint32_t byte0 = value & 0x000000FF;
    uint32_t byte1 = value & 0x0000FF00;
    uint32_t byte2 = value & 0x00FF0000;
    uint32_t byte3 = value & 0xFF000000;
    byte0 = byte0 << 24;
    byte1 = byte1 << 8;
    byte2 = byte2 >> 8;
    byte3 = byte3 >> 24;
    value = byte0 | byte1 | byte2 | byte3;
    return value;
}

endian_kind_t detect_host_endian(void)
{
    uint32_t value = 0x01020304;
    unsigned char *c = (unsigned char *) & value;
    if(c[0] == 0x01) return ENDIAN_BIG;
    if(c[0] == 0x04) return ENDIAN_LITTLE;
    return ENDIAN_UNKNOWN;
}
