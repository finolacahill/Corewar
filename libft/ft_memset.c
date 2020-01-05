/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:19:08 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/12 16:24:45 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	j;

	i = 0;
	j = c;
	str = b;
	while (i < len)
	{
		str[i] = c;
		++i;
	}
	return (void*)(b);
}
