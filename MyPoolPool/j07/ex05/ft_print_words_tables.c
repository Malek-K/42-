/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:23:33 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/17 18:45:56 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		a;

	a = 0;
	while (str[a])
		ft_putchar(str[a++]);
}

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
