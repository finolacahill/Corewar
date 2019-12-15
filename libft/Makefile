NAME = libft.a
SRC = ft_power.c ft_strrev_fr.c ft_strjoin_fr.c ft_uitoa_base.c ft_atol.c ft_lstaddend.c ft_numlen.c getchar.c get_next_line.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strequ.c ft_strnequ.c ft_strjoin.c ft_strsub.c ft_strtrim.c ft_putchar.c ft_putstr.c ft_putendl.c ft_pfputnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strdel.c ft_strmapi.c ft_itoa.c ft_strsplit.c ft_revmemcpy.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_wordcounter.c ft_isspace.c ft_sqrt.c ft_factorial.c ft_swap.c ft_char.c ft_flags.c ft_hex.c ft_int.c ft_itoa_base.c ft_octal.c ft_percent.c ft_point.c ft_printf.c ft_str.c ft_uitoa_base.c ft_unint.c ft_read.c ft_float.c ft_itoa_float.c ft_error.c ft_specifiers.c ft_buffer.c ft_returnerror.c ft_roundstr.c ft_readu.c ft_numlen.c ft_unumlen.c ft_printfloat.c ft_putstrb.c ft_uputnbr.c ft_pfputnbr.c ft_binary.c
HEAD = libft.h get_next_line.h 

CFLAGS = -Wall -Werror -Wextra
CC = gcc -g
OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean: 
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
