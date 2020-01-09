/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:05:59 by adietric          #+#    #+#             */
/*   Updated: 2020/01/09 17:48:58 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			op_lld(t_all *vm, t_process *p)
{
	long		pm1;
	int			bytes_read;

	bytes_read = 5;
	if (p->decode[0] == IND_CODE)
	{
		pm1 = get_val_at_ind(vm, p, 1, 0);
		bytes_read = 3;
	}
	else
		pm1 = get_next_bytes(vm, p, 4, 1);
	load_val_in_reg(vm, p, pm1, bytes_read);
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | lld %d n", p->pid, pm1);
	if (p->op_fail == 1)
		return ;
	check_carry(p, pm1);
}
