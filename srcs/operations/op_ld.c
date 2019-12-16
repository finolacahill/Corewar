#include "../../includes/vm.h"

uint16_t		check_op_ld(t_all *all, uint8_t *content)
{
	int			i;

	i = 0;
	if (!(content[1]) || is_in(content[1], op_check_tab[1].ocp_value) != 1)
		return (0);
	i += content[1] == 144 ? op_check_tab[1].dir_size + 1 : 0;
	i += content[1] == 208 ? IND_SIZE + 1 : 0;
	i += 2;
	return (i);
}


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
		pm1 = get_next_bytes(vm, p, 2, 1) % IDX_MOD;
		pm1 = get_next_bytes(vm, p, 2, pm1 + 1); //should the len be 4??
		bytes_read = 3;
	}
	else
		pm1 = get_next_bytes(vm, p, 4, 1);
	load_val_in_reg(vm, p, pm1, bytes_read);
	check_carry(p, pm1);
}
