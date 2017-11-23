/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 23:06:15 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/06 20:50:13 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (power > 0)
	{
		while (i < power)
		{
			j = (j * nb);
			i++;
		}
		if (j <= 2147483647)
			return (j);
		else
			return (0);
	}
	else if (power == 0)
		return (1);
	else
		return (0);
}
