/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:00:15 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:11:44 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_zerochar(t_flag flag)
{
	if (flag.x == 0)
		if (!(flag.str = (char *)malloc(sizeof(char) * 4096)))
			return (flag = ft_returnerror(flag));
	flag.str[flag.x] = 0;
	++flag.x;
	return (flag);
}

t_flag			ft_char(t_flag flag, char cval)
{
	int len;

	len = 0;
	if (flag.left == 1 && cval == 0)
		flag = ft_zerochar(flag);
	else if (flag.left == 1)
		flag = ft_buffer(flag, cval);
	while (++len < flag.width)
	{
		if (flag.zero == 1 && flag.left == 0)
			flag = ft_buffer(flag, '0');
		else
			flag = ft_buffer(flag, ' ');
	}
	if (flag.left == 0 && cval == 0)
		flag = ft_zerochar(flag);
	else if (flag.left == 0)
		flag = ft_buffer(flag, cval);
	flag.i++;
	return (flag);
}
