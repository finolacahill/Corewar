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

/*
** Get reg number. If it is valid (i.e. positive and smaller than REG_NUMBER)
** get the assoicated reg value in the process. If it is invalid, note that
** the process failed (p->op_fail = 1) and return -1.
*/
long	get_reg_val(t_all *vm, t_process *p, int bytes_read)
{
	int		reg;

	reg = (int)get_next_bytes(vm, p, 1, bytes_read);
	if (reg < 1 || reg > REG_NUMBER)
	{
		p->op_fail = 1;
		return (-1);
	}
	return (p->r[reg - 1]);
}

/*
** Get the address, check if it should be negative, and if idx == 1
** take into account % IDX_Mod. 
*/
long	get_ind(t_all *vm, t_process *p, long bytes_read, int idx)
{
	long	address;

	address = get_next_bytes(vm, p, 2, bytes_read);
	address = check_neg_address(address);
	if (idx == 1)
		return (address % IDX_MOD);
	return (address);
}

/*
** Get the address given an index and then use that address to find the associated value.
*/
long	get_val_at_ind(t_all *vm, t_process *p, long bytes_read, int idx)
{
	long	address;

	address = get_ind(vm, p, bytes_read, idx);
	return (get_next_bytes(vm, p, 4, address - 1));
}

/*
** If a parameter in an operation could be multiple types, we check the type
** and then recover the value. We also note the size in bytes of this param 
** and add it to total bytes. Directs here are of size 4 and indirects 
** take into account % IDX_MOD
*/
long	get_unspecified_val(t_all *vm, t_process *p, long *bytes, int param)
{
	long	val;

	if (p->decode[param] == REG_CODE)
	{
		val = get_reg_val(vm, p, bytes[0]);
		bytes[0] += 1;
	}
	if (p->decode[param] == IND_CODE)
	{
		val = get_val_at_ind(vm, p, bytes[0], 1);
		bytes[0] += 2;
	}
	if (p->decode[param] == DIR_CODE)
	{
		val = get_next_bytes(vm, p, 4, bytes[0]);
		bytes[0] += 4;
	}
	return (val);
}

/*
** If a parameter in an operation could be multiple types, we check the type
** and then recover the value. We also note the size in bytes of this param 
** and add it to total bytes. Directs here are of size 2 and indirects 
** take into account % IDX_MOD
*/
long	get_unspecified_val_2(t_all *vm, t_process *p, long *bytes, int param)
{
	long	val;

	if (p->decode[param] == REG_CODE)
	{
		val = get_reg_val(vm, p, bytes[0]);
		bytes[0] += 1;
	}
	if (p->decode[param] == IND_CODE)
	{
		val = get_val_at_ind(vm, p, bytes[0], 1);
		bytes[0] += 2;
	}
	if (p->decode[param] == DIR_CODE)
	{
		val = get_next_bytes(vm, p, 2, bytes[0]);
		bytes[0] += 2;
	}
	return (val);
}
