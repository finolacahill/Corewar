/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:19:46 by yodana            #+#    #+#             */
/*   Updated: 2019/06/11 00:40:42 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_sup_zero(char *res, int precision)
{
	char	*new;
	int		i;
	int		comma;

	comma = ft_calc_comma(res);
	i = precision;
	while (res[i] == '0' && res[i] != '.')
		i--;
	if (res[i] == '.')
		i--;
	new = ft_strsub(res, 0, i + 1);
	ft_strdel(&res);
	return (new);
}

int		ft_conv_b(t_conv *lst_fct, va_list args, int flags)
{
	t_float		d1;
	int			size;

	d1.f = flags == FL ? va_arg(args, long double) : va_arg(args, double);
	lst_fct->final = ft_i_to_bi(d1.parts.m);
	lst_fct->final = ft_sup_zero(lst_fct->final, ft_strlen(lst_fct->final));
	ft_putstr(lst_fct->final);
	size = ft_strlen(lst_fct->final);
	ft_strdel(&lst_fct->final);
	return (size);
}
