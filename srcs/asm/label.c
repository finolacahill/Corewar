#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

int     put_adress_label(t_instruc *instruc)
{
    int i;
    t_instruc *tmp;

    tmp = instruc;
    i = 0;
    while (tmp->next)
    {
        i = i + ((ft_strlen(tmp->hexa_instruc) + 2) / 2);
        tmp = tmp->next;
    }
    return (i);
}

void    put_label(t_env *env, char *label)
{
    t_label *tmp;

    tmp = env->label;
    while (tmp->next)
        tmp = tmp->next;
    tmp->label = ft_strdup(label);
    tmp->adress = put_adress_label(env->instruc);
    tmp->next = new_label();
}

int     is_label(char *label)
{
    int i;

    i = 0;
    if (label == NULL)
        return (-1);
    while(label[i])
    {
        if (!ft_isdigit(label[i]) && !ft_isalpha(label[i]) && label[i] != '_')
            return (-1);
        i++;
    }
    return (1);
}

int   get_label(char *line, t_env *env)
{
    int i;
    char *label;

    i = 0;
    label = NULL;
    while(line[i] && line[i] != ':')
        i++;
    if (line[i] == ':')
        label = ft_strsub(line, 0, i);
    //printf("label %s\n", label);
    if (is_label(label) == 1)
        put_label(env, label);
    else
        i = 0;
    ft_strdel(&label);
    if (i == 0)
        return (0);
    return (i + 1);
}