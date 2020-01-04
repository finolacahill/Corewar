#include "../includes/vm.h"

void		load_value(t_all *vm, int add, int len, int val)
{
	int i;
	int power;
	int shift;
	int address;

	i = 0;
	power = 2;
	shift = 0;
	while (++i <= len)
	{
		address = (add + len - i) % MEM_SIZE;
		if (address < 0)
			address = MEM_SIZE - address;
		vm->arena[address] = (val % (ft_puissance(16, power)) >> shift);
		val -= val % (ft_puissance(16, power));
		power +=2;
		shift += 8;
	}
}

//QUESTION. CAN Registers hold negatice values? Should we be exiting instead of return -1 for invalid reg??
void    load_val_in_reg(t_all *vm, t_process *p, int val, int bytes_read)
{
    int reg2;
    
    reg2 = get_next_bytes(vm, p, 1, bytes_read);
	if (reg2 < 1 || reg2 > 16)
	{
		p->op_fail = 1;
		return ;
	}
    p->r[reg2 - 1] = val;
	if (p->op == 10 && vm->flag_v == 3)
		ft_printf("\t \tload val %d in reg %d\n", val, reg2);
}
/*
//Question, will the value alwya have a len of 4????
void    load_val4_at_ind(t_all *vm, t_process *p, int val, int bytes_read)
{
    int ind;

    ind = (get_next_bytes(vm, p, 2, bytes_read) % MEM_SIZE) % IDX_MOD;
    load_value(vm, (((p->pc + ind) % MEM_SIZE) % IDX_MOD), 4, val); //GAH SHOULD WE IDX_MOD???
	printf("value loaded to %d\n", (((p->pc + ind) % MEM_SIZE) % IDX_MOD));
}*/