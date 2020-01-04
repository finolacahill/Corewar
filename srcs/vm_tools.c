#include "../includes/vm.h"

void    check_carry(t_process *p, int param)
{
	if (p != NULL ) //kill flag?
	{
		if (param == 0)
			p->carry = 1;
		else
			p->carry = 0;
	}
//	if (p->pid == 8)
//		ft_printf("\tcarry is now %d\n", p->carry);
}

int		get_next_bytes(t_all *vm, t_process *p, int len, int bytes_read)
{
	int		val;
	int		i;
	int 	address;

	val = 0;
	i = 0;
	while (++i <= len)
	{
	//	 printf("val b4 shift = %d", val);
		val <<= 8;
	//	 printf("val after = %d", val);
		address = (p->pc + bytes_read + i) % MEM_SIZE;
		if (address < 0)
			address = MEM_SIZE - address;
		val += vm->arena[address];
	//	 printf("val added %d\n", val);
	}
	if ((val % 65536) >= 32768)
		val -= 65536;
	return (val);
}