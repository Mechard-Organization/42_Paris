# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 12:44:13 by mechard           #+#    #+#              #
#    Updated: 2024/03/26 19:33:01 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===================VAR_GBL===================

NAME			= push_swap
HEADER			= -Iinc -Iinc/libft/inc

CC 				= cc
CFLAGS			= -Wall -Wextra -Werror -g3

INC				= inc/

SRC				= src/main.c src/sort/set_a.c src/sort/set_b.c src/sort/sort.c \
					src/sort/sort3.c src/tools/ft_splitav.c src/tools/error/error.c \
					src/tools/free/free.c src/tools/moove/push.c \
					src/tools/moove/reverse_rotate.c src/tools/moove/rotate.c \
					src/tools/moove/swap.c src/tools/stack/search.c \
					src/tools/stack/utils.c

#====================LIBFT====================

LIB				= libft.a #inclu Libft, ft_printf, get_next_line et pipex
LIB_DIR			= $(addprefix $(INC), libft/)
LIB_PLACE		= $(addprefix $(LIB_DIR), exec/)
LIB_A			= $(addprefix $(LIB_PLACE), $(LIB))

#===================SRC_GBL===================

SRC_ALL			= $(SRC) $(LIB_A)

#====================COLOR====================

#_________RESET_COLOR__________

D_COLOR = \033[0m

#__________COLOR_TEXT__________

BLACK1	= \033[30m
RED1	= \033[31m
GREEN1	= \033[32m
YELLOW1	= \033[33m
BLUE1	= \033[34m
PINK1	= \033[35m
CYAN1	= \033[36m
GREY1	= \033[37m

#_______COLOR_BACKGROUND_______

BLACK2	= \033[40m
RED2	= \033[41m
GREEN2	= \033[42m
YELLOW2	= \033[43m
BLUE2	= \033[44m
PINK2	= \033[45m
CYAN2	= \033[46m
GREY2	= \033[47m

#====================RULES====================

$(NAME) : $(SRC_ALL)
	@echo "========$(YELLOW1)PUSH_SWAP$(D_COLOR)========\n"
	@$(CC) $(CFLAGS) $(SRC_ALL) $(HEADER) -o $(NAME)
	@echo "./push_swap : $(GREEN1)Ok$(D_COLOR)\n"

$(LIB_A) :
	@ make --no-print-directory -C $(LIB_DIR) $(LIB) 

all : $(NAME)

bonus : all

clean : clean_lib

clean_lib :
	@make --no-print-directory -C $(LIB_DIR) clean

fclean : clean
	@make --no-print-directory -C $(LIB_DIR) fclean
	@echo "==========$(CYAN1)EXEC$(D_COLOR)===========\n"
	@rm -rf $(NAME)
	@echo "$(RED1)supprime !$(D_COLOR)\n"
	
re : fclean all

.PHONY : all, clean, fclean, re, bonus