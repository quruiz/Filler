# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/05/04 14:58:34 by quruiz       #+#   ##    ##    #+#        #
#    Updated: 2018/05/15 19:12:11 by quruiz      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = quruiz.filler
LIBFT = libft/libft.a
HEADER = include/filler.h libft/libft/libft.h libft/get_next_line/get_next_line.h
FLAG = -Werror -Wall -Wextra
SRC = src/error.c src/heat_map.c src/main.c src/piece.c src/solver.c
OBJ = $(SRC:.c=.o)

all: lib $(NAME)

%.o: %.c $(HEADER)
		gcc $(FLAG) -c $< -o $@

lib:
		make -C libft

$(NAME): $(OBJ) $(LIBFT)
		gcc $(FLAG) $(OBJ) $(LIBFT) -o $(NAME)

clean:
		make clean -C libft/
		rm -f $(OBJ)

fclean: clean
		make fclean -C libft/
		rm -f $(NAME)

re: fclean all
