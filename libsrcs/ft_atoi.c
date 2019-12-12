/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:48:42 by flafonso          #+#    #+#             */
/*   Updated: 2019/11/14 16:38:17 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libsrcs.h"

int		ft_try(char chiffre, int value)
{
	unsigned long	test;

	test = 0;
	test = (test * 10) + (chiffre - 48);
	if (test > 2147483647)
		return (-1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int				i;
	int				s;
	int				nb;

	i = 0;
	s = 1;
	nb = 0;
	while (ft_isspace((int)str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (ft_isdigit((int)str[i]) == 1)
	{
		if (ft_try(str[i], nb) == -1)
			return (-1);
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * s);
}
