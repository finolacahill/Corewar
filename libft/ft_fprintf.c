/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 00:17:35 by yodana            #+#    #+#             */
/*   Updated: 2020/01/06 00:17:49 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fprintf(int fd, char *fmt, ...)
{
	va_list			ap;
	char			*p;
	t_flag			flag;

	if (fd < 0)
		return (-1);
	va_start(ap, fmt);
	p = fmt;
	flag.i = 0;
	flag.ret = 0;
	flag.x = 0;
	while (p[flag.i] != '\0')
	{
		flag.fd = fd;
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
