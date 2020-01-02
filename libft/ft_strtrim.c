/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:43:52 by yodana            #+#    #+#             */
/*   Updated: 2018/11/23 16:23:40 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int b;
	int len;

	if (s == NULL)
		return (NULL);
	b = 0;
	while ((s[b] == ' ' || s[b] == '\n' || s[b] == '\t') && s[b])
		b++;
	len = ft_strlen(s) - 1;
	while ((s[len] == ' ' || s[len] == '\t' || s[len] == '\n') && len >= 0)
		len--;
	len++;
	if (!(len))
		return (ft_strnew(0));
	return (ft_strsub(s, b, len - b));
}
