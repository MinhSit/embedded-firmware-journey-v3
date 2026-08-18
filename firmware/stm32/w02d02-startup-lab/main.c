#include <stdint.h>

volatile uint32_t lab_seed = 0x12345678U;
volatile uint32_t lab_counter;

int main(void)
{
    lab_counter = lab_seed;

    for (;;) {
        __asm volatile ("nop");
    }
}
