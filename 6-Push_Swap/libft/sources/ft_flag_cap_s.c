/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_cap_S.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:40:00 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/03 14:45:26 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char			*ft_flag_cap_s(va_list *ap, t_data *arg)
{
	char		*str;

	str = ft_wstr_to_str(va_arg(*ap, wchar_t*));
	if (str == NULL)
		str = ("(null)");
	arg->length_f = ft_strlen(str);
	return (str);
}
