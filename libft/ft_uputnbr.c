/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:18:33 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:17:54 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_uputnbr(t_flag flag, unsigned long long n, int precision)
{
	int					count;
	unsigned long long	limit;

	limit = n;
	if (limit == -9223372036854775808U)
	{
		flag = ft_putstrb(flag, "-9", -1);
		n = 223372036854775808;
	}
	count = ft_unumlen(n);
	while (count++ < precision)
		flag = ft_buffer(flag, '0');
	if (n >= 10)
	{
		count++;
		flag = ft_uputnbr(flag, n / 10, 0);
	}
	flag = ft_buffer(flag, n % 10 + '0');
	return (flag);
}
