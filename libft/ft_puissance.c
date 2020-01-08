/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puissance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:24:27 by flafonso          #+#    #+#             */
/*   Updated: 2019/11/29 18:55:31 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_puissance(int nbr, int p)
{
	int			i;
	long 		nb;

	i = 1;
	nb = nbr;
	if (p == 0)
		return (1);
	if (p == 1)
		return (nb);
	while (i < p)
	{
		nb = nbr * nb;
		i++;
	}
	return (nb);
}
