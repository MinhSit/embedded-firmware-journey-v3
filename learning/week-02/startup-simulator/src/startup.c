#include "startup.h"

#include "sim_memory.h"
#include "sim_trace.h"

void Reset_Handler(void)
{
    trace_record(TRACE_RESET_HANDLER_ENTER, 0u, 0u);

    /* TODO(LEARNER): Call SystemInit at the contractually correct point. */
    SystemInit();
    /* TODO(LEARNER): Copy the complete initialized .data range manually.
     * Use the linker-symbol-like boundaries declared in sim_memory.h.
     * Constraint: do not use memcpy.
     * Record TRACE_DATA_COPY with the affected word index and value.
     */
    size_t data_index = 0u;
    const uint32_t *src = _sidata;
    uint32_t *dst = _sdata;
    while(dst < _edata){
        *dst = *src;
        trace_record(TRACE_DATA_COPY, data_index, *dst);
        dst++;
        src++;
        data_index++;
    }
    /* TODO(LEARNER): Zero the complete .bss range manually.
     * Use the linker-symbol-like boundaries declared in sim_memory.h.
     * Constraint: do not use memset.
     * Record TRACE_BSS_ZERO with the affected word index and value.
     */
    size_t bss_index = 0u;
    uint32_t *bss = _sbss;
    while(bss < _ebss){
        *bss = 0x00000000;
        trace_record(TRACE_BSS_ZERO, bss_index, *bss);
        bss++;
        bss_index++;
    }
    /* TODO(LEARNER): Complete runtime initialization and application
     * sequencing. The trace must make the ordering observable.
     */
    runtime_init();
    app_main();
}
