/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:03:57 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 17:05:33 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

uint16_t	check_op_live(t_all *all, uint8_t *content)
{
	int		i;

	(void)content;
	i = 0;
	return (op_check_tab[0].dir_size + 1);
}

int			is_player_nb(int id, t_all *vm)
{
	int		i;

	i = -1;
	while (++i < vm->total_champ)
	{
		if (vm->champs[i].id == id)	//THIS MUST BE CHANGED, IS JUST FOR TESTING
		{
			vm->champs[i].last_live = vm->cycles;
			return (1);
		}
	}
	return (0);
}

void	op_live(t_all *vm, t_process *p)
{
	int p1;

	p1 = get_next_bytes(vm, p, 4, 0);
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | Live %d at cycle %d.\n", p->pid, p1, vm->cycles);
	if (is_player_nb(p1, vm) == 1)
	{
		if (p1 == p->id)
			p->live_calls = vm->cycles + 1;
		if (vm->flag_v == 1)
			ft_printf("A process shows that player number %d, %s, is alive at cycle %d.\n", p1, vm->champs[p1 - 1].name, vm->cycles);
		vm->last_alive = p1;
		vm->last_alive_cycle = vm->cycles + 1;
		++vm->nbr_live_since_check;
	}
}
