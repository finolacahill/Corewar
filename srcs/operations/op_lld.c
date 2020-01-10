/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:05:59 by adietric          #+#    #+#             */
/*   Updated: 2020/01/10 11:56:01 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			op_lld(t_all *vm, t_process *p)
{
	long		pm1;
	long		bytes;
	long		address;

	bytes = 5;
	if (p->decode[0] == IND_CODE)
	{
		address = get_ind(vm, p, 1, 0);
		pm1 = get_next_bytes(vm, p, 2, address - 1);
		bytes = 3;
	}
	else
		pm1 = get_next_bytes(vm, p, 4, 1);
	pm1 = check_neg_address(pm1);
	load_val_in_reg(vm, p, pm1, bytes);
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | lld %ld\n", p->pid, pm1);
	if (p->op_fail == 1)
		return ;
	check_carry(p, pm1);
}
