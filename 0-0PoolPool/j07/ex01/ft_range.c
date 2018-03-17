/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 21:32:40 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/17 16:04:50 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*tab;
	int		i;

	i = 0;
	if (min >= max)
	{
		tab = 0;
		return (tab);
	}
	else
	{
		tab = (int*)malloc(sizeof(*tab) * (max - min));
		while (min < max)
		{
			tab[i] = min;
			i++;
			min++;
		}
		tab[i] = 0;
	}
	return (tab);
}
