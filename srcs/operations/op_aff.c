#include "../../includes/vm.h"

uint16_t		check_op_aff(t_all *all, uint8_t *content)
{
	int			i;

	i = 0;
	if (!(content[1]) || is_in(content[1], op_check_tab[15].ocp_value) != 1)
		return (0);
	i = content[1] == 64 ? 1 + 2 : 0;
	return (i);
}


void    op_aff(t_all *vm, t_process *p)
{
	int val;
	unsigned char c;

	val = get_reg_val(vm, p, 1);
	c = (unsigned char)(val % 256);
	if (p->op_fail != 1)
	{
		if (vm->flag_v == 4)
			ft_printf("\tP%6d | ", p->pid);
		ft_printf("Aff: %c", c);
		if (vm->flag_v == 4)
			ft_printf("(val %#02x)\n", (val % 256));
		else
			ft_putchar('\n');
	}	
}