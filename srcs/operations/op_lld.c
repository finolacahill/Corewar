/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:05:59 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 17:06:46 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

uint16_t		check_op_lld(uint8_t *content)
{
	int			i;

	i = 0;
	if (!(content[1]) || is_in(content[1], g_op_check_tab[12].ocp_value) != 1)
		return (0);
	i += content[1] == 144 ? g_op_check_tab[12].dir_size + 1 : 0;
	i += content[1] == 208 ? IND_SIZE + 1 : 0;
	i += 2;
	return (i);
}

void			op_lld(t_all *vm, t_process *p)
{
	long		pm1;
	long		bytes;
	long		address;

	bytes = 5;
	if (p->decode[0] == IND_CODE)
	{
		address = get_ind(vm, p, 1, 0);
		pm1 = get_next_bytes(vm, p, 2, address - 1);
		bytes = 3;
	}
	else
		pm1 = get_next_bytes(vm, p, 4, 1);
	pm1 = check_neg_address(pm1);
	load_val_in_reg(vm, p, pm1, bytes);
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | lld %ld\n", p->pid, pm1);
	if (p->op_fail == 1)
		return ;
	check_carry(p, pm1);
}
