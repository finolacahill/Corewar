/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:56:17 by adietric          #+#    #+#             */
/*   Updated: 2019/12/15 23:15:52 by adietric         ###   ########.fr       */
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

int			flag_n(int ac, char **av, t_all *all, int *j)
{
	int		n_id;
	int		i;

	n_id = 0;
	i = 0;
	while ((i) < ac && (ft_strcmp(av[(i)], "-n") != 0))
		(i)++;
	if (av[(i) + 1])
		n_id = ft_atoi(av[(i) + 1]);
	if (n_id < 1 || n_id > 4 || (av[(i) + 1]
		&& just_number(av[(i) + 1]) != 1))
		print_usage(all);
	if (av[(i) + 2] && dasm_is_it_cor(av[(i) + 2]) == 1)
	{
		if (!(all->champs[n_id - 1].path = ft_strdup(av[(i) + 2])))
			error(all, "Malloc error in flag_n");
		all->champs[n_id - 1].id = n_id;
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

	j = -1;
	if (all->flag_n == 1)
		all->flag_n = flag_n(ac, av, all, &j);
	i = 0;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-dump") == 0)
			check_dump(ac, av, all, &i);
		if (ft_strcmp(av[i], "-dump") == 0 && all->flag_dump != -1)
			i += 2;
		if (i != j && i < ac)
		{
			if (id == all->flag_n - 1)
				id++;
			if (!(all->champs[id++].path = ft_strdup(av[i])))
				error(all, "Malloc error in stock good id");
			all->champs[id - 1].id = id;
		}
		else
			i += 2;
	}
}

int			check_flag(int ac, char **av, int *flag_n, int *flag_dump)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-n") == 0)
		{
			(*flag_n)++;
		}
		if (ft_strcmp(av[i], "-dump") == 0)
			(*flag_dump)++;
	}
	if ((*flag_n) > 1 || (*flag_dump) > 1)
		return (1);
	if (ac > 5 + ((*flag_n) * 2) + ((*flag_dump) * 2))
		return (1);
	return (0);
}

void		dasm_input(int ac, char **av, t_all *all)
{
	int		flag_n;
	int		flag_dump;

	flag_n = 0;
	flag_dump = 0;
	if (ac < 2 || ac > 9)
		print_usage(all);
	if (check_flag(ac, av, &flag_n, &flag_dump))
		print_usage(all);
	if (flag_n == 1)
		all->flag_n = 1;
	stock_good_id(all, ac, av, 0);
}
