/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:51:14 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 16:52:20 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

uint16_t	check_op_add(uint8_t *content)
{
	int		i;

	i = 0;
	if (!(content[1]) || is_in(content[1], g_op_check_tab[3].ocp_value) != 1)
		return (0);
	i = content[1] == 84 ? 3 * 1 + 2 : 0;
	return (i);
}

void		op_add(t_all *vm, t_process *p)
{
	long	p1;
	long	p2;

	p1 = get_reg_val(vm, p, 1);
	p2 = get_reg_val(vm, p, 2);
	if (p->op_fail == 1)
		return ;
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | add R%ld R%ld R%ld at cycles %d\n", p->pid,
		get_next_bytes(vm, p, 1, 1), get_next_bytes(vm, p, 1, 2),
		get_next_bytes(vm, p, 1, 3), vm->cycles);
	if (p->op_fail == 1)
		return ;
	load_val_in_reg(vm, p, p1 + p2, 3);
	if (p->op_fail != 1)
		check_carry(p, p1 + p2);
//	if (vm->cycles == 815)
//		print_debug(vm, 32, p->pc, 0);
}
