/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:48:43 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/14 10:36:41 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libsrcs.h"

size_t	ft_strlen(const char *str)
{
	size_t		c;

	c = 0;
	if (str == NULL)
		return (0);
	while (*str++)
		c++;
	return (c);
}
