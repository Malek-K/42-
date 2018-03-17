/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:54:03 by alima             #+#    #+#             */
/*   Updated: 2017/12/08 14:34:34 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_fillin(char **grid, t_lst *list, int *tab)
{
	grid[tab[0] + list->x[0]][tab[1] + list->y[0]] = list->letter;
	grid[tab[0] + list->x[1]][tab[1] + list->y[1]] = list->letter;
	grid[tab[0] + list->x[2]][tab[1] + list->y[2]] = list->letter;
	grid[tab[0] + list->x[3]][tab[1] + list->y[3]] = list->letter;
	return (grid);
}

static int		ft_try(char **grid, t_lst *list, int size, int *tab)
{
	if ((tab[0] + list->x[3]) >= size || (tab[1] + list->y[3]) >= size ||
		(tab[0] + list->x[2]) >= size || (tab[1] + list->y[2]) >= size ||
		(tab[0] + list->x[1]) >= size || (tab[1] + list->y[1]) >= size ||
		(tab[0] + list->x[0]) >= size || (tab[1] + list->y[0]) >= size ||
		(tab[1] + list->y[3]) < 0 || (tab[1] + list->y[2]) < 0 ||
		(tab[1] + list->y[1]) < 0 || (tab[1] + list->y[0]) < 0)
		return (0);
	if (grid[tab[0] + list->x[0]][tab[1] + list->y[0]] == '.')
	{
		if (grid[tab[0] + list->x[1]][tab[1] + list->y[1]] == '.')
		{
			if (grid[tab[0] + list->x[2]][tab[1] + list->y[2]] == '.')
			{
				if (grid[tab[0] + list->x[3]][tab[1] + list->y[3]] == '.')
				{
					return (1);
				}
			}
		}
	}
	return (0);
}

static char		**ft_solution(char **grid, t_lst *list, int size)
{
	char	**tmp;
	int		tab[2];

	if (!list->next)
		return (grid);
	tmp = NULL;
	tab[0] = 0;
	while (tab[0] < size)
	{
		tab[1] = 0;
		while (tab[1] < size)
		{
			while (grid[tab[0]][tab[1]] != '.' && tab[1] < size)
				tab[1]++;
			if (ft_try(grid, list, size, tab) && list->next)
				tmp = ft_solution(ft_fillin(grid, list, tab), list->next, size);
			if (tmp)
				return (tmp);
			grid = ft_retry(grid, list, size);
			tab[1]++;
		}
		tab[0]++;
	}
	return (0);
}

char			**ft_backtracking(t_lst *list, int size, char **grid)
{
	grid = ft_gridmaker(grid, size);
	if (!(ft_solution(grid, list, size)))
		grid = ft_backtracking(list, ++size, grid);
	return (grid);
}
