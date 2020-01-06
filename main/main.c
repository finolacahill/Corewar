/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:27:16 by flafonso          #+#    #+#             */
/*   Updated: 2020/01/06 11:06:39 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		main(int ac, char **av)
{
	t_all		vm;
	t_process	p;

	vm.arena = NULL;
	p.decode = NULL;
	dasm_init(&vm, ac, av);
	init_arena(&vm);
	//ft_print_arena(&vm, 64, 0, 0);
	if (run_vm(&vm, &p) == -1)
		return (free_all(&vm, &p));
//	ft_print_arena(&vm, 64, 0, 0);
//	(&vm);
	free_all(&vm, NULL);
}
