/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_free_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:37:40 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 12:39:14 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			free_process(t_all *vm, t_process *p)
{
	if (p != NULL && vm->total_process - vm->dead > 0)
	{
		if (vm->flag_v == 8)
		{
			ft_printf("Process pid %d, id %d", p->pid, p->id);
			ft_printf(" hasn't lived for %d", vm->cycles - p->live_calls);
			ft_printf(" (cycles to die %d, cycle ", vm->cycles_to_die);
			ft_printf("%d).\n", vm->cycles);
		}
		if (p->decode != NULL)
			free(p->decode);
		p->decode = NULL;
		free(p);
		++vm->dead;
		p = NULL;
	}
}

void			free_vm(t_all *vm)
{
	if (vm->arena != NULL)
		ft_memdel((void **)&vm->arena);
	vm->arena = NULL;
	if (vm->order != NULL)
		free(vm->order);
	vm->order = NULL;
	dasm_free(vm);
}

int				free_all(t_all *vm, t_process *p)
{
	free_process(vm, p);
	free_vm(vm);
	return (0);
}

void			free_dasm_header(t_all *all, uint8_t *cor_content, char *s)
{
	free(cor_content);
	error(all, s);
}
