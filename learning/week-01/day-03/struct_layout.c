#include "struct_layout.h"

layout_info_t inspect_layout_a(void)
{
    layout_info_t info = {0};

    /* TODO: fill from sizeof, _Alignof and offsetof. Do not hard-code numbers. */

    return info;
}

layout_info_t inspect_layout_b(void)
{
    layout_info_t info = {0};

    /* TODO: fill from sizeof, _Alignof and offsetof. Do not hard-code numbers. */

    return info;
}

uint16_t byte_swap_u16(uint16_t value)
{
    (void)value;

    /* TODO: implement without compiler byte-swap built-ins. */
    return 0u;
}

uint32_t byte_swap_u32(uint32_t value)
{
    (void)value;

    /* TODO: implement without compiler byte-swap built-ins. */
    return 0u;
}

endian_kind_t detect_host_endian(void)
{
    /* TODO: inspect object representation without union-punning shortcut. */
    return ENDIAN_UNKNOWN;
}
