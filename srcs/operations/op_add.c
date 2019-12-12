/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:50:47 by adietric          #+#    #+#             */
/*   Updated: 2019/12/11 18:13:00 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int			do_op_add(t_all *all, t_op *op, uint8_t *content)
{
	return(0);
}

uint16_t		op_add(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	(void)op;
	i = 0;
	if (all->check_mode != 1)
		i = do_op_add(all, op, content);
	else if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[3].ocp_value) != 1)
			return (0);
		i = content[1] == 84 ? 3 * REG_SIZE + 2 : 0;
	}
	return (i);
}