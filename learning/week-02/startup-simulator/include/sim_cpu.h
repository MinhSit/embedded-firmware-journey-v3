#ifndef SIM_CPU_H
#define SIM_CPU_H

#include "sim_vector.h"

#include <stdint.h>

typedef struct
{
    uint32_t msp;
    unsigned reset_count;
} sim_cpu_t;

typedef enum
{
    SIM_RESET_OK = 0,
    SIM_RESET_INVALID_STACK,
    SIM_RESET_INVALID_HANDLER
} sim_reset_result_t;

void sim_cpu_init(sim_cpu_t *cpu);
sim_reset_result_t sim_cpu_reset(sim_cpu_t *cpu,
                                 const sim_vector_table_t *vector_table);
const char *sim_reset_result_name(sim_reset_result_t result);

#endif
