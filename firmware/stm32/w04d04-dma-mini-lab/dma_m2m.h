#ifndef DMA_M2M_H
#define DMA_M2M_H

#include <stdint.h>

typedef struct {
    const uint32_t *source;
    uint32_t *destination;
    uint32_t element_count;
} dma_m2m_request_t;

void dma_m2m_experiment(const dma_m2m_request_t *request);

#endif
