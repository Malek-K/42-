/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 21:45:36 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/03 14:46:47 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char			*ft_flag_p(va_list *ap, t_data *arg)
{
	uintmax_t	nb;
	char		*nbr;
	int			i;

	nb = va_arg(*ap, uintmax_t);
	nbr = ft_utoa_base(nb, 16);
	if (arg->p_field && arg->precision == 0 && nb == 0)
		*nbr = '\0';
	arg->length_f = ft_strlen(nbr);
	i = -1;
	while (nbr[++i])
		nbr[i] = ft_tolower(nbr[i]);
	return (nbr);
}
