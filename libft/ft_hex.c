/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:00:54 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:06:49 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_hexflag(t_flag flag, char p)
{
	if (flag.hashtag == 1)
	{
		if (p == 'x')
			flag = ft_putstrb(flag, "0x", -1);
		else
			flag = ft_putstrb(flag, "0X", -1);
		flag.hashtag = 0;
	}
	return (flag);
}

static t_flag	ft_hexwidth(t_flag flag, char p, int len)
{
	if (flag.left == 0 && flag.width > 0)
	{
		if (flag.hashtag == 1 && flag.zero == 1
				&& (len >= flag.width || flag.precision < 0))
			flag = ft_hexflag(flag, p);
		while (len++ < flag.width)
		{
			if (flag.zero == 1 && flag.precision < 0)
				flag = ft_buffer(flag, '0');
			else
				flag = ft_buffer(flag, ' ');
		}
	}
	if (flag.left == 1 && flag.width > 0)
	{
		while (len++ < flag.width)
			flag = ft_buffer(flag, ' ');
	}
	++flag.i;
	return (flag);
}

static t_flag	ft_hexzero(t_flag flag, int len)
{
	int lenb;

	len = 0;
	lenb = 0;
	if (flag.precision > 0)
		lenb = flag.precision;
	if (flag.precision < 0)
		lenb = 1;
	if (flag.left == 1 && flag.precision < 0)
		flag = ft_buffer(flag, '0');
	while (flag.left == 1 && len++ < flag.precision)
		flag = ft_buffer(flag, '0');
	while (lenb++ < flag.width)
	{
		if (flag.left == 0 && flag.zero == 1 && flag.precision < 0)
			flag = ft_buffer(flag, '0');
		else
			flag = ft_buffer(flag, ' ');
	}
	while (flag.left == 0 && len++ < flag.precision)
		flag = ft_buffer(flag, '0');
	if (flag.left == 0 && flag.precision < 0)
		flag = ft_buffer(flag, '0');
	++flag.i;
	return (flag);
}

static int		ft_hexlen(t_flag flag, int prew)
{
	int len;

	len = prew + (flag.hashtag * 2);
	if (len < flag.precision + (flag.hashtag * 2))
		len = flag.precision + (flag.hashtag * 2);
	return (len);
}

t_flag			ft_hex(t_flag flag, char p, char *xval)
{
	int					len;
	int					prew;
	int					preb;

	prew = ft_strlen(xval);
	len = ft_hexlen(flag, prew);
	if (xval[0] == '0' && xval[1] == '\0')
	{
		free(xval);
		return (flag = ft_hexzero(flag, len));
	}
	if (flag.precision < prew)
		preb = prew;
	else
		preb = flag.precision;
	if (flag.left == 0)
		flag = ft_hexwidth(flag, p, len);
	flag = ft_hexflag(flag, p);
	while (prew++ < preb)
		flag = ft_buffer(flag, '0');
	flag = ft_putstrb(flag, xval, preb);
	if (flag.left == 1)
		flag = ft_hexwidth(flag, p, len);
	free(xval);
	return (flag);
}
