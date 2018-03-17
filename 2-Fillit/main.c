/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:09:44 by alima             #+#    #+#             */
/*   Updated: 2017/12/07 18:06:17 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	buf[BUF_SIZE + 1];
	char	**grid;
	t_lst	*lst;

	grid = NULL;
	if (ac != 2)
	{
		ft_putstr("usage: fillit [files_path]\n");
		return (1);
	}
	if ((ft_check(ft_read(av[1], buf))) != 0 || ft_check_nb_tetri(buf) > 26 ||
			(buf[0] == '\0'))
	{
		ft_putstr("error\n");
		return (1);
	}
	lst = ft_range(buf);
	grid = ft_backtracking(lst, ft_gridsize(lst), grid);
	ft_print_words_tables(grid);
	return (0);
}
