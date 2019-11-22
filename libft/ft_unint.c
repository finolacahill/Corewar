/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:17:38 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:17:40 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_unwidth(t_flag flag, int len)
{
	if (flag.width > 0)
		while (len++ < flag.width)
		{
			if (flag.zero == 1 && flag.left == 0
					&& flag.precision < 0)
				flag = ft_buffer(flag, '0');
			else
				flag = ft_buffer(flag, ' ');
		}
	return (flag);
}

t_flag			ft_unint(t_flag flag, unsigned long long uval)
{
	int len;
	int prec;

	len = ft_unumlen(uval);
	if (flag.precision == 0 && uval == 0)
		len = 0;
	prec = flag.precision;
	if (flag.precision < len &&
			(uval != 0 || flag.precision != 0))
		prec = len;
	if (flag.precision > len)
		len = flag.precision;
	if (flag.left == 1 && prec != 0)
		flag = ft_uputnbr(flag, uval, prec);
	flag = ft_unwidth(flag, len);
	if (flag.left == 0 && (uval != 0 || prec != 0))
		flag = ft_uputnbr(flag, uval, prec);
	flag.i++;
	return (flag);
}
