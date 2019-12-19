#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

void    put_hexa_label(int16_t label,t_instruc *instruc, int size)
{
    char *hexa_l;

    //ft_printf("res == %d\n", label);
    if (label >= 0)
        hexa_l = ft_uitoa_base((uint16_t)label, 16, 0);
    else
        hexa_l = ft_uitoa_base((uint16_t)label, 16, 0);
    size = size - ft_strlen(hexa_l);
    while (size > 0)
    {
        hexa_l = ft_strjoin_fr("0", hexa_l, 2);
        size--;
    }
    if (instruc->hexa_instruc != NULL)
        instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc, hexa_l, 1);
    else
        instruc->hexa_instruc = ft_strdup(hexa_l);
    ft_strdel(&hexa_l);
}

void    put_label_instruc(t_instruc *instruc, char *label, int16_t adress, int size)
{
    t_label *tmp;
    char    *empty;

    empty = ft_strdup("#");
    size--;
    tmp = instruc->label;
    while (tmp->next)
        tmp = tmp->next;
    tmp->label = ft_strdup(label);
    tmp->adress = adress;
   // ft_printf("adress %d for %s\n", adress, label);
    tmp->size = size + 1;
    tmp->next = new_label();
    while (size > 0)
    {
        empty = ft_strjoin_fr(empty, "#", 1);
        size--;
    }
     if (instruc->hexa_instruc != NULL)
        instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc, empty, 1);
    else
        instruc->hexa_instruc = ft_strdup(empty);
    ft_strdel(&empty);
}

void    is_label_exist(char *label, t_env *env, t_instruc *instruc, int size)
{
    t_label *tmp;
    int adress;
    int16_t res;

    adress = get_adress(env->instruc, instruc);
    tmp = env->label;
    while (tmp->next)
    {
        if (ft_strcmp(tmp->label, label) == 0)
        {
            res = tmp->adress - adress;
            put_hexa_label(res, instruc, size);
            return ;
        }
        tmp = tmp->next;
    }
    if (is_label(label) == -1)
        error(5, env->line, -1, label);
    put_label_instruc(instruc, label, adress, size);
}

int     param_register(t_instruc *instruc, char *c_index_r, int j, t_env *env)
{
    char *hexa_r;
    int index_r;

    if (check_numbers(c_index_r) == -1)
        error(10, env->line, j, ft_itoa(instruc->opcode));
    index_r = ft_atoi(c_index_r);
    if (index_r > REG_NUMBER || index_r < 0)
        error(3, env->line, j, NULL); // index du registre trop haut
    if ((instruc->params[j] & T_REG) != T_REG)
       error(4, env->line, j, ft_itoa(instruc->opcode)); // mauvais parametre
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

int     param_direct(t_instruc *instruc, char *index_d, int j, t_env *env)
{
    // faire la condition pour le label
    // faire la protection voir si c est bien que des chiffres + exception pour le comment
    char *hexa_d;
    int size;
 
    size = 4;
    if (instruc->for_direct == 0)
        size = 8;
    if ((instruc->params[j] & T_DIR) != T_DIR)
       error(4, env->line, j, ft_itoa(instruc->opcode));
       // error(4, env->line, j, ft_itoa(instruc->opcode)); // Mauvais parametre
    instruc->params[j] = T_DIR;
    if (index_d[0] == ':')
        is_label_exist(&index_d[1], env, instruc, size);
    else if (check_numbers(index_d) == -1)
        error(10, env->line, j, ft_itoa(instruc->opcode));
    else
    {
    hexa_d = ft_uitoa_base((uint16_t)ft_atoi(index_d), 16, 0);
    size = size - ft_strlen(hexa_d);
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
    }
    return (1);
}

int     param_indirect(t_instruc *instruc, char *index_i, int j, t_env *env)
{
    // faire la condition pour le label
    // faire la protection voir si c est bien que des chiffres
    char *hexa_i;
    int size;

    size = 4;
    if ((instruc->params[j] & T_IND) != T_IND)
       error(4, env->line, j, ft_itoa(instruc->opcode));
        //error(4, env->line, j, ft_itoa(instruc->opcode)); // mauvais parametre
    instruc->params[j] = T_IND;
    if (index_i[0] == ':')
        is_label_exist(&index_i[1], env, instruc, size);
    else if (check_numbers(index_i) == -1)
        error(10, env->line, j, ft_itoa(instruc->opcode));
    else
    {
    hexa_i = ft_uitoa_base((uint16_t)ft_atoi(index_i), 16, 0);
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
    if (ft_strlen(since_space) == 0)
        error(10, env->line, j, ft_itoa(instruc->opcode));
        if (since_space[0] == 'r')
            param_register(instruc, &since_space[1], j, env);
        else if (since_space[0] == '%')
            param_direct(instruc, &since_space[1], j, env);
        else if ((ft_isdigit(since_space[0]) || (ft_isdigit(since_space[1]) && since_space[0] == '-')) || since_space[0] == ':')
            param_indirect(instruc, since_space, j, env);
     // ft_printf("params hexa dans la boucle == %s\n", instruc->hexa_instruc);
        //else if (ft_isdigit(since_space[0]))
          //  param_direct(ins)
    //ft_printf("since space == %s || size == %d\n", since_space, ft_strlen(since_space));
   //if (since_space[0])
    ft_strdel(&since_space); // malloc free error
    return (0);
}

int     check_params(char **params, t_env *env)
{
    int j;
    t_instruc *tmp;

    tmp = get_last_intruct(env->instruc);
    j = 0;
    while (params[j])
        j++;
    if (j != tmp->nbr_params)
        error(9, env->line, -1, ft_itoa(tmp->opcode));
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
    //char **comment;
    char **params;

    //comment = ft_strsplit(line, COMMENT_CHAR);
    params = ft_strsplit(line, ',');
    check_params(params, env);
    ft_strrdel(params);
     //ft_printf("params == %s\n", params[0]);
    return (1);
}