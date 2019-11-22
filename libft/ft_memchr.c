/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:52:52 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/23 16:39:56 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int i, size_t n)
{
	const char		*str;
	char			c;
	unsigned int	j;

	str = s;
	c = i;
	j = 0;
	while (j < n)
	{
		if (str[j] == c)
			return (void*)(&str[j]);
		++j;
	}
	return (NULL);
}
