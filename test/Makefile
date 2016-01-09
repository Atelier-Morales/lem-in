# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmorales <fmorales@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/27 16:01:27 by fmorales          #+#    #+#              #
#    Updated: 2014/02/23 01:19:14 by fmorales         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIB = libft/

HEADER = includes/

DIRSRC = srcs/

FLAGS = -Wall -Wextra -Werror -g

SRC = main.c \
	  nest.c \
	  main.c \
	  ants.c \
	  room.c \
	  pipe.c \
	  move.c \
	  put_path.c \
	  check.c \
	  error.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: init $(NAME)

init:
	@echo "\033[0;32m          $(NAME) PROJECT"

$(NAME): $(OBJ)
	@make -s -C $(LIB)
	@gcc $(FLAGS) -o $(NAME) $^ -L$(LIB) -lft

%.o: $(DIRSRC)%.c
	@gcc $(FLAGS) -o $@ -c $< -I$(LIB)$(HEADER) -I$(HEADER)

clean:
	@rm -f $(OBJ)
	@make clean -s -C $(LIB)
	@echo "\033[4;32mDeleted\033[0;33m $(OBJ)\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIB)
	@echo "\033[4;32mDeleted\033[0;33m $(NAME)\033[0m"

re: fclean all
