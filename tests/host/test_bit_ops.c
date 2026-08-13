#include "bit_ops.h"

#include <stdint.h>
#include <stdio.h>

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

static void test_bit_set(void)
{
    uint32_t value = UINT32_C(0x00000000);
    bool accepted = bit_set_u32(&value, 0u);
    CHECK("D04-T01 set bit 0", accepted && value == UINT32_C(0x00000001));

    value = UINT32_C(0x00000000);
    accepted = bit_set_u32(&value, 31u);
    CHECK("D04-T02 set bit 31", accepted && value == UINT32_C(0x80000000));

    value = UINT32_C(0x00000080);
    accepted = bit_set_u32(&value, 7u);
    CHECK("D04-T03 set already-set bit",
          accepted && value == UINT32_C(0x00000080));

    value = UINT32_C(0xa5a5a5a5);
    accepted = bit_set_u32(&value, 32u);
    CHECK("D04-T04 reject set bit 32 and preserve value",
          !accepted && value == UINT32_C(0xa5a5a5a5));

    CHECK("D04-T05 reject set NULL", !bit_set_u32(NULL, 0u));
}

static void test_bit_clear(void)
{
    uint32_t value = UINT32_C(0xffffffff);
    bool accepted = bit_clear_u32(&value, 0u);
    CHECK("D04-T06 clear bit 0", accepted && value == UINT32_C(0xfffffffe));

    value = UINT32_C(0xffffffff);
    accepted = bit_clear_u32(&value, 31u);
    CHECK("D04-T07 clear bit 31", accepted && value == UINT32_C(0x7fffffff));

    value = UINT32_C(0xffffff7f);
    accepted = bit_clear_u32(&value, 7u);
    CHECK("D04-T08 clear already-clear bit",
          accepted && value == UINT32_C(0xffffff7f));

    value = UINT32_C(0x5a5a5a5a);
    accepted = bit_clear_u32(&value, 32u);
    CHECK("D04-T09 reject clear bit 32 and preserve value",
          !accepted && value == UINT32_C(0x5a5a5a5a));

    CHECK("D04-T10 reject clear NULL", !bit_clear_u32(NULL, 31u));
}

static void test_bit_extract(void)
{
    uint32_t out = UINT32_C(0xcccccccc);
    bool accepted = bit_extract_u32(UINT32_C(0x00000010), 4u, 1u, &out);
    CHECK("D04-T11 extract single bit", accepted && out == UINT32_C(0x1));

    out = UINT32_C(0xcccccccc);
    accepted = bit_extract_u32(UINT32_C(0xdeadbeef), 8u, 8u, &out);
    CHECK("D04-T12 extract middle field", accepted && out == UINT32_C(0xbe));

    out = UINT32_C(0xcccccccc);
    accepted = bit_extract_u32(UINT32_C(0xf1234567), 28u, 4u, &out);
    CHECK("D04-T13 extract field ending at bit 31",
          accepted && out == UINT32_C(0xf));

    out = UINT32_C(0xcccccccc);
    accepted = bit_extract_u32(UINT32_C(0x89abcdef), 0u, 32u, &out);
    CHECK("D04-T14 extract width 32", accepted && out == UINT32_C(0x89abcdef));

    out = UINT32_C(0x13579bdf);
    accepted = bit_extract_u32(UINT32_C(0xffffffff), 0u, 0u, &out);
    CHECK("D04-T15 reject extract width 0 and preserve output",
          !accepted && out == UINT32_C(0x13579bdf));

    out = UINT32_C(0x13579bdf);
    accepted = bit_extract_u32(UINT32_C(0xffffffff), 32u, 1u, &out);
    CHECK("D04-T16 reject extract lsb 32 and preserve output",
          !accepted && out == UINT32_C(0x13579bdf));

    out = UINT32_C(0x13579bdf);
    accepted = bit_extract_u32(UINT32_C(0xffffffff), 31u, 2u, &out);
    CHECK("D04-T17 reject extract range crossing bit 31",
          !accepted && out == UINT32_C(0x13579bdf));

    CHECK("D04-T18 reject extract NULL output",
          !bit_extract_u32(UINT32_C(0xffffffff), 0u, 1u, NULL));

    out = UINT32_C(0x13579bdf);
    accepted = bit_extract_u32(UINT32_C(0xffffffff), 0u, 33u, &out);
    CHECK("D04-T19 reject extract width 33 and preserve output",
          !accepted && out == UINT32_C(0x13579bdf));

    out = UINT32_C(0xcccccccc);
    accepted = bit_extract_u32(UINT32_C(0x80000000), 31u, 1u, &out);
    CHECK("D04-T20 extract bit 31", accepted && out == UINT32_C(0x1));

    out = UINT32_C(0x13579bdf);
    accepted = bit_extract_u32(UINT32_C(0xffffffff), 1u, 32u, &out);
    CHECK("D04-T21 reject extract width 32 with nonzero lsb",
          !accepted && out == UINT32_C(0x13579bdf));
}

static void test_bit_update(void)
{
    uint32_t value = UINT32_C(0xffffffff);
    bool accepted = bit_update_u32(&value, 8u, 8u, UINT32_C(0x00));
    CHECK("D04-T22 update middle field",
          accepted && value == UINT32_C(0xffff00ff));

    value = UINT32_C(0xfffffff0);
    accepted = bit_update_u32(&value, 0u, 4u, UINT32_C(0x0a));
    CHECK("D04-T23 update field at bit 0",
          accepted && value == UINT32_C(0xfffffffa));

    value = UINT32_C(0x00000000);
    accepted = bit_update_u32(&value, 28u, 4u, UINT32_C(0x0f));
    CHECK("D04-T24 update field ending at bit 31",
          accepted && value == UINT32_C(0xf0000000));

    value = UINT32_C(0xffffffff);
    accepted = bit_update_u32(&value, 0u, 32u, UINT32_C(0x12345678));
    CHECK("D04-T25 update width 32",
          accepted && value == UINT32_C(0x12345678));

    value = UINT32_C(0x00000000);
    accepted = bit_update_u32(&value, 4u, 4u, UINT32_C(0x0f));
    CHECK("D04-T26 update maximum fitting field value",
          accepted && value == UINT32_C(0x000000f0));

    value = UINT32_C(0x2468ace0);
    accepted = bit_update_u32(&value, 4u, 4u, UINT32_C(0x10));
    CHECK("D04-T27 reject oversized field value and preserve word",
          !accepted && value == UINT32_C(0x2468ace0));

    value = UINT32_C(0x2468ace0);
    accepted = bit_update_u32(&value, 0u, 0u, UINT32_C(0x00));
    CHECK("D04-T28 reject update width 0 and preserve word",
          !accepted && value == UINT32_C(0x2468ace0));

    value = UINT32_C(0x2468ace0);
    accepted = bit_update_u32(&value, 31u, 2u, UINT32_C(0x00));
    CHECK("D04-T29 reject update range crossing bit 31",
          !accepted && value == UINT32_C(0x2468ace0));

    CHECK("D04-T30 reject update NULL",
          !bit_update_u32(NULL, 0u, 1u, UINT32_C(0x1)));

    value = UINT32_C(0xa5a55aa5);
    accepted = bit_update_u32(&value, 12u, 8u, UINT32_C(0x3c));
    CHECK("D04-T31 update preserves non-target bits",
          accepted &&
              (value & UINT32_C(0xfff00fff)) ==
                  (UINT32_C(0xa5a55aa5) & UINT32_C(0xfff00fff)) &&
              (value & UINT32_C(0x000ff000)) == UINT32_C(0x0003c000));

    value = UINT32_C(0x2468ace0);
    accepted = bit_update_u32(&value, 32u, 1u, UINT32_C(0x0));
    CHECK("D04-T32 reject update lsb 32 and preserve word",
          !accepted && value == UINT32_C(0x2468ace0));

    value = UINT32_C(0x00000000);
    accepted = bit_update_u32(&value, 31u, 1u, UINT32_C(0x1));
    CHECK("D04-T33 update bit 31", accepted && value == UINT32_C(0x80000000));

    value = UINT32_C(0x2468ace0);
    accepted = bit_update_u32(&value, 1u, 32u, UINT32_C(0x12345678));
    CHECK("D04-T34 reject update width 32 with nonzero lsb",
          !accepted && value == UINT32_C(0x2468ace0));
}

int main(void)
{
    test_bit_set();
    test_bit_clear();
    test_bit_extract();
    test_bit_update();

    printf("SUMMARY: %d tests, %d failed\n", tests_run, tests_failed);
    return tests_failed == 0 ? 0 : 1;
}
