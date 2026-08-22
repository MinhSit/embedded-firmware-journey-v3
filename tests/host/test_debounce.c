#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "debounce.h"

typedef bool (*test_fn_t)(void);

static int tests_run;
static int tests_failed;

static debounce_config_t make_config(uint32_t threshold_ticks,
                                     bool active_level)
{
    debounce_config_t config = {
        .threshold_ticks = threshold_ticks,
        .active_level = active_level
    };
    return config;
}

static bool test_initial_inactive_state(void)
{
    debounce_t ctx;
    const debounce_config_t config = make_config(5U, true);

    debounce_init(&ctx, &config, false, 10U);
    return !debounce_stable_level(&ctx) &&
           debounce_sample(&ctx, false, 11U) == DEBOUNCE_EVENT_NONE;
}

static bool test_initial_active_state(void)
{
    debounce_t ctx;
    const debounce_config_t config = make_config(5U, true);

    debounce_init(&ctx, &config, true, 10U);
    return debounce_stable_level(&ctx) &&
           debounce_sample(&ctx, true, 11U) == DEBOUNCE_EVENT_NONE;
}

static bool test_raw_transition_before_threshold(void)
{
    debounce_t ctx;
    const debounce_config_t config = make_config(5U, true);

    debounce_init(&ctx, &config, false, 0U);
    if (debounce_sample(&ctx, true, 10U) != DEBOUNCE_EVENT_NONE) {
        return false;
    }
    return debounce_sample(&ctx, true, 14U) == DEBOUNCE_EVENT_NONE &&
           !debounce_stable_level(&ctx);
}

static bool test_exact_threshold_boundary(void)
{
    debounce_t ctx;
    const debounce_config_t config = make_config(5U, true);

    debounce_init(&ctx, &config, false, 0U);
    (void)debounce_sample(&ctx, true, 10U);
    return debounce_sample(&ctx, true, 15U) == DEBOUNCE_EVENT_ACTIVATED &&
           debounce_stable_level(&ctx);
}

static bool test_bounce_noise_restarts_candidate(void)
{
    debounce_t ctx;
    const debounce_config_t config = make_config(4U, true);

    debounce_init(&ctx, &config, false, 0U);
    (void)debounce_sample(&ctx, true, 1U);
    (void)debounce_sample(&ctx, false, 2U);
    (void)debounce_sample(&ctx, true, 3U);
    if (debounce_sample(&ctx, true, 6U) != DEBOUNCE_EVENT_NONE) {
        return false;
    }
    return debounce_sample(&ctx, true, 7U) == DEBOUNCE_EVENT_ACTIVATED;
}

static bool test_press_stabilization(void)
{
    debounce_t ctx;
    const debounce_config_t config = make_config(3U, true);

    debounce_init(&ctx, &config, false, 0U);
    (void)debounce_sample(&ctx, true, 20U);
    return debounce_sample(&ctx, true, 23U) == DEBOUNCE_EVENT_ACTIVATED &&
           debounce_stable_level(&ctx);
}

static bool test_release_stabilization(void)
{
    debounce_t ctx;
    const debounce_config_t config = make_config(3U, true);

    debounce_init(&ctx, &config, true, 0U);
    (void)debounce_sample(&ctx, false, 30U);
    return debounce_sample(&ctx, false, 33U) == DEBOUNCE_EVENT_DEACTIVATED &&
           !debounce_stable_level(&ctx);
}

static bool test_repeated_samples_do_not_duplicate_event(void)
{
    debounce_t ctx;
    const debounce_config_t config = make_config(2U, true);

    debounce_init(&ctx, &config, false, 0U);
    (void)debounce_sample(&ctx, true, 40U);
    if (debounce_sample(&ctx, true, 42U) != DEBOUNCE_EVENT_ACTIVATED) {
        return false;
    }
    return debounce_sample(&ctx, true, 43U) == DEBOUNCE_EVENT_NONE;
}

static bool test_uint32_tick_wrap(void)
{
    debounce_t ctx;
    const debounce_config_t config = make_config(4U, true);

    debounce_init(&ctx, &config, false, UINT32_MAX - 10U);
    (void)debounce_sample(&ctx, true, UINT32_MAX - 2U);
    return debounce_sample(&ctx, true, 2U) == DEBOUNCE_EVENT_ACTIVATED &&
           debounce_stable_level(&ctx);
}

static bool test_active_low_event_mapping(void)
{
    debounce_t ctx;
    const debounce_config_t config = make_config(5U, false);

    debounce_init(&ctx, &config, true, 0U);
    (void)debounce_sample(&ctx, false, 100U);
    return debounce_sample(&ctx, false, 105U) == DEBOUNCE_EVENT_ACTIVATED &&
           !debounce_stable_level(&ctx);
}

static void run_test(const char *name, test_fn_t test_fn)
{
    const bool passed = test_fn();
    ++tests_run;
    if (passed) {
        printf("[PASS] %s\n", name);
    } else {
        ++tests_failed;
        printf("[FAIL] %s\n", name);
    }
}

int main(void)
{
    run_test("initial inactive state", test_initial_inactive_state);
    run_test("initial active state", test_initial_active_state);
    run_test("raw transition before threshold", test_raw_transition_before_threshold);
    run_test("exact threshold boundary", test_exact_threshold_boundary);
    run_test("bounce/noise restarts candidate", test_bounce_noise_restarts_candidate);
    run_test("press stabilization", test_press_stabilization);
    run_test("release stabilization", test_release_stabilization);
    run_test("no duplicate semantic event", test_repeated_samples_do_not_duplicate_event);
    run_test("uint32 tick wrap-around", test_uint32_tick_wrap);
    run_test("active-low event mapping", test_active_low_event_mapping);

    printf("SUMMARY: %d tests, %d failed\n", tests_run, tests_failed);
    return tests_failed == 0 ? 0 : 1;
}
