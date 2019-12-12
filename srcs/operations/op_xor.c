/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:57:43 by adietric          #+#    #+#             */
/*   Updated: 2019/12/11 18:15:19 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int			do_op_xor(t_all *all, t_op *op, uint8_t *content)
{
	return(0);

}

uint16_t		op_xor(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	(void)op;
	if (all->check_mode != 1)
		i = do_op_xor(all, op, content);
	else if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[7].ocp_value) != 1)
			return (0);
		i += content[1] == 84 ? 3 * REG_SIZE : 0;
		i += content[1] == 100 ? 2 * REG_SIZE + op_tab[7].dir_size : 0;
		i += content[1] == 116 ? 2 * REG_SIZE + IND_SIZE : 0;
		i += content[1] == 148 ? 2 * REG_SIZE + op_tab[7].dir_size : 0;
		i += content[1] == 164 ? REG_SIZE + 2 * op_tab[7].dir_size : 0;
		i += content[1] == 180 ? REG_SIZE + IND_SIZE + op_tab[7].dir_size : 0;
		i += content[1] == 212 ? 2 * REG_SIZE + IND_SIZE : 0;
		i += content[1] == 228 ? REG_SIZE + IND_SIZE + op_tab[7].dir_size : 0;
		i += content[1] == 244 ? 2 * IND_SIZE + REG_SIZE : 0;
		i += 2;
	}
	return (i);
}
