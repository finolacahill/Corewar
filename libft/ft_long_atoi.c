/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:03:23 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/21 13:51:28 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_long_atoi(const char *str)
{
	long i;
	long result;
	long neg;

	i = 0;
	result = 0;
	neg = 1;
	while (ft_isspace(str[i]) != 0)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		++i;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result * neg);
}
