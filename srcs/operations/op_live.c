/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:03:57 by adietric          #+#    #+#             */
/*   Updated: 2020/01/07 09:14:23 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

uint16_t	check_op_live(uint8_t *content)
{
	int		i;

	(void)content;
	i = 0;
	return (g_op_check_tab[0].dir_size + 1);
}

int			is_player_nb(int id, t_all *vm)
{
	int		i;

	i = -1;
	while (++i < vm->total_champ)
	{
		if (vm->champs[i].id == id)
		{
			vm->champs[i].last_live = vm->cycles;
			return (i);
		}
	}
	return (-1);
}

void		op_live(t_all *vm, t_process *p)
{
	int		p1;
	int		i;

	p1 = get_next_bytes(vm, p, 4, 0);
	p->live_calls = vm->cycles + 1;
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | Live %d at cycle %d.\n", p->pid, p1, vm->cycles);
	if ((i = is_player_nb(p1, vm)) != -1)
	{
		if (vm->flag_v == 1)
		{
			ft_printf("A process shows that player number %d, ", p1);
			ft_printf("%s, is alive at cycle %d.\n",
			vm->champs[i].name, vm->cycles);
		}
		vm->last_alive = p1;
		vm->last_alive_cycle = vm->cycles + 1;
		++vm->nbr_live_since_check;
	}
}
