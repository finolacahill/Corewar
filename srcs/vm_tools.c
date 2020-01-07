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

int		get_next_bytes(t_all *vm, t_process *p, int len, int bytes_read)
{
	int		val;
	int		i;
	int		address;

	val = 0;
	i = 0;
	while (++i <= len)
	{
		val <<= 8;
		address = (p->pc + bytes_read + i) % MEM_SIZE;
		if (address < 0)
			address = MEM_SIZE + address;
		val += vm->arena[address];
	}
	if ((val % 65536) >= 32768)
		val -= 65536;
	return (val);
}
