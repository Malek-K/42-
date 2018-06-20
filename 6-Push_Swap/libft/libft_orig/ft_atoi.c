/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:25:20 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/27 19:00:33 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_atoi(const char *str)
{
	long long int	i;
	long long int	nbr;
	long long int	posneg;

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
