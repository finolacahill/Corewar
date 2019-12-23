/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:27:16 by flafonso          #+#    #+#             */
/*   Updated: 2019/12/16 07:54:23 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int main(int ac, char **av)
{
	t_all vm;
	t_process p;

	vm.arena = NULL;
	p.decode = NULL;
	p.all_dead = -1;
	dasm_init(&vm, ac, av);
	if (init_arena(&vm) == -1)
		return (error_arena(&vm, &p));
	if (run_vm(&vm, &p) == -1)
		return (free_all(&vm, &p));
//	(&vm);
	free_all(&vm, NULL);
	// free the vm
}

