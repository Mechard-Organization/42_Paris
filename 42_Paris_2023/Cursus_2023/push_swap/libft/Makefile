# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 20:03:06 by abutet            #+#    #+#              #
#    Updated: 2024/01/19 16:56:45 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c\
			ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
			ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c\
			ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c\
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
			ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_strcpy.c \
			ft_strtrim.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c ft_nbrlen.c ft_strcmp.c ft_strcat.c
SRCS	= $(addprefix ./src/, $(SRC))

OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix ./obj/, $(OBJ))

CFLAGS = -Wall -Wextra -Werror
CC 		= cc $(CFLAGS)

HEADERS	=  -I ./inc/libft.h

#--------------COLOR--------------#

##RESET##

D_COLOR = \033[0m

##TEXT##

BLACK1	= \033[30m
RED1	= \033[31m
GREEN1	= \033[32m
YELLOW1	= \033[33m
BLUE1	= \033[34m
PINK1	= \033[35m
CYAN1	= \033[36m
GREY1	= \033[37m

##BACKGROUND##

BLACK2	= \033[40m
RED2	= \033[41m
GREEN2	= \033[42m
YELLOW2	= \033[43m
BLUE2	= \033[44m
PINK2	= \033[45m
CYAN2	= \033[46m
GREY2	= \033[47m

#---------------------------------#

./obj/%.o: ./src/%.c
	@$(CC) $(HEADERS) -c $< -o $@

$(NAME) : obj $(OBJS)
	@echo "             compilation des .c en .o $(GREEN1)OK$(D_COLOR)"
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "              compilation de libft.a $(GREEN1)OK$(D_COLOR)"

obj:
	@mkdir -p obj

all : $(NAME)

clean :
	@rm -rf ./obj
	@echo "              Fichiers objets $(RED1)SUPPRIME$(D_COLOR)"

fclean : clean
	@rm -f $(NAME)
	@echo "                  $(NAME) $(RED1)SUPPRIME$(D_COLOR)"

re : fclean all

.PHONY : all, clean, fclean, re, bonus