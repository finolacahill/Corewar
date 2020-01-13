/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 03:58:29 by yodana            #+#    #+#             */
/*   Updated: 2020/01/09 16:10:42 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		check_file(char *file)
{
	int i;
	int len;
	int j;

	i = 0;
	j = 0;
	while (file[i])
	{
		if (file[i] == '.')
			j = i;
		i++;
	}
	i = j;
	if (!file[i])
		return (-1);
	len = ft_strlen(&file[i]);
	if (ft_strcmp(".s", &file[i]) == 0)
		return (1);
	return (-1);
}

void	create_file_cor(char *file_name, t_env *env)
{
	char	*new_name;
	int		len;

	if (check_file(file_name) == -1)
		error(2, env, -1, NULL);
	len = ft_strlen(file_name) - 2;
	if (!(new_name = ft_strnew(len)))
		error(8, env, -1, NULL);
	ft_memcpy(new_name, file_name, len);
	if (!(new_name = ft_strjoin_fr(new_name, ".cor", 1)))
		error(8, env, -1, NULL);
	env->header->fd = open(new_name, O_WRONLY | O_CREAT, 0777);
	if (env->header->fd < 0)
		error(12, env, -1, NULL);
	write_header_magic(env, new_name, 0);
	ft_strdel(&new_name);
}

void	go_instruc(char *line, t_env *env, int i)
{
	char	**point;
	int		j;
	char	**commentaire;

	j = 0;
	if (!(commentaire = ft_strsplit(line, '#')))
		error(8, env, -1, NULL);
	if (!(point = ft_strsplit(commentaire[0], ';')))
		error(8, env, -1, NULL);
	if (env->header->c != 1 || env->header->n != 1)
		which_cmd_error(env->header, env);
	i = get_label(&point[0][i], env);
	i = i + get_instruc(&point[0][i], env, i);
	get_params(&point[0][i], env);
	next_instruc(env);
	i = 0;
	j++;
	ft_strrdel(point);
	ft_strrdel(commentaire);
}

void	every_go(char *av, t_env *env)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(av, O_RDONLY);
	env->header->fd = fd;
	if (fd < 0)
		error(12, env, -1, NULL);
	while (get_next_line(fd, &line) == 1)
	{
		if (line_ispoint(line) == 1)
			go_cmd(env, line);
		else if (line_iscomment(line) == 1)
			(void)line;
		else if (line_empty(line) == 1)
			go_instruc(line, env, i);
		env->line++;
		free(line);
		i = 0;
	}
	close(fd);
}

int		main(int ac, char **av)
{
	t_env		*env;
	int			i;

	i = 1;
	if (ac == 1)
		error(1, NULL, -1, NULL);
	while (av[i])
	{
		env = init_env();
		every_go(av[i], env);
		last_verif(env);
		create_file_cor(av[i], env);
		write_to_file(env->instruc, env->header->fd, env->header, env);
		free_all(env);
		i++;
	}
	return (0);
}
