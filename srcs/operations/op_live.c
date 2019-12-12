/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:54:26 by adietric          #+#    #+#             */
/*   Updated: 2019/12/11 18:13:35 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int				do_op_live(t_all *all, t_op *op, uint8_t *content)
{
	return(0);
	
}

uint16_t		op_live(t_all *all, t_op *op, uint8_t *content)
{	
	int		i;

	(void)op;
	(void)content;
	i = 0;
	if (all->check_mode != 1)
		i = do_op_live(all, op, content);
	else if (all->check_mode == 1)
		return (op_tab[0].dir_size + 1);
	return (i);
}
