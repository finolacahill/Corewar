/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:36:54 by yodana            #+#    #+#             */
/*   Updated: 2020/01/09 16:10:42 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_label		*new_label(t_env *n)
{
	t_label	*new;

	if (!(new = (t_label*)malloc(sizeof(t_label))))
		error(8, NULL, -1, NULL);
	new->label = NULL;
	new->adress = 0;
	new->size = 0;
	new->next = NULL;
	return (new);
}

t_instruc	*new_instruct(t_env *n)
{
	t_instruc *new;

	if (!(new = (t_instruc*)malloc(sizeof(t_instruc))))
		error(8, NULL, -1, NULL);
	new->opcode = 0;
	new->params = NULL;
	new->ocp = 0;
	new->adress = 0;
	new->label = new_label(n);
	new->is_ocp = 0;
	new->hexa_params = NULL;
	new->hexa_instruc = NULL;
	new->next = NULL;
	new->index = 0;
	new->for_direct = 0;
	new->nbr_params = 0;
	return (new);
}

t_env		*init_env(void)
{
	t_env *new;

	if (!(new = (t_env*)malloc(sizeof(t_env))))
		error(8, NULL, -1, NULL);
	if (!(new->header = (t_header*)malloc(sizeof(t_header))))
		error(8, NULL, -1, NULL);
	new->header->c = 0;
	new->header->n = 0;
	new->header->filename = NULL;
	new->header->fd = 0;
	new->header->magic = 0;
	new->header->prog_size = 0;
	new->instruc = new_instruct(new);
	new->line = 0;
	new->column = 0;
	new->c_line = NULL;
	new->label = new_label(new);
	return (new);
}
