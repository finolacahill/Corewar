/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:44:20 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:17:14 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_sconvert(unsigned int value)
{
	char				result;

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

static char	ft_convert(unsigned int value)
{
	char				result;

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

static char	*uitoa_zero(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*ft_uitoa_base(unsigned long long value, int base, int cap)
{
	char				*str;
	long long unsigned	i;
	long long unsigned	counter;

	counter = value;
	i = 1;
	while ((counter = counter / base) != 0)
		++i;
	if (value == 0)
		i = 1;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (value == 0)
		return (str = uitoa_zero(str));
	str[i] = '\0';
	while (value != 0)
	{
		i--;
		if (cap == 1)
			str[i] = ft_convert(value % base);
		else if (cap == 0)
			str[i] = ft_sconvert(value % base);
		value = value / base;
	}
	return (str);
}
