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

int		create_heaxl(int size, int label, char **hexa_l)
{
	if (size == 8)
		*hexa_l = ft_uitoa_base((uint32_t)label, 16, 0);
	else
		*hexa_l = ft_uitoa_base((uint16_t)label, 16, 0);
	if (*hexa_l == NULL)
	{
		error_no_exit(8, -1, -1, NULL);
		return (-1);
	}
	return (0);
}

int		put_hexa_label(int label, t_instruc *instruc, int size)
{
	char *hexa_l;

	if (create_heaxl(size, label, &hexa_l) == -1)
		return (-1);
	size = size - ft_strlen(hexa_l);
	while (size-- > 0)
	{
		if (!(hexa_l = ft_strjoin_fr("0", hexa_l, 2)))
		{
			ft_strdel(&hexa_l);
			return (return_error_i(8, -1));
		}
	}
	if (instruc->hexa_instruc != NULL)
		instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc, hexa_l, 1);
	else
		instruc->hexa_instruc = ft_strdup(hexa_l);
	if (instruc->hexa_instruc == NULL)
	{
		ft_strdel(&hexa_l);
		return (return_error_i(8, -1));
	}
	ft_strdel(&hexa_l);
	return (0);
}

int		is_label_exist(char *label, t_env *env, t_instruc *instruc, int size)
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
			if ((put_hexa_label(res, instruc, size)) == -1)
				return (-1);
		}
		tmp = tmp->next;
	}
	if (is_label(label) == -1)
	{
		error_no_exit(5, env->line, -1, label);
		return (-1);
	}
	if ((put_label_instruc(instruc, label, adress, size)) == -1)
		return (-1);
	return (0);
}

int		check_params(char **params, t_env *env)
{
	int			j;
	t_instruc	*tmp;
	char		*name;

	tmp = get_last_intruct(env->instruc);
	j = 0;
	while (params[j])
		j++;
	if (j != tmp->nbr_params)
	{
		if (!(name = ft_itoa(tmp->opcode)))
			return (return_error_i(8, -1));
		error_no_exit(9, env->line, -1, name);
		free(name);
		return (-1);
	}
	j = -1;
	while (params[++j])
	{
		if ((what_params(&params[j][0], tmp, j, env)) == -1)
			return (-1);
	}
	if (tmp->is_ocp == 1)
		get_ocp(tmp, -1, -1);
	return (0);
}

int		get_params(char *line, t_env *env)
{
	char		**params;
	t_instruc	*tmp;
	int			nbr_line;
	char		*name;

	nbr_line = check_numbers_separator(line);
	tmp = get_last_intruct(env->instruc);
	if (tmp->opcode == 0)
		return (1);
	if (nbr_line != tmp->nbr_params - 1 && nbr_line != 0)
	{
		if (!(name = ft_itoa(tmp->opcode)))
			return (-1);
		error_no_exit(9, env->line, -1, name);
		free(name);
		return (-1);
	}
	if (!(params = ft_strsplit(line, SEPARATOR_CHAR)))
		return (return_error_i(8, -1));
	if ((check_params(params, env)) == -1)
		return (del_and_return((void**)&params, -1));
	ft_strdel(params);
	return (1);
}
