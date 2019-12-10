#include "../includes/vm.h"

void			get_next_bytes(t_all *vm, t_process *p, int *value, int len)
{
	int		i;
    int     result;

    i = 0;
    result = 0;
	while (++i <= len)
	{
		result <<= 8;
		result += vm->arena[p->pc + i];
	}
	*value = result;
}