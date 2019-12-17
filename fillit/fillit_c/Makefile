# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkayla <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/17 14:02:46 by hkayla            #+#    #+#              #
#    Updated: 2019/12/17 14:12:41 by hkayla           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

FLAG=-Wall -Wextra -Werror

INC=-I ./

SRC=main.c

OBJ=$(SRC:.c=.o)

LIB=./libft/libft.a

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(FLAG) $(OBJ) $(INC) $(LIB) -o $(NAME)

%.o:%.c
	gcc $(FLAG) $(INC) -c $< -o $@

all: $(NAME)

clean:
	make -C ./libft clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C ./libft fclean
	/bin/rm -rf $(NAME)

re: fclean all
