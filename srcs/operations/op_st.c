/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:10:04 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 17:12:08 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

uint16_t		check_op_st(uint8_t *content)
{
	int			i;

	(void)content;
	i = 0;
	if (!(content[1]) || is_in(content[1], g_op_check_tab[2].ocp_value) != 1)
		return (0);
	i += content[1] == 80 ? 2 * 1 : 0;
	i += content[1] == 112 ? 1 + IND_SIZE : 0;
	i += 2;
	return (i);
}

void			op_st(t_all *vm, t_process *p)
{
	long		param1;
	long		param2;

	param2 = -1;
	if ((param1 = get_reg_val(vm, p, 1)) == -1 && p->op_fail == 1)
		return ;
	if (p->decode[1] == REG_CODE)
	{
		load_val_in_reg(vm, p, param1, 2);
		if (vm->flag_v == 4)
			ft_printf("\tP%6d | st R%d (%d) at at R%d + pc %d at cycle %d \n",
			p->pid, get_next_bytes(vm, p, 1, 1), param1,
			get_next_bytes(vm, p, 1, 2), p->pc, vm->cycles);
		if (p->op_fail == 1)
			return ;
	}
	else
	{
		param2 = get_ind(vm, p, 2, 0);
		if (vm->flag_v == 4)
			ft_printf("\tP%6d | st R%d (%d) at at %d + pc %d at cycle %d \n",
			p->pid, get_next_bytes(vm, p, 1, 1), param1, param2 % IDX_MOD,
			p->pc, vm->cycles);
		load_value(vm, p->pc + (param2 % IDX_MOD), 4, param1);
	}
//	print_debug(vm, 64, p->pc, p->pc + (param2 % IDX_MOD));
}
