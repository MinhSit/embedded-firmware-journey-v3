#include "sim_vector.h"

#include "sim_memory.h"
#include "sim_trace.h"
#include "startup.h"

static unsigned fault_handler_calls;

sim_vector_table_t sim_vector_baseline(void)
{
    sim_vector_table_t vector_table;

    vector_table.initial_msp = SIM_RAM_TOP;
    vector_table.reset_handler = Reset_Handler;
    return vector_table;
}

void Fault_Handler(void)
{
    ++fault_handler_calls;
    trace_record(TRACE_FAULT_HANDLER, fault_handler_calls, 0u);
}

void sim_fault_handler_reset_count(void)
{
    fault_handler_calls = 0u;
}

unsigned sim_fault_handler_count(void)
{
    return fault_handler_calls;
}
