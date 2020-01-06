/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_get_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:48:59 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 10:44:08 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			dasm_get_exec_code(uint8_t *cor_content, int len)
{
	int		value;
	int		i;

	i = -1;
	value = 0;
	while (++i < len)
		value += cor_content[i] * ft_puissance(256, len - 1 - i);
	return (value);
}
