
#include "../includes/vm.h"

t_process *load_processes(t_all *vm, t_process *head)
{
	t_process   *new;
	int         i;

	i = 0;
	head = init_process(vm, &vm->champs[0], head);
	ft_printf("new->hwad = %d/%02x\n", head->id, head->id);
	ft_printf("reg  = %d/%02x\n", head->r[0], head->r[0]);
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

 void	load_new_process(t_all *vm, t_process *p)
{
	p->pc = (p->pc + 1) % MEM_SIZE;
	p->op = vm->arena[p->pc];
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
}

static void	re_order_process(t_process **process , t_process **head)
{
	t_process *tmp;

	tmp = *head;
	while((*process) != NULL && (*process)->op_fail != 2)
		*process = (*process)->next;
	if ((*process) != NULL)
	{
		tmp = (*head);
		(*head) = (*process)->next;
		(*process)->next = (*process)->next->next;
		(*head)->next = tmp;
		(*process)->op_fail = 0;
	//	printf("head = %d\n", (*head)->pid);
	//	printf("next head = %d\n", (*head)->next->pid);
	}	
}

t_process 	**exec_process(t_all *vm, t_process **process, t_op *op_table, t_process **head)
{	
	int	bytes;

	bytes = 0;
//	ft_printf("->%d\n", (*p)->op);
	if (re_check_block(vm, *process) == 1)
	{
		(*process)->op_fail = 0;
		(*process) = ft_decode_byte(vm->arena[((*process)->pc + 1) % MEM_SIZE], *process);
		calc_bytes(*process, &bytes);
		if ((*process)->op != 0)
		{	
	//		ft_printf("	=> id %d do operation %d at cycle %d\n", (*process)->id, (*process)->op, vm->cycles);
			op_table[(*process)->op - 1].inst(vm, (*process));
	//		printf("(*id = %dm dail %d\n", (*process)->op, (*process)->op_fail);
			if ((*process)->op == 12 || (*process)->op == 15)
			{
				if((*process)->op_fail == 2)
					re_order_process(process, head);
		//		printf("\n\tnow head = %d, linke = %d\n", (*head)->id, (*head)->next->id);
			}
		//		ft_printf("bytes = %d\n", bytes);		
		}
		if (((*process)->op_fail == 0 && (*process)->op != 9) || ((*process)->op == 9 && (*process)->op_fail == 1))
			(*process)->pc = ((*process)->pc + bytes) % MEM_SIZE;
	}
	load_new_process(vm, *process);
//	printf("\n\tnow head = %d, linke = %d\n", (*head)->id, (*head)->next->id);		
	return (head);
}

int run_processes(t_all *vm, t_process **head, t_op *op_table)
{
	t_process *tracker;
	int live;

	live = vm->cycles_to_die;
	printf("live = %d\n", live);
//	ft_print_arena(vm, 32, 0);
	while (live > 0)
	{
	//	printf("live = %d\n", live);
		if (vm->flag_dump != -1 && vm->cycles >= vm->flag_dump)
		{
			ft_printf("_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_vm->cycles = %d\n", vm->cycles);
			ft_print_arena(vm, 32, (*head)->pc);
			return (-100);
			//KILL ALL 
		}
		tracker = (*head);
		if (tracker != NULL)
			++vm->cycles;
		while (tracker != NULL)
		{
	//		ft_printf("tracker = %d op = %d exec = %d cycle = %d\n", tracker->id, tracker->op, tracker->exec_cycle, vm->cycles);
			if (vm->cycles == tracker->exec_cycle)
				head = exec_process(vm, &tracker, op_table, head);
			tracker = tracker->next;
		}
		--live;
	}
	return (0);
}
