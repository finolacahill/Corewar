#include "../../includes/vm.h"

uint16_t	check_op_sub(t_all *all, uint8_t *content)
{
	int			i;

	i = 0;
	if (!(content[1]) || is_in(content[1], op_check_tab[4].ocp_value) != 1)
		return (0);
	i = content[1] == 84 ? 3 * 1 + 2: 0;
	return (i);
}

void    op_sub(t_all *vm, t_process *p)
{
	int p1;
	int p2;

	p1 = get_reg_val(vm, p, 1);
	p2 = get_reg_val(vm, p, 2);
	if (vm->flag_v == 3)
		ft_printf("\t\t%d | sub \n", p->pid);

	if (p->op_fail == 1)
		return ;
	load_val_in_reg(vm, p, p1 - p2, 3);
	if (p->op_fail != 1)
		check_carry(p, p1 - p2);
}