#include "test_common.h"

#include "sim_cpu.h"
#include "sim_fault.h"
#include "sim_memory.h"
#include "sim_trace.h"
#include "sim_vector.h"
#include "startup.h"

#include <stddef.h>

static bool event_before(trace_event_kind_t first, trace_event_kind_t second)
{
    const size_t first_index = trace_find_first(first);
    const size_t second_index = trace_find_first(second);

    return first_index != SIZE_MAX && second_index != SIZE_MAX &&
           first_index < second_index;
}

static bool complete_startup_trace_present(void)
{
    static const trace_event_kind_t required[] = {
        TRACE_CPU_RESET_BEGIN,
        TRACE_VECTOR_MSP_READ,
        TRACE_MSP_SET,
        TRACE_RESET_VECTOR_READ,
        TRACE_RESET_HANDLER_ENTER,
        TRACE_SYSTEM_INIT,
        TRACE_DATA_COPY,
        TRACE_BSS_ZERO,
        TRACE_RUNTIME_INIT,
        TRACE_APP_MAIN
    };
    size_t required_index;
    size_t event_index = 0u;
    trace_event_t event;

    for (required_index = 0u;
         required_index < sizeof(required) / sizeof(required[0]);
         ++required_index) {
        bool found = false;
        while (trace_get(event_index, &event)) {
            ++event_index;
            if (event.kind == required[required_index]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }

    return true;
}

int main(void)
{
    test_context_t tests = {0u, 0u};
    sim_cpu_t cpu;
    sim_vector_table_t vector_table;
    sim_reset_result_t result;
    const startup_observer_t *observer;
    size_t bad_index = 0u;
    uint32_t expected = 0u;
    uint32_t actual = 0u;
    bool condition;

    sim_memory_seed();
    sim_fault_set_mode(FAULT_NONE);
    sim_fault_handler_reset_count();
    startup_observer_reset();
    trace_reset();
    sim_cpu_init(&cpu);
    vector_table = sim_vector_baseline();
    result = sim_cpu_reset(&cpu, &vector_table);
    observer = startup_observer_get();

    condition = sim_memory_data_matches_image(&bad_index, &expected, &actual);
    test_check(&tests, "TEST-STARTUP-01", "complete .data copied", condition);
    if (!condition) {
        test_word_mismatch(bad_index, expected, actual);
    }

    condition = sim_memory_bss_is_zero(&bad_index, &actual);
    test_check(&tests, "TEST-STARTUP-02", "complete .bss zeroed", condition);
    if (!condition) {
        test_word_mismatch(bad_index, 0u, actual);
    }

    test_check(&tests, "TEST-STARTUP-03", "SystemInit executed",
               observer->system_init_called);
    test_check(&tests, "TEST-STARTUP-04", "runtime init executed",
               observer->runtime_init_called);
    test_check(&tests, "TEST-STARTUP-05", "app_main executed",
               observer->app_main_called);
    test_check(&tests, "TEST-STARTUP-06", "SystemInit precedes app_main",
               event_before(TRACE_SYSTEM_INIT, TRACE_APP_MAIN));
    test_check(&tests, "TEST-STARTUP-07", "runtime init precedes app_main",
               event_before(TRACE_RUNTIME_INIT, TRACE_APP_MAIN));
    test_check(&tests, "TEST-STARTUP-08", "CPU accepted baseline reset",
               result == SIM_RESET_OK);
    test_check(&tests, "TEST-STARTUP-09", "guard words remain unchanged",
               sim_memory_guards_intact(&bad_index, &actual));
    test_check(&tests, "TEST-STARTUP-10", "complete startup trace order",
               complete_startup_trace_present());

    return test_finish(&tests);
}
