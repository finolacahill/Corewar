/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_rdm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:18:49 by adietric          #+#    #+#             */
/*   Updated: 2020/01/08 19:04:02 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	just_nb_init(const char *str, int i, int *neg)
{
	while (ft_isspace(str[i]) != 0)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			(*neg) = -1;
		++i;
	}
	return (i);
}

int			just_nb_atoi(const char *str, t_all *all)
{
	int			i;
	int			result;
	int			neg;
	long long	check;

	i = 0;
	result = 0;
	check = 0;
	neg = 1;
	i = just_nb_init(str, i, &neg);
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		check = (str[i] - '0') + (check * 10);
		result = (str[i] - '0') + (result * 10);
		if (check < -2147483648 || check > 2147483647)
			print_usage(all);
		i++;
	}
	check = check * neg;
	if (check < -2147483648 || check > 2147483647)
		print_usage(all);
	return (result * neg);
}

int			is_in(int i, int value[9])
{
	int		r;

	r = -1;
	while (++r < 9)
		if (value[r] == i)
			return (1);
	return (0);
}

int			just_number(char *str)
{
	int		i;
	int		c;
	int		len;

	len = ft_strlen(str);
	i = -1;
	c = 0;
	while (str[++i])
	{
		if (str[i] != '-' && str[i] != '+' && (str[i] < 48 || str[i] > 57))
			return (0);
		if (str[i] == '-' || str[i] == '+')
			c++;
		if (i > 0 && (str[i] == '-' || str[i] == '+'))
			return (0);
	}
	if (c > 1 || i < len)
		return (0);
	return (1);
}
