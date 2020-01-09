/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:06:55 by adietric          #+#    #+#             */
/*   Updated: 2020/01/09 17:49:05 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			op_lldi(t_all *vm, t_process *p)
{
	long		address1;
	long		address2;
	long		val;
	long		bytes_read;

	bytes_read = 1;
	if (p->decode[0] == IND_CODE)
	{
		address1 = get_val_at_ind(vm, p, bytes_read, 0);
		bytes_read += 2;
	}
	else
	{
		address1 = get_unspecified_val_2(vm, p, &bytes_read, 0);
	}
	address2 = get_unspecified_val_2(vm, p, &bytes_read, 1);
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | lldi from %d + %d (with mod and pc %d)\n",
		p->pid, address1, address2, address1 + address2 + p->pc);
	address1 += address2;
	val = get_next_bytes(vm, p, 4, p->pc + address1 - 1);
	if (p->op_fail == 1)
		return ;
	load_val_in_reg(vm, p, val, bytes_read);
	check_carry(p, val);
}
