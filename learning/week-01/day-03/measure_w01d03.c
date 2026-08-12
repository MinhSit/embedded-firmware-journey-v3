#include <stdio.h>
#include <stdint.h>

#include "struct_layout.h"

int main(void)
{
    printf("sizeof(u32_view_t): %zu\n", sizeof(u32_view_t));
    printf("_Alignof(u32_view_t): %zu\n", _Alignof(u32_view_t));

    uint32_t value = 0x01020304u;
    unsigned char *bytes = (unsigned char *)&value;

    printf("bytes:");
    for (size_t i = 0; i < sizeof(value); ++i) {
        printf(" %02X", bytes[i]);
    }
    printf("\n");

    printf("detected endian enum: %d\n", (int)detect_host_endian());

    return 0;
}
