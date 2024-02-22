# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mechard <mechard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 20:03:06 by abutet            #+#    #+#              #
#    Updated: 2024/02/19 11:59:11 by mechard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c\
			ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
			ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c\
			ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c\
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
			ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_strcpy.c \
			ft_strtrim.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c	

OBJS	= $(SRCS:.c=.o)

HEADERS	= libft.h/

NAME	= libft.a

#reset_color#

D_COLOR = \033[0m

#color_text#

BLACK1	= \033[30m
RED1	= \033[31m
GREEN1	= \033[32m
YELLOW1	= \033[33m
BLUE1	= \033[34m
PINK1	= \033[35m
CYAN1	= \033[36m
GREY1	= \033[37m

#color_background#

BLACK2	= \033[40m
RED2	= \033[41m
GREEN2	= \033[42m
YELLOW2	= \033[43m
BLUE2	= \033[44m
PINK2	= \033[45m
CYAN2	= \033[46m
GREY2	= \033[47m

%.o: %.c
	@cc -Wall -Wextra -Werror -I $(HEADERS) -c $< -o $@

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS) > /dev/null 2>&1
	@ranlib $(NAME) > /dev/null 2>&1

all : $(NAME)

clean :
	@rm -f $(OBJS) > /dev/null 2>&1

fclean : clean
	@rm -f $(NAME)  > /dev/null 2>&1

re : fclean all

.PHONY : all, clean, fclean, re, bonus
