/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print_intro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:09:06 by adietric          #+#    #+#             */
/*   Updated: 2019/11/29 18:29:35 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		vm_print_intro(t_all *all)
{
	int		id;
	int		true;
	int		i;

	id = 1;
	true = 1;
	ft_putstr("Introducing contestants...\n");
	while (true)
	{
		i = -1;
		while (all->champs[++i].id != id)
			if (i == 4)
				return ;
		ft_putstr("* Player ");
		ft_putnbr(id);
		ft_putstr(", weighing ");
		ft_putnbr(all->champs[i].len_exec_code);
		ft_putstr(" bytes, \"");
		ft_putstr((const char *)all->champs[i].name);
		ft_putstr("\" (\"");
		ft_putstr((const char *)all->champs[i].comment);
		ft_putstr("\") !\n");
		id++;
	}
}
