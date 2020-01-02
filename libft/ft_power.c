/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 01:22:13 by yodana            #+#    #+#             */
/*   Updated: 2019/06/11 01:22:22 by yodana           ###   ########.fr       */
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
