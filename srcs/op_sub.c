#include "../includes/vm.h"

void    op_sub(t_all *vm, t_process *p)
{
	int p1;
	int p2;
	int p3;

	p1 = get_reg_val(vm, p, 1);
	p2 = get_reg_val(vm, p, 2);
	if (p->op_fail == 1)
		return ;
	load_val_in_reg(vm, p, p1 - p2, 3);
	printf("p1 -p2 = %d\n", p1 -p2);
	if (p->op_fail != 1)
		check_carry(p, p1 - p2);
}