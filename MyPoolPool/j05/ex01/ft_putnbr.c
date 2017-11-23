/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 22:17:03 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/12 15:38:14 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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
