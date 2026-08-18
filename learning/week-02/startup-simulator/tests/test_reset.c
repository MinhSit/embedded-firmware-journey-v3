#include "test_common.h"

#include "sim_cpu.h"
#include "sim_fault.h"
#include "sim_memory.h"
#include "sim_trace.h"
#include "sim_vector.h"
#include "startup.h"

#include <stddef.h>

static unsigned alternate_handler_calls;

static void alternate_reset_handler(void)
{
    ++alternate_handler_calls;
    trace_record(TRACE_RESET_HANDLER_ENTER, alternate_handler_calls, 0u);
}

static void reset_fixture(void)
{
    alternate_handler_calls = 0u;
    sim_memory_seed();
    sim_fault_set_mode(FAULT_NONE);
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
    trace_event_t event;

    reset_fixture();
    sim_cpu_init(&cpu);
    vector_table = sim_vector_baseline();
    vector_table.reset_handler = alternate_reset_handler;
    result = sim_cpu_reset(&cpu, &vector_table);

    test_check(&tests, "TEST-RESET-01", "reset reads initial MSP",
               trace_get(1u, &event) &&
                   event.kind == TRACE_VECTOR_MSP_READ &&
                   event.value == vector_table.initial_msp);
    test_check(&tests, "TEST-RESET-02", "reset stores simulated MSP",
               result == SIM_RESET_OK && cpu.msp == vector_table.initial_msp);
    test_check(&tests, "TEST-RESET-03", "reset invokes vector handler",
               alternate_handler_calls == 1u);
    test_check(&tests, "TEST-RESET-04", "reset count increments",
               cpu.reset_count == 1u);

    reset_fixture();
    sim_cpu_init(&cpu);
    vector_table = sim_vector_baseline();
    vector_table.initial_msp = SIM_RAM_BASE + UINT32_C(2);
    result = sim_cpu_reset(&cpu, &vector_table);
    test_check(&tests, "TEST-RESET-05", "misaligned stack is rejected",
               result == SIM_RESET_INVALID_STACK &&
                   trace_find_first(TRACE_RESET_HANDLER_ENTER) == SIZE_MAX);

    reset_fixture();
    sim_cpu_init(&cpu);
    vector_table = sim_vector_baseline();
    vector_table.reset_handler = NULL;
    result = sim_cpu_reset(&cpu, &vector_table);
    test_check(&tests, "TEST-RESET-06", "null reset vector is rejected",
               result == SIM_RESET_INVALID_HANDLER &&
                   trace_find_first(TRACE_RESET_HANDLER_ENTER) == SIZE_MAX);

    return test_finish(&tests);
}
