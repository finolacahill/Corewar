/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_load_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:30:34 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 16:32:06 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		load_value(t_all *vm, int add, int len, long val)
{
	int		i;
	int		power;
	int		shift;
	int		address;

	i = len + 1;
	power = 2;
	shift = 24;
	while (--i >= 0)
	{
		address = (add + len - i) % MEM_SIZE;
		if (address < 0)
			address = MEM_SIZE + address;
		vm->arena[address] = (val >> shift);
		val = val << 8;
	}
}

void		load_val_in_reg(t_all *vm, t_process *p, int val, int bytes_read)
{
	int		reg2;

	reg2 = get_next_bytes(vm, p, 1, bytes_read);
	if (reg2 < 1 || reg2 > 16)
	{
		p->op_fail = 1;
		return ;
	}
	p->r[reg2 - 1] = val;
	if (p->op == 10 && vm->flag_v == 4)
		ft_printf("\t \tload val %d in reg %d\n", val, reg2);
}
