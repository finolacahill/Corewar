/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_get_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:40:14 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 12:43:27 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			get_reg_val(t_all *vm, t_process *p, int bytes_read)
{
	int		reg;

	reg = get_next_bytes(vm, p, 1, bytes_read);
	if (reg < 1 || reg > REG_NUMBER)
	{
		p->op_fail = 1;
		return (-1);
	}
	return (p->r[reg - 1]);
}

int			get_ind(t_all *vm, t_process *p, int bytes_read, int restriction)
{
	if (restriction == 1)
		return (get_next_bytes(vm, p, 2, bytes_read) % IDX_MOD);
	return (get_next_bytes(vm, p, 2, bytes_read));
}

int			get_val_at_ind(t_all *vm, t_process *p, int bytes_read,
			int restriction)
{
	int		address;

	address = get_ind(vm, p, bytes_read, restriction);
	return (get_next_bytes(vm, p, 4, address - 1));
}

int			get_unspecified_val(t_all *vm, t_process *p, int *bytes_read,
			int param)
{
	int		val;

	if (p->decode[param] == REG_CODE)
	{
		val = get_reg_val(vm, p, bytes_read[0]);
		bytes_read[0] += 1;
	}
	if (p->decode[param] == IND_CODE)
	{
		val = get_val_at_ind(vm, p, bytes_read[0], 1);
		bytes_read[0] += 2;
	}
	if (p->decode[param] == DIR_CODE)
	{
		val = get_next_bytes(vm, p, 4, bytes_read[0]);
		bytes_read[0] += 4;
	}
	return (val);
}

int			get_unspecified_val_2(t_all *vm, t_process *p, int *bytes_read,
			int param)
{
	int		val;

	if (p->decode[param] == REG_CODE)
	{
		val = get_reg_val(vm, p, bytes_read[0]);
		bytes_read[0] += 1;
	}
	if (p->decode[param] == IND_CODE)
	{
		val = get_val_at_ind(vm, p, bytes_read[0], 1);
		bytes_read[0] += 2;
	}
	if (p->decode[param] == DIR_CODE)
	{
		val = get_next_bytes(vm, p, 2, bytes_read[0]);
		bytes_read[0] += 2;
	}
	return (val);
}
