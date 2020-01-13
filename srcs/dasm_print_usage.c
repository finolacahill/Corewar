/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_print_usage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:58:42 by adietric          #+#    #+#             */
/*   Updated: 2020/01/13 13:43:23 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	dasm_free(t_all *all)
{
	int		i;

	i = 0;
	while (all->champs[i].path != NULL && i < MAX_PLAYERS)
	{
		ft_strdel((char**)&(all->champs[i].path));
		ft_strdel((char**)&(all->champs[i].name));
		ft_strdel((char**)&(all->champs[i].comment));
		ft_strdel((char**)&(all->champs[i].exec_code));
		i++;
	}
	free(all);
	all = NULL;
}

void	error_size(t_all *all, char *path, size_t cor_size)
{
	ft_fprintf(2, "Error: File %s has a too large code (%d bytes > %d bytes)\n",
	path, cor_size - 2192, CHAMP_MAX_SIZE);
	dasm_free(all);
	exit(EXIT_FAILURE);
}

void	error(t_all *all, char *str)
{
	ft_fprintf(2, "%s", str);
	dasm_free(all);
	exit(EXIT_FAILURE);
}

void	print_usage(t_all *all)
{
	ft_printf("Usage: ./vm_champs/corewar [-dump X -v X -n X]\n");
	ft_printf("#### TEXT OUTPUT MODE ");
	ft_printf("##########################################################\n");
	ft_printf("\t\t-dump X\t: Dumps memory after X cycles then exits. ");
	ft_printf("X is a positive integer.\n\t\t-n    X\t: Set a player's id to");
	ft_printf(" X. X is an integer.\n");
	ft_printf("\t\t-v    X\t: Verbosity levels\n\t\t\t- 0 : Show");
	ft_printf(" only essentials\n");
	ft_printf("\t\t\t- 1 : Show lives\n\t\t\t- 2 : Show cycles\n\t\t\t- 4");
	ft_printf(" : Show operations\n");
	ft_printf("\t\t\t- 8 : Show deaths\n\t\t\t- 16 : Show cycles to die\n");
	dasm_free(all);
	exit(EXIT_FAILURE);
}
