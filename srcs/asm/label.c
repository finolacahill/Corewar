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
        if (tmp->hexa_instruc)
        i = i + ((ft_strlen(tmp->hexa_instruc) + 2) / 2);
        tmp = tmp->next;
    }
    return (i);
}

void    use_label(t_env *env, t_label *label)
{
    t_instruc *tmp_i;
    t_label   *tmp_l;

    tmp_l = NULL;
    tmp_i = env->instruc;
    while (tmp_i)
    {
        tmp_l = tmp_i->label;
        while (tmp_l)
        {
            if (tmp_l->label && ft_strcmp(tmp_l->label, label->label) == 0)
                remplace_empty(tmp_i, label->adress - tmp_l->adress);
            tmp_l = tmp_l->next;
        }
        tmp_i = tmp_i->next;
    }
}

void    put_label(t_env *env, char *label)
{
    t_label *tmp;

    tmp = env->label;
    while (tmp->next)
        tmp = tmp->next;
    tmp->label = ft_strdup(label);
      ft_printf("lol");
    tmp->adress = put_adress_label(env->instruc);
    tmp->next = new_label();
    use_label(env, tmp);
}

int     is_label(char *label)
{
    int i;

    i = 0;
    if (label == NULL)
        return (-1);
    // verifier aussi si il y a deux fois le meme label;
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
    ft_printf("label == %s\n", label);
    if (is_label(label) == 1)
        put_label(env, label);
    else
        i = 0;
    if (label != NULL)
        ft_strdel(&label);
    if (i == 0)
        return (0);
    return (i + 1);
}