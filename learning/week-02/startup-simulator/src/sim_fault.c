#include "sim_fault.h"

#include "sim_memory.h"

#include <stddef.h>
#include <string.h>

static sim_fault_mode_t active_mode;

void sim_fault_set_mode(sim_fault_mode_t mode)
{
    active_mode = mode;
}

sim_fault_mode_t sim_fault_get_mode(void)
{
    return active_mode;
}

const char *sim_fault_mode_name(sim_fault_mode_t mode)
{
    switch (mode) {
    case FAULT_NONE:
        return "none";
    case FAULT_DATA_COPY_SHORT_ONE_WORD:
        return "data-short";
    case FAULT_SKIP_BSS_ZERO:
        return "skip-bss";
    case FAULT_BAD_STACK:
        return "bad-stack";
    case FAULT_MAIN_BEFORE_RUNTIME:
        return "main-before-runtime";
    case FAULT_WRONG_RESET_HANDLER:
        return "wrong-reset-handler";
    default:
        return "unknown";
    }
}

bool sim_fault_mode_from_string(const char *text, sim_fault_mode_t *mode)
{
    sim_fault_mode_t candidate;

    if (text == NULL || mode == NULL) {
        return false;
    }

    for (candidate = FAULT_NONE; candidate <= FAULT_WRONG_RESET_HANDLER;
         candidate = (sim_fault_mode_t)(candidate + 1)) {
        if (strcmp(text, sim_fault_mode_name(candidate)) == 0) {
            *mode = candidate;
            return true;
        }
    }

    return false;
}

void sim_fault_configure_vector(sim_vector_table_t *vector_table)
{
    if (vector_table == NULL) {
        return;
    }

    if (active_mode == FAULT_BAD_STACK) {
        vector_table->initial_msp = SIM_RAM_BASE + UINT32_C(2);
    } else if (active_mode == FAULT_WRONG_RESET_HANDLER) {
        vector_table->reset_handler = Fault_Handler;
    }
}

void sim_fault_after_reset_handler(void)
{
    if (active_mode == FAULT_DATA_COPY_SHORT_ONE_WORD) {
        sim_memory_inject_short_data_copy();
    } else if (active_mode == FAULT_SKIP_BSS_ZERO) {
        sim_memory_inject_skipped_bss_zero();
    }
}
