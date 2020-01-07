/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:54:21 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 16:57:59 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

uint16_t		check_op_fork(uint8_t *content)
{
	int			i;

	(void)content;
	i = 0;
	return (g_op_check_tab[11].dir_size + 1);
}

static void		copy_registers(t_process *p, t_process *new)
{
	int i;

	i = -1;
	while (++i < REG_NUMBER)
		new->r[i] = p->r[i];
}

t_process		*copy_process(t_process *p, t_process *new)
{
	if (!(new->decode = (int *)malloc(sizeof(int) * 4)))
	{
		free(new);
		p->op_fail = 3;
		return (new);
	}
	new->id = p->id;
	copy_registers(p, new);
	new->op = 0;
	new->exec_cycle = p->exec_cycle + 1;
	new->live_calls = p->live_calls;
	new->pc = p->pc;
	new->op_fail = 0;
	new->next = p->next;
	new->carry = p->carry;
	p->next = new;
	return (new);
}

void			op_fork(t_all *vm, t_process *p)
{
	int			p1;
	t_process	*new;

	if (!(new = (t_process*)malloc(sizeof(t_process))))
	{
		p->op_fail = 3;
		return ;
	}
	new = copy_process(p, new);
	if (p->op_fail == 3)
		return ;
	p1 = get_next_bytes(vm, p, 2, 0);
	new->pc += (p1 % IDX_MOD) - 1;
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | Fork to %d (+ pc %d = %d) cycle %d.\n",
		p->pid, p1, new->pc, p1 + new->pc, vm->cycles);
	if (new->pc < 0)
		new->pc += MEM_SIZE;
	load_new_process(vm, new);
	new->pid = vm->total_process + 1;
	++vm->total_process;
	p->next = new;
	p->op_fail = 2;
}
