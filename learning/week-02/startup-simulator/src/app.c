#include "startup.h"

#include "sim_fault.h"
#include "sim_memory.h"
#include "sim_trace.h"

#include <stddef.h>

static startup_observer_t observer;
static bool runtime_init_deferred;

void startup_observer_reset(void)
{
    observer.system_init_called = false;
    observer.runtime_init_called = false;
    observer.app_main_called = false;
    observer.app_saw_initialized_memory = false;
    runtime_init_deferred = false;
}

const startup_observer_t *startup_observer_get(void)
{
    return &observer;
}

void SystemInit(void)
{
    observer.system_init_called = true;
    trace_record(TRACE_SYSTEM_INIT, 0u, 0u);
}

static void record_runtime_init(void)
{
    observer.runtime_init_called = true;
    trace_record(TRACE_RUNTIME_INIT, 0u, 0u);
}

void runtime_init(void)
{
    if (sim_fault_get_mode() == FAULT_MAIN_BEFORE_RUNTIME) {
        runtime_init_deferred = true;
        return;
    }

    record_runtime_init();
}

void app_main(void)
{
    size_t bad_index = 0u;
    uint32_t expected = 0u;
    uint32_t actual = 0u;

    observer.app_main_called = true;
    observer.app_saw_initialized_memory =
        sim_memory_data_matches_image(&bad_index, &expected, &actual) &&
        sim_memory_bss_is_zero(&bad_index, &actual);
    trace_record(TRACE_APP_MAIN, 0u, 0u);

    if (runtime_init_deferred) {
        runtime_init_deferred = false;
        record_runtime_init();
    }
}
