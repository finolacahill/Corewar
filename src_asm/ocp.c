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

void	res_ocp(t_instruc *instruc, char *ocp, t_env *env)
{
	int res;

	res = bi_to_dec(ocp);
	ft_strdel(&ocp);
	if (!(ocp = ft_uitoa_base(res, 16, 0)))
		error(8, env, -1, NULL);
	if (ft_strlen(ocp) == 1)
	{
		if (!(ocp = ft_strjoin_fr("0", ocp, 2)))
			error(8, env, -1, NULL);
	}
	if (!(instruc->hexa_instruc = ft_strjoin_fr(ocp, instruc->hexa_instruc, 3)))
		error(8, env, -1, NULL);
}

void	get_ocp(t_instruc *instruc, int i, int j, t_env *env)
{
	char *ocp;

	if (!(ocp = ft_strnew(8)))
		error(8, env, -1, NULL);
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
	res_ocp(instruc, ocp, env);
}
