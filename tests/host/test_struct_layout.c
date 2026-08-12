#include "struct_layout.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static int tests_run = 0;
static int tests_failed = 0;

#define CHECK(name, condition)                                                   \
    do {                                                                         \
        ++tests_run;                                                             \
        if (!(condition)) {                                                      \
            ++tests_failed;                                                      \
            printf("FAIL: %s\n", (name));                                       \
        } else {                                                                 \
            printf("PASS: %s\n", (name));                                       \
        }                                                                        \
    } while (0)

static endian_kind_t expected_host_endian(void)
{
    const uint32_t value = UINT32_C(0x01020304);
    unsigned char bytes[sizeof(value)] = {0};

    memcpy(bytes, &value, sizeof(value));

    if (bytes[0] == 0x04u) {
        return ENDIAN_LITTLE;
    }
    if (bytes[0] == 0x01u) {
        return ENDIAN_BIG;
    }
    return ENDIAN_UNKNOWN;
}

static void test_layout_a(void)
{
    const layout_info_t info = inspect_layout_a();

    CHECK("D03-T01 A size", info.size == sizeof(layout_a_t));
    CHECK("D03-T01 A alignment", info.alignment == _Alignof(layout_a_t));
    CHECK("D03-T01 A tag offset", info.offset_tag == offsetof(layout_a_t, tag));
    CHECK("D03-T01 A value offset", info.offset_value == offsetof(layout_a_t, value));
    CHECK("D03-T01 A code offset", info.offset_code == offsetof(layout_a_t, code));
    CHECK("D03-T03 A value aligned",
          (offsetof(layout_a_t, value) % _Alignof(uint32_t)) == 0u);
    CHECK("D03-T03 A code aligned",
          (offsetof(layout_a_t, code) % _Alignof(uint16_t)) == 0u);
}

static void test_layout_b(void)
{
    const layout_info_t info = inspect_layout_b();

    CHECK("D03-T02 B size", info.size == sizeof(layout_b_t));
    CHECK("D03-T02 B alignment", info.alignment == _Alignof(layout_b_t));
    CHECK("D03-T02 B tag offset", info.offset_tag == offsetof(layout_b_t, tag));
    CHECK("D03-T02 B value offset", info.offset_value == offsetof(layout_b_t, value));
    CHECK("D03-T02 B code offset", info.offset_code == offsetof(layout_b_t, code));
    CHECK("D03-T03 B value aligned",
          (offsetof(layout_b_t, value) % _Alignof(uint32_t)) == 0u);
    CHECK("D03-T03 B code aligned",
          (offsetof(layout_b_t, code) % _Alignof(uint16_t)) == 0u);
}

static void test_union_storage(void)
{
    u32_view_t value;

    CHECK("D03-T04 union contains uint32_t", sizeof(value) >= sizeof(uint32_t));
    CHECK("D03-T04 union members share start address",
          (void *)&value.word == (void *)&value.bytes[0]);
}

static void test_swap_u16(void)
{
    CHECK("D03-T05 swap16 known", byte_swap_u16(UINT16_C(0x1234)) == UINT16_C(0x3412));
    CHECK("D03-T06 swap16 zero", byte_swap_u16(UINT16_C(0x0000)) == UINT16_C(0x0000));
    CHECK("D03-T06 swap16 ones", byte_swap_u16(UINT16_C(0xffff)) == UINT16_C(0xffff));
    CHECK("D03-T07 swap16 involution",
          byte_swap_u16(byte_swap_u16(UINT16_C(0xa501))) == UINT16_C(0xa501));
}

static void test_swap_u32(void)
{
    CHECK("D03-T08 swap32 known",
          byte_swap_u32(UINT32_C(0x11223344)) == UINT32_C(0x44332211));
    CHECK("D03-T09 swap32 zero",
          byte_swap_u32(UINT32_C(0x00000000)) == UINT32_C(0x00000000));
    CHECK("D03-T09 swap32 ones",
          byte_swap_u32(UINT32_C(0xffffffff)) == UINT32_C(0xffffffff));
    CHECK("D03-T10 swap32 involution",
          byte_swap_u32(byte_swap_u32(UINT32_C(0x89abcdef))) == UINT32_C(0x89abcdef));
}

static void test_endian_detection(void)
{
    CHECK("D03-T11 host endian", detect_host_endian() == expected_host_endian());
}

int main(void)
{
    test_layout_a();
    test_layout_b();
    test_union_storage();
    test_swap_u16();
    test_swap_u32();
    test_endian_detection();

    printf("SUMMARY: %d tests, %d failed\n", tests_run, tests_failed);
    return tests_failed == 0 ? 0 : 1;
}
