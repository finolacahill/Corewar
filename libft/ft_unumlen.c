/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:12:02 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:17:47 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unumlen(unsigned long long int n)
{
	unsigned int count;

	count = 1;
	while ((n = n / 10) != 0)
		++count;
	return ((int)count);
}
