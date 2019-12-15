/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:02:24 by yodana            #+#    #+#             */
/*   Updated: 2019/03/27 21:49:35 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev_fr(char *str)
{
	char	*new;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	i = ft_strlen(str) - 1;
	j = 0;
	if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	new[ft_strlen(str)] = '\0';
	while (i >= 0)
	{
		new[j] = str[i];
		j++;
		i--;
	}
	ft_strdel(&str);
	return (new);
}