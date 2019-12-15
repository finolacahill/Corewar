/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:05:37 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:05:40 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_zerowidth(t_flag flag, int len, int lenc)
{
	while (len++ < flag.width)
	{
		if (flag.left == 0 && flag.zero == 1 && flag.precision < 0)
			flag = ft_buffer(flag, '0');
		else
			flag = ft_buffer(flag, ' ');
	}
	if (flag.left == 0 && flag.precision != 0)
	{
		flag = ft_buffer(flag, '0');
		while (lenc++ < flag.precision)
			flag = ft_buffer(flag, '0');
	}
	return (flag);
}

static t_flag	ft_bizero(t_flag flag)
{
	int len;
	int lenc;

	len = 1;
	lenc = 1;
	if (flag.precision == 0)
		len = 0;
	if (len < flag.precision)
		len = flag.precision;
	if (flag.left == 1)
	{
		flag = ft_buffer(flag, '0');
		while (lenc++ < flag.precision)
			flag = ft_buffer(flag, '0');
	}
	flag = ft_zerowidth(flag, len, lenc);
	++flag.i;
	return (flag);
}

static t_flag	ft_biwidth(t_flag flag, int len)
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

t_flag			ft_binary(t_flag flag, char *oval)
{
	int len;
	int lenb;
	int prec;

	if (oval[0] == '0' && oval[1] == '\0')
		return (flag = ft_bizero(flag));
	len = ft_strlen(oval);
	prec = flag.precision;
	if (flag.precision < len)
		prec = len;
	lenb = len;
	if (flag.precision > len)
		lenb = flag.precision;
	if (flag.left == 0 && flag.width > 0)
		flag = ft_biwidth(flag, lenb);
	while (len++ < flag.precision)
		flag = ft_buffer(flag, '0');
	flag = ft_putstrb(flag, oval, prec);
	if (flag.left == 1 && flag.width > 0)
		flag = ft_biwidth(flag, lenb);
	++flag.i;
	return (flag);
}
