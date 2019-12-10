/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_print_usage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:58:42 by adietric          #+#    #+#             */
/*   Updated: 2019/12/10 03:19:21 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	error_exec(t_all *all, char *champ_name, uint16_t line)
{
	ft_putstr("Operation invalide pour le champion \"");
	ft_putstr(champ_name);
	// ft_putstr("\" à la ligne ");
	// ft_putnbr((int)line);
	ft_putstr("\n");
	dasm_free(all);
	exit(EXIT_FAILURE);
}

void	dasm_free(t_all *all)
{
	int		i;

	i = 0;
	while (all->champs[i].path != NULL && i < 5)
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
	ft_putstr("Error: File ");
	ft_putstr(path);
	ft_putstr(" has too large a code (");
	ft_putnbr(cor_size - 2192);
	ft_putstr(" bytes > ");
	ft_putnbr(CHAMP_MAX_SIZE);
	ft_putstr(" bytes)\n");
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
	ft_putstr("Usage: ./vm_champs/corewar [-d N -s N -v N | -b --stealth");
	ft_putstr("| -n --stealth] [-a] <champion1.cor> <...>");
	dasm_free(all);
	exit(EXIT_FAILURE);
}
