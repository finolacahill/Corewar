/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:27:24 by flafonso          #+#    #+#             */
/*   Updated: 2019/11/29 18:54:14 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include "../libft/libft.h"
#include "op.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define	BUFF_SIZE	256

typedef	struct		s_champs
{
	char				*path;
	int					id;
	unsigned char		*name;
	unsigned char		*comment;
	size_t				len_exec_code;
	unsigned char		*exec_code;
}					t_champs;

typedef struct		s_all
{
	struct	s_champs	champs[5];
	int					flag_dump;
	int					flag_n;
}					t_all;

void			dasm_get_header(t_all *all, size_t cor_size, uint8_t **cor_content, t_champs *champs);
size_t			dasm_get_data(t_all	*all, char *cor_file, uint8_t **cor_content);
int				dsam_get_exec_code(uint8_t *cor_content);
void			*dasm_memmalloccopy(void *content, size_t prev_size, size_t all_size);
void			vm_print_intro(t_all *all);
void			dasm_input(int ac, char **av, t_all *all);
void			print_usage(t_all *all);
void			dasm_init(t_all *all);
int				dasm_is_it_cor(char *path);
void			dasm_free(t_all	*all);
void			error_size(t_all *all, char *path, size_t cor_size);
void			error(t_all *all, char *str);
void			dasm_print_all(t_all *all);
int				just_number(char *str);
#endif

