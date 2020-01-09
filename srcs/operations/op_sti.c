/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:12:38 by adietric          #+#    #+#             */
/*   Updated: 2020/01/09 17:49:28 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

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
	if (vm->flag_v == 4)
	{
		ft_printf("\n\tP%6d | sti reg %d", p->pid, get_next_bytes(vm, p, 1, 1));
		ft_printf(" val %d to %d + %d with ", p1, p2, p3);
		ft_printf("mod %d (with pc ", (p2 + p3) % IDX_MOD);
		ft_printf("%d) at cycle %d\n",
		((p2 + p3) + p->pc) % MEM_SIZE, vm->cycles);
	}
	if (p->op_fail == 1)
		return ;
	load_value(vm, (p->pc + ((p2 + p3) % IDX_MOD)), 4, p1);
}
