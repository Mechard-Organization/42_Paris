# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 12:03:14 by mechard           #+#    #+#              #
#    Updated: 2024/02/19 11:59:47 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

EXEC		= printf

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -fPIC
LIB			= libft/libft.a
LIB_H		= libft/libft.h
PATH_LIB 	= libft/

SRCS		= ft_printf.c ft_print_mand.c ft_check.c

OBJS_B		= ft_putstr_fd.o ft_strdup.o ft_strlen.o ft_strcpy.o ft_isdigit.o \
				ft_nbrlen.o ft_atoi.o
OBJS_LIB 	= $(addprefix libft/, $(OBJS_B))

OBJS		= $(SRCS:.c=.o)

#reset_color#

D_COLOR = \033[0m

#color_text#

BLACK1	= \033[30m
RED1	= \033[31m
GREEN1	= \033[32m
YELLOW1	= \033[33m
BLUE1	= \033[34m
PINK1	= \033[35m
CYAN1	= \033[36m
GREY1	= \033[37m

#color_background#

BLACK2	= \033[40m
RED2	= \033[41m
GREEN2	= \033[42m
YELLOW2	= \033[43m
BLUE2	= \033[44m
PINK2	= \033[45m
CYAN2	= \033[46m
GREY2	= \033[47m

%.o: %.c
	@$(CC) $(CFLAGS) -I $(HEADER) -I $(LIB_H) -c $< > /dev/null 2>&1

$(NAME) : $(OBJS)
	@make --no-print-directory -C $(PATH_LIB) libft.a > /dev/null 2>&1
	@ar rcs $(NAME) $(OBJS) $(OBJS_LIB) > /dev/null 2>&1
	@ranlib $(NAME) > /dev/null 2>&1

all : $(NAME)

clean :
	@make --no-print-directory -C $(PATH_LIB) clean > /dev/null 2>&1
	@rm -f $(OBJS)

fclean : clean
	@make --no-print-directory -C $(PATH_LIB) fclean > /dev/null 2>&1
	@rm -f $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re