/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:42:44 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/23 17:07:23 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_factorial(int nb)
{
	if ((nb < 0 || nb > 12))
		return (0);
	if ((nb == 0 || nb == 1))
		return (1);
	return (nb * ft_factorial(nb - 1));
}
