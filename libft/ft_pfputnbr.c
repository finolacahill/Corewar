/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfputnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:30:34 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/12 12:30:36 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_pfputnbr(t_flag flag, long long n, int precision)
{
	int					count;
	unsigned long long	limit;

	limit = n;
	if (n == 0 && precision == 0)
		return (flag = ft_buffer(flag, ' '));
	if (limit == -9223372036854775808U)
	{
		flag = ft_putstrb(flag, "-9", -1);
		n = 223372036854775808;
	}
	if (n < 0)
	{
		flag = ft_buffer(flag, '-');
		n = -n;
	}
	count = ft_numlen(n);
	while (count++ < precision)
		flag = ft_buffer(flag, '0');
	if (n >= 10)
		flag = ft_pfputnbr(flag, n / 10, 0);
	flag = ft_buffer(flag, n % 10 + '0');
	return (flag);
}
