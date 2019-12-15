/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_op_block.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:50:21 by adietric          #+#    #+#             */
/*   Updated: 2019/12/15 19:46:14 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		is_it_ocp(t_process *process)
{
	int	op;

	op = process->op;
	if (op == 1 || op == 9 || op == 12 || op == 15)
		return (-1);
	return (0); 
}

int		check_reg(t_all *vm, t_process *process)
{
	int		reg;
	int		ocp;

	ocp = get_next_bytes(vm, process, 1, 0);
	if (process->op == 2)
		if (is_reg(reg = get_next_bytes(vm, process, 1, ocp == 144 ? 5 : 3)
			, process) != 1)
			return (0);
	else if (process->op == 3)
	{
		if (is_reg(reg = get_next_bytes(vm, process, 1, 1)
			, process) != 1)
			return (0);
		if (is_reg(reg = get_next_bytes(vm, process, 1, ocp == 80 ? 2 : 1)
			, process) != 1)
			return (0);
	}
	return (1);
}

int		check_comb_op_ocp(t_all *vm, t_process *process)
{
	int val;
	int op;

	op = process->op;
	val = get_next_bytes(vm, process, 1, 0);
																		printf("	\033[32;1mEst ce que ocp %d est ok pour une op %d ? \n", val, process->op);
	if (is_it_ocp(process) == -1)
	{
																		printf("		PAS OCP\033[0m\n");
		return (1);
	}
	if (is_in(val, op_check_tab[process->op - 1].ocp_value) != 1)
	{
																		printf("		NON\033[0m\n");
		return (0);
	}
																		printf("		OUI\033[0m\n");
	return (1);
}

int		check_op_block(t_all *vm, t_process *process)  //Prochain bloc (op + opc + values) est bon ? 1 : 0;
{
	if (process->op < 1 || process->op > 16)
		return (0);
	if (check_comb_op_ocp(vm ,process) == 0)
		return (0);
	if (is_it_ocp(process) == 0)
		if (check_reg(vm, process) == 0)
			return (0);
	return (1);
}