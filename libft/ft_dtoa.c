/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:58:05 by yodana            #+#    #+#             */
/*   Updated: 2019/05/27 18:58:07 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dtoa(long double m, int size)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	j = 0;
	if (!(res = ft_strnew(size)))
		return (NULL);
	j = (int)m;
	while (i != size)
	{
		if (i == 1)
		{
			res[i] = '.';
			i++;
		}
		res[i] = j + '0';
		m = m - j;
		m = m * 10;
		j = (int)m;
		i++;
	}
	return (res);
}
