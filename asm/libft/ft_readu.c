/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:13:00 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:13:15 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_readb(t_flag flag, char *p, va_list ap)
{
	long long unsigned	oval;
	char				*str;

	if (p[flag.i] == 'b')
	{
		if (flag.ll == 1 || flag.j == 1 || flag.z == 1)
			oval = va_arg(ap, long long unsigned int);
		if (flag.l == 1 && flag.j == 0 && flag.z == 0)
			oval = va_arg(ap, long unsigned int);
		if (flag.h == 1 && flag.j == 0 && flag.z == 0)
			oval = (short unsigned)va_arg(ap, unsigned int);
		if (flag.hh == 1 && flag.j == 0 && flag.z == 0)
			oval = (unsigned char)va_arg(ap, unsigned int);
		else if (flag.ll == 0 && flag.l == 0 && flag.h == 0
				&& flag.hh == 0 && flag.j == 0 && flag.z == 0)
			oval = va_arg(ap, unsigned int);
		if (!(str = ft_uitoa_base(oval, 2, 0)))
			return (flag = ft_returnerror(flag));
		flag = ft_binary(flag, str);
		free(str);
	}
	return (flag);
}

t_flag			ft_readu(t_flag flag, char *p, va_list ap)
{
	unsigned long long	uval;

	if (p[flag.i] == 'u' || p[flag.i] == 'U')
	{
		if (flag.ll == 1 || p[flag.i] == 'U' || flag.j == 1 || flag.z == 1)
			uval = va_arg(ap, unsigned long long int);
		if ((flag.l == 1 || flag.z == 1)
				&& p[flag.i] != 'U' && flag.j == 0 && flag.z == 0)
			uval = va_arg(ap, unsigned long);
		if (flag.h == 1 && p[flag.i] != 'U' && flag.j == 0 && flag.z == 0)
			uval = (unsigned short)va_arg(ap, unsigned int);
		if (flag.hh == 1 && p[flag.i] != 'U' && flag.j == 0 && flag.z == 0)
			uval = (unsigned char)va_arg(ap, unsigned int);
		if (flag.ll == 0 && flag.l == 0 && flag.h == 0
				&& flag.hh == 0 && p[flag.i] != 'U'
				&& flag.j == 0 && flag.z == 0)
			uval = va_arg(ap, unsigned int);
		return (flag = ft_unint(flag, uval));
	}
	if (p[flag.i] == 'b')
		flag = ft_readb(flag, p, ap);
	flag = ft_readb(flag, p, ap);
	return (flag);
}
