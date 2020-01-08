/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_run_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:40:12 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 16:41:36 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		declare_winner(t_all *vm)
{
	int		i;

	i = -1;
	while (i++ < vm->total_champ)
	{
		if (vm->champs[i].id == vm->last_alive && vm->last_alive != 0)
		{
			ft_printf("THE WINNER IS PLAYER NUMBER %d, %s!!!\n",
			vm->last_alive, vm->champs[i].name);
			return ;
		}
	}
	ft_printf("Nobody declared themselves alive, it's a draw. :(\n");
}

static int	dump(t_all *vm, t_process *p, t_op *op)
{
	ft_print_arena(vm, 32);
	//print_debug(vm, 64, p->pc, -1);
	free_op_table(op);
	return (0);
}

int			run_vm(t_all *vm, t_process *process)
{
	t_op	*op_table;

	if (!(op_table = (t_op*)malloc(sizeof(t_op) * 16)))
	{
		free(vm->order);
		free(vm->arena);
		error(vm, "Malloc error run_vm.\n");
	}
	op_table = init_op_check(vm, op_table);
	vm->cycles_to_die = CYCLE_TO_DIE;
	process = load_processes(vm, process);
	if (process->start == -1)
		return (error_run_vm(vm, op_table));
	while (check_alive(vm, &process) == 1)
	{
		if ((run_processes(vm, &process, op_table)) == -2)
			return (dump(vm, process, op_table));
	}
	declare_winner(vm);
	free_op_table(op_table);
	return (0);
}
