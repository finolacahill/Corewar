/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_fr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:22:32 by yodana            #+#    #+#             */
/*   Updated: 2019/12/23 14:54:58 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_fr(char *s1, char *s2, int i)
{
	char *dest;

	if (!(dest = ft_strjoin(s1, s2)))
		return (NULL);
	if (i == 1)
		ft_strdel(&s1);
	else if (i == 2)
		ft_strdel(&s2);
	else if (i == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (dest);
}
