#include "../../includes/vm.h"

uint16_t		check_op_lld(t_all *all, uint8_t *content)
{
	int			i;

	i = 0;
	if (!(content[1]) || is_in(content[1], op_check_tab[12].ocp_value) != 1)
		return (0);
	i += content[1] == 144 ? op_check_tab[12].dir_size + 1 : 0;
	i += content[1] == 208 ? IND_SIZE + 1 : 0;
	i += 2;
	return (i);
}


void    op_lld(t_all *vm, t_process *p)
{
	int pm1;
	int bytes_read;

	bytes_read = 5;
	if (p->decode[0] == IND_CODE)
	{
		pm1 = get_val_at_ind(vm, p, 1, 0);
		bytes_read = 3;
	}
	else
		pm1 = get_next_bytes(vm, p, 4, 1);
	load_val_in_reg(vm, p, pm1, bytes_read);
	if (p->op_fail == 1)
		return ;
	check_carry(p, pm1);
}