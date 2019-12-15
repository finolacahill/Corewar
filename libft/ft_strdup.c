/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:14:57 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/23 16:40:50 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		j;
	char	*copy;

	j = 0;
	if (!(copy = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1)))
		return (NULL);
	while (s1[j] != '\0')
	{
		copy[j] = s1[j];
		++j;
	}
	copy[j] = '\0';
	return (copy);
}
