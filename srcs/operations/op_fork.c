#include "../../includes/vm.h"

uint16_t		check_op_fork(t_all *all, uint8_t *content)
{
	int			i;

	(void)content;
	i = 0;
	return (op_check_tab[11].dir_size + 1);
}

int		copy_process(t_process *p, t_process *new)
{
	int i; 

	i = -1;
	if (!(new = malloc(sizeof(t_process))))
		return (-1);
	if (!(new->decode = malloc(sizeof(int) * 4)))
	{
		free(new);
		return (-1);
	}
	new->id = p->id * 10;
	while (++i < REG_NUMBER)	
		new->r[i] = p->r[i];
	new->op = 0;
	new->exec_cycle = p->exec_cycle + 1;
	new->live_calls = p->live_calls;
	new->pc = p->pc;
	new->op_fail = 0;
	new->all_dead = 0;
	new->next = p->next;
	p->next = new;
	return (0);
}

void    op_fork(t_all *vm, t_process *p)
{
	int p1;
	t_process new;

	if ((copy_process(p, &new)) == -1)
	{
		p->op_fail = 1;
		return ;
	}
	p1 = get_next_bytes(vm, p, 4, 0) % IDX_MOD;
	new.pc += p1 - 1;
	load_new_process(vm, &new);
	++vm->total_process;
	p->op_fail = 2;
}