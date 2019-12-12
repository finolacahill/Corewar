/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:38:37 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/14 10:36:50 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libsrcs.h"

char	*ft_strnew(size_t size)
{
	char	*tab;

	if (!(tab = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(tab, size + 1);
	return (tab);
}
