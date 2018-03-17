/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:39:54 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/07 17:50:33 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char			*ft_flag_n(va_list *ap, t_data *arg)
{
	intmax_t	*nb;
	char		*nbr;

	nbr = NULL;
	nb = (void*)va_arg(*ap, intmax_t);
	*nb = arg->octet;
	*nb = ft_size_conv_int(*nb, arg);
	nbr = ft_strdup("");
	free(nbr);
	return (nbr);
}
