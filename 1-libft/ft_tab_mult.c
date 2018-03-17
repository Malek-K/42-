/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:20:09 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/22 19:13:45 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_tab_mult(char *nbr)
{
	int	nb;
	int	calc;
	int	compteur;

	nb = 0;
	calc = 0;
	compteur = 1;
	nb = ft_atoi(nbr);
	while (compteur <= 9)
	{
		ft_putnbr(compteur);
		ft_putstr(" x ");
		ft_putstr(nbr);
		ft_putstr(" = ");
		calc = compteur * nb;
		ft_putnbr(calc);
		ft_putchar('\n');
		compteur++;
	}
}
