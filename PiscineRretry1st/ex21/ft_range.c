/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:45:30 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/07 14:26:56 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
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
	}
	return (tab);
}
