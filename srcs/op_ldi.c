#include "../includes/vm.h"

uint16_t		check_op_ldi(t_all *all, uint8_t *content)
{
	int			i;

	i = 0;
	if (!(content[1]) || is_in(content[1], op_check_tab[9].ocp_value) != 1)
		return (0);
	i += content[1] == 84 ? 3 * 1 : 0;
	i += content[1] == 100 ? 2 * 1 + op_check_tab[9].dir_size : 0;
	i += content[1] == 148 ? 2 * 1 + op_check_tab[9].dir_size : 0;
	i += content[1] == 164 ? 1 + 2 * op_check_tab[9].dir_size : 0;
	i += content[1] == 212 ? 2 * 1 + IND_SIZE : 0;
	i += content[1] == 228 ? 1 + IND_SIZE + op_check_tab[9].dir_size : 0;
	i += 2;
	return (i);
}

void    op_ldi(t_all *vm, t_process *p)
{
	;
}