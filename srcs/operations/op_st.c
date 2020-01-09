/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:10:04 by adietric          #+#    #+#             */
/*   Updated: 2020/01/09 17:49:22 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			op_st(t_all *vm, t_process *p)
{
	long		param1;
	long		param2;

	param2 = -1;
	if ((param1 = get_reg_val(vm, p, 1)) == -1 && p->op_fail == 1)
		return ;
	if (p->decode[1] == REG_CODE)
	{
		load_val_in_reg(vm, p, param1, 2);
		if (vm->flag_v == 4)
			ft_printf("\tP%6d | st R%d (%d) at at R%d + pc %d at cycle %d \n",
			p->pid, get_next_bytes(vm, p, 1, 1), param1,
			get_next_bytes(vm, p, 1, 2), p->pc, vm->cycles);
		if (p->op_fail == 1)
			return ;
	}
	else
	{
		param2 = get_ind(vm, p, 2, 0);
		if (vm->flag_v == 4)
			ft_printf("\tP%6d | st R%d (%d) at at %d + pc %d at cycle %d \n",
			p->pid, get_next_bytes(vm, p, 1, 1), param1, param2 % IDX_MOD,
			p->pc, vm->cycles);
		load_value(vm, p->pc + (param2 % IDX_MOD), 4, param1);
	}
}
