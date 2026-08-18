#include "sim_cpu.h"
#include "sim_fault.h"
#include "sim_memory.h"
#include "sim_trace.h"
#include "sim_vector.h"
#include "startup.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

static void print_words(const char *label, const uint32_t *words, size_t count)
{
    size_t index;

    printf("%s", label);
    for (index = 0u; index < count; ++index) {
        printf(" 0x%08lX", (unsigned long)words[index]);
    }
    putchar('\n');
}

static void print_trace(void)
{
    size_t index;
    trace_event_t event;

    puts("Trace:");
    for (index = 0u; trace_get(index, &event); ++index) {
        printf("  %02zu %-22s index=%zu value=0x%08lX\n",
               index,
               trace_event_name(event.kind),
               event.index,
               (unsigned long)event.value);
    }
}

int main(int argc, char **argv)
{
    sim_cpu_t cpu;
    sim_vector_table_t vector_table;
    sim_reset_result_t result;
    sim_fault_mode_t mode = FAULT_NONE;
    size_t bad_index = 0u;
    uint32_t actual = 0u;

    if (argc > 2 ||
        (argc == 2 && !sim_fault_mode_from_string(argv[1], &mode))) {
        fprintf(stderr,
                "Usage: startup_demo [none|data-short|skip-bss|bad-stack|"
                "main-before-runtime|wrong-reset-handler]\n");
        return 2;
    }

    sim_memory_seed();
    startup_observer_reset();
    sim_fault_handler_reset_count();
    trace_reset();
    sim_cpu_init(&cpu);
    sim_fault_set_mode(mode);
    vector_table = sim_vector_baseline();
    sim_fault_configure_vector(&vector_table);

    printf("Fault mode: %s\n", sim_fault_mode_name(mode));
    print_words("Before .data:", _sdata, DATA_WORDS);
    print_words("Before .bss: ", _sbss, BSS_WORDS);

    result = sim_cpu_reset(&cpu, &vector_table);

    printf("Reset result: %s\n", sim_reset_result_name(result));
    print_trace();
    print_words("After .data: ", _sdata, DATA_WORDS);
    print_words("After .bss:  ", _sbss, BSS_WORDS);
    printf("Final MSP: 0x%08lX\n", (unsigned long)cpu.msp);
    printf("Guards: %s\n",
           sim_memory_guards_intact(&bad_index, &actual) ? "INTACT" : "DAMAGED");

    return 0;
}
