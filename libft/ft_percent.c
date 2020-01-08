/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:35:14 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/24 02:48:44 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_percent(t_flag flag)
{
	int len;

	len = 0;
	if (flag.left == 1)
		flag = ft_buffer(flag, '%');
	while (len++ < flag.width - 1)
	{
		if (flag.zero == 1 && flag.left == 0)
			flag = ft_buffer(flag, '0');
		else
			flag = ft_buffer(flag, ' ');
	}
	if (flag.left == 0)
		flag = ft_buffer(flag, '%');
	flag.i++;
	return (flag);
}
