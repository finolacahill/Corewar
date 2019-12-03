#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

void    print_instruc(t_instruc *instruc)
{
    t_instruc *tmp;
    int i;

    i = 0;
    tmp = instruc;
    while (tmp)
    {
        printf("opcode == %d\n", tmp->opcode);
        printf("params == ");
        while (tmp->params[i] != 0)
        {
            printf("|| %d || ", tmp->params[i]);
            i++;
        }
        i = 0;
        tmp = tmp->next;
    }
}

void    print_label(t_label *labels)
{
    t_label *tmp;

    tmp = labels;
    while (tmp)
    {
        printf("%s\n", tmp->label);
        tmp = tmp->next;
    }
}