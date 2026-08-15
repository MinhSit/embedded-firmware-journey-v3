#include <stdbool.h>
#include <stdint.h> 
#include <stdio.h>


bool help(uint32_t *dst, unsigned bit){
    if(dst == NULL || bit > 31) return false;
    uint32_t mask = 1u << bit;
    *dst = *dst & ~mask;
    return true;
}

bool u32_field_write(
    uint32_t *dst,
    unsigned lsb,
    unsigned width,
    uint32_t field
)
{
    if(dst == NULL || width == 0 || width > 32 || lsb > 31) return false;
    if(width == 32 && lsb != 0) return false;
    if(lsb + width > 32) return false;
    if(width < 32 && field >> width > 0) return false;
    for(unsigned i = lsb; i < lsb + width; i++ ){
        help(dst, i);
    }
    uint32_t mask = field << lsb;
    *dst= *dst | mask;
    return true;
}

void run_test(const char* test_name, bool expected_return, uint32_t expected_val, 
              bool actual_return, uint32_t actual_val) {
    if (expected_return == actual_return && expected_val == actual_val) {
        printf("[PASS] %s\n", test_name);
    } else {
        printf("[FAIL] %s\n", test_name);
        printf("       Return - Mong doi: %d, Thuc te: %d\n", expected_return, actual_return);
        printf("       Value  - Mong doi: 0x%08X, Thuc te: 0x%08X\n", expected_val, actual_val);
    }
}

int main() {
    uint32_t reg;
    bool res;

    printf("=== TEST TRUONG HOP HOP LE (HAPPY PATHS) ===\n");

    reg = 0xFFFFFFFF;
    res = u32_field_write(&reg, 4, 4, 0xA);
    run_test("Ghi 4 bit (0xA) vao vi tri bit 4", true, 0xFFFFFFAF, res, reg);

    reg = 0x00000000;
    res = u32_field_write(&reg, 0, 32, 0x12345678);
    run_test("Ghi toan bo 32 bit", true, 0x12345678, res, reg);

    reg = 0x00000000;
    res = u32_field_write(&reg, 31, 1, 1);
    run_test("Ghi 1 bit vao MSB (bit 31)", true, 0x80000000, res, reg);

    printf("\n=== TEST TRUONG HOP LOI (EDGE/ERROR CASES) ===\n");

    res = u32_field_write(NULL, 0, 8, 0xFF);
    run_test("Truyen con tro NULL", false, 0, res, 0);

    reg = 0x00000000;
    res = u32_field_write(&reg, 4, 0, 0xF);
    run_test("Width bang 0", false, 0x00000000, res, reg);

    reg = 0x00000000;
    res = u32_field_write(&reg, 30, 4, 0xF);
    run_test("Tran bien (lsb+width > 32)", false, 0x00000000, res, reg);

    reg = 0x00000000;
    res = u32_field_write(&reg, 0, 2, 5); 
    run_test("Gia tri field lon hon width", false, 0x00000000, res, reg);

    return 0;
}