/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_op_block.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:50:21 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 12:34:35 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			check_comb_op_ocp(t_all *vm, t_process *process)
{
	int		val_ocp;
	int		op;

	op = process->op;
	val_ocp = get_next_bytes(vm, process, 1, 0);
	if (if_no_opcode(process) == 1)
		return (1);
	if (val_ocp == 0
		|| is_in(val_ocp, g_op_check_tab[process->op - 1].ocp_value) != 1)
		return (0);
	return (1);
}

int			check_op_block(t_all *vm, t_process *process)
{
	if (process->op < 1 || process->op > 16)
		return (0);
	if (check_comb_op_ocp(vm, process) == 0)
		return (0);
	return (1);
}

int			re_check_block(t_all *vm, t_process *process)
{
	int		new_opc;

	if ((if_no_opcode(process)) == 0)
	{
		new_opc = vm->arena[process->pc + 1];
		if (new_opc != process->opc)
		{
			if (check_comb_op_ocp(vm, process) == 0)
				return (0);
		}
	}
	return (1);
}
