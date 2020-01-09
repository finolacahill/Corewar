/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:27:16 by flafonso          #+#    #+#             */
/*   Updated: 2020/01/08 21:04:41 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		main(int ac, char **av)
{
	t_all		*vm;
	t_process	p;

	if (!(vm = (t_all*)malloc(sizeof(t_all))))
		return (0);
	dasm_init(vm, ac, av);
	init_arena(vm);
	ft_print_arena(vm, 64);
	vm_print_intro(vm);
	// ft_printf("\n\nTest de ft_printf ahahaha = %d !\n\n", 2);
	// sleep(2);
	if (run_vm(vm, &p) == -1)
		return (free_all(vm, &p));
	ft_print_arena(vm, 64);
	free_all(vm, NULL);
	return (0);
}
