# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 13:47:46 by mechard           #+#    #+#              #
#    Updated: 2025/03/20 17:39:49 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#======================================================
#                   VARIABLES
#======================================================

#------------------------------------------------------
# Variables globales
#------------------------------------------------------

PROJECT         = cpp05
NAME            = ex01

#------------------------------------------------------
# Flags de compilation et compilateur
#------------------------------------------------------

CXXFLAGS        = -Wall -Wextra -Werror -std=c++98 -g3
CXX             = c++ $(CXXFLAGS)

#------------------------------------------------------
# Fichiers sources et headers
#------------------------------------------------------

SRC				= main.cpp Bureaucrat.cpp Form.cpp
SRCS            = $(addprefix ./, $(SRC))
HDR             = Bureaucrat.hpp Form.hpp
HDRS            = $(addprefix ./, $(HDR))
SRCS_LOCATION   = $(SRCS) $(HDRS)

#------------------------------------------------------
# Couleurs, symboles et autres variables d'affichage
#------------------------------------------------------

# Reset & style
D_COLOR         = \033[0m
BOLD            = \033[1m

# Couleurs texte
BLACK1          = \033[30m
RED1            = \033[31m
GREEN1          = \033[32m
YELLOW1         = \033[33m
BLUE1           = \033[34m
PINK1           = \033[35m
CYAN1           = \033[36m
GREY1           = \033[37m

# Couleurs de fond
BLACK2          = \033[40m
RED2            = \033[41m
GREEN2          = \033[42m
YELLOW2         = \033[43m
BLUE2           = \033[44m
PINK2           = \033[45m
CYAN2           = \033[46m
GREY2           = \033[47m

# Symboles
SUCCESS         = ✅
TELECHARGEMENT  = 🔽🔁
DL_FINISH       = 🔽✅
DELETED         = 💥

# Autres variables
SILENCE         = > /dev/null 2>&1
MAKE            = make --no-print-directory -C ./
FIN             = =================$(GREEN1)END$(D_COLOR)=================\n

#------------------------------------------------------
# Variables d'affichage (pour les règles begin et under_begin)
#------------------------------------------------------

LINE_WIDTH      = 37
BLOCK_SIZE      = 21
END_SPACES      = 12

#------------------------------------------------------
# (Optionnel) Variables pour la librairie
#------------------------------------------------------

LIB_A           =
LIB_DIR         =
LIB             =

#======================================================
#                   RÈGLES PRINCIPALES
#======================================================

all: $(NAME)

#------------------------------------------------------
# Compilation de l'exécutable
#------------------------------------------------------

$(NAME): $(SRCS_LOCATION)
ifeq ($(filter-out all $(NAME), $(MAKECMDGOALS)), )
	@$(MAKE) begin ARG3="$(MAKECMDGOALS)"
endif
	@-$(MAKE) under_begin ARG3="$(NAME)"
	@-$(CXX) $(HDRS) $(SRCS) -o $(NAME) > res_cmp
	@if [ ! -s res_cmp ]; then \
		rm -rf res_cmp; \
		echo "|$(NAME)                         : $(GREEN1)$(SUCCESS)$(D_COLOR)  |"; \
	elif [ -s res_cmp ]; then \
		echo "|                                   |"; \
		echo "|$(RED1)Erreur de compilation !!$(D_COLOR)           |"; \
		echo "|$(YELLOW1)Consultez les commandes \"make cmp\" $(D_COLOR)|"; \
		echo "|$(YELLOW1)ou le fichier \"cmp_res\"            $(D_COLOR)|"; \
		echo "|$(YELLOW1)pour plus de details !$(D_COLOR)             |"; \
	fi
	@$(MAKE) end

#------------------------------------------------------
# Nettoyage (fichiers temporaires)
#------------------------------------------------------

clean:
ifneq ($(filter-out $(COMPI),$(MAKECMDGOALS)),)
	@$(MAKE) begin ARG3="$(MAKECMDGOALS)"
endif
	@if [ -s Home_shrubbery ]; then \
		$(MAKE) under_begin ARG3="CLEAN"; \
		rm Home_shrubbery; \
		echo "|Home_shrubbery               : $(RED1)$(DELETED)$(D_COLOR)  |"; \
		if [ "$(MAKECMDGOALS)" != "clean" ]; then \
			echo "|                                   |"; \
		fi; \
	fi
ifeq ($(MAKECMDGOALS), clean)
	@$(MAKE) end
endif

#------------------------------------------------------
# Nettoyage complet (exécutable, etc.)
#------------------------------------------------------

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		$(MAKE) under_begin ARG3="FCLEAN"; \
		rm -rf $(NAME) $(SILENCE); \
		echo "|$(NAME)                         : $(RED1)$(DELETED)$(D_COLOR)  |"; \
		if [ "$(MAKECMDGOALS)" != "fclean" ]; then \
			echo "|                                   |"; \
		fi; \
	fi
ifeq ($(MAKECMDGOALS), fclean)
	@$(MAKE) end
endif

#------------------------------------------------------
# Recompilation totale
#------------------------------------------------------

re: fclean all

#======================================================
#                 AUTRES RÈGLES
#======================================================

#------------------------------------------------------
# Compilation de la librairie statique (exemple)
#------------------------------------------------------

$(LIB_A):
	@$(MAKE) $(LIB) -C $(LIB_DIR)

#------------------------------------------------------
# Règle d'affichage "begin"
# Affiche 37 caractères : "=" + bloc central (35) + "="
# Tronque ARG3 (34 + ".") si > 35, " " => "\" \"", 
# puis on centre
#------------------------------------------------------

begin:
	@if [ -z "$(ARG3)" ]; then \
		upper_arg3="\" \""; \
	elif [ "$(ARG3)" = " " ]; then \
		upper_arg3="\" \""; \
	else \
		upper_arg3=$$(echo "$(ARG3)" | tr '[:lower:]' '[:upper:]'); \
	fi; \
	arg_len=$$(echo -n "$$upper_arg3" | wc -c); \
	if [ $$arg_len -gt 35 ]; then \
		truncated_arg3=$$(echo -n "$$upper_arg3" | cut -c1-34).; \
		printf "\n="; \
		printf "$(PINK1)$$truncated_arg3$(D_COLOR)"; \
		printf "=\n|                                   |\n"; \
	else \
		leftover=$$(( 35 - arg_len )); \
		left_equals=$$(( leftover / 2 )); \
		right_equals=$$(( leftover - left_equals )); \
		printf "\n="; \
		for _ in $$(seq 1 $$left_equals); do printf "="; done; \
		printf "$(PINK1)$$upper_arg3$(D_COLOR)"; \
		for _ in $$(seq 1 $$right_equals); do printf "="; done; \
		printf "=\n|                                   |\n"; \
	fi
	@-$(MAKE) under_begin ARG3="$(PROJECT)"

#------------------------------------------------------
# Règle d'affichage "under_begin"
# Affiche une ligne de 37 caractères :
# |  + bloc central de 21 caractères + 12 espaces + |
# Bloc central : si ARG3 > 19 caractères, on tronque à 18 caractères et on ajoute un point.
# Sinon, on centre ARG3 en entourant de '=' pour atteindre 21 caractères.
#------------------------------------------------------

under_begin:
	@if [ -z "$(ARG3)" ]; then \
		upper_arg3=" "; \
	else \
		upper_arg3=$$(echo "$(ARG3)" | tr '[:lower:]' '[:upper:]'); \
	fi; \
	upper_project=$$(echo "$(PROJECT)" | tr '[:lower:]' '[:upper:]'); \
	if [ "$$upper_arg3" = "$$upper_project" ]; then \
	    block_size=31; \
	    spaces_after=2; \
		color=$(BLUE1); \
	else \
	    block_size=21; \
	    spaces_after=12; \
		color=$(YELLOW1); \
	fi; \
	arg_len=$$(echo -n "$$upper_arg3" | wc -c); \
	printf "|  "; \
	threshold=$$(( block_size - 2 )); \
	if [ $$arg_len -gt $$threshold ]; then \
	    truncated_arg3=$$(echo -n "$$upper_arg3" | cut -c1-$$(( block_size - 3 ))).; \
	    printf "=%s=" "\\$$color$$truncated_arg3$(D_COLOR)"; \
	else \
	    leftover=$$(( block_size - arg_len )); \
	    left_equals=$$(( leftover / 2 )); \
	    right_equals=$$(( leftover - left_equals )); \
	    for _ in $$(seq 1 $$left_equals); do printf "="; done; \
	    printf "\\$$color$$upper_arg3$(D_COLOR)"; \
	    for _ in $$(seq 1 $$right_equals); do printf "="; done; \
	fi; \
	for _ in $$(seq 1 $$spaces_after); do printf " "; done; \
	printf "|\n|                                   |\n";

#------------------------------------------------------
# Règle d'affichage "end"
#------------------------------------------------------

end:
	@printf "|                                   |\n"
	@echo "$(FIN)"

#======================================================
#              RÈGLES PHONY (obligatoires)
#======================================================

.PHONY: all clean fclean re $(NAME) $(LIB_A) begin under_begin end
