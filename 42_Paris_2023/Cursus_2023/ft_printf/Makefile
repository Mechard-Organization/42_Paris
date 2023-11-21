# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 12:03:14 by mechard           #+#    #+#              #
#    Updated: 2023/11/20 15:48:37 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c \

OBJS		= $(SRC:.c=.o)

HEADERS		= libft/libft.h libftprintf.h/

LIB			= libft.a
PATH_LIB 	= libft/

NAME		= libftprintf.a

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
	@cc -Wall -Wextra -Werror -I $(HEADERS) -c $(SRCS)

$(NAME) : $(OBJS)
	@echo "<---------------------$(BLUE1)FT_PRINTF$(D_COLOR)------------------>"
	@echo "   <--------------------$(BLUE1)LIBFT$(D_COLOR)------------------>\n"
	@make --no-print-directory -C $(PATH_LIB) libft.a
	@echo "   <--------------------$(BLUE1)PRINTF$(D_COLOR)------------------>\n"
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "            compilation de libftprintf.a $(GREEN1)OK$(D_COLOR)\n"
	@cc -g -o printf  main.c $(NAME) ./libft/libft.a

all : $(NAME)

clean :
	@echo "\n<------------------$(YELLOW1)Folder Clean$(D_COLOR)----------------->\n"
	@make --no-print-directory -C $(PATH_LIB) clean
	@rm -f $(OBJS)

fclean : clean
	@@make --no-print-directory -C $(PATH_LIB) fclean
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