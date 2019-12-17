#include "../../includes/vm.h"

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


/* p1 = reg/dir/ind p2 = reg/dir p3 = regg
// INACURATE IN ChEAtsheAT, PM2 DOES NOT TAKE IND, only dir or reg
*/
void    op_ldi(t_all *vm, t_process *p)
{
	int address;
	int val;
	int bytes_read;

	bytes_read = 1;
	address = get_unspecified_val_2(vm, p, &bytes_read, 0);
	address = (address + get_unspecified_val_2(vm, p, &bytes_read, 1)) % IDX_MOD;
	val = get_next_bytes(vm, p, 4, address - 1);
	if (p->op_fail == 1)
		return ;
	load_val_in_reg(vm, p, val, bytes_read);
}