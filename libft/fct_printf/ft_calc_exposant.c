/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_exposant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 19:18:34 by yodana            #+#    #+#             */
/*   Updated: 2019/05/27 18:25:38 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_calc_exposant_neg(char *res, int stop, int hold, int i)
{
	int j;

	if (!res)
		return (NULL);
	while (stop-- > 1)
	{
		while (res[i++])
		{
			j = (hold + (res[i] - '0')) / 2;
			if ((res[i] - '0') % 2 == 1)
				hold = 10;
			else
				hold = 0;
			if (j >= 0)
				res[i] = (j % 10 + '0');
		}
		if (hold == 10)
		{
			if (!(res = ft_strjoin_fr(res, "5", 1)))
				return (NULL);
		}
		i = 0;
	}
	return (res);
}

char	*ft_calc_exposant_pos(char *res, int exposant, int i, int hold)
{
	int j;

	while (exposant >= 0)
	{
		while (i >= 0)
		{
			j = (res[i] - '0') * 2;
			if (j >= 0)
				res[i] = (j % 10 + '0') + hold;
			if (j >= 10)
				hold = 1;
			else if (j >= 0)
				hold = 0;
			if (i == 0 && j >= 10)
			{
				if (!(res = ft_strjoin_fr("1", res, 2)))
					return (NULL);
			}
			i--;
		}
		i = ft_strlen(res) - 1;
		hold = 0;
		exposant--;
	}
	return (res);
}

char	*ft_calc_exposant(long double f, char *res, unsigned int exposant)
{
	int i;

	i = ft_strlen(res) - 1;
	if (f < 1 && f > -1)
		res = ft_calc_exposant_neg(res, (exposant - 16383) * -1, 0, 0);
	else
		res = ft_calc_exposant_pos(res, exposant - 16383, i, 0);
	return (res);
}
