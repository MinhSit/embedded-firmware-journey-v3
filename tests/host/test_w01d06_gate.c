#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

bool u32_field_write(uint32_t *dst, unsigned lsb, unsigned width,
                     uint32_t field);
size_t copy_token(char *dst, size_t dst_cap, const char *src);
bool get_max_value(const int *values, size_t count, int *out_max);

static unsigned tests_run;
static unsigned tests_failed;

#define CHECK(label, condition)                                               \
    do {                                                                      \
        ++tests_run;                                                          \
        if (condition) {                                                      \
            printf("[PASS] %s\n", label);                                    \
        } else {                                                              \
            ++tests_failed;                                                   \
            printf("[FAIL] %s\n", label);                                    \
        }                                                                     \
    } while (0)

int main(void)
{
    uint32_t reg = UINT32_C(0xA5A5A5A5);
    CHECK("safe_bit rejects NULL", !u32_field_write(NULL, 0, 1, 0));
    CHECK("safe_bit rejects zero width unchanged",
          !u32_field_write(&reg, 0, 0, 0) && reg == UINT32_C(0xA5A5A5A5));
    CHECK("safe_bit rejects lsb+width overflow unchanged",
          !u32_field_write(&reg, 31, 2, 0) && reg == UINT32_C(0xA5A5A5A5));
    CHECK("safe_bit rejects oversized field unchanged",
          !u32_field_write(&reg, 4, 3, 8) && reg == UINT32_C(0xA5A5A5A5));
    CHECK("safe_bit accepts full-width write",
          u32_field_write(&reg, 0, 32, UINT32_C(0x12345678)) &&
              reg == UINT32_C(0x12345678));

    char dst[8] = "KEEP";
    CHECK("copy_token rejects NULL destination",
          copy_token(NULL, sizeof(dst), "abc") == 0);
    CHECK("copy_token rejects zero capacity without mutation",
          copy_token(dst, 0, "abc") == 0 && strcmp(dst, "KEEP") == 0);
    CHECK("copy_token handles NULL source as empty string",
          copy_token(dst, sizeof(dst), NULL) == 0 && dst[0] == '\0');
    CHECK("copy_token truncates and terminates",
          copy_token(dst, 4, "abcdef") == 3 && strcmp(dst, "abc") == 0);
    CHECK("copy_token copies complete token",
          copy_token(dst, sizeof(dst), "Hi") == 2 && strcmp(dst, "Hi") == 0);

    int out = 77;
    const int values[] = {-8, -3, -12, -4};
    CHECK("get_max_value rejects NULL values unchanged",
          !get_max_value(NULL, 4, &out) && out == 77);
    CHECK("get_max_value rejects zero count unchanged",
          !get_max_value(values, 0, &out) && out == 77);
    CHECK("get_max_value rejects NULL output",
          !get_max_value(values, 4, NULL));
    CHECK("get_max_value finds maximum",
          get_max_value(values, 4, &out) && out == -3);

    printf("SUMMARY: %u tests, %u failed\n", tests_run, tests_failed);
    return tests_failed == 0 ? 0 : 1;
}
