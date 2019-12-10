/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:01:39 by adietric          #+#    #+#             */
/*   Updated: 2019/12/10 11:32:51 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	vm_start(t_all *all)
{
	t_op		op[17];
	int			id;
	int			i;
	uint16_t	index;

	index = init_op_check(op);
	id = 1;
																						printf("\n\n	Nb_champ = %d\n", all->total_champ);
	while (id <= all->total_champ)
	{
		index = 0;
		i = 0;
		while (all->champs[i].id != id)
			i++;
																						// printf("Le champ [%d] est |%s|\n", id, all->champs[i].name);
		while (index < all->champs[i].len_exec_code)
		{
																						// printf("					index = %hu   | --> |%hhu|\n", index, all->champs[i].exec_code[index]);
			index += vm_check_exec(all, &(all->champs[i])
					, &(all->champs[i].exec_code[index]), op);
		}
		id++;
					printf("Champ |%s| est BON !! \n", all->champs[i].name);
	}
}