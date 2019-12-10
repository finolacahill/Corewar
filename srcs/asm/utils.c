#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

void    next_instruc(t_env *env)
{
    t_instruc *tmp;

    tmp = env->instruc;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new_instruct();
}

t_instruc *get_last_intruct(t_instruc *instruc)
{
    t_instruc *tmp;

    tmp = instruc;
    ft_printf("opcode DANS LAST == %d\n", instruc->opcode);
    while (tmp->next)
        tmp = tmp->next;
    ft_printf("opcode APRES LAST == %d\n", tmp->opcode);
    return (tmp);
}