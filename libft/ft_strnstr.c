/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 19:30:00 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/23 16:44:43 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *c, size_t len)
{
	unsigned int		i;
	unsigned int		j;
	const char			*location;

	i = 0;
	j = 0;
	if (c[0] == '\0')
		return (char *)(hay);
	while ((i < len) && (hay[i] != '\0'))
	{
		if (c[j] == hay[i])
		{
			location = &hay[i];
			while ((c[j] != '\0' && hay[i + j] != '\0') &&
					((i + j < len && c[j] == hay[i + j]) ||
					(c[j + 1] == '\0' && hay[i + j + 1] == '\0')))
				++j;
			if (c[j] == '\0')
				return (char *)(location);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
