#ifndef FAULT_DIAG_H
#define FAULT_DIAG_H

#include <stdint.h>

typedef struct {
    uint32_t cfsr;
    uint32_t hfsr;
    uint32_t mmfar;
    uint32_t bfar;
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r12;
    uint32_t lr;
    uint32_t pc;
    uint32_t xpsr;
} fault_diag_snapshot_t;

extern volatile fault_diag_snapshot_t g_fault_diag_snapshot;

/*
 * TODO(learner): design the capture interface only after defining which facts
 * must be preserved and how the active stack context will be identified.
 */

#endif
