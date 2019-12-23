#include "../../includes/vm.h"

uint16_t		check_op_zjmp(t_all *all, uint8_t *content)
{
	(void)content;
	return (op_check_tab[8].dir_size + 1);
}

//if carry is one, modifies the pc
void    op_zjmp(t_all *vm, t_process *p)
{
	int address;
//	ft_printf("CARRY JUMP = %d\n", p->carry);
	if (p->carry == 1)
	{
	//	(vm, 64, p->pc);
		address = get_next_bytes(vm, p, 2, 0);
//		ft_printf("address = %02x ", address);
//		ft_printf("old pc = %d\n", p->pc);
		p->pc = (p->pc + address - 1) % MEM_SIZE;
//		ft_printf("\t\t jumped to %d\n", p->pc + 1);
	}
	else
	{
		ft_printf("\t\t zjmp FAILED\n");
		p->op_fail = 1;
	}
	
}