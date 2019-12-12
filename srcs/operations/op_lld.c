/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:54:47 by adietric          #+#    #+#             */
/*   Updated: 2019/12/11 18:13:51 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int				do_op_lld(t_all *all, t_op *op, uint8_t *content)
{
	return(0);
	
}

uint16_t		op_lld(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	(void)op;
	i = 0;
	if (all->check_mode != 1)
		i = do_op_lld(all, op, content);
	else if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[12].ocp_value) != 1)
			return (0);

		i += content[1] == 144 ? op_tab[12].dir_size + REG_SIZE : 0;
		i += content[1] == 208 ? IND_SIZE + REG_SIZE : 0;
		i += 2;
	}
	return (i);
}
