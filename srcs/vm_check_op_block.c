/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_op_block.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:50:21 by adietric          #+#    #+#             */
/*   Updated: 2019/12/15 22:40:18 by adietric         ###   ########.fr       */
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

int		check_comb_op_ocp(t_all *vm, t_process *process)
{
	int val_ocp;
	int op;

	op = process->op;
	val_ocp = get_next_bytes(vm, process, 1, 0);
																		printf("	\033[32;1mEst ce que ocp %d est ok pour une op %d (%s)? \n", 
																		val_ocp, process->op, op_check_tab[process->op - 1].name);
	if (is_it_ocp(process) == -1)
	{
																		printf("		\033[38;5;129mPAS OCP\033[0m\n");
		return (1);
	}
	if (val_ocp == 0 || is_in(val_ocp, op_check_tab[process->op - 1].ocp_value) != 1)
	{
																		printf("		\033[38;5;160mNON\033[0m\n");
		return (0);
	}
																		printf("		\033[38;5;12mOUI\033[0m\n");
	return (1);
}

int		check_op_block(t_all *vm, t_process *process)  //Prochain bloc (op + opc + values) est bon ? 1 : 0;
{
	if (process->op < 1 || process->op > 16)
		return (0);												//op fausse
	if (check_comb_op_ocp(vm ,process) == 0)
		return (0);												//op fausse
	return (1);
}