/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:09:51 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:09:54 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_pointprecision(t_flag flag, char *pval, int len)
{
	if (flag.left == 0)
	{
		if (flag.zero == 0 || flag.width <= len + 2 || len == 0)
			flag = ft_putstrb(flag, "0x", -1);
		while (len++ < flag.precision)
			flag = ft_buffer(flag, '0');
		if (flag.zero == 1 && flag.width > 0
				&& flag.precision > len)
			flag = ft_putstrb(flag, "0x", -1);
		flag = ft_putstrb(flag, pval, flag.precision);
	}
	if (flag.left == 1)
	{
		if (flag.hashtag == 1)
			flag = ft_putstrb(flag, "0x", -1);
		while (len++ < flag.precision)
			flag = ft_buffer(flag, '0');
		flag = ft_putstrb(flag, pval, flag.precision);
		len++;
	}
	return (flag);
}

static t_flag	ft_pointwidth(t_flag flag, int len, char *pval)
{
	if (pval[0] == '0' && pval[1] == '\0'
			&& flag.precision > len - 2)
		len = flag.precision + 2;
	while (len++ < flag.width)
	{
		if (flag.zero == 1 && flag.left == 0)
		{
			if (flag.left == 0 && flag.hashtag == 1)
			{
				flag = ft_putstrb(flag, "0x", -1);
				flag.hashtag = 0;
			}
			flag = ft_buffer(flag, '0');
		}
		else
			flag = ft_buffer(flag, ' ');
	}
	return (flag);
}

t_flag			ft_point(t_flag flag, char *pval)
{
	int len;

	len = ft_strlen(pval);
	flag.hashtag = 1;
	if (flag.precision >= 0 && flag.precision <= len)
		flag.zero = 0;
	if (flag.precision < len && (flag.precision != 0
				|| (pval[0] != '0' || pval[1] != '\0')))
		flag.precision = len;
	if (pval[0] == '0' && pval[1] == '\0')
	{
		if (flag.precision == 0)
			len = 0;
	}
	if (flag.precision > len)
		flag.zero = 0;
	if (flag.left == 1)
		flag = ft_pointprecision(flag, pval, len);
	flag = ft_pointwidth(flag, len + 2, pval);
	if (flag.left == 0)
		flag = ft_pointprecision(flag, pval, len);
	flag.i++;
	return (flag);
}
