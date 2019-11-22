/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:16:33 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:16:45 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_nullstr(t_flag flag, int len)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 7)))
		return (flag = ft_returnerror(flag));
	str = ft_strcpy(str, "(null)");
	if (flag.precision >= 0 && flag.precision < len)
		len = flag.precision;
	if (flag.left == 1)
		flag = ft_putstrb(flag, str, flag.precision);
	while (len++ < flag.width)
	{
		if (flag.left == 0 && flag.zero)
			flag = ft_buffer(flag, '0');
		else
			flag = ft_buffer(flag, ' ');
	}
	if (flag.left == 0)
		flag = ft_putstrb(flag, str, flag.precision);
	++flag.i;
	free(str);
	return (flag);
}

t_flag			ft_str(t_flag flag, char *sval)
{
	int len;

	if (sval == NULL)
		return (flag = ft_nullstr(flag, 6));
	len = ft_strlen(sval);
	if (flag.precision >= 0 && len > flag.precision)
		len = flag.precision;
	if (flag.left == 1 && (++flag.i || 1))
		flag = ft_putstrb(flag, sval, flag.precision);
	while (len++ < flag.width)
	{
		if (flag.zero == 1 && flag.left == 0)
			flag = ft_buffer(flag, '0');
		else
			flag = ft_buffer(flag, ' ');
	}
	if (flag.left == 0 && (++flag.i || 1))
		flag = ft_putstrb(flag, sval, flag.precision);
	return (flag);
}
