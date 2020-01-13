/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_get_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:00:45 by adietric          #+#    #+#             */
/*   Updated: 2020/01/06 10:42:57 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		free_and_exit(t_all *all)
{
	dasm_free(all);
	exit(EXIT_FAILURE);
}

static void		free_cor_and_exit(t_all *all, uint8_t **cor_content)
{
	free(*cor_content);
	free_and_exit(all);
}

static void		open_error(t_all *all)
{
	ft_fprintf(2, "Error: can not open given file.\n");
	free_and_exit(all);
}

size_t			dasm_get_data(t_all *all, char *cor_file, uint8_t **cor_content)
{
	int			fd;
	uint8_t		buff[BUFF_SIZE + 1];
	int			ret;
	size_t		cor_size;

	if (!(cor_file))
		return (0);
	if ((fd = open(cor_file, O_RDONLY)) == -1)
		open_error(all);
	if (!(cor_content[0] = (uint8_t *)malloc(sizeof(uint8_t) * 1)))
		free_and_exit(all);
	cor_content[0][0] = '\0';
	cor_size = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(cor_content[0] = dasm_memmalloccopy(cor_content[0]
			, cor_size, cor_size + ret)))
			free_cor_and_exit(all, cor_content);
		ft_memcpy(&(cor_content[0][cor_size]), buff, ret);
		cor_size += ret;
	}
	if (close(fd) == -1)
		free_cor_and_exit(all, cor_content);
	return (cor_size);
}
