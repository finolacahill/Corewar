/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:46:09 by yodana            #+#    #+#             */
/*   Updated: 2018/11/27 12:06:31 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src >= dst)
		return (ft_memcpy(dst, src, len));
	while (len)
	{
		((char*)dst)[len - 1] = ((char*)src)[len - 1];
		len--;
	}
	return (dst);
}
