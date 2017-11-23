/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:56:45 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/07 19:20:40 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_takes_place(int hour)
{
	int		x;
	char	h;
	char	hh;

	h = 'A';
	hh = 'A';
	x = (hour + 1) % 24;
	if (hour >= 12)
		h = 'P';
	if (x >= 12)
		hh = 'P';
	hour = hour % 12;
	x = x % 12;
	if (hour == 0)
		hour = 12;
	if (x == 0)
		x = 12;
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	printf("%i.00 %c.M. AND %i.00 %c.M.\n", hour, h, x, hh);
}
