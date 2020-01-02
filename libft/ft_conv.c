/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 02:09:17 by yodana            #+#    #+#             */
/*   Updated: 2019/05/28 02:11:12 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_conv_wf_2(va_list args, int flags, t_conv *lst_fct)
{
	unsigned long			ld;
	unsigned long long		lld;
	unsigned char			hhd;

	if (flags == HH)
	{
		hhd = (unsigned char)va_arg(args, unsigned char*);
		lst_fct->final = lst_fct->display(hhd);
		lst_fct->final = ft_attribut(hhd, lst_fct);
	}
	else if (flags == L)
	{
		ld = (unsigned long)va_arg(args, unsigned long);
		lst_fct->final = lst_fct->display(ld);
		lst_fct->final = ft_attribut(ld, lst_fct);
	}
	else if (flags == LL)
	{
		lld = (unsigned long long)va_arg(args, unsigned long long);
		lst_fct->final = lst_fct->display(lld);
		lst_fct->final = ft_attribut(lld, lst_fct);
	}
	return (lst_fct->final);
}

int		ft_conv_2(t_conv *lst_fct, va_list args, int flags)
{
	unsigned int		d;
	int					size;
	unsigned short int	hd;

	if (flags >= 2)
		lst_fct->final = ft_conv_wf_2(args, flags, lst_fct);
	if (flags == H)
	{
		hd = (unsigned short)va_arg(args, unsigned int);
		lst_fct->final = lst_fct->display(hd);
		lst_fct->final = ft_attribut(hd, lst_fct);
	}
	else if (flags == 0)
	{
		d = (unsigned int)va_arg(args, unsigned int);
		lst_fct->final = lst_fct->display(d);
		lst_fct->final = ft_attribut(d, lst_fct);
	}
	ft_putstr(lst_fct->final);
	size = ft_strlen(lst_fct->final);
	ft_strdel(&lst_fct->final);
	return (size);
}

char	*ft_conv_wf(va_list args, int flags, t_conv *lst_fct)
{
	long		ld;
	long long	lld;
	char		hhd;

	if (flags == HH)
	{
		hhd = (char)va_arg(args, char*);
		lst_fct->final = lst_fct->display(hhd);
		lst_fct->final = ft_attribut(hhd, lst_fct);
	}
	else if (flags == L)
	{
		ld = (long)va_arg(args, long);
		lst_fct->final = lst_fct->display(ld);
		lst_fct->final = ft_attribut(ld, lst_fct);
	}
	else if (flags == LL)
	{
		lld = (long long)va_arg(args, long long);
		lst_fct->final = lst_fct->display(lld);
		lst_fct->final = ft_attribut(lld, lst_fct);
	}
	return (lst_fct->final);
}

int		ft_conv(t_conv *lst_fct, va_list args, int flags)
{
	int			d;
	int			size;
	short int	hd;

	if (flags >= 2)
		lst_fct->final = ft_conv_wf(args, flags, lst_fct);
	if (flags == H)
	{
		hd = (short)va_arg(args, int);
		lst_fct->final = lst_fct->display(hd);
		lst_fct->final = ft_attribut(hd, lst_fct);
	}
	else if (flags == 0)
	{
		d = (int)va_arg(args, int);
		lst_fct->final = lst_fct->display(d);
		lst_fct->final = ft_attribut(d, lst_fct);
	}
	ft_putstr(lst_fct->final);
	size = ft_strlen(lst_fct->final);
	ft_strdel(&lst_fct->final);
	return (size);
}
