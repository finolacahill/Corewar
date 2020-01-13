/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:53:17 by yodana            #+#    #+#             */
/*   Updated: 2020/01/09 16:10:42 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static const	t_error_cmd g_error_cmd_tab[] =
{
	{1, "Error: Double \"\" does not exist in "},
	{2, "Error: Lexical error in "},
	{3, "Error: This CMD already exist -> "},
	{4, "Error: This CMD does not exist -> "},
	{5, "Error: CMD missing -> "},
	{6, "Error: Champion size too big -> "},
	{0, NULL}
};

void	which_cmd_error(t_header *header, t_env *env)
{
	if (header->n == 0)
		error_cmd(5, env, "name", -1);
	else
		error_cmd(5, env, "comment", -1);
}

void	error_cmd(int type, t_env *env, char *cmd, int line)
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
			ft_fprintf(2, "\n");
			if (env)
			{
				if (env->header)
					close(env->header->fd);
				free_all(env);
			}
			exit(2);
		}
		i++;
	}
	exit(2);
}
