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

int		main(int ac, char **av)
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
