/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:56:17 by adietric          #+#    #+#             */
/*   Updated: 2020/01/08 19:01:45 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			flag_n(int ac, char **av, t_all *all, int *j)
{
	int		n_id;
	int		i;

	n_id = 0;
	i = 0;
	while ((i) < ac && (ft_strcmp(av[(i)], "-n") != 0))
		(i)++;
	if (av[(i) + 1])
		n_id = just_nb_atoi(av[(i) + 1], all);
	if (!(av[(i) + 1]) || just_number(av[(i) + 1]) != 1)
		print_usage(all);
	if (av[(i) + 2] && dasm_is_it_cor(av[(i) + 2]) == 1)
	{
		if (!(all->champs[0].path = ft_strdup(av[(i) + 2])))
			error(all, "Malloc error in flag_n");
		all->champs[0].id = n_id;
	}
	else
		print_usage(all);
	(*j) = i;
	return (n_id);
}

void		stock_good_id(t_all *all, int ac, char **av, int id)
{
	int		i;
	int		j;
	int		r;
	int		ban;

	j = -1;
	r = 0;
	if (all->flag_n == 1 && ++id)
		ban = flag_n(ac, av, all, &j);
	i = 0;
	while (++i < ac)
	{
		if (ft_jump_flags(ac, av, &i, all) == 1)
			continue ;
		if (i != j && i < ac)
		{
			if (!(all->champs[id++].path = ft_strdup(av[i])))
				error(all, "Malloc error in stock good id");
			r = id - 1 == ban ? r + 1 : r;
			all->champs[id - 1].id = all->flag_n == 1 ? id + r - 1 : id + r;
		}
		else
			i += 2;
	}
}

int			check_flag(t_all *all, char **av, int *flag_n, int *flag_dump)
{
	int		i;
	int		ac;

	ac = all->ac;
	i = 0;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-n") == 0)
			(*flag_n)++;
		if (ft_strcmp(av[i], "-v") == 0)
			all->flag_v++;
		if (ft_strcmp(av[i], "-dump") == 0)
			(*flag_dump)++;
	}
	if ((*flag_n) > 1 || (*flag_dump) > 1 || all->flag_v > 1)
		return (1);
	if (ac > 5 + ((*flag_n) * 2) + ((*flag_dump) * 2) + (all->flag_v * 2))
		return (1);
	return (0);
}

void		flag_v(int ac, char **av, t_all *all)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-v") == 0)
		{
			if (av[i + 1] && just_number(av[i + 1]) == 1)
			{
				all->flag_v = just_nb_atoi(av[i + 1], all);
				if (all->flag_v != 0 && all->flag_v != 1 && all->flag_v != 2
				&& all->flag_v != 4 && all->flag_v != 8 && all->flag_v != 16)
					print_usage(all);
				else
					return ;
			}
		}
	}
	print_usage(all);
}

void		dasm_input(int ac, char **av, t_all *all)
{
	int		flag_n;
	int		flag_dump;

	flag_n = 0;
	flag_dump = 0;
	if (ac < 2 || ac > 11)
		print_usage(all);
	if (check_flag(all, av, &flag_n, &flag_dump))
		print_usage(all);
	if (all->flag_v == 1)
		flag_v(ac, av, all);
	if (flag_n == 1)
		all->flag_n = 1;
	stock_good_id(all, ac, av, 0);
}
