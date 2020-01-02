/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:28:42 by yodana            #+#    #+#             */
/*   Updated: 2018/11/26 12:29:51 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	if (s == NULL || f == NULL)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (0);
	i = 0;
	while (s[i])
	{
		new[i] = f((char)s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
