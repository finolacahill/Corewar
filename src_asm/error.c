/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:00:09 by yodana            #+#    #+#             */
/*   Updated: 2020/01/09 16:10:42 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static const	t_error g_error_tab[13] =
{
	{1, "Usage: ./asm file.s", -1, -1, 0, 0},
	{2, "Error: File is not a .s", -1, -1, 0, 0},
	{3, "Error: Number for register invalid", 1, 1, -1, 0},
	{4, "Error: Bad parameter for ", 1, -1, 1, 0},
	{5, "Error: Label incorrect ", 1, -1, -1, 1},
	{6, "Error: Instruction does not exist ", 1, -1, -1, 1},
	{7, "Error: Lexical incorrect", 1, 1, -1, -1},
	{8, "Error: malloc fail", -1, -1, -1, -1},
	{9, "Error: Bad number of parameters for ", 1, -1, 1, -1},
	{10, "Error: Lexical's parameter incorrect for ", 1, -1, 1, -1},
	{11, "Error: Label does not exist for ", 1, -1, 1, -1},
	{12, "Error: Fd error (seems the file doesnt exist or crypted)"
		, -1, -1, -1, -1},
	{0, NULL, 0, 0, 0, 0}
};

void	last_verif(t_env *env)
{
	int			i;
	t_instruc	*tmp;

	tmp = env->instruc;
	i = 0;
	while (tmp)
	{
		while (tmp->hexa_instruc && tmp->hexa_instruc[i])
		{
			if (tmp->hexa_instruc[i] == '#')
				error(11, env, -1, ft_itoa(tmp->opcode));
			i++;
		}
		i = 0;
		tmp = tmp->next;
	}
}

int		check_numbers(char *str)
{
	int i;

	i = 0;
	if ((str[i] == '-' && ft_strlen(str) == 1) || ft_strlen(str) == 0)
		return (-1);
	else if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		i++;
	}
	return (1);
}

void	write_error(int j, char *name, int line, int column)
{
	ft_fprintf(2, "%s", g_error_tab[j].message);
	if (g_error_tab[j].params == 1 && name)
	{
		ft_fprintf(2, "instruct %s", get_params_with_opcode(ft_atoi(name)));
		if (name != NULL)
			ft_strdel(&name);
		if (column >= 0)
			ft_fprintf(2, " parameter %d", column);
	}
	if (g_error_tab[j].label == 1 && name)
		ft_fprintf(2, "\"%s\"", name);
	if (g_error_tab[j].line == 1)
		ft_fprintf(2, " in line %d", line + 1);
	if (g_error_tab[j].column == 1)
		ft_fprintf(2, " in column %d", column + 1);
	ft_fprintf(2, "\n");
}

void	error(int i, t_env *env, int column, char *name)
{
	int j;

	j = 0;
	while (g_error_tab[j].type != 0)
	{
		if (g_error_tab[j].type == i)
		{
			write_error(j, name, env->line, column);
			close(env->header->fd);
			if (env)
				free_all(env);
			exit(2);
		}
		j++;
	}
}
