#include <stdio.h>
#include <string.h>
#include "cmd_line.h"

int32_t cmd_help(uint8_t *args)
{
    printf("Available commands: help, led\n");
    return 0;
}

int32_t cmd_led(uint8_t *args)
{
    if (args)
        printf("LED command with arg: %s\n", args);
    else
        printf("LED command no arg\n");
    return 0;
}

cmd_line_t cmd_table[] = {
    {(int8_t *)"help", cmd_help, (int8_t *)"Show help"},
    {(int8_t *)"led", cmd_led, (int8_t *)"Control LED"},
    {0, 0, 0}};

/* MAIN */
int main(int argc, char const *argv[])
{
    uint8_t input[32];
    printf("Simple CLI (type 'exit' to quit)\n");
    while (1)
    {
        printf("> ");
        fflush(stdout);

        /* đọc input từ terminal */
        if (fgets((char *)input, sizeof(input), stdin) == NULL)
            continue;

        /* remove newline */
        input[strcspn((char *)input, "\n")] = 0;

        /* exit */
        if (strcmp((char *)input, "exit") == 0)
            break;

        /* gọi parser */
        uint8_t ret = cmd_line_parser(cmd_table, input);

        /* handle result */
        if (ret == CMD_NOT_FOUND)
            printf("Command not found\n");
        else if (ret == CMD_TOO_LONG)
            printf("Command too long\n");
    }
    return 0;
}