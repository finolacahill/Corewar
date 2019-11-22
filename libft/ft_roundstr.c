/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:30:37 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/24 02:52:07 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_roundstr(t_flag flag, char *p1, char *p2, int end)
{
	int		i;

	i = ft_strlen(p2);
	flag.test = 0;
	while (i > 0)
	{
		if (p2[i] > '5')
			p2[i - 1] = p2[i - 1] + 1;
		if (p2[i] == '5')
			if (p2[i - 1] % 2 != 0)
				p2[i - 1] = p2[i - 1] + 1;
		--i;
	}
	if (p2[0] >= '5')
	{
		if (p2[0] == '5')
		{
			flag.test = ft_atoi(p1);
			if (flag.test % 2 != 0 || p2[1] > '0')
				p1[end] = p1[end] + 1;
		}
		else
			p1[end] = p1[end] + 1;
	}
	return (p1);
}
