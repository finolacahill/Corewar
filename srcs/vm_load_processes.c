
#include "../includes/vm.h"

t_process *load_processes(t_all *vm, t_process *head)
{
	t_process   *new;
	int         i;

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
	}	
}

t_process 	**exec_process(t_all *vm, t_process **process, t_op *op_table, t_process **head)
{	
	int	bytes;

	bytes = 0;
//	if((*process)->pid == 8)
//	{
	//	ft_printf("\t\t CYCLE = %d\n", vm->cycles);
	//	ft_print_arena(vm, 32, (*process)->pc);
	//	if (vm->cycles >= 4957)
	//		exit(1);}
	if (re_check_block(vm, *process) == 1)
	{
		(*process)->op_fail = 0;
		(*process) = ft_decode_byte(vm->arena[((*process)->pc + 1) % MEM_SIZE], *process);
		calc_bytes(*process, &bytes);
		if ((*process)->op != 0)
		{	
			op_table[(*process)->op - 1].inst(vm, (*process));
			if ((*process)->op == 12 || (*process)->op == 15)
			{
				if((*process)->op_fail == 2)
					re_order_process(process, head);
			}
		}
	//	if (vm->arena[2289] == 1)
	//	{
	//		ft_printf("\t\tIT HAPPENED HERE %d\n", vm->cycles);
	//		exit(1);
	//	}
		if (((*process)->op_fail == 0 && (*process)->op != 9) || ((*process)->op == 9 && (*process)->op_fail == 1))
			(*process)->pc = ((*process)->pc + bytes) % MEM_SIZE;
	}
	load_new_process(vm, *process);
	return (head);
}

int run_processes(t_all *vm, t_process **head, t_op *op_table)
{
	t_process *tracker;
	int live;

	live = vm->cycles_to_die;
	while (live > 0)
	{
		if (vm->flag_dump != -1 && vm->cycles >= vm->flag_dump)
		{
			ft_printf("_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_ vm->cycles = %d\n", vm->cycles);
			ft_print_arena(vm, 32, 2289);
			return (-100);
			//KILL ALL 
		}
		tracker = (*head);
		if (tracker != NULL)
			++vm->cycles;
		while (tracker != NULL)
		{
			if (vm->cycles == tracker->exec_cycle)
				head = exec_process(vm, &tracker, op_table, head);
			tracker = tracker->next;
		}
		--live;
	}
	return (0);
}
