# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pberries <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 12:25:33 by hkayla            #+#    #+#              #
#    Updated: 2020/02/09 14:59:56 by pberries         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CFLAGS=-Wall -Wextra -Werror

SRCS=   ft_lstdel.c             \
        ft_putendl.c            \
        ft_strcpy.c             \
        ft_strnew.c             \
        ft_atoi.c               \
        ft_lstdelone.c          \
        ft_putendl_fd.c         \
        ft_strdel.c             \
        ft_strnstr.c            \
        ft_bzero.c              \
        ft_lstiter.c            \
        ft_putnbr.c             \
        ft_strdup.c             \
        ft_strrchr.c            \
        ft_div_mod.c            \
        ft_lstmap.c             \
        ft_putnbr_fd.c          \
        ft_strequ.c             \
        ft_strrev.c             \
        ft_dup.c                \
        ft_lstnew.c             \
        ft_putstr.c             \
        ft_striter.c            \
        ft_strsplit.c           \
        ft_isalnum.c            \
        ft_memalloc.c           \
        ft_putstr_fd.c          \
        ft_striteri.c           \
        ft_strstr.c             \
        ft_isalpha.c            \
        ft_memccpy.c            \
        ft_str_is_alpha.c       \
        ft_strjoin.c            \
        ft_strsub.c             \
        ft_isascii.c            \
        ft_memchr.c             \
        ft_str_is_lowercase.c   \
        ft_strlcat.c            \
        ft_strtrim.c            \
        ft_isdigit.c            \
        ft_memcmp.c             \
        ft_str_is_uppercase.c   \
        ft_strlen.c             \
        ft_swap.c               \
        ft_islower.c            \
        ft_memcpy.c             \
        ft_strcat.c             \
        ft_strmap.c             \
        ft_tolower.c            \
        ft_isprint.c            \
        ft_memdel.c             \
        ft_strchr.c             \
        ft_strmapi.c            \
        ft_toupper.c            \
        ft_isupper.c            \
        ft_memmove.c            \
        ft_strclr.c             \
        ft_strncat.c            \
        ft_itoa.c               \
        ft_memset.c             \
        ft_strcmp.c             \
        ft_strncmp.c            \
        ft_lstadd.c             \
        ft_putchar.c            \
        ft_strcntendchar.c      \
        ft_strncpy.c            \
        ft_lstaddend.c          \
        ft_putchar_fd.c         \
        ft_strcntstartchar.c    \
        ft_strnequ.c
OBJECTS = $(SRCS:.c=.o)

INCLUDES=./

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS) libft.h
	@gcc $(CFLAGS) -I $(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
