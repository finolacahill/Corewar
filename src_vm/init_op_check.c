/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_op_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:04:38 by adietric          #+#    #+#             */
/*   Updated: 2020/01/09 17:47:01 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	init_link_op(t_op *op)
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

t_op		*init_op_check(t_all *vm, t_op *op)
{
	ft_bzero(op, sizeof(t_op) * 16);
	init_link_op(op);
	return (op);
}
