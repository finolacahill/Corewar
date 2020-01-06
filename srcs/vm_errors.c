#include "../includes/vm.h"

t_process	*error_process(t_process *p)
{
	p->start = -1;
	return (p);
}

void	error_arena(t_all *vm, t_process *p)
{
	ft_printf("Malloc error init_arena.\n");
	free_all(vm, p);
	exit(1);
}

int			error_run_vm(t_all *vm, t_op *op_table)
{
	if (op_table != NULL)
		free_op_table(op_table);
	ft_printf("Malloc error run_vm.\n");
	return (-1);
}