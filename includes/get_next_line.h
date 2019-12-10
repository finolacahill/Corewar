/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:12:27 by flafonso          #+#    #+#             */
/*   Updated: 2019/11/14 14:49:31 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libsrcs.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE  256

typedef struct		s_listt
{
	char			*str;
	int				fd;
	int				i;
	struct s_listt	*next;
}					t_listt;

int					get_next_line(const int fd, char **line);

#endif
