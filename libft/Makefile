# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manki <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 10:30:31 by manki             #+#    #+#              #
#    Updated: 2019/09/16 13:43:31 by manki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_bzero.c ft_putstr.c ft_putchar.c ft_putendl.c ft_putnbr.c ft_strnew.c \
	ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_strlen.c ft_memset.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_memmove.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_strncmp.c ft_strcmp.c ft_atoi.c \
	ft_toupper.c ft_memdel.c ft_tolower.c ft_memalloc.c ft_strnstr.c \
	ft_strclr.c ft_memcpy.c ft_memccpy.c ft_isascii.c ft_isprint.c \
	ft_strdel.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	ft_strsplit.c ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_abs.c ft_isspace.c \
	ft_strrev_fr.c ft_lstcount.c ft_printlst.c ft_isblank.c ft_printcolor.c \
	ft_strjoin.c ft_sqrt.c get_next_line.c ft_strjoin_fr.c ft_strrdel.c \
	ft_power.c ft_dtoa.c ft_strsub_fr.c ft_itoa_u.c ft_get_txt.c \
	ft_attribut.c ft_calc_bi.c ft_calc_float.c \
	ft_conv.c ft_conv_char.c ft_conv_f.c \
	ft_lst.c ft_printf.c ft_calc.c ft_calc_exposant.c \
	ft_check.c ft_conv_b.c ft_conv_e.c ft_conv_spe.c \
	ft_prec_champ.c ft_error.c ft_str_is_numeric.c ft_atoll.c \
	ft_sort_integer_table.c norme.c ft_uitoa_base.c

HEADER = libft.h

BIN_FOLDER = ./bin/

YELLOW = \033[0;33m

GREEN = \033[0;32m

END_COLOR = \033[0m

OBJ = $(addprefix $(BIN_FOLDER),$(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

bin:
	@mkdir bin

$(NAME): bin  $(HEADER) $(OBJ)
	ar rc $(NAME) $(OBJ)
	printf "$(GREEN) LIBFT DONE SUCESS! $(END_COLOR)"

$(BIN_FOLDER)%.o :%.c
	$(CC) $< -c -I $(HEADER) -o $@ $(FLAGS)
	printf "$(YELLOW) Compiling:$(END_COLOR) $<  $(GREEN)[OK] $(END_COLOR)              \r"

clean: 
	rm -rf $(BIN_FOLDER)
	printf "$(GREEN) Clean libft done $(END_COLOR)\n"

fclean: clean
	rm -rf $(NAME)
	printf "$(GREEN) Fclean libft done $(END_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re

.SILENT:
