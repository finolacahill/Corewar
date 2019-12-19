#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

void    put_comment(t_env *env, char *line)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (line[i] && line[i] != '"')
        i++;
    if (line[i] == '\0')
        error_cmd(1, "comment", env->line);
    i++;
    while  (line[i] && line[i] != '"')
    {
        env->header->comment[j] = line[i];     
        j++;
        i++;
    }
    if (line[i] == '\0')
         error_cmd(1, "comment", env->line);
    i++;
    /*while (line[i])
    {
        if ()
    }*/
    //ft_printf("comment == %s\n", env->header->comment);
}
void    put_name(t_env *env, char *line)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (line[i] && line[i] != '"')
        i++;
    if (line[i] == '\0')
        error_cmd(1, "name", env->line);
    i++;
    while  (line[i] && line[i] != '"')
    {
        env->header->prog_name[j] = line[i];     
        j++;
        i++;
    }
    if (line[i] == '\0')
        error_cmd(1, "name", env->line);
    i++;
    while (line[i])
    {
        if (line[i] != ';' && line[i] > ' ')
            error_cmd(2, "name", env->line);
        i++;
    }
   // ft_printf("name == %s\n", env->header->prog_name);
}

void    go_cmd(t_env *env, char *line)
{
    int i;
    char *check;
    int j;
    int len;

    i = 0;
    while (line[i] <= ' ')
        i++;
    len = i;
    i++;
    j = i;
    while (line[j] && line[j] > ' ')
        j++;
    check = ft_strsub(line, i, j - len - 1);
    //ft_printf("check == %s\n", check);
    if (line[i] && ft_strcmp("name", check) == 0)
        put_name(env, &line[i]);
   else if (line[i] && ft_strcmp("comment", check) == 0)
       put_comment(env, &line[i]);
    ft_strdel(&check);
}