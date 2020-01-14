/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 01:43:50 by yodana            #+#    #+#             */
/*   Updated: 2020/01/09 16:10:42 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		put_hexa_label(int label, t_instruc *instruc, int size)
{
	char *hexa_l;

	if (size == 8)
		hexa_l = ft_uitoa_base((uint32_t)label, 16, 0);
	else
		hexa_l = ft_uitoa_base((uint16_t)label, 16, 0);
	if (hexa_l == NULL)
		return (-8);
	size = size - ft_strlen(hexa_l);
	while (size > 0)
	{
		if (!(hexa_l = ft_strjoin_fr("0", hexa_l, 2)))
			return (-8);
		size--;
	}
	if (instruc->hexa_instruc != NULL)
		instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc, hexa_l, 1);
	else
		instruc->hexa_instruc = ft_strdup(hexa_l);
	if (instruc->hexa_instruc == NULL)
		return (-8);
	ft_strdel(&hexa_l);
	return (1);
}

int		put_label_instruc(t_instruc *instruc, char *label, int16_t adress,
	int size)
{
	t_label	*tmp;
	char	*empty;

	if (!(empty = ft_strdup("#")))
		return (-8);
	tmp = instruc->label;
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->label = ft_strdup(label)))
		return (-8);
	tmp->adress = adress;
	tmp->size = size;
	tmp->next = new_label();
	while (--size > 0 && empty)
		empty = ft_strjoin_fr(empty, "#", 1);
	if (instruc->hexa_instruc != NULL && empty)
		instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc, empty, 1);
	else if (empty)
		instruc->hexa_instruc = ft_strdup(empty);
	if (instruc->hexa_instruc == NULL || empty == NULL)
		return (-8);
	ft_strdel(&empty);
	return (1);
}

void	is_label_exist(char *label, t_env *env, t_instruc *instruc, int size)
{
	t_label	*tmp;
	int		adress;
	int16_t	res;

	adress = get_adress(env->instruc, instruc);
	tmp = env->label;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->label, label) == 0)
		{
			res = tmp->adress - adress;
			if (put_hexa_label(res, instruc, size) < 0)
				error(8, env, -1, NULL);
			return ;
		}
		tmp = tmp->next;
	}
	if (is_label(label) == -1)
		error(5, env, -1, label);
	if (put_label_instruc(instruc, label, adress, size) < 0)
		error(8, env, -1, NULL);
}

int		check_params(char **params, t_env *env)
{
	int			j;
	t_instruc	*tmp;

	tmp = get_last_intruct(env->instruc);
	j = 0;
	while (params[j])
		j++;
	if (j != tmp->nbr_params)
		error(9, env, -1, ft_itoa(tmp->opcode));
	j = 0;
	while (params[j])
	{
		what_params(&params[j][0], tmp, j, env);
		j++;
	}
	if (tmp->is_ocp == 1)
		get_ocp(tmp, -1, -1, env);
	return (0);
}

int		get_params(char *line, t_env *env)
{
	char		**params;
	t_instruc	*tmp;
	int			nbr_line;

	nbr_line = check_numbers_separator(line);
	tmp = get_last_intruct(env->instruc);
	if (tmp->opcode == 0)
		return (1);
	if (nbr_line != tmp->nbr_params - 1 && nbr_line != 0)
		error(9, env, -1, ft_itoa(tmp->opcode));
	if (!(params = ft_strsplit(line, SEPARATOR_CHAR)))
		error(8, env, -1, NULL);
	check_params(params, env);
	ft_strrdel(params);
	return (1);
}
