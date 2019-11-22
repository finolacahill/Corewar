/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:05:00 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/18 20:19:15 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*location;

	i = 0;
	while ((s[i] != (char)c) && (s[i] != '\0'))
		++i;
	if (s[i] == '\0' && (char)c != '\0')
		return (NULL);
	location = &s[i];
	return (char *)(location);
}
