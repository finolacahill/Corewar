/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:52:23 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/21 12:51:13 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	int			j;
	const char	*location;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return (char *)(haystack);
	while (haystack[i] != '\0')
	{
		if (needle[j] == haystack[i])
		{
			location = &haystack[i];
			while (needle[j] == haystack[i + j] && needle[j] != '\0'
					&& haystack[i + j] != '\0')
				++j;
			if (needle[j] == '\0')
				return (char *)(location);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
