/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:44:21 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 12:46:36 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			get_duration(t_all *vm, int opc)
{
	if (opc == 1 || opc == 4 || opc == 5 || opc == 13)
		return (vm->cycles + 10);
	if (opc == 2 || opc == 3)
		return (vm->cycles + 5);
	if (opc == 6 || opc == 7 || opc == 8)
		return (vm->cycles + 6);
	if (opc == 9)
		return (vm->cycles + 20);
	if (opc == 10 || opc == 11)
		return (vm->cycles + 25);
	if (opc == 12)
		return (vm->cycles + 800);
	if (opc == 14)
		return (vm->cycles + 50);
	if (opc == 15)
		return (vm->cycles + 1000);
	if (opc == 16)
		return (vm->cycles + 2);
	return (1);
}

static void	init_registers(t_process *p)
{
	int		i;

	i = 0;
	p->r[0] = p->id;
	while (++i < REG_NUMBER)
		p->r[i] = 0;
}

t_process	*init_process(t_all *vm, t_champs *c, t_process *p)
{
	if (!(p = (t_process*)ft_memalloc(sizeof(t_process))))
		return (error_process(p));
	if (!(p->decode = (int *)malloc((sizeof(int)) * 4)))
		return (error_process(p));
	p->id = c->id;
	p->carry = 0;
	init_registers(p);
	p->live_calls = -1;
	p->start = c->start;
	p->op = c->exec_code[0];
	p->pc = p->start;
	p->next = NULL;
	p->exec_cycle = get_duration(vm, p->op);
	p->bytes = 0;
	c->last_live = 0;
	p->op_fail = 0;
	p->pid = vm->total_process + 1;
	++vm->total_process;
	if ((if_no_opcode(p)) == 1)
		p->opc = 0;
	else
		p->opc = c->exec_code[1];
	p = ft_decode_byte(p->opc, p);
	return (p);
}

static void	get_order(t_all *vm)
{
	int i;
	int x;

	i = -1;
	x = 1;
	if (!(vm->order = malloc(sizeof(int) * MAX_PLAYERS)))
	{
		free(vm->arena);
		error(vm, "Malloc error in get_order\n");
	}
	while (++i < vm->total_champ)
		vm->order[i] = i;
	while (x < vm->total_champ)
	{
		if (vm->champs[vm->order[x]].id < vm->champs[vm->order[x - 1]].id)
		{
			ft_swap(&vm->order[x], &vm->order[x - 1]);
			x = 0;
		}
		++x;
	}
}

t_all		*init_arena(t_all *vm)
{
	int		i;
	int		divide;

	i = -1;
	divide = 0;
	vm->cycles = 0;
	vm->dead = 0;
	vm->last_alive = 0;
	vm->last_alive_cycle = 0;
	vm->nbr_live_since_check = 0;
	vm->total_checks = 0;
	vm->total_process = 0;
	if (!(vm->arena = (unsigned char *)ft_memalloc((sizeof(unsigned char))
		* MEM_SIZE)))
		error(vm, "Malloc error init_arena.\n");
	get_order(vm);
	while (++i < vm->total_champ)
	{
		vm->champs[vm->order[i]].start = divide;
		ft_memcpy(&vm->arena[divide], vm->champs[vm->order[i]].exec_code,
		vm->champs[vm->order[i]].len_exec_code);
		divide = divide + MEM_SIZE / vm->total_champ;
	}
	return (vm);
}
