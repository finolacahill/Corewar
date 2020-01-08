# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 13:22:46 by adietric          #+#    #+#              #
#    Updated: 2020/01/08 19:02:57 by flafonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
NAME_TWO = asm

LIB_NAME = libft.a
LIB_PATH = ./libft
SRCS_PATH = ./srcs
OBJ_PATH = ./obj
MAIN_PATH = ./main
OBJM_PATH = ./main
OP_PATH = ./srcs/operations
SRC_ASM_PATH = ./src_asm

SRCS_NAME = dasm_get_data.c		\
			dasm_get_exec.c		\
			dasm_header.c		\
			dasm_input.c		\
			dasm_is_cor.c		\
			dasm_print_usage.c	\
			dasm_realloc.c		\
			dasm_init.c			\
			dasm_rdm.c			\
			vm_print_intro.c	\
			vm_init_arena.c		\
			vm_load_processes.c \
			vm_errors.c 		\
			vm_decode_bytes.c	\
			vm_check_alive.c 	\
			vm_get_values.c		\
			vm_load_values.c	\
			vm_tab_check.c		\
			vm_check_op_block.c	\
			init_op_check.c		\
			vm_free_structs.c	\
			vm_tools.c			\
			vm_run_vm.c			\
			vm_printing.c		\
			print_debug.c		\
			dasm_input_check.c	\
			dasm_check_hex_code.c

OP_NAME =	op_add.c	\
			op_aff.c	\
			op_and.c	\
			op_fork.c	\
			op_ld.c		\
			op_ldi.c	\
			op_lfork.c	\
			op_live.c	\
			op_lld.c	\
			op_lldi.c	\
			op_or.c		\
			op_st.c		\
			op_sti.c	\
			op_sub.c	\
			op_xor.c	\
			op_zjmp.c

SRC_ASM_NAME =	write.c			\
				utils_line.c	\
				utils_params.c	\
				error_cmd.c		\
				error.c			\
				cmd.c			\
				free.c			\
				utils.c			\
				ocp.c			\
				main.c			\
				init.c			\
				label.c			\
				instruc.c		\
				params.c		\
				calc.c

MAIN_NAME = main.c

OBJLIB_NAME = $(LIB_NAME:.c=.o)
OBJ_NAME = $(SRCS_NAME:.c=.o)
OBJM_NAME = $(MAIN_NAME:.c=.o)
OBJ_OP_NAME = $(OP_NAME:.c=.o)
OBJ_ASM_NAME = $(SRC_ASM_NAME:.c=.o)

LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
SRCS_ASM = $(addprefix $(SRC_ASM_PATH)/, $(SRC_ASM_NAME))
OBJ_ASM = $(addprefix $(OBJ_PATH)/,$(OBJ_ASM_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJM = $(addprefix $(OBJM_PATH)/,$(OBJM_NAME))
OBJOP = $(addprefix $(OP_PATH)/,$(OP_NAME))

INCL =	./includes/vm.h
INCL_ASM =	./includes/corewar.h


CC = gcc -g3

FLAG = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: lib $(NAME) $(NAME_TWO)

lib: $(LIB_PATH)
	@make -C $(LIB_PATH)

$(NAME): $(LIB) $(OBJ) $(OBJM) $(INCL) $(OBJOP)
	@$(CC) $(FLAG) $(OBJOP) $(OBJM) $(LIB) $(OBJ) -I $(INCL) -o $(NAME)
	@echo "$(BOLD)$(GREY)*dasm-$(GREEN)[$(NAME) done]$(END)"

$(NAME_TWO): $(LIB) $(OBJ_ASM) $(INCL_ASM)
	@$(CC) $(LIB) $(OBJ_ASM) -I $(INCL_ASM) -o $(NAME_TWO)
	@echo "$(BOLD)$(GREY)*asm-$(GREEN)[$(NAME_TWO) done]$(END)"

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJ_PATH)/%.o: $(OP_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJM_PATH)/%.o: $(MAIN_PATH)/%.c
	@mkdir $(OBJM_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJ_PATH)/%.o: $(SRC_ASM_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	@make clean -C ./libft
	@rm -rf $(OBJ) $(OBJM) $(OBJ_ASM)
	@rm -rf $(OBJ_PATH)
	@echo "$(BOLD)$(GREY)*dasm-$(GREEN)[clean]$(END)"

fclean: clean
	@make just_f -C ./libft
	@rm -f $(NAME)
	@rm -f $(NAME_TWO)
	@echo "$(BOLD)$(GREY)*dasm-$(GREEN)[fclean]$(END)"

re: fclean all
	@sleep 1

####____________####
##// Pimp List  \\##
#||	(Colors and ||##
#||		Effects)||##
################################################################################
# Effects
END = \033[0m
BOLD = \033[1m
UNDER = \033[4m
REV = \033[7m

# Text Colors
GREY = \033[38;5;246m
RED = \033[38;5;160m
GREEN = \033[38;5;118m
YELLOW = \033[38;5;226m
BLUE = \033[38;5;12m
PURPLE = \033[38;5;129m
CYAN = \033[38;5;45m
WHITE = \033[38;5;231m
BLACK = \033[38;5;0m

# Backgrounds Colors
IGREY = \033[48;5;246m
IRED = \033[48;5;160m
IGREEN = \033[48;5;118m
IYELLOW = \033[48;5;226m
IBLUE = \033[48;5;12m
IPURPLE = \033[48;5;129m
ICYAN = \033[48;5;45m
IWHITE = \033[48;5;231m
IBLACK = \033[48;5;0m

pimp:
	@echo "$(END)$(BOLD)$(UNDER)Text Colors :$(END)\n\n$(GREY)Gris\n\
	$(RED)Rouge\n$(GREEN)Vert\n$(YELLOW)Jaune\n$(BLUE)Bleu\n$(PURPLE)Violet\n\
	$(CYAN)Cyan\n$(WHITE)Blanc\n$(BLACK)Noir"
	@echo "\n"
	@echo "$(END)$(BOLD)$(UNDER)Backgrounds Colors :$(END)\n\n$(IGREY)Gris\n\
	$(IRED)Rouge\n$(IGREEN)Vert\n$(IYELLOW)Jaune\n$(IBLUE)Bleu\n\
	$(IPURPLE)Violet\n$(ICYAN)Cyan\n$(IWHITE)Blanc\n$(IBLACK)Noir"
	@echo "\n"
	@echo "$(END)$(BOLD)$(UNDER)Effects :$(END)\n\nNormal\n$(END)\
	$(BOLD)Gras\n$(END)$(UNDER)Souligner\n$(END)$(REV)Inverse$(END)"
################################################################################