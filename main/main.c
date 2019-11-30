/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:27:16 by flafonso          #+#    #+#             */
/*   Updated: 2019/11/29 17:40:50 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

int	main(int ac, char **av)
{
	t_all		all;
	uint8_t		*cor_content;
	size_t		cor_size;
	int			i;

	cor_size = 0;
	cor_content = NULL;
	dasm_init(&all);
	dasm_input(ac, av, &all);
	i = 0;
	while (all.champs[i].path != NULL && i < 5)
	{
		if (dasm_is_it_cor(all.champs[i].path) != 1)
			print_usage(&all);
		cor_size = dasm_get_data(&all, all.champs[i].path, &cor_content);
		dasm_get_header(&all, cor_size, &cor_content, &all.champs[i]);
		free(cor_content);
		cor_content = NULL;
		i++;
	}
	// dasm_print_all(&all);
	vm_print_intro(&all);
	dasm_free(&all);
	return (0);
}
