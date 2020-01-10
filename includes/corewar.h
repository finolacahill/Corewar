/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 09:57:22 by yodana            #+#    #+#             */
/*   Updated: 2020/01/09 16:12:21 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../includes/op.h"
# include "../libft/libft.h"

# define INT_MAX_64 "9223372036854775807"
# define INT_MIN_64 "9223372036854775808"

typedef	struct			s_label
{
	char			*label;
	int				adress;
	int				size;
	struct s_label	*next;
}						t_label;

typedef struct			s_instruc
{
	int					opcode;
	int					*params;
	int					nbr_params;
	int					ocp;
	int					adress;
	int					is_ocp;
	char				*hexa_instruc;
	char				*hexa_params;
	int					for_direct;
	int					index;
	struct s_instruc	*next;
	struct s_label		*label;
}						t_instruc;

typedef struct			s_env
{
	struct s_instruc	*instruc;
	struct s_label		*label;
	struct s_header		*header;
	char				*c_line;
	int					line;
	int					column;

}						t_env;

typedef struct			s_op
{
	char			*instruc;
	int				nbr_params;
	int				param_type[3];
	int				opcode;
	char			*real_name;
	int				registre;
	int				for_direct;
}						t_op;

typedef struct			s_error
{
	int		type;
	char	*message;
	int		line;
	int		column;
	int		params;
	int		label;
}						t_error;

typedef struct			s_error_cmd
{
	int		type;
	char	*message;

}						t_error_cmd;

t_env					*init_env();
t_instruc				*new_instruct();
t_label					*new_label();
int						get_label(char *line, t_env *env);
void					print_instruc(t_instruc *instruc);
void					print_label(t_label *labels);
int						get_instruc(char *line, t_env *env, int column);
int						get_params(char *line, t_env *env);
void					get_ocp(t_instruc *instruc, int i, int j, t_env *env);
int						bi_to_dec(char *bi);
int						ft_strtol(char *str, int base, int size);
t_instruc				*get_last_intruct(t_instruc *instruc);
void					next_instruc(t_env *env);
int						dec_to_hexa(int i);
void					error(int i, t_env *env, int column, char *name);
int						line_ispoint(char *line);
void					go_cmd(t_env *env, char *line);
int						line_empty(char *line);
int						len_instruc(t_instruc *instruc);
void					free_all(t_env *env);
void					remplace_empty(t_instruc *instruc, int res, int size, t_env *env);
int						get_adress(t_instruc *instruc, t_instruc *working);
int						line_iscomment(char *line);
char					*get_params_with_opcode(int ocp);
int						is_label(char *label);
int						check_numbers(char *str);
void					last_verif(t_env *env);
void					error_cmd(int type, t_env *env, char *cmd, int line);
void					go_instruc(char *line, t_env *env, int i);
void					which_cmd_error(t_header *header, t_env *env);
void					is_label_exist(char *l, t_env *e, t_instruc *i, int s);
int						what_params(char *p, t_instruc *i, int j, t_env *env);
void					write_to_file(t_instruc *i, int f,
	t_header *h, t_env *e);
void					write_header_magic(t_env *env, char *new_name, int i);
int						check_numbers_separator(char *line);
int						line_isascii(char *line);
int						check_max_min(char *index, int len, t_instruc *instruc);
#endif
