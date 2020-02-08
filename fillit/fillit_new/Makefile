# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkayla <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/17 14:02:46 by hkayla            #+#    #+#              #
#    Updated: 2020/02/07 14:09:42 by hkayla           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

SRCS=*.c

OBJ=$(SRC:.c=.o))

CC = gcc
FLAGS=-Werror -Wextra -Wall

# ft library
LIBFT= ./libft/

# directories
SRCDIR= ./src/

all: $(NAME)

$(NAME):
	@make -C $(LIBFT) re
	$(CC) -o $(NAME) $(FLAGS) $(SRCDIR)$(SRCS) $(LIBFT)libft.a

clean:
	@make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
