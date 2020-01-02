/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 02:06:09 by yodana            #+#    #+#             */
/*   Updated: 2019/05/28 02:07:12 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check_u(char c)
{
	if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (-1);
	return (1);
}

char	*ft_fill_attribut(void)
{
	char *tab;

	if (!(tab = ft_strnew(6)))
		return (NULL);
	tab[0] = '#';
	tab[1] = '0';
	tab[2] = '-';
	tab[3] = '+';
	tab[4] = ' ';
	tab[5] = '\0';
	return (tab);
}
