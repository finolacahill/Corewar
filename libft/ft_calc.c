/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:13:41 by yodana            #+#    #+#             */
/*   Updated: 2019/06/11 18:19:58 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_calc_octa(long long nbr)
{
	char				*res;
	char				*c;
	unsigned long long	i;

	i = nbr;
	c = ft_strnew(1);
	res = ft_strnew(1);
	if (i == 0)
		res = ft_strjoin_fr("0", res, 2);
	while (i >= 1)
	{
		c[0] = (i % 8) + '0';
		res = ft_strjoin_fr(c, res, 2);
		i = i / 8;
	}
	ft_strdel(&c);
	return (res);
}

char	*ft_calc_long_hexam(long long nbr)
{
	char				*res;
	char				*c;
	unsigned long long	i;

	i = nbr;
	c = ft_strnew(1);
	res = ft_strnew(0);
	if (i == 0)
		res = ft_strjoin_fr("0", res, 2);
	while (i >= 1)
	{
		if (i % 16 >= 10)
			c[0] = (55 + (i % 16));
		else
			c[0] = (i % 16) + '0';
		res = ft_strjoin_fr(c, res, 2);
		i = i / 16;
	}
	ft_strdel(&c);
	return (res);
}

char	*ft_calc_long_hexa(long long nbr)
{
	char				*res;
	char				*c;
	unsigned long long	i;

	i = nbr;
	c = ft_strnew(1);
	res = ft_strnew(0);
	if (i == 0)
		res = ft_strjoin_fr("0", res, 2);
	while (i >= 1)
	{
		if (i % 16 >= 10)
			c[0] = (87 + (i % 16));
		else
			c[0] = (i % 16) + '0';
		res = ft_strjoin_fr(c, res, 2);
		i = i / 16;
	}
	ft_strdel(&c);
	return (res);
}

char	*ft_calc_hexa(unsigned long nbr)
{
	char				*res;
	char				*c;
	unsigned long long	i;

	i = nbr;
	c = ft_strnew(1);
	res = ft_strnew(0);
	if (i == 0)
		res = ft_strjoin_fr("0", res, 2);
	while (i >= 1)
	{
		if (i % 16 >= 10)
			c[0] = (87 + (i % 16));
		else
			c[0] = (i % 16) + '0';
		res = ft_strjoin_fr(c, res, 2);
		i = i / 16;
	}
	ft_strdel(&c);
	return (res);
}
