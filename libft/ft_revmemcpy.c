/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revmemcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:36:05 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/22 18:52:04 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_revmemcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*str1;
	const char		*str2;

	str1 = dst;
	str2 = src;
	i = n - 1;
	while (i > 0)
	{
		str1[i] = str2[i];
		i--;
	}
	str1[i] = str2[i];
	return (void *)(dst);
}
