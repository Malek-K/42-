/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_cap_C.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:20:54 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/03 14:44:25 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char			*ft_flag_cap_c(va_list *ap, t_data *arg)
{
	wchar_t		c;
	char		*str;

	c = (wchar_t)va_arg(*ap, wint_t);
	str = ft_wchar_to_str(c);
	if (c == 0)
	{
		*str = '\0';
		arg->length_f = 1;
	}
	else
		arg->length_f = ft_strlen(str);
	return (str);
}
