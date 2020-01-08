/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 21:20:25 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/23 16:25:57 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int j;

	j = 0;
	while ((j < len) && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	while (j != len)
	{
		dst[j] = '\0';
		j++;
	}
	return (dst);
}
