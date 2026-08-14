#include "ring_buffer.h"

#include <stdbool.h>
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

static bool push_values(
    ring_buffer_t *rb,
    const uint8_t *values,
    size_t length
)
{
    for (size_t i = 0u; i < length; ++i) {
        if (!rb_push(rb, values[i])) {
            return false;
        }
    }

    return true;
}

static bool pop_matches(
    ring_buffer_t *rb,
    const uint8_t *expected,
    size_t length
)
{
    for (size_t i = 0u; i < length; ++i) {
        uint8_t actual = 0u;
        if (!rb_pop(rb, &actual) || actual != expected[i]) {
            return false;
        }
    }

    return true;
}

static void test_fresh_buffer(void)
{
    ring_buffer_t rb;
    memset(&rb, 0xa5, sizeof(rb));

    CHECK("D05-T01 initialize valid buffer", rb_init(&rb));
    CHECK("D05-T02 fresh buffer reports empty", rb_is_empty(&rb));
    CHECK("D05-T03 fresh buffer does not report full", !rb_is_full(&rb));
    CHECK("D05-T04 fresh buffer size is zero", rb_size(&rb) == 0u);
    CHECK("D05-T05 valid buffer reports named capacity",
          rb_capacity(&rb) == RB_CAPACITY);
}

static void test_push_one_pop_one(void)
{
    ring_buffer_t rb = {0};
    uint8_t out = 0u;
    (void)rb_init(&rb);

    CHECK("D05-T06 push one succeeds", rb_push(&rb, UINT8_C(0xa5)));
    CHECK("D05-T07 one item updates size and empty state",
          rb_size(&rb) == 1u && !rb_is_empty(&rb));
    CHECK("D05-T08 pop one returns the pushed value",
          rb_pop(&rb, &out) && out == UINT8_C(0xa5));
    CHECK("D05-T09 one push and pop restores empty state",
          rb_is_empty(&rb) && rb_size(&rb) == 0u);
}

static void test_multiple_fifo(void)
{
    static const uint8_t values[] = {
        UINT8_C(0x11), UINT8_C(0x22), UINT8_C(0x33)
    };
    ring_buffer_t rb = {0};
    (void)rb_init(&rb);

    CHECK("D05-T10 multiple pushes succeed",
          push_values(&rb, values, sizeof(values) / sizeof(values[0])));
    CHECK("D05-T11 multiple pushes update size", rb_size(&rb) == 3u);
    CHECK("D05-T12 multiple elements preserve FIFO order",
          pop_matches(&rb, values, sizeof(values) / sizeof(values[0])));
    CHECK("D05-T13 FIFO drain leaves buffer empty", rb_is_empty(&rb));
}

static void test_empty_rejection(void)
{
    ring_buffer_t rb = {0};
    uint8_t out = UINT8_C(0xcc);
    bool accepted;
    (void)rb_init(&rb);

    accepted = rb_pop(&rb, &out);
    CHECK("D05-T14 pop on empty fails", !accepted);
    CHECK("D05-T15 failed empty pop preserves output sentinel",
          out == UINT8_C(0xcc));
    CHECK("D05-T16 failed empty pop preserves observable state",
          rb_is_empty(&rb) && !rb_is_full(&rb) && rb_size(&rb) == 0u);

    out = 0u;
    CHECK("D05-T17 failed empty pop preserves later FIFO behavior",
          rb_push(&rb, UINT8_C(0x6b)) && rb_pop(&rb, &out) &&
              out == UINT8_C(0x6b) && rb_is_empty(&rb));
}

static void test_full_rejection(void)
{
    static const uint8_t values[RB_CAPACITY] = {
        UINT8_C(0x10), UINT8_C(0x20), UINT8_C(0x30), UINT8_C(0x40)
    };
    ring_buffer_t rb = {0};
    bool accepted;
    (void)rb_init(&rb);

    CHECK("D05-T18 fill exactly to capacity succeeds",
          push_values(&rb, values, RB_CAPACITY));
    CHECK("D05-T19 exact fill reports capacity size",
          rb_size(&rb) == RB_CAPACITY);
    CHECK("D05-T20 exact fill reports full", rb_is_full(&rb));

    accepted = rb_push(&rb, UINT8_C(0xee));
    CHECK("D05-T21 push while full fails", !accepted);
    CHECK("D05-T22 failed full push preserves size and full state",
          rb_size(&rb) == RB_CAPACITY && rb_is_full(&rb));
    CHECK("D05-T23 failed full push preserves existing FIFO data",
          pop_matches(&rb, values, RB_CAPACITY));
    CHECK("D05-T24 draining preserved full data leaves buffer empty",
          rb_is_empty(&rb) && rb_size(&rb) == 0u);
}

static void test_write_wrap(void)
{
    static const uint8_t initial[RB_CAPACITY] = {
        UINT8_C(0x01), UINT8_C(0x02), UINT8_C(0x03), UINT8_C(0x04)
    };
    static const uint8_t expected[RB_CAPACITY] = {
        UINT8_C(0x03), UINT8_C(0x04), UINT8_C(0x05), UINT8_C(0x06)
    };
    ring_buffer_t rb = {0};
    uint8_t out = 0u;
    bool operations_ok;
    (void)rb_init(&rb);

    operations_ok = push_values(&rb, initial, RB_CAPACITY);
    operations_ok = operations_ok && rb_pop(&rb, &out) &&
                    out == UINT8_C(0x01);
    operations_ok = operations_ok && rb_pop(&rb, &out) &&
                    out == UINT8_C(0x02);
    operations_ok = operations_ok && rb_push(&rb, UINT8_C(0x05));
    operations_ok = operations_ok && rb_push(&rb, UINT8_C(0x06));

    CHECK("D05-T25 write position wraps through public operations",
          operations_ok && rb_is_full(&rb));
    CHECK("D05-T26 FIFO order survives write wrap",
          pop_matches(&rb, expected, RB_CAPACITY));
}

static void test_read_wrap(void)
{
    static const uint8_t initial[RB_CAPACITY] = {
        UINT8_C(0x31), UINT8_C(0x32), UINT8_C(0x33), UINT8_C(0x34)
    };
    static const uint8_t after_wrap[] = {UINT8_C(0x41), UINT8_C(0x42)};
    ring_buffer_t rb = {0};
    bool operations_ok;
    (void)rb_init(&rb);

    operations_ok = push_values(&rb, initial, RB_CAPACITY);
    operations_ok = operations_ok && pop_matches(&rb, initial, RB_CAPACITY);
    operations_ok = operations_ok && push_values(
        &rb,
        after_wrap,
        sizeof(after_wrap) / sizeof(after_wrap[0])
    );

    CHECK("D05-T27 read position wraps through public operations",
          operations_ok && rb_size(&rb) == 2u);
    CHECK("D05-T28 FIFO order survives read wrap",
          pop_matches(
              &rb,
              after_wrap,
              sizeof(after_wrap) / sizeof(after_wrap[0])
          ));
}

static void test_repeated_wrap_cycles(void)
{
    ring_buffer_t rb = {0};
    bool cycles_ok = true;
    (void)rb_init(&rb);

    for (size_t cycle = 0u; cycle < 5u && cycles_ok; ++cycle) {
        for (size_t i = 0u; i < RB_CAPACITY && cycles_ok; ++i) {
            uint8_t value = (uint8_t)(cycle * RB_CAPACITY + i);
            cycles_ok = rb_push(&rb, value);
        }

        for (size_t i = 0u; i < RB_CAPACITY && cycles_ok; ++i) {
            uint8_t expected = (uint8_t)(cycle * RB_CAPACITY + i);
            uint8_t actual = UINT8_C(0xff);
            cycles_ok = rb_pop(&rb, &actual) && actual == expected;
        }
    }

    CHECK("D05-T29 repeated wrap cycles preserve FIFO order", cycles_ok);
    CHECK("D05-T30 repeated wrap cycles finish empty",
          rb_is_empty(&rb) && rb_size(&rb) == 0u);
}

static void test_invalid_input(void)
{
    ring_buffer_t rb = {0};
    uint8_t out = UINT8_C(0x7e);
    uint8_t recovered = 0u;
    (void)rb_init(&rb);

    CHECK("D05-T31 reject init NULL", !rb_init(NULL));
    CHECK("D05-T32 reject push NULL", !rb_push(NULL, UINT8_C(0x55)));
    CHECK("D05-T33 reject pop NULL buffer", !rb_pop(NULL, &out));

    (void)rb_push(&rb, UINT8_C(0x5a));
    CHECK("D05-T34 reject pop NULL output", !rb_pop(&rb, NULL));
    CHECK("D05-T35 NULL output rejection preserves FIFO state and data",
          rb_size(&rb) == 1u && rb_pop(&rb, &recovered) &&
              recovered == UINT8_C(0x5a));
    CHECK("D05-T36 NULL queries follow safe-failure contract",
          !rb_is_empty(NULL) && !rb_is_full(NULL) && rb_size(NULL) == 0u &&
              rb_capacity(NULL) == 0u);
}

int main(void)
{
    test_fresh_buffer();
    test_push_one_pop_one();
    test_multiple_fifo();
    test_empty_rejection();
    test_full_rejection();
    test_write_wrap();
    test_read_wrap();
    test_repeated_wrap_cycles();
    test_invalid_input();

    printf("SUMMARY: %d tests, %d failed\n", tests_run, tests_failed);
    return tests_failed == 0 ? 0 : 1;
}
