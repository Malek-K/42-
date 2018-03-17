 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alima <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 11:45:06 by alima             #+#    #+#              #
#    Updated: 2017/11/27 13:39:34 by alima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Makefile de la LIBFT

NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_free_tab.c ft_is_lower.c ft_is_upper.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_print_words_tables.c ft_print_int_tables.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_strsplit.c ft_strrchr.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

.PHONY: clean, fclean, re

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@echo "Librairie creer"

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
