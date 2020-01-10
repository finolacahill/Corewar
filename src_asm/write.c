/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:30:26 by yodana            #+#    #+#             */
/*   Updated: 2020/01/09 16:10:42 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int	write_header_magic(t_header *header, char *new_name, int i)
{
	char	*res;
	char	*header_magic;
	int		j;

	j = 0;
	if (!(res = ft_strnew(8)))
		return (-1);
	write(1, "Writing output program to ", 26);
	write(1, new_name, ft_strlen(new_name));
	write(1, "\n", 1);
	header->magic = COREWAR_EXEC_MAGIC;
	if (!(header_magic = ft_uitoa_base(header->magic, 16, 0)))
		{
			free(res);
			return (-1);
		}
	if (!(header_magic = ft_strjoin_fr("00", header_magic, 2)))
	{
		free(res);
		ft_strdel(&header_magic);
		return (-1);
	}
	while (header_magic[i])
	{
		res[j] = ft_strtol(&header_magic[i], 16, 2);
		i = i + 2;
		j++;
	}
	write(header->fd, res, 4);
	ft_strdel(&res);
	ft_strdel(&header_magic);
	return (0);
}

void	write_comment(t_header *header, char *size, char c, t_env *env)
{
	char	*hexa_size;
	int		j;
	int		i;
	int		len;

	i = 0;
	j = -1;
	if (!(hexa_size = ft_strnew(4)))
	{
		free(size);
		free_all(env, header);
		error(8, -1, -1, NULL);
	}
	while (size[i])
	{
		hexa_size[++j] = ft_strtol(&size[i], 16, 2);
		i = i + 2;
	}
	len = 4 - j + 1;
	while (--len > 0)
		write(header->fd, &c, 1);
	write(header->fd, hexa_size, 2);
	write(header->fd, header->comment, ft_strlen(header->comment));
	len = COMMENT_LENGTH - ft_strlen(header->comment) + 1;
	while (--len > 0)
		write(header->fd, &c, 1);
	len = 4 + 1;
	while (--len > 0)
		write(header->fd, &c, 1);
	ft_strdel(&hexa_size);
}

void	write_name(t_header *header, int fd, t_env *env)
{
	int		len;
	char	c;
	int		s;
	char	*size;

	s = 4;
	c = 0;
	if (!(size = ft_uitoa_base(len_instruc(env->instruc) / 2, 16, 0)))
	{
		free_all(env, env->header);
		error(8, -1, -1, NULL);
	}
	s = s - ft_strlen(size) + 1;
	while (--s > 0)
	{
		if (!(size = ft_strjoin_fr("0", size, 2)))
		{
			ft_strdel(&size);
			free_all(env, env->header);
			error(8, -1, -1, NULL);
		}
	}
	len = PROG_NAME_LENGTH - ft_strlen(header->prog_name);
	write(fd, header->prog_name, ft_strlen(header->prog_name));
	while (--len > 0)
		write(fd, &c, 1);
	len = 4 + 1;
	while (--len > 0)
		write(fd, &c, 1);
	write_comment(header, size, c, env);
	ft_strdel(&size);
}

void	go_to_write(int len, t_instruc *tmp, int fd)
{
	char	*res;
	int		i;
	int		j;

	len = (ft_strlen(tmp->hexa_instruc) / 2) + 1;
	j = 0;
	i = 0;
	if (!(res = ft_strnew(len)))
		error(8, -1, -1, NULL);
	res[j] = dec_to_hexa(tmp->opcode);
	j++;
	while (tmp->hexa_instruc[i])
	{
		res[j] = ft_strtol(&tmp->hexa_instruc[i], 16, 2);
		j++;
		i = i + 2;
	}
	write(fd, res, len);
	ft_strdel(&res);
}

void	write_to_file(t_instruc *instruc, int fd, t_header *header, t_env *env)
{
	t_instruc *tmp;

	tmp = instruc;
	write_name(header, fd, env);
	while (tmp->next)
	{
		if (tmp->hexa_instruc)
			go_to_write(0, tmp, fd);
		tmp = tmp->next;
	}
}
