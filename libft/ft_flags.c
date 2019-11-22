/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:00:35 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:06:19 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_flags2(t_flag flag, char *p, va_list ap)
{
	if (p[flag.i] == '*')
	{
		flag.width = va_arg(ap, int);
		if (flag.width < 0)
		{
			flag.width = -flag.width;
			flag.left = 1;
		}
	}
	if (p[flag.i] == '.' && (++flag.i || 1))
	{
		flag.precision = 0;
		if (p[flag.i] == '*' && (++flag.i || 1))
			flag.precision = va_arg(ap, int);
		else
		{
			flag.precision = ft_atoi(&p[flag.i]);
			while (ft_isdigit(p[flag.i]) == 1)
				++flag.i;
		}
		return (flag);
	}
	++flag.i;
	return (flag);
}

static t_flag	ft_flags(t_flag flag, char *p, va_list ap)
{
	while (p[flag.i] != '%' && ft_isalpha(p[flag.i]) == 0
			&& p[flag.i] != '\0' && p[flag.i] != '\n')
	{
		if (p[flag.i] == '-')
			flag.left = 1;
		if (p[flag.i] == '+')
			flag.plus = 1;
		if (p[flag.i] == '0')
			flag.zero = 1;
		if (p[flag.i] == '#')
			flag.hashtag = 1;
		if (p[flag.i] == ' ')
			flag.space = 1;
		if (p[flag.i] != '0' && ft_isdigit(p[flag.i]) == 1)
		{
			flag.width = ft_atoi(&p[flag.i]);
			while (ft_isdigit(p[flag.i]) == 1)
				++flag.i;
			continue ;
		}
		flag = ft_flags2(flag, p, ap);
		if (p[flag.i] == '\0' || p[flag.i] == '\n')
			flag = ft_errorcheck(flag, p, 1);
	}
	return (flag);
}

static t_flag	ft_initialiseflags(t_flag flag)
{
	flag.left = 0;
	flag.width = -1;
	flag.precision = -1;
	flag.plus = 0;
	flag.zero = 0;
	flag.hashtag = 0;
	flag.space = 0;
	flag.l = 0;
	flag.ll = 0;
	flag.h = 0;
	flag.hh = 0;
	flag.neg = 0;
	flag.j = 0;
	flag.z = 0;
	return (flag);
}

t_flag			ft_readflags(t_flag flag, char *p, va_list ap)
{
	while (p[flag.i] != '%' && p[flag.i] != '\0')
	{
		flag = ft_buffer(flag, p[flag.i]);
		++flag.i;
	}
	if (p[flag.i] != '\0' && (++flag.i || 1))
	{
		flag = ft_initialiseflags(flag);
		flag = ft_specifiers(flag, p);
		flag = ft_flags(flag, p, ap);
	}
	return (flag);
}
