/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 14:52:11 by yodana            #+#    #+#             */
/*   Updated: 2019/12/23 14:52:19 by yodana           ###   ########.fr       */
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
