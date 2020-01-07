/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_check_hex_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 08:04:09 by flafonso          #+#    #+#             */
/*   Updated: 2020/01/06 10:39:34 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

uint16_t		check_code(t_all *vm, char *name, uint8_t *cont
				, t_verif_op *verif_op)
{
	uint16_t	i;

	i = 0;
	if (cont[0] > 16 || cont[0] < 1)
		error_exec(vm, name, i);
	i = verif_op[cont[0] - 1].inst(cont);
	i == 0 ? error_exec(vm, name, i) : 0;
	return (i);
}

void			dasm_check_hex_code(t_all *vm)
{
	t_verif_op	*verif_op;
	int			id;
	uint16_t	i;

	if (!(verif_op = (t_verif_op*)malloc(sizeof(t_verif_op) * 16)))
		error(vm, "Malloc error dasm_check_hex_code\n");
	verif_op = init_op_verif(vm, verif_op);
	id = -1;
	while (++id < vm->total_champ)
	{
		i = 0;
		while (i < vm->champs[id].len_exec_code)
		{
			i += check_code(vm, (char*)vm->champs[id].name
				, &(vm->champs[id].exec_code[i]), verif_op);
		}
	}
	free(verif_op);
}
