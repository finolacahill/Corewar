/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:52:32 by adietric          #+#    #+#             */
/*   Updated: 2020/01/10 11:54:27 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				op_aff(t_all *vm, t_process *p)
{
	int				val;
	unsigned char	c;

	val = get_reg_val(vm, p, 1);
	c = (unsigned char)(val % 256);
	if (p->op_fail != 1)
	{
		if (vm->flag_v == 4)
			ft_printf("\tP%6d | ", p->pid);
		ft_printf("Aff: %c", c);
		if (vm->flag_v == 4)
			ft_printf("(val %#02x) at cycle %d.\n", (val % 256), vm->cycles);
		else
			ft_putchar('\n');
	}
}
