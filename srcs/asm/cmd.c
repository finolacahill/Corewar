/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:20:13 by yodana            #+#    #+#             */
/*   Updated: 2019/12/19 17:52:32 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	last_check_cmd(t_env *env, char *line, char *cmd)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ';' && line[i] > ' ')
			error_cmd(2, cmd, env->line);
		else if (line[i] == ';')
			return ;
		i++;
	}
}

void	put_comment(t_env *env, char *line)
{
	int i;
	int j;

	j = -1;
	i = -1;
	if (env->header->c == 1)
		error_cmd(3, "comment", env->line);
	while (line[++i] && line[i] != '"')
	{
		if (line[i] > ' ')
			error_cmd(2, "comment", env->line);
	}
	if (line[i] == '\0')
		error_cmd(1, "comment", env->line);
	i++;
	while (line[i] && line[i] != '"')
	{
		env->header->comment[++j] = line[i];
		i++;
	}
	if (line[i] == '\0')
		error_cmd(1, "comment", env->line);
	i++;
	env->header->c = 1;
	last_check_cmd(env, &line[i], "comment");
}

void	put_name(t_env *env, char *line)
{
	int i;
	int j;

	j = -1;
	i = -1;
	if (env->header->n == 1)
		error_cmd(3, "name", env->line);
	while (line[++i] && line[i] != '"')
	{
		if (line[i] > ' ')
			error_cmd(2, "name", env->line);
	}
	if (line[i] == '\0')
		error_cmd(1, "name", env->line);
	i++;
	while (line[i] && line[i] != '"')
	{
		env->header->prog_name[++j] = line[i];
		i++;
	}
	if (line[i] == '\0')
		error_cmd(1, "name", env->line);
	i++;
	env->header->n = 1;
	last_check_cmd(env, &line[i], "name");
}

void	go_cmd(t_env *env, char *line)
{
	int		i;
	char	*check;
	int		j;
	int		len;

	i = 0;
	while (line[i] && line[i] <= ' ')
		i++;
	len = i;
	i++;
	j = i;
	while (line[j] && line[j] > ' ')
		j++;
	if (!(check = ft_strsub(line, i, j - len - 1)))
		error(8, -1, -1, NULL);
	if (line[i] && ft_strcmp("name", check) == 0)
		put_name(env, &line[j]);
	else if (line[i] && ft_strcmp("comment", check) == 0)
		put_comment(env, &line[j]);
	else
		error_cmd(4, check, env->line);
	ft_strdel(&check);
}
