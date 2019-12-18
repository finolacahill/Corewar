#include "../includes/vm.h"

void		load_value(t_all *vm, int address, int len, int val)
{
	int i;
	int power;
	int shift;

	i = 0;
	power = 2;
	shift = 0;
	while (++i <= len)
	{
		vm->arena[(address + len - i) % MEM_SIZE] = (val % (ft_puissance(16, power)) >> shift);
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
    if ((is_reg(reg2, p)) == 0)
        return ;
    p->r[reg2 - 1] = val;
	ft_printf("\t \tload val %d in reg %d\n", val, reg2);
}

//Question, will the value alwya have a len of 4????
void    load_val4_at_ind(t_all *vm, t_process *p, int val, int bytes_read)
{
    int ind;

    ind = (get_next_bytes(vm, p, 2, bytes_read) % MEM_SIZE) % IDX_MOD;
    load_value(vm, (((p->pc + ind) % MEM_SIZE) % IDX_MOD), 4, val); //GAH SHOULD WE IDX_MOD???
	printf("value loaded to %d\n", (((p->pc + ind) % MEM_SIZE) % IDX_MOD));
}