/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:09:12 by yodana            #+#    #+#             */
/*   Updated: 2019/06/11 02:24:16 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check_float_round(char *print, int precision)
{
	int i;

	i = 0;
	if (precision != 1)
		return (1);
	if (print[2] == '5')
	{
		if ((print[0] - 48) % 2 == 1)
			return (1);
		while (i != 20)
		{
			if (print[i + 3] >= '1')
				return (1);
			i++;
		}
	}
	else if (print[2] > '5')
		return (1);
	return (0);
}

int		ft_check_precision(int *i, const char *format, va_list args)
{
	int res;
	int k;

	k = 0;
	res = 0;
	if (format[k] != '.')
		return (0);
	if (format[1] == '*')
	{
		*i = *i + 1;
		res = va_arg(args, int) + 1;
	}
	else
		res = ft_atoi(&format[1]) + 1;
	k++;
	*i = *i + 1;
	while (ft_isdigit(format[k]) == 1)
	{
		*i = *i + 1;
		k++;
	}
	if (res < 0)
		return (0);
	return (res);
}

int		ft_check_champ(int *i, const char *format, va_list args)
{
	int resultat;
	int k;

	k = 0;
	if (format[0] == '*')
	{
		*i = *i + 1;
		resultat = va_arg(args, int);
	}
	else
		resultat = ft_atoi(format);
	while (ft_isdigit(format[k]) == 1 || format[k] == '-'
		|| format[k] == '+' || format[k] == '#')
	{
		k++;
		*i = *i + 1;
	}
	return (resultat);
}

int		ft_check_flags(const char *format)
{
	int flags;

	flags = 0;
	if (format[0] == 'h')
	{
		flags = 1;
		if (format[1] == 'h')
			flags++;
	}
	if (format[0] == 'l')
	{
		flags = 4;
		if (format[1] == 'l')
			flags++;
	}
	if (format[0] == 'L')
		flags = 7;
	return (flags);
}

char	*ft_check_attribut(int *i, const char *format, int k, int j)
{
	char *attributs;
	char *res;

	if (!(res = ft_strnew(10)))
		return (NULL);
	if (!(attributs = ft_fill_attribut()))
		return (NULL);
	while (format[*i] == '+' || format[*i] == '-' || format[*i] == ' '
		|| format[*i] == '#' || format[*i] == '0')
	{
		while (attributs[j])
		{
			if (attributs[j] == format[*i])
				res[k++] = attributs[j];
			j++;
		}
		j = 0;
		*i = *i + 1;
	}
	ft_strdel(&attributs);
	return (res);
}
