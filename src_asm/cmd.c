/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:20:13 by yodana            #+#    #+#             */
/*   Updated: 2020/01/09 16:32:24 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		last_check_cmd(t_env *env, char *line, char *cmd)
{
	int i;

	i = 0;
	while (line[i])
	{
		if ((line[i] != ';' && line[i] != COMMENT_CHAR) && line[i] > ' ')
			error_cmd(2, env, cmd, env->line);
		else if (line[i] == ';' || line[i] == COMMENT_CHAR)
			return (1);
		i++;
	}
	return (1);
}

void	put_leftovers(char *l, t_env *env, char *add, char *cmd)
{
	int		j;
	char	*line;
	int		i;

	i = 0;
	if (!(line = ft_strdup(l)))
		error(8, env, -1, NULL);
	j = -1;
	while (line[i] != '"')
	{
		if (line[i] != '\0')
			add[++j] = line[i++];
		if (line[i] == '\0')
		{
			i = 0;
			add[++j] = '\n';
			ft_strdel(&line);
			if (get_next_line(env->header->fd, &line) <= 0)
				error_cmd(1, env, cmd, env->line);
			env->line++;
		}
	}
	add[++j] = '\0';
	last_check_cmd(env, &line[++i], cmd);
	ft_strdel(&line);
}

void	put_comment(t_env *env, char *l)
{
	int		i;
	char	*line;

	if (!(line = ft_strdup(l)))
		error(8, env, -1, NULL);
	i = -1;
	if (env->header->c == 1)
		error_cmd(3, env, "comment", env->line);
	while (line[++i] && line[i] != '"')
	{
		if (line[i] > ' ')
			error_cmd(2, env, "comment", env->line);
	}
	i++;
	put_leftovers(&line[i], env, env->header->comment, "comment");
	env->header->c = 1;
	if ((ft_strlen(env->header->comment)) > COMMENT_LENGTH)
		error_cmd(6, env, "comment", -1);
	ft_strdel(&line);
}

void	put_name(t_env *env, char *l)
{
	int		i;
	char	*line;

	if (!(line = ft_strdup(l)))
		error(8, env, -1, NULL);
	i = -1;
	if (env->header->n == 1)
		error_cmd(3, env, "name", env->line);
	while (line[++i] && line[i] != '"')
	{
		if (line[i] > ' ')
			error_cmd(2, env, "name", env->line);
	}
	i++;
	put_leftovers(&line[i], env, env->header->prog_name, "name");
	env->header->n = 1;
	if ((ft_strlen(env->header->prog_name)) > PROG_NAME_LENGTH)
		error_cmd(6, env, "name", -1);
	ft_strdel(&line);
}

void	go_cmd(t_env *env, char *line)
{
	int		i;
	char	*check;
	int		j;
	int		len;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	len = i;
	i++;
	j = i;
	while (line[j] && (line[j] > ' ' && line[j] != '"'))
		j++;
	if (!(check = ft_strsub(line, i, j - len - 1)))
		error(8, env, -1, NULL);
	if (line[i] && ft_strcmp("name", check) == 0)
		put_name(env, &line[j]);
	else if (line[i] && ft_strcmp("comment", check) == 0)
		put_comment(env, &line[j]);
	else
		error_cmd(4, env, check, env->line);
	ft_strdel(&check);
}
