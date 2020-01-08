/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 02:21:55 by yodana            #+#    #+#             */
/*   Updated: 2020/01/08 15:05:55 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int			check_numbers_separator(char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == SEPARATOR_CHAR)
			j++;
		i++;
	}
	return (j);
}

int			get_adress(t_instruc *instruc, t_instruc *working)
{
	int			res;
	t_instruc	*tmp;

	res = 0;
	tmp = instruc;
	while (tmp != working)
	{
		if (tmp->hexa_instruc)
			res = res + ((ft_strlen(tmp->hexa_instruc) + 2) / 2);
		tmp = tmp->next;
	}
	return (res);
}

void		remplace_empty(t_instruc *instruc, int res, int size)
{
	char	*remplace;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (instruc->hexa_instruc[i] && instruc->hexa_instruc[i] != '#')
		i++;
	if (!(remplace = ft_uitoa_base((uint16_t)res, 16, 0)))
		error(8, -1, -1, NULL);
	size = size - ft_strlen(remplace);
	while (size > 0)
	{
		if (!(remplace = ft_strjoin_fr("0", remplace, 2)))
			error(8, -1, -1, NULL);
		size--;
	}
	while (instruc->hexa_instruc[i] && remplace[j])
	{
		instruc->hexa_instruc[i] = remplace[j];
		j++;
		i++;
	}
	ft_strdel(&remplace);
}

void		next_instruc(t_env *env)
{
	t_instruc *tmp;

	tmp = env->instruc;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_instruct();
}

t_instruc	*get_last_intruct(t_instruc *instruc)
{
	t_instruc *tmp;

	tmp = instruc;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
