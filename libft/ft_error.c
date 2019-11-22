/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:06:06 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:06:12 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_printerror(t_flag flag, char *p, int i, int len)
{
	while (p[i] == '#' || p[i] == ' ' || p[i] == '*'
			|| p[i] == '-' || p[i] == '+'
			|| (ft_isdigit(p[i]) == 1) || p[i] == '.')
		++i;
	if (p[i] != '\0')
	{
		flag = ft_buffer(flag, p[i]);
		if (flag.left == 1)
		{
			while (len++ < flag.width)
				flag = ft_buffer(flag, ' ');
		}
		while (p[++i] != '\0' && p[i] != '%')
			flag = ft_buffer(flag, p[i]);
	}
	flag.i = i;
	return (flag);
}

static t_flag	ft_errorwidth(t_flag flag, char *p, int i, int len)
{
	if (flag.test == 0 && p[i] == '%')
	{
		if (i > 0)
			if (p[i - 1] == '%')
				flag.test = 1;
		if (p[i + 1] == '\0')
			flag.test = 1;
	}
	if (flag.test == 0 && (++i || 1))
	{
		if (flag.left == 0)
		{
			while (len++ < flag.width)
			{
				if (flag.zero == 1)
					flag = ft_buffer(flag, '0');
				else
					flag = ft_buffer(flag, ' ');
			}
		}
		flag = ft_printerror(flag, p, i, len);
	}
	return (flag);
}

t_flag			ft_errorcheck(t_flag flag, char *p, int len)
{
	int i;

	i = flag.i;
	flag.test = 0;
	while (p[i] != '%' && flag.test == 0 && i != 0)
	{
		if (p[i] == 'l' || p[i] == 'L' || p[i] == 'd')
			flag.test = 1;
		if (p[i] == 'i' || p[i] == 'z' || p[i] == 'j')
			flag.test = 1;
		if (p[i] == 'h' || p[i] == 's' || p[i] == 'c')
			flag.test = 1;
		if (p[i] == 'o' || p[i] == 'p' || p[i] == 'x')
			flag.test = 1;
		if (p[i] == 'X' || p[i] == 'u' || p[i] == 'U')
			flag.test = 1;
		if (p[i] == 'f' || p[i] == 'C' || p[i] == 'O')
			flag.test = 1;
		if (p[i] == 'S' || p[i] == 'F' || p[i] == 'b')
			flag.test = 1;
		--i;
	}
	flag = ft_errorwidth(flag, p, i, len);
	return (flag);
}
