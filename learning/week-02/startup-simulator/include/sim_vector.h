#ifndef SIM_VECTOR_H
#define SIM_VECTOR_H

#include <stdint.h>

typedef void (*handler_fn_t)(void);

typedef struct sim_vector_table
{
    uint32_t initial_msp;
    handler_fn_t reset_handler;
} sim_vector_table_t;

sim_vector_table_t sim_vector_baseline(void);

void Fault_Handler(void);
void sim_fault_handler_reset_count(void);
unsigned sim_fault_handler_count(void);

#endif
