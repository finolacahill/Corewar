#include "../includes/vm.h"

t_process	*error_process(t_process *p)
{
	p->start = -1;
	return (p);
}

int			error_arena(t_all *vm, t_process *p)
{
	ft_printf("Error initialising arena.\n");
	free_all(vm, p);
	return (0);
}

int			error_run_vm(t_all *vm, t_process *p, t_op *op_table)
{
	if (op_table != NULL)
		free_op_table(op_table);
	ft_printf("Malloc error run_vm.\n");
	return (-1);
}