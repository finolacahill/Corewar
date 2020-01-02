/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 04:20:01 by yodana            #+#    #+#             */
/*   Updated: 2019/06/11 18:14:13 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_add_forget(char *res, t_conv *lst_fct, long long i)
{
	if (res && (i < 0 || ft_strrchr(lst_fct->final, '-') != NULL))
		res = ft_strjoin_fr("-", res, 2);
	if (res && (ft_strrchr(lst_fct->attribut, ' ') && i >= 0
				&& ft_strrchr(lst_fct->final, '-') == NULL))
		res = ft_strjoin_fr(" ", res, 2);
	if (res && (ft_strrchr(lst_fct->attribut, '+') && i >= 0
				&& ft_strrchr(lst_fct->final, '-') == NULL))
		res = ft_strjoin_fr("+", res, 2);
	if (res && ((lst_fct->type == 'x' || lst_fct->type == 'X')
				&& ft_strrchr(lst_fct->attribut, '#')))
	{
		if (lst_fct->type == 'x')
			res = ft_strjoin_fr("0x", res, 2);
		else
			res = ft_strjoin_fr("0X", res, 2);
	}
	return (res);
}

char	*ft_zero(long long i, t_conv *lst_fct, int d, int size)
{
	char	*res;

	res = ft_strdup(lst_fct->final);
	while (res && (lst_fct->final[d] == ' ' || lst_fct->final[d] == '+'
				|| lst_fct->final[d] == '-'))
	{
		d++;
		res = ft_strsub_fr(res, d, size);
	}
	if (res && ((lst_fct->type == 'x' || lst_fct->type == 'X')
				&& ft_strrchr(lst_fct->attribut, '#') != NULL))
	{
		d = 1;
		res = ft_strsub_fr(res, 2, size);
	}
	while (res && (size < lst_fct->precision || size < lst_fct->champ))
	{
		res = ft_strjoin_fr("0", res, 2);
		size++;
	}
	res = ft_add_forget(res, lst_fct, i);
	ft_strdel(&lst_fct->final);
	return (res);
}

char	*ft_precision(long long i, t_conv *lst_fct, int d, int size)
{
	char *res;

	if (i == 0 && lst_fct->precision == 1)
		return (ft_strdup(""));
	if (ft_strrchr(lst_fct->attribut, '#') && i != 0 && lst_fct->type == 'o')
		size++;
	if (i < 0)
		size--;
	while (lst_fct->final[d] == ' ' || lst_fct->final[d] == '+'
			|| lst_fct->final[d] == '-')
	{
		d++;
		res = ft_strsub(lst_fct->final, d, size);
	}
	if (d == 0)
		res = ft_strdup(lst_fct->final);
	while (res && (size < lst_fct->precision - 1))
	{
		res = ft_strjoin_fr("0", res, 2);
		size++;
	}
	if (res && (i < 0 && ft_strrchr(lst_fct->final, '-') != NULL))
		res = ft_strjoin_fr("-", res, 2);
	ft_strdel(&lst_fct->final);
	return (res);
}
