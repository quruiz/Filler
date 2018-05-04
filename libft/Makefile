# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: quruiz <quruiz@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/18 12:41:18 by quruiz       #+#   ##    ##    #+#        #
#    Updated: 2018/05/01 23:58:48 by quruiz      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a
FLAG = -Werror -Wall -Wextra
SRC = $(shell find . -type f -name "*.c")
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
		@gcc $(FLAG) -c $^ -o $@

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ) $@ $^
		@ranlib $(NAME)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all
