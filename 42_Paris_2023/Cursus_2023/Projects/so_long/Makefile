# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 12:44:13 by mechard           #+#    #+#              #
#    Updated: 2024/03/21 12:41:19 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===================VAR_GBL===================

NAME			= so_long
HEADER			= -Iinc -Iinc/libft/inc -Iinc/minilibx/
LIB_X11			= -lXext -lX11 -lm
SRC				= so_long.c verif_map.c game.c
SRC_PIPEX		= $(addprefix src/, $(SRC))

CC 				= cc
CFLAGS			= -Wall -Wextra -Werror -g3

INC				= inc/

#====================LIBFT====================

LIB				= libft.a
LIB_DIR			= $(addprefix $(INC), libft/)
LIB_EXEC		= $(addprefix $(LIB_DIR), exec/)
LIB_A			= $(addprefix $(LIB_EXEC), $(LIB))

#=====================MLX=====================

MLX				= libmlx.a
MLX_DIR			= $(addprefix $(INC), minilibx/)
MLX_A			= $(addprefix $(MLX_DIR), $(MLX))

#===================SRC_GBL===================

SRCS			= $(SRC_PIPEX) $(LIB_A) $(MLX_A)

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

$(NAME) : $(SRCS)
	@echo "===========$(YELLOW1)MLX$(D_COLOR)==========\n"
	@$(CC) $(CFLAGS) -IX11 $(SRCS) $(HEADER) $(LIB_X11) -o $(NAME)
	@echo "./so_long : $(GREEN1)Ok$(D_COLOR)\n"

$(LIB_A) :
	@ make --no-print-directory -C $(LIB_DIR) $(LIB) 

all : $(NAME)

bonus : all

clean :

clean_lib :
	@ make --no-print-directory -C $(LIB_DIR) clean

fclean : clean
	@ make --no-print-directory -C $(LIB_DIR) fclean
	@echo "==========$(CYAN1)EXEC$(D_COLOR)===========\n"
	@rm -rf $(NAME)
	@echo "$(RED1)supprime !$(D_COLOR)\n"
	
re : fclean all

.PHONY : all, clean, fclean, re, bonus