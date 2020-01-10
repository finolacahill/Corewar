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
	int		i;

	i = 0;
	while (line[i])
	{
		if ((line[i] != ';' && line[i] != COMMENT_CHAR) && line[i] > ' ')
			return (-3);
		else if (line[i] == ';' || line[i] == COMMENT_CHAR)
			return (0);
		i++;
	}
	return (0);
}

void	check_leftovers_com(char *l, char *check, char *line, t_env *env)
{
	int		leftovers;

	if ((leftovers = put_leftovers(line, env,
		env->header->comment, "comment")) < 0)
	{
		free_and_freeall((void**)&l, (void**)&check, (void**)&line, env);
		if (leftovers == -1)
			error(8, -1, -1, NULL);
		if (leftovers == -2)
			error_cmd(1, "comment", env->line, 1);
		if (leftovers == -3)
			error_cmd(2, "comment", env->line, 1);
	}
}

void	check_comment_len(char *l, char *check, char *line, t_env *env)
{
	if ((ft_strlen(env->header->comment)) > COMMENT_LENGTH)
	{
		free_and_freeall((void**)&l, (void**)&check, (void**)&line, env);
		error_cmd(6, "comment", -1, 1);
	}
	ft_strdel(&line);
}

void	put_comment(t_env *env, char *l, char *check)
{
	int		i;
	char	*line;

	if (!(line = ft_strdup(l)))
		free_error_8((void**)&l, (void**)&check, NULL, env);
	i = -1;
	if (env->header->c == 1)
	{
		free_and_freeall((void**)&l, (void**)&check, (void**)&line, env);
		error_cmd(3, "comment", env->line, 1);
	}
	while (line[++i] && line[i] != '"')
	{
		if (line[i] > ' ')
		{
			free_and_freeall((void**)&l, (void**)&check, (void**)&line, env);
			error_cmd(2, "comment", env->line, 1);
		}
	}
	i++;
	env->header->c = 1;
	check_leftovers_com(l, check, &line[i], env);
	check_comment_len(l, check, line, env);
}

void	end_cmd(char *line, char *check, t_env *env)
{
	free(line);
	free_all(env, env->header);
	error_cmd(4, check, env->line, 0);
	ft_strdel(&check);
	exit(0);
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
		free_error_8((void**)&line, NULL, NULL, env);
	if (line[i] && ft_strcmp("name", check) == 0)
		put_name(env, &line[j], check);
	else if (line[i] && ft_strcmp("comment", check) == 0)
		put_comment(env, &line[j], check);
	else
		end_cmd(line, check, env);
	ft_strdel(&check);
}
