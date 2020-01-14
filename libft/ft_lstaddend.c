/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:38:45 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/21 16:31:17 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list *alst, t_list *new)
{
	if ((!alst) || (!new))
		return ;
	while (alst->next != NULL)
		alst = alst->next;
	alst->next = new;
}
