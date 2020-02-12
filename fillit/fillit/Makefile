
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pberries <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/08 13:16:50 by pberries          #+#    #+#              #
#    Updated: 2020/02/09 16:27:49 by pberries         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = src/
INC_PATH = inc/
OBJ_PATH = obj/
LFT_PATH = libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = fillit.h
LIB := libft/libft.a

SRC_NAME =  checker.c   \
            main.c      \
            mapper.c    \
            reader.c    \
            shifter.c   \
            solver.c

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft

$(OBJ): $(OBJ_PATH)%.o: $(SRC_PATH)%.c $(addprefix $(INC_PATH),$(INC_NAME))
	mkdir -p $(OBJ_PATH)
	gcc $(FLAGS) $(INC)  -o $@ -c $<

.FORCE:

$(LIB):.FORCE
	make -C $(LFT_PATH)

clean:
	make -C $(LFT_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LFT_PATH) fclean
	rm -f $(NAME)

re: fclean all
