/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:04:38 by adietric          #+#    #+#             */
/*   Updated: 2019/12/09 21:57:54 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"


void		init_name_op(t_op *op)
{
	ft_memcpy(&op[0].op_name, "live", 4);
	ft_memcpy(&op[1].op_name, "ld", 2);
	ft_memcpy(&op[2].op_name, "st", 2);
	ft_memcpy(&op[3].op_name, "add", 3);
	ft_memcpy(&op[4].op_name, "sub", 3);
	ft_memcpy(&op[5].op_name, "and", 3);
	ft_memcpy(&op[6].op_name, "or", 2);
	ft_memcpy(&op[7].op_name, "xor", 3);
	ft_memcpy(&op[8].op_name, "zjmp", 4);
	ft_memcpy(&op[9].op_name, "ldi", 3);
	ft_memcpy(&op[10].op_name, "sti", 3);
	ft_memcpy(&op[11].op_name, "fork", 4);
	ft_memcpy(&op[12].op_name, "lld", 3);
	ft_memcpy(&op[13].op_name, "lldi", 4);
	ft_memcpy(&op[14].op_name, "lfork", 5);
	ft_memcpy(&op[15].op_name, "aff", 3);
}

void		init_link_op(t_op *op)
{
	op[0].inst = op_live;
	op[1].inst = op_ld;
	op[2].inst = op_st;
	op[3].inst = op_add;
	op[4].inst = op_sub;
	op[5].inst = op_and;
	op[6].inst = op_or;
	op[7].inst = op_xor;
	op[8].inst = op_zjmp;
	op[9].inst = op_ldi;
	op[10].inst = op_sti;
	op[11].inst = op_fork;
	op[12].inst = op_lld;
	op[13].inst = op_lldi;
	op[14].inst = op_lfork;
	op[15].inst = op_aff;
}

uint16_t	vm_init(t_op *op)
{
	ft_bzero(op, sizeof(t_op) * 17);
	init_link_op(op);
	init_name_op(op);
	return (0);
}