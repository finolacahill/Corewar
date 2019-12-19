#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

t_error_cmd error_cmd_tab[3] =
{
    {1, "Error: Double \"\" does not exist in "},
    {2, "Error: Lexical error in "},
    {0, NULL}
};

void    error_cmd(int type, char *cmd, int line)
{
    int i;

    i = 0;
    while (error_cmd_tab[i].message)
    {
        if (error_cmd_tab[i].type == type)
        {
            ft_printf("%s", error_cmd_tab[i].message);
            ft_printf("%s", cmd);
            ft_printf(" in line %d", line);
            exit(0);
        }
        i++;
    }
    exit (0);
}