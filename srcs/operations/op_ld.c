/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:58:09 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 16:59:01 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

uint16_t	check_op_ld(uint8_t *content)
{
	int		i;

	i = 0;
	if (!(content[1]) || is_in(content[1], g_op_check_tab[1].ocp_value) != 1)
		return (0);
	i += content[1] == 144 ? g_op_check_tab[1].dir_size + 1 : 0;
	i += content[1] == 208 ? IND_SIZE + 1 : 0;
	i += 2;
	return (i);
}

void		op_ld(t_all *vm, t_process *p)
{
	int		pm1;
	int		bytes_read;

	bytes_read = 1;
	pm1 = get_unspecified_val(vm, p, &bytes_read, 0);
	load_val_in_reg(vm, p, pm1, bytes_read);
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | load %d R%d at cycle %d\n", p->pid, pm1,
		get_next_bytes(vm, p, 1, bytes_read), vm->cycles);
	if (p->op_fail == 1)
		return ;
	check_carry(p, pm1);
}
