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

	address = get_next_bytes(vm, p, 2, 0);
//	ft_printf("CARRY JUMP = %d\n", p->carry);
	if (p->carry == 1)
	{
	//	(vm, 64, p->pc);
		
//		ft_printf("address = %02x ", address);
//		ft_printf("old pc = %d\n", p->pc);
		if (vm->flag_v == 3)
			ft_printf("\t\t%d | jumped to %d\n", p->pid, address % MEM_SIZE);
		p->pc = (p->pc + address - 1) % MEM_SIZE;
	}
	else
	{
		if (vm->flag_v == 3)
			ft_printf("\t\t%d | zjmp %d FAILED\n", p->pid, address);
		p->op_fail = 1;
	}
	
}