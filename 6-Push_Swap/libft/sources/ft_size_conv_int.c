/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_conv_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:24:41 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/03 15:07:20 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

intmax_t	ft_size_conv_int(intmax_t nb, t_data *arg)
{
	if (arg->size == 0)
		nb = (int)nb;
	if (arg->size == 1)
		nb = (char)nb;
	if (arg->size == 2)
		nb = (short int)nb;
	if (arg->size == 3)
		nb = (long int)nb;
	if (arg->size == 4)
		nb = (long long int)nb;
	if (arg->size == 5)
		nb = (intmax_t)nb;
	if (arg->size == 6)
		nb = (size_t)nb;
	if (arg->size == 7)
		nb = (ptrdiff_t)nb;
	return (nb);
}
