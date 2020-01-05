/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:36:27 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/21 16:30:15 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list **temp;

	temp = alst;
	if (!(alst) || !(del))
		return ;
	while ((*alst) != NULL)
	{
		*temp = *alst;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = (*temp)->next;
	}
}
