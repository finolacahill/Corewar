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

#ifndef VM_H
#define VM_H

#include <stdio.h>
#include "../libft/ft_printf.h"
#include "../libft/libft.h"
#include "op.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef	struct		s_champs
{
	char				*path;
	int					id;
	unsigned char		*name;
	unsigned char		*comment;
	size_t				len_exec_code;
	unsigned char		*exec_code;
	int					start;
	int					last_live;
	int					pc;
}					t_champs;

typedef struct		s_arena
{
	
	int				live_calls;
	int				cycles;
		
}					t_arena;

typedef struct		s_all
{
	struct	s_champs	champs[MAX_PLAYERS];
	int					flag_dump;
	int					flag_n;
	int					total_champ;
	unsigned char		*arena;
	t_list				processes;
	int					last_alive;
	int					last_alive_cycle;
	int					cycles;
	int					nbr_live_since_check;
	int					cycles_to_die;
	int					total_checks;
	
}					t_all;

typedef struct			s_process
{
	int					id;
	int					r[REG_NUMBER];
	int					pc;
	char				carry;
	int					live_calls;
	int					start;
	int					exec_cycle;
	int					bytes;
	int					*decode;
	unsigned char 		op;
	struct s_process	*next;
}						t_process;

void			dasm_get_header(t_all *all, size_t cor_size, uint8_t **cor_content, t_champs *champs);
size_t			dasm_get_data(t_all	*all, char *cor_file, uint8_t **cor_content);
int				dsam_get_exec_code(uint8_t *cor_content);
void			*dasm_memmalloccopy(void *content, size_t prev_size, size_t all_size);
void			vm_print_intro(t_all *all);
void			dasm_input(int ac, char **av, t_all *all);
void			print_usage(t_all *all);
void			dasm_init(t_all *vm, int ac, char **av);
int				dasm_is_it_cor(char *path);
void			dasm_free(t_all	*all);
void			error_size(t_all *all, char *path, size_t cor_size);
void			error(t_all *all, char *str);
void			dasm_print_all(t_all *all);
int				just_number(char *str);

//vm
int 			init_arena(t_all *vm);
int   			load_process(t_all *vm, t_process *head);
int     		run_vm(t_all *vm);
t_process		*ft_decode_byte(unsigned char c, t_process *p);
void			calc_bytes(t_process *p, int *bytes);
int				get_next_bytes(t_all *vm, t_process *p, int len, int bytes_read);
int         	check_alive(t_all *vm, t_process *p);
int				is_player_nb(int i, t_all *vm);
int     		get_reg_val(t_all *vm, t_process *p, int reg);
int     		get_ind(t_all *vm, t_process *p, int bytes_read);
void			load_value(t_all *vm, int address, int len, int val);

// operations
void			op_live(t_all *vm, t_process *p);
void    		op_st(t_all *vm, t_process *p);

//errors
t_process *error_process(t_process *p);
#endif

