#include "test_common.h"

#include "sim_cpu.h"
#include "sim_fault.h"
#include "sim_memory.h"
#include "sim_trace.h"
#include "sim_vector.h"
#include "startup.h"

#include <stddef.h>

static void reset_fixture(sim_fault_mode_t mode)
{
    sim_memory_seed();
    sim_fault_set_mode(mode);
    sim_fault_handler_reset_count();
    startup_observer_reset();
    trace_reset();
}

int main(void)
{
    test_context_t tests = {0u, 0u};
    sim_cpu_t cpu;
    sim_vector_table_t vector_table;
    sim_reset_result_t result;
    const startup_observer_t *observer;
    size_t runtime_index;
    size_t main_index;

    reset_fixture(FAULT_DATA_COPY_SHORT_ONE_WORD);
    _sdata[0] = _sidata[0];
    _sdata[1] = _sidata[1];
    _sdata[2] = _sidata[2];
    sim_fault_after_reset_handler();
    test_check(&tests, "TEST-FAULT-A", "short copy leaves only final word wrong",
               _sdata[0] == _sidata[0] && _sdata[1] == _sidata[1] &&
                   _sdata[2] == _sidata[2] && _sdata[3] != _sidata[3]);

    reset_fixture(FAULT_SKIP_BSS_ZERO);
    app_main();
    sim_fault_after_reset_handler();
    observer = startup_observer_get();
    test_check(&tests, "TEST-FAULT-B", "main can run while .bss stays poisoned",
               observer->app_main_called && _sbss[0] == SIM_BSS_POISON &&
                   !observer->app_saw_initialized_memory);

    reset_fixture(FAULT_BAD_STACK);
    sim_cpu_init(&cpu);
    vector_table = sim_vector_baseline();
    sim_fault_configure_vector(&vector_table);
    result = sim_cpu_reset(&cpu, &vector_table);
    test_check(&tests, "TEST-FAULT-C", "bad stack blocks reset handler",
               result == SIM_RESET_INVALID_STACK &&
                   trace_find_first(TRACE_RESET_HANDLER_ENTER) == SIZE_MAX);

    reset_fixture(FAULT_MAIN_BEFORE_RUNTIME);
    runtime_init();
    app_main();
    runtime_index = trace_find_first(TRACE_RUNTIME_INIT);
    main_index = trace_find_first(TRACE_APP_MAIN);
    test_check(&tests, "TEST-FAULT-D", "trace detects main before runtime",
               main_index != SIZE_MAX && runtime_index != SIZE_MAX &&
                   main_index < runtime_index);

    reset_fixture(FAULT_WRONG_RESET_HANDLER);
    sim_cpu_init(&cpu);
    vector_table = sim_vector_baseline();
    sim_fault_configure_vector(&vector_table);
    result = sim_cpu_reset(&cpu, &vector_table);
    observer = startup_observer_get();
    test_check(&tests, "TEST-FAULT-E", "wrong vector reaches fault handler only",
               result == SIM_RESET_OK && sim_fault_handler_count() == 1u &&
                   !observer->system_init_called &&
                   !observer->runtime_init_called && !observer->app_main_called);

    return test_finish(&tests);
}
