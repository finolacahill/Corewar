/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 22:34:54 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:33:53 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_itoa_round(long double n, t_flag flag, char *number, int i)
{
	n = n - (unsigned long long)n;
	n = n * 10;
	--i;
	if ((unsigned long long)n >= 5)
	{
		if (n == 5)
		{
			if (number[i] % 2 != 0)
				number[i] = number[i] + 1;
		}
		else
			number[i] = number[i] + 1;
	}
	if (number[i] == ':')
	{
		number[i] = '9';
		while (number[i] == '9')
		{
			number[i] = '0';
			i--;
		}
		number[i] = number[i] + 1;
	}
	number[flag.precision + 1] = '\0';
	return (number);
}

char		*ft_itoa_float(long double n, t_flag flag)
{
	char				*number;
	unsigned long long	count;
	int					i;

	if (flag.precision <= 0)
		flag.precision = 6;
	if (!(number = malloc((sizeof(char) * (flag.precision + 1)))))
		return (NULL);
	i = 0;
	n = n - (unsigned long long)n;
	while (i < (flag.precision))
	{
		n = n * 10;
		count = (unsigned long long)n;
		number[i] = count + '0';
		n = (n - (unsigned long long)n);
		i++;
	}
	number[i] = '\0';
	number = ft_itoa_round(n, flag, number, i);
	return (number);
}
