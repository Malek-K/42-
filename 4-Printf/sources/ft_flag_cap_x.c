/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_cap_X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:29:08 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/03 14:46:37 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char			*ft_flag_cap_x(va_list *ap, t_data *arg)
{
	uintmax_t	nb;
	char		*nbr;

	nb = va_arg(*ap, uintmax_t);
	nb = ft_size_conv_uint(nb, arg);
	nbr = ft_utoa_base(nb, 16);
	if (arg->p_field && arg->precision == 0 && nb == 0)
		*nbr = '\0';
	arg->length_f = ft_strlen(nbr);
	return (nbr);
}
