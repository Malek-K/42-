/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 10:33:25 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/08 13:01:43 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ultimator.h>

#include <stdlib.h>

void	ft_destroy(char ***factory)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (factory[i])
	{
		j = 0;
		while (factory[i][j])
		{
			k = 0;
			while (factory[i][j][k])
			{
				if (factory[i][j][k] != NULL)
					free(factory[i][j][k]);
				k++;
			}
			free(factory[i][j]);
			j++;
		}
		free(factory[i]);
		i++;
	}
	free(factory);
}
