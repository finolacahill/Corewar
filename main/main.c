/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:27:16 by flafonso          #+#    #+#             */
/*   Updated: 2020/01/07 19:46:18 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	dasm_print_all(t_all *all)
{
	int i;
	int r;

	r = -1;
	i = 0;
	printf("\n====================================\n");
	printf("	===========PRINT=ALL========\n");
	printf("	flag_dump	=	%d\n", all->flag_dump);
	printf("	flag_n		=	%d\n", all->flag_n);
	printf("	============================\n");
	while (all->champs[i].path != NULL && i < 5)
	{
		printf("	champs[%d].path = |%s|\n", i, all->champs[i].path);
		printf("	id		=		%d\n", all->champs[i].id);
		printf("	name		=	|%s|\n", all->champs[i].name);
		printf("	comment		=	|%s|\n", all->champs[i].comment);
		printf("	len_exec	=		%zu\n", all->champs[i].len_exec_code);
		printf("	exec_code	=\n\n");
		// while (++r   <  all->champs[i].len_exec_code)
			// printf("%02x ", all->champs[i].exec_code[r]);
		printf("\n	===========================\n");
		i++;
	}
	printf("====================================\n");
}


int		main(int ac, char **av)
{
	t_all		vm;
	t_process	p;

	vm.arena = NULL;
	p.decode = NULL;
	dasm_init(&vm, ac, av);
	dasm_print_all(&vm);
	init_arena(&vm);
	// ft_print_arena(&vm, 64);
	//ft_print_arena(&vm, 64, 0, 0);
																					// dasm_print_all(&vm);
	// if (run_vm(&vm, &p) == -1)
		// return (free_all(&vm, &p));
//	(&vm);
	free_all(&vm, NULL);
}
