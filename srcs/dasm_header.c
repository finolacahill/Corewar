/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasm_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:38:49 by adietric          #+#    #+#             */
/*   Updated: 2019/11/29 17:47:15 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

size_t		dasm_hexalen(uint8_t *cor_content, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		if (cor_content[i] == 0)
			break ;
	return (i);
}

void		dasm_get_header(t_all *all, size_t cor_size, uint8_t **cor_content
						, t_champs *champs)
{
	size_t	name_len;
	size_t	comment_len;
	char	*exec_code;

	if (cor_size < 2192)
		error(all, "Fichier trop petit! (pas assez d'informations)\n");
	if (cor_size > CHAMP_MAX_SIZE + 2192)
		error_size(all, champs->path, cor_size);
	if (cor_content[0][0] != 0x00 || cor_content[0][1] != 0xea
		|| cor_content[0][2] != 0x83 || cor_content[0][3] != 0xf3)
		error(all, "Magic_Number (0xea83f3) inexistant\n");
	name_len = dasm_hexalen(&(cor_content[0][4]), 128);
	comment_len = dasm_hexalen(&(cor_content[0][140]), 2048);
	champs->name = (unsigned char*)ft_strsub((const char *)cor_content[0]
					, 4, name_len);
	champs->comment = (unsigned char*)ft_strsub((const char *)cor_content[0]
					, 140, comment_len);
	champs->len_exec_code = (size_t)dsam_get_exec_code(&(cor_content[0][136]));
	if (champs->exec_code)
		printf("\n\n____ATTENTION____\n\n");
	champs->exec_code = (unsigned char*)ft_strsub((const char *)cor_content[0]
						, 2192, champs->len_exec_code);
}
