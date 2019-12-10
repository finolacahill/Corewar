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
	return (1);
}

t_process *init_process(t_all *vm, t_champs *c, t_process *p)
{
	int i;

	i = 0;
	if (!(p = ft_memalloc(sizeof(t_process))))
		return (error_process(p));
	if (!(p->decode = malloc((sizeof(int)) * 4)))
		return (error_process(p));
	p->id = c->id;
	p->carry = 0;
	p->r[0] = p->id;
	while (++i < REG_NUMBER)
		p->r[i] = 0;
	p->live_calls = -1;
	p->start = c->start;
	p->op = c->exec_code[0];
	p->pc = p->start;
	p->next = NULL;
	p->exec_cycle = get_duration(vm, p->op);
	p->bytes = 0;
	return (p);
}

t_process *load_processes(t_all *vm, t_process *head)
{
	t_process   *new;
	int         i;

	i = 0;
	head = malloc(sizeof(t_process));
	new = init_process(vm, &vm->champs[0], new);
	head->next = new;
	while (++i < vm->total_champ)
	{
		if (new->start == -1)
			return (error_process(new));
		new->next = init_process(vm, &vm->champs[i], new->next);
		new = new->next;
	}
	head = head->next;
	return (head);
}

int		exec_process(t_all *vm, t_process *process)
{	
	int	bytes;

	if (process->op != 0)
		printf("id %d do operation %d at cycle %d\n", process->id, process->op, vm->cycles);
	bytes = 0;
	if (process->op == 1)
		op_live(vm, process);
	if (process->pc == MEM_SIZE - 1)
		process->pc = -1;
	process = ft_decode_byte(vm->arena[process->pc + 1], process);
	calc_bytes(process, &bytes);
	process->pc = process->pc + bytes + 1;
	if (process->pc > MEM_SIZE - 1)
		process->pc = process->pc - MEM_SIZE;
	process->op = vm->arena[process->pc];
	process->exec_cycle = get_duration(vm, process->op);
	return (0);
	}

int 	run_processes(t_all *vm, t_process *head)
{
	t_process *tracker;
	int live;

	//to be changed to CYCLES TO DIE
	live = CYCLE_TO_DIE * 1000;
	while (live != 0)
	{
		tracker = head;
		while (tracker != NULL)
		{
			if (vm->cycles == tracker->exec_cycle)
				exec_process(vm, tracker);
			tracker = tracker->next;
		}
		++vm->cycles;
		--live;
	}
	return (0);
}

int     run_vm(t_all *vm)
{
	unsigned char c = 68;
	int bytes = 0;

	t_process *process;

	process = load_processes(vm, process);
	if (process->start == -1)
		return (-1);
	run_processes(vm, process);
	return (0);
}