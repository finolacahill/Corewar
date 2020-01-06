/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_is_cor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:13:09 by adietric          #+#    #+#             */
/*   Updated: 2019/12/10 02:40:09 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int free_content(char *content, int ret)
{
	free(content);
	return (ret);
}

int			dasm_is_it_cor(char *path)
{
	int		len;
	char	*content;
	char	*tmp;

	len = ft_strlen(path);
	if (len < 5)
		return (0);
	if (!(tmp = ft_strdup(path)))
		return (0);
	ft_reverse(&tmp);
	if (!(content = ft_strsub(tmp, 0, 4)))
	{
		free(tmp);
		return (free_content(content, 0));
	}
	free(tmp);
	if (ft_strcmp(content, "roc.") == 0)
		return (free_content(content, 1));
	free(content);
	return (0);
}
