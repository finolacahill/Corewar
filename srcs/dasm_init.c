/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:04:55 by adietric          #+#    #+#             */
/*   Updated: 2020/01/09 14:12:57 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		zero_champs(t_all *vm)
{
	int			i;

	i = -1;
	while (++i < MAX_PLAYERS)
		ft_bzero(&(vm->champs[i]), sizeof(t_champs));
}

void			dasm_init_champs(t_all *vm, int ac, char **av)
{
	uint8_t		*cor_content;
	size_t		cor_size;

	cor_size = 0;
	cor_content = NULL;
	dasm_input(ac, av, vm);
	while (vm->total_champ < MAX_PLAYERS
		&& vm->champs[vm->total_champ].path != NULL)
	{
		if (dasm_is_it_cor(vm->champs[vm->total_champ].path) != 1)
			print_usage(vm);
		cor_size = dasm_get_data(vm, vm->champs[vm->total_champ].path,
		&cor_content);
		dasm_get_header(vm, cor_size, &cor_content,
		&vm->champs[vm->total_champ]);
		free(cor_content);
		cor_content = NULL;
		vm->champs[vm->total_champ].pc = 0;
		vm->total_champ++;
	}
}

t_all			*dasm_init(t_all *vm, int ac, char **av)
{
	int			i;
	int			nb;

	i = -1;
	nb = 0;
	zero_champs(vm);
	vm->flag_dump = -1;
	vm->flag_n = -1;
	vm->flag_v = 0;
	vm->total_champ = 0;
	vm->ac = ac;
	dasm_init_champs(vm, ac, av);
	while (++i < MAX_PLAYERS)
		if (vm->champs[i].name != NULL)
			nb++;
	if (vm->flag_n != -1 && nb < vm->flag_n)
		print_usage(vm);
	dasm_check_hex_code(vm);
	return (vm);
}
