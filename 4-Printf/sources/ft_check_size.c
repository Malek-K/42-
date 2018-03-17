/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 18:39:18 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/05 14:27:28 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_check_size(char *cpy, t_data *arg)
{
	if (*cpy == 'h')
	{
		if (*(cpy + 1) == 'h' && arg->size < 1)
			arg->size = 1;
		else if (*(cpy - 1) != 'h' && *(cpy + 1) != 'h' && arg->size < 2)
			arg->size = 2;
	}
	if (*cpy == 'l')
	{
		if (*(cpy + 1) == 'l' && arg->size < 4)
			arg->size = 4;
		else if (arg->size < 3)
			arg->size = 3;
	}
	if (*cpy == 'z' && arg->size < 5)
		arg->size = 5;
	if (*cpy == 'j' && arg->size < 6)
		arg->size = 6;
	if (*cpy == 't' && arg->size < 7)
		arg->size = 7;
	if (*cpy == 'L')
		arg->dbl = 1;
}
