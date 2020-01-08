/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:48:30 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 16:49:21 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	check_carry(t_process *p, int param)
{
	if (p != NULL)
	{
		if (param == 0)
			p->carry = 1;
		else
			p->carry = 0;
	}
}

long	get_next_bytes(t_all *vm, t_process *p, int len, long bytes_read)
{
	long	val;
	int		i;
	int		address;

	val = 0;
	i = 0;
	while (++i <= len)
	{
		val <<= 8;
		address = (p->pc + bytes_read + i) % MEM_SIZE;
	//	print_debug(vm, 64, p->pc, address);
	//	ft_printf("pc = %d address = %d i = %d index get = %d\n", p->pc, bytes_read, i, address);
		if (address < 0)
			address = MEM_SIZE + address;
		val += vm->arena[address];
	}
//	if ((val % 65536) >= 32768)
//	{
//		val -= 65536;
	//	if (val >= 0)
	//		val += 65546;
//	}
//	ft_printf("val = %ld\n", val);
	return (val);
}

long	check_neg_address(long val)
{
	if (val < 65536 && val >= 32768)
		val -= 65536;
	return (val);
}