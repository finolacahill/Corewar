/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:54:08 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/14 10:35:24 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libsrcs.h"

void	*ft_memalloc(size_t size)
{
	void	*tab;

	if (!(tab = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(tab, size);
	return (tab);
}
