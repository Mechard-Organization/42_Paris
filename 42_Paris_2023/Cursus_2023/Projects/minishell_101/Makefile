# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 13:47:46 by mechard           #+#    #+#              #
#    Updated: 2025/01/26 13:59:32 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==================VAR_GBL==================

NAME			= minishell
INC				= inc/
LIBRARY			= -lreadline -lncurses

#===================FLAG====================

CFLAG				= -Wall -Wextra -Werror -g3 #-fsanitize=address -fsanitize=undefined
HEADERS				= -I$(HEAD_DIR) -I$(LIB_INC)
CC					= cc $(CFLAG) $(HEADERS)
TO_OBJ				= -c

#===================OTHERS==================

SUCCESS			= ✅
TELECHARGEMENT	= 🔽🔁
DL_FINISH		= 🔽✅
DELETED			= 💥
SILENCE			= > /dev/null 2>&1
MAKE			= make --no-print-directory -C ./
FIN				= =================$(GREEN1)END$(D_COLOR)=================\n

#==================SOURCES==================

#_________MAIN_FOLDER__________

MAIN_FILES		= main.c # print_debug.c
MAIN_LOCATION	= $(addprefix src/, $(MAIN_FILES))

#_________TOOL_FOLDER__________

TOOL_DIR		= tools/
TOOL_FILE		= ft_init.c ft_free.c ft_prompt.c ft_cleanup.c\
					 ft_signal.c utils.c ft_print_err.c utils_deux.c\
					 utils_trois.c main_tools.c
TOOL_LOCATION	= $(addprefix $(addprefix src/, $(TOOL_DIR)), $(TOOL_FILE))

#_________BUIN_FOLDER__________

BUIN_DIR		= builtins/
BUIN_FILE		= ft_builtins.c ft_cd.c ft_cd_tools.c ft_echo.c ft_env.c ft_exit.c ft_pwd.c \
					ft_unset.c ft_export.c ft_export_tools.c ft_export_tools_2.c ft_builtins_tools.c
BUIN_LOCATION	= $(addprefix $(addprefix src/, $(BUIN_DIR)), $(BUIN_FILE))

#_________EXEC_FOLDER__________

EXEC_DIR		= exec/
EXEC_FILE		= ft_exec.c ft_exec_tools.c ft_exec_redir.c ft_pipe.c ft_execute_command.c ft_fd_tools.c ft_fd_cleanup.c
EXEC_LOCATION	= $(addprefix $(addprefix src/, $(EXEC_DIR)), $(EXEC_FILE))

#_________PARS_FOLDER__________

PARS_DIR		= parser/
PARS_FILE		= ft_parser.c ft_parse_heredoc.c ft_parse_text.c ft_parse_text_tools.c ft_parse_redir.c \
					ft_parse_pipe.c ft_parse_heredoc_tools.c ft_check_cmd.c
PARS_LOCATION	= $(addprefix $(addprefix src/, $(PARS_DIR)), $(PARS_FILE))

#________TOKEN_FOLDER__________

TOKEN_DIR		= tokenizer/
TOKEN_FILE		= ft_tokenizer.c ft_token_tools.c ft_token_extract_tools.c ft_token_extract_tools_deux.c \
					ft_token_tools_deux.c ft_token_extract.c ft_token_error.c
TOKEN_LOCATION	= $(addprefix $(addprefix src/, $(addprefix $(PARS_DIR), $(TOKEN_DIR))), $(TOKEN_FILE))

#________HEADER_FOLDER_________

HEAD_DIR			= inc/minishell/
HEADER				= fdw.h minishell.h s_builtin.h s_cmd.h s_minishell.h typedef.h
H_PLACE				= $(addprefix $(HEAD_DIR), $(HEADER))


#________LIBFT_FOLDER__________

LIB				= libft.a
LIB_DIR			= $(addprefix $(INC), libft/)
LIB_OBJ			= $(addprefix $(LIB_DIR), obj/)
LIB_INC			= $(addprefix $(LIB_DIR), inc/)
LIB_EXEC		= $(addprefix $(LIB_DIR), exec/)
LIB_A			= $(addprefix $(LIB_EXEC), $(LIB))

#_________SRCS_FOLDER__________

SRCS_LOCATION	= $(MAIN_LOCATION) $(EXEC_LOCATION) $(TOOL_LOCATION) $(BUIN_LOCATION) $(PARS_LOCATION) $(TOKEN_LOCATION)
SRCS			= $(SRCS_LOCATION) $(LIB_A)

#====================COLOR====================

#_________RESET_COLOR__________

D_COLOR = \033[0m

#__________TEXT_STYLE__________

BOLD = \033[1m

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

$(NAME) : $(SRCS_LOCATION)
ifeq ($(filter-out all $(NAME), $(MAKECMDGOALS)), )
	@$(MAKE) begin ARG3="$(MAKECMDGOALS)"
endif
	@echo "|  =======$(YELLOW1)LIBFT$(D_COLOR)========             |"
	@make --no-print-directory -C $(LIB_DIR) all $(SILENCE)
	@echo "|                                   |"
	@echo "|./libft                        : $(GREEN1)$(SUCCESS)$(D_COLOR)|"
	@$(MAKE) check_norme
	@if [ -s norminette ]; then \
		echo "|                                   |"; \
		echo "|$(RED1)Erreur de norme !!$(D_COLOR)                 |"; \
		echo "|$(YELLOW1)Consultez les commandes            $(D_COLOR)|"; \
		echo "|$(YELLOW1)\"make norme\" ou \"norminette\"       $(D_COLOR)|"; \
		echo "|$(YELLOW1)pour plus de details !$(D_COLOR)             |"; \
		echo "|                                   |"; \
		rm -rf $(EXEC_DIR); \
		exit 0; \
	fi
	@-$(CC) $(CFLAGS) $(SRCS) $(LIBRARY) -o $(NAME)
	@if [ ! -s res_cmp ]; then \
		rm -rf res_cmp; \
	fi
	@if [ ! -s res_cmp ]; then \
		echo "|                                   |"; \
		echo "|  =====$(YELLOW1)MINISHELL$(D_COLOR)======             |"; \
		echo "|                                   |"; \
		echo "|$(NAME)                      : $(GREEN1)$(SUCCESS)$(D_COLOR)|"; \
	elif [ -s res_cmp ]; then \
		echo "|                                   |"; \
		echo "|$(RED1)Erreur de compilation !!$(D_COLOR)           |"; \
		echo "|$(YELLOW1)Consultez les commandes \"make cmp\" $(D_COLOR)|"; \
		echo "|$(YELLOW1)ou le fichier \"cmp_res\"            $(D_COLOR)|"; \
		echo "|$(YELLOW1)pour plus de details !$(D_COLOR)             |"; \
		echo "|                                   |"; \
	fi

ifeq ($(filter-out all $(NAME) re, $(MAKECMDGOALS)), )
	@$(MAKE) end
endif

$(LIB_A) :
	@make --no-print-directory -C $(LIB_DIR) $(LIB) 

clean :
ifneq ($(filter-out $(COMPI),$(MAKECMDGOALS)),)
	@$(MAKE) begin ARG3="$(MAKECMDGOALS)"
endif
	
	@if [ -d "$(LIB_OBJ)" ]; then \
		make --no-print-directory -C $(LIB_DIR) clean $(SILENCE); \
		echo "|Le dossier \"obj\" de la libft : $(RED1)$(DELETED)$(D_COLOR)  |"; \
	fi

ifeq ($(MAKECMDGOALS), clean)
	@$(MAKE) end
endif

fclean : clean
	@if [ -f "$(LIB_A)" ]; then \
		$(MAKE)$(LIB_DIR) fclean $(SILENCE); \
		echo "|$(LIB)                      : $(RED1)$(DELETED)$(D_COLOR)  |"; \
	fi
	@if [ -f "$(NAME)" ]; then \
		rm -rf $(NAME) $(SILENCE); \
		echo "|$(NAME)                    : $(RED1)$(DELETED)$(D_COLOR)  |"; \
	fi

ifeq ($(MAKECMDGOALS), fclean)
	@$(MAKE) end
else
	@echo "|                                   |"	
endif

re : fclean all

.PHONY : all, clean, fclean, re

#________OTHER_RULES___________

begin :
	@if [ -z "$(ARG3)" ]; then upper_makecmd="\" \""; else upper_makecmd=$$(echo $(ARG3) | tr 'a-z' 'A-Z'); fi; \
	len=$$(echo -n "$$upper_makecmd" | wc -c); \
	eq_len=$$(( (37 - len) / 2 )); \
	left_len=$$(( eq_len )); \
	right_len=$$(( 37 - len - left_len )); \
	printf "\n"; \
	for _ in $$(seq 1 $$left_len); do printf "="; done; \
	printf "$(PINK1)$$upper_makecmd$(D_COLOR)"; \
	for _ in $$(seq 1 $$right_len); do printf "="; done; \
	printf "\n"; \
	printf "|                                   |\n"

end :
	@printf "|                                   |\n"
	@echo "$(FIN)"

check_norme :
	-@norminette $(SRCS_LOCATION) > res_cmd || true
	-@grep 'Error' res_cmd > norminette || true
	-@norminette $(H_PLACE) > res_cmd || true
	-@grep "Error" res_cmd >> norminette || true
	@rm res_cmd
	@if [ ! -s norminette ]; then \
    	rm norminette; \
		echo "|norminette des .c de $(NAME) : $(GREEN1)$(SUCCESS)$(D_COLOR)|"; \
	fi

norme :
	@$(MAKE) begin ARG3="$(MAKECMDGOALS)"
	@if [ -s ./norminette ]; then \
		norminette; \
		echo -n; \
	fi
	
	@echo "|                                   |"
	@echo "$(FIN)"