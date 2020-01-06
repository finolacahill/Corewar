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

void	free_all_process(t_all *vm, t_process *p)
{
	t_process *tmp;
	tmp = p;
	while (p != NULL)
	{
		tmp = p;
		p = p->next;
		free_process(vm, tmp);
	}
}

void	free_vm(t_all *vm)
{
//	printf("\n\t\tHEREEEE\n\n");
	if (vm->arena != NULL)
		ft_memdel((void **)&vm->arena);
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
		ft_strdel(&(op[i].op_name));
	//	free(op[i].inst);
	}
	free(op);
}

void	free_dasm_header(t_all *all,  uint8_t *cor_content, char *s)
{
	ft_printf("here\n\n");
	free(cor_content);
	error(all, s);
}