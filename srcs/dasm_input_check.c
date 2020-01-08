/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_input_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:00:43 by flafonso          #+#    #+#             */
/*   Updated: 2020/01/08 19:01:51 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		check_dump(int ac, char **av, t_all *all, int *i)
{
	int		l;

	l = i[0];
	if (l + 1 >= ac)
		print_usage(all);
	if (just_number(av[l + 1]) != 1)
		print_usage(all);
	all->flag_dump = ft_atoi(av[l + 1]);
	if (all->flag_dump <= 0)
		print_usage(all);
	i[0] += 2;
}

int			ft_jump_flags(int ac, char **av, int *i, t_all *all)
{
	if (av[(*i)] && ft_strcmp(av[(*i)], "-dump") == 0)
		check_dump(ac, av, all, i);
	if (av[(*i)] && ft_strcmp(av[(*i)], "-dump") == 0 && all->flag_dump != -1
		&& (*i)++)
		return (1);
	if (av[(*i)] && ft_strcmp(av[(*i)], "-v") == 0 && (*i)++)
		return (1);
	return (0);
}
