/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:04:55 by adietric          #+#    #+#             */
/*   Updated: 2019/11/29 17:42:34 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

void	dasm_init_champs(t_all *all)
{
	int	i;

	i = -1;
	while (++i < 5)
		ft_bzero(&(all->champs[i]), sizeof(t_champs));
}

void	dasm_init(t_all *all)
{
	dasm_init_champs(all);
	all->flag_dump = -1;
	all->flag_n = -1;
}
