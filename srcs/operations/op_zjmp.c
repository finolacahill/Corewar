/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:58:01 by adietric          #+#    #+#             */
/*   Updated: 2019/12/12 00:01:05 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int			do_op_zjmp(t_all *all, t_op *op, uint8_t *content)
{
	return(0);
}

uint16_t		op_zjmp(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	(void)op;
	(void)content;
	i = 0;
	if (all->check_mode != 1)
		i = do_op_zjmp(all, op, content);
	else if (all->check_mode == 1)
		return (op_tab[8].dir_size + 1);
	return (i);
}
