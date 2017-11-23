/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:43:21 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/18 21:26:44 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		nb = 47483648;
		ft_putchar('-');
		ft_putchar('2');
		ft_putchar('1');
		ft_putnbr(nb / 10);
	}
	else if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
		ft_putnbr(nb / 10);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + 48);
}

void	ft_show_tab(struct s_stock_par *par)
{
	char	**arr;

	while (par->str)
	{
		ft_putstr(par->str);
		ft_putchar('\n');
		ft_putnbr(par->size_param);
		ft_putchar('\n');
		arr = par->tab;
		while (*arr)
		{
			ft_putstr(*arr);
			ft_putchar('\n');
			arr++;
		}
		par++;
	}
}
