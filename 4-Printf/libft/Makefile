# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkamel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 15:59:31 by mkamel            #+#    #+#              #
#    Updated: 2018/02/21 14:00:59 by mkamel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
	  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
	  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
	  ft_memmove.c ft_memset.c ft_print_words_tables.c ft_putchar.c \
	  ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
	  ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c \
	  ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	  ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
	  ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
	  ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
	  ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	  ft_print_nb_tables.c ft_sort_int_tab.c ft_tab_mult.c ft_swap.c \
	  ft_strjoin_free.c ft_strdup_free.c ft_strchr_cpy.c ft_strchr_cpy_free.c \
	  ft_strsub_free.c ft_itoa_base.c ft_utoa_base.c ft_wstrlen.c \
	  ft_wchar_to_str.c ft_wstr_to_str.c ft_putwchar.c ft_putwstr.c \
	  ft_putnstr.c


OBJ = $(SRC:.c=.o)
HEAD = libft.h
NAME = libft.a

all : $(NAME)

$(NAME) :
	@echo "\033[31;1;2m  Compiling Libft\033[0m"
	@$(CC) -I $(HEAD) -c $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib libft.a
	@echo "\033[31;1;2m  Libft created !\033[0m"

test : all
	@$(CC) $(FLAGS) main.c -L. -lft
clean :
	@/bin/rm -f $(OBJ)
	@echo "\033[33m   cleaning libft done \033[0m"

fclean : clean
	@/bin/rm -f $(NAME)
	@echo "\033[33m   fcleaning libft done \033[0m"


re : fclean all

.PHONY : all clean fclean re test
