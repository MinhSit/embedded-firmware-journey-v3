#ifndef UART_PARSER_H
#define UART_PARSER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define UART_PARSER_MAX_LINE_LENGTH 32U

/*
 * STARTER CONTRACT — implementation detail, not roadmap policy.
 *
 * - Commands are lowercase ASCII and terminated by LF; CRLF is also accepted.
 * - Empty lines produce no event.
 * - Supported forms are: help, status, led on, led off, led toggle,
 *   and rate <1..10000> where the argument is decimal milliseconds.
 * - Leading/trailing whitespace, extra arguments, unknown commands, and invalid
 *   numeric forms are rejected.
 * - timeout_ticks is an inter-byte timeout measured from the most recent byte.
 * - An overlong line emits LINE_TOO_LONG once, discards through the next line
 *   terminator, then accepts a fresh command.
 */

typedef enum {
    UART_PARSER_EVENT_NONE = 0,
    UART_PARSER_EVENT_HELP,
    UART_PARSER_EVENT_STATUS,
    UART_PARSER_EVENT_LED,
    UART_PARSER_EVENT_RATE,
    UART_PARSER_EVENT_UNKNOWN_COMMAND,
    UART_PARSER_EVENT_MALFORMED_ARGUMENT,
    UART_PARSER_EVENT_LINE_TOO_LONG,
    UART_PARSER_EVENT_TIMEOUT
} uart_parser_event_t;

typedef enum {
    UART_PARSER_LED_NONE = 0,
    UART_PARSER_LED_ON,
    UART_PARSER_LED_OFF,
    UART_PARSER_LED_TOGGLE
} uart_parser_led_action_t;

typedef struct {
    uart_parser_event_t event;
    uart_parser_led_action_t led_action;
    uint32_t rate_ms;
} uart_parser_result_t;

typedef struct {
    char line[UART_PARSER_MAX_LINE_LENGTH + 1U];
    size_t line_length;
    uint32_t timeout_ticks;
    uint32_t last_byte_tick;
    bool line_active;
    bool discarding_overlong;
} uart_parser_t;

void uart_parser_init(uart_parser_t *parser, uint32_t timeout_ticks);
uart_parser_result_t uart_parser_feed(uart_parser_t *parser,
                                     uint8_t byte,
                                     uint32_t now_tick);
uart_parser_result_t uart_parser_poll(uart_parser_t *parser,
                                     uint32_t now_tick);

#endif
