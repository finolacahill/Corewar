#include "../includes/vm.h"

int		get_next_bytes(t_all *vm, t_process *p, int len, int bytes_read)
{
	int		val;
	int		i;

	val = 0;
	i = 0;
	while (++i <= len)
	{
	//	printf("val b4 shift = %d\n", val);
		val <<= 8;
	//	printf("val after = %d\n", val);
		val += vm->arena[((p->pc + bytes_read + i) % MEM_SIZE)];
	//	printf("val added %d\n", val);
	}
	return (val);
}

int     get_reg_val(t_all *vm, t_process *p, int bytes_read)
{
    int reg;

    reg = get_next_bytes(vm, p, 1, bytes_read);
    if (reg < 0 || reg > REG_NUMBER)
    {
        ft_printf("Invalid register -> KILL THIS PROCESS");
        return (-1);
    }
    return (p->r[reg - 1]);
}

int     get_ind(t_all *vm, t_process *p, int bytes_read)
{
    return (get_next_bytes(vm, p, 2, bytes_read) % IDX_MOD);
}

int     get_dir_2(t_all *vm, t_process *p, int bytes_read)
{
    return (get_next_bytes(vm, p, 2, bytes_read) % IDX_MOD);
}