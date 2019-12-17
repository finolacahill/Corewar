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
	;
}