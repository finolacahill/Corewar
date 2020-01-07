/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:12:38 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 17:17:23 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

uint16_t		check_op_sti(uint8_t *content)
{
	int			i;

	i = 0;
	if (!(content[1]) || is_in(content[1], g_op_check_tab[10].ocp_value) != 1)
		return (0);
	i += content[1] == 84 ? 3 * 1 : 0;
	i += content[1] == 88 ? 2 * 1 + g_op_check_tab[10].dir_size : 0;
	i += content[1] == 100 ? 2 * 1 + g_op_check_tab[10].dir_size : 0;
	i += content[1] == 104 ? 1 + 2 * g_op_check_tab[10].dir_size : 0;
	i += content[1] == 116 ? 2 * 1 + IND_SIZE : 0;
	i += content[1] == 120 ? 1 + IND_SIZE + g_op_check_tab[10].dir_size : 0;
	i += 2;
	return (i);
}

void			op_sti(t_all *vm, t_process *p)
{
	int			p1;
	int			p2;
	int			p3;
	int			bytes_read;

	bytes_read = 2;
	p1 = get_reg_val(vm, p, 1);
	p2 = get_unspecified_val_2(vm, p, &bytes_read, 1);
	p3 = get_unspecified_val_2(vm, p, &bytes_read, 2);
	if (vm->flag_v == 4)
	{
		ft_printf("\n\tP%6d | sti reg %d", p->pid, get_next_bytes(vm, p, 1, 1));
		ft_printf(" val %d to %d + %d with ", p1, p2, p3);
		ft_printf("mod %d (with pc ", (p2 + p3) % IDX_MOD);
		ft_printf("%d) at cycle %d\n",
		((p2 + p3) + p->pc) % MEM_SIZE, vm->cycles);
	}
	if (p->op_fail == 1)
		return ;
	load_value(vm, (p->pc + ((p2 + p3) % IDX_MOD)), 4, p1);
}
