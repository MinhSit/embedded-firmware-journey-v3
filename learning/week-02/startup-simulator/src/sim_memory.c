#include "sim_memory.h"

enum
{
    FLASH_DATA_OFFSET = 2,
    RAM_DATA_OFFSET = 1,
    RAM_DATA_GUARD_OFFSET = RAM_DATA_OFFSET + DATA_WORDS,
    RAM_BSS_OFFSET = RAM_DATA_GUARD_OFFSET + 1,
    RAM_BSS_GUARD_OFFSET = RAM_BSS_OFFSET + BSS_WORDS
};

uint32_t fake_flash[SIM_FLASH_WORDS];
uint32_t fake_ram[SIM_RAM_WORDS];

uint32_t *_sidata = &fake_flash[FLASH_DATA_OFFSET];
uint32_t *_sdata = &fake_ram[RAM_DATA_OFFSET];
uint32_t *_edata = &fake_ram[RAM_DATA_OFFSET + DATA_WORDS];
uint32_t *_sbss = &fake_ram[RAM_BSS_OFFSET];
uint32_t *_ebss = &fake_ram[RAM_BSS_OFFSET + BSS_WORDS];

void sim_memory_seed(void)
{
    size_t index;

    for (index = 0u; index < SIM_FLASH_WORDS; ++index) {
        fake_flash[index] = 0u;
    }

    for (index = 0u; index < SIM_RAM_WORDS; ++index) {
        fake_ram[index] = SIM_GUARD_WORD;
    }

    _sidata[0] = UINT32_C(0x11111111);
    _sidata[1] = UINT32_C(0x22222222);
    _sidata[2] = UINT32_C(0x33333333);
    _sidata[3] = UINT32_C(0x44444444);

    for (index = 0u; index < DATA_WORDS; ++index) {
        _sdata[index] = SIM_DATA_POISON;
    }

    for (index = 0u; index < BSS_WORDS; ++index) {
        _sbss[index] = SIM_BSS_POISON;
    }
}

bool sim_memory_data_matches_image(size_t *bad_index,
                                   uint32_t *expected,
                                   uint32_t *actual)
{
    size_t index;

    for (index = 0u; index < DATA_WORDS; ++index) {
        if (_sdata[index] != _sidata[index]) {
            if (bad_index != NULL) {
                *bad_index = index;
            }
            if (expected != NULL) {
                *expected = _sidata[index];
            }
            if (actual != NULL) {
                *actual = _sdata[index];
            }
            return false;
        }
    }

    return true;
}

bool sim_memory_bss_is_zero(size_t *bad_index, uint32_t *actual)
{
    size_t index;

    for (index = 0u; index < BSS_WORDS; ++index) {
        if (_sbss[index] != 0u) {
            if (bad_index != NULL) {
                *bad_index = index;
            }
            if (actual != NULL) {
                *actual = _sbss[index];
            }
            return false;
        }
    }

    return true;
}

bool sim_memory_guards_intact(size_t *bad_index, uint32_t *actual)
{
    static const size_t guard_indices[] = {
        0u,
        RAM_DATA_GUARD_OFFSET,
        RAM_BSS_GUARD_OFFSET,
        RAM_BSS_GUARD_OFFSET + 1u,
        RAM_BSS_GUARD_OFFSET + 2u,
        RAM_BSS_GUARD_OFFSET + 3u,
        RAM_BSS_GUARD_OFFSET + 4u,
        RAM_BSS_GUARD_OFFSET + 5u
    };
    size_t index;

    for (index = 0u; index < sizeof(guard_indices) / sizeof(guard_indices[0]);
         ++index) {
        const size_t ram_index = guard_indices[index];
        if (fake_ram[ram_index] != SIM_GUARD_WORD) {
            if (bad_index != NULL) {
                *bad_index = ram_index;
            }
            if (actual != NULL) {
                *actual = fake_ram[ram_index];
            }
            return false;
        }
    }

    return true;
}

void sim_memory_inject_short_data_copy(void)
{
    _edata[-1] = SIM_DATA_POISON;
}

void sim_memory_inject_skipped_bss_zero(void)
{
    size_t index;

    for (index = 0u; index < BSS_WORDS; ++index) {
        _sbss[index] = SIM_BSS_POISON;
    }
}
