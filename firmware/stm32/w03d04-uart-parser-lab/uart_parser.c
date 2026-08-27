#include "uart_parser.h"
#include <string.h>

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
    if (parser == NULL) {
        return;
    }
    parser->line[0] = '\0';
    parser->line_length = 0U;
    parser->timeout_ticks = timeout_ticks;
    parser->last_byte_tick = 0U;
    parser->line_active = false;
    parser->discarding_overlong = false;
}

uart_parser_result_t uart_parser_feed(uart_parser_t *parser,
                                     uint8_t byte,
                                     uint32_t now_tick)
{
    /*
     * TODO(learner): implement bounded byte accumulation, line termination,
     * recognition, argument parsing, and overlong-line recovery.
     */
    if (parser == NULL) {
        return no_event();
    }

    /* Bỏ qua '\r' hoàn toàn và giữ nguyên state (không kích hoạt line_active trên buffer rỗng) */
    if (byte == '\r') {
        if (parser->line_active) {
            parser->last_byte_tick = now_tick;
        }
        return no_event();
    }

    /* Xử lý kết thúc dòng '\n' */
    if (byte == '\n') {
        bool was_discarding = parser->discarding_overlong;
        size_t len = parser->line_length;

        if (was_discarding) {
            parser->line_length = 0U;
            parser->line[0] = '\0';
            parser->line_active = false;
            parser->discarding_overlong = false;
            return no_event();
        }

        if (len == 0U) {
            parser->line_active = false;
            return no_event();
        }

        uart_parser_result_t result = {
            .event = UART_PARSER_EVENT_NONE,
            .led_action = UART_PARSER_LED_NONE,
            .rate_ms = 0U
        };

        if (strcmp(parser->line, "help") == 0) {
            result.event = UART_PARSER_EVENT_HELP;
        } else if (strcmp(parser->line, "status") == 0) {
            result.event = UART_PARSER_EVENT_STATUS;
        } else if (strcmp(parser->line, "led on") == 0) {
            result.event = UART_PARSER_EVENT_LED;
            result.led_action = UART_PARSER_LED_ON;
        } else if (strcmp(parser->line, "led off") == 0) {
            result.event = UART_PARSER_EVENT_LED;
            result.led_action = UART_PARSER_LED_OFF;
        } else if (strcmp(parser->line, "led toggle") == 0) {
            result.event = UART_PARSER_EVENT_LED;
            result.led_action = UART_PARSER_LED_TOGGLE;
        } else if (strncmp(parser->line, "led ", 4) == 0 || strcmp(parser->line, "led") == 0) {
            result.event = UART_PARSER_EVENT_MALFORMED_ARGUMENT;
        } else if (strncmp(parser->line, "rate ", 5) == 0) {
            const char *arg = parser->line + 5;
            if (*arg == '\0') {
                result.event = UART_PARSER_EVENT_MALFORMED_ARGUMENT;
            } else {
                uint32_t val = 0U;
                bool valid = true;
                for (size_t i = 0; arg[i] != '\0'; i++) {
                    if (arg[i] < '0' || arg[i] > '9') {
                        valid = false;
                        break;
                    }
                    val = val * 10U + (uint32_t)(arg[i] - '0');
                    if (val > 10000U) {
                        valid = false;
                        break;
                    }
                }

                if (!valid || val < 1U) {
                    result.event = UART_PARSER_EVENT_MALFORMED_ARGUMENT;
                } else {
                    result.event = UART_PARSER_EVENT_RATE;
                    result.rate_ms = val;
                }
            }
        } else if (strcmp(parser->line, "rate") == 0) {
            result.event = UART_PARSER_EVENT_MALFORMED_ARGUMENT;
        } else {
            result.event = UART_PARSER_EVENT_UNKNOWN_COMMAND;
        }

        parser->line_length = 0U;
        parser->line[0] = '\0';
        parser->line_active = false;
        parser->discarding_overlong = false;

        return result;
    }

    /* Đang trong trạng thái bỏ qua phần dư của dòng quá dài */
    if (parser->discarding_overlong) {
        parser->last_byte_tick = now_tick;
        return no_event();
    }

    /* Kiểm tra tràn buffer: byte thứ UART_PARSER_MAX_LINE_LENGTH + 1 */
    if (parser->line_length >= UART_PARSER_MAX_LINE_LENGTH) {
        parser->discarding_overlong = true;
        parser->last_byte_tick = now_tick;
        parser->line_active = true;
        const uart_parser_result_t result = {
            .event = UART_PARSER_EVENT_LINE_TOO_LONG,
            .led_action = UART_PARSER_LED_NONE,
            .rate_ms = 0U
        };
        return result;
    }

    /* Nhận ký tự hợp lệ: cập nhật timestamp và bật flag active */
    parser->last_byte_tick = now_tick;
    parser->line_active = true;
    parser->line[parser->line_length++] = (char)byte;
    parser->line[parser->line_length] = '\0';

    return no_event();
}

uart_parser_result_t uart_parser_poll(uart_parser_t *parser,
                                     uint32_t now_tick)
{
    /* TODO(learner): implement the documented inter-byte timeout transition. */
    if (parser == NULL || !parser->line_active) {
        return no_event();
    }

    if (parser->timeout_ticks > 0U && (now_tick - parser->last_byte_tick) >= parser->timeout_ticks) {
        parser->line_length = 0U;
        parser->line[0] = '\0';
        parser->line_active = false;
        parser->discarding_overlong = false;

        const uart_parser_result_t result = {
            .event = UART_PARSER_EVENT_TIMEOUT,
            .led_action = UART_PARSER_LED_NONE,
            .rate_ms = 0U
        };
        return result;
    }

    return no_event();
}
