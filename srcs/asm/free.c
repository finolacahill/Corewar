#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"


void    free_label(t_label *label)
{
    t_label *tmp;

    while (tmp)
    {

    }
}

void    free_env(t_env *env)
{
    t_env *tmp;

    while (tmp)
    {
        free_instruc(env->instruc);
        free_label(env->label);
        tmp = tmp->next;
    }
}

void    free_all(t_env *env, header_t *header)
{
    free_env(env);
    free_header(header);
}