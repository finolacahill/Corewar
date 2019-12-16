/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:27:24 by flafonso          #+#    #+#             */
/*   Updated: 2019/12/16 09:12:40 by flafonso         ###   ########.fr       */
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
	int					last_alive;
	int					last_alive_cycle;
	int					cycles;
	int					nbr_live_since_check;
	int					cycles_to_die;
	int					total_checks;
	int					check_mode;
	
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
	int					op_fail;
	struct s_process	*next;
}						t_process;

typedef	struct		s_op
{
	char				*op_name;
	void				(*inst)(t_all *vm, t_process *p);
}					t_op;

typedef	struct		s_verif_op
{
	uint16_t			(*inst)(t_all *all, uint8_t *content);
}					t_verif_op;

typedef struct			s_op_check
{
	char				*name;
	int					nb_param;
	int					ocp_value[9];
	int					op_code;
	int					nb_cycle;
	int					dir_size;
}						t_op_check;

t_op_check       		op_check_tab[17];

void			dasm_get_header(t_all *all, size_t cor_size, uint8_t **cor_content, t_champs *champs);
size_t			dasm_get_data(t_all	*all, char *cor_file, uint8_t **cor_content);
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
int				dasm_get_exec_code(uint8_t *cor_content, int len);
void			dasm_check_hex_code(t_all *vm);
void			error_exec(t_all *all, char *champ_name, uint16_t line);
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
int     		get_reg_val(t_all *vm, t_process *p, int bytes_read);
int     		get_ind(t_all *vm, t_process *p, int bytes_read);
void			load_value(t_all *vm, int address, int len, int val);
int				is_reg(int reg, t_process *p);
void    		check_carry(t_process *p, int param);
void    		load_val4_at_ind(t_all *vm, t_process *p, int val, int bytes_read);
void    		load_val_in_reg(t_all *vm, t_process *p, int val, int bytes_read);
int				check_op_block(t_all *vm, t_process *process);
int				is_in(int i, int value[9]);
void 			ft_print_arena(t_all *vm);

// operations
t_op			*init_op_check(t_all *vm, t_op *op);
t_verif_op		*init_op_verif(t_all *vm, t_verif_op *op);
void			op_live(t_all *vm, t_process *p);
void    		op_st(t_all *vm, t_process *p);
void    		op_ld(t_all *vm, t_process *p);
void    		op_sub(t_all *vm, t_process *p);
void    		op_add(t_all *vm, t_process *p);
void    		op_and(t_all *vm, t_process *p);
void    		op_or(t_all *vm, t_process *p);
void    		op_xor(t_all *vm, t_process *p);
void    		op_zjmp(t_all *vm, t_process *p);
void    		op_ldi(t_all *vm, t_process *p);
void    		op_sti(t_all *vm, t_process *p);
void    		op_fork(t_all *vm, t_process *p);
void    		op_lld(t_all *vm, t_process *p);
void    		op_lldi(t_all *vm, t_process *p);
void    		op_lfork(t_all *vm, t_process *p);
void    		op_aff(t_all *vm, t_process *p);

//verif operations
uint16_t		check_op_add(t_all *all, uint8_t *content);
uint16_t		check_op_aff(t_all *all, uint8_t *content);
uint16_t		check_op_and(t_all *all, uint8_t *content);
uint16_t		check_op_fork(t_all *all, uint8_t *content);
uint16_t		check_op_ld(t_all *all, uint8_t *content);
uint16_t		check_op_ldi(t_all *all, uint8_t *content);
uint16_t		check_op_lfork(t_all *all, uint8_t *content);
uint16_t		check_op_live(t_all *all, uint8_t *content);
uint16_t		check_op_lld(t_all *all, uint8_t *content);
uint16_t		check_op_lldi(t_all *all, uint8_t *content);
uint16_t		check_op_or(t_all *all, uint8_t *content);
uint16_t		check_op_st(t_all *all, uint8_t *content);
uint16_t		check_op_sti(t_all *all, uint8_t *content);
uint16_t		check_op_sub(t_all *all, uint8_t *content);
uint16_t		check_op_xor(t_all *all, uint8_t *content);
uint16_t		check_op_zjmp(t_all *all, uint8_t *content);



//errors
t_process *error_process(t_process *p);
#endif

