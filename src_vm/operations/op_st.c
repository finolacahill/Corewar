/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:10:04 by adietric          #+#    #+#             */
/*   Updated: 2020/01/10 11:56:18 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void		st_ind(t_all *vm, t_process *p, long param1)
{
	long param2;

	param2 = get_ind(vm, p, 2, 0);
	if (vm->flag_v == 4)
	{
		if (p->decode[0] == REG_CODE)
			ft_printf("\tP%6d | st R%d at %d + pc %d at cycle %d \n",
				p->pid, get_next_bytes(vm, p, 1, 1), param2 % IDX_MOD,
				p->pc, vm->cycles);
		else
			ft_printf("\tP%6d | st %d at %d + pc %d at cycle %d \n",
				p->pid, param1, param2 % IDX_MOD,
				p->pc, vm->cycles);
	}
	load_value(vm, p->pc + (param2 % IDX_MOD), 4, param1);
}

static void		st_reg(t_all *vm, t_process *p, long param1)
{
	load_val_in_reg(vm, p, param1, 2);
	if (p->op_fail == 1)
		return ;
	if (vm->flag_v == 4)
	{
		if (p->decode[0] == REG_CODE)
			ft_printf("\tP%6d | st R%d at R%d + pc %d at cycle %d \n",
				p->pid, get_next_bytes(vm, p, 1, 1),
				get_next_bytes(vm, p, 1, 2), p->pc, vm->cycles);
		else
			ft_printf("\tP%6d | st %d at R%d + pc %d at cycle %d \n",
				p->pid, param1,
				get_next_bytes(vm, p, 1, 2), p->pc, vm->cycles);
	}
}

/*
** Get the value of the reg in param 1 and loads it 
** into either a reg or an address in the arena.
*/
void			op_st(t_all *vm, t_process *p)
{
	long		param1;

	param1 = get_reg_val(vm, p, 1);
	if (p->op_fail == 1)
		return ;
	if (p->decode[1] == REG_CODE)
		st_reg(vm, p, param1);
	else
		st_ind(vm, p, param1);
}
