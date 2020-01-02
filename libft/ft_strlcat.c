/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:09:30 by yodana            #+#    #+#             */
/*   Updated: 2018/11/21 15:55:11 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t size_dst;

	size_dst = ft_strlen(dst);
	if (size <= size_dst)
		return (ft_strlen(src) + size);
	ft_strncat(dst, src, size - size_dst - 1);
	return (ft_strlen(src) + size_dst);
}
