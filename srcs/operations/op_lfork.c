#include "../../includes/vm.h"

uint16_t		check_op_lfork(t_all *all, uint8_t *content)
{
	int			i;

	(void)content;
	i = 0;
	return (op_check_tab[14].dir_size + 1);
}

t_process	*l_copy_process(t_process *p, t_process *new)
{
	int i; 

	i = -1;
	if (!(new = (t_process*)malloc(sizeof(t_process))))
	{
		p->op_fail = -1;
		return (new);
	};
	if (!(new->decode = (int *)malloc(sizeof(int) * 4)))
	{
		free(new);
		p->op_fail = -1;
		return (new);
	}
	new->id = p->id;
	while (++i < REG_NUMBER)	
		new->r[i] = p->r[i];
	new->op = 0;
	new->exec_cycle = p->exec_cycle + 1;
	new->live_calls = p->live_calls;
	new->pc = p->pc;
	new->op_fail = 0;
	new->next = p->next;
	new->carry = p->carry;
	p->next = new;
//	ft_printf("new pc = %d\n", new->pc);
	return (new);
}
//323 (414)
void    op_lfork(t_all *vm, t_process *p)
{
	int p1;
	t_process *new;

	new = l_copy_process(p, new);
	if (p->op_fail == -1)
		return ;
//	ft_printf("new pc = %d\n", new.pc);
	int p2;
//	(vm, 64, p->pc);
	p1 = get_next_bytes(vm, p, 2, 0);	
//	ft_printf("%04x, %04x\n", p->op, p1);
//	ft_printf("\t\tFork to %d (+ pc %d = %d)\n", p1, new->pc, p1 + new->pc);
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | Lfork to %d (+ pc %d = %d) at cycle %d\n", p->pid, p1, new->pc, p1 + new->pc, vm->cycles);
	new->pc += p1 - 1;
	if (new->pc < 0)
		new->pc += MEM_SIZE;
//	ft_print_arena(vm, 64, p->pc, new->pc);
	load_new_process(vm, new);
	new->pid = vm->total_process + 1;
	++vm->total_process;
	p->next = new;
	p->op_fail = 2;
}