#ifndef SIM_TRACE_H
#define SIM_TRACE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef enum
{
    TRACE_CPU_RESET_BEGIN = 0,
    TRACE_VECTOR_MSP_READ,
    TRACE_MSP_SET,
    TRACE_RESET_VECTOR_READ,
    TRACE_RESET_HANDLER_ENTER,
    TRACE_SYSTEM_INIT,
    TRACE_DATA_COPY,
    TRACE_BSS_ZERO,
    TRACE_RUNTIME_INIT,
    TRACE_APP_MAIN,
    TRACE_FAULT_HANDLER
} trace_event_kind_t;

typedef struct
{
    trace_event_kind_t kind;
    size_t index;
    uint32_t value;
} trace_event_t;

void trace_reset(void);
void trace_record(trace_event_kind_t kind, size_t index, uint32_t value);
size_t trace_count(void);
bool trace_get(size_t index, trace_event_t *event);
size_t trace_find_first(trace_event_kind_t kind);
const char *trace_event_name(trace_event_kind_t kind);

#endif
