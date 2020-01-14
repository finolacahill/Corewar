/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:47:31 by yodana            #+#    #+#             */
/*   Updated: 2020/01/09 16:10:42 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		check_min(char *index, int size, t_instruc *instruc)
{
	if (index[0] == '-' && ((ft_strlen(&index[1]) > 19) ||
		(ft_strlen(&index[1]) == 19 && (ft_strcmp(INT_MIN_64, &index[1]) < 0))))
	{
		if (size == 4)
		{
			if (instruc->hexa_instruc != NULL)
				instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc,
						"0000", 1);
			else
				instruc->hexa_instruc = ft_strdup("0000");
		}
		else if (size == 8)
		{
			if (instruc->hexa_instruc != NULL)
				instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc,
						"00000000", 1);
			else
				instruc->hexa_instruc = ft_strdup("00000000");
		}
		if (instruc->hexa_instruc == NULL)
			return (-8);
		return (-1);
	}
	return (1);
}

int		check_max(char *index, int size, t_instruc *instruc)
{
	if (ft_strlen(index) > 19 || (ft_strlen(index) == 19 &&
				(ft_strcmp(INT_MAX_64, index) < 0)))
	{
		if (size == 4)
		{
			if (instruc->hexa_instruc != NULL)
				instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc,
						"ffff", 1);
			else
				instruc->hexa_instruc = ft_strdup("ffff");
		}
		else if (size == 8)
		{
			if (instruc->hexa_instruc != NULL)
				instruc->hexa_instruc = ft_strjoin_fr(instruc->hexa_instruc,
						"ffffffff", 1);
			else
				instruc->hexa_instruc = ft_strdup("ffffffff");
		}
		if (instruc->hexa_instruc == NULL)
			return (-8);
		return (-1);
	}
	return (1);
}

int		check_max_min(char *index, int size, t_instruc *instruc)
{
	int error;

	error = 0;
	if ((error = check_min(index, size, instruc)) == 1 &&
			(error = check_max(index, size, instruc)) == 1)
		return (1);
	if (error == -8)
		return (error);
	return (-1);
}
