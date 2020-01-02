/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:45:33 by yodana            #+#    #+#             */
/*   Updated: 2018/12/11 05:05:46 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	if (c == 0)
		return ((char*)s + ft_strlen(s));
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
