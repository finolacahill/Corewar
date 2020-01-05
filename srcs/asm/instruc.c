/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 19:19:11 by yodana            #+#    #+#             */
/*   Updated: 2019/12/22 19:28:06 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0}
};

char	*get_params_with_opcode(int ocp)
{
	int i;

	i = 0;
	while (ocp != g_op_tab[i].opcode)
		i++;
	return (g_op_tab[i].instruc);
}

int		put_instruc_params(t_instruc *instruc, int j)
{
	int i;

	i = 0;
	if (!(instruc->params = (int*)malloc(sizeof(int) *
		(g_op_tab[j].nbr_params + 1))))
		error(8, -1, -1, NULL);
	while (i != g_op_tab[j].nbr_params)
	{
		instruc->params[i] = g_op_tab[j].param_type[i];
		i++;
	}
	instruc->params[i] = 0;
	return (1);
}

int		put_instruc(t_instruc *instruc_env, int j, int line)
{
	t_instruc *tmp;

	tmp = get_last_intruct(instruc_env);
	tmp->opcode = g_op_tab[j].opcode;
	tmp->nbr_params = g_op_tab[j].nbr_params;
	put_instruc_params(tmp, j);
	tmp->for_direct = g_op_tab[j].for_direct;
	tmp->index = line;
	return (1);
}

int		check_instruc(char *instruc, t_env *env)
{
	int j;

	j = 0;
	while (g_op_tab[j].instruc)
	{
		if (ft_strcmp(instruc, (const char*)g_op_tab[j].instruc) == 0)
		{
			put_instruc(env->instruc, j, env->line);
			ft_strdel(&instruc);
			return (1);
		}
		j++;
	}
	error(6, env->line, -1, instruc);
	return (1);
}

int		get_instruc(char *line, t_env *env, int column)
{
	int		i;
	char	*instruc;
	int		j;

	j = 0;
	while (line[j] && line[j] <= ' ')
		j++;
	if (!line[j])
		return (0);
	i = j;
	while (line[i] && ft_isalpha(line[i]))
		i++;
	if (i == j || !(instruc = ft_strsub(line, j, i - j)))
	{
		if (i == j)
			error(7, env->line, j + column, NULL);
		else
			error(8, -1, -1, NULL);
		exit(0);
	}
	if (!check_instruc(instruc, env))
		return (-1);
	return (i);
}
