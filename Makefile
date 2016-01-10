# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmorales <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/21 11:06:58 by fmorales          #+#    #+#              #
#    Updated: 2015/11/01 18:46:32 by fmorales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	main.c \
	  	anthill.c \
	  	main.c \
	  	ants.c \
	  	room.c \
	  	pipe.c \
	  	move.c \
	  	put_path.c \
	  	check.c \
	  	error.c

DIR = srcs/
LIB = libft/
HEADER = includes/
FLAGS = -Wall -Wextra -Werror -g
OBJ = $(SRC:.c=.o)
NAME = lem-in

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIB)
	@gcc $(FLAGS) -o $(NAME) $^ -L$(LIB) -lft
	@echo "lemin-in is ready. Enjoy!"

%.o: $(DIR)%.c
	@gcc $(FLAGS)  -o $@ -c $< -I$(LIB)$(HEADER) -I$(HEADER)

clean:
	@rm -f $(OBJ)
	@make clean -s -C $(LIB)
	@echo "Objects deleted"

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIB)
	@echo "Folder cleanup successful"

re: fclean all

.PHONY: all clean fclean re
