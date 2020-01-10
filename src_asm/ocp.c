/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:46:58 by yodana            #+#    #+#             */
/*   Updated: 2020/01/09 16:10:42 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int	res_ocp(t_instruc *instruc, char *ocp)
{
	int res;

	res = bi_to_dec(ocp);
	ft_strdel(&ocp);
	if (!(ocp = ft_uitoa_base(res, 16, 0)))
		return (-1);
	if (ft_strlen(ocp) == 1)
	{
		if (!(ocp = ft_strjoin_fr("0", ocp, 2)))
		{
			ft_strdel(&ocp);
			return (-1);
		}
	}
	if (!(instruc->hexa_instruc = ft_strjoin_fr(ocp, instruc->hexa_instruc, 3)))
	{
		ft_strdel(&ocp);
		return (-1);
	}
	return (0);
}

int		ret_ocp(t_instruc *instruc, char *ocp)
{
	if ((res_ocp(instruc, ocp)) == -1)
		return (-1);
	return (0);
}

int		get_ocp(t_instruc *instruc, int i, int j)
{
	char *ocp;

	if (!(ocp = ft_strnew(8)))
		return (-1);
	while (instruc->params[++i] != 0)
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
	}
	while (j < 7)
		ocp[++j] = '0';
	return (ret_ocp(instruc, ocp));
}
