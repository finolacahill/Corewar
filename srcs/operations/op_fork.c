#include "../../includes/vm.h"

uint16_t		check_op_fork(t_all *all, uint8_t *content)
{
	int			i;

	(void)content;
	i = 0;
	return (op_check_tab[11].dir_size + 1);
}

t_process	*copy_process(t_process *p, t_process *new)
{
	int i; 

	i = -1;
	if (!(new = malloc(sizeof(t_process))))
	{
		p->op_fail = -1;
		return (new);
	};
	if (!(new->decode = malloc(sizeof(int) * 4)))
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
	new->all_dead = 0;
	new->next = p->next;
	new->carry = p->carry;
	p->next = new;
//	ft_printf("new pc = %d\n", new->pc);
	return (new);
}
//323 (414)
void    op_fork(t_all *vm, t_process *p)
{
	int p1;
	t_process *new;

	new = copy_process(p, new);
	if (p->op_fail == -1)
		return ;
//	ft_printf("new pc = %d\n", new.pc);
	int p2;
//	(vm, 64, p->pc);
	p1 = get_next_bytes(vm, p, 2, 0);	
//	ft_printf("%04x, %04x\n", p->op, p1);
//	ft_printf("\t\tFork to %d (+ pc %d = %d)\n", p1, new->pc, p1 + new->pc);
	new->pc += p1 - 1;
	load_new_process(vm, new);
	new->pid = vm->total_process + 1;
	++vm->total_process;
	p->next = new;
	p->op_fail = 2;
}