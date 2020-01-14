/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 02:15:38 by yodana            #+#    #+#             */
/*   Updated: 2020/01/09 16:10:42 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		put_params(t_instruc *instruc, int size, char *index, int error)
{
	char *hexa;

	if ((error = check_max_min(index, size, instruc)) == -1)
		return (1);
	if (size != 8 && error != -8)
		hexa = ft_uitoa_base((uint16_t)ft_atoi(index), 16, 0);
	else if (error != -8)
		hexa = ft_uitoa_base((uint32_t)ft_atoi(index), 16, 0);
	if (hexa == NULL || error == -8)
		return (-8);
	size = size - ft_strlen(hexa);
	while (size-- > 0)
	{
		if (!(hexa = ft_strjoin_fr("0", hexa, 2)))
			return (-8);
	}
	if (instruc->hexa_instruc != NULL)
		instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc,
				hexa, 1);
	else
		instruc->hexa_instruc = ft_strdup(hexa);
	if (instruc->hexa_instruc == NULL)
		return (-8);
	ft_strdel(&hexa);
	return (1);
}

void	param_register(t_instruc *instruc, char *c_index_r, int j, t_env *env)
{
	char	*hexa_r;
	int		index_r;

	if (check_numbers(c_index_r) == -1 || ft_strlen(c_index_r) > 2)
		error(10, env, j, ft_itoa(instruc->opcode));
	index_r = ft_atoi(c_index_r);
	if (index_r < 0)
		error(3, env, j, NULL);
	if ((instruc->params[j] & T_REG) != T_REG)
		error(4, env, j, ft_itoa(instruc->opcode));
	instruc->params[j] = T_REG;
	instruc->is_ocp = 1;
	if (!(hexa_r = ft_uitoa_base(index_r, 16, 0)))
		error(8, env, -1, NULL);
	if ((ft_strlen(hexa_r)) == 1)
		hexa_r = ft_strjoin_fr("0", hexa_r, 2);
	if (hexa_r != NULL && instruc->hexa_instruc != NULL)
		instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc, hexa_r, 1);
	else if (hexa_r != NULL)
		instruc->hexa_instruc = ft_strdup(hexa_r);
	if (hexa_r == NULL || instruc->hexa_instruc == NULL)
		error(8, env, -1, NULL);
	ft_strdel(&hexa_r);
}

int		param_direct(t_instruc *instruc, char *index_d, int j, t_env *env)
{
	char	*hexa_d;
	int		size;

	size = 4;
	hexa_d = NULL;
	if (instruc->for_direct == 0)
		size = 8;
	if ((instruc->params[j] & T_DIR) != T_DIR)
		error(4, env, j, ft_itoa(instruc->opcode));
	instruc->params[j] = T_DIR;
	if (index_d[0] == ':')
		is_label_exist(&index_d[1], env, instruc, size);
	else if (check_numbers(index_d) == -1)
		error(10, env, j, ft_itoa(instruc->opcode));
	else
	{
		if (put_params(instruc, size, index_d, 0) < 0)
			error(8, env, -1, NULL);
	}
	return (1);
}

int		param_indirect(t_instruc *instruc, char *index_i, int j, t_env *env)
{
	char	*hexa_i;
	int		size;

	size = 4;
	hexa_i = NULL;
	if ((instruc->params[j] & T_IND) != T_IND)
		error(4, env, j, ft_itoa(instruc->opcode));
	instruc->params[j] = T_IND;
	if (index_i[0] == ':')
		is_label_exist(&index_i[1], env, instruc, size);
	else if (check_numbers(index_i) == -1)
		error(10, env, j, ft_itoa(instruc->opcode));
	else
	{
		if (put_params(instruc, size, index_i, 0) < 0)
			error(8, env, -1, NULL);
	}
	return (1);
}

int		what_params(char *params, t_instruc *instruc, int j, t_env *env)
{
	char	*since_space;
	int		i;

	i = 0;
	if (!(since_space = ft_strtrim(params)))
		error(8, env, -1, NULL);
	if (ft_strlen(since_space) == 0)
		error(10, env, j, ft_itoa(instruc->opcode));
	if (since_space[0] == 'r')
		param_register(instruc, &since_space[1], j, env);
	else if (since_space[0] == DIRECT_CHAR)
		param_direct(instruc, &since_space[1], j, env);
	else if ((ft_isdigit(since_space[0]) || (ft_isdigit(since_space[1])
					&& since_space[0] == '-')) || since_space[0] == ':')
		param_indirect(instruc, since_space, j, env);
	else
		error(10, env, j, ft_itoa(instruc->opcode));
	ft_strdel(&since_space);
	return (0);
}
