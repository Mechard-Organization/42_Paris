# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 20:03:06 by abutet            #+#    #+#              #
#    Updated: 2024/04/25 15:14:12 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
EXEC_DIR	= exec/

SUCCESS	= Ok
PREVIOUS_CONTENT := 0
DELETED	= supprime !
SILENCE	= > /dev/null 2>&1
MAKE	= make --no-print-directory -C ./
FIN		= ===========END===========

#==================SOURCES==================

TOOLS_DIR		= tools/
TOOLS_PS		= ft_splitav.c error.c free.c push.c reverse_rotate.c rotate.c \
					swap.c search.c utils.c
TOOLS_PLACE		= $(addprefix $(TOOLS_DIR), $(TOOLS_PS)) #chemin de tout les outils (les mooves, les free, les erreurs,... etc)

SORT_DIR		= sort/

SORT_PS			= set_a.c set_b.c sort.c sort3.c
SORT_PLACE		= $(addprefix $(SORT_DIR), $(SORT_PS)) #chemin des fonstions de tri

SRC		= ft_atoi.c ft_isalpha.c ft_lstadd_back.c ft_lstlast.c ft_memcmp.c \
			ft_nbrlen.c ft_putnbr_fd.c ft_strcmp.c ft_strlcat.c ft_strnstr.c \
			ft_toupper.c ft_bzero.c ft_isascii.c ft_lstadd_front.c ft_lstmap.c \
			ft_memcpy.c ft_printf.c ft_putstr_fd.c ft_strcpy.c ft_strlcpy.c \
			ft_strrchr.c get_next_line.c ft_calloc.c ft_isdigit.c ft_lstclear.c \
			ft_lstnew.c ft_memdel.c ft_print_mand.c ft_split.c ft_strdup.c \
			ft_strlen.c ft_strtrim.c get_next_line_utils.c ft_check.c \
			ft_isprint.c ft_lstdelone.c ft_lstsize.c ft_memmove.c \
			ft_putchar_fd.c ft_strcat.c ft_striteri.c ft_strmapi.c ft_substr.c \
			ft_isalnum.c ft_itoa.c ft_lstiter.c ft_memchr.c ft_memset.c \
			ft_putendl_fd.c ft_strchr.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
			ft_pipex.c pipex.c tools_pipex.c ft_push_swap.c
SRC_DIR	= src/

#===================OBJETS===================

OBJ		= $(SRC:.c=.o) $(TOOLS_PS:.c=.o) $(SORT_PS:.c=.o)
OBJ_DIR	= obj/

#===================HEADER====================

HEAD_DIR	= inc/

#===================VAR_GBL===================

SRCS	= $(addprefix $(SRC_DIR), $(SRC)) $(addprefix $(SRC_DIR), $(TOOLS_PLACE)) \
			$(addprefix $(SRC_DIR), $(SORT_PLACE))
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

#====================FLAG=====================

FLAG_CP	= -Wall -Wextra -Werror -g3
HEADERS	= -I$(HEAD_DIR)
CC		= cc $(FLAG_CP) $(HEADERS)
TO_OBJ	= -c

#====================COLOR=====================

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

all : $(NAME)

$(OBJS): $(SRCS)
	@if [ "$(PREVIOUS_CONTENT)" = "1" ]; then \
		$(MAKE) clear_pline; \
		echo "0" > .prev_content; \
		$(eval PREVIOUS_CONTENT = $(shell cat .prev_content)) \
	fi
	@echo "==========$(YELLOW1)LIBFT$(D_COLOR)==========\n"
	@$(MAKE) norminette
	@$(MAKE) lib_creation
	@$(MAKE) end

$(NAME) : $(OBJS)

clean :
	@if [ -d "./obj" ]; then \
		if [ "$(PREVIOUS_CONTENT)" = "1" ]; then \
			$(MAKE) clear_pline; \
			echo "0" > .prev_content; \
			$(eval PREVIOUS_CONTENT = $(shell cat .prev_content)) \
		fi; \
		echo "========$(CYAN1)OBJ_LIBFT$(D_COLOR)========\n"; \
		rm -rf $(OBJ_DIR) $(SILENCE); \
		echo "$(RED1)$(DELETED)$(D_COLOR)\n"; \
		$(MAKE) end; \
	else \
		echo "\rmake: Nothing to be done for 'clean'."; \
	fi

fclean : clean
	@if [ -d "./exec" ]; then \
		if [ "$(PREVIOUS_CONTENT)" = "1" ]; then \
			$(MAKE) clear_pline; \
			echo "0" > .prev_content; \
			$(eval PREVIOUS_CONTENT = $(shell cat .prev_content)) \
		fi; \
		echo "=========$(CYAN1)LIBFT.A$(D_COLOR)=========\n"; \
		rm -rf $(EXEC_DIR) $(SILENCE); \
		echo "$(RED1)$(DELETED)$(D_COLOR)\n"; \
		$(MAKE) end; \
	else \
		$(MAKE) clear_pline; \
		echo -e "\rmake: Nothing to be done for 'fclean'."; \
	fi

norminette : $(SRCS)
	-@norminette src/ > res_cmd || true
	-@grep 'Error' res_cmd > norminette || true
	-@norminette inc/ > res_cmd || true
	-@grep "Error" res_cmd >> norminette || true
	@rm res_cmd
	@if [ ! -s norminette ]; then \
    	rm norminette; \
		echo "\nnorminette des .c de $(NAME) : $(GREEN1)OK!$(D_COLOR)\n"; \
	else \
   		echo "\nnorminette des .c de $(NAME) : $(RED1)Erreur!$(D_COLOR)\n"; \
		cat norminette; \
		echo "\n"; \
		rm norminette; \
	fi

lib_creation :
	@$(CC) $(TO_OBJ) $(SRCS)
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ) $(OBJ_DIR)
	@ar rcs $(NAME) $(OBJS) $(SILENCE)
	@ranlib $(NAME) $(SILENCE)
	@echo "$(NAME) : $(GREEN1)$(SUCCESS)$(D_COLOR)\n"
	@mkdir -p $(EXEC_DIR)
	@mv $(NAME) $(EXEC_DIR)

clear_pline :
	@printf "\033[1A"
	@printf "\033[K"

end :
	@if [ "$(PREVIOUS_CONTENT)" = "0" ]; then \
		echo "===========$(GREEN1)END$(D_COLOR)==========="; \
		echo "1" > .prev_content; \
		$(eval PREVIOUS_CONTENT = $(shell cat .prev_content)) \
	fi
	
re : fclean all

.PHONY : all, clean, fclean, re, bonus