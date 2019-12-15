#include "../includes/vm.h"

/*
** pm1 is a indirect or a D4, pm2 is a reg. Stocks param 1 in param 2
** modifies the carry. 
*/
void    op_ld(t_all *vm, t_process *p)
{
	int     pm1;
	int     pm2;
	int     bytes_read;

	bytes_read = 5;

	if (p->decode[0] == IND_CODE)
	{
		pm1 = get_ind(vm, p, 1);
		pm1 = get_next_bytes(vm, p, 4, pm1 - 1);
		bytes_read = 3;
	}
	else
		pm1 = get_next_bytes(vm, p, 4, 1);
	load_val_in_reg(vm, p, pm1, bytes_read);
	if (p->op_fail == 1)
		return ;
	check_carry(p, pm1);
}
