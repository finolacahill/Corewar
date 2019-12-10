/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:44:36 by adietric          #+#    #+#             */
/*   Updated: 2019/12/10 11:32:18 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

uint16_t		op_add(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[3].ocp_value) != 1)
			return (0);
		i = content[1] == 84 ? 3 * REG_SIZE + 2 : 0;
	}
	return (i);
}

uint16_t		op_aff(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[15].ocp_value) != 1)
			return (0);
		i = content[1] == 64 ? REG_SIZE + 2 : 0;
	}
	return (i);
}

uint16_t		op_and(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[5].ocp_value) != 1)
			return (0);
		i += content[1] == 84 ? 3 * REG_SIZE : 0;
		i += content[1] == 100 ? 2 * REG_SIZE + op_tab[5].dir_size : 0;
		i += content[1] == 116 ? 2 * REG_SIZE + IND_SIZE : 0;
		i += content[1] == 148 ? 2 * REG_SIZE + op_tab[5].dir_size : 0;
		i += content[1] == 164 ? REG_SIZE + 2 * op_tab[5].dir_size : 0;
		i += content[1] == 180 ? REG_SIZE + IND_SIZE + op_tab[5].dir_size : 0;
		i += content[1] == 212 ? 2 * REG_SIZE + IND_SIZE : 0;
		i += content[1] == 228 ? REG_SIZE + IND_SIZE + op_tab[5].dir_size : 0;
		i += content[1] == 244 ? 2 * IND_SIZE + REG_SIZE : 0;
		i += 2;
	}
	return (i);
}

uint16_t		op_fork(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (all->check_mode == 1)
		return (op_tab[11].dir_size + 1);
	return (i);
}

uint16_t		op_ld(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[1].ocp_value) != 1)
			return (0);
		i += content[1] == 144 ? op_tab[1].dir_size + REG_SIZE : 0;
		i += content[1] == 208 ? IND_SIZE + REG_SIZE : 0;
		i += 2;
	}
	return (i);
}

uint16_t		op_ldi(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[9].ocp_value) != 1)
			return (0);
		i += content[1] == 84 ? 3 * REG_SIZE : 0;
		i += content[1] == 100 ? 2 * REG_SIZE + op_tab[9].dir_size : 0;
		i += content[1] == 148 ? 2 * REG_SIZE + op_tab[9].dir_size : 0;
		i += content[1] == 164 ? REG_SIZE + 2 * op_tab[9].dir_size : 0;
		i += content[1] == 212 ? 2 * REG_SIZE + IND_SIZE : 0;
		i += content[1] == 228 ? REG_SIZE + IND_SIZE + op_tab[9].dir_size : 0;
		i += 2;
	}
	return (i);
}

uint16_t		op_lfork(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (all->check_mode == 1)
		return (op_tab[14].dir_size + 1);
	return (i);
}

uint16_t		op_live(t_all *all, t_op *op, uint8_t *content)
{
	if (all->check_mode == 1)
		return (op_tab[0].dir_size + 1);
	return (0);
}

uint16_t		op_lld(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[12].ocp_value) != 1)
			return (0);

		i += content[1] == 144 ? op_tab[12].dir_size + REG_SIZE : 0;
		i += content[1] == 208 ? IND_SIZE + REG_SIZE : 0;
		i += 2;
	}
	return (i);
}

uint16_t		op_lldi(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[13].ocp_value) != 1)
			return (0);
		i += content[1] == 84 ? 3 * REG_SIZE : 0;
		i += content[1] == 100 ? 2 * REG_SIZE + op_tab[13].dir_size : 0;
		i += content[1] == 148 ? 2 * REG_SIZE + op_tab[13].dir_size : 0;
		i += content[1] == 164 ? REG_SIZE + 2 * op_tab[13].dir_size : 0;
		i += content[1] == 212 ? 2 * REG_SIZE + IND_SIZE : 0;
		i += content[1] == 228 ? REG_SIZE + IND_SIZE + op_tab[13].dir_size : 0;
		i += 2;
	}
	return (i);
}

uint16_t		op_or(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[6].ocp_value) != 1)
			return (0);
		i += content[1] == 84 ? 3 * REG_SIZE : 0;
		i += content[1] == 100 ? 2 * REG_SIZE + op_tab[6].dir_size : 0;
		i += content[1] == 116 ? 2 * REG_SIZE + IND_SIZE : 0;
		i += content[1] == 148 ? 2 * REG_SIZE + op_tab[6].dir_size : 0;
		i += content[1] == 164 ? REG_SIZE + 2 * op_tab[6].dir_size : 0;
		i += content[1] == 180 ? REG_SIZE + IND_SIZE + op_tab[6].dir_size : 0;
		i += content[1] == 212 ? 2 * REG_SIZE + IND_SIZE : 0;
		i += content[1] == 228 ? REG_SIZE + IND_SIZE + op_tab[6].dir_size : 0;
		i += content[1] == 244 ? 2 * IND_SIZE + REG_SIZE : 0;
		i += 2;
	}
	return (i);
}

uint16_t		op_st(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[2].ocp_value) != 1)
			return (0);
		i += content[1] == 80 ? 2 * REG_SIZE : 0;
		i += content[1] == 112 ? REG_SIZE + IND_SIZE : 0;
		i += 2;
	}
	return (i);
}

uint16_t		op_sti(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[10].ocp_value) != 1)
			return (0);
		i += content[1] == 84 ? 3 * REG_SIZE : 0;
		i += content[1] == 88 ? 2 * REG_SIZE + op_tab[10].dir_size : 0;
		i += content[1] == 100 ? 2 * REG_SIZE + op_tab[10].dir_size : 0;
		i += content[1] == 104 ? REG_SIZE + 2 * op_tab[10].dir_size : 0;
		i += content[1] == 116 ? 2 * REG_SIZE + IND_SIZE : 0;
		i += content[1] == 120 ? REG_SIZE + IND_SIZE + op_tab[10].dir_size : 0;
		i += 2;
	}
	return (i);
}

uint16_t		op_sub(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (all->check_mode == 1)
	{
		if (!(content[1]) || is_in(content[1], op_tab[4].ocp_value) != 1)
			return (0);
		i = content[1] == 84 ? 3 * REG_SIZE + 2: 0;
	}
	return (i);
}

uint16_t		op_xor(t_all *all, t_op *op, uint8_t *content)
{
	int			i;

	i = 0;
	if (all->check_mode == 1)
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

uint16_t		op_zjmp(t_all *all, t_op *op, uint8_t *content)
{
	if (all->check_mode == 1)
		return (op_tab[8].dir_size + 1);
	return (0);
}

