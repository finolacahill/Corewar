/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:28:20 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/22 13:58:11 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *head;
	t_list *tmp;

	if (!(lst) || !(f))
		return (NULL);
	if (!(tmp = (t_list *)malloc(sizeof(f(lst)))))
		return (NULL);
	tmp = f(lst);
	newlist = ft_lstnew(tmp->content, tmp->content_size);
	head = newlist;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		newlist->next = ft_lstnew(tmp->content, tmp->content_size);
		newlist = newlist->next;
		lst = lst->next;
	}
	return (head);
}
