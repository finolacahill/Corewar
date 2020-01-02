/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:51:46 by yodana            #+#    #+#             */
/*   Updated: 2018/11/05 20:10:25 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int resultat;

	resultat = 1;
	if (nb <= 0)
		return (0);
	while (resultat * resultat <= nb)
	{
		if (resultat * resultat == nb)
			return (resultat);
		resultat++;
	}
	return (0);
}
