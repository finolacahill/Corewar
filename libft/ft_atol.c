/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:54:27 by fcahill           #+#    #+#             */
/*   Updated: 2019/07/29 12:54:41 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atol(const char *str)
{
	long long i;
	long long result;
	long long neg;

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
