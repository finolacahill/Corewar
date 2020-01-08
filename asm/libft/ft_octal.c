/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:04:24 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:04:28 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_negwidth(t_flag flag, int len, int lenc)
{
	while (len++ < flag.width)
	{
		if (flag.left == 0 && flag.zero == 1 && flag.precision < 0)
			flag = ft_buffer(flag, '0');
		else
			flag = ft_buffer(flag, ' ');
	}
	if (flag.left == 0 && flag.hashtag == 1 && flag.precision == 0)
		flag = ft_buffer(flag, '0');
	if (flag.left == 0 && flag.precision != 0)
	{
		flag = ft_buffer(flag, '0');
		while (lenc++ < flag.precision)
			flag = ft_buffer(flag, '0');
	}
	return (flag);
}

static t_flag	ft_octalneg(t_flag flag)
{
	int len;
	int lenc;

	len = 1;
	lenc = 1;
	if (flag.precision <= 1)
		lenc = lenc + flag.hashtag;
	if (flag.precision == 0)
		len = 0 + flag.hashtag;
	if (len < flag.precision)
		len = flag.precision;
	if (flag.left == 1 && flag.hashtag == 1 && flag.precision == 0)
		flag = ft_buffer(flag, '0');
	if (flag.left == 1 && flag.precision != 0)
	{
		flag = ft_buffer(flag, '0');
		while (lenc++ < flag.precision)
			flag = ft_buffer(flag, '0');
	}
	flag = ft_negwidth(flag, len, lenc);
	++flag.i;
	return (flag);
}

static t_flag	ft_octalwidth(t_flag flag, int len)
{
	while (len++ < flag.width)
	{
		if (flag.zero == 1 && flag.left == 0
				&& (flag.precision < 0))
			flag = ft_buffer(flag, '0');
		else
			flag = ft_buffer(flag, ' ');
	}
	return (flag);
}

static t_flag	ft_printoctal(t_flag flag, char *oval, int prec)
{
	if (flag.hashtag == 1)
		flag = ft_buffer(flag, '0');
	flag = ft_putstrb(flag, oval, prec);
	return (flag);
}

t_flag			ft_octal(t_flag flag, char *oval)
{
	int len;
	int lenb;
	int prec;

	if (oval[0] == '0' && oval[1] == '\0')
		return (flag = ft_octalneg(flag));
	len = ft_strlen(oval) + flag.hashtag;
	prec = flag.precision;
	if (flag.precision < len)
		prec = len;
	lenb = len;
	if (flag.width > flag.precision && flag.precision > len)
		lenb = lenb - flag.hashtag;
	if (flag.precision > len)
		lenb = flag.precision;
	if (flag.left == 0 && flag.width > 0)
		flag = ft_octalwidth(flag, lenb);
	while (len++ < flag.precision)
		flag = ft_buffer(flag, '0');
	flag = ft_printoctal(flag, oval, prec);
	if (flag.left == 1 && flag.width > 0)
		flag = ft_octalwidth(flag, lenb);
	++flag.i;
	return (flag);
}
