/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:00:09 by yodana            #+#    #+#             */
/*   Updated: 2019/12/19 18:03:51 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

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
				error(11, tmp->index, -1, ft_itoa(tmp->opcode));
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
	if (str[i] == '-' && ft_strlen(str) == 1)
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

void	error(int i, int line, int column, char *name)
{
	int j;

	j = 0;
	while (g_error_tab[j].type != 0)
	{
		if (g_error_tab[j].type == i)
		{
			ft_printf("%s", g_error_tab[j].message);
			if (g_error_tab[j].params == 1)
			{
				ft_printf("instruct %s", get_params_with_opcode(ft_atoi(name)));
				if (column >= 0)
					ft_printf(" parameter %d", column);
			}
			if (g_error_tab[j].label == 1)
				ft_printf("\"%s\"", name);
			if (g_error_tab[j].line == 1)
				ft_printf(" in line %d", line + 1);
			if (g_error_tab[j].column == 1)
				ft_printf(" in column %d", column + 1);
			ft_printf("\n");
			exit(0);
		}
		j++;
	}
}
