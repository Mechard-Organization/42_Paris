# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 20:03:06 by abutet            #+#    #+#              #
#    Updated: 2024/07/09 14:31:15 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= libft.a
EXEC_DIR			= exec/
INC					= inc/

SUCCESS				= ✅
TELECHARGEMENT		= 🔽🔁
DL_FINISH			= 🔽✅
PRESENT				= Deja present !
DELETED				= 💥
SILENCE				= > /dev/null 2>&1
MAKE				= make --no-print-directory -C ./
FIN					= =================$(GREEN1)END$(D_COLOR)=================\n

#==================SOURCES==================

#_________MAIN_FOLDER__________

SRC					= ft_atoi.c ft_isalpha.c ft_lstadd_back.c ft_lstlast.c ft_memcmp.c \
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
						ft_pipex.c pipex.c tools_pipex.c game.c so_long.c
SRC_DIR				= src/

#________SO_LONG_FOLDER________

TOOLS_SO_LONG		= verif_map.c key.c free.c init.c image.c coor.c moove.c \
					collectibles.c ff.c
TOOLS_DIR			= $(addprefix tools_so_long/, $(TOOLS_SO_LONG))

#=====================MLX=====================

LIB_X11				= -lXext -lX11 -lm

MLX					= libmlx.a
MIN					= minilibx-linux
LINK_MLX			= https://cdn.intra.42.fr/document/document/21439/minilibx-linux.tgz
MLX_DIR				= $(addprefix $(INC), $(MIN)/)
MLX_A				= $(addprefix $(MLX_DIR), $(MLX))

#===================OBJETS===================

OBJ					= $(SRC:.c=.o) $(TOOLS_SO_LONG:.c=.o)
OBJ_DIR				= obj/

#===================HEADER====================

HEAD_DIR			= inc/
HEADER				= ft_printf.h get_next_line.h libft.h pipex.h so_long.h
H_PLACE				= $(addprefix inc/, $(HEADER))

#===================VAR_GBL===================

SRCS				= $(addprefix $(SRC_DIR), $(SRC)) $(addprefix $(SRC_DIR), $(TOOLS_DIR))
OBJS				= $(addprefix $(OBJ_DIR), $(OBJ))

#====================FLAG=====================

CFLAG				= -Wall -Wextra -Werror -g3
HEADERS				= -I$(HEAD_DIR) -I$(MLX_DIR)
CC					= cc $(CFLAG) $(HEADERS)
TO_OBJ				= -c

#====================COLOR=====================

#_________RESET_COLOR__________

D_COLOR 			= \033[0m

#__________TEXT_STYLE__________

BOLD 				= \033[1m
#__________COLOR_TEXT__________

BLACK1				= \033[30m
RED1				= \033[31m
GREEN1				= \033[32m
YELLOW1				= \033[33m
BLUE1				= \033[34m
PINK1				= \033[35m
CYAN1				= \033[36m
GREY1				= \033[37m

#_______COLOR_BACKGROUND_______

BLACK2				= \033[40m
RED2				= \033[41m
GREEN2				= \033[42m
YELLOW2				= \033[43m
BLUE2				= \033[44m
PINK2				= \033[45m
CYAN2				= \033[46m
GREY2				= \033[47m

#====================RULES====================

all : $(NAME)

$(OBJS): $(SRCS) $(H_PLACE)
ifeq ($(MAKECMDGOALS), all)
	@echo "\n=================$(PINK1)ALL$(D_COLOR)================="
endif
ifeq ($(MAKECMDGOALS), $(NAME))
	@echo "\n===============$(PINK1)LIBFT.A$(D_COLOR)==============="
endif
ifeq ($(MAKECMDGOALS), )
	@echo "\n=================$(PINK1)\" \"$(D_COLOR)================="
endif
	@echo "|  =========$(YELLOW1)MLX$(D_COLOR)========             |"
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "|$(PINK1)Téléchargement de la mlx$(D_COLOR)     : $(TELECHARGEMENT)|"; \
		mkdir -p $(MLX_DIR); \
		curl -o $(INC)/minilibx-linux.tgz $(LINK_MLX) $(SILENCE); \
		tar -xzf $(INC)/minilibx-linux.tgz -C $(INC); \
		rm $(INC)/minilibx-linux.tgz; \
		echo "$(GREEN1)|Minilibx telechargé$(D_COLOR)          : $(DL_FINISH)|"; \
	fi
	@ make --no-print-directory -C $(MLX_DIR) all $(SILENCE)
	@echo "|./minilibx                   : $(GREEN1)$(SUCCESS)$(D_COLOR)  |"
	@echo "|  ========$(YELLOW1)LIBFT$(D_COLOR)========            |"
	@$(CC) $(TO_OBJ) $(SRCS)
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ) $(OBJ_DIR)
	@ar rcs $(NAME) $(OBJS) $(SILENCE)
	@ranlib $(NAME) $(SILENCE)
	@mkdir -p $(EXEC_DIR)
	@mv $(NAME) $(EXEC_DIR)
	@$(MAKE) check_norme
	@if [ -s norminette ]; then \
		echo "|                                   |"; \
		echo "|$(RED1)Erreur de norme !!$(D_COLOR)                 |"; \
		echo "|$(YELLOW1)Consultez les commandes            $(D_COLOR)|"; \
		echo "|$(YELLOW1)\"make norminette\" ou \"norminette\"  $(D_COLOR)|"; \
		echo "|$(YELLOW1)pour plus de details !$(D_COLOR)             |"; \
		echo "|                                   |"; \
		rm -rf $(EXEC_DIR); \
		exit 0; \
	else \
		echo "|$(NAME)                      : $(GREEN1)$(SUCCESS)$(D_COLOR)  |"; \
	fi
ifeq ($(MAKECMDGOALS), all)
	@echo "$(FIN)"
endif
ifeq ($(MAKECMDGOALS), $(NAME))
	@echo "$(FIN)"
endif
ifeq ($(MAKECMDGOALS), )
	@echo "$(FIN)"
endif
ifeq ($(MAKECMDGOALS), re)
	@echo "$(FIN)"
endif

	@if [ -s norminette ]; then \
		echo "\nnorminette des .c de $(NAME) : $(RED1)Erreur ‼️$(D_COLOR)"; \
		cat norminette; \
		rm -rf norminette; \
	fi

$(NAME) : $(OBJS)

clean :
ifeq ($(MAKECMDGOALS), clean)
	@echo "\n================$(PINK1)CLEAN$(D_COLOR)================"
endif
ifeq ($(MAKECMDGOALS), fclean)
	@echo "\n================$(PINK1)FCLEAN$(D_COLOR)==============="
endif
ifeq ($(MAKECMDGOALS), re)
	@echo "\n==================$(PINK1)RE$(D_COLOR)================="
endif
	@echo "|  =====$(CYAN1)OBJ_LIBFT$(D_COLOR)=====              |"
	@rm -rf $(OBJ_DIR) $(SILENCE)
	@echo "|Le dossier \"obj\"             : $(RED1)$(DELETED)$(D_COLOR)  |"
ifeq ($(MAKECMDGOALS), clean)
	@echo "$(FIN)"
endif

fclean : clean
	@if [ -d "$(MLX_DIR)" ]; then \
		echo "|  ========$(CYAN1)MLX$(D_COLOR)========              |"; \
		make --no-print-directory -C $(MLX_DIR) clean $(SILENCE); \
		rm -rf $(MLX_DIR); \
		echo "|Le dossier de la mlx         : $(RED1)$(DELETED)$(D_COLOR)  |"; \
	fi
	@echo "|  ======$(CYAN1)LIBFT.A$(D_COLOR)======              |"
	@rm -rf $(EXEC_DIR) $(SILENCE)
	@echo "|$(NAME)                      : $(RED1)$(DELETED)$(D_COLOR)  |"
	@if [ -f norminette ]; then \
		rm norminette; \
		echo "|trace norminette             : 💥  |"; \
	fi
ifeq ($(MAKECMDGOALS), fclean)
	@echo "$(FIN)"
endif

re : fclean all

.PHONY : all, clean, fclean, re, bonus

#_________OTHER_RULES___________

minilibx :
ifeq ($(MAKECMDGOALS),minilibx)
	@echo "===============$(GREEN1)MINILIBX$(D_COLOR)=============="
endif
	@echo "|  =========$(YELLOW1)MLX$(D_COLOR)========             |"
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "|$(PINK1)Téléchargement de la mlx$(D_COLOR)     : $(TELECHARGEMENT)|"; \
		mkdir -p $(MLX_DIR); \
		curl -o $(INC)/minilibx-linux.tgz $(LINK_MLX) $(SILENCE); \
		tar -xzf $(INC)/minilibx-linux.tgz -C $(INC); \
		rm $(INC)/minilibx-linux.tgz; \
		echo "|$(GREEN1)Minilibx telechargé$(D_COLOR)          : $(DL_FINISH)|"; \
	fi
	@if [ ! -f "$(MLX_A)" ]; then \
		make --no-print-directory -C $(MLX_DIR) all $(SILENCE); \
		echo "|./minilibx                   : $(GREEN1)$(SUCCESS)$(D_COLOR)  |"; \
	else \
		echo "|./$(MLX) : $(YELLOW1)$(PRESENT)$(D_COLOR)"; \
	fi
ifeq ($(MAKECMDGOALS), minilibx)
	@echo "$(FIN)"
endif

check_norme :
	-@norminette src/ > res_cmd || true
	-@grep 'Error' res_cmd > norminette || true
	-@norminette $(H_PLACE) > res_cmd || true
	-@grep "Error" res_cmd >> norminette || true
	@rm res_cmd
	@if [ ! -s norminette ]; then \
    	rm norminette; \
		echo "|norminette des .c de $(NAME) : $(GREEN1)$(SUCCESS)$(D_COLOR)  |"; \
	fi

norminette :
	@echo "\n================$(PINK1)NORME$(D_COLOR)================"
	-@norminette src/ > res_cmd || true
	-@grep 'Error' res_cmd > norminette || true
	-@norminette $(H_PLACE) > res_cmd || true
	-@grep "Error" res_cmd >> norminette || true
	@rm res_cmd
	@if [ ! -s norminette ]; then \
    	rm norminette; \
		echo "|norminette des .c de $(NAME) : $(GREEN1)$(SUCCESS)$(D_COLOR)  |"; \
	else \
		echo "\nnorminette des .c de $(NAME) : $(RED1)Erreur ‼️$(D_COLOR)"; \
		cat norminette; \
		echo; \
		rm norminette; \
	fi
	@echo "$(FIN)"