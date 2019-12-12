/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:52:01 by adietric          #+#    #+#             */
/*   Updated: 2019/12/11 23:48:49 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int			do_op_aff(t_all *all, t_op *op, uint8_t *content)
{
	char		print;

	if (!(content[1]) || is_in(content[1], op_tab[15].ocp_value) != 1)
		return (0);
	else if (content[2] <= REG_NUMBER && content[2] > 0)
	{
		print = all->processes.r[content[2]] % 256;
		all->processes.carry = print == 0 ? 1 : 0;
		ft_putstr("(id = ");
		ft_putnbr(all->processes.id);
		ft_putstr(") affiche --> |");
		ft_putchar(print);
		ft_putstr("|\n");
		return (3);
	}
	return (0);
}

uint16_t		op_aff(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	(void)op;
	i = 0;
	if (all->check_mode != 1)
		i = do_op_aff(all, op, content);
	else if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[15].ocp_value) != 1)
			return (0);
		i = content[1] == 64 ? REG_SIZE + 2 : 0;
	}
	return (i);
}
