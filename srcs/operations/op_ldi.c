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
	int address1;
	int address2;
	int val;
	int bytes_read;

	bytes_read = 1;
	address1 = get_unspecified_val_2(vm, p, &bytes_read, 0);
	address2 = get_unspecified_val_2(vm, p, &bytes_read, 1);
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | ldi from %d + %d (with mod and pc %d\n", p->pid, address1, address2, ((address1 + address2) % IDX_MOD) + p->pc);
	address1 = (address1 + address2) % IDX_MOD;
//	ft_print_arena(vm, 64, p->pc, p->pc + address1);
	val = get_next_bytes(vm, p, 4, address1 - 1);
	if (p->op_fail == 1)
		return ;
	load_val_in_reg(vm, p, val, bytes_read);
	/*if (val = -1879048192)
	{
		ft_printf("cycle = %d\n", vm->cycles);
		ft_print_arena(vm, 64, address1);
		exit(1);
	}*/
}