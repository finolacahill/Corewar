/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:26:40 by adietric          #+#    #+#             */
/*   Updated: 2020/01/07 09:27:59 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

uint16_t		check_op_xor(uint8_t *content)
{
	int			i;

	i = 0;
	if (!(content[1]) || is_in(content[1], g_op_check_tab[7].ocp_value) != 1)
		return (0);
	i += content[1] == 84 ? 3 * 1 : 0;
	i += content[1] == 100 ? 2 * 1 + g_op_check_tab[7].dir_size : 0;
	i += content[1] == 116 ? 2 * 1 + IND_SIZE : 0;
	i += content[1] == 148 ? 2 * 1 + g_op_check_tab[7].dir_size : 0;
	i += content[1] == 164 ? 1 + 2 * g_op_check_tab[7].dir_size : 0;
	i += content[1] == 180 ? 1 + IND_SIZE + g_op_check_tab[7].dir_size : 0;
	i += content[1] == 212 ? 2 * 1 + IND_SIZE : 0;
	i += content[1] == 228 ? 1 + IND_SIZE + g_op_check_tab[7].dir_size : 0;
	i += content[1] == 244 ? 2 * IND_SIZE + 1 : 0;
	i += 2;
	return (i);
}

void			op_xor(t_all *vm, t_process *p)
{
	long		pm1;
	long		pm2;
	long		bytes_read;

	bytes_read = 1;
	pm1 = get_unspecified_val(vm, p, &bytes_read, 0);
	pm2 = get_unspecified_val(vm, p, &bytes_read, 1);
/*	if (p->decode[0] != REG_CODE && (pm1 % 65536) >= 32768)
		pm1 += 65536;
	if (p->decode[1] != REG_CODE && (pm2 % 65536) >= 32768)
		pm2 += 65536;*/
	if (vm->flag_v == 4)
		ft_printf("\tP%6d | xor R%d/pm1 %d R%d/pm2 %d R%d at cycles %d\n",
		p->pid, get_next_bytes(vm, p, 1, 1), pm1,
		get_next_bytes(vm, p, 1, 2), pm2,
		get_next_bytes(vm, p, 1, bytes_read), vm->cycles);
	if (p->op_fail == 1)
		return ;
	load_val_in_reg(vm, p, pm1 ^ pm2, bytes_read);
	if (p->op_fail != 1)
		check_carry(p, pm1 ^ pm2);
}
