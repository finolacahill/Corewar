/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:03:04 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/23 17:00:53 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_insertnum(char *str, int n, int i)
{
	if (str)
	{
		str[i + 1] = '\0';
		while (n >= 10)
		{
			str[i] = (n % 10 + '0');
			n = n / 10;
			i--;
		}
		str[i] = n + '0';
	}
	return (&*str);
}

char			*ft_itoa(int n)
{
	int			i;
	int			j;
	char		*str;

	i = 0;
	j = n;
	while ((j / 10 != 0) && (i++ || 1))
		j = j / 10;
	if (!(str = (char *)malloc(sizeof(char) * i + 2)))
		return (NULL);
	if ((n < 0) && (i++ || 1))
	{
		if (n == -2147483648)
		{
			str[1] = 2 + '0';
			n = -147483648;
		}
		str[0] = '-';
		n = -n;
	}
	str = ft_insertnum(str, n, i);
	return (str);
}
