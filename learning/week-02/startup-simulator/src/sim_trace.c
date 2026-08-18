#include "sim_trace.h"

#define TRACE_CAPACITY 64u

static trace_event_t events[TRACE_CAPACITY];
static size_t event_count;

void trace_reset(void)
{
    event_count = 0u;
}

void trace_record(trace_event_kind_t kind, size_t index, uint32_t value)
{
    if (event_count < TRACE_CAPACITY) {
        events[event_count].kind = kind;
        events[event_count].index = index;
        events[event_count].value = value;
        ++event_count;
    }
}

size_t trace_count(void)
{
    return event_count;
}

bool trace_get(size_t index, trace_event_t *event)
{
    if (event == NULL || index >= event_count) {
        return false;
    }

    *event = events[index];
    return true;
}

size_t trace_find_first(trace_event_kind_t kind)
{
    size_t index;

    for (index = 0u; index < event_count; ++index) {
        if (events[index].kind == kind) {
            return index;
        }
    }

    return SIZE_MAX;
}

const char *trace_event_name(trace_event_kind_t kind)
{
    switch (kind) {
    case TRACE_CPU_RESET_BEGIN:
        return "CPU_RESET_BEGIN";
    case TRACE_VECTOR_MSP_READ:
        return "VECTOR_MSP_READ";
    case TRACE_MSP_SET:
        return "MSP_SET";
    case TRACE_RESET_VECTOR_READ:
        return "RESET_VECTOR_READ";
    case TRACE_RESET_HANDLER_ENTER:
        return "RESET_HANDLER_ENTER";
    case TRACE_SYSTEM_INIT:
        return "SYSTEM_INIT";
    case TRACE_DATA_COPY:
        return "DATA_COPY";
    case TRACE_BSS_ZERO:
        return "BSS_ZERO";
    case TRACE_RUNTIME_INIT:
        return "RUNTIME_INIT";
    case TRACE_APP_MAIN:
        return "APP_MAIN";
    case TRACE_FAULT_HANDLER:
        return "FAULT_HANDLER";
    default:
        return "UNKNOWN";
    }
}
