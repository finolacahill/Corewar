/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:58:09 by adietric          #+#    #+#             */
/*   Updated: 2020/01/10 11:54:45 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		op_ld(t_all *vm, t_process *p)
{
	long	pm1;
	long	bytes_read;

	bytes_read = 1;
	pm1 = get_unspecified_val(vm, p, &bytes_read, 0);
	load_val_in_reg(vm, p, pm1, bytes_read);
	if (p->op_fail == 1)
		return ;
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | load %d R%d at cycle %d\n", p->pid, pm1,
		get_next_bytes(vm, p, 1, bytes_read), vm->cycles);
	check_carry(p, pm1);
}
