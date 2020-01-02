/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:18:04 by yodana            #+#    #+#             */
/*   Updated: 2019/09/18 15:40:53 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->next = NULL;
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	if (!(new->content = malloc(sizeof(content) * content_size)))
		return (NULL);
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	return (new);
}

void	ft_lsadd(t_list **list, void const *content, size_t c_size)
{
	t_list	*tmp;

	if (*list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(content, c_size);
	}
	else
		list[0] = ft_lstnew(content, c_size);
}

void	ft_lstdel_2(t_list **alst)
{
	t_list	*tmp;

	while (*alst)
	{
		free(alst[0]->content);
		alst[0]->content = NULL;
		tmp = alst[0];
		alst[0] = alst[0]->next;
		free(tmp);
		tmp = NULL;
	}
	free(*alst);
	*alst = NULL;
}

size_t	ft_lstprint(t_list list[], char c)
{
	size_t	ret;

	ret = 0;
	while (list)
	{
		write(1, list->content, list->content_size);
		write(1, &c, 1);
		ret += list->content_size;
		list = list->next;
	}
	return (ret);
}
