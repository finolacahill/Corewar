#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

t_error_cmd error_cmd_tab[6] =
{
    {1, "Error: Double \"\" does not exist in "},
    {2, "Error: Lexical error in "},
    {3, "Error: This CMD already exist -> "},
    {4, "Error: This CMD does not exist -> "},
    {5, "Error: CMD missing -> "},
    {0, NULL}
};

void    which_cmd_error(header_t *header)
{
    if (header->n == 0)
        error_cmd(5, "name", -1);
    else
        error_cmd(5, "comment", -1);
}

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
            if (line >= 0)
                ft_printf(" in line %d", line + 1);
            exit(0);
        }
        i++;
    }
    exit (0);
}