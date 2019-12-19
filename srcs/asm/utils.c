#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

int     line_iscomment(char *line)
{
    int i;

    i = 0;
    while (line[i] && line[i] <= 32)
        i++;
    if (line[i] == COMMENT_CHAR)
        return (1);
    return (-1);
}

int     len_instruc(t_instruc *instruc)
{
    int i;
    t_instruc *tmp;

    i = 0;
    tmp = instruc;
    while (tmp)
    {
        if (tmp->hexa_instruc)
            i = i + (ft_strlen(tmp->hexa_instruc) + 2);
        tmp = tmp->next;
    }
    return (i);
}

int     line_ispoint(char *line)
{
    int i;

    i = 0;
    while (line[i] && line[i] <= 32)
        i++;
    if (line[i] == '.')
        return (1);
    return (-1);
}

int     line_empty(char *line)
{
    int i;

    i = 0;
    while (line[i] && line[i] <= 32)
        i++;
    if (line[i] == '\0')
        return (-1);
    return (1);
}

int     get_adress(t_instruc *instruc, t_instruc *working)
{
    int res;
    t_instruc *tmp;

    res = 0;
    tmp = instruc;
    while (tmp != working)
    {
        if (tmp->hexa_instruc)
            res = res + ((ft_strlen(tmp->hexa_instruc) + 2) / 2);
        tmp = tmp->next;
    }
    return (res);
}

void    remplace_empty(t_instruc *instruc, int res)
{
    char *remplace;
    int i;
    int j;
    int size;

    size = 4;
    j = 0;
    i = 0;
    while (instruc->hexa_instruc[i] != '#')
        i++;
    ft_printf("res == %d\n", res);
    remplace = ft_uitoa_base((uint16_t)res, 16, 0);
    size = size - ft_strlen(remplace);
    while (size > 0)
    {
        remplace = ft_strjoin_fr("0", remplace, 2);
        size--;
    }
    while (remplace[j])
    {
        instruc->hexa_instruc[i] = remplace[j];
        j++;
        i++;
    }
    ft_strdel(&remplace);
}

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
    //ft_printf("opcode DANS LAST == %d\n", instruc->opcode);
    while (tmp->next)
        tmp = tmp->next;
    //ft_printf("opcode APRES LAST == %d\n", tmp->opcode);
    return (tmp);
}