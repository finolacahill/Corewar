/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:20:55 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/23 16:42:52 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dstlen;
	unsigned int	srclen;
	int				i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (size == 0)
		return (srclen);
	while ((src[i] != '\0') && (dstlen + i < size - 1))
	{
		dst[dstlen + i] = src[i];
		++i;
	}
	dst[dstlen + i] = '\0';
	if (dstlen < size)
		return (dstlen + srclen);
	return (srclen + size);
}
