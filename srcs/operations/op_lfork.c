/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:54:04 by adietric          #+#    #+#             */
/*   Updated: 2019/12/11 18:13:29 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int				do_op_lfork(t_all *all, t_op *op, uint8_t *content)
{
	return(0);
	
}

uint16_t		op_lfork(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	(void)op;
	(void)content;
	i = 0;
	if (all->check_mode != 1)
		i = do_op_lfork(all, op, content);
	else if (all->check_mode == 1)
		return (op_tab[14].dir_size + 1);
	return (i);
}
