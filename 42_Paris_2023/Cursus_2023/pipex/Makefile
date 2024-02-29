# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 12:44:13 by mechard           #+#    #+#              #
#    Updated: 2024/02/28 12:30:22 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===================VAR_GBL===================

NAME			= pipex
HEADER			= inc/pipex.h
SRC_PIPEX		= pipex.c main.c tools_pipex.c

CC 				= cc
CFLAGS			= -Wall -Wextra -Werror -g3

TOOLS			= tools/

#====================LIBFT====================

LIB				= $(addprefix $(TOOLS), libft/)
NAME_LIB		= libft.a
LIB_A			= $(addprefix $(LIB), $(NAME_LIB))

SRC_L			= ft_putchar_fd.c ft_strlen.c ft_putstr_fd.c ft_putnbr_fd.c ft_strjoin.c \
				ft_strdup.c ft_strncmp.c
SRC_LIB			= $(addprefix $(LIB), $(SRC_L))

#==================FT_PRINTF==================

LIB_PRTF		= $(addprefix $(TOOLS), ft_printf/)
NAME_PRTF		= libftprintf.a
LIB_PRTF_A		= $(addprefix $(LIB_PRTF), $(NAME_PRTF))

#================GET_NEXT_LINE================

GNL				= $(addprefix $(TOOLS), get_next_line/)
SRC_G			= get_next_line.c get_next_line_utils.c

SRC_GNL			= $(addprefix $(GNL), $(SRC_G))

#===================SRC_GBL===================

SRCS			= $(SRC_PIPEX) $(SRC_GNL) $(LIB_A) $(LIB_PRTF_A)

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
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)
	@echo "==========$(BLUE1)LIBFT$(D_COLOR)==========\n"
	@ make --no-print-directory -C $(LIB) re
	@echo "Libft : $(GREEN1)Ok$(D_COLOR)\n"
	@echo "==========$(BLUE1)FT_PRINTF$(D_COLOR)=======\n"
	@ make --no-print-directory -C $(LIB_PRTF) re
	@echo "ft_printf : $(GREEN1)Ok$(D_COLOR)\n"
	@echo "==========$(YELLOW1)PIPEX$(D_COLOR)==========\n"
	@echo "./pipex : $(GREEN1)Ok$(D_COLOR)\n"

bonus : all

clean : aclean
	@ make --no-print-directory -C $(LIB) clean
	@ make --no-print-directory -C $(LIB_PRTF) clean

aclean :

fclean : clean
	@ rm -rf $(NAME)
	
afclean : fclean
	@ make --no-print-directory -C $(LIB) fclean > /dev/null 2>&1
	@ make --no-print-directory -C $(LIB_PRTF) fclean > /dev/null 2>&1
	

re : fclean all

.PHONY : all, clean, fclean, re, bonus