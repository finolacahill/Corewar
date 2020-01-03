#include "../../includes/vm.h"

uint16_t		check_op_sti(t_all *all, uint8_t *content)
{
	int			i;

	i = 0;
	if (!(content[1]) || is_in(content[1], op_check_tab[10].ocp_value) != 1)
		return (0);
	i += content[1] == 84 ? 3 * 1 : 0;
	i += content[1] == 88 ? 2 * 1 + op_check_tab[10].dir_size : 0;
	i += content[1] == 100 ? 2 * 1 + op_check_tab[10].dir_size : 0;
	i += content[1] == 104 ? 1 + 2 * op_check_tab[10].dir_size : 0;
	i += content[1] == 116 ? 2 * 1 + IND_SIZE : 0;
	i += content[1] == 120 ? 1 + IND_SIZE + op_check_tab[10].dir_size : 0;
	i += 2;
	return (i);
}
//last param is a reg or a direct!!
void    op_sti(t_all *vm, t_process *p)
{
	int p1;
	int p2;
	int p3;
	int bytes_read;

	bytes_read = 2;
	p1 = get_reg_val(vm, p, 1);
	p2 = get_unspecified_val_2(vm, p, &bytes_read, 1);
	p3 = get_unspecified_val_2(vm,p, &bytes_read, 2);
//	ft_printf("reg = %d, p1 = %d/%02x, p2 = %d/%02x\n", p1, p2, p2, p3, p3);
	if (vm->flag_v == 3)
		ft_printf("\n\tP%6d | sti reg %d val %d to %d + %d with mod %d (with pc %d) at cycle %d\n",  p->pid, get_next_bytes(vm, p, 1, 1), p1, p2, p3, (p2 + p3) % IDX_MOD, ((p2 + p3) + p->pc) % MEM_SIZE, vm->cycles);
	if (p->op_fail == 1)
		return ;
//	ft_print_arena(vm, 64, p->pc);
	load_value(vm, (p->pc + ((p2 + p3) % IDX_MOD)) , 4, p1);
//	ft_print_arena(vm, 64, p->pc, p->pc + ((p2 + p3) % IDX_MOD));
//	ft_printf("\n_________________________________________\n");

}