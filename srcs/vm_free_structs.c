#include "../includes/vm.h"

void    free_process(t_all *vm, t_process *p)
{
	if (p != NULL && vm->total_process > 0)
	{	
		if (p->decode != NULL)
			free(p->decode);
		p->decode = NULL;
		free(p);
		--vm->total_process;
		p = NULL;
	}
}

void	free_vm(t_all *vm)
{
//	printf("\n\t\tHEREEEE\n\n");
//	if (vm->arena != NULL)
//		ft_memdel((void **)&vm->arena);
	vm->arena = NULL;
	dasm_free(vm);
	vm = NULL;
}

int		free_all(t_all *vm, t_process *p)
{
	free_process(vm, p);
	free_vm(vm);
	return (0);
}

void	free_op_table(t_op *op)
{
	int i;

	i = -1;
	while (++i < 16)
	{
		free(op[i].op_name);
	//	free(op[i].inst);
	}
	free(op);

}