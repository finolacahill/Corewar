/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:02:26 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:07:01 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag	ft_intwidth(t_flag flag, long long ival, int len)
{
	if (ival == 0 && flag.precision == 0)
		len = 0;
	if (flag.width > 0)
	{
		while (len++ < flag.width - flag.plus - flag.space)
		{
			if (flag.zero == 1 && flag.left == 0 && flag.precision < 0)
			{
				if (ival < 0)
				{
					flag = ft_buffer(flag, '-');
					ival = -ival;
					flag.neg = 1;
				}
				flag = ft_buffer(flag, '0');
			}
			else
				flag = ft_buffer(flag, ' ');
		}
	}
	return (flag);
}

static t_flag	ft_intplus(t_flag flag, long long ival)
{
	if (ival >= 0 && (flag.plus == 1 || flag.space == 1))
	{
		if (flag.plus == 0)
			if (flag.left == 1
					|| (flag.left == 0 && flag.zero == 1 && flag.width > 0))
				flag = ft_buffer(flag, ' ');
		if ((flag.plus == 1 && flag.width > 0 && flag.zero == 1 && ival != 0
					&& (flag.precision < 0 || (flag.precision > ft_numlen(ival)
							&& flag.precision >= flag.width)))
				|| (flag.plus == 1 && ival == 0 && flag.precision < 0
					&& flag.zero == 1 && flag.width > 0))
			flag = ft_buffer(flag, '+');
		else if (flag.plus == 1 && flag.left == 1)
			flag = ft_buffer(flag, '+');
	}
	if (flag.left == 0 && flag.space == 1
			&& ival < 0 && flag.width > ft_numlen(ival))
		flag = ft_buffer(flag, ' ');
	if (flag.left == 1 && (ival != 0 || flag.precision != 0))
		flag = ft_pfputnbr(flag, ival, flag.precision);
	if (flag.left == 1 && flag.space == 1
			&& ival < 0 && flag.width >= ft_numlen(ival))
		flag = ft_buffer(flag, ' ');
	return (flag);
}

static t_flag	ft_intflag(t_flag flag, long long ival)
{
	if (flag.left == 0 && ival >= 0
			&& (flag.plus == 1 || flag.space == 1))
	{
		if (flag.plus == 0 && (flag.zero == 0 || flag.width < 0))
			flag = ft_buffer(flag, ' ');
		else if (flag.plus == 1 && ((flag.width > 0 && flag.zero == 0)
					|| (flag.width <= 0) || (flag.zero == 1
						&& ival == 0 && flag.precision >= 0)
					|| (flag.zero == 1 & ival > 0 &&
						flag.precision <= ft_numlen(ival)
						&& flag.precision >= 0)
					|| (flag.zero == 1 && flag.precision > ft_numlen(ival)
						&& flag.precision < flag.width)))
			flag = ft_buffer(flag, '+');
	}
	if (flag.neg == 1)
		ival = -ival;
	if (flag.left == 0 && (ival != 0 ||
				(ival == 0 && flag.precision != 0)
				|| (ival != 0 && flag.zero == 1 && flag.width > 0)))
		flag = ft_pfputnbr(flag, ival, flag.precision);
	flag.i++;
	return (flag);
}

static t_flag	ft_intneg(t_flag flag, long long ival)
{
	if (ival < 0 && flag.left == 0)
	{
		if (flag.precision >= ft_numlen(ival))
		{
			if (flag.width > 0 && flag.width > ft_numlen(ival)
					&& flag.zero == 0)
				--flag.width;
		}
	}
	if (ival < 0 && flag.precision > 0)
	{
		if (flag.left == 1
				&& flag.precision >= ft_numlen(ival))
			--flag.width;
		if (flag.zero == 1 && flag.left == 0)
		{
			ival = -ival;
			if (flag.precision > ft_numlen(ival))
				--flag.width;
		}
	}
	return (flag);
}

t_flag			ft_int(t_flag flag, long long ival)
{
	int		len;

	len = ft_numlen(ival);
	if (ival < 0)
		flag.plus = 0;
	if (ival < 0 || (flag.plus == 1 && flag.space == 1))
		flag.space = 0;
	if (flag.precision > len)
		len = flag.precision;
	flag = ft_intplus(flag, ival);
	flag = ft_intneg(flag, ival);
	flag = ft_intwidth(flag, ival, len);
	flag = ft_intflag(flag, ival);
	return (flag);
}
