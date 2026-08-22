#ifndef W02D06_DEBOUNCE_H
#define W02D06_DEBOUNCE_H

#include <stdbool.h>
#include <stdint.h>

typedef enum {
    DEBOUNCE_EVENT_NONE = 0,
    DEBOUNCE_EVENT_ACTIVATED,
    DEBOUNCE_EVENT_DEACTIVATED
} debounce_event_t;

typedef struct {
    uint32_t threshold_ticks;
    bool active_level;
} debounce_config_t;

typedef struct {
    debounce_config_t config;
    uint32_t candidate_since;
    bool stable_level;
    bool candidate_level;
    bool candidate_active;
} debounce_t;

/* Preconditions: ctx and config are non-NULL; threshold_ticks is greater than 0. */
void debounce_init(debounce_t *ctx,
                   const debounce_config_t *config,
                   bool initial_raw_level,
                   uint32_t now_ticks);

/*
 * Supply one raw sample and its monotonic uint32_t tick value.
 * A semantic event is returned only when the stable logical state changes.
 */
debounce_event_t debounce_sample(debounce_t *ctx,
                                 bool raw_level,
                                 uint32_t now_ticks);

bool debounce_stable_level(const debounce_t *ctx);

#endif
