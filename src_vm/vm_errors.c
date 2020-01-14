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

t_process	*error_process(t_process *p)
{
	p->start = -1;
	return (p);
}

void		error_arena(t_all *vm, t_process *p)
{
	ft_fprintf(2, "Malloc error init_arena.\n");
	free_all(vm, p);
	exit(1);
}

int			error_run_vm(t_all *vm, t_op *op_table)
{
	if (op_table != NULL)
		free(op_table);
	ft_fprintf(2, "Malloc error run_vm.\n");
	return (-1);
}

void		end_prog(t_all *vm, t_process *head, t_op *op)
{
	free_all_process(vm, head);
	free(vm->arena);
	free(vm->order);
	free(op);
	error(vm, "Malloc error during fork.\n");
}

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
