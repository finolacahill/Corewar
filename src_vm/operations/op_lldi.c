/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:06:55 by adietric          #+#    #+#             */
/*   Updated: 2020/01/10 11:56:06 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int		check_reg(t_all *vm, t_process *p, long bytes)
{
	long reg;

	reg = get_next_bytes(vm, p, 1, bytes);
	if (reg < 1 || reg > 16)
		return (0);
	return (1);
}

static long		get_pm1(t_all *vm, t_process *p, long *bytes)
{
	long		address1;

	if (p->decode[0] == IND_CODE)
	{
		address1 = get_ind(vm, p, 1, 1);
		address1 = get_next_bytes(vm, p, 4, (address1 - 1));
		bytes[0] = 3;
	}
	else
	{
		address1 = get_unspecified_val_2(vm, p, bytes, 0);
	}
	return (address1);
}


/*
** Gets the values stored at parameter 1, and parameter 2
** adds them together and uses it as an address NOT limited by IDX_MOD
** from which we get the value which we will load to the 
** register given in parameter 3.
*/
void			op_lldi(t_all *vm, t_process *p)
{
	long		address1;
	long		address2;
	long		val;
	long		bytes_read;

	bytes_read = 1;
	address1 = get_pm1(vm, p, &bytes_read);
	address2 = get_unspecified_val_2(vm, p, &bytes_read, 1);
	if (p->op_fail == 1 || check_reg(vm, p, bytes_read) == 0)
		return ;
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | lldi from %d + %d (with mod and pc %d)\n",
		p->pid, address1, address2, address1 + address2 + p->pc);
	address1 += address2;
	val = get_next_bytes(vm, p, 4, address1 - 1);
	if (p->op_fail == 1)
		return ;
	load_val_in_reg(vm, p, val, bytes_read);
	check_carry(p, val);
}
