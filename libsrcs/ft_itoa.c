/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:46:39 by flafonso          #+#    #+#             */
/*   Updated: 2019/11/09 14:05:13 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libsrcs.h"

static int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static int		ft_signe(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static int		ft_nbrlen(int n_cpy)
{
	int		nbrlen;

	nbrlen = 0;
	if (n_cpy < 0)
		n_cpy = -n_cpy;
	if (n_cpy == 0)
		return (1);
	while (n_cpy != 0)
	{
		n_cpy = n_cpy / 10;
		nbrlen++;
	}
	return (nbrlen);
}

static void		ft_plusdeplace(char *nbr, int n, int nbrlen, int signe)
{
	if (n == 0)
		nbr[nbrlen] = '0';
	while (n != 0)
	{
		nbr[nbrlen] = (n % 10) + 48;
		n = n / 10;
		nbrlen++;
	}
	if (signe == 1)
		nbr[nbrlen] = '-';
	nbr[nbrlen + 1] = '\0';
}

char			*ft_itoa(int n)
{
	char	*nbr;
	int		nbrlen;
	int		signe;

	signe = ft_signe(n);
	if (n == -2147483648)
	{
		if (!(nbr = ft_strnew(12)))
			return (NULL);
		n = 214748364;
		nbr[0] = '8';
		nbrlen = 1;
	}
	else
	{
		n = ft_abs(n);
		nbrlen = ft_nbrlen(n);
		if (!(nbr = ft_strnew(nbrlen + signe + 1)))
			return (NULL);
		nbrlen = 0;
	}
	ft_plusdeplace(nbr, n, nbrlen, signe);
	ft_reverse(&nbr);
	return (nbr);
}
