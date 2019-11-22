/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:18:05 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:20:33 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_putstrb(t_flag flag, char const *s, int max)
{
	int i;

	i = 0;
	if (max < 0)
		max = ft_strlen(s);
	if (!s)
		return (flag);
	while (s[i] != '\0' && i < max)
	{
		flag = ft_buffer(flag, s[i]);
		i++;
	}
	return (flag);
}
