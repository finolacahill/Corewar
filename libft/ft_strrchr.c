/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:34:32 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/21 12:49:39 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*location;

	location = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			location = &s[i];
		++i;
	}
	if ((char)c == '\0')
		location = &s[i];
	return (char *)(location);
}
