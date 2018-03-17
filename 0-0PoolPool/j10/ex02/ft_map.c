/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:17:53 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/19 18:32:54 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		i;
	int		*arr;

	i = 0;
	if (!(arr = (int*)malloc(sizeof(int) * (length + 1))))
		return (NULL);
	while (i < length)
	{
		arr[i] = f(tab[i]);
		i++;
	}
	arr[i] = 0;
	return (arr);
}
