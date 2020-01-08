/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puissance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:24:27 by flafonso          #+#    #+#             */
/*   Updated: 2019/11/29 18:55:31 by flafonso         ###   ########.fr       */
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
