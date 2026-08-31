#include "rx_ring_buffer.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

static unsigned int g_tests_run = 0U;
static unsigned int g_tests_failed = 0U;

static void report(const char *id, const char *name, bool passed)
{
    ++g_tests_run;
    if (passed) {
        printf("PASS %s %s\n", id, name);
    } else {
        ++g_tests_failed;
        printf("FAIL %s %s\n", id, name);
    }
}

static bool test_init_empty(void)
{
    rx_ring_buffer_t buffer = {0};
    buffer.head = 3U;
    buffer.tail = 5U;
    buffer.count = 2U;
    buffer.overflow_count = 7U;

    rx_ring_buffer_init(&buffer);

    return rx_ring_buffer_is_empty(&buffer)
        && !rx_ring_buffer_is_full(&buffer)
        && (rx_ring_buffer_count(&buffer) == 0U)
        && (rx_ring_buffer_overflow_count(&buffer) == 0U);
}

static bool test_invalid_input(void)
{
    rx_ring_buffer_t buffer = {0};
    uint8_t out_byte = 0U;

    rx_ring_buffer_init(&buffer);
    const size_t before_count = rx_ring_buffer_count(&buffer);
    const uint32_t before_overflow = rx_ring_buffer_overflow_count(&buffer);

    return !rx_ring_buffer_push(NULL, 0xA5U)
        && !rx_ring_buffer_pop(NULL, &out_byte)
        && !rx_ring_buffer_pop(&buffer, NULL)
        && (rx_ring_buffer_count(NULL) == 0U)
        && (rx_ring_buffer_overflow_count(NULL) == 0U)
        && (rx_ring_buffer_count(&buffer) == before_count)
        && (rx_ring_buffer_overflow_count(&buffer) == before_overflow);
}

static bool test_normal_fifo(void)
{
    rx_ring_buffer_t buffer = {0};
    uint8_t out_byte = 0U;

    rx_ring_buffer_init(&buffer);

    return rx_ring_buffer_push(&buffer, 0x11U)
        && rx_ring_buffer_push(&buffer, 0x22U)
        && rx_ring_buffer_push(&buffer, 0x33U)
        && rx_ring_buffer_pop(&buffer, &out_byte) && (out_byte == 0x11U)
        && rx_ring_buffer_pop(&buffer, &out_byte) && (out_byte == 0x22U)
        && rx_ring_buffer_pop(&buffer, &out_byte) && (out_byte == 0x33U)
        && rx_ring_buffer_is_empty(&buffer);
}

static bool test_one_element_boundary(void)
{
    rx_ring_buffer_t buffer = {0};
    uint8_t out_byte = 0U;

    rx_ring_buffer_init(&buffer);

    return rx_ring_buffer_push(&buffer, 0x5AU)
        && !rx_ring_buffer_is_empty(&buffer)
        && !rx_ring_buffer_is_full(&buffer)
        && (rx_ring_buffer_count(&buffer) == 1U)
        && rx_ring_buffer_pop(&buffer, &out_byte)
        && (out_byte == 0x5AU)
        && rx_ring_buffer_is_empty(&buffer)
        && (rx_ring_buffer_count(&buffer) == 0U);
}

static bool test_exact_capacity_full(void)
{
    rx_ring_buffer_t buffer = {0};
    rx_ring_buffer_init(&buffer);

    for (size_t i = 0U; i < RX_RING_BUFFER_CAPACITY; ++i) {
        if (!rx_ring_buffer_push(&buffer, (uint8_t)i)) {
            return false;
        }
    }

    return rx_ring_buffer_is_full(&buffer)
        && !rx_ring_buffer_is_empty(&buffer)
        && (rx_ring_buffer_count(&buffer) == RX_RING_BUFFER_CAPACITY);
}

static bool test_wrap(void)
{
    rx_ring_buffer_t buffer = {0};
    uint8_t out_byte = 0U;
    const size_t half = RX_RING_BUFFER_CAPACITY / 2U;

    rx_ring_buffer_init(&buffer);

    for (size_t i = 0U; i < RX_RING_BUFFER_CAPACITY; ++i) {
        if (!rx_ring_buffer_push(&buffer, (uint8_t)i)) {
            return false;
        }
    }

    for (size_t i = 0U; i < half; ++i) {
        if (!rx_ring_buffer_pop(&buffer, &out_byte) || (out_byte != (uint8_t)i)) {
            return false;
        }
    }

    for (size_t i = 0U; i < half; ++i) {
        const uint8_t value = (uint8_t)(RX_RING_BUFFER_CAPACITY + i);
        if (!rx_ring_buffer_push(&buffer, value)) {
            return false;
        }
    }

    for (size_t i = half; i < (RX_RING_BUFFER_CAPACITY + half); ++i) {
        if (!rx_ring_buffer_pop(&buffer, &out_byte) || (out_byte != (uint8_t)i)) {
            return false;
        }
    }

    return rx_ring_buffer_is_empty(&buffer);
}

static bool test_repeated_wrap(void)
{
    rx_ring_buffer_t buffer = {0};
    uint8_t out_byte = 0U;

    rx_ring_buffer_init(&buffer);

    for (size_t round = 0U; round < 4U; ++round) {
        for (size_t i = 0U; i < RX_RING_BUFFER_CAPACITY; ++i) {
            const uint8_t value = (uint8_t)((round * RX_RING_BUFFER_CAPACITY) + i);
            if (!rx_ring_buffer_push(&buffer, value)) {
                return false;
            }
        }

        for (size_t i = 0U; i < RX_RING_BUFFER_CAPACITY; ++i) {
            const uint8_t expected = (uint8_t)((round * RX_RING_BUFFER_CAPACITY) + i);
            if (!rx_ring_buffer_pop(&buffer, &out_byte) || (out_byte != expected)) {
                return false;
            }
        }
    }

    return rx_ring_buffer_is_empty(&buffer)
        && (rx_ring_buffer_count(&buffer) == 0U);
}

static bool test_failed_operation_state_preservation(void)
{
    rx_ring_buffer_t buffer = {0};
    uint8_t out_byte = 0xC3U;

    rx_ring_buffer_init(&buffer);
    const size_t before_count = rx_ring_buffer_count(&buffer);
    const uint32_t before_overflow = rx_ring_buffer_overflow_count(&buffer);
    const bool before_empty = rx_ring_buffer_is_empty(&buffer);
    const bool before_full = rx_ring_buffer_is_full(&buffer);

    const bool empty_pop_result = rx_ring_buffer_pop(&buffer, &out_byte);
    const bool null_output_result = rx_ring_buffer_pop(&buffer, NULL);

    return before_empty
        && !empty_pop_result
        && !null_output_result
        && (out_byte == 0xC3U)
        && (rx_ring_buffer_count(&buffer) == before_count)
        && (rx_ring_buffer_overflow_count(&buffer) == before_overflow)
        && (rx_ring_buffer_is_empty(&buffer) == before_empty)
        && (rx_ring_buffer_is_full(&buffer) == before_full);
}

static bool test_overflow_counter(void)
{
    rx_ring_buffer_t buffer = {0};
    rx_ring_buffer_init(&buffer);

    for (size_t i = 0U; i < RX_RING_BUFFER_CAPACITY; ++i) {
        if (!rx_ring_buffer_push(&buffer, (uint8_t)i)) {
            return false;
        }
    }

    const uint32_t before = rx_ring_buffer_overflow_count(&buffer);
    (void)rx_ring_buffer_push(&buffer, 0xE1U);

    return (rx_ring_buffer_overflow_count(&buffer) == (before + 1U))
        && (rx_ring_buffer_count(&buffer) <= RX_RING_BUFFER_CAPACITY);
}

static bool test_declared_overflow_policy(void)
{
    const rx_ring_buffer_overflow_policy_t policy = rx_ring_buffer_overflow_policy();
    if (policy == RX_RING_BUFFER_OVERFLOW_POLICY_UNDECIDED) {
        return false;
    }

    rx_ring_buffer_t buffer = {0};
    uint8_t out_byte = 0U;
    rx_ring_buffer_init(&buffer);

    for (size_t i = 0U; i < RX_RING_BUFFER_CAPACITY; ++i) {
        if (!rx_ring_buffer_push(&buffer, (uint8_t)i)) {
            return false;
        }
    }

    const bool overflow_push_result = rx_ring_buffer_push(&buffer, 0xE1U);
    if ((rx_ring_buffer_overflow_count(&buffer) != 1U)
        || (rx_ring_buffer_count(&buffer) != RX_RING_BUFFER_CAPACITY)) {
        return false;
    }

    if (policy == RX_RING_BUFFER_OVERFLOW_POLICY_DROP_NEWEST) {
        if (overflow_push_result) {
            return false;
        }
        for (size_t i = 0U; i < RX_RING_BUFFER_CAPACITY; ++i) {
            if (!rx_ring_buffer_pop(&buffer, &out_byte) || (out_byte != (uint8_t)i)) {
                return false;
            }
        }
        return true;
    }

    if (policy == RX_RING_BUFFER_OVERFLOW_POLICY_OVERWRITE_OLDEST) {
        if (!overflow_push_result) {
            return false;
        }
        for (size_t i = 1U; i < RX_RING_BUFFER_CAPACITY; ++i) {
            if (!rx_ring_buffer_pop(&buffer, &out_byte) || (out_byte != (uint8_t)i)) {
                return false;
            }
        }
        return rx_ring_buffer_pop(&buffer, &out_byte) && (out_byte == 0xE1U);
    }

    return false;
}

static bool test_reinitialization(void)
{
    rx_ring_buffer_t buffer = {0};
    buffer.head = 1U;
    buffer.tail = 2U;
    buffer.count = RX_RING_BUFFER_CAPACITY;
    buffer.overflow_count = 9U;

    rx_ring_buffer_init(&buffer);

    return rx_ring_buffer_is_empty(&buffer)
        && !rx_ring_buffer_is_full(&buffer)
        && (rx_ring_buffer_count(&buffer) == 0U)
        && (rx_ring_buffer_overflow_count(&buffer) == 0U);
}

int main(void)
{
    report("W03D03-T01", "INIT_EMPTY", test_init_empty());
    report("W03D03-T02", "INVALID_INPUT", test_invalid_input());
    report("W03D03-T03", "NORMAL_FIFO", test_normal_fifo());
    report("W03D03-T04", "BOUNDARY_ONE_ELEMENT", test_one_element_boundary());
    report("W03D03-T05", "FULL_EXACT_CAPACITY", test_exact_capacity_full());
    report("W03D03-T06", "WRAP", test_wrap());
    report("W03D03-T07", "REPEATED_WRAP", test_repeated_wrap());
    report("W03D03-T08", "FAILED_OPERATION_STATE_PRESERVATION",
           test_failed_operation_state_preservation());
    report("W03D03-T09", "OVERFLOW_COUNTER", test_overflow_counter());
    report("W03D03-T10", "LEARNER_SELECTED_OVERFLOW_POLICY",
           test_declared_overflow_policy());
    report("W03D03-T11", "REINITIALIZATION", test_reinitialization());

    printf("SUMMARY: %u tests, %u failed\n", g_tests_run, g_tests_failed);
    return (g_tests_failed == 0U) ? 0 : 1;
}
