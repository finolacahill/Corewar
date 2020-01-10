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

void	end_error(t_env *env)
{
	free_all(env, env->header);
	ft_putstr_fd("Close error in every_go.\n", 2);
}

void	every_go(char *av, t_env *env)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
	{
		free_all(env, env->header);
		error(12, -1, -1, NULL);
	}
	env->header->fd = fd;
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
	if ((close(fd)) == -1)
		end_error(env);
}

int		main(int ac, char **av)
{
	t_env		*env;
	int			i;

	i = 1;
	if (ac == 1)
		error(1, -1, -1, NULL);
	while (av[i])
	{
		env = init_env();
		every_go(av[i], env);
		last_verif(env);
		create_file_cor(av[i], env->header, env);
		write_to_file(env->instruc, env->header->fd, env->header, env);
		free_all(env, env->header);
		i++;
	}
	return (0);
}
