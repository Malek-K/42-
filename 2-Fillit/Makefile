# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alima <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 15:40:13 by alima             #+#    #+#              #
#    Updated: 2017/12/07 14:30:04 by alima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Makefile de FILLIT

LIB = libft/libft.a
LIBPATH = libft/
NAME = fillit
SRC = ft_read.c ft_check.c main.c ft_range.c ft_upnleft.c ft_thegrid.c \
	  ft_backtracking.c ft_check_nb_tetri.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIBPATH) 
	@gcc $(FLAGS) -c $(SRC)
	@gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo "Creation de l'executable."

clean:
	@$(MAKE) clean -C $(LIBPATH) 
	@/bin/rm -f $(OBJ)
	@echo "Suppression des fichiers objet."

fclean: clean
	@$(MAKE) fclean -C $(LIBPATH) 
	@/bin/rm -f $(NAME)
	@echo "Suppression de l'executable."

re: fclean all

.PHONY: clean, all, fclean
