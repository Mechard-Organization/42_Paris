# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 14:03:29 by mechard           #+#    #+#              #
#    Updated: 2024/07/17 15:18:16 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===================GLOBAL===================

#_____________MAIN_____________

NAME				= philo
UPPER_MAKECMDGOALS	= $(echo $(MAKECMDGOALS) | tr 'a-z' 'A-Z')

#_____________COMP_____________

CFLAGS				= -Wall -Wextra -Werror 
HEADER_FLAG			= -I
CC 					= cc $(CFLAGS)

#___________MESSAGE____________

SUCCESS				= ✅
DELETED				= 💥

#____________OTHER_____________

COMPI				= all $(NAME)
SUPPR				= clean fclean re

SILENCE				= > /dev/null 2>&1
FIN					= =================$(GREEN1)END$(D_COLOR)=================\n

#===================SOURCES===================

#____________FILE_C____________

SRCS				= main.c tools_philo.c

#____________FILE_H____________

HEADERS				= philo.h

#____________FILE_O____________

OBJ_DIR				= obj

#====================COLOR====================

#_________RESET_COLOR__________

D_COLOR 			= \033[0m

#__________TEXT_STYLE__________

BOLD				= \033[1m

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

#__________MAIN_RULES__________

all : $(NAME)

$(NAME) : $(SRCS) $(HEADERS)
ifeq ($(filter-out all $(NAME), $(MAKECMDGOALS)), )
	@if [ -z "$(MAKECMDGOALS)" ]; then upper_makecmd="\" \""; else upper_makecmd=$$(echo $(MAKECMDGOALS) | tr 'a-z' 'A-Z'); fi; \
	len=$$(echo -n "$$upper_makecmd" | wc -c); \
	eq_len=$$(( (37 - len) / 2 )); \
	left_len=$$(( eq_len )); \
	right_len=$$(( 37 - len - left_len )); \
	printf "\n"; \
	for _ in $$(seq 1 $$left_len); do printf "="; done; \
	printf "$(PINK1)$$upper_makecmd$(D_COLOR)"; \
	for _ in $$(seq 1 $$right_len); do printf "="; done; \
	printf "\n"
endif

	@$(CC) $(SRCS) -o $(NAME)
	@$(MAKE) check_norme $(SILENCE)
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
		echo "|$(NAME)                        : $(GREEN1)$(SUCCESS)$(D_COLOR)  |"; \
	fi

ifeq ($(filter-out all $(NAME) re, $(MAKECMDGOALS)), )
	@echo "$(FIN)"
endif

clean :
ifneq ($(filter-out $(COMPI),$(MAKECMDGOALS)),)
	@if [ -z "$(MAKECMDGOALS)" ]; then upper_makecmd="\" \""; else upper_makecmd=$$(echo $(MAKECMDGOALS) | tr 'a-z' 'A-Z'); fi; \
	len=$$(echo -n "$$upper_makecmd" | wc -c); \
	eq_len=$$(( (37 - len) / 2 )); \
	left_len=$$(( eq_len )); \
	right_len=$$(( 37 - len - left_len )); \
	printf "\n"; \
	for _ in $$(seq 1 $$left_len); do printf "="; done; \
	printf "$(PINK1)$$upper_makecmd$(D_COLOR)"; \
	for _ in $$(seq 1 $$right_len); do printf "="; done; \
	printf "\n"
endif

ifeq ($(MAKECMDGOALS), clean)
	@echo "$(FIN)"
endif

fclean : clean
	@rm -rf $(NAME)
	@echo "|$(NAME)                        : $(RED1)$(DELETED)$(D_COLOR)  |"
ifeq ($(MAKECMDGOALS), fclean)
	@echo "$(FIN)"
endif

re : fclean all

.PHONY : all, clean, fclean, re

#________OTHER_RULES___________

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