#ifndef SIM_FAULT_H
#define SIM_FAULT_H

#include "sim_vector.h"

#include <stdbool.h>

typedef enum
{
    FAULT_NONE = 0,
    FAULT_DATA_COPY_SHORT_ONE_WORD,
    FAULT_SKIP_BSS_ZERO,
    FAULT_BAD_STACK,
    FAULT_MAIN_BEFORE_RUNTIME,
    FAULT_WRONG_RESET_HANDLER
} sim_fault_mode_t;

void sim_fault_set_mode(sim_fault_mode_t mode);
sim_fault_mode_t sim_fault_get_mode(void);
const char *sim_fault_mode_name(sim_fault_mode_t mode);
bool sim_fault_mode_from_string(const char *text, sim_fault_mode_t *mode);
void sim_fault_configure_vector(sim_vector_table_t *vector_table);
void sim_fault_after_reset_handler(void);

#endif
