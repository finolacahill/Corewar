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

int		put_params(t_instruc *instruc, int size, char *index)
{
	char	*hexa;
	int		ret;

	if ((ret = check_max_min(index, size, instruc)) <= 0)
		return (ret);
	if (size != 8)
		hexa = ft_uitoa_base((uint16_t)ft_atoi(index), 16, 0);
	else
		hexa = ft_uitoa_base((uint32_t)ft_atoi(index), 16, 0);
	if (hexa == NULL)
		return (-1);
	size = size - ft_strlen(hexa);
	while (size-- > 0)
		if (!(hexa = ft_strjoin_fr("0", hexa, 2)))
			return (del_and_return((void**)&hexa, -1));
	if (instruc->hexa_instruc != NULL)
		instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc,
				hexa, 1);
	else
		instruc->hexa_instruc = ft_strdup(hexa);
	if (instruc->hexa_instruc == NULL)
		return (del_and_return((void**)&hexa, -1));
	ft_strdel(&hexa);
	return (0);
}

int		param_register(t_instruc *instruc, char *c_index_r, int j, t_env *env)
{
	char	*hexa_r;
	int		index_r;
	char	*name;

	if (!(name = ft_itoa(instruc->opcode)))
		return (-1);
	if (check_numbers(c_index_r) == -1 || ft_strlen(c_index_r) > 2)
	{
		error_no_exit(10, env->line, j, name);
		free(name);
		return (-1);
	}
	index_r = ft_atoi(c_index_r);
	if (index_r < 0)
	{
		error_no_exit(3, env->line, j, NULL);
		free(name);
		return (-1);
	}
	if ((instruc->params[j] & T_REG) != T_REG)
	{
		error_no_exit(4, env->line, j, name);
		free(name);
		return (-1);
	}
	instruc->params[j] = T_REG;
	instruc->is_ocp = 1;
	if (!(hexa_r = ft_uitoa_base(index_r, 16, 0)))
	{
		error_no_exit(8, -1, -1, NULL);
		free(name);
		return (-1);
	}
	if ((ft_strlen(hexa_r)) == 1)
		if (!(hexa_r = ft_strjoin_fr("0", hexa_r, 2)))
		{
			ft_strdel(&hexa_r);
			free(name);
			return (-1);
		}
	if (hexa_r != NULL && instruc->hexa_instruc != NULL)
		{
			if (!(instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc, hexa_r, 1)))
			{
				ft_strdel(&hexa_r);
				free(name);
				return (-1);
			}
		}
	else if (hexa_r != NULL)
		{
			if (!(instruc->hexa_instruc = ft_strdup(hexa_r)))
			{
				ft_strdel(&hexa_r);
				free(name);
				return (-1);
			}
		}
	if (hexa_r == NULL || instruc->hexa_instruc == NULL)
	{
		ft_strdel(&hexa_r);
		free(name);
		error_no_exit(8, -1, -1, NULL);
		return (-1);
	}
	ft_strdel(&hexa_r);
	free(name);
	return (1);
}

int		param_direct(t_instruc *instruc, char *index_d, int j, t_env *env)
{
	char	*hexa_d;
	int		size;
	char	*name;

	size = 4;
	hexa_d = NULL;
	if (!(name = ft_itoa(instruc->opcode)))
		return (-1);
	if (instruc->for_direct == 0)
		size = 8;
	if ((instruc->params[j] & T_DIR) != T_DIR)
	{
		error_no_exit(4, env->line, j, name);
		free(name);
		return (-1);
	}

	instruc->params[j] = T_DIR;
	if (index_d[0] == ':')
	{
			if ((is_label_exist(&index_d[1], env, instruc, size)) == -1)
		{
			free(name);
			return (-1);
		}
	}
	else if (check_numbers(index_d) == -1)
	{
			error_no_exit(10, env->line, j, name);
			free(name);
			return(-1);
	}
	else
	{
		if ((put_params(instruc, size, index_d)) == -1)
		{
			free(name);
			return (-1);
		}
	}
	return (1);
}

int		param_indirect(t_instruc *instruc, char *index_i, int j, t_env *env)
{
	char	*hexa_i;
	int		size;
	char	*name;

	size = 4;
	hexa_i = NULL;
	if (!(name = ft_itoa(instruc->opcode)))
		return (-1);
	if ((instruc->params[j] & T_IND) != T_IND)
	{
		error_no_exit(4, env->line, j, name);
		free(name);
		return (-1);
	}
	instruc->params[j] = T_IND;
	if (index_i[0] == ':')
	{
		if ((is_label_exist(&index_i[1], env, instruc, size)) == -1)
		{
			free(name);
			return (-1);
		}
	}
	else if (check_numbers(index_i) == -1)
	{
		error_no_exit(10, env->line, j, name);
		free(name);
		return (-1);
	}
	else
	{
		if (put_params(instruc, size, index_i) == -1)
		{
			free(name);
			return (-1);
		}
	}
	free(name);
	return (1);
}

int		free_name_del(char *name, char *since_space)
{
	free(name);
	ft_strdel(&since_space);
	return (-1);
}

int		what_params(char *params, t_instruc *instruc, int j, t_env *env)
{
	char	*since_space;
	int		i;
	char	*name;

	i = 0;
	if (!(name = ft_itoa(instruc->opcode)))
		return (-1);
	if (!(since_space = ft_strtrim(params)))
		return (return_error_i(8, -1));
	if (ft_strlen(since_space) == 0)
	{
		error_no_exit(10, env->line, j, name);
		return (free_name_del(name, since_space));
	}
	if (since_space[0] == 'r')
	{
		if ((param_register(instruc, &since_space[1], j, env)) == -1)
			return (free_name_del(name, since_space));
	}
	else if (since_space[0] == DIRECT_CHAR)
	{
		if ((param_direct(instruc, &since_space[1], j, env)) == -1)
			return (free_name_del(name, since_space));
	}
	else if ((ft_isdigit(since_space[0]) || (ft_isdigit(since_space[1])
					&& since_space[0] == '-')) || since_space[0] == ':')
	{
		if ((param_indirect(instruc, since_space, j, env)) == -1)
			return (free_name_del(name, since_space));
	}
	else
	{
		error_no_exit(10, env->line, j, name);
		return (free_name_del(name, since_space));
	}
	ft_strdel(&since_space);
	return (0);
}
