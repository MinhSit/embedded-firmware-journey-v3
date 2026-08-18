#include "sim_cpu.h"

#include "sim_fault.h"
#include "sim_memory.h"
#include "sim_trace.h"

#include <stddef.h>

static bool stack_is_valid(uint32_t stack_value)
{
    const bool in_range = stack_value >= SIM_RAM_BASE &&
                          stack_value <= SIM_RAM_TOP;
    const bool aligned = (stack_value & UINT32_C(0x7)) == 0u;

    return in_range && aligned;
}

void sim_cpu_init(sim_cpu_t *cpu)
{
    if (cpu != NULL) {
        cpu->msp = 0u;
        cpu->reset_count = 0u;
    }
}

sim_reset_result_t sim_cpu_reset(sim_cpu_t *cpu,
                                 const sim_vector_table_t *vector_table)
{
    if (cpu == NULL || vector_table == NULL) {
        return SIM_RESET_INVALID_HANDLER;
    }

    ++cpu->reset_count;
    trace_record(TRACE_CPU_RESET_BEGIN, cpu->reset_count, 0u);
    trace_record(TRACE_VECTOR_MSP_READ, 0u, vector_table->initial_msp);

    if (!stack_is_valid(vector_table->initial_msp)) {
        trace_record(TRACE_FAULT_HANDLER, 0u, vector_table->initial_msp);
        return SIM_RESET_INVALID_STACK;
    }

    cpu->msp = vector_table->initial_msp;
    trace_record(TRACE_MSP_SET, 0u, cpu->msp);
    trace_record(TRACE_RESET_VECTOR_READ, 1u, 0u);

    if (vector_table->reset_handler == NULL) {
        trace_record(TRACE_FAULT_HANDLER, 1u, 0u);
        return SIM_RESET_INVALID_HANDLER;
    }

    vector_table->reset_handler();
    sim_fault_after_reset_handler();
    return SIM_RESET_OK;
}

const char *sim_reset_result_name(sim_reset_result_t result)
{
    switch (result) {
    case SIM_RESET_OK:
        return "SIM_RESET_OK";
    case SIM_RESET_INVALID_STACK:
        return "SIM_RESET_INVALID_STACK";
    case SIM_RESET_INVALID_HANDLER:
        return "SIM_RESET_INVALID_HANDLER";
    default:
        return "SIM_RESET_UNKNOWN";
    }
}
