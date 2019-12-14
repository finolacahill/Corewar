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

<<<<<<< HEAD
int		is_reg(int reg, t_process *p)
{
    if (reg < 0 || reg > REG_NUMBER)
    {
		p->op_fail = 1;
=======
int		is_reg(int reg)
{
    if (reg < 0 || reg > REG_NUMBER)
    {
        ft_printf("Invalid register called -> KILLING THIS PROCESS");
>>>>>>> 391e4df2ad9e5026fe5116a9d76db956a9e9a1a4
        return (0);
    }
	return (1);
}

//can values return negative numbers?? Should we be exiting instead of sending -1??
int     get_reg_val(t_all *vm, t_process *p, int bytes_read)
{
    int reg;

    reg = get_next_bytes(vm, p, 1, bytes_read);
<<<<<<< HEAD
	is_reg(reg, p);
	if (p->op_fail == 1)
		return ;
=======
	if ((is_reg(reg)) == 0)
		return (-1);
>>>>>>> 391e4df2ad9e5026fe5116a9d76db956a9e9a1a4
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