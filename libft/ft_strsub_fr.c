/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_fr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 01:23:11 by yodana            #+#    #+#             */
/*   Updated: 2019/06/11 01:24:15 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_fr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	new = ft_strsub(s, start, len);
	ft_strdel((char**)&s);
	return (new);
}
