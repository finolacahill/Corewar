#include "../includes/vm.h"

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

int		is_reg(int reg, t_process *p)
{
    if (reg < 1 || reg > REG_NUMBER)
    {
		p->op_fail = 1;
        return (0);
    }
	return (1);
}

//can values return negative numbers?? Should we be exiting instead of sending -1??
int     get_reg_val(t_all *vm, t_process *p, int bytes_read)
{
    int reg;

    reg = get_next_bytes(vm, p, 1, bytes_read);
	is_reg(reg, p);
	if (p->op_fail == 1)
		return (-1);
//	printf("reg %d = %d\n", reg, p->r[reg - 1]);
    return (p->r[reg - 1]);
}

int     get_ind(t_all *vm, t_process *p, int bytes_read)
{
    return (get_next_bytes(vm, p, 2, bytes_read) % IDX_MOD);
}

int		get_val_at_ind(t_all *vm, t_process *p, int bytes_read)
{
	int address;

	address = get_next_bytes(vm, p, 2, bytes_read);
	return (get_next_bytes(vm, p, 4, address - 1));
}

int		get_unspecified_val(t_all *vm, t_process *p, int *bytes_read, int param)
{
	int val; 

	if (p->decode[param] == REG_CODE)
     {
        val = get_reg_val(vm, p, bytes_read[0]);
        bytes_read[0] += 1;
     }
    if (p->decode[param] == IND_CODE)
    {
          val = get_val_at_ind(vm, p, bytes_read[0]);
          bytes_read[0] += 2;
    }
    if (p->decode[param] == DIR_CODE)
    {
		val = get_next_bytes(vm, p, 4, bytes_read[0]);
		bytes_read[0] += 4;
	}
	return (val);
}

int		get_unspecified_val_2(t_all *vm, t_process *p, int *bytes_read, int param)
{
	int val; 

	if (p->decode[param] == REG_CODE)
     {
        val = get_reg_val(vm, p, bytes_read[0]);
		printf("\treg = %d\n", val);
        bytes_read[0] += 1;
     }
    if (p->decode[param] == IND_CODE)
    {
          val = get_val_at_ind(vm, p, bytes_read[0]);
		  printf("\tind = %d\n", val);
          bytes_read[0] += 2;
    }
    if (p->decode[param] == DIR_CODE)
    {
		val = get_next_bytes(vm, p, 2, bytes_read[0]);
		printf("\tdir2= %d\n", val);
		bytes_read[0] += 2;
	}
	return (val);
}