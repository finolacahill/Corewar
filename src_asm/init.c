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

int		new_label(t_label **new)
{
	if (!((*new) = (t_label*)malloc(sizeof(t_label))))
		return (-1);
	(*new)->label = NULL;
	(*new)->adress = 0;
	(*new)->size = 0;
	(*new)->next = NULL;
	return (0);
}

int		new_instruct(t_instruc **new)
{
	if (!((*new) = (t_instruc*)malloc(sizeof(t_instruc))))
		return (-1);
	(*new)->opcode = 0;
	(*new)->params = NULL;
	(*new)->ocp = 0;
	(*new)->adress = 0;
	new_label(&((*new)->label));
	(*new)->is_ocp = 0;
	(*new)->hexa_params = NULL;
	(*new)->hexa_instruc = NULL;
	(*new)->next = NULL;
	(*new)->index = 0;
	(*new)->for_direct = 0;
	(*new)->nbr_params = 0;
	return (0);
}

void		free_envi(t_env *new)
{
	free(new->instruc->label);
	free(new->instruc);
	free(new->header);
	free(new);
	error(8, -1, -1, NULL);
}

void	free_new_head(t_env *new)
{
	free(new->header);
	free(new);
	error(8, -1, -1, NULL);
}

t_env		*init_env(void)
{
	t_env *new;

	if (!(new = (t_env*)malloc(sizeof(t_env))))
		error(8, -1, -1, NULL);
	if (!(new->header = (t_header*)malloc(sizeof(t_header))))
	{
		free(new);
		error(8, -1, -1, NULL);
	}
	new->header->c = 0;
	new->header->n = 0;
	new->header->filename = NULL;
	new->header->fd = 0;
	new->header->magic = 0;
	new->header->prog_size = 0;
	if ((new_instruct(&(new->instruc))) == -1)
		free_new_head(new);
	new->line = 0;
	new->column = 0;
	if ((new_label(&(new->label))) == -1)
		free_envi(new);
	return (new);
}
