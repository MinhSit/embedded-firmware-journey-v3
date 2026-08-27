#include "uart_parser.h"

static uart_parser_result_t no_event(void)
{
    const uart_parser_result_t result = {
        .event = UART_PARSER_EVENT_NONE,
        .led_action = UART_PARSER_LED_NONE,
        .rate_ms = 0U
    };
    return result;
}

void uart_parser_init(uart_parser_t *parser, uint32_t timeout_ticks)
{
    /* TODO(learner): establish the documented initial parser invariants. */
    (void)parser;
    (void)timeout_ticks;
}

uart_parser_result_t uart_parser_feed(uart_parser_t *parser,
                                     uint8_t byte,
                                     uint32_t now_tick)
{
    /*
     * TODO(learner): implement bounded byte accumulation, line termination,
     * recognition, argument parsing, and overlong-line recovery.
     */
    (void)parser;
    (void)byte;
    (void)now_tick;
    return no_event();
}

uart_parser_result_t uart_parser_poll(uart_parser_t *parser,
                                     uint32_t now_tick)
{
    /* TODO(learner): implement the documented inter-byte timeout transition. */
    (void)parser;
    (void)now_tick;
    return no_event();
}
