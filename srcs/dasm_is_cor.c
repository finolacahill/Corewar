/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_is_cor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:13:09 by adietric          #+#    #+#             */
/*   Updated: 2019/11/29 18:22:41 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/point.h"

int			dasm_is_it_cor(char *path)
{
	int		len;
	char	*content;
	char	*tmp;

	len = ft_strlen(path);
	if (len < 5)
		return (0);
	tmp = ft_strdup(path);
	ft_reverse(&tmp);
	content = ft_strsub(tmp, 0, 4);
	free(tmp);
	if (ft_strcmp(content, "roc.") == 0)
	{
		free(content);
		return (1);
	}
	free(content);
	return (0);
}
