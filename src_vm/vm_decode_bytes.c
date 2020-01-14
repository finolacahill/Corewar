/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_decode_bytes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:35:01 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 12:36:11 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/* Some operations do not have opcodes. If this is the case
** the function returns 1 otherwise, it returns 0.
*/
int			if_no_opcode(t_process *p)
{
	if (p->op == 0 || p->op == 1 ||
		p->op == 9 || p->op == 12 || p->op == 15)
		return (1);
	return (0);
}

/*
** Given a number we must decode it's meaning. The first two bits
** correspond to the first param, 2nd is 2nd, and the last 2 bits h
** should be empty. 01 represents Reg, 10 represents Dir and 11 ind.
*/
t_process	*ft_decode_byte(unsigned char c, t_process *p)
{
	if (if_no_opcode(p) == 0)
	{
		p->decode[0] = c >> 6;
		c = (c << 2);
		p->decode[1] = c >> 6;
		c = (c << 2);
		p->decode[2] = c >> 6;
		c = (c << 2);
		p->decode[3] = c >> 6;
	}
	return (p);
}

/*
** Some operations do not have an opc, and instead have a predetermined
** amount of bytes to jump to find the next operation. This function 
** returns the number of bytes in this case. 
*/
static void	get_direct_bytes(t_process *p, int *bytes)
{
	if (p->op == 0)
		bytes[0] = 0;
	if (p->op == 1)
		bytes[0] = 4;
	if (p->op == 9 || p->op == 12 || p->op == 15)
		bytes[0] = 2;
}

/*
** The subject predetermines that certain operations will have directs of 
** a size of 2, and others four. We check if the given process has a
** direct of 2 or 4. 
*/
static int	is_direct_two(t_process *p)
{
	if (p->op == 14 || p->op == 12 || p->op == 11 || p->op == 10)
		return (1);
	return (0);
}

/*
** Given the opc, we calculate how many bytes we will have to move the pc
** after completing the operation, in order to find the next operation.
*/
void		calc_bytes(t_process *p, int *bytes)
{
	int		i;
	int		dir;

	dir = 0;
	i = -1;
	bytes[0] = 0;
	if (if_no_opcode(p) == 1)
		return (get_direct_bytes(p, bytes));
	if (is_direct_two(p) == 1)
		dir = 2;
	while (++i < 3)
	{
		if (p->decode[i] == REG_CODE)
			bytes[0] += 1;
		if (p->decode[i] == DIR_CODE)
			bytes[0] += 4 - dir;
		if (p->decode[i] == IND_CODE)
			bytes[0] += 2;
	}
	++bytes[0];
}
