/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:44:34 by fcahill           #+#    #+#             */
/*   Updated: 2020/01/09 16:35:21 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_insert(const char *s, char *fresh, int start, int end)
{
	int				j;

	j = 0;
	while (start != end)
	{
		fresh[j] = s[start];
		j++;
		start++;
	}
	fresh[j] = '\0';
}

static int			ft_start(const char *s, char c, int start, int end)
{
	start = end;
	while (s[start] == c)
		++start;
	return (start);
}

static int			ft_end(const char *s, char c, int start, int end)
{
	end = start;
	while (s[end] != c && s[end] != '\0')
		++end;
	return (end);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**fresh;
	int				i;
	int				start;
	int				end;

	end = 0;
	i = 0;
	if (!(s) || !(c))
		return (NULL);
	if (!(fresh = (char**)malloc(sizeof(char*) * ft_wordcounter(s, c) + 1)))
		return (NULL);
	while (i < ft_wordcounter(s, c))
	{
		start = ft_start(s, c, start, end);
		end = ft_end(s, c, start, end);
		if (s[start] != '\0')
		{
			if (!(fresh[i] = (char*)malloc(sizeof(char) * end - start + 1)))
				return (NULL);
			ft_insert(s, fresh[i], start, end);
		}
		i++;
	}
	fresh[i] = NULL;
	return ((char**)fresh);
}
