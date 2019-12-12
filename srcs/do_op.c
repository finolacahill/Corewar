/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:27:26 by adietric          #+#    #+#             */
/*   Updated: 2019/12/10 15:32:27 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	do_op(t_all *all, t_op *op, char *name_op, uint8_t *cont)
{
	int		i;

	i = -1;
	while (ft_strcmp(op[i].op_name, name_op) != 0)
		i++;
	op[i].inst(all, op, cont);
}