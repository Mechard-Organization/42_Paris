# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 20:03:06 by abutet            #+#    #+#              #
#    Updated: 2024/01/19 19:06:23 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRC			= push_swap.c ft_move_pr.c ft_move_rr.c ft_move_s
SRCS		= $(addprefix ./src/, $(SRC))

OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix ./obj/, $(OBJ))

CFLAGS		= -Wall -Werror -Wextra
CC			= cc $(CFLAGS)
HEADERS		= -I ./inc/push_swap.h
PATH_LIB 	= libft/

#--------------COLOR--------------#

##RESET##

D_COLOR = \033[0m

##TEXT##

BLACK1	= \033[30m
RED1	= \033[31m
GREEN1	= \033[32m
YELLOW1	= \033[33m
BLUE1	= \033[34m
PINK1	= \033[35m
CYAN1	= \033[36m
GREY1	= \033[37m

##BACKGROUND##

BLACK2	= \033[40m
RED2	= \033[41m
GREEN2	= \033[42m
YELLOW2	= \033[43m
BLUE2	= \033[44m
PINK2	= \033[45m
CYAN2	= \033[46m
GREY2	= \033[47m

#---------------------------------#

./obj/%.o: ./src/%.c
	@$(CC) $(HEADERS) -c $< -o $@

$(NAME): obj $(OBJS)
	@echo "\n<----------------------$(BLUE1)PUSH_SWAP$(D_COLOR)-------------------->\n"
	@make --no-print-directory -C $(PATH_LIB)
	@echo "\n  <---------------------PUSH_SWAP--------------------->\n"
	@echo "             compilation des .c en .o $(GREEN1)OK$(D_COLOR)"
	@$(CC) $(HEADERS) -L$(PATH_LIB) -lft -o $(NAME) $(OBJS) -Llibft -lft
	@echo "        compilation du programme $(NAME) $(GREEN1)OK$(D_COLOR)"


obj:
	@mkdir -p obj

all : $(NAME)

clean :
	@rm -rf ./obj
	@echo "\n<------------------$(YELLOW1)Folder Clean$(D_COLOR)----------------->\n"
	@make --no-print-directory -C $(PATH_LIB) clean
	@echo "              Fichiers objets $(RED1)SUPPRIME$(D_COLOR)"

fclean : clean
	@make --no-print-directory -C $(PATH_LIB) fclean
	@rm -f $(NAME)
	@echo "                  $(NAME) $(RED1)SUPPRIME$(D_COLOR)"

re : fclean all

.PHONY : all, clean, fclean, re