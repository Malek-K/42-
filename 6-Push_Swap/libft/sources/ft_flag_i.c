/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:27:23 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/03 14:27:49 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char			*ft_flag_i(va_list *ap, t_data *arg)
{
	intmax_t	nb;
	char		*nbr;

	nb = va_arg(*ap, intmax_t);
	nb = ft_size_conv_int(nb, arg);
	nbr = ft_itoa_base(nb, 10);
	if (arg->p_field && arg->precision == 0 && nb == 0)
		*nbr = '\0';
	arg->length_f = ft_strlen(nbr);
	return (nbr);
}
