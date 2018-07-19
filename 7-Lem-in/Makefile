# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhuber <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 14:57:57 by dhuber            #+#    #+#              #
#                                                                              #
# **************************************************************************** #

CC = @clang

CFLAGS = -Werror -Wextra -Wall -Weverything -g $(INCLUDE)

SRC_NAME = main.c \
		print_list.c \
		print_info.c \
		ft_parse.c \
		ft_check_list.c \
		ft_check_pipes.c \
		ft_check_start_n_end.c \
		fill_info.c \
		ft_skip_hash.c \
		fill_link.c \
		delete_struct.c \
		my_function.c \
		ft_create_path.c \
		ft_print_sol.c

SRC = $(addprefix src/,$(SRC_NAME))

OBJ = $(SRC:.c=.o)

NAME = lem-in

LIB_PATH = ft_printf/

LIB = ft_printf/libftprintf.a

INCLUDE = -I ./includes


all : libftcomp $(OBJ) $(NAME)

$(NAME) : $(LIB) $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(LIB) $(OBJ)
	@echo "Compilation Lem-in!"
	@cat ant

$(OBJ) : includes/lem_in.h

libftcomp :
	@make -C $(LIB_PATH)

clean :
	@make clean -C $(LIB_PATH)
	@/bin/rm -f $(OBJ)

fclean : clean
	@make fclean -C $(LIB_PATH)
	@/bin/rm -f $(LIB)
	@echo "\033[1;32mSucced clean of libft.a\033[0m"
	@/bin/rm -f $(NAME)
	@echo "\033[1;32mSucced clean lem-in\033[0m"

re : fclean all

.PHONY: re all fclean clean
