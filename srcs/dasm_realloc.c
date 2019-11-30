/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:02:02 by adietric          #+#    #+#             */
/*   Updated: 2019/11/29 18:32:49 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	*dasm_memmalloccopy(void *content, size_t prev_size, size_t all_size)
{
	void	*new_content;
	size_t	size_min;

	if (!content)
		return (content);
	if (prev_size == all_size)
		return (content);
	if (all_size == 0)
	{
		ft_putstr("Trucs à Free etc..\n");
		exit(EXIT_FAILURE);
	}
	size_min = (prev_size < all_size) ? prev_size : all_size;
	if (!(new_content = ft_memalloc(all_size)))
	{
		ft_putstr("Trucs à Free etc..\n");
		exit(EXIT_FAILURE);
	}
	ft_memcpy(new_content, content, size_min);
	free(content);
	return (new_content);
}
