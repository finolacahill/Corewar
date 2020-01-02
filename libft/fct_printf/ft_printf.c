/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:39:30 by yodana            #+#    #+#             */
/*   Updated: 2019/06/11 02:24:37 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_is_attribut(const char format)
{
	if (format == '#' || format == '0' || format == '-'
		|| format == '+' || format == ' ')
		return (1);
	return (0);
}

int		ft_find_conv(const char *format, t_conv *lst_fct
, va_list args, t_info *info)
{
	(void)args;
	while (lst_fct != NULL)
	{
		if (format[info->i] == lst_fct->type)
		{
			lst_fct->precision = info->precision;
			lst_fct->champ = info->champ;
			if (!(lst_fct->attribut = ft_strdup(info->attribut)))
				return (1);
			info->size = lst_fct->f(lst_fct, args, info->flags);
			ft_strdel(&lst_fct->attribut);
		}
		lst_fct = lst_fct->next;
	}
	return (info->size);
}

int		ft_init_conv(const char *format, t_conv *lst_fct, va_list args, int *d)
{
	t_info	*info;
	int		i;
	int		size;

	if (format[0] == '\0')
		return (0);
	i = 0;
	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (1);
	if (!(info->attribut = ft_check_attribut(&i, &format[i], 0, 0)))
		return (1);
	info->champ = ft_check_champ(&i, &format[i], args);
	info->precision = ft_check_precision(&i, &format[i], args);
	info->flags = ft_check_flags(&format[i]);
	i = i + (info->flags % 3);
	info->i = i;
	size = ft_find_conv(format, lst_fct, args, info);
	ft_strdel(&info->attribut);
	free(info);
	*d = *d + i + 2;
	return (size);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	t_conv	*lst_fct;
	int		size;

	size = 0;
	i = 0;
	va_start(args, format);
	if (!format || !(lst_fct = ft_create_lst()))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
			size = size + ft_init_conv(&format[i + 1], lst_fct, args, &i);
		if (format[i] && format[i] != '%')
		{
			ft_putchar(format[i++]);
			size++;
		}
	}
	ft_free_lst(lst_fct);
	return (size);
}
