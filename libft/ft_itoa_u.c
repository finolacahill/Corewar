/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:17:20 by yodana            #+#    #+#             */
/*   Updated: 2019/06/11 18:18:20 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_u(int size, unsigned long long n, int neg)
{
	char *new;

	if (!(new = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	new[size] = '\0';
	size--;
	while (size >= 0)
	{
		new[size] = (n % 10) + '0';
		if (size == 0 && neg == 1)
			new[size] = '-';
		n = n / 10;
		size--;
	}
	return (new);
}

char		*ft_itoa_u(long long n)
{
	unsigned long long	i;
	int					size;
	int					neg;

	neg = 0;
	size = 0;
	if (n == 0)
		return (ft_strdup("0"));
	i = n;
	while (i > 0)
	{
		i = i / 10;
		size++;
	}
	return (ft_create_u(size, n, neg));
}
