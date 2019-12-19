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
//	ft_printf("\tcarry is now %d\n", p->carry);
}

int		get_next_bytes(t_all *vm, t_process *p, int len, int bytes_read)
{
	int		val;
	int		i;

	val = 0;
	i = 0;
	while (++i <= len)
	{
		// printf("val b4 shift = %d\n", val);
		val <<= 8;
		// printf("val after = %d\n", val);
		val += vm->arena[((p->pc + bytes_read + i)) % MEM_SIZE];
		// printf("val added %d\n", val);
	}
	return (val);
}