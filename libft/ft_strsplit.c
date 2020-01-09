/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:50:21 by yodana            #+#    #+#             */
/*   Updated: 2018/11/26 16:47:07 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mot(char const *s, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			words++;
		while (s[i] != c && s[i])
			i++;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	if (s == NULL || !(new = (char**)malloc(sizeof(char*) * ft_mot(s, c) + 1)))
		return (NULL);
	while (i < ft_mot(s, c))
	{
		while (s[j] == c && s[j])
			j++;
		if (!(new[i] = (char*)malloc(sizeof(char) * j + 1)))
			return (NULL);
		while (s[j] != c && s[j])
			new[i][k++] = (char)s[j++];
		new[i][k] = '\0';
		k = 0;
		i++;
	}
	new[i] = NULL;
	return (new);
}
