#include "../includes/vm.h"

uint16_t		check_op_lld(t_all *all, uint8_t *content)
{
	int			i;

	i = 0;
	if (!(content[1]) || is_in(content[1], op_check_tab[12].ocp_value) != 1)
		return (0);
	i += content[1] == 144 ? op_check_tab[12].dir_size + REG_SIZE : 0;
	i += content[1] == 208 ? IND_SIZE + REG_SIZE : 0;
	i += 2;
	return (i);
}


void    op_lld(t_all *vm, t_process *p)
{
	;
}