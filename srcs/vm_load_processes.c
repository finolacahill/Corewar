/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_load_processes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:47:03 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 16:29:13 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_process		*load_processes(t_all *vm, t_process *head)
{
	t_process	*new;
	int			i;

	i = 0;
	head = init_process(vm, &vm->champs[0], head);
	while (++i < vm->total_champ)
	{
		if (head->start == -1)
			return (error_process(head));
		new = init_process(vm, &vm->champs[i], new);
		new->next = head;
		head = new;
	}
	return (head);
}

void			load_new_process(t_all *vm, t_process *p)
{
	p->pc = (p->pc + 1) % MEM_SIZE;
	p->op = vm->arena[p->pc];
	p->opc = vm->arena[(p->pc + 1) % MEM_SIZE];
	p = ft_decode_byte(p->op, p);
	if ((check_op_block(vm, p)) == 1)
	{
		if (if_no_opcode(p) == 0)
			p->opc = vm->arena[(p->pc + 1) % MEM_SIZE];
		else
			p->opc = 0;
		p->exec_cycle = get_duration(vm, p->op);
		p = ft_decode_byte(p->op, p);
	}
	else
	{
		p->op = 0;
		p->exec_cycle = vm->cycles + 1;
	}
//	ft_printf("PID %d exec cycle %d\n", p->pid, p->exec_cycle);
//	print_debug(vm, 32, p->pc, 0);
}

static void		re_order_process(t_process **process, t_process **head)
{
	t_process	*tmp;

	tmp = *head;
	while ((*process) != NULL && (*process)->op_fail != 2)
		*process = (*process)->next;
	if ((*process) != NULL)
	{
		tmp = (*head);
		(*head) = (*process)->next;
		(*process)->next = (*process)->next->next;
		(*head)->next = tmp;
		(*process)->op_fail = 0;
	}
}

t_process		**exec_process(t_all *vm, t_process **process, t_op *op_table,
				t_process **head)
{
	int			bytes;

	(*process) = ft_decode_byte(vm->arena[((*process)->pc + 1) % MEM_SIZE], *process);
	if (check_op_block(vm, *process) == 1)
	{
		(*process)->op_fail = 0;
	//	(*process) = ft_decode_byte(vm->arena[((*process)->pc + 1) % MEM_SIZE],
	//	*process);
		calc_bytes(*process, &bytes);
		if ((*process)->op != 0)
		{
			op_table[(*process)->op - 1].inst(vm, (*process));
			if ((*process)->op == 12 || (*process)->op == 15)
			{
				if ((*process)->op_fail == 3)
					end_prog(vm, (*head), op_table);
				if ((*process)->op_fail == 2)
					re_order_process(process, head);
			}
		}
	/*	if ((*process)->op_fail == 1 && (*process)->op_fail != 9)
			{
			//	recalc_bytes(*process, &bytes);
			//	(*process)->op_fail = 0;
			}*/
		if ((((*process)->op_fail == 0 || (*process)->op_fail == 1)
			&& (*process)->op != 9)
			|| ((*process)->op == 9 && (*process)->op_fail == 1))
			(*process)->pc = ((*process)->pc + bytes) % MEM_SIZE;
	//	ft_printf("\t\t\tPid %d pc = %d op = %d bytes %d\n", (*process)->pid, (*process)->pc, (*process)->op, bytes);
	//	print_debug(vm, 32, (*process)->pc, (*process)->pc + bytes);
	}
//	print_debug(vm, 32, (*process)->pc, (*process)->pc + bytes);
	load_new_process(vm, *process);
	return (head);
}
t_process		*check_is_rewritten(t_all *vm, t_process *p)
{
	if (vm->arena[p->pc] != p->op)
	{
		p->pc -= 1;
		load_new_process(vm, p);
		--p->exec_cycle;
	}
	return (p);
}
int				run_processes(t_all *vm, t_process **head, t_op *op_table)
{
	t_process	*tracker;
	int			live;

	live = vm->cycles_to_die;
	while (live > 0)
	{
		tracker = (*head);
	//	if (tracker != NULL)
			++vm->cycles;
	//	if (vm->flag_v == 2 || vm->flag_v == 4)
	//		ft_printf("cycle = %d\n", vm->cycles);
		while (tracker != NULL)
		{
			tracker = check_is_rewritten(vm, tracker);
			if (vm->cycles == tracker->exec_cycle)
				head = exec_process(vm, &tracker, op_table, head);
			tracker = tracker->next;
		}
		--live;
		if (vm->flag_dump != -1 && vm->cycles >= vm->flag_dump)
		{
			free_all_process(vm, (*head));
			return (-2);
		}
	}
	return (0);
}
