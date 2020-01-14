/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:25:10 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/22 20:55:44 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *newcontent, size_t content_size)
{
	t_list *newlist;

	if (!(newlist = (t_list *)(malloc(sizeof(t_list)))))
		return (NULL);
	if (newcontent == NULL)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		if (!(newlist->content = (void*)(malloc(content_size))))
			return (NULL);
		ft_memcpy(newlist->content, newcontent, content_size);
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	return (newlist);
}
