/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:15:10 by adietric          #+#    #+#             */
/*   Updated: 2020/01/10 11:56:35 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			op_sub(t_all *vm, t_process *p)
{
	int			p1;
	int			p2;

	p1 = get_reg_val(vm, p, 1);
	p2 = get_reg_val(vm, p, 2);
	if (p->op_fail == 1)
		return ;
	load_val_in_reg(vm, p, p1 - p2, 3);
	if (p->op_fail != 1)
	{
		check_carry(p, p1 - p2);
		if (vm->flag_v == 4)
			ft_printf("\tP%6d | sub R%ld R%ld R%ld at cycles %d\n", p->pid,
			get_next_bytes(vm, p, 1, 1), get_next_bytes(vm, p, 1, 2),
			get_next_bytes(vm, p, 1, 3), vm->cycles);
	}
}
