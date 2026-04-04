#include "../lib/unity.h"
#include "cmd_line.h"
#include <string.h>

static short help_called;
static short led_called;

int32_t help_handler(uint8_t *argv)
{
    help_called++;
    return 0;
}

int32_t led_handler(uint8_t *argv)
{
    led_called++;
    return 0;
}

cmd_line_t test_table[] = {
    {(int8_t *)"help", help_handler, (int8_t *)"help info"},
    {(int8_t *)"led", led_handler, (int8_t *)"led info"},
    {0, 0, 0}};

void setUp(void)
{
    help_called = 0;
    led_called = 0;
}

void tearDown(void) {}

/* ================= TEST CASES ================= */

/* Test 1: Command hợp lệ */
void test_help_command(void)
{
    uint8_t cmd[] = "help";
    uint8_t ret = cmd_line_parser(test_table, cmd);
    TEST_ASSERT_EQUAL(CMD_SUCCESS, ret);
    TEST_ASSERT_EQUAL(1, help_called);
}

/* Test 2: Command có argument */
void test_led_command(void)
{
    uint8_t cmd[] = "led on";
    uint8_t ret = cmd_line_parser(test_table, cmd);
    TEST_ASSERT_EQUAL(CMD_SUCCESS, ret);
    TEST_ASSERT_EQUAL(1, led_called);
}

/* Test 3: Command không tồn tại */
void test_unknown_command(void)
{
    uint8_t cmd[] = "abc";
    uint8_t ret = cmd_line_parser(test_table, cmd);
    TEST_ASSERT_EQUAL(CMD_NOT_FOUND, ret);
}

/* Test 4: Command quá dài */
void test_command_too_long(void)
{
    uint8_t cmd[] = "veryverylongcommand";
    uint8_t ret = cmd_line_parser(test_table, cmd);
    TEST_ASSERT_EQUAL(CMD_TOO_LONG, ret);
}

/* Test 5: Command rỗng */
void test_null_command(void)
{
    uint8_t cmd[] = "";
    uint8_t ret = cmd_line_parser(test_table, cmd);
    TEST_ASSERT_EQUAL(CMD_NOT_FOUND, ret);
}

/* Test 6: Table NULL */
void test_null_table(void)
{
    uint8_t cmd[] = "help";
    uint8_t ret = cmd_line_parser(NULL, cmd);
    TEST_ASSERT_EQUAL(CMD_TBL_NOT_FOUND, ret);
}

/* Test 7: Command hợp lệ nhưng sai argument */
void test_invalid_argument(void)
{
    uint8_t cmd[] = "led invalid_arg";
    uint8_t ret = cmd_line_parser(test_table, cmd);
    TEST_ASSERT_EQUAL(CMD_SUCCESS, ret);
}

/* Test 8: Command có nhiều khoảng trắng */
void test_multiple_spaces(void)
{
    uint8_t cmd[] = "   led on   ";
    uint8_t ret = cmd_line_parser(test_table, cmd);
    TEST_ASSERT_EQUAL(CMD_SUCCESS, ret);
}

/* Test 9: Command viết hoa */
void test_uppercase_command(void)
{
    uint8_t cmd[] = "HELP";
    uint8_t ret = cmd_line_parser(test_table, cmd);
    TEST_ASSERT_EQUAL(CMD_NOT_FOUND, ret);
}

/* Test 10: Command gần đúng */
void test_similar_command(void)
{
    uint8_t cmd[] = "hel";
    uint8_t ret = cmd_line_parser(test_table, cmd);
    TEST_ASSERT_EQUAL(CMD_NOT_FOUND, ret);
}

/* ================= MAIN TEST ================= */

int main(void)
{
    UNITY_BEGIN();

    // TEST CASES
    RUN_TEST(test_help_command);
    RUN_TEST(test_led_command);
    RUN_TEST(test_unknown_command);
    RUN_TEST(test_command_too_long);
    RUN_TEST(test_null_command);

    RUN_TEST(test_null_table);
    RUN_TEST(test_invalid_argument);
    RUN_TEST(test_multiple_spaces);
    RUN_TEST(test_uppercase_command);
    RUN_TEST(test_similar_command);

    return UNITY_END();
}