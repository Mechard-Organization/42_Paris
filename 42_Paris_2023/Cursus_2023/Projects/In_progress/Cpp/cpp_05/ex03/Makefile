# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 13:47:46 by mechard           #+#    #+#              #
#    Updated: 2025/03/22 15:54:31 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#======================================================
#                   VARIABLES
#======================================================

#------------------------------------------------------
# Variables globales
#------------------------------------------------------

PROJECT         = cpp05
NAME            = ex03
LANG			= c++

#------------------------------------------------------
# Flags de compilation et compilateur
#------------------------------------------------------

# Compilation pour le c++

CXXFLAGS        = -Wall -Wextra -Werror -std=c++98 -g3
CXX             = c++ $(CXXFLAGS) $(CXXHDRFLAG)
CXXHDRFLAG		= -I$(CXXHDR_LOCATION)
CXXCOMPI		= $(CXX) $(CXXSRCS) -o $(NAME)

# Compilation pour le c

CFLAGS			= -Wall -Wextra -Werror -g3
C				= cc $(CFLAGS) $(CHDRFLAG)
CHDRFLAG		= -I$(CHDR_LOCATION)
CCOMPI			= $(C) $(CSRCS) -o $(NAME)

# Compilateur

ifeq ($(LANG), c++)
	COMPILATION	= $(CXXCOMPI)
else ifeq ($(LANG), c)
	COMPILATION	= $(CCOMPI)
endif

#------------------------------------------------------
# Fichiers sources et headers
#------------------------------------------------------

# Fichiers sources pour le c++

CXXSRCS				= $(shell find . -type f | awk 'length($$0) >= 4 && substr($$0, length($$0)-3, 4) == ".cpp" { print }')
CXXHDRS				= $(shell find . -type f | awk 'length($$0) >= 4 && substr($$0, length($$0)-3, 4) == ".hpp" { print }')
CXXHDR_LOCATION		= $(shell find . -type f | awk 'length($$0) >= 4 && substr($$0, length($$0)-3, 4) == ".hpp" { cmd="dirname "$$0; cmd | getline d; close(cmd); print d }' | sort -u)
CXXSRC_LOCATION		= $(CXXSRCS) $(CXXHDRS)

# Fichiers sources pour le c

CSRCS				= $(shell find . -type f | awk 'length($$0) >= 2 && substr($$0, length($$0)-1, 2) == ".c" { print }')
COBJS				= $(shell find . -type f | awk 'length($$0) >= 2 && substr($$0, length($$0)-1, 2) == ".o" { print }')
CHDRS				= $(shell find . -type f | awk 'length($$0) >= 2 && substr($$0, length($$0)-1, 2) == ".h" { print }')
CHDR_LOCATION		= $(shell find . -type f | awk 'length($$0) >= 2 && substr($$0, length($$0)-1, 2) == ".h" { cmd="dirname "$$0; cmd | getline d; close(cmd); print d }' | sort -u)
CSRC_LOCATION		= $(CSRCS) $(CHDRS) $(COBJS)

# Tout les fichiers sources en une seule variables

ALL					= $(CSRC_LOCATION) $(CXXSRC_LOCATION)

ifeq ($(LANG), c++)
	FILES			= $(CXXSRC_LOCATION)
else ifeq ($(LANG), c)
	FILES			= $(CSRC_LOCATION)
endif

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

LIB				= libft.a
LIB_DIR			= $(addprefix $(INC), libft/)
LIB_OBJ			= $(addprefix $(LIB_DIR), obj/)
LIB_INC			= $(addprefix $(LIB_DIR), inc/)
LIB_EXEC		= $(addprefix $(LIB_DIR), exec/)
LIB_A			= $(addprefix $(LIB_EXEC), $(LIB))
LIBRARY			= -lreadline -lncurses

#======================================================
#                   RÈGLES PRINCIPALES
#======================================================

all: $(NAME)

#------------------------------------------------------
# Compilation de l'exécutable
#------------------------------------------------------

$(NAME): $(FILES)
ifeq ($(filter-out all $(NAME), $(MAKECMDGOALS)), )
	@$(MAKE) begin ARG3="$(MAKECMDGOALS)"
endif
	@-$(MAKE) under_begin ARG3="$(NAME)"
ifeq ($(LANG), c++)
	@-$(MAKE) c++
else ifeq ($(LANG), c)
	FILES			= $(CSRC_LOCATION)
endif
	@$(MAKE) end

#------------------------------------------------------
# Nettoyage (fichiers temporaires)
#------------------------------------------------------

clean:
ifneq ($(filter-out $(COMPI),$(MAKECMDGOALS)),)
	@$(MAKE) begin ARG3="$(MAKECMDGOALS)"
endif
	@allowed="$(FILES) $(OBJS) $(NAME) Makefile"; \
	deleted=0; \
	for file in $$(find . -type f); do \
		keep=no; \
		for a in $$allowed; do \
			if [ "$$file" = "$$a" ] || [ "$$file" = "./$$a" ]; then \
				keep=yes; \
			fi; \
		done; \
		if [ "$$keep" = "no" ]; then \
			if [ $$deleted -eq 0 ]; then \
				$(MAKE) under_begin ARG3="CLEAN"; \
				deleted=1; \
			fi; \
			rm -f $$file; \
			$(MAKE) suppr_line ARG3=$$file; \
		fi; \
	done; \
	for dir in $$(find . -type f -name "*.o" -exec dirname {} \; | sort -u); do \
	    if [ "$$dir" != "." ]; then \
		    rm -rf $$dir; \
		    $(MAKE) suppr_line ARG3="Directory $$dir"; \
	    fi; \
	done; \
	if [ "$(MAKECMDGOALS)" != "clean" ] && [ $$deleted -eq 1 ]; then \
		printf "|                                   |\n"; \
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
# Compilation de la librairie statique
#------------------------------------------------------

$(LIB_A):
	@$(MAKE) $(LIB) -C $(LIB_DIR)

#------------------------------------------------------
# Règle de compilation
#------------------------------------------------------

c :
	@-$(COMPILATION) > res_cmp
	@if [ ! -s res_cmp ]; then \
		rm -rf res_cmp; \
		if [ -s $(NAME) ]; then \
			echo "|$(NAME)                         : $(GREEN1)$(SUCCESS)$(D_COLOR)  |"; \
		fi; \
	elif [ -s res_cmp ]; then \
		$(MAKE) error_compi; \
	fi

c++ :
	@-$(COMPILATION) > res_cmp
	@if [ ! -s res_cmp ]; then \
		rm -rf res_cmp; \
		if [ -s $(NAME) ]; then \
			echo "|$(NAME)                         : $(GREEN1)$(SUCCESS)$(D_COLOR)  |"; \
		fi; \
	elif [ -s res_cmp ]; then \
		$(MAKE) error_compi; \
	fi

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
	@-$(MAKE) under_begin ARG3="$(LANG)"

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
	upper_lang=$$(echo "$(LANG)" | tr '[:lower:]' '[:upper:]'); \
	if [ "$$upper_arg3" = "$$upper_project" ] || [ "$$upper_arg3" = "$$upper_lang" ]; then \
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
	if [ "$$upper_arg3" != "$$upper_project" ]; then \
	    printf "|\n|                                   "; \
	fi; \
	printf "|\n";

#------------------------------------------------------
# Règle d'affichage "error_line"
# Affiche une ligne de 37 caractères contenant ARG3 ajusté
# sur 29 caractères (tronqué ou complété) suivi de " : 💥  "
# pour signaler la suppression d'un fichier.
#------------------------------------------------------

suppr_line:
	@{ \
		if [ -z "$(ARG3)" ]; then \
			display_arg3="\" \""; \
		else \
			display_arg3="$(ARG3)"; \
		fi; \
		arg_len=$$(echo -n "$$display_arg3" | wc -c); \
		if [ $$arg_len -gt 28 ]; then \
			truncated=$$(echo -n "$$display_arg3" | cut -c1-25); \
			field="$$truncated..."; \
		else \
			field="$$display_arg3"; \
			pad=$$((28 - arg_len)); \
			i=1; \
			while [ $$i -le $$pad ]; do \
				field="$$field "; \
				i=$$(( i + 1 )); \
			done; \
		fi; \
		printf "|$(RED2)%s$(D_COLOR) : 💥  |\n" "$$field"; \
	}

#------------------------------------------------------
# Règle d'affichage "end"
#------------------------------------------------------

end:
	@printf "|                                   |\n"
	@echo "$(FIN)"

#======================================================
#              RÈGLES PHONY (obligatoires)
#======================================================

.PHONY: all clean fclean re begin under_begin suppr_line end