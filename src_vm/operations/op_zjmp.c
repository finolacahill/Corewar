/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:28:17 by adietric          #+#    #+#             */
/*   Updated: 2020/01/10 11:56:46 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** If the carry is 1, jumps the PC of the process
** to the value stored in pm1. It is limited by
** IDX_MOD. 
*/
void			op_zjmp(t_all *vm, t_process *p)
{
	long		address;

	address = get_next_bytes(vm, p, 2, 0);
	address = check_neg_address(address);
	if (p->carry == 1)
	{
		if (vm->flag_v == 4)
			ft_printf("\tP%6d | jumped to %d at cycle %d.\n", p->pid,
			address % MEM_SIZE, vm->cycles);
		address = p->pc + (address % IDX_MOD) - 1;
		if (address < 0)
			address += MEM_SIZE;
		p->pc = address;
	}
	else
	{
		if (vm->flag_v == 4)
			ft_printf("\tP%6d | zjmp %d FAILED at cycle%d\n", p->pid,
			address, vm->cycles);
		p->op_fail = 1;
	}
}
