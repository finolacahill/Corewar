/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:21:42 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/24 03:17:24 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_errorfloat(t_flag flag, long double fval)
{
	int		len;
	char	*p1;

	if (fval != fval || fval == 1.0 / 0.0)
		len = 3;
	else
		len = 4;
	if (!(p1 = (char *)malloc(sizeof(char) * len)))
		return (flag = ft_returnerror(flag));
	if (fval != fval)
		ft_strcpy(p1, "nan");
	if (fval == 1.0 / 0.0)
		ft_strcpy(p1, "inf");
	if (fval == -1.0 / 0.0)
		ft_strcpy(p1, "-inf");
	if (flag.left == 1)
		flag = ft_putstrb(flag, p1, -1);
	while (len++ < flag.width)
		flag = ft_buffer(flag, ' ');
	if (flag.left == 0)
		flag = ft_putstrb(flag, p1, -1);
	free(p1);
	flag.i++;
	return (flag);
}

static t_flag	ft_floatwidth(t_flag flag, int len)
{
	if (len < flag.width && flag.zero == 1
			&& flag.left == 0 && flag.plus == 1)
		flag = ft_buffer(flag, '+');
	while (len++ < flag.width)
	{
		if (flag.zero == 1 && flag.left == 0)
		{
			if (flag.neg == 1)
			{
				flag = ft_buffer(flag, '-');
				flag.neg = 0;
			}
			flag = ft_buffer(flag, '0');
		}
		else
			flag = ft_buffer(flag, ' ');
	}
	return (flag);
}

static t_flag	ft_floatprecision(t_flag flag, char *p1, char *p2, int len)
{
	if (flag.precision == 0)
	{
		len = len - ft_strlen(p2);
		if (flag.hashtag == 0)
			--len;
	}
	if (p1[0] == '0' && p1[1] == '\0')
	{
		if (flag.precision < 0)
			len = 8 + flag.space + flag.plus;
		else if (flag.precision > 0)
			len = 2 + flag.precision + flag.space + flag.plus;
		else if (flag.precision == 0)
			len = 1 + flag.hashtag + flag.space + flag.plus;
	}
	if (flag.left == 1)
		flag = ft_printfloat(p1, p2, flag, len);
	flag = ft_floatwidth(flag, len);
	if (flag.left == 0)
		flag = ft_printfloat(p1, p2, flag, len);
	++flag.i;
	free(p1);
	free(p2);
	return (flag);
}

static t_flag	ft_negfloat(t_flag flag, long double fval)
{
	if (fval < 0)
	{
		flag.plus = 0;
		flag.neg = 1;
		flag.space = 0;
		--flag.width;
	}
	return (flag);
}

t_flag			ft_float(t_flag flag, long double fval)
{
	char	*p1;
	char	*p2;
	int		len;

	if (fval != fval || fval == 1.0 / 0.0 || fval == -1.0 / 0.0)
		return (flag = ft_errorfloat(flag, fval));
	flag = ft_negfloat(flag, fval);
	if (fval < 0)
		fval = -fval;
	if (flag.space == 1 && flag.plus == 1)
		flag.space = 0;
	if (flag.space == 1)
		flag = ft_buffer(flag, ' ');
	if (!(p1 = ft_uitoa_base((unsigned long long)fval, 10, 0)))
		return (flag = ft_returnerror(flag));
	if (fval < 0)
		fval = -fval;
	if (!(p2 = ft_itoa_float(fval, flag)))
	{
		free(p1);
		return (flag = ft_returnerror(flag));
	}
	len = ft_strlen(p1) + ft_strlen(p2) + 1 + flag.space + flag.plus;
	flag = ft_floatprecision(flag, p1, p2, len);
	return (flag);
}
