# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adietric <adietric@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/30 14:41:01 by flafonso          #+#    #+#              #
#    Updated: 2020/01/13 10:58:52 by adietric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ_PATH = ./obj_lib
SRC_PATH = ./

SRC_NAME =	ft_atol.c ft_lstaddend.c ft_numlen.c getchar.c get_next_line.c		\
		ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c			\
		ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c			\
		ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c			\
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c		\
		ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c			\
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c			\
		ft_strnew.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c			\
		ft_strequ.c ft_strnequ.c ft_strjoin.c ft_strsub.c ft_strtrim.c			\
		ft_putchar.c ft_putstr.c ft_putendl.c ft_pfputnbr.c ft_putchar_fd.c		\
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strdel.c ft_strmapi.c	\
		ft_itoa.c ft_strsplit.c ft_revmemcpy.c ft_lstnew.c ft_lstdelone.c		\
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_wordcounter.c		\
		ft_isspace.c ft_sqrt.c ft_factorial.c ft_swap.c ft_char.c ft_flags.c	\
		ft_hex.c ft_int.c ft_itoa_base.c ft_octal.c ft_percent.c ft_point.c		\
		ft_printf.c ft_str.c ft_uitoa_base.c ft_unint.c ft_read.c ft_float.c	\
		ft_itoa_float.c ft_error.c ft_specifiers.c ft_buffer.c ft_returnerror.c	\
		ft_roundstr.c ft_readu.c ft_numlen.c ft_unumlen.c ft_printfloat.c		\
		ft_putstrb.c ft_uputnbr.c ft_pfputnbr.c ft_binary.c ft_puissance.c		\
		ft_putnbr.c ft_reverse.c ft_long_atoi.c ft_itoa_base.c ft_long_atoi.c	\
		ft_puissance.c ft_reverse.c ft_uitoa_base.c ft_fprintf.c ft_power.c		\
		ft_strjoin_fr.c ft_strrdel.c

HEAD = libft.h get_next_line.h

CFLAGS = -Wall -Werror -Wextra
CC = gcc -g3

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

.PHONY: all clean fclean re

all: $(NAME)
	@:

$(NAME): $(OBJ) $(HEAD)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(BOLD)$(GREY)  *lib-$(GREEN)[$(NAME) done]$(END)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "$(BOLD)$(GREY)  *lib-$(GREEN)[clean]$(END)"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "$(BOLD)$(GREY)  *lib-$(GREEN)[fclean]$(END)"

just_f:
	@/bin/rm -rf $(NAME)
	@echo "$(BOLD)$(GREY)  *lib-$(GREEN)[fclean]$(END)"

re: fclean all

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
