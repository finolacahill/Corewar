/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:16:09 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:16:13 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_spechjz(t_flag flag, char *p)
{
	if (p[flag.i] == 'h')
	{
		if (p[flag.i + 1] == 'h')
		{
			flag.hh = 1;
			flag.i++;
		}
		else
			flag.h = 1;
		++flag.i;
	}
	if (p[flag.i] == 'j')
	{
		flag.j = 1;
		++flag.i;
	}
	if (p[flag.i] == 'z')
	{
		flag.z = 1;
		++flag.i;
	}
	return (flag);
}

t_flag			ft_specifiers(t_flag flag, char *p)
{
	if (p[flag.i] == 'l' || p[flag.i] == 'L' || p[flag.i] == 'h'
			|| p[flag.i] == 'R' || p[flag.i] == 'Y' || p[flag.i] == 'B'
			|| p[flag.i] == 'V' || p[flag.i] == 'j' || p[flag.i] == 'z')
	{
		flag.l = 0;
		flag.ll = 0;
		flag.h = 0;
		flag.hh = 0;
		if ((p[flag.i] == 'l' || p[flag.i] == 'L') && (++flag.i || 1))
		{
			if (p[flag.i] == 'l' && (++flag.i || 1))
				flag.ll = 1;
			else
				flag.l = 1;
		}
		flag = ft_spechjz(flag, p);
	}
	return (flag);
}
