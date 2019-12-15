/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:57:29 by adietric          #+#    #+#             */
/*   Updated: 2019/12/15 18:54:33 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	dasm_print_all(t_all *all)
{
	printf("\n====================================\n");
	printf("	===========PRINT=ALL========\n");
	printf("	flag_dump	=	%d\n", all->flag_dump);
	printf("	flag_n		=	%d\n", all->flag_n);
	printf("	============================\n");
	int i = 0;
	while (all->champs[i].path != NULL && i < 5)
	{
		printf("	champs[%d].path = |%s|\n", i, all->champs[i].path);
		printf("	id		=		%d\n", all->champs[i].id);
		printf("	name		=	|%s|\n", all->champs[i].name);
		printf("	comment		=	|%s|\n", all->champs[i].comment);
		printf("	len_exec	=		%zu\n", all->champs[i].len_exec_code);
		printf("	exec_code	=\n\n");
		int r = -1;
		while (++r <  all->champs[i].len_exec_code)
			printf("%0.2d ", all->champs[i].exec_code[r]);
		printf("\n	===========================\n");
		i++;
	}
	printf("====================================\n");

}