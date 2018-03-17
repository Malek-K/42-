/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 20:04:16 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/03 14:47:24 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char			*ft_flag_x(va_list *ap, t_data *arg)
{
	uintmax_t	nb;
	int			i;
	char		*nbr;

	nb = va_arg(*ap, uintmax_t);
	nb = ft_size_conv_uint(nb, arg);
	nbr = ft_utoa_base(nb, 16);
	if (arg->p_field && arg->precision == 0 && nb == 0)
		*nbr = '\0';
	arg->length_f = ft_strlen(nbr);
	i = -1;
	while (nbr[++i])
		nbr[i] = ft_tolower(nbr[i]);
	return (nbr);
}
