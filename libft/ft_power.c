/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 00:18:13 by yodana            #+#    #+#             */
/*   Updated: 2020/01/06 00:18:22 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_power(double nbr, double power)
{
	int		i;
	double	res;

	res = 1;
	i = 1;
	while (i <= power)
	{
		res = res * nbr;
		i++;
	}
	return (res);
}
