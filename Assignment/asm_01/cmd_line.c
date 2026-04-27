/**
 ******************************************************************************
 * @author: GaoKong
 * @date:   13/08/2016
 ******************************************************************************
 **/

#include <string.h>
#include "cmd_line.h"
// #include "xprintf.h"

uint8_t cmd_line_parser(cmd_line_t *cmd_table, uint8_t *command)
{
    uint8_t cmd[MAX_CMD_SIZE];
    uint8_t *p_command = command;
    uint8_t cmd_index = 0;
    uint8_t index_check = 0;

    if (cmd_table == (cmd_line_t *)0)
    {
        return CMD_TBL_NOT_FOUND;
    }

    /* get cmd */
    /* skip leading spaces/tabs */
    while (*p_command == ' ' || *p_command == '\t')
        p_command++;

    while (*p_command)
    {
        if (*p_command == ' ' || *p_command == '\r' || *p_command == '\n')
        {
            break;
        }

        /* reserve space for terminating NUL */
        if (cmd_index >= (MAX_CMD_SIZE - 1))
        {
            return CMD_TOO_LONG;
        }

        cmd[cmd_index++] = *(p_command++);
    }

    /* ensure null-termination */
    cmd[cmd_index] = 0;

    /* find respective command in command table */
    while (cmd_table[index_check].cmd)
    {

        if (strcmp((const char *)cmd_table[index_check].cmd, (const char *)cmd) == 0)
        {

            /* perform respective function */
            /* skip leading separators before passing args */
            while (*p_command == ' ' || *p_command == '\t' || *p_command == '\r' || *p_command == '\n')
                p_command++;
            cmd_table[index_check].func(p_command); /* pass the rest of the command as argument */

            /* return success */
            return CMD_SUCCESS;
        }

        index_check++;
    }

    return CMD_NOT_FOUND; /* command not found */
}
