/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 00:42:20 by yodana            #+#    #+#             */
/*   Updated: 2019/06/11 00:42:49 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check_number(char *res)
{
	int i;
	int size;

	i = 0;
	if (res == NULL)
		return (-1);
	size = (int)ft_strlen(res);
	while (i <= size && (res[i] == '0' || res[i] == '.'))
		i++;
	if (i == size)
		return (-1);
	return (i);
}

char	*ft_calc_float(char *m_2, t_conv *lst_fct, t_float d1)
{
	char		*r;

	r = ft_bi_to_dec(m_2, 0, 1, 66 + lst_fct->precision);
	r = ft_calc_exposant(d1.f, r, d1.parts.e);
	lst_fct->final = ft_print_float(r, lst_fct, 0, ft_calc_comma(r));
	if (d1.parts.sign == 1)
		lst_fct->final = ft_strjoin_fr("-", lst_fct->final, 2);
	if (lst_fct->type == 'e')
		lst_fct->final = ft_scientific(lst_fct, lst_fct->final);
	ft_strdel(&r);
	ft_strdel(&m_2);
	return (lst_fct->final);
}
