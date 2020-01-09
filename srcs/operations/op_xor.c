/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:26:40 by adietric          #+#    #+#             */
/*   Updated: 2020/01/09 17:49:41 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void			op_xor(t_all *vm, t_process *p)
{
	long		pm1;
	long		pm2;
	long		bytes_read;

	bytes_read = 1;
	pm1 = get_unspecified_val(vm, p, &bytes_read, 0);
	pm2 = get_unspecified_val(vm, p, &bytes_read, 1);
/*
if (p->decode[0] != REG_CODE && (pm1 % 65536) >= 32768)
		pm1 += 65536;
	if (p->decode[1] != REG_CODE && (pm2 % 65536) >= 32768)
		pm2 += 65536;
*/
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | xor R%d/pm1 %d R%d/pm2 %d R%d at cycles %d\n",
		p->pid, get_next_bytes(vm, p, 1, 1), pm1,
		get_next_bytes(vm, p, 1, 2), pm2,
		get_next_bytes(vm, p, 1, bytes_read), vm->cycles);
	if (p->op_fail == 1)
		return ;
	load_val_in_reg(vm, p, pm1 ^ pm2, bytes_read);
	if (p->op_fail != 1)
		check_carry(p, pm1 ^ pm2);
}
