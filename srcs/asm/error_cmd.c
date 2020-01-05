/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:53:17 by yodana            #+#    #+#             */
/*   Updated: 2019/12/19 17:58:41 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

static const	t_error_cmd g_error_cmd_tab[] =
{
	{1, "Error: Double \"\" does not exist in "},
	{2, "Error: Lexical error in "},
	{3, "Error: This CMD already exist -> "},
	{4, "Error: This CMD does not exist -> "},
	{5, "Error: CMD missing -> "},
	{0, NULL}
};

void	which_cmd_error(t_header *header)
{
	if (header->n == 0)
		error_cmd(5, "name", -1);
	else
		error_cmd(5, "comment", -1);
}

void	error_cmd(int type, char *cmd, int line)
{
	int i;

	i = 0;
	while (g_error_cmd_tab[i].message)
	{
		if (g_error_cmd_tab[i].type == type)
		{
			ft_fprintf(2, "%s", g_error_cmd_tab[i].message);
			ft_fprintf(2, "%s", cmd);
			if (line >= 0)
				ft_fprintf(2, " in line %d", line + 1);
			exit(0);
		}
		i++;
	}
	exit(0);
}
