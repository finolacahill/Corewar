/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print_intro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:09:06 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 16:33:07 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		vm_print_intro(t_all *all)
{
	int		i;

	i = -1;
	ft_putstr("Introducing contestants...\n");
	while(++i < all->total_champ)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			all->champs[i].id, all->champs[i].len_exec_code, all->champs[i].name,
			all->champs[i].comment);
	}
}
