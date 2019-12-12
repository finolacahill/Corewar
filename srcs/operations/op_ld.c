/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:53:07 by adietric          #+#    #+#             */
/*   Updated: 2019/12/11 23:45:22 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int				do_op_ld(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (!(content[1]) || is_in(content[1], op_tab[1].ocp_value) != 1)
		return (0);
	if (content[1] == 144)								//DIRECT
	{
		if (content[6] <= REG_NUMBER && content[6] > 0) // REGISTRE VALIDE
		{
																					printf("Reg[%d] avant = %d\n", content[6], all->processes.r[content[6]]);
			all->processes.r[content[6]] = dasm_get_exec_code(&(content[2]), 4);	//Stocke dans le R les 4 bits du Direct
			if (all->processes.r[content[6]] == 0)
				all->processes.carry = 1;
																					printf("Reg[%d] apres = %d\n", content[6], all->processes.r[content[6]]);
		}
		return (6);
	}
	if (content[1] == 208)								//INDIRECT
	{
		if (content[4] <= REG_NUMBER && content[4] > 0) // REGISTRE VALIDE
		{
																					printf("Reg[%d] avant = %d\n", content[4], all->processes.r[content[4]]);
			all->processes.r[content[4]] = dasm_get_exec_code(&(content[2]), 2);	//Stocke dans le R les 4 bits du Direct
			if (all->processes.r[content[4]] == 0)
				all->processes.carry = 1;
																					printf("Reg[%d] apres = %d\n", content[4], all->processes.r[content[4]]);
		}
		return (4);	
	}
	return (0);

}

uint16_t		op_ld(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	(void)op;
	i = 0;
	if (all->check_mode != 1)
		i = do_op_ld(all, op, content);
	else if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[1].ocp_value) != 1)
			return (0);
		i += content[1] == 144 ? op_tab[1].dir_size + REG_SIZE : 0;
		i += content[1] == 208 ? IND_SIZE + REG_SIZE : 0;
		i += 2;
	}
	return (i);
}
