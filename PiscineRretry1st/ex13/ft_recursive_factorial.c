/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:08:09 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/06 19:39:10 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	if (nb > 0 && nb < 13)
		return (nb * ft_recursive_factorial(nb - 1));
	if (nb == 0)
		return (1);
	else
		return (0);
}
