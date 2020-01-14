/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:12:38 by adietric          #+#    #+#             */
/*   Updated: 2020/01/10 11:56:24 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void		print_sti(t_all *vm, t_process *p, long p2, long p3)
{
	ft_printf("\tP%6d | sti r%d, %d, %d", p->pid,
		get_next_bytes(vm, p, 1, 1), p2, p3);
	ft_printf("\n\t\t| -> store to %d + %d with ", p2, p3);
	ft_printf("mod %d (with pc ", (p2 + p3) % IDX_MOD);
	ft_printf("%d) at cycle %d\n",
		(((p2 + p3) % IDX_MOD) + p->pc) % MEM_SIZE, vm->cycles);
}

void			op_sti(t_all *vm, t_process *p)
{
	long		p1;
	long		p2;
	long		p3;
	long		bytes_read;

	bytes_read = 2;
	p1 = get_reg_val(vm, p, 1);
	p2 = get_unspecified_val_2(vm, p, &bytes_read, 1);
	p3 = get_unspecified_val_2(vm, p, &bytes_read, 2);
	p2 = check_neg_address(p2);
	p3 = check_neg_address(p3);
	if (p->op_fail == 1)
		return ;
	if (vm->flag_v == 4)
		print_sti(vm, p, p2, p3);
	load_value(vm, (p->pc + ((p2 + p3) % IDX_MOD)), 4, p1);
}
