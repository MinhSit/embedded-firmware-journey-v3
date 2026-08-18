#ifndef STARTUP_H
#define STARTUP_H

#include <stdbool.h>

typedef struct
{
    bool system_init_called;
    bool runtime_init_called;
    bool app_main_called;
    bool app_saw_initialized_memory;
} startup_observer_t;

void startup_observer_reset(void);
const startup_observer_t *startup_observer_get(void);

void Reset_Handler(void);
void SystemInit(void);
void runtime_init(void);
void app_main(void);

#endif
