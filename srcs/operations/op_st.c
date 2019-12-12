/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:56:05 by adietric          #+#    #+#             */
/*   Updated: 2019/12/12 15:21:59 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int				do_op_st(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (!(content[1]) || is_in(content[1], op_tab[2].ocp_value) != 1)
		return (0);
	if (content[1] == 80)
	{
		if (content[2] <= REG_NUMBER && content[2] > 0
			&& content[3] <= REG_NUMBER && content[3] > 0)
		{
			all->processes.r[content[3]] = all->processes.r[content[2]];
			all->processes.carry = all->processes.r[content[2]] == 0 ? 1 : 0;
			return (4);
		}
	}
	else if (content[1] == 112)
	{
		if (content[2] <= REG_NUMBER && content[2] > 0)
		{
			// copy_arena(&(all->arena[dasm_get_exec_code(&(content[3]), 2)]), all->processes.r[content[2]], 4);  C"EST NUL ! 
			// Il faut copier la value du registre à la position pointee par INDIRECT !!
			all->processes.carry = all->processes.r[content[2]] == 0 ? 1 : 0;
			return (5);
		}
	}
	return (0);
}

uint16_t		op_st(t_all *all, t_op *op, uint8_t *content)
{
	int			i;
	(void)op;
	(void)content;
	i = 0;
	if (all->check_mode != 1)
		i = do_op_st(all, op, content);
	else if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[2].ocp_value) != 1)
			return (0);
		i += content[1] == 80 ? 2 * REG_SIZE : 0;
		i += content[1] == 112 ? REG_SIZE + IND_SIZE : 0;
		i += 2;
	}
	return (i);
}
