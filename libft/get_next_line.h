/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:26:00 by fcahill           #+#    #+#             */
/*   Updated: 2018/12/14 15:07:22 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 4000
# define MAX_FD 4864

int		get_next_line(const int fd, char **line);
int		ft_getchar(int fd);
#endif
