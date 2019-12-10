/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:48:34 by adietric          #+#    #+#             */
/*   Updated: 2019/12/10 02:40:09 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

uint16_t	vm_check_exec(t_all *all, t_champs *champs, uint8_t *cont, t_op *op)
{
	uint16_t	i;

	i = 0;
	if (cont[0] > 16 || cont[0] < 1)
		error_exec(all, (char*)champs->name, i);
	i = op[cont[0] - 1].inst(all, op, cont);
	i == 0 ? error_exec(all, (char*)champs->name, i) : 0;
																						// printf(" 		I = %hu\n", i);
	return (i);
}