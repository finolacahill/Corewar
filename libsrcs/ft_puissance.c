/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puissance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:24:27 by flafonso          #+#    #+#             */
/*   Updated: 2019/06/14 10:38:29 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libsrcs.h"

unsigned long long	ft_puissance(int nbr, int p)
{
	int						i;
	unsigned long long		nb;

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
