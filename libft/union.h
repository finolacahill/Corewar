/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 05:39:51 by yodana            #+#    #+#             */
/*   Updated: 2019/05/28 09:15:03 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNION_H

# define UNION_H

typedef union				u_float
{
	long double				f;
	struct
	{
		unsigned long long	m:64;
		unsigned int		e:15;
		unsigned int		sign:1;
		unsigned int		empty:16;
	}						parts;
}							t_float;
#endif
