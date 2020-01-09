/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:51:14 by adietric          #+#    #+#             */
/*   Updated: 2020/01/09 17:48:12 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		op_add(t_all *vm, t_process *p)
{
	long	p1;
	long	p2;

	p1 = get_reg_val(vm, p, 1);
	p2 = get_reg_val(vm, p, 2);
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | add R%ld R%ld R%ld at cycles %d\n", p->pid,
		get_next_bytes(vm, p, 1, 1), get_next_bytes(vm, p, 1, 2),
		get_next_bytes(vm, p, 1, 3), vm->cycles);
	if (p->op_fail == 1)
		return ;
	load_val_in_reg(vm, p, p1 + p2, 3);
	if (p->op_fail != 1)
		check_carry(p, p1 + p2);
}
