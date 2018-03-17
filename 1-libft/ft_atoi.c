/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:25:20 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/17 17:32:52 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int		i;
	long int		nbr;
	long int		posneg;

	i = 0;
	nbr = 0;
	posneg = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' ||
	str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		posneg = str[i] == '-' ? -1 : 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + ((str[i] - 48) * posneg);
		i++;
	}
	return (nbr);
}
