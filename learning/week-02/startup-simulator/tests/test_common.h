#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef struct
{
    unsigned run;
    unsigned failed;
} test_context_t;

static inline void test_check(test_context_t *context,
                              const char *id,
                              const char *description,
                              bool condition)
{
    ++context->run;
    if (condition) {
        printf("[PASS] %s %s\n", id, description);
    } else {
        ++context->failed;
        printf("[FAIL] %s %s\n", id, description);
    }
}

static inline void test_word_mismatch(size_t index,
                                      uint32_t expected,
                                      uint32_t actual)
{
    printf("       index:    %zu\n", index);
    printf("       expected: 0x%08lX\n", (unsigned long)expected);
    printf("       actual:   0x%08lX\n", (unsigned long)actual);
}

static inline int test_finish(const test_context_t *context)
{
    printf("SUMMARY: %u tests, %u failed\n", context->run, context->failed);
    return context->failed == 0u ? 0 : 1;
}

#endif
