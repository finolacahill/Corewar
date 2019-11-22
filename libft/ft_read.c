/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:12:37 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:12:43 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_readdsc(t_flag flag, char *p, va_list ap)
{
	long long			ival;

	if (p[flag.i] == '%')
		return (flag = ft_percent(flag));
	if (p[flag.i] == 'd' || p[flag.i] == 'i' || p[flag.i] == 'D')
	{
		if ((flag.ll == 1 && flag.z == 0 && flag.j == 0) || (p[flag.i] == 'D'))
			ival = va_arg(ap, long long);
		if ((flag.l == 1 || flag.z == 1 || flag.j == 1) && p[flag.i] != 'D')
			ival = va_arg(ap, long);
		if (flag.h == 1 && flag.z == 0 && flag.j == 0 && p[flag.i] != 'D')
			ival = (short)va_arg(ap, int);
		if (flag.hh == 1 && flag.z == 0 && flag.j == 0 && p[flag.i] != 'D')
			ival = (char)va_arg(ap, int);
		else if (flag.ll == 0 && flag.l == 0 && flag.j == 0
				&& flag.h == 0 && flag.hh == 0
				&& flag.z == 0 && p[flag.i] != 'D')
			ival = va_arg(ap, int);
		return (flag = ft_int(flag, ival));
	}
	if (p[flag.i] == 's' || p[flag.i] == 'S')
		return (flag = ft_str(flag, va_arg(ap, char *)));
	if (p[flag.i] == 'c' || p[flag.i] == 'C')
		return (flag = ft_char(flag, (char)va_arg(ap, int)));
	return (flag);
}

static t_flag	ft_reado(t_flag flag, char *p, va_list ap)
{
	long long unsigned	oval;
	char				*str;

	if (p[flag.i] == 'o' || p[flag.i] == 'O')
	{
		if (flag.ll == 1 || p[flag.i] == 'O' || flag.j == 1 || flag.z == 1)
			oval = va_arg(ap, long long unsigned int);
		if (flag.l == 1 && p[flag.i] != 'O' && flag.j == 0 && flag.z == 0)
			oval = va_arg(ap, long unsigned int);
		if (flag.h == 1 && p[flag.i] != 'O' && flag.j == 0 && flag.z == 0)
			oval = (short unsigned)va_arg(ap, unsigned int);
		if (flag.hh == 1 && p[flag.i] != 'O' && flag.j == 0 && flag.z == 0)
			oval = (unsigned char)va_arg(ap, unsigned int);
		else if (flag.ll == 0 && flag.l == 0 && p[flag.i] != 'O'
				&& flag.h == 0 && flag.hh == 0 && flag.j == 0 && flag.z == 0)
			oval = va_arg(ap, unsigned int);
		if (!(str = ft_uitoa_base(oval, 8, 0)))
			return (flag = ft_returnerror(flag));
		flag = ft_octal(flag, str);
		free(str);
	}
	return (flag);
}

static t_flag	ft_readfp(t_flag flag, char *p, va_list ap)
{
	char	*str;

	if (p[flag.i] == 'f' || p[flag.i] == 'F')
	{
		if (flag.l == 1 || flag.ll == 1)
			return (flag = ft_float(flag, va_arg(ap, long double)));
		else if (flag.ll == 0 && flag.l == 0)
			return (flag = ft_float(flag, va_arg(ap, double)));
	}
	if (p[flag.i] == 'p')
	{
		if (!(str = ft_uitoa_base(va_arg(ap, long unsigned), 16, 0)))
			return (flag = ft_returnerror(flag));
		else
		{
			flag = ft_point(flag, str);
			free(str);
		}
	}
	return (flag);
}

static t_flag	ft_readx(t_flag flag, char *p, va_list ap)
{
	int					cap;
	long long unsigned	xval;
	char				*str;

	cap = 0;
	if (p[flag.i] == 'x' || p[flag.i] == 'X')
	{
		if (p[flag.i] == 'X')
			cap = 1;
		if (flag.ll == 1 || flag.j == 1 || flag.z == 1)
			xval = va_arg(ap, long long unsigned);
		if (flag.l == 1 && flag.j == 0 && flag.z == 0)
			xval = va_arg(ap, long unsigned);
		if (flag.h == 1 && flag.j == 0 && flag.z == 0)
			xval = (unsigned short)va_arg(ap, unsigned int);
		if (flag.hh == 1 && flag.j == 0 && flag.z == 0)
			xval = (unsigned char)va_arg(ap, unsigned int);
		else if (flag.ll == 0 && flag.l == 0 && flag.z == 0
				&& flag.j == 0 && flag.h == 0 && flag.hh == 0)
			xval = va_arg(ap, unsigned int);
		if (!(str = ft_uitoa_base(xval, 16, cap)))
			return (flag = ft_returnerror(flag));
		return (flag = ft_hex(flag, p[flag.i], str));
	}
	return (flag);
}

t_flag			ft_read(t_flag flag, char *p, va_list ap)
{
	char c;

	c = p[flag.i];
	if (c == 'D' || c == 'd' || c == '%'
			|| c == 'i' || c == 's' || c == 'c'
			|| c == 'C' || c == 'S')
		return (flag = ft_readdsc(flag, p, ap));
	if (c == 'o' || c == 'O')
		return (flag = ft_reado(flag, p, ap));
	if (c == 'x' || c == 'X')
		return (flag = ft_readx(flag, p, ap));
	if (c == 'b' || c == 'U' || c == 'u')
		return (flag = ft_readu(flag, p, ap));
	if (c == 'f' || c == 'F' || c == 'p')
		return (flag = ft_readfp(flag, p, ap));
	if (ft_isalpha(p[flag.i]) == 1)
		flag = ft_errorcheck(flag, p, 1);
	return (flag);
}
