/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:36:41 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 12:36:49 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** In case of malloc error in the process, marks p->start as -1
** to signal to following process to end program. 
*/
t_process	*error_process(t_process *p)
{
	p->start = -1;
	return (p);
}

/*
** In case of malloc error in the arena, frees and exits.
*/
void		error_arena(t_all *vm, t_process *p)
{
	ft_fprintf(2, "Malloc error init_arena.\n");
	free_all(vm, p);
	exit(1);
}

/*
** In case of malloc error in the vm, frees and exits.
*/
int			error_run_vm(t_all *vm, t_op *op_table)
{
	if (op_table != NULL)
		free(op_table);
	ft_fprintf(2, "Malloc error run_vm.\n");
	return (-1);
}

/*
** In case of Malloc error during fork.
** Free all the proccess', the arena, the order, op_table and vm.
*/
void		end_prog(t_all *vm, t_process *head, t_op *op)
{
	free_all_process(vm, head);
	free(vm->arena);
	free(vm->order);
	free(op);
	error(vm, "Malloc error during fork.\n");
}

/*
** Free all the proccesses in the process loop
*/
void		free_all_process(t_all *vm, t_process *p)
{
	t_process	*tmp;

	tmp = p;
	while (p != NULL)
	{
		tmp = p;
		p = p->next;
		free_process(vm, tmp);
	}
}
