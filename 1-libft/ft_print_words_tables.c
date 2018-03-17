/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:59:25 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/22 18:59:29 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_words_tables(char **tab)
{
	int		x;
	int		y;

	x = 0;
	while (tab[x] != 0)
	{
		y = 0;
		while (tab[x][y] != '\0')
		{
			ft_putchar(tab[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}
