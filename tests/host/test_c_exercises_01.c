#include <stdio.h>
#include <stdlib.h>

#include "../../learning/week-01/day-01/c_exercises_01.h"

static int tests_run = 0;
static int tests_failed = 0;

#define CHECK(condition)                                                     \
    do {                                                                     \
        ++tests_run;                                                         \
        if (!(condition)) {                                                  \
            ++tests_failed;                                                  \
            printf("FAIL: %s:%d: %s\n", __FILE__, __LINE__, #condition);     \
        }                                                                    \
    } while (0)

static int multiply_by_two(int value)
{
    return value * 2;
}

static void test_swap_int(void)
{
    int a = 10;
    int b = 20;

    CHECK(swap_int(&a, &b));
    CHECK(a == 20);
    CHECK(b == 10);

    CHECK(swap_int(&a, &a));
    CHECK(a == 20);

    CHECK(!swap_int(NULL, &b));
    CHECK(!swap_int(&a, NULL));
}

static void test_sum_ints(void)
{
    const int values[] = {1, 2, 3, 4};
    long sum = -1;

    CHECK(sum_ints(values, 4, &sum));
    CHECK(sum == 10);

    sum = -1;
    CHECK(sum_ints(NULL, 0, &sum));
    CHECK(sum == 0);

    CHECK(!sum_ints(NULL, 2, &sum));
    CHECK(!sum_ints(values, 4, NULL));
}

static void test_max_int(void)
{
    const int values[] = {-8, 4, 20, 3, -1};
    int max_value = 0;

    CHECK(max_int(values, 5, &max_value));
    CHECK(max_value == 20);

    CHECK(!max_int(NULL, 5, &max_value));
    CHECK(!max_int(values, 0, &max_value));
    CHECK(!max_int(values, 5, NULL));
}

static void test_reverse_ints(void)
{
    int values[] = {1, 2, 3, 4, 5};

    CHECK(reverse_ints(values, 5));

    CHECK(values[0] == 5);
    CHECK(values[1] == 4);
    CHECK(values[2] == 3);
    CHECK(values[3] == 2);
    CHECK(values[4] == 1);

    CHECK(reverse_ints(NULL, 0));
    CHECK(!reverse_ints(NULL, 3));
}

static void test_find_first(void)
{
    const int values[] = {5, 8, 3, 8, 1};

    const int *found = find_first(values, 5, 8);

    CHECK(found != NULL);

    if (found != NULL) {
        CHECK(*found == 8);
        CHECK(found == &values[1]);
    }

    CHECK(find_first(values, 5, 100) == NULL);
    CHECK(find_first(NULL, 5, 8) == NULL);
    CHECK(find_first(NULL, 0, 8) == NULL);
}

static void test_retarget_pointer(void)
{
    int a = 10;
    int b = 20;

    int *p = &a;

    CHECK(retarget_pointer(&p, &b));
    CHECK(p == &b);
    CHECK(*p == 20);

    CHECK(retarget_pointer(&p, NULL));
    CHECK(p == NULL);

    CHECK(!retarget_pointer(NULL, &a));
}

static void test_transform_ints(void)
{
    int values[] = {1, 2, 3, 4};

    CHECK(transform_ints(values, 4, multiply_by_two));

    CHECK(values[0] == 2);
    CHECK(values[1] == 4);
    CHECK(values[2] == 6);
    CHECK(values[3] == 8);

    CHECK(transform_ints(NULL, 0, multiply_by_two));
    CHECK(!transform_ints(NULL, 3, multiply_by_two));
    CHECK(!transform_ints(values, 4, NULL));
}

int main(void)
{
    test_swap_int();
    test_sum_ints();
    test_max_int();
    test_reverse_ints();
    test_find_first();
    test_retarget_pointer();
    test_transform_ints();

    printf("\nTests run:    %d\n", tests_run);
    printf("Tests failed: %d\n", tests_failed);

    if (tests_failed == 0) {
        printf("RESULT: PASS\n");
        return EXIT_SUCCESS;
    }

    printf("RESULT: FAIL\n");
    return EXIT_FAILURE;
}