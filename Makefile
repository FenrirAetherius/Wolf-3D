# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2020/02/27 17:45:12 by mrozniec          #+#    #+#             #
#   Updated: 2020/03/06 14:48:25 by fenrir           ###   ########lyon.fr   #
#                                                                            #
# ************************************************************************** #

NAME = Wolf-3D

ifeq ($(shell uname), Linux)
TARGET = ft_printf/linux/libftprintf.a
FLAGS = -Wall -Wextra# -I minilibx -L minilibx -lmlx -lXext -lX11
else
TARGET = ft_printf/mac/libftprintf.a
FLAGS = -Wall -Wextra -I minilibx -L minilibx -lmlx
endif

SRC =	srcs/ft_error.c\
		srcs/ft_texture.c\
		srcs/init_map.c\
		srcs/ft_utils_map.c\
		srcs/ft_lst.c\
        main-test.c

HEADER =	header/$(wildcard *.h)

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@cc $(FLAGS) $(OBJ) $(TARGET)

%.o: %.c
	@cc -o $@ -c $< $(FLAGS)

.PHONY: clean fclean re all

clean:
	@/bin/rm $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
