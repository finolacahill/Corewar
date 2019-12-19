/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:17:31 by yodana            #+#    #+#             */
/*   Updated: 2019/12/19 17:19:03 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

int		dec_to_hexa(int i)
{
	char	*itoa;
	int		res;

	itoa = ft_uitoa_base(i, 16, 0);
	res = ft_strtol(itoa, 16, 2);
	ft_strdel(&itoa);
	return (res);
}

int		ft_strtol(char *str, int base, int size)
{
	int i;
	int res;
	int c;

	i = 0;
	c = 0;
	res = 0;
	while (str[i] && i < size)
	{
		if (ft_isalpha(str[i]) == 1)
			c = str[i] - ('a' - 10);
		else if (ft_isdigit(str[i]) == 1)
			c = str[i] - '0';
		res = res * base;
		res = res + c;
		i++;
	}
	return (res);
}

int		bi_to_dec(char *bi)
{
	int i;
	int len;
	int res;

	res = 0;
	i = 0;
	while (bi[i] && bi[i] == '0')
		i++;
	len = ft_strlen(&bi[i]) - 1;
	while (len >= 0)
	{
		if (bi[i] == '1')
			res = res + ft_power(2, len);
		i++;
		len--;
	}
	return (res);
}
