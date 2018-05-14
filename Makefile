# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/05/04 14:58:34 by quruiz       #+#   ##    ##    #+#        #
#    Updated: 2018/05/14 18:40:44 by quruiz      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = quruiz.filler
LIB = libft/libft.a
FLAG = -Werror -Wall -Wextra
HEADERS = libft/libft/libft.h libft/get_next_line/get_next_line.h include/filler.h
FILLER_SRC = src/error.c src/heat_map.c src/main.c src/piece.c src/solver.c
LIBFT_SRC = ft_atoi.c ft_bzero.c ft_conncat.c ft_intlen.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c \
	ft_isupper.c ft_itoa.c ft_itoa_base.c ft_lstadd.c ft_lstdel.c \
	ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
	ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
	ft_putnbr.c ft_putnbr_fd.c ft_putnstr_fd.c ft_putnwstr_fd.c ft_putstr.c \
	ft_putstr_fd.c ft_putstrchar.c ft_putwchar.c ft_putwchar_fd.c ft_putwstr.c \
	ft_putwstr_fd.c ft_recursive_factorial.c ft_recursive_power.c ft_sqrt.c \
	ft_str_is_alpha.c ft_str_is_lowercase.c ft_str_is_numeric.c \
	ft_str_is_printable.c ft_str_is_uppercase.c ft_str_realloc.c \
	ft_strcapitalize.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
	ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strlowcase.c ft_strmap.c ft_strmapi.c \
	ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	ft_strupcase.c ft_swap.c ft_tab_realloc.c ft_tolower.c ft_toupper.c \
	ft_wcharlen.c ft_wstrdup.c ft_wstrlen.c
GNL_SRC = get_next_line/get_next_line.c
LIB_SRC = $(addprefix libft/libft/, $(LIBFT_SRC)) $(addprefix libft/, $(GNL_SRC))
FILLER_OBJ = $(FILLER_SRC:.c=.o)
LIB_OBJ = $(LIB_SRC:.c=.o)
OBJ = $(LIB_OBJ) $(FILLER_OBJ)

all: $(NAME)

%.o: %.c $(HEADERS)
		@gcc $(FLAG) -c $< -o $@

$(NAME): $(OBJ)
		@ar rc $(LIB) $(OBJ)
		@ranlib $(LIB)
		@gcc $(FLAG) $(FILLER_OBJ) $(LIB) -o $(NAME)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME) $(LIB)

re: fclean all
