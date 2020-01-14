/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_re_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:33:11 by fcahill           #+#    #+#             */
/*   Updated: 2020/01/09 17:33:14 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** If no opcode, get predefined bytes associated.
*/
static int	get_direct_bytes(t_process *p, int *bytes)
{
	if (p->op == 0)
		bytes[0] = 0;
	if (p->op == 1)
		bytes[0] = 4;
	if (p->op == 9 || p->op == 12 || p->op == 15)
		bytes[0] = 2;
	return (1);
}


/*
** Check if direct is equal to two or four.
*/
static int	is_direct_two(t_process *p)
{
	if (p->op == 14 || p->op == 12 || p->op == 11 || p->op == 10)
		return (1);
	return (0);
}

/*
** Get len to check (one param, two param, three param)
*/
static int	get_len(t_process *p)
{
	int i;

	i = p->op;
	if (i == 1 || i == 16 || i == 15
		|| i == 12 || i == 9)
		return (1);
	if (i == 2 || i == 3 || i == 13)
		return (2);
	return (3);
}

/*
** Given a invalid opcode, recalculate how many bytes
** we should jump to find next operation. 
*/
int			recalc_bytes(t_process *p, int *bytes)
{
	int		dir;
	int		i;
	int		len;

	i = -1;
	len = get_len(p);
	dir = 0;
	bytes[0] = 1;
	if (is_direct_two(p) == 1)
		dir = 2;
	if (if_no_opcode(p) == 1)
		return (get_direct_bytes(p, bytes - 1));
	while (++i < len)
	{
		if (p->decode[i] == REG_CODE)
			bytes[0] += 1;
		if (p->decode[i] == DIR_CODE)
			bytes[0] += 4 - dir;
		if (p->decode[i] == IND_CODE)
			bytes[0] += 2;
	}
	return (0);
}
