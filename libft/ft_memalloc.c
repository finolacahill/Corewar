/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:04:01 by yodana            #+#    #+#             */
/*   Updated: 2018/11/26 15:21:06 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *memory_zone;

	if (!(memory_zone = malloc(size)))
		return (NULL);
	ft_bzero(memory_zone, size);
	return (memory_zone);
}
