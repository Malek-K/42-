/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thegrid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:55:59 by alima             #+#    #+#             */
/*   Updated: 2017/12/11 18:10:52 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**ft_retry(char **grid, t_lst *list, int size)
{
	int	x;
	int	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (grid[x][y] == list->letter)
				grid[x][y] = '.';
			y++;
		}
		x++;
	}
	return (grid);
}

int				ft_gridsize(t_lst *list)
{
	int		i;
	int		max;

	i = 0;
	max = 2;
	while (list->next)
	{
		i++;
		list = list->next;
	}
	while (max * max < i * 4)
		max++;
	return (max);
}

static char		**ft_gridfiller(char **grid, int size)
{
	int i;
	int j;

	i = 0;
	if (!(grid[i] = (char *)malloc(sizeof(char) * (size))))
		return (NULL);
	while (i < size)
	{
		grid[i] = ft_strnew(size);
		j = 0;
		while (j < size)
			grid[i][j++] = '.';
		i++;
	}
	grid[i] = 0;
	return (grid);
}

char			**ft_gridmaker(char **grid, int size)
{
	free(grid);
	grid = (char **)malloc(sizeof(char *) * size);
	if (!grid)
		return (NULL);
	grid[size] = 0;
	grid = ft_gridfiller(grid, size);
	return (grid);
}
