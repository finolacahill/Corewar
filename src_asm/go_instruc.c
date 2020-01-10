#include "../includes/corewar.h"

void	exit_5(char *line, t_env *env, char **commentaire, char **point)
{
	free(line);
	free(commentaire);
	free(point);
	if (env->header->n == 0)
		error_cmd(5, "name", -1, 0);
	else
		error_cmd(5, "comment", -1, 0);
	free_all(env, env->header);
	exit(0);
}

void	get_exit(int i)
{
	if (i == -3)
		exit(0);
	if (i == -2)
		error(8, -1, -1, NULL);
}

void	end_instruc(char **point, t_env *env, char *line, char **comment)
{
	free_and_freeall((void**)&line,
		(void**)&comment, (void**)&point, env);
	exit(0);
}

void	go_instruc(char *line, t_env *env, int i)
{
	char	**point;
	int		j;
	char	**commentaire;

	j = 0;
	if (!(commentaire = ft_strsplit(line, '#')))
		free_error_8((void**)&line, NULL, NULL, env);
	if (!(point = ft_strsplit(commentaire[0], ';')))
		free_error_8((void**)&line, (void**)&commentaire, NULL, env);
	if (env->header->c != 1 || env->header->n != 1)
		exit_5(line, env, commentaire, point);
	if ((i = get_label(&point[0][i], env)) == -1)
		free_error_8((void**)&line, (void**)&commentaire, (void**)&point, env);
	if ((i = i + get_instruc(&point[0][i], env, i)) < 0)
		get_exit(i);
	if ((get_params(&point[0][i], env)) == -1)
	{
		free_and_freeall((void**)&line,
			(void**)&commentaire, (void**)&point, env);
		exit(0);
	}
	if (next_instruc(env) == -1)
		end_instruc(point, env, line, commentaire);
	ft_strrdel(point);
	ft_strrdel(commentaire);
}
