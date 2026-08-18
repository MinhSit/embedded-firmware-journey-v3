#ifndef SIM_MEMORY_H
#define SIM_MEMORY_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define SIM_FLASH_WORDS 8u
#define SIM_RAM_WORDS 16u
#define DATA_WORDS 4u
#define BSS_WORDS 4u

#define SIM_DATA_POISON UINT32_C(0xDEADBEEF)
#define SIM_BSS_POISON UINT32_C(0xA5A5A5A5)
#define SIM_GUARD_WORD UINT32_C(0xCAFEBABE)

#define SIM_RAM_BASE UINT32_C(0x20000000)
#define SIM_RAM_TOP (SIM_RAM_BASE + (SIM_RAM_WORDS * UINT32_C(4)))

extern uint32_t fake_flash[SIM_FLASH_WORDS];
extern uint32_t fake_ram[SIM_RAM_WORDS];

extern uint32_t *_sidata;
extern uint32_t *_sdata;
extern uint32_t *_edata;
extern uint32_t *_sbss;
extern uint32_t *_ebss;

void sim_memory_seed(void);
bool sim_memory_data_matches_image(size_t *bad_index,
                                   uint32_t *expected,
                                   uint32_t *actual);
bool sim_memory_bss_is_zero(size_t *bad_index, uint32_t *actual);
bool sim_memory_guards_intact(size_t *bad_index, uint32_t *actual);

void sim_memory_inject_short_data_copy(void);
void sim_memory_inject_skipped_bss_zero(void);

#endif
