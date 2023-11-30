# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 12:03:14 by mechard           #+#    #+#              #
#    Updated: 2023/11/30 19:22:43 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

EXEC		= printf

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -fPIC
LIB			= libft/libft.a
LIB_H		= libft/libft.h
PATH_LIB 	= libft/

SRCS		= ft_printf.c ft_parse.c ft_convert.c \

OBJS_B		= ft_putnbr_fd.o ft_putstr_fd.o ft_putchar_fd.o \
				ft_nbrlen.o ft_itoa.o ft_strcmp.o ft_strdup.o \
				ft_strlen.o ft_strdup.o ft_strcpy.o ft_strcat.o \
				ft_strjoin.o ft_memmove.o ft_toupper.o
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
	@$(CC) $(CFLAGS) -I $(HEADERS) -I $(LIB_H) -c $<

$(NAME) : $(OBJS)
	@echo "<---------------------$(BLUE1)FT_PRINTF$(D_COLOR)------------------>"
	@make --no-print-directory -C $(PATH_LIB) libft.a
	@echo "   <--------------------$(BLUE1)PRINTF$(D_COLOR)------------------>\n"
	@ar rcs $(NAME) $(OBJS) $(OBJS_LIB)
	@ranlib $(NAME)
	@echo "            compilation de libftprintf.a $(GREEN1)OK$(D_COLOR)\n"

all : $(NAME)

clean :
	@echo "\n<------------------$(YELLOW1)Folder Clean$(D_COLOR)----------------->\n"
	@make --no-print-directory -C $(PATH_LIB) clean
	@rm -f $(OBJS)

fclean : clean
	@make --no-print-directory -C $(PATH_LIB) fclean
	@rm -f $(NAME)
	@echo "              $(NAME) $(RED1)SUPPRIME$(D_COLOR)\n"

leaks:
	@valgrind memusage ./$(NAME)

norme:
	@echo "<---------------------$(PINK2)$(BLACK1)Norminette$(D_COLOR)----------------------->\n"
	@norminette -R CheckDefine $(INC)
	@echo "\n                    NORMINETTE $(PINK1)OK$(D_COLOR)\n"

re : fclean all

.PHONY : all, clean, fclean, re