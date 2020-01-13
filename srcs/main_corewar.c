/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:27:16 by flafonso          #+#    #+#             */
/*   Updated: 2020/01/13 15:37:14 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		define_check(void)
{
	if (MAX_PLAYERS != 4)
	{
		ft_fprintf(2, "Error: Max players must be 4.\n");
		exit(0);
	}
	if (MEM_SIZE != 4096)
	{
		ft_fprintf(2, "Error: Mem_size must be 4096.\n");
		exit(0);
	}
	if (IDX_MOD != 512)
	{
		ft_fprintf(2, "Error: Idx_mod must be 512");
		exit(0);
	}
	if (CHAMP_MAX_SIZE != 682)
	{
		ft_fprintf(2, "Error: Champ_max_size must be 682.\n");
		exit(0);
	}
}

int				main(int ac, char **av)
{
	t_all		*vm;
	t_process	p;

	define_check();
	if (!(vm = (t_all*)malloc(sizeof(t_all))))
		return (0);
	dasm_init(vm, ac, av);
	init_arena(vm);
	vm_print_intro(vm);
	if (run_vm(vm, &p) == -1)
		return (free_all(vm, &p));
	free_all(vm, NULL);
	return (0);
}
