#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"


void    free_label(t_label *label)
{
    t_label *tmp;
    t_label *free_tmp;

    tmp = label;
    while (tmp)
   {
        ft_strdel(&tmp->label);
        free_tmp = tmp;
        tmp = tmp->next;
        free(free_tmp);
    }
}

void    free_instruc(t_instruc *instruc)
{
    t_instruc *tmp;
    t_instruc *free_tmp;

    tmp = instruc;
    while (tmp)
    {
        free(tmp->params);
        if (tmp->hexa_params)
        ft_strdel(&tmp->hexa_instruc);
        ft_strdel(&tmp->hexa_params);
        free_label(tmp->label);
        free_tmp = tmp;
        tmp = tmp->next;
        free(free_tmp);
    }
}

void    free_env(t_env *env)
{
    free_instruc(env->instruc);
    free_label(env->label);
}

void    free_all(t_env *env, header_t *header)
{
    free_env(env);
    free(env);
    //(void)header;
    free(header);
}