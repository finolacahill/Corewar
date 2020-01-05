/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 01:43:50 by yodana            #+#    #+#             */
/*   Updated: 2019/12/23 02:14:59 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	put_hexa_label(int16_t label, t_instruc *instruc, int size)
{
	char *hexa_l;

	if (label >= 0)
		hexa_l = ft_uitoa_base((uint16_t)label, 16, 0);
	else
		hexa_l = ft_uitoa_base((uint16_t)label, 16, 0);
	if (hexa_l == NULL)
		error(8, -1, -1, NULL);
	size = size - ft_strlen(hexa_l);
	while (size > 0)
	{
		if (!(hexa_l = ft_strjoin_fr("0", hexa_l, 2)))
			error(8, -1, -1, NULL);
		size--;
	}
	if (instruc->hexa_instruc != NULL)
		instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc, hexa_l, 1);
	else
		instruc->hexa_instruc = ft_strdup(hexa_l);
	if (instruc->hexa_instruc == NULL)
		error(8, -1, -1, NULL);
	ft_strdel(&hexa_l);
}

void	put_label_instruc(t_instruc *instruc, char *label, int16_t adress,
	int size)
{
	t_label	*tmp;
	char	*empty;

	if (!(empty = ft_strdup("#")))
		error(8, -1, -1, NULL);
	tmp = instruc->label;
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->label = ft_strdup(label)))
		error(8, -1, -1, NULL);
	tmp->adress = adress;
	tmp->size = size;
	tmp->next = new_label();
	while (--size > 0)
	{
		if (!(empty = ft_strjoin_fr(empty, "#", 1)))
			error(8, -1, -1, NULL);
	}
	if (instruc->hexa_instruc != NULL)
		instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc, empty, 1);
	else
		instruc->hexa_instruc = ft_strdup(empty);
	if (instruc->hexa_instruc == NULL)
		error(8, -1, -1, NULL);
	ft_strdel(&empty);
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
			put_hexa_label(res, instruc, size);
			return ;
		}
		tmp = tmp->next;
	}
	if (is_label(label) == -1)
		error(5, env->line, -1, label);
	put_label_instruc(instruc, label, adress, size);
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
		error(9, env->line, -1, ft_itoa(tmp->opcode));
	j = 0;
	while (params[j])
	{
		what_params(&params[j][0], tmp, j, env);
		j++;
	}
	if (tmp->is_ocp == 1)
		get_ocp(tmp, 0, -1);
	return (0);
}

int		get_params(char *line, t_env *env)
{
	char **params;

	if (!(params = ft_strsplit(line, SEPARATOR_CHAR)))
		error(8, -1, -1, NULL);
	check_params(params, env);
	ft_strrdel(params);
	return (1);
}
