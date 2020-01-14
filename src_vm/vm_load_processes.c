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

/*
** Load and link initial processes. If there is a malloc error
** (head->start == -1) end the program.
*/
t_process	*load_processes(t_all *vm, t_process *head)
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

/*
** Move carraige forward one place (having already jumped
** all the parameters involved in previous operation)
** Set op to this value, and the opcode to the value after. 
** Check if it's a valid operation, and if so set duration
** and decode byte. Otherwise operation is 0 (empty)
** and exec is this cycle plus 1, so that we will check 
** for a valid operation at the next cycle.
*/
void		load_new_process(t_all *vm, t_process *p)
{
	p->pc = (p->pc + 1) % MEM_SIZE;
	if (p->pc < 0)
		p->pc += MEM_SIZE;
	p->op = vm->arena[p->pc % MEM_SIZE];
	p->opc = vm->arena[(p->pc + 1) % MEM_SIZE];
	p = ft_decode_byte(p->op, p);
	if ((is_operation(p->op)) == 1)
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
}

/*
** If fork has created a new process, we reorder to keep newest process
** first. 
*/
static void	re_order_process(t_process **process, t_process **head)
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

/*
** If we have forked. If it has failed we end program, 
** if it hasn't failed, we reorder process to maintain continuity.
*/ 
static void	check_fork(t_all *vm, t_process **p, t_op *op, t_process **head)
{
	if ((*p)->op == 12 || (*p)->op == 15)
	{
		if ((*p)->op_fail == 3)
			end_prog(vm, (*head), op);
		if ((*p)->op_fail == 2)
			re_order_process(p, head);
	}
}

/*
** Check if the operation is still valid (operation number and opcode)
** before execution reset fail to 0, calculate bytes to jump after execution, 
** and if op is not equal to zero (indicating empty operation), we execute. 
** If a malloc hasn't failed and we are not jumping, we reset pc. 
** we then load a new process.
*/
t_process	**exec_process(t_all *vm, t_process **p, t_op *op, t_process **head)
{
	int			bytes;

	(*p) = ft_decode_byte(vm->arena[((*p)->pc + 1)
		% MEM_SIZE], *p);
	if (check_op_block(vm, *p) == 1)
	{
		(*p)->op_fail = 0;
		calc_bytes(*p, &bytes);
		if ((*p)->op != 0)
		{
			op[(*p)->op - 1].inst(vm, (*p));
			check_fork(vm, p, op, head);
		}
		if ((((*p)->op_fail == 0 || (*p)->op_fail == 1)
			&& (*p)->op != 9)
			|| ((*p)->op == 9 && (*p)->op_fail == 1))
			(*p)->pc = ((*p)->pc + bytes) % MEM_SIZE;
	}
	load_new_process(vm, *p);
	return (head);
}
