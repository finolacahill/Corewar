#include "../includes/corewar.h"

void	check_leftovers_nam(char *l, char *check, char *line, t_env *env)
{
	int leftovers;

	if ((leftovers = put_leftovers(line, env, env->header->prog_name,
		"name")) < 0)
	{
		free(check);
		free(l);
		free(line);
		free_all(env, env->header);
		if (leftovers == -1)
			error(8, -1, -1, NULL);
		if (leftovers == -2)
			error_cmd(1, "name", env->line, 1);
		if (leftovers == -3)
			error_cmd(2, "name", env->line, 1);
	}
}

void	check_prog_lem(char *l, char *line, char *check, t_env *env)
{
	if ((ft_strlen(env->header->prog_name)) > PROG_NAME_LENGTH)
	{
		ft_strdel(&line);
		free(check);
		free(l);
		free_all(env, env->header);
		error_cmd(6, "name", -1, 1);
	}
	ft_strdel(&line);
}

void	put_name(t_env *env, char *l, char *check)
{
	int		i;
	char	*line;

	if (!(line = ft_strdup(l)))
		free_error_8((void**)&l, (void**)&check, NULL, env);
	i = -1;
	if (env->header->n == 1)
	{
		free_and_freeall((void**)&l, (void**)&check, (void**)&line, env);
		error_cmd(3, "name", env->line, 1);
	}
	while (line[++i] && line[i] != '"')
	{
		if (line[i] > ' ')
		{
			free_and_freeall((void**)&l, (void**)&check, (void**)&line, env);
			error_cmd(2, "name", env->line, 1);
		}
	}
	i++;
	check_leftovers_nam(l, check, &line[i], env);
	env->header->n = 1;
	check_prog_lem(l, line, check, env);
}

int		ret_leftovers(t_env *env, char *line, char *cmd, int i)
{
	if ((last_check_cmd(env, &line[++i], cmd)) == -3)
		return (del_and_return((void**)&line, -3));
	return (del_and_return((void**)&line, 0));
}

int		put_leftovers(char *l, t_env *env, char *add, char *cmd)
{
	int		j;
	char	*line;
	int		i;

	i = 0;
	if (!(line = ft_strdup(l)))
		return (-1);
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
				return (-2);
			env->line++;
		}
	}
	add[++j] = '\0';
	return (ret_leftovers(env, line, cmd, i));
}
