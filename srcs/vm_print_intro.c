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

void		vm_print_intro(t_all *vm)
{
	int		i;

	i = -1;
	ft_putstr("Introducing contestants...\n");
	while (++i < vm->total_champ)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			vm->champs[vm->order[i]].id, vm->champs[vm->order[i]].len_exec_code,
			vm->champs[vm->order[i]].name, vm->champs[vm->order[i]].comment);
	}
}
