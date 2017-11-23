# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkamel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:42:32 by mkamel            #+#    #+#              #
#    Updated: 2017/11/08 20:04:47 by mkamel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = ft_display_file
SRC = ft_display_file.c
SRC_O = ft_display_file.o

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) $(SRC_O) -o $(NAME)
	 
clean :
	/bin/rm -f $(SRC_O)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
