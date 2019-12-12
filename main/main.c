/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:27:16 by flafonso          #+#    #+#             */
/*   Updated: 2019/12/10 15:47:02 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int main(int ac, char **av)
{
	t_all vm;
	t_process process;

	dasm_init(&vm, ac, av);
	if (init_arena(&vm) == -1)
		{
		printf("Error initialising arena.\n");
		dasm_free(&vm);
		return (0);
	}
	// if (run_vm(&vm) == -1)
	// {
		
		// free the things;
		// return (0);
	// }
	notre_truc_a_nous(&vm);
	dasm_free(&vm);
	//free the vm
}
