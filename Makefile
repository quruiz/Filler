# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/05/04 14:58:34 by quruiz       #+#   ##    ##    #+#        #
#    Updated: 2018/05/10 17:09:25 by quruiz      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = quruiz.filler
LIBFT = libft/libft.a
FLAG = -Werror -Wall -Wextra
SRC = src/error.c src/heat_map.c src/main.c src/piece.c src/solver.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c include/filler.h
		@gcc $(FLAG) -c $< -o $@

$(NAME): $(OBJ)
		@make -C libft/
		@gcc $(FLAG) $(OBJ) $(LIBFT) -o $(NAME)

clean:
		@make clean -C libft/
		@rm -f $(OBJ)

fclean: clean
		@make fclean -C libft/
		@rm -f $(NAME)

re: fclean all
