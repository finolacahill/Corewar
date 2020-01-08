/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:12:07 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:12:10 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_printfloat(char *p1, char *p2, t_flag flag, int len)
{
	int end;

	end = ft_strlen(p1) - 1;
	if (flag.plus == 1 && ((flag.left == 1 || flag.zero == 0)
				|| (flag.zero == 1 && flag.width < len)))
		flag = ft_buffer(flag, '+');
	if (flag.precision != 0)
	{
		if (flag.neg == 1)
			flag = ft_buffer(flag, '-');
		flag = ft_putstrb(flag, p1, -1);
		flag = ft_buffer(flag, '.');
		flag = ft_putstrb(flag, p2, -1);
	}
	else
	{
		if (flag.neg == 1)
			flag = ft_buffer(flag, '-');
		p1 = ft_roundstr(flag, p1, p2, end);
		flag = ft_putstrb(flag, p1, -1);
		if (flag.hashtag == 1)
			flag = ft_buffer(flag, '.');
	}
	return (flag);
}
