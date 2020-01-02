/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 03:17:51 by yodana            #+#    #+#             */
/*   Updated: 2019/05/28 04:02:43 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_put_space(char *res, int d, int size, t_conv *lst_fct)
{
	char *c;

	c = ft_strnew(1);
	if (ft_strchr(lst_fct->attribut, '0') != NULL && lst_fct->type == '%')
		c[0] = '0';
	else
		c[0] = ' ';
	while (res && (d > size && ft_strrchr(lst_fct->attribut, '-') == NULL))
	{
		res = ft_strjoin_fr(c, res, 2);
		d--;
	}
	while (res && (d > size && ft_strrchr(lst_fct->attribut, '-') != NULL))
	{
		res = ft_strjoin_fr(res, c, 1);
		size++;
	}
	if (ft_strchr(lst_fct->attribut, ' ') && lst_fct->type == 'd'
		&& size == 0 && lst_fct->precision == 1)
		res = ft_strjoin_fr(res, " ", 1);
	ft_strdel(&c);
	return (res);
}

char	*ft_space(long long i, t_conv *lst_fct, int size)
{
	char *res;

	res = ft_strdup(lst_fct->final);
	if (res && ft_check_u(lst_fct->type) != -1 && ((ft_strrchr(lst_fct->attribut
			, ' ') && res[0] != '\0')) && i >= 0 && !(ft_strrchr(lst_fct->final
				, '-') && lst_fct->type != '%'))
	{
		res = ft_strjoin_fr(" ", res, 2);
		if (res && lst_fct->type == 'f')
		{
			ft_strdel(&lst_fct->final);
			lst_fct->final = ft_strdup(res);
		}
		size++;
	}
	if ((ft_strrchr(lst_fct->attribut, '-') == NULL
		&& (ft_strrchr(lst_fct->attribut, '0') != NULL && lst_fct->type != '%'))
			&& (lst_fct->precision < 1 || lst_fct->type == 'f'))
	{
		ft_strdel(&res);
		return (lst_fct->final);
	}
	res = ft_put_space(res, lst_fct->champ, size, lst_fct);
	ft_strdel(&lst_fct->final);
	return (res);
}

char	*ft_plus(t_conv *lst_fct)
{
	if (lst_fct->final == 0 && lst_fct->precision == 1)
	{
		ft_strdel(&lst_fct->final);
		lst_fct->final = ft_strdup("+");
		return (lst_fct->final);
	}
	lst_fct->final = ft_strjoin_fr("+", lst_fct->final, 2);
	return (lst_fct->final);
}

char	*ft_hachtag(long long i, t_conv *lst_fct)
{
	if (lst_fct->type == 'o' && (i != 0 || ft_strlen(lst_fct->final) == 0))
		lst_fct->final = ft_strjoin_fr("0", lst_fct->final, 2);
	if (lst_fct->type == 'x' && i != 0)
		lst_fct->final = ft_strjoin_fr("0x", lst_fct->final, 2);
	if (lst_fct->type == 'X' && i != 0)
		lst_fct->final = ft_strjoin_fr("0X", lst_fct->final, 2);
	if (lst_fct->type == 'f' && lst_fct->precision <= 1)
		lst_fct->final = ft_strjoin_fr(lst_fct->final, ".", 1);
	return (lst_fct->final);
}

char	*ft_attribut(long long i, t_conv *lst_fct)
{
	if (lst_fct->type == 'f' || lst_fct->type == 'e')
		lst_fct->precision--;
	if (lst_fct->final != NULL
		&& lst_fct->precision != 0 && (lst_fct->type != 'f'
			&& lst_fct->type != 'e'))
		lst_fct->final = ft_precision(i, lst_fct, 0, ft_strlen(lst_fct->final));
	if (lst_fct->final != NULL && ft_strrchr(lst_fct->attribut, '+')
			&& i >= 0 && ft_strrchr(lst_fct->final, '-') == NULL
				&& ft_check_u(lst_fct->type) != -1)
		lst_fct->final = ft_plus(lst_fct);
	if (lst_fct->final != NULL && ft_strrchr(lst_fct->attribut, '#') != NULL)
		lst_fct->final = ft_hachtag(i, lst_fct);
	if (lst_fct->final != NULL && ((ft_strrchr(lst_fct->attribut, ' ') != NULL
				&& ft_strrchr(lst_fct->attribut, '+') == NULL)
					|| lst_fct->champ != 0))
		lst_fct->final = ft_space(i, lst_fct, ft_strlen(lst_fct->final));
	if (lst_fct->final != NULL && ft_strrchr(lst_fct->attribut, '0')
			&& (lst_fct->precision < 1 || lst_fct->type == 'f')
				&& ft_strrchr(lst_fct->attribut, '-') == NULL)
		lst_fct->final = ft_zero(i, lst_fct, 0, ft_strlen(lst_fct->final));
	return (lst_fct->final);
}
