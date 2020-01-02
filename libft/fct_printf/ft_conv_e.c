/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:20:58 by yodana            #+#    #+#             */
/*   Updated: 2019/06/09 22:21:26 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_e_final(char *new, t_conv *lst_fct, char *str_comma, int comma)
{
	if (lst_fct->precision == 1)
		new = ft_strsub_fr(new, 0, 1);
	str_comma = ft_itoa(comma - 1);
	if (lst_fct->precision <= 1 && ft_strrchr(lst_fct->attribut, '#') != NULL)
		new = ft_strjoin_fr(new, ".", 1);
	if (comma <= 10)
		str_comma = ft_strjoin_fr("0", str_comma, 2);
	if (comma - 1 < 0)
		new = ft_strjoin_fr(new, "e-", 1);
	else
		new = ft_strjoin_fr(new, "e+", 1);
	new = ft_strjoin_fr(new, str_comma, 3);
	return (new);
}

char	*ft_add_science(char *new, t_conv *lst_fct, int comma, int i)
{
	char	*tmp;
	char	*str_comma;
	int		j;

	j = 0;
	str_comma = NULL;
	if (ft_check_float_round(new, lst_fct->precision) == 1)
	{
		tmp = ft_float_round(i - 21, new, lst_fct->precision + 1);
		if (new[0] != tmp[0])
			ft_strdel(&new);
		new = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	while (new[j] && new[j] != '.')
		j++;
	if (j > 1)
	{
		comma--;
		new[1] = '.';
		new[j] = '0';
	}
	new = ft_e_final(new, lst_fct, str_comma, comma);
	return (new);
}

char	*ft_scientific(t_conv *lst_fct, char *res)
{
	char	*new;
	int		i;
	int		j;
	int		comma;

	j = 1;
	i = 2;
	comma = ft_calc_comma(res);
	if (!(new = ft_strnew(ft_strlen(res))))
		return (NULL);
	new[0] = res[0];
	new[1] = '.';
	while (i <= lst_fct->precision + 21)
	{
		if (res[j] != '.')
		{
			new[i] = res[j];
			i++;
		}
		j++;
	}
	ft_strdel(&res);
	new = ft_add_science(new, lst_fct, comma, i);
	return (new);
}

char	*ft_e_zero(t_conv *lst_fct, t_float d1, int i, int size)
{
	char		*res_final;
	char		*m_2;
	int			comma;
	char		*new;

	res_final = NULL;
	if (!(m_2 = ft_i_to_bi(d1.parts.m)))
		return (NULL);
	while ((comma = ft_check_number(res_final)) == -1)
	{
		ft_strdel(&res_final);
		res_final = ft_bi_to_dec(m_2, 0, 1, size + lst_fct->precision);
		res_final = ft_calc_exposant(d1.f, res_final, d1.parts.e);
		size = size * 2;
	}
	ft_strdel(&m_2);
	new = ft_strnew(ft_strlen(res_final));
	new[0] = res_final[comma];
	new[1] = '.';
	while (++i <= lst_fct->precision + 21)
		new[i] = res_final[i + comma - 1];
	ft_strdel(&res_final);
	new = ft_add_science(new, lst_fct, comma, i);
	return (new);
}

int		ft_conv_e(t_conv *lst_fct, va_list args, int flags)
{
	t_float		d1;
	char		*m_2;
	int			s;

	d1.f = flags == FL ? va_arg(args, long double) : va_arg(args, double);
	lst_fct->precision = lst_fct->precision == 0 ? 7 : lst_fct->precision;
	if (d1.f < 1 && d1.f > -1 && d1.f != 0)
		lst_fct->final = ft_e_zero(lst_fct, d1, 1, 66);
	else
	{
		m_2 = ft_i_to_bi(d1.parts.m);
		if ((s = ft_check_excep(d1.parts.e, m_2, d1.parts.sign, lst_fct)) != -1)
		{
			ft_strdel(&m_2);
			return (s);
		}
		lst_fct->final = ft_calc_float(m_2, lst_fct, d1);
	}
	if (d1.parts.sign == 1)
		lst_fct->final = ft_strjoin_fr("-", lst_fct->final, 2);
	lst_fct->final = ft_attribut(d1.f, lst_fct);
	ft_putstr(lst_fct->final);
	s = ft_strlen(lst_fct->final);
	ft_strdel(&lst_fct->final);
	return (s);
}
