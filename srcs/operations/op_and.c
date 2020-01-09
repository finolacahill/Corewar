/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:53:15 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 16:54:10 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

uint16_t		check_op_and(uint8_t *content)
{
	int			i;

	i = 0;
	if (!(content[1]) || is_in(content[1], g_op_check_tab[5].ocp_value) != 1)
		return (0);
	i += content[1] == 84 ? 3 * 1 : 0;
	i += content[1] == 100 ? 2 * 1 + g_op_check_tab[5].dir_size : 0;
	i += content[1] == 116 ? 2 * 1 + IND_SIZE : 0;
	i += content[1] == 148 ? 2 * 1 + g_op_check_tab[5].dir_size : 0;
	i += content[1] == 164 ? 1 + 2 * g_op_check_tab[5].dir_size : 0;
	i += content[1] == 180 ? 1 + IND_SIZE + g_op_check_tab[5].dir_size : 0;
	i += content[1] == 212 ? 2 * 1 + IND_SIZE : 0;
	i += content[1] == 228 ? 1 + IND_SIZE + g_op_check_tab[5].dir_size : 0;
	i += content[1] == 244 ? 2 * IND_SIZE + 1 : 0;
	i += 2;
	return (i);
}

void			op_and(t_all *vm, t_process *p)
{
	long			pm1;
	long			pm2;
	long			bytes_read;

	bytes_read = 1;
	pm1 = get_unspecified_val(vm, p, &bytes_read, 0);
	pm2 = get_unspecified_val(vm, p, &bytes_read, 1);
	ft_printf("HEREEEEE");
	if (p->op_fail == 1)
	{
		ft_printf("bytes = %d\n", bytes_read);
		p->pc += bytes_read;
		return ;
	}
	load_val_in_reg(vm, p, pm1 & pm2, bytes_read);
	if (p->op_fail != 1)
	{
		ft_printf("2bytes = %d\n", bytes_read);
		check_carry(p, pm1 & pm2);
		if (vm->flag_v == 4)
			ft_printf("\tP%6d | and %ld, %ld, R%d\n",
			p->pid, pm1, pm2, get_next_bytes(vm, p, 1, bytes_read));
	}
	else
	{
		ft_printf("3bytes = %d\n", bytes_read);
		p->pc += bytes_read;
	}
	
}
