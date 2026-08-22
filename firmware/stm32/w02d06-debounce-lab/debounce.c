#include "debounce.h"

void debounce_init(debounce_t *ctx,
                   const debounce_config_t *config,
                   bool initial_raw_level,
                   uint32_t now_ticks)
{
    ctx->config = *config;
    ctx->candidate_since = now_ticks;
    ctx->stable_level = initial_raw_level;
    ctx->candidate_level = initial_raw_level;
    ctx->candidate_active = false;
}

debounce_event_t debounce_sample(debounce_t *ctx,
                                 bool raw_level,
                                 uint32_t now_ticks)
{
    /* TODO(learner): implement the non-blocking tick/state-machine core. */
    if(ctx->stable_level == raw_level){
        ctx->candidate_active = false;
        return DEBOUNCE_EVENT_NONE;
    }
    else{
        if(ctx->candidate_active == false || ctx->candidate_level != raw_level){
            ctx->candidate_active = true;
            ctx->candidate_level = raw_level;
            ctx->candidate_since = now_ticks;
        }
        else{
            uint32_t elapsed = now_ticks - ctx->candidate_since;
            if(elapsed >= ctx->config.threshold_ticks){
                ctx->stable_level = ctx->candidate_level;
                ctx->candidate_active = false;
                if(ctx->stable_level == ctx->config.active_level) return DEBOUNCE_EVENT_ACTIVATED;
                else return DEBOUNCE_EVENT_DEACTIVATED;
            }
        }
    }
    return DEBOUNCE_EVENT_NONE;
}

bool debounce_stable_level(const debounce_t *ctx)
{
    return ctx->stable_level;
}
