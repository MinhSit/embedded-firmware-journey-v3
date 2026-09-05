#include "stm32f446xx.h"
#include "dma_m2m.h"
#include <stddef.h>

int main(void)
{
    /*
     * Optional mini-lab entry point. The learner decides buffer storage,
     * lifetime, ownership, expected contents, and when to call the DMA module.
     * The initial starter intentionally performs no DMA configuration or transfer.
     */
    dma_m2m_experiment(NULL);
    for (;;) {
        __asm volatile ("nop");
    }
}
