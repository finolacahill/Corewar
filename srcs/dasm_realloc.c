/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:02:02 by adietric          #+#    #+#             */
/*   Updated: 2019/12/10 02:40:09 by flafonso         ###   ########.fr       */
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
		return (NULL);
	size_min = (prev_size < all_size) ? prev_size : all_size;
	if (!(new_content = ft_memalloc(all_size)))
		return (NULL);
	ft_memcpy(new_content, content, size_min);
	free(content);
	return (new_content);
}
