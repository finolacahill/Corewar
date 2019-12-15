/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:10:04 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/23 17:00:15 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*fresh;

	if (!s)
		return (0);
	start = 0;
	end = ft_strlen(s) - 1;
	i = 0;
	while ((s[start] == ' ') || (s[start] == '\t') || (s[start] == '\n'))
		start++;
	while ((start < end) && ((s[end] == ' ')
				|| (s[end] == '\t') || (s[end] == '\n')))
		end--;
	if (!(fresh = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	while (start <= end)
	{
		fresh[i] = s[start];
		i++;
		start++;
	}
	fresh[i] = '\0';
	return (fresh);
}
