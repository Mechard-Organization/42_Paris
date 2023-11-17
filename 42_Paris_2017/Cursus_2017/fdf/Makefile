# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 05:07:51 by tarchen           #+#    #+#              #
#    Updated: 2017/11/21 00:51:06 by tarchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

PATH_LIBFT = ./libft/libft.a

CFLAGS = 	-Wall -Wextra -Werror -g

SRC = fdf.c	mlx_draw_line.c	\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(PATH_LIBFT) -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
	@echo "\033[36mrule \033[32mall:	Done.\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[36mrule \033[32mclean:	Done.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[36mrule \033[32mfclean:	Done.\033[0m"

re: fclean all clean

.PHONY: all lib clean fclean re