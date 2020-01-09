/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:53:15 by adietric          #+#    #+#             */
/*   Updated: 2020/01/09 17:48:25 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			op_and(t_all *vm, t_process *p)
{
	long			pm1;
	long			pm2;
	long			bytes_read;

	bytes_read = 1;
	pm1 = get_unspecified_val(vm, p, &bytes_read, 0);
	pm2 = get_unspecified_val(vm, p, &bytes_read, 1);
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | and\n", p->pid);
	if (p->op_fail == 1)
		return ;
	load_val_in_reg(vm, p, pm1 & pm2, bytes_read);
	if (p->op_fail != 1)
		check_carry(p, pm1 & pm2);
}
