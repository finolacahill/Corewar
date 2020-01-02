/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 04:50:14 by yodana            #+#    #+#             */
/*   Updated: 2019/05/28 05:42:02 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_conv
{
	char			type;
	char			*(*display)(long long);
	char			*attribut;
	int				champ;
	int				precision;
	char			*final;
	int				(*f)(struct s_conv*, va_list, int);
	struct s_conv	*next;
}				t_conv;

typedef struct	s_init
{
	char	type;
	int		(*f)(struct s_conv*, va_list, int);
	char	*(*display)(long long);
}				t_init;

typedef struct	s_info
{
	int		flags;
	char	*attribut;
	int		champ;
	int		precision;
	int		size;
	int		i;
}				t_info;

#endif
