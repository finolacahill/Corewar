/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:17:52 by fcahill           #+#    #+#             */
/*   Updated: 2018/11/21 17:06:30 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstcpy(t_list *lst1)
{
	t_list	*lst2;

	while (lst1 != NULL)
	{
		if (!(lst2 = (t_list *)malloc(sizeof(lst1))))
			return (NULL);
		lst2 = lst1;
		lst1 = (lst1)->next;
	}
	return (lst2);
}
