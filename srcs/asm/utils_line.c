/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:29:29 by yodana            #+#    #+#             */
/*   Updated: 2019/12/23 04:29:52 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int		line_isascii(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isascii(line[i]))
			i++;
		else
			return (-1);
	}
	return (1);
}

int		line_iscomment(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] <= 32)
		i++;
	if (line[i] == COMMENT_CHAR)
		return (1);
	return (-1);
}

int		len_instruc(t_instruc *instruc)
{
	int			i;
	t_instruc	*tmp;

	i = 0;
	tmp = instruc;
	while (tmp)
	{
		if (tmp->hexa_instruc)
			i = i + (ft_strlen(tmp->hexa_instruc) + 2);
		tmp = tmp->next;
	}
	return (i);
}

int		line_ispoint(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] <= 32)
		i++;
	if (line[i] == '.')
		return (1);
	return (-1);
}

int		line_empty(char *line)
{
	int i;

	i = 0;
	while (line[i] && ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == '\0')
	{
		return (-1);
	}
	return (1);
}
