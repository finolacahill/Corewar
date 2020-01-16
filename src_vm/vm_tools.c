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

/*
** Given the parameter used in the operation check
** if the carry should be changed. The carry is 1 if 
** the parameter is 0. If the carry is, zjmp can be used.
*/
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

/*
** Given a length of value to find and bytes that have already been
** read snce the pc, find the value in the arena. 
*/
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
		if (address < 0)
			address = MEM_SIZE + address;
		val += vm->arena[address];
	}
	return (val);
}

/*
** When collecting a value, we get it's absolute value. 
** here we check if as a decimal from signed 2's complement
** if it is negative or not. 
*/
long	check_neg_address(long val)
{
	if (val < 65536 && val >= 32768)
		val -= 65536;
	return (val);
}


/*
** Check if any defines that would cause memory errors have been changed
** in op.h
*/
void	define_check(void)
{
	if (MAX_PLAYERS != 4)
	{
		ft_fprintf(2, "Error: Max players must be 4.\n");
		exit(0);
	}
	if (MEM_SIZE != 4096)
	{
		ft_fprintf(2, "Error: Mem_size must be 4096.\n");
		exit(0);
	}
	if (IDX_MOD != 512)
	{
		ft_fprintf(2, "Error: Idx_mod must be 512");
		exit(0);
	}
	if (CHAMP_MAX_SIZE != 682)
	{
		ft_fprintf(2, "Error: Champ_max_size must be 682.\n");
		exit(0);
	}
}
