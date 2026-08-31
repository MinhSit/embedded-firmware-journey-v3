#include "uart_parser.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static unsigned int g_tests_run = 0U;
static unsigned int g_tests_failed = 0U;

static void report(const char *id, const char *name, bool passed)
{
    ++g_tests_run;
    if (passed) {
        printf("PASS %s %s\n", id, name);
    } else {
        ++g_tests_failed;
        printf("FAIL %s %s\n", id, name);
    }
}

static uart_parser_result_t feed_bytes(uart_parser_t *parser,
                                       const uint8_t *bytes,
                                       size_t length,
                                       uint32_t first_tick)
{
    uart_parser_result_t observed = {0};
    for (size_t i = 0U; i < length; ++i) {
        const uart_parser_result_t current =
            uart_parser_feed(parser, bytes[i], first_tick + (uint32_t)i);
        if (current.event != UART_PARSER_EVENT_NONE) {
            observed = current;
        }
    }
    return observed;
}

static uart_parser_result_t feed_text(uart_parser_t *parser,
                                      const char *text,
                                      uint32_t first_tick)
{
    return feed_bytes(parser, (const uint8_t *)text, strlen(text), first_tick);
}

static bool test_init(void)
{
    uart_parser_t parser;
    memset(&parser, 0xA5, sizeof(parser));

    uart_parser_init(&parser, 10U);

    return (parser.line_length == 0U)
        && (parser.timeout_ticks == 10U)
        && !parser.line_active
        && !parser.discarding_overlong
        && (parser.line[0] == '\0');
}

static bool test_help_lf(void)
{
    uart_parser_t parser = {0};
    uart_parser_init(&parser, 10U);
    return feed_text(&parser, "help\n", 1U).event == UART_PARSER_EVENT_HELP;
}

static bool test_status_crlf(void)
{
    uart_parser_t parser = {0};
    uart_parser_init(&parser, 10U);
    return feed_text(&parser, "status\r\n", 1U).event == UART_PARSER_EVENT_STATUS;
}

static bool test_led_forms(void)
{
    uart_parser_t parser = {0};
    uart_parser_init(&parser, 10U);

    const uart_parser_result_t on = feed_text(&parser, "led on\n", 1U);
    const uart_parser_result_t off = feed_text(&parser, "led off\n", 20U);
    const uart_parser_result_t toggle = feed_text(&parser, "led toggle\n", 40U);

    return (on.event == UART_PARSER_EVENT_LED)
        && (on.led_action == UART_PARSER_LED_ON)
        && (off.event == UART_PARSER_EVENT_LED)
        && (off.led_action == UART_PARSER_LED_OFF)
        && (toggle.event == UART_PARSER_EVENT_LED)
        && (toggle.led_action == UART_PARSER_LED_TOGGLE);
}

static bool test_rate_valid_boundaries(void)
{
    uart_parser_t parser = {0};
    uart_parser_init(&parser, 10U);

    const uart_parser_result_t low = feed_text(&parser, "rate 1\n", 1U);
    const uart_parser_result_t high = feed_text(&parser, "rate 10000\n", 30U);

    return (low.event == UART_PARSER_EVENT_RATE) && (low.rate_ms == 1U)
        && (high.event == UART_PARSER_EVENT_RATE) && (high.rate_ms == 10000U);
}

static bool test_unknown_command(void)
{
    uart_parser_t parser = {0};
    uart_parser_init(&parser, 10U);
    return feed_text(&parser, "hello\n", 1U).event
        == UART_PARSER_EVENT_UNKNOWN_COMMAND;
}

static bool test_malformed_arguments(void)
{
    uart_parser_t parser = {0};
    uart_parser_init(&parser, 10U);

    const uart_parser_result_t bad_led = feed_text(&parser, "led blink\n", 1U);
    const uart_parser_result_t bad_rate = feed_text(&parser, "rate abc\n", 30U);
    const uart_parser_result_t zero_rate = feed_text(&parser, "rate 0\n", 60U);
    const uart_parser_result_t high_rate =
        feed_text(&parser, "rate 10001\n", 90U);

    return (bad_led.event == UART_PARSER_EVENT_MALFORMED_ARGUMENT)
        && (bad_rate.event == UART_PARSER_EVENT_MALFORMED_ARGUMENT)
        && (zero_rate.event == UART_PARSER_EVENT_MALFORMED_ARGUMENT)
        && (high_rate.event == UART_PARSER_EVENT_MALFORMED_ARGUMENT);
}

static bool test_empty_line(void)
{
    uart_parser_t parser = {0};
    uart_parser_init(&parser, 10U);
    const uart_parser_result_t result = feed_text(&parser, "\n", 1U);
    return (result.event == UART_PARSER_EVENT_NONE)
        && (parser.line_length == 0U)
        && !parser.line_active;
}

static bool test_exact_length_boundary(void)
{
    uart_parser_t parser = {0};
    uint8_t input[UART_PARSER_MAX_LINE_LENGTH + 1U];
    memset(input, 'x', UART_PARSER_MAX_LINE_LENGTH);
    input[UART_PARSER_MAX_LINE_LENGTH] = (uint8_t)'\n';

    uart_parser_init(&parser, 100U);
    const uart_parser_result_t result =
        feed_bytes(&parser, input, sizeof(input), 1U);

    return (result.event == UART_PARSER_EVENT_UNKNOWN_COMMAND)
        && !parser.discarding_overlong
        && (parser.line_length == 0U);
}

static bool test_overlong_no_buffer_overrun(void)
{
    struct guarded_parser {
        uint32_t before;
        uart_parser_t parser;
        uint32_t after;
    } guarded = {
        .before = 0x11223344U,
        .parser = {{0}},
        .after = 0x55667788U
    };

    uint8_t input[UART_PARSER_MAX_LINE_LENGTH + 2U];
    memset(input, 'y', UART_PARSER_MAX_LINE_LENGTH + 1U);
    input[UART_PARSER_MAX_LINE_LENGTH + 1U] = (uint8_t)'\n';

    uart_parser_init(&guarded.parser, 100U);
    const uart_parser_result_t result =
        feed_bytes(&guarded.parser, input, sizeof(input), 1U);

    return (result.event == UART_PARSER_EVENT_LINE_TOO_LONG)
        && (guarded.before == 0x11223344U)
        && (guarded.after == 0x55667788U)
        && (guarded.parser.line_length <= UART_PARSER_MAX_LINE_LENGTH);
}

static bool test_partial_line_timeout(void)
{
    uart_parser_t parser = {0};
    uart_parser_init(&parser, 10U);
    (void)feed_text(&parser, "hel", 1U);

    const uart_parser_result_t timeout = uart_parser_poll(&parser, 13U);
    const uart_parser_result_t repeated_poll = uart_parser_poll(&parser, 14U);

    return (timeout.event == UART_PARSER_EVENT_TIMEOUT)
        && (repeated_poll.event == UART_PARSER_EVENT_NONE)
        && (parser.line_length == 0U)
        && !parser.line_active;
}

static bool test_timeout_tick_wrap(void)
{
    uart_parser_t parser = {0};
    uart_parser_init(&parser, 5U);
    (void)uart_parser_feed(&parser, (uint8_t)'h', UINT32_MAX - 2U);

    return uart_parser_poll(&parser, 2U).event == UART_PARSER_EVENT_TIMEOUT;
}

static bool test_recovery_after_invalid(void)
{
    uart_parser_t parser = {0};
    uart_parser_init(&parser, 20U);
    const uart_parser_result_t invalid = feed_text(&parser, "wat\n", 1U);
    const uart_parser_result_t valid = feed_text(&parser, "help\n", 20U);

    return (invalid.event == UART_PARSER_EVENT_UNKNOWN_COMMAND)
        && (valid.event == UART_PARSER_EVENT_HELP);
}

static bool test_recovery_after_overlong(void)
{
    uart_parser_t parser = {0};
    uint8_t input[UART_PARSER_MAX_LINE_LENGTH + 2U];
    memset(input, 'z', UART_PARSER_MAX_LINE_LENGTH + 1U);
    input[UART_PARSER_MAX_LINE_LENGTH + 1U] = (uint8_t)'\n';

    uart_parser_init(&parser, 100U);
    const uart_parser_result_t overlong =
        feed_bytes(&parser, input, sizeof(input), 1U);
    const uart_parser_result_t valid = feed_text(&parser, "status\n", 100U);

    return (overlong.event == UART_PARSER_EVENT_LINE_TOO_LONG)
        && (valid.event == UART_PARSER_EVENT_STATUS);
}

static bool test_recovery_after_timeout(void)
{
    uart_parser_t parser = {0};
    uart_parser_init(&parser, 5U);
    (void)feed_text(&parser, "rat", 1U);
    const uart_parser_result_t timeout = uart_parser_poll(&parser, 8U);
    const uart_parser_result_t valid = feed_text(&parser, "rate 25\n", 20U);

    return (timeout.event == UART_PARSER_EVENT_TIMEOUT)
        && (valid.event == UART_PARSER_EVENT_RATE)
        && (valid.rate_ms == 25U);
}

static bool test_repeated_commands(void)
{
    uart_parser_t parser = {0};
    uart_parser_init(&parser, 20U);
    const uart_parser_result_t first = feed_text(&parser, "status\n", 1U);
    const uart_parser_result_t second = feed_text(&parser, "status\n", 20U);

    return (first.event == UART_PARSER_EVENT_STATUS)
        && (second.event == UART_PARSER_EVENT_STATUS);
}

int main(void)
{
    report("W03D04-T01", "INIT", test_init());
    report("W03D04-T02", "HELP_LF", test_help_lf());
    report("W03D04-T03", "STATUS_CRLF", test_status_crlf());
    report("W03D04-T04", "LED_FORMS", test_led_forms());
    report("W03D04-T05", "RATE_VALID_BOUNDARIES", test_rate_valid_boundaries());
    report("W03D04-T06", "UNKNOWN_COMMAND", test_unknown_command());
    report("W03D04-T07", "MALFORMED_ARGUMENTS", test_malformed_arguments());
    report("W03D04-T08", "EMPTY_LINE", test_empty_line());
    report("W03D04-T09", "EXACT_LENGTH_BOUNDARY", test_exact_length_boundary());
    report("W03D04-T10", "OVERLONG_NO_BUFFER_OVERRUN",
           test_overlong_no_buffer_overrun());
    report("W03D04-T11", "PARTIAL_LINE_TIMEOUT", test_partial_line_timeout());
    report("W03D04-T12", "TIMEOUT_TICK_WRAP", test_timeout_tick_wrap());
    report("W03D04-T13", "RECOVERY_AFTER_INVALID", test_recovery_after_invalid());
    report("W03D04-T14", "RECOVERY_AFTER_OVERLONG", test_recovery_after_overlong());
    report("W03D04-T15", "RECOVERY_AFTER_TIMEOUT", test_recovery_after_timeout());
    report("W03D04-T16", "REPEATED_COMMANDS", test_repeated_commands());

    printf("SUMMARY: %u tests, %u failed\n", g_tests_run, g_tests_failed);
    return (g_tests_failed == 0U) ? 0 : 1;
}
