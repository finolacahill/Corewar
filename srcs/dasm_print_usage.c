/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_print_usage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:58:42 by adietric          #+#    #+#             */
/*   Updated: 2019/12/16 09:22:58 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	error_exec(t_all *all, char *champ_name, uint16_t line)
{
	ft_putstr("Invalid operation for champion \"");
	ft_putstr(champ_name);
	ft_putstr("\" at line ");
	ft_putnbr((int)line);
	ft_putstr("\n");
	dasm_free(all);
	exit(EXIT_FAILURE);
}

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
}

void	error_size(t_all *all, char *path, size_t cor_size)
{
	ft_printf("Error: File %s has too large a code (%d bytes > %d bytes)\n", 
	path, cor_size - 2192, CHAMP_MAX_SIZE);
	dasm_free(all);
	exit(EXIT_FAILURE);
}

void	error(t_all *all, char *str)
{
	ft_putstr(str);
	dasm_free(all);
	exit(EXIT_FAILURE);
}

void	print_usage(t_all *all)
{
	ft_printf("Usage: ./vm_champs/corewar [-dump X -v X -n X]\n#### TEXT OUTPUT");
	ft_printf(" MODE ##########################################################\n");
	ft_printf("\t\t-dump X\t: Dumps memory after X cycles then exits\n");
	ft_printf("\t\t-n    X\t: Set a player id to X. X is a number between 1 & number of players.\n");
	ft_printf("\t\t-v    X\t: Verbosity levels\n\t\t\t- 0 : Show only essentials\n");
	ft_printf("\t\t\t- 1 : Show lives\n\t\t\t- 2 : Show cycles\n\t\t\t- 4 : Show");
	ft_printf(" operations\n\t\t\t- 8 : Show deaths\n\t\t\t- 16 : Show cycles to die\n");
	dasm_free(all);
	exit(EXIT_FAILURE);
}
