/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:59:11 by adietric          #+#    #+#             */
/*   Updated: 2020/01/10 11:54:51 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		op_ldi(t_all *vm, t_process *p)
{
	long	address1;
	long	address2;
	long	val;
	long	bytes_read;

	bytes_read = 1;
	address1 = get_unspecified_val_2(vm, p, &bytes_read, 0);
	address2 = get_unspecified_val_2(vm, p, &bytes_read, 1);
	if (p->decode[0] == 2)
		address1 = check_neg_address(address1);
	if (p->decode[1] == 2)
		address2 = check_neg_address(address2);
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | ldi from %d + %d (with mod and pc %d)\n", p->pid,
		address1, address2, ((address1 + address2) % IDX_MOD) + p->pc);
	address1 = (address1 + address2) % IDX_MOD;
	val = get_next_bytes(vm, p, 4, address1 - 1);
	if (p->op_fail == 1)
		return ;
	load_val_in_reg(vm, p, val, bytes_read);
}
