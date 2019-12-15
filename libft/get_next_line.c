/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:11:52 by fcahill           #+#    #+#             */
/*   Updated: 2018/12/14 14:54:57 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_splitline(char *buf, char **line, char *remain[], int fd)
{
	char *tmp;

	tmp = NULL;
	if ((remain[fd] != NULL) && (buf != remain[fd]))
	{
		if (!(tmp = ft_strjoin(remain[fd], buf)))
			return (-1);
	}
	else if (!(tmp = ft_strdup(buf)))
		return (-1);
	ft_strclr(remain[fd]);
	ft_strclr(buf);
	free(remain[fd]);
	if (!(remain[fd] = ft_strdup(ft_strchr(tmp, '\n') + 1)))
		return (-1);
	*(ft_strchr(tmp, '\n')) = '\0';
	free(*line);
	if (!(*line = ft_strdup(tmp)))
		return (-1);
	free(tmp);
	return (1);
}

static int		ft_makeline(char *buf, char **line, char *remain[], int fd)
{
	char *tmp;

	tmp = NULL;
	if (ft_strchr(buf, '\n') == NULL)
	{
		if ((remain[fd]) && remain[fd] != buf)
		{
			if (!(tmp = ft_strjoin(remain[fd], buf)))
				return (-1);
			free(remain[fd]);
			remain[fd] = tmp;
			ft_strclr(buf);
			free(*line);
			if (!(*line = ft_strdup(remain[fd])))
				return (-1);
			return (0);
		}
		if (!(remain[fd] = ft_strdup(buf)))
			return (-1);
		ft_strclr(buf);
		free(tmp);
		return (0);
	}
	free(tmp);
	return (ft_splitline(buf, line, remain, fd));
}

static int		ft_end(int n, char **line, char *remain[], int fd)
{
	char *tmp;

	tmp = NULL;
	if (n == 0 && *remain[fd])
	{
		if (!(tmp = ft_strdup(remain[fd])))
			return (-1);
		ft_strclr(*line);
		ft_strclr(remain[fd]);
		*line = tmp;
		return (1);
	}
	if ((n == 0) && (!(*remain[fd])))
		return (0);
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	char		*buf;
	int			n;
	static char	*remain[MAX_FD];

	if (BUFF_SIZE < 1 || line == NULL || (!(buf = ft_strnew(BUFF_SIZE + 1))))
		return (-1);
	if (fd >= MAX_FD || (!(*line = ft_strnew(BUFF_SIZE))) || fd < 0)
		return (-1);
	if ((n = 1 || 1) && (remain[fd]))
		if ((ft_makeline(remain[fd], line, remain, fd)) == 1)
			return (1);
	while (n > 0)
	{
		if ((n = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[n] = '\0';
		if ((ft_makeline(buf, line, remain, fd) == 1))
		{
			ft_strdel(&buf);
			return (1);
		}
	}
	n = ft_end(n, line, remain, fd);
	return (n);
}
