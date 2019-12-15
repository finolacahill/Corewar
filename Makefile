# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adietric <adietric@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 13:22:46 by adietric          #+#    #+#              #
#    Updated: 2019/12/15 18:09:53 by adietric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

LIB_PATH = ./libft

SRCS_PATH = ./srcs

OBJLIB_PATH = ./obj

OBJ_PATH = ./obj

MAIN_PATH = ./main

OBJM_PATH = ./main



SRCS_NAME = dasm_get_data.c		\
			dasm_get_exec.c		\
			dasm_header.c		\
			dasm_input.c		\
			dasm_is_cor.c		\
			dasm_print_usage.c	\
			dasm_realloc.c		\
			dasm_init.c			\
			dasm_rdm.c			\
			print_all.c			\
			vm_print_intro.c	\
			vm_init_arena.c		\
			vm_load_processes.c \
			vm_errors.c 		\
			vm_decode_bytes.c	\
			vm_operations.c 	\
			op_live.c			\
			op_st.c				\
			op_ld.c 			\
			op_add.c			\
			op_sub.c			\
			vm_get_values.c		\
			vm_load_values.c	\
			vm_tab_check.c		\
			vm_check_op_block.c


MAIN_NAME = main.c

OBJ_NAME = $(SRCS_NAME:.c=.o)

OBJM_NAME = $(MAIN_NAME:.c=.o)

LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJM = $(addprefix $(OBJM_PATH)/,$(OBJM_NAME))

INCL = ./includes/vm.h

CC = gcc -g3

FLAG = -Wall -Werror -Wextra -fsanitize=address

.PHONY: all clean fclean re

all: check $(NAME)

check:
	@make -C ./libft

$(NAME): $(OBJ) $(OBJM) $(INCL)
	@$(CC) $(FLAG) $(OBJ) $(OBJM) -I $(INCL) ./libft/libft.a -o $(NAME)

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJM_PATH)/%.o: $(MAIN_PATH)/%.c
	@mkdir $(OBJM_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	make clean -C ./libft
	rm -rf $(OBJ) $(OBJLIB) $(OBJM)
	rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
