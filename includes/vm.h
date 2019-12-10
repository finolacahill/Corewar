/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 02:40:33 by flafonso          #+#    #+#             */
/*   Updated: 2019/12/10 03:09:50 by flafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
#define VM_H

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
	int					start;
	int					pc;
}					t_champs;

typedef struct		s_arena
{
	
	int				live_calls;
	int				cycles;
	
	
}					t_arena;

typedef struct		s_all
{
	struct	s_champs	champs[MAX_PLAYERS + 1];
	int					flag_dump;
	int					flag_n;
	int					total_champ;
	unsigned char		*arena;
	t_list				processes;
	int					last_alive;
	int					cycles;
	int					check_mode;
}					t_all;

typedef struct			s_process
{
	unsigned char				*name;
	int					id;
//	int					number;
	int					r[REG_NUMBER];
	int					pc;
	char				carry;
	int					live_calls;
	int					duration;
	int					start;
	int					bytes;
	int					*decode;
	int					len_program;
	unsigned char				*program;
//	void				(*op)();
	unsigned char 				op;
	struct s_process	*next;
}						t_process;

typedef	struct		s_op
{
	uint8_t				*op_name;
	uint16_t			(*inst)(struct s_all *all, struct s_op *op, uint8_t *c);
}					t_op;

typedef struct		s_op_check
{
	char				*name;
	int					nb_param;
	int					ocp_value[9];
	int					op_code;
	int					nb_cycle;
	int					dir_size;
}					t_op_check;

t_op_check   	 op_tab[17];

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
int 			init_arena(t_all *vm);
int   			load_process(t_all *vm, t_process *head);
int     		run_vm(t_all *vm);

void			error_exec(t_all *all, char *champ_name, uint16_t line);

int				is_in(int i, int *value);
void			vm_start(t_all *all);
uint16_t		init_op_check(t_op *op);
uint16_t		vm_check_exec(t_all *all, t_champs *champs, uint8_t *cont, t_op *op);
uint16_t		op_add(t_all *all, t_op *op, uint8_t *content);
uint16_t		op_aff(t_all *all, t_op *op, uint8_t *content);
uint16_t		op_and(t_all *all, t_op *op, uint8_t *content);
uint16_t		op_fork(t_all *all, t_op *op, uint8_t *content);
uint16_t		op_ld(t_all *all, t_op *op, uint8_t *content);
uint16_t		op_ldi(t_all *all, t_op *op, uint8_t *content);
uint16_t		op_lfork(t_all *all, t_op *op, uint8_t *content);
uint16_t		op_live(t_all *all, t_op *op, uint8_t *content);
uint16_t		op_lld(t_all *all, t_op *op, uint8_t *content);
uint16_t		op_lldi(t_all *all, t_op *op, uint8_t *content);
uint16_t		op_or(t_all *all, t_op *op, uint8_t *content);
uint16_t		op_st(t_all *all, t_op *op, uint8_t *content);
uint16_t		op_sti(t_all *all, t_op *op, uint8_t *content);
uint16_t		op_sub(t_all *all, t_op *op, uint8_t *content);
uint16_t		op_xor(t_all *all, t_op *op, uint8_t *content);
uint16_t		op_zjmp(t_all *all, t_op *op, uint8_t *content);


#endif

