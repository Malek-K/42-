/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_conv_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:24:07 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/03 15:07:47 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

uintmax_t			ft_size_conv_uint(uintmax_t nb, t_data *arg)
{
	if (arg->size == 0)
		nb = (unsigned int)nb;
	if (arg->size == 1)
		nb = (unsigned char)nb;
	if (arg->size == 2)
		nb = (unsigned short int)nb;
	if (arg->size == 3)
		nb = (unsigned long int)nb;
	if (arg->size == 4)
		nb = (unsigned long long int)nb;
	if (arg->size == 5)
		nb = (uintmax_t)nb;
	if (arg->size == 6)
		nb = (size_t)nb;
	if (arg->size == 7)
		nb = (ptrdiff_t)nb;
	return (nb);
}
