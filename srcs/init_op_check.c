/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_op_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:04:38 by adietric          #+#    #+#             */
/*   Updated: 2019/12/16 08:46:35 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		init_link_verif_op(t_verif_op *op)
{
	op[0].inst = check_op_live;
	op[1].inst = check_op_ld;
	op[2].inst = check_op_st;
	op[3].inst = check_op_add;
	op[4].inst = check_op_sub;
	op[5].inst = check_op_and;
	op[6].inst = check_op_or;
	op[7].inst = check_op_xor;
	op[8].inst = check_op_zjmp;
	op[9].inst = check_op_ldi;
	op[10].inst = check_op_sti;
	op[11].inst = check_op_fork;
	op[12].inst = check_op_lld;
	op[13].inst = check_op_lldi;
	op[14].inst = check_op_lfork;
	op[15].inst = check_op_aff;
}

t_verif_op		*init_op_verif(t_all *vm, t_verif_op *op)
{
	ft_bzero(op, sizeof(t_verif_op) * 16);
	init_link_verif_op(op);
	return (op);
}

void		init_name_op(t_all *vm, t_op **op)
{
	int		i;

	i = -1;
	(*op)[0].op_name = ft_strdup("live");
	(*op)[1].op_name = ft_strdup("ld");
	(*op)[2].op_name = ft_strdup("st");
	(*op)[3].op_name = ft_strdup("add");
	(*op)[4].op_name = ft_strdup("sub");
	(*op)[5].op_name = ft_strdup("and");
	(*op)[6].op_name = ft_strdup("or");
	(*op)[7].op_name = ft_strdup("xor");
	(*op)[8].op_name = ft_strdup("zjmp");
	(*op)[9].op_name = ft_strdup("ldi");
	(*op)[10].op_name = ft_strdup("sti");
	(*op)[11].op_name = ft_strdup("fork");
	(*op)[12].op_name = ft_strdup("lld");
	(*op)[13].op_name = ft_strdup("lldi");
	(*op)[14].op_name = ft_strdup("lfork");
	(*op)[15].op_name = ft_strdup("aff");
	//NEED MALLOC PROTECTION HERE
	while (++i < 16)
	{
		if ((*op)[i].op_name == NULL)
			error(vm, "malloc error init_name_op");
		// printf("		op[%d].op_name = |%s|\n", i, (*op)[i].op_name);
	}
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

t_op		*init_op_check(t_all *vm, t_op *op)
{
	ft_bzero(op, sizeof(t_op) * 16);
	init_link_op(op);
	init_name_op(vm, &op);
	return (op);
}