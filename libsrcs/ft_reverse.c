/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:06:19 by flafonso          #+#    #+#             */
/*   Updated: 2019/11/14 16:38:39 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libsrcs.h"

void	ft_reverse(char **str)
{
	char	c;
	int		l;
	int		i;

	l = 0;
	i = 0;
	while (str[0][l] != '\0')
		l++;
	l--;
	while (i < l)
	{
		c = str[0][i];
		str[0][i] = str[0][l];
		str[0][l] = c;
		i++;
		l--;
	}
}
