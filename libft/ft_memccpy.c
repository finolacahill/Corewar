/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:18:30 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/22 20:28:04 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int			i;
	unsigned char			*str1;
	unsigned const char		*str2;

	str1 = dst;
	str2 = src;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		str1[i] = str2[i];
		if (str2[i] == (unsigned char)c)
		{
			str1[i] = str2[i];
			return (void*)(dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
