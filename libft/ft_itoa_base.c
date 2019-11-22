/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:03:44 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:03:46 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_sconvert(long long value)
{
	char		result;

	if (value < 10)
		result = value + '0';
	if (value == 10)
		result = 'a';
	if (value == 11)
		result = 'b';
	if (value == 12)
		result = 'c';
	if (value == 13)
		result = 'd';
	if (value == 14)
		result = 'e';
	if (value == 15)
		result = 'f';
	return (result);
}

static char	ft_convert(long long value)
{
	char		result;

	if (value < 10)
		result = value + '0';
	if (value == 10)
		result = 'A';
	if (value == 11)
		result = 'B';
	if (value == 12)
		result = 'C';
	if (value == 13)
		result = 'D';
	if (value == 14)
		result = 'E';
	if (value == 15)
		result = 'F';
	return (result);
}

static char	*ft_itoa_zero(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*ft_itoa_base(long long value, int base, int cap)
{
	char		*str;
	long long	i;

	i = ft_numlen(value);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (value == 0)
		return (ft_itoa_zero(str));
	if (value < 0)
	{
		value = -value;
		if (base == 10)
			str[0] = '-';
	}
	str[i] = '\0';
	while (value != 0)
	{
		i--;
		if (cap == 0)
			str[i] = ft_sconvert(value % base);
		else
			str[i] = ft_convert(value % base);
		value = value / base;
	}
	return (str);
}
