/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:24:16 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/07 20:53:08 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char			*ft_flag_s(va_list *ap, t_data *arg)
{
	char		*str;

	str = NULL;
	if (arg->size == 0)
		str = (char*)va_arg(*ap, wchar_t*);
	else if (arg->size == 3)
		str = ft_wstr_to_str(va_arg(*ap, wchar_t*));
	if (str == NULL)
		str = ("(null)");
	arg->length_f = ft_strlen(str);
	return (str);
}
