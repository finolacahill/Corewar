/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:06:55 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 17:07:41 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

uint16_t		check_op_lldi(uint8_t *content)
{
	int			i;

	(void)content;
	i = 0;
	if (!(content[1]) || is_in(content[1], g_op_check_tab[13].ocp_value) != 1)
		return (0);
	i += content[1] == 84 ? 3 * 1 : 0;
	i += content[1] == 100 ? 2 * 1 + g_op_check_tab[13].dir_size : 0;
	i += content[1] == 148 ? 2 * 1 + g_op_check_tab[13].dir_size : 0;
	i += content[1] == 164 ? 1 + 2 * g_op_check_tab[13].dir_size : 0;
	i += content[1] == 212 ? 2 * 1 + IND_SIZE : 0;
	i += content[1] == 228 ? 1 + IND_SIZE + g_op_check_tab[13].dir_size : 0;
	i += 2;
	return (i);
}

void			op_lldi(t_all *vm, t_process *p)
{
	long		address1;
	long		address2;
	long		val;
	long		bytes_read;

	bytes_read = 1;
	if (p->decode[0] == IND_CODE)
	{
		address1 = get_val_at_ind(vm, p, bytes_read, 0);
		bytes_read += 2;
	}
	else
	{
		address1 = get_unspecified_val_2(vm, p, &bytes_read, 0);
	}
	address2 = get_unspecified_val_2(vm, p, &bytes_read, 1);
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | lldi from %d + %d (with mod and pc %d)\n",
		p->pid, address1, address2, address1 + address2 + p->pc);
	address1 += address2;
	val = get_next_bytes(vm, p, 4, p->pc + address1 - 1);
	if (p->op_fail == 1)
		return ;
	load_val_in_reg(vm, p, val, bytes_read);
	check_carry(p, val);
}
