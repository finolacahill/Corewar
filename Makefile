# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flafonso <flafonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 13:22:46 by adietric          #+#    #+#              #
#    Updated: 2019/11/30 19:36:11 by fcahill          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

LIB_PATH = ./libft

SRCS_PATH = ./srcs

OBJLIB_PATH = ./obj

OBJ_PATH = ./obj

MAIN_PATH = ./main

OBJM_PATH = ./main

LIB_NAME =	ft_atoi.c			\
			ft_bzero.c			\
			ft_isdigit.c		\
			ft_isspace.c		\
			ft_itoa.c			\
			ft_memalloc.c		\
			ft_memcpy.c			\
			ft_puissance.c		\
			ft_putchar.c		\
			ft_putnbr.c			\
			ft_putstr.c			\
			ft_reverse.c		\
			ft_strcat.c			\
			ft_strchr.c			\
			ft_strcmp.c			\
			ft_strcpy.c			\
			ft_strdel.c			\
			ft_strdup.c			\
			ft_strjoin.c		\
			ft_strlen.c			\
			ft_strncpy.c		\
			ft_strnew.c			\
			ft_strsub.c			\
			ft_memset.c

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
			op_live.c			


MAIN_NAME = main.c

OBJLIB_NAME = $(LIB_NAME:.c=.o)

OBJ_NAME = $(SRCS_NAME:.c=.o)

OBJM_NAME = $(MAIN_NAME:.c=.o)

LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJM = $(addprefix $(OBJM_PATH)/,$(OBJM_NAME))

INCL = ./includes/vm.h

CC = gcc -g3

FLAG = -Wall -Werror -Wextra -fsanitize=address

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB) $(OBJM) $(INCL)
	@$(CC) $(FLAG) $(OBJ) $(OBJLIB) $(OBJM) -I $(INCL) -o $(NAME)

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
	rm -rf $(OBJ) $(OBJLIB) $(OBJM)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
