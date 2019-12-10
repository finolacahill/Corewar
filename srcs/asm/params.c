#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

void    is_label_exist(char *label, t_env *env, t_instruc *instruc)
{
    t_label *tmp;

    tmp = env->label;
    (void)instruc;
    while (tmp->next)
    {
        if (ft_strcmp(tmp->label, label) == 0)
        {
            // mettre adresse label: - adresse :label dans hexa_params;
        }
        tmp = tmp->next;
    }
}
int     param_register(t_instruc *instruc, int index_r, int j)
{
    char *hexa_r;

    if (index_r > 16)
        return (-1); // index du registre trop haut
    if ((instruc->params[j] & T_REG) != T_REG)
        return (-1); // mauvais parametre
    instruc->params[j] = T_REG; // pour l OCP;
    instruc->is_ocp = 1;
    hexa_r = ft_uitoa_base(index_r, 16, 0);
    if ((ft_strlen(hexa_r)) == 1)
     {
        hexa_r = ft_strjoin_fr("0", hexa_r, 2);
     }
    if (instruc->hexa_instruc != NULL)
        instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc, hexa_r, 1);
    else
        instruc->hexa_instruc = ft_strdup(hexa_r);
    ft_strdel(&hexa_r);
    return (1);
}

int     param_direct(t_instruc *instruc, char *index_r, int j)
{
    // faire la condition pour le label
    // faire la protection voir si c est bien que des chiffres
    char *hexa_d;
    int size;
 
    size = 4;
    if ((instruc->params[j] & T_DIR) != T_DIR)
        return (-1); // Mauvais parametre
    hexa_d = ft_uitoa_base(ft_atoi(index_r), 16, 0);
    if (instruc->for_direct == 0)
        size = 8;
    size = size - ft_strlen(hexa_d);
    instruc->params[j] = T_DIR;
    while (size > 0)
    {
        hexa_d = ft_strjoin_fr("0", hexa_d, 2);
        size--;
    }
    if (instruc->hexa_instruc != NULL)
        instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc, hexa_d, 1);
    else
        instruc->hexa_instruc = ft_strdup(hexa_d);
    ft_strdel(&hexa_d);
    return (1);
}

int     param_indirect(t_instruc *instruc, char *index_i, int j, t_env *env)
{
    // faire la condition pour le label
    // faire la protection voir si c est bien que des chiffres
    char *hexa_i;
    int size;

    size = 4;
    if (index_i[0] == ':')
        is_label_exist(&index_i[1], env, instruc);
    else
    {
    if ((instruc->params[j] & T_IND) != T_IND)
        return (-1);
    hexa_i = ft_uitoa_base(ft_atoi(index_i), 16, 0);
    instruc->params[j] = T_IND;
    size = size - ft_strlen(hexa_i);
    while (size > 0)
    {
        hexa_i = ft_strjoin_fr("0", hexa_i, 2);
        size--;
    }
    if (instruc->hexa_instruc != NULL)
        instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc, hexa_i, 1);
    else
        instruc->hexa_instruc = ft_strdup(hexa_i);
    ft_strdel(&hexa_i);
    }
    return (1);
}

int     what_params(char *params, t_instruc *instruc, int j, t_env *env)
{
    char *since_space;
    int i;

    i = 0;
    since_space = ft_strtrim(params);
    //while (since_space[i])
    {
        if (since_space[0] == 'r')
            param_register(instruc, ft_atoi(&since_space[1]), j);
        else if (since_space[0] == '%')
            param_direct(instruc, &since_space[1], j);
        else if (ft_isdigit(since_space[0]) || since_space[0] == ':')
            param_indirect(instruc, since_space, j, env);
        ft_printf("params hexa dans la boucle == %s\n", instruc->hexa_instruc);
        //else if (ft_isdigit(since_space[0]))
          //  param_direct(ins)
        j++;
        i++;
    }
    printf("since space == %s\n", since_space);
    ft_strdel(&since_space);
    return (0);
}

int     check_params(char **params, t_env *env)
{
    int j;
    t_instruc *tmp;

    tmp = get_last_intruct(env->instruc);
    j = 0;
    while (params[j])
    {
        what_params(&params[j][0], tmp, j, env);
        j++;
    }
    if (tmp->is_ocp == 1)
        get_ocp(tmp);
    return (0);
}

int     get_params(char *line, t_env *env)
{
    char **params;

    printf("avan split == %s\n", line);
    params = ft_strsplit(line, ',');
    printf("params == %s\n", params[0]);
    check_params(params, env);
    return (1);
}