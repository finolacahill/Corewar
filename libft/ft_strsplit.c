/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:47:21 by manki             #+#    #+#             */
/*   Updated: 2017/12/27 15:40:33 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int		ft_wrdlen(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int		ft_nbwrd(const char *str, char c)
{
	int		i;
	int		cut;

	i = 0;
	cut = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			cut++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (cut);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	int		i;
	int		j;
	int		k;

	if (!s || !(fresh = (char **)malloc(sizeof(char *) * (ft_nbwrd(s, c) + 1))))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < ft_nbwrd(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		if (!(fresh[j] = (char *)malloc(ft_wrdlen(&s[i], c) + 1)))
			return (NULL);
		k = 0;
		while (s[i] && s[i] != c)
			fresh[j][k++] = s[i++];
		fresh[j][k] = '\0';
	}
	fresh[j] = 0;
	return (fresh);
}
