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
		if (vm->flag_v == 4)
			ft_printf("\tP%6d | jumped to %d\n", p->pid, address % MEM_SIZE);
		p->pc = (p->pc + address - 1) % MEM_SIZE;
		if (p->pc < 0)
			p->pc = MEM_SIZE - p->pc;
	}
	else
	{
		if (vm->flag_v == 4)
			ft_printf("\tP%6d | zjmp %d FAILED at cycle%d\n", p->pid, address, vm->cycles);
/*		if (vm->cycles == 4952)
		{
			ft_printf("pc = %d\n", p->pc);
			ft_print_arena(vm, 64, 925);
			exit(1);
		}*/
		p->op_fail = 1;
	}
	
}