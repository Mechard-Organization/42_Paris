# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 14:03:29 by mechard           #+#    #+#              #
#    Updated: 2025/02/01 18:20:28 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#===================GLOBAL===================

#_____________MAIN_____________

NAME				= philo
UPPER_MAKECMDGOALS	= $(echo $(MAKECMDGOALS) | tr 'a-z' 'A-Z')

#_____________COMP_____________

CFLAGS				= -Wall -Wextra -Werror -g3
HEADER_FLAG			= -I
CC 					= cc $(CFLAGS)

#___________MESSAGE____________

SUCCESS				= ✅
DELETED				= 💥
COMPILATION			= 🔽🔁

SILENCE				= > /dev/null 2>&1
MAKE				= make --no-print-directory -C ./

#____________OTHER_____________

ARG3 				= $(word 2, $(MAKECMDGOALS))
COMPI				= all $(NAME)
SUPPR				= clean fclean re

SILENCE				= > /dev/null 2>&1
FIN					= =================$(GREEN1)END$(D_COLOR)=================\n

#===================SOURCES===================

#____________FILE_C____________

SRCS				= main.c ft_error.c ft_init.c ft_monitor.c ft_routine.c ft_thread.c ft_utils_i.c ft_utils_v.c

#____________FILE_H____________

HEADERS				= philo.h msg.h

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
	@$(MAKE) begin ARG3="$(MAKECMDGOALS)"
endif

	@$(CC) $(SRCS) -o $(NAME)
	@$(MAKE) check_norme
	@if [ -s norminette ]; then \
		echo "|$(RED1)Erreur de norme !!$(D_COLOR)                 |"; \
		echo "|$(YELLOW1)Consultez les commandes            $(D_COLOR)|"; \
		echo "|$(YELLOW1)\"make norme\" ou \"norminette\"       $(D_COLOR)|"; \
		echo "|$(YELLOW1)pour plus de details !$(D_COLOR)             |"; \
		rm -rf $(NAME); \
		exit 0; \
	else \
		echo "|$(NAME)                         : $(GREEN1)$(SUCCESS)$(D_COLOR) |"; \
	fi

ifeq ($(filter-out all $(NAME) re, $(MAKECMDGOALS)), )
	@$(MAKE) end
endif

clean :
ifneq ($(filter-out $(COMPI),$(MAKECMDGOALS)),)
	@$(MAKE) begin ARG3="$(MAKECMDGOALS)"
endif

	@if [ -s norminette ]; then \
		rm norminette; \
	fi

ifeq ($(MAKECMDGOALS), clean)
	@$(MAKE) end
endif

fclean : clean
	@if [ -f $(NAME) ]; then \
		rm -rf $(NAME); \
		echo "|$(NAME)                         : $(RED1)$(DELETED)$(D_COLOR) |";\
	fi

ifeq ($(MAKECMDGOALS), fclean)
	@$(MAKE) end
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
	-@norminette $(SRCS) > res_cmd || true
	-@norminette $(HEADERS) >> res_cmd || true
	-@grep "Error" res_cmd > norminette || true
	@rm res_cmd
	@if [ ! -s norminette ]; then \
    	rm norminette; \
		echo "|norminette des .c de $(NAME)    : $(GREEN1)$(SUCCESS)$(D_COLOR) |"; \
	fi

norme :
	@$(MAKE) begin ARG3="$(MAKECMDGOALS)"
	@if [ -s ./norminette ]; then \
		cat norminette; \
		echo -n; \
	fi
	@echo "|                                   |"
	@echo "$(FIN)"