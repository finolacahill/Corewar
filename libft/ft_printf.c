/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:10:12 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:10:15 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *fmt, ...)
{
	va_list			ap;
	char			*p;
	t_flag			flag;

	va_start(ap, fmt);
	p = fmt;
	flag.i = 0;
	flag.ret = 0;
	flag.x = 0;
	while (p[flag.i] != '\0')
	{
		flag = ft_readflags(flag, p, ap);
		flag = ft_specifiers(flag, p);
		if (p[flag.i] != '\0')
			flag = ft_read(flag, p, ap);
		if (flag.ret == -1)
			return (flag.ret);
	}
	flag = ft_buffer(flag, p[flag.i]);
	va_end(ap);
	return (flag.ret);
}
