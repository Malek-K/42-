/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 17:18:05 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/06 19:41:47 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_next_prime(int nb)
{
	int		i;

	i = 2;
	if (nb <= 2)
		return (2);
	if (nb > 2)
	{
		while (i < nb && (nb % i) != 0)
			i++;
		if (i == nb)
			return (i);
		else
			return (ft_find_next_prime(nb + 1));
	}
	return (1);
}
