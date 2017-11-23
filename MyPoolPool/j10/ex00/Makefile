# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkamel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 22:43:23 by mkamel            #+#    #+#              #
#    Updated: 2017/09/19 16:38:29 by mkamel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
HEADDIR = ./includes/

NAME = libft.a
SRC = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c \
./srcs/ft_strlen.c ./srcs/ft_swap.c 
FLAGS = -Wall -Wextra -Werror -c


all : $(NAME)

$(NAME) :
	$(CC) -I $(HEADDIR) $(FLAGS) $(SRC)
	ar -rc $(NAME) ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
	
clean :
	/bin/rm -f ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
