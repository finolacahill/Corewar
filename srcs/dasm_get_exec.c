/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_get_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:48:59 by adietric          #+#    #+#             */
/*   Updated: 2019/12/10 02:40:09 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			dsam_get_exec_code(uint8_t *cor_content)
{
	int		value;
	int		i;

	i = -1;
	value = 0;
	while (++i < 4)
		value += cor_content[i] * ft_puissance(256, 3 - i);
	return (value);
}
