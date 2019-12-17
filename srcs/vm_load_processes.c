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

static void	init_registers(t_process *p)
{
	int i;

	i = 0;
	p->r[0] = p->id;
	while (++i < REG_NUMBER)
		p->r[i] = 0;
}

t_process	*init_process(t_all *vm, t_champs *c, t_process *p)
{	
	if (!(p = ft_memalloc(sizeof(t_process))))
		return (error_process(p));
	if (!(p->decode = malloc((sizeof(int)) * 4)))
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
	if ((if_no_opcode(p)) == 1)
		p->opc = 0;
	else
		p->opc = c->exec_code[1];
	p = ft_decode_byte(p->opc, p);
	return (p);
}

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

void 	load_new_process(t_all *vm, t_process *p)
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

int		exec_process(t_all *vm, t_process *process, t_op *op_table)
{	
	int	bytes;

	bytes = 0;
	if (re_check_block(vm, process) == 1)
	{
		process->op_fail = 0;
		process = ft_decode_byte(vm->arena[process->pc + 1], process);
		calc_bytes(process, &bytes);
		if (process->op != 0)
		{		
			ft_printf("	=> id %d do operation %d at cycle %d\n", process->id, process->op, vm->cycles);
			op_table[process->op - 1].inst(vm, process);
		}
		if (process->op_fail == 0)
			process->pc = (process->pc + bytes) % MEM_SIZE;
	}
	load_new_process(vm, process);
	return (0);
}

int 	run_processes(t_all *vm, t_process *head, t_op *op_table)
{
	t_process *tracker;
	int live;

	live = vm->cycles_to_die;
	while (live != 0)
	{
		if (vm->flag_dump != -1 && vm->cycles >= vm->flag_dump)
		{
			ft_printf("_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_vm->cycles = %d\n", vm->cycles);
			ft_print_arena(vm);
			return (-100);
			//KILL ALL 
		}
		tracker = head;
		if (tracker != NULL)
			++vm->cycles;
		while (tracker != NULL)
		{
			if (vm->cycles == tracker->exec_cycle)
				exec_process(vm, tracker, op_table);
			tracker = tracker->next;
		}		
		--live;
	}
	return (0);
}

void	declare_winner(t_all *vm)
{
	if (is_player_nb(vm->last_alive, vm) == 1)
		ft_printf("THE WINNER IS PLAYER NUMBER %d, %s!!!\n", vm->last_alive, vm->champs[vm->last_alive - 1].name);
	else
	{
		ft_printf("A mystery player, number %d, has won", vm->last_alive); //or it was a draw?
	}
	
}

int     run_vm(t_all *vm)
{
	t_process	*process;
	t_op		*op_table;

	if (!(op_table = (t_op*)malloc(sizeof(t_op) * 16)))
		error(vm, "malloc error run_vm");
	op_table = init_op_check(vm, op_table);
	vm->cycles_to_die = CYCLE_TO_DIE;
	process = load_processes(vm, process);
	if (process->start == -1)
		return (-1);
	while (check_alive(vm, process) == 1)
		if ((run_processes(vm, process, op_table) == -100))
			return (0);
	declare_winner(vm);
	return (0);
}