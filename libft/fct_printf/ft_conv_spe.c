/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_spe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 02:14:27 by yodana            #+#    #+#             */
/*   Updated: 2019/05/28 02:57:31 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_conv_spe(t_conv *lst_fct, va_list args, int flags)
{
	char	*res;
	int		size;

	(void)args;
	(void)flags;
	res = ft_strnew(1);
	res[0] = '%';
	if (!(lst_fct->final = ft_strdup(res)))
		return (1);
	lst_fct->final = ft_space(1, lst_fct, ft_strlen(lst_fct->final));
	ft_putstr(lst_fct->final);
	size = ft_strlen(lst_fct->final);
	ft_strdel(&res);
	ft_strdel(&lst_fct->final);
	return (size);
}
