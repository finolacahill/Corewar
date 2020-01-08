/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:10:33 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:44:26 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_buffer(t_flag flag, char c)
{
	if (flag.x == 0 && flag.ret != -1)
		if (!(flag.str = (char *)malloc(sizeof(char) * 1000)))
			return (flag = ft_returnerror(flag));
	if (flag.ret != -1)
	{
		if (c != '\0')
		{
			flag.str[flag.x] = c;
			++flag.x;
		}
		if (flag.x == 1000 || c == '\0')
		{
			write(flag.fd, flag.str, flag.x);
			flag.ret = flag.ret + flag.x;
			flag.x = 0;
			free(flag.str);
		}
	}
	return (flag);
}
