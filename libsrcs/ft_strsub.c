/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 08:43:26 by flafonso          #+#    #+#             */
/*   Updated: 2019/10/05 15:25:08 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libsrcs.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = len + 1;
	if (!(str = ft_memalloc(i)) || !(s))
		return (NULL);
	str = ft_strncpy(str, &s[start], len);
	str[len] = '\0';
	return (str);
}
