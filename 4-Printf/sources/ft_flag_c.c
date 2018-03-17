/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:46:50 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/07 16:12:49 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char			*ft_flag_c(va_list *ap, t_data *arg)
{
	intmax_t	c;
	char		*str;

	str = NULL;
	c = va_arg(*ap, intmax_t);
	if (arg->size == 0)
		str = ft_wchar_to_str((char)c);
	else if (arg->size == 3)
	{
		c = (wint_t)c;
		str = ft_wchar_to_str((wchar_t)c);
	}
	if (c == 0)
	{
		*str = '\0';
		arg->length_f = 1;
	}
	else
		arg->length_f = ft_strlen(str);
	return (str);
}
