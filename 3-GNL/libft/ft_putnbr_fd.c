/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:17:06 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/17 17:24:31 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	{
		if (n == -2147483648)
		{
			n = 47483648;
			ft_putchar_fd('-', fd);
			ft_putchar_fd('2', fd);
			ft_putchar_fd('1', fd);
			ft_putnbr_fd(n / 10, fd);
		}
		else if (n < 0)
		{
			n = n * -1;
			ft_putchar_fd('-', fd);
			if (n >= 10)
				ft_putnbr_fd(n / 10, fd);
		}
		else if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd(n % 10 + 48, fd);
	}
}
