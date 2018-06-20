/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:58:10 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/03 14:28:20 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char			*ft_flag_u(va_list *ap, t_data *arg)
{
	uintmax_t	nb;
	char		*nbr;

	nb = va_arg(*ap, uintmax_t);
	nb = ft_size_conv_uint(nb, arg);
	nbr = ft_utoa_base(nb, 10);
	if (arg->p_field && arg->precision == 0 && nb == 0)
		*nbr = '\0';
	arg->length_f = ft_strlen(nbr);
	return (nbr);
}
