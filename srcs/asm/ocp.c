/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:46:58 by yodana            #+#    #+#             */
/*   Updated: 2019/12/22 19:28:32 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/op.h"
#include <fcntl.h>
#include "../../libft/libft.h"
#include <stdio.h>
#include "../../includes/corewar.h"

void	res_ocp(t_instruc *instruc, char *ocp)
{
	int res;

	res = bi_to_dec(ocp);
	ft_strdel(&ocp);
	ocp = ft_uitoa_base(res, 16, 0);
	if (ft_strlen(ocp) == 1)
		ocp = ft_strjoin_fr("0", ocp, 2);
	instruc->hexa_instruc = ft_strjoin_fr(ocp, instruc->hexa_instruc, 3);
}

void	get_ocp(t_instruc *instruc, int i, int j)
{
	char *ocp;

	ocp = ft_strnew(8);
	while (instruc->params[i] != 0)
	{
		if (instruc->params[i] == T_REG)
		{
			ocp[++j] = '0';
			ocp[++j] = '1';
		}
		else if (instruc->params[i] == T_DIR)
		{
			ocp[++j] = '1';
			ocp[++j] = '0';
		}
		else if (instruc->params[i] == T_IND)
		{
			ocp[++j] = '1';
			ocp[++j] = '1';
		}
		i++;
	}
	while (j < 7)
		ocp[++j] = '0';
	res_ocp(instruc, ocp);
}
