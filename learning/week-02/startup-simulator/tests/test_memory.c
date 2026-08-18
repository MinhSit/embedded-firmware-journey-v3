#include "test_common.h"

#include "sim_memory.h"

#include <stddef.h>

int main(void)
{
    static const uint32_t expected_image[DATA_WORDS] = {
        UINT32_C(0x11111111),
        UINT32_C(0x22222222),
        UINT32_C(0x33333333),
        UINT32_C(0x44444444)
    };
    test_context_t tests = {0u, 0u};
    bool image_ok = true;
    bool data_already_matches;
    bool bss_already_zero;
    size_t index;
    size_t bad_index = 0u;
    uint32_t expected = 0u;
    uint32_t actual = 0u;

    sim_memory_seed();

    test_check(&tests, "TEST-MEM-01", ".data boundary length",
               (size_t)(_edata - _sdata) == DATA_WORDS);
    test_check(&tests, "TEST-MEM-02", ".bss boundary length",
               (size_t)(_ebss - _sbss) == BSS_WORDS);
    test_check(&tests, "TEST-MEM-03", ".data range is non-empty",
               _sdata < _edata);
    test_check(&tests, "TEST-MEM-04", ".bss range is non-empty",
               _sbss < _ebss);
    test_check(&tests, "TEST-MEM-05", ".data and .bss do not overlap",
               _edata <= _sbss || _ebss <= _sdata);

    for (index = 0u; index < DATA_WORDS; ++index) {
        if (_sidata[index] != expected_image[index]) {
            image_ok = false;
            bad_index = index;
            expected = expected_image[index];
            actual = _sidata[index];
            break;
        }
    }
    test_check(&tests, "TEST-MEM-06", "Flash .data image is deterministic",
               image_ok);
    if (!image_ok) {
        test_word_mismatch(bad_index, expected, actual);
    }

    data_already_matches =
        sim_memory_data_matches_image(&bad_index, &expected, &actual);
    test_check(&tests, "TEST-MEM-07", "pre-reset RAM .data is poisoned",
               !data_already_matches);

    bss_already_zero = sim_memory_bss_is_zero(&bad_index, &actual);
    test_check(&tests, "TEST-MEM-08", "pre-reset .bss is poisoned",
               !bss_already_zero);

    test_check(&tests, "TEST-MEM-09", "guard words start intact",
               sim_memory_guards_intact(&bad_index, &actual));

    return test_finish(&tests);
}
