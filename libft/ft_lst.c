/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 02:57:44 by yodana            #+#    #+#             */
/*   Updated: 2019/05/28 03:17:46 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static const t_init	g_tab_init[] = {
	{'c', ft_char, NULL},
	{'s', ft_str, NULL},
	{'p', ft_pointer, NULL},
	{'d', ft_conv, ft_itoa},
	{'i', ft_conv, ft_itoa},
	{'o', ft_conv_2, ft_calc_octa},
	{'u', ft_conv_2, ft_itoa_u},
	{'x', ft_conv_2, ft_calc_long_hexa},
	{'X', ft_conv_2, ft_calc_long_hexam},
	{'f', ft_conv_f, NULL},
	{'%', ft_conv_spe, NULL},
	{'e', ft_conv_e, NULL},
	{'b', ft_conv_b, NULL},
	{'\0', NULL, NULL},
};

void	ft_free_lst(t_conv *list)
{
	t_conv *tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

void	ft_conv_lst_add(t_conv **new, t_conv *next)
{
	t_conv *tmp;

	if (next)
	{
		tmp = *new;
		if (tmp == NULL)
			tmp = next;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = next;
		}
	}
}

t_conv	*ft_add_lst(int i)
{
	t_conv *new;

	if (!(new = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	new->type = g_tab_init[i].type;
	new->f = g_tab_init[i].f;
	new->attribut = NULL;
	new->champ = 0;
	new->precision = 0;
	new->display = g_tab_init[i].display;
	new->final = NULL;
	new->next = NULL;
	return (new);
}

t_conv	*ft_create_lst(void)
{
	t_conv	*new;
	t_conv	*next;
	int		i;

	i = 1;
	if (!(new = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	new->type = 'c';
	new->f = ft_char;
	new->attribut = NULL;
	new->champ = 0;
	new->precision = 0;
	new->display = NULL;
	new->final = NULL;
	new->next = NULL;
	while (g_tab_init[i].type != '\0')
	{
		next = ft_add_lst(i);
		i++;
		ft_conv_lst_add(&new, next);
	}
	return (new);
}
