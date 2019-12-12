/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notre_truc_a_nous.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:47:28 by adietric          #+#    #+#             */
/*   Updated: 2019/12/11 23:58:36 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void				init_reg(t_all *all)
{
	int r = 1;
	while (++r < REG_NUMBER)
		all->processes.r[r] = 0;
}

unsigned char		*join_arena(unsigned char *arena, int pos)
{
	unsigned char	*all_arena;

	if (!(all_arena = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE)))
		exit(EXIT_FAILURE);   //A CHANGER
	ft_memcpy(all_arena, &(arena[pos]), MEM_SIZE - pos);
	ft_memcpy(&(all_arena[MEM_SIZE - pos]), &(arena[0]), pos);
	return (all_arena);
}

void	print_arenaw(t_all *all, int i)
{
	if (i % 65 == 0 && i != 0)
		printf("\n");
	if (i < all->champs[0].len_exec_code && i != all->processes.pc)								//EXEC_CODE
		printf("\033[38;5;12m%0.2d \033[0m",  all->arena[i]);
	else if (i == all->processes.pc)
		printf("\033[48;5;118m\033[38;5;0m%0.2d\033[0m ",  all->arena[i]);						//CURSOR
	else
		printf("%0.2d ",  all->arena[i]);
}

void	notre_truc_a_nous(t_all *all)
{
	t_op		op[17];
	uint16_t	index;

	index = init_op_check(op);
	init_reg(all);																	// Reg pas tous a zero ???? SI ENCULE !
	printf("\n=======================\n\n	On travaille avec |%s|\n", all->champs[0].name);
	// dasm_print_all(all);
	int i = -1;
	unsigned char *next_arena;
	unsigned char *all_arena;

	while (1)
	{
		all->processes.pc = -1;
		while (++(all->processes.pc) < MEM_SIZE - 1)
		{
			while (++i < MEM_SIZE - 1)
			{
				print_arenaw(all, i);
				if (i == all->processes.pc)
				{
					if (all->arena[i] > 0 && all->arena[i] < 17)
					{
						all_arena = join_arena(all->arena, i);
						if (all->processes.carry == 1 && all->arena[i] == 9)
						{
							all->processes.pc = dasm_get_exec_code(&(all_arena[1]), 2);
							free(all_arena);
							continue ;
						}
						all->processes.pc += op[all->arena[i] - 1].inst(all, op, all_arena);
						free(all_arena);
						sleep(1);
					}
				}
			}
			printf("\n\n__NEXT__\n\n\n");
			sleep  (1);
			i = -1;
		}
	}
}